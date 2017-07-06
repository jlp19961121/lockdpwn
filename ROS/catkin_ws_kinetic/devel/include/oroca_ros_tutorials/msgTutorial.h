// Generated by gencpp from file oroca_ros_tutorials/msgTutorial.msg
// DO NOT EDIT!


#ifndef OROCA_ROS_TUTORIALS_MESSAGE_MSGTUTORIAL_H
#define OROCA_ROS_TUTORIALS_MESSAGE_MSGTUTORIAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace oroca_ros_tutorials
{
template <class ContainerAllocator>
struct msgTutorial_
{
  typedef msgTutorial_<ContainerAllocator> Type;

  msgTutorial_()
    : data(0)  {
    }
  msgTutorial_(const ContainerAllocator& _alloc)
    : data(0)  {
  (void)_alloc;
    }



   typedef int32_t _data_type;
  _data_type data;




  typedef boost::shared_ptr< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> const> ConstPtr;

}; // struct msgTutorial_

typedef ::oroca_ros_tutorials::msgTutorial_<std::allocator<void> > msgTutorial;

typedef boost::shared_ptr< ::oroca_ros_tutorials::msgTutorial > msgTutorialPtr;
typedef boost::shared_ptr< ::oroca_ros_tutorials::msgTutorial const> msgTutorialConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace oroca_ros_tutorials

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'oroca_ros_tutorials': ['/home/odroid/gitrepo/lockdpwn/ROS/catkin_ws/src/oroca_ros_tutorials/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
{
  static const char* value()
  {
    return "da5909fbe378aeaf85e547e830cc1bb7";
  }

  static const char* value(const ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xda5909fbe378aeafULL;
  static const uint64_t static_value2 = 0x85e547e830cc1bb7ULL;
};

template<class ContainerAllocator>
struct DataType< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
{
  static const char* value()
  {
    return "oroca_ros_tutorials/msgTutorial";
  }

  static const char* value(const ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 data\n\
";
  }

  static const char* value(const ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msgTutorial_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::oroca_ros_tutorials::msgTutorial_<ContainerAllocator>& v)
  {
    s << indent << "data: ";
    Printer<int32_t>::stream(s, indent + "  ", v.data);
  }
};

} // namespace message_operations
} // namespace ros

#endif // OROCA_ROS_TUTORIALS_MESSAGE_MSGTUTORIAL_H
