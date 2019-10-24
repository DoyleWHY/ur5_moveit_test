#ifndef CGLOBAL_H
#define CGLOBAL_H

class CGlobal
{
public:
    CGlobal();
    ~CGlobal();

public:
    static int testValue;
    static int buttonB;
    static double coordinates[3];
    static double motorAngles[6];
    static double motorVelocity[6];
    static double motorEffort[6];
    static double tfPosition[4];
    static float model_coordinates[3];

};

#endif // CGLOBAL_H
