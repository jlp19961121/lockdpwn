// Generated by gencpp from file rndf_manager/srvHeightMapRequest.msg
// DO NOT EDIT!


#ifndef RNDF_MANAGER_MESSAGE_SRVHEIGHTMAPREQUEST_H
#define RNDF_MANAGER_MESSAGE_SRVHEIGHTMAPREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rndf_manager
{
template <class ContainerAllocator>
struct srvHeightMapRequest_
{
  typedef srvHeightMapRequest_<ContainerAllocator> Type;

  srvHeightMapRequest_()
    : x(0.0)
    , y(0.0)
    , theta(0.0)
    , mode(0)  {
    }
  srvHeightMapRequest_(const ContainerAllocator& _alloc)
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




  typedef boost::shared_ptr< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> const> ConstPtr;

}; // struct srvHeightMapRequest_

typedef ::rndf_manager::srvHeightMapRequest_<std::allocator<void> > srvHeightMapRequest;

typedef boost::shared_ptr< ::rndf_manager::srvHeightMapRequest > srvHeightMapRequestPtr;
typedef boost::shared_ptr< ::rndf_manager::srvHeightMapRequest const> srvHeightMapRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rndf_manager

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "644e98df8f75d5c5b73d84d5bc60a5ee";
  }

  static const char* value(const ::rndf_manager::srvHeightMapRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x644e98df8f75d5c5ULL;
  static const uint64_t static_value2 = 0xb73d84d5bc60a5eeULL;
};

template<class ContainerAllocator>
struct DataType< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rndf_manager/srvHeightMapRequest";
  }

  static const char* value(const ::rndf_manager::srvHeightMapRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 x\n\
float64 y\n\
float64 theta\n\
int64 mode\n\
";
  }

  static const char* value(const ::rndf_manager::srvHeightMapRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.theta);
      stream.next(m.mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct srvHeightMapRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rndf_manager::srvHeightMapRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rndf_manager::srvHeightMapRequest_<ContainerAllocator>& v)
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

#endif // RNDF_MANAGER_MESSAGE_SRVHEIGHTMAPREQUEST_H