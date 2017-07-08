// Generated by gencpp from file nasa_r2_common_msgs/PoseCommandStatus.msg
// DO NOT EDIT!


#ifndef NASA_R2_COMMON_MSGS_MESSAGE_POSECOMMANDSTATUS_H
#define NASA_R2_COMMON_MSGS_MESSAGE_POSECOMMANDSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace nasa_r2_common_msgs
{
template <class ContainerAllocator>
struct PoseCommandStatus_
{
  typedef PoseCommandStatus_<ContainerAllocator> Type;

  PoseCommandStatus_()
    : stamp()
    , commandId()
    , status(0)
    , statusMessage()  {
    }
  PoseCommandStatus_(const ContainerAllocator& _alloc)
    : stamp()
    , commandId(_alloc)
    , status(0)
    , statusMessage(_alloc)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _commandId_type;
  _commandId_type commandId;

   typedef uint8_t _status_type;
  _status_type status;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _statusMessage_type;
  _statusMessage_type statusMessage;


    enum { PENDING = 0u };
     enum { ACTIVE = 1u };
     enum { REJECTED = 2u };
     enum { SUCCEEDED = 3u };
     enum { FAILED = 4u };
 

  typedef boost::shared_ptr< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> const> ConstPtr;

}; // struct PoseCommandStatus_

typedef ::nasa_r2_common_msgs::PoseCommandStatus_<std::allocator<void> > PoseCommandStatus;

typedef boost::shared_ptr< ::nasa_r2_common_msgs::PoseCommandStatus > PoseCommandStatusPtr;
typedef boost::shared_ptr< ::nasa_r2_common_msgs::PoseCommandStatus const> PoseCommandStatusConstPtr;

// constants requiring out of line definition

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace nasa_r2_common_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'nasa_r2_common_msgs': ['/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/deprecated_nasa_r2_common/nasa_r2_common_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'visualization_msgs': ['/opt/ros/indigo/share/visualization_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "82493b7735e3fe414b93381d96bfd1ee";
  }

  static const char* value(const ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x82493b7735e3fe41ULL;
  static const uint64_t static_value2 = 0x4b93381d96bfd1eeULL;
};

template<class ContainerAllocator>
struct DataType< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nasa_r2_common_msgs/PoseCommandStatus";
  }

  static const char* value(const ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n\
string commandId\n\
uint8 PENDING=0\n\
uint8 ACTIVE=1\n\
uint8 REJECTED=2\n\
uint8 SUCCEEDED=3\n\
uint8 FAILED=4\n\
uint8 status\n\
string statusMessage\n\
";
  }

  static const char* value(const ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.commandId);
      stream.next(m.status);
      stream.next(m.statusMessage);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PoseCommandStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nasa_r2_common_msgs::PoseCommandStatus_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "commandId: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.commandId);
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
    s << indent << "statusMessage: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.statusMessage);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NASA_R2_COMMON_MSGS_MESSAGE_POSECOMMANDSTATUS_H
