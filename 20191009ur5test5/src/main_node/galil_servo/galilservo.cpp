#include "galilservo.h"

using namespace std;

GalilServo::GalilServo()
    : rc(GALIL_EXAMPLE_OK), galilLinked(false), axisStrSet("ABCD"), g(NULL)
{
    for(size_t i = 0; i < MAX_AXIS_NUMBER; ++i)
    {
        currentMode[i] = GALIL_NOMODE;
        velocity[i] = 10000;
        acceleration[i] = 8000000;   //max 1000 0000
        deceleration[i] = 8000000;   //initialize dec and acc
    }
    countsPerRevolution[0] = 10854;
    countsPerRevolution[1] = 10854;
    countsPerRevolution[2] = 10854;
    countsPerRevolution[3] = 68608;
}

GalilServo::~GalilServo()
{
    GClose(g);
}

bool GalilServo::initMotor(uint axis)
{
//    LOGFUNC
    assert(axis <= MAX_AXIS_NUMBER);
    if(!galilLinked)
    {
        try
        {
            cout << "Step3 : Initialize DMC4143 controller\n";
            cout << "  3.1 : connect to DMC4143 controller\n";
            x_e(GVersion(buf, sizeof(buf))); //library version
            cout << "Library versions: " << buf << "\n";

            cout << "Connecting to hardware\n";
            x_e(GOpen("/dev/ttyUSB0 --baud 115200 --subscribe ALL", &g));
            x_e(GInfo(g, buf, sizeof(buf))); //grab connection string
            cout << buf << '\n';
            cout << "*********************************" << endl;

            galilLinked = true;
            cout << "  3.2 : Set initial parameters\n";
            x_e(GCmd(g, "ST")); //stop all motion and programs
            x_e(GCmd(g, "DP 0,0,0,0")); //define ABCD position zero
            x_e(GCmd(g, "SP 10000,10000,10000,60000")); //set up speed
            x_e(GCmd(g, "AC 8000000,8000000,8000000,8000000")); //acceleration
            x_e(GCmd(g, "DC 8000000,8000000,8000000,8000000")); //deceleration
            cout << "Parameters are set successfully!" << endl;
            cout << "  3.3 : Move to home positon\n";

            x_e(GCmd(g, "PR 20000,40000,60000,80000")); //Postion Relative.
            x_e(GCmd(g, "SH ABCD")); //Servo Here
            x_e(GCmd(g, "BG ABCD")); //Begin motion
            x_e(GMotionComplete(g, "ABCD")); //Block until motion is complete on axis A
            cout << "Motion Complete\n";
            x_e(GCmdT(g, "RP", buf, sizeof(buf), &trimmed));
            cout << "Position: " << trimmed << '\n';
            cout << "Initialize successfully!" << endl;
            cout << "*********************************" << endl;

        }//try
        catch (GReturn gr) //for x_e() function
        {
            if (gr == GALIL_EXAMPLE_ERROR)
                cout << "ERROR: Example code failed\n";
            else
            {
                cout << "Function returned " << gr << '\n';
                GError(gr, buf, sizeof(buf));
                cout << buf << '\n';
                GSize size = sizeof(buf);

                if (g)
                {
                    GUtility(g, G_UTIL_ERROR_CONTEXT, buf, &size);
                    cout << buf << '\n'; //further context
                }

            }
            rc = GALIL_EXAMPLE_ERROR;
            if (g) GClose(g); g = 0; //close g
        }
        catch (std::exception& e)
        {
            std::cerr << "Unexpected std::exception... Kaboom. " << e.what() << std::endl;
            rc = GALIL_EXAMPLE_ERROR;
            if (g) GClose(g); g = 0; //close g
        }
        catch (...)
        {
            cout << "Unexpected error... Kaboom." << endl;
            rc = GALIL_EXAMPLE_ERROR;
            if (g) GClose(g); g = 0; //close g
        }
    }

//    if(axis == 0)
//    {
//        sprintf(buf, "AC %u,%u,%u,%u", acceleration[0], acceleration[1], acceleration[2], acceleration[3]);
//        check(GCmd(g, buf), g);
//        sprintf(buf, "DC %u,%u,%u,%u", deceleration[0], deceleration[1], deceleration[2], deceleration[3]);
//        check(GCmd(g, buf), g);
//        sprintf(buf, "SH %s", axisStrSet);
//        check(GCmd(g, buf), g);
//    }
//    else
//    {
//        sprintf(buf, "AC%c=%u", axisStrSet[axis-1], acceleration[axis-1]);
//        check(GCmd(g, buf), g);
//        sprintf(buf, "DC%c=%u", axisStrSet[axis-1], deceleration[axis-1]);
//        check(GCmd(g, buf), g);
//        sprintf(buf, "SH %c", axisStrSet[axis-1]);
//        check(GCmd(g, buf), g);
//    }
//    return true;
}

bool GalilServo::disableMotor(uint axis)
{
//    LOGFUNC
    assert(axis <= MAX_AXIS_NUMBER);
    if(axis == 0)
        sprintf(buf, "ST %s", axisStrSet);
    else
        sprintf(buf, "ST %c", axisStrSet[axis-1]);
    x_e(GCmd(g, buf));
    cout << "Motion stop!" << endl;
    return true;
}

bool GalilServo::movePositionAbsolutely(uint axis, long pos)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    currentMode[axis-1] = GALIL_POSITION;
    sprintf(buf, "PA%c=%ld;BG%c", axisStrSet[axis-1], pos, axisStrSet[axis-1]);
    x_e(GCmd(g, buf));
    return true;
}

bool GalilServo::movePositionRelatively(uint axis, long pos)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    currentMode[axis-1] = GALIL_POSITION;
    sprintf(buf, "PR%c=%ld;BG%c", axisStrSet[axis-1], pos, axisStrSet[axis-1]);
    x_e(GCmd(g, buf));
    return true;
}

bool GalilServo::movePositionTracking(uint axis, long pos)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    if(currentMode[axis-1] != GALIL_PT)
    {
        sprintf(buf, "IT%c=0.3;PT%c=1", axisStrSet[axis-1], axisStrSet[axis-1]); //Need modified
        x_e(GCmd(g, buf));
        currentMode[axis-1] = GALIL_PT;
    }
    sprintf(buf, "PA%c=%ld", axisStrSet[axis-1], pos);
    x_e(GCmd(g, buf));
}

bool GalilServo::moveVelocity(uint axis, long v)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    currentMode[axis-1] = GALIL_JOG;
    sprintf(buf, "JG%c=%ld;BG%c", axisStrSet[axis-1], v, axisStrSet[axis-1]);
    x_e(GCmd(g, buf));
    return true;
}

bool GalilServo::getMotorPosition(uint axis, int &pos)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    sprintf(buf, "TP%c", axisStrSet[axis-1]);
    x_e(GCmdI(g, buf, &pos));
    return true;
}

bool GalilServo::setMotorVelocity(uint axis, long rpm)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    long countsPerSecond = static_cast<long>(countsPerRevolution[axis-1]*(rpm/60.0));
    sprintf(buf, "SP%c=%ld", axisStrSet[axis-1], countsPerSecond);
    x_e(GCmd(g, buf));
    return true;
}

bool GalilServo::definePosition(uint axis, int pos)
{
//    LOGFUNC
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    sprintf(buf, "DP%c=%d", axisStrSet[axis-1], pos);
    x_e(GCmd(g, buf));
    return true;
}

bool GalilServo::printPositon(uint axis)
{
    assert((axis <= MAX_AXIS_NUMBER) && (axis >= 1));
    x_e(GCmdT(g, "RP", buf, sizeof(buf), &trimmed));
    cout << "Position: " << trimmed << '\n';
}


void GalilServo::x_e(GReturn rc)
{
        if (rc != G_NO_ERROR)
                throw rc;
}

void GalilServo::check(GReturn rc)
{
        if (rc != G_NO_ERROR)
        {
                printf("ERROR: %d", rc);
                if (g)
                        GClose(g);
                exit (rc);
        }
}
