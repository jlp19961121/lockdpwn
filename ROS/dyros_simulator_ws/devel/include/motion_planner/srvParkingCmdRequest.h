// Generated by gencpp from file motion_planner/srvParkingCmdRequest.msg
// DO NOT EDIT!


#ifndef MOTION_PLANNER_MESSAGE_SRVPARKINGCMDREQUEST_H
#define MOTION_PLANNER_MESSAGE_SRVPARKINGCMDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace motion_planner
{
template <class ContainerAllocator>
struct srvParkingCmdRequest_
{
  typedef srvParkingCmdRequest_<ContainerAllocator> Type;

  srvParkingCmdRequest_()
    : x(0.0)
    , y(0.0)
    , theta(0.0)
    , mode(0)  {
    }
  srvParkingCmdRequest_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , theta(0.0)
    , mode(0)  {
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _theta_type;
  _theta_type theta;

   typedef int64_t _mode_type;
  _mode_type mode;




  typedef boost::shared_ptr< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> const> ConstPtr;

}; // struct srvParkingCmdRequest_

typedef ::motion_planner::srvParkingCmdRequest_<std::allocator<void> > srvParkingCmdRequest;

typedef boost::shared_ptr< ::motion_planner::srvParkingCmdRequest > srvParkingCmdRequestPtr;
typedef boost::shared_ptr< ::motion_planner::srvParkingCmdRequest const> srvParkingCmdRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace motion_planner

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "644e98df8f75d5c5b73d84d5bc60a5ee";
  }

  static const char* value(const ::motion_planner::srvParkingCmdRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x644e98df8f75d5c5ULL;
  static const uint64_t static_value2 = 0xb73d84d5bc60a5eeULL;
};

template<class ContainerAllocator>
struct DataType< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "motion_planner/srvParkingCmdRequest";
  }

  static const char* value(const ::motion_planner::srvParkingCmdRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n\
float64 y\n\
float64 theta\n\
int64 mode\n\
";
  }

  static const char* value(const ::motion_planner::srvParkingCmdRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.theta);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct srvParkingCmdRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::motion_planner::srvParkingCmdRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::motion_planner::srvParkingCmdRequest_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
    s << indent << "mode: ";
    Printer<int64_t>::stream(s, indent + "  ", v.mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MOTION_PLANNER_MESSAGE_SRVPARKINGCMDREQUEST_H