// Generated by gencpp from file nasa_r2_common_msgs/ParseTableSceneRequest.msg
// DO NOT EDIT!


#ifndef NASA_R2_COMMON_MSGS_MESSAGE_PARSETABLESCENEREQUEST_H
#define NASA_R2_COMMON_MSGS_MESSAGE_PARSETABLESCENEREQUEST_H


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
struct ParseTableSceneRequest_
{
  typedef ParseTableSceneRequest_<ContainerAllocator> Type;

  ParseTableSceneRequest_()
    : cmd(false)  {
    }
  ParseTableSceneRequest_(const ContainerAllocator& _alloc)
    : cmd(false)  {
  (void)_alloc;
    }



   typedef uint8_t _cmd_type;
  _cmd_type cmd;




  typedef boost::shared_ptr< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ParseTableSceneRequest_

typedef ::nasa_r2_common_msgs::ParseTableSceneRequest_<std::allocator<void> > ParseTableSceneRequest;

typedef boost::shared_ptr< ::nasa_r2_common_msgs::ParseTableSceneRequest > ParseTableSceneRequestPtr;
typedef boost::shared_ptr< ::nasa_r2_common_msgs::ParseTableSceneRequest const> ParseTableSceneRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace nasa_r2_common_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'nasa_r2_common_msgs': ['/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/deprecated_nasa_r2_common/nasa_r2_common_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'visualization_msgs': ['/opt/ros/indigo/share/visualization_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fab6d5f499de320aad10749bce1f85cf";
  }

  static const char* value(const ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfab6d5f499de320aULL;
  static const uint64_t static_value2 = 0xad10749bce1f85cfULL;
};

template<class ContainerAllocator>
struct DataType< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nasa_r2_common_msgs/ParseTableSceneRequest";
  }

  static const char* value(const ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool cmd\n\
";
  }

  static const char* value(const ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.cmd);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ParseTableSceneRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nasa_r2_common_msgs::ParseTableSceneRequest_<ContainerAllocator>& v)
  {
    s << indent << "cmd: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NASA_R2_COMMON_MSGS_MESSAGE_PARSETABLESCENEREQUEST_H
