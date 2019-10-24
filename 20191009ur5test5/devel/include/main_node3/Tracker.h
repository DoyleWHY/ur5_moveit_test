// Generated by gencpp from file main_node3/Tracker.msg
// DO NOT EDIT!


#ifndef MAIN_NODE3_MESSAGE_TRACKER_H
#define MAIN_NODE3_MESSAGE_TRACKER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace main_node3
{
template <class ContainerAllocator>
struct Tracker_
{
  typedef Tracker_<ContainerAllocator> Type;

  Tracker_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , error_x(0.0)
    , error_y(0.0)
    , error_z(0.0)
    , flag1(false)
    , flag2(false)
    , flag3(false)  {
    }
  Tracker_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , error_x(0.0)
    , error_y(0.0)
    , error_z(0.0)
    , flag1(false)
    , flag2(false)
    , flag3(false)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _error_x_type;
  _error_x_type error_x;

   typedef double _error_y_type;
  _error_y_type error_y;

   typedef double _error_z_type;
  _error_z_type error_z;

   typedef uint8_t _flag1_type;
  _flag1_type flag1;

   typedef uint8_t _flag2_type;
  _flag2_type flag2;

   typedef uint8_t _flag3_type;
  _flag3_type flag3;





  typedef boost::shared_ptr< ::main_node3::Tracker_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::main_node3::Tracker_<ContainerAllocator> const> ConstPtr;

}; // struct Tracker_

typedef ::main_node3::Tracker_<std::allocator<void> > Tracker;

typedef boost::shared_ptr< ::main_node3::Tracker > TrackerPtr;
typedef boost::shared_ptr< ::main_node3::Tracker const> TrackerConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::main_node3::Tracker_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::main_node3::Tracker_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace main_node3

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'main_node3': ['/home/doylewhy/efficient/moveit/20191009ur5test5/src/main_node3/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::main_node3::Tracker_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::main_node3::Tracker_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::main_node3::Tracker_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::main_node3::Tracker_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::main_node3::Tracker_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::main_node3::Tracker_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::main_node3::Tracker_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b283d7d9a91916dac4010d28ee78ee60";
  }

  static const char* value(const ::main_node3::Tracker_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb283d7d9a91916daULL;
  static const uint64_t static_value2 = 0xc4010d28ee78ee60ULL;
};

template<class ContainerAllocator>
struct DataType< ::main_node3::Tracker_<ContainerAllocator> >
{
  static const char* value()
  {
    return "main_node3/Tracker";
  }

  static const char* value(const ::main_node3::Tracker_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::main_node3::Tracker_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# message type to describe the tracking information of the blocks\n"
"# to be published as a topic\n"
"\n"
"float64 x  # x coordinate in the world\n"
"float64 y  # y coordinate in the world\n"
"float64 z  # z coordinate in the world\n"
"float64 error_x\n"
"float64 error_y\n"
"float64 error_z\n"
"bool flag1\n"
"bool flag2\n"
"bool flag3\n"
"\n"
;
  }

  static const char* value(const ::main_node3::Tracker_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::main_node3::Tracker_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.error_x);
      stream.next(m.error_y);
      stream.next(m.error_z);
      stream.next(m.flag1);
      stream.next(m.flag2);
      stream.next(m.flag3);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Tracker_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::main_node3::Tracker_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::main_node3::Tracker_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "error_x: ";
    Printer<double>::stream(s, indent + "  ", v.error_x);
    s << indent << "error_y: ";
    Printer<double>::stream(s, indent + "  ", v.error_y);
    s << indent << "error_z: ";
    Printer<double>::stream(s, indent + "  ", v.error_z);
    s << indent << "flag1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flag1);
    s << indent << "flag2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flag2);
    s << indent << "flag3: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flag3);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAIN_NODE3_MESSAGE_TRACKER_H
