// Generated by gencpp from file localization/GpsReceiverData.msg
// DO NOT EDIT!


#ifndef LOCALIZATION_MESSAGE_GPSRECEIVERDATA_H
#define LOCALIZATION_MESSAGE_GPSRECEIVERDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace localization
{
template <class ContainerAllocator>
struct GpsReceiverData_
{
  typedef GpsReceiverData_<ContainerAllocator> Type;

  GpsReceiverData_()
    : t(0.0)
    , utc(0.0)
    , gps_quality(0)
    , no_sats(0)
    , hdop(0.0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , heading(0.0)
    , velocity(0.0)
    , tm_x(0.0)
    , tm_y(0.0)  {
    }
  GpsReceiverData_(const ContainerAllocator& _alloc)
    : t(0.0)
    , utc(0.0)
    , gps_quality(0)
    , no_sats(0)
    , hdop(0.0)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , heading(0.0)
    , velocity(0.0)
    , tm_x(0.0)
    , tm_y(0.0)  {
  (void)_alloc;
    }



   typedef double _t_type;
  _t_type t;

   typedef double _utc_type;
  _utc_type utc;

   typedef int32_t _gps_quality_type;
  _gps_quality_type gps_quality;

   typedef int32_t _no_sats_type;
  _no_sats_type no_sats;

   typedef double _hdop_type;
  _hdop_type hdop;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _altitude_type;
  _altitude_type altitude;

   typedef double _heading_type;
  _heading_type heading;

   typedef double _velocity_type;
  _velocity_type velocity;

   typedef double _tm_x_type;
  _tm_x_type tm_x;

   typedef double _tm_y_type;
  _tm_y_type tm_y;




  typedef boost::shared_ptr< ::localization::GpsReceiverData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::localization::GpsReceiverData_<ContainerAllocator> const> ConstPtr;

}; // struct GpsReceiverData_

typedef ::localization::GpsReceiverData_<std::allocator<void> > GpsReceiverData;

typedef boost::shared_ptr< ::localization::GpsReceiverData > GpsReceiverDataPtr;
typedef boost::shared_ptr< ::localization::GpsReceiverData const> GpsReceiverDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::localization::GpsReceiverData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::localization::GpsReceiverData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace localization

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'localization': ['/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/localization/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::localization::GpsReceiverData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::localization::GpsReceiverData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::localization::GpsReceiverData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::localization::GpsReceiverData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::localization::GpsReceiverData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::localization::GpsReceiverData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::localization::GpsReceiverData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6fcd8b41f0982f00b09b9c6b9702d7ca";
  }

  static const char* value(const ::localization::GpsReceiverData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6fcd8b41f0982f00ULL;
  static const uint64_t static_value2 = 0xb09b9c6b9702d7caULL;
};

template<class ContainerAllocator>
struct DataType< ::localization::GpsReceiverData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "localization/GpsReceiverData";
  }

  static const char* value(const ::localization::GpsReceiverData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::localization::GpsReceiverData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 t\n\
float64 utc\n\
int32 gps_quality\n\
int32 no_sats\n\
float64 hdop\n\
float64 latitude\n\
float64 longitude\n\
float64 altitude\n\
float64 heading\n\
float64 velocity\n\
float64 tm_x\n\
float64 tm_y\n\
";
  }

  static const char* value(const ::localization::GpsReceiverData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::localization::GpsReceiverData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.t);
      stream.next(m.utc);
      stream.next(m.gps_quality);
      stream.next(m.no_sats);
      stream.next(m.hdop);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.heading);
      stream.next(m.velocity);
      stream.next(m.tm_x);
      stream.next(m.tm_y);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GpsReceiverData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::localization::GpsReceiverData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::localization::GpsReceiverData_<ContainerAllocator>& v)
  {
    s << indent << "t: ";
    Printer<double>::stream(s, indent + "  ", v.t);
    s << indent << "utc: ";
    Printer<double>::stream(s, indent + "  ", v.utc);
    s << indent << "gps_quality: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gps_quality);
    s << indent << "no_sats: ";
    Printer<int32_t>::stream(s, indent + "  ", v.no_sats);
    s << indent << "hdop: ";
    Printer<double>::stream(s, indent + "  ", v.hdop);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<double>::stream(s, indent + "  ", v.altitude);
    s << indent << "heading: ";
    Printer<double>::stream(s, indent + "  ", v.heading);
    s << indent << "velocity: ";
    Printer<double>::stream(s, indent + "  ", v.velocity);
    s << indent << "tm_x: ";
    Printer<double>::stream(s, indent + "  ", v.tm_x);
    s << indent << "tm_y: ";
    Printer<double>::stream(s, indent + "  ", v.tm_y);
  }
};

} // namespace message_operations
} // namespace ros

#endif // LOCALIZATION_MESSAGE_GPSRECEIVERDATA_H
