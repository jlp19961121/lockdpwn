// Generated by gencpp from file car_can/CarCanData.msg
// DO NOT EDIT!


#ifndef CAR_CAN_MESSAGE_CARCANDATA_H
#define CAR_CAN_MESSAGE_CARCANDATA_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace car_can
{
template <class ContainerAllocator>
struct CarCanData_
{
  typedef CarCanData_<ContainerAllocator> Type;

  CarCanData_()
    : t(0.0)
    , gyro()
    , accl()
    , magnet()
    , sas(0.0)
    , obdVel1(0.0)
    , obdVel2(0.0)  {
      gyro.assign(0.0);

      accl.assign(0.0);

      magnet.assign(0.0);
  }
  CarCanData_(const ContainerAllocator& _alloc)
    : t(0.0)
    , gyro()
    , accl()
    , magnet()
    , sas(0.0)
    , obdVel1(0.0)
    , obdVel2(0.0)  {
      gyro.assign(0.0);

      accl.assign(0.0);

      magnet.assign(0.0);
  }



   typedef double _t_type;
  _t_type t;

   typedef boost::array<double, 3>  _gyro_type;
  _gyro_type gyro;

   typedef boost::array<double, 3>  _accl_type;
  _accl_type accl;

   typedef boost::array<double, 3>  _magnet_type;
  _magnet_type magnet;

   typedef double _sas_type;
  _sas_type sas;

   typedef double _obdVel1_type;
  _obdVel1_type obdVel1;

   typedef double _obdVel2_type;
  _obdVel2_type obdVel2;




  typedef boost::shared_ptr< ::car_can::CarCanData_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::car_can::CarCanData_<ContainerAllocator> const> ConstPtr;

}; // struct CarCanData_

typedef ::car_can::CarCanData_<std::allocator<void> > CarCanData;

typedef boost::shared_ptr< ::car_can::CarCanData > CarCanDataPtr;
typedef boost::shared_ptr< ::car_can::CarCanData const> CarCanDataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::car_can::CarCanData_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::car_can::CarCanData_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace car_can

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'car_can': ['/home/dyros-vehicle/gitrepo/lockdpwn/ROS/catkin_ws/src/car_can/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::car_can::CarCanData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::car_can::CarCanData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::car_can::CarCanData_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::car_can::CarCanData_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::car_can::CarCanData_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::car_can::CarCanData_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::car_can::CarCanData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aad0b4ce5de8f6b9c2d6a08270853f6e";
  }

  static const char* value(const ::car_can::CarCanData_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaad0b4ce5de8f6b9ULL;
  static const uint64_t static_value2 = 0xc2d6a08270853f6eULL;
};

template<class ContainerAllocator>
struct DataType< ::car_can::CarCanData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "car_can/CarCanData";
  }

  static const char* value(const ::car_can::CarCanData_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::car_can::CarCanData_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 t\n\
float64[3] gyro\n\
float64[3] accl\n\
float64[3] magnet\n\
float64 sas\n\
float64 obdVel1\n\
float64 obdVel2\n\
";
  }

  static const char* value(const ::car_can::CarCanData_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::car_can::CarCanData_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.t);
      stream.next(m.gyro);
      stream.next(m.accl);
      stream.next(m.magnet);
      stream.next(m.sas);
      stream.next(m.obdVel1);
      stream.next(m.obdVel2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct CarCanData_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::car_can::CarCanData_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::car_can::CarCanData_<ContainerAllocator>& v)
  {
    s << indent << "t: ";
    Printer<double>::stream(s, indent + "  ", v.t);
    s << indent << "gyro[]" << std::endl;
    for (size_t i = 0; i < v.gyro.size(); ++i)
    {
      s << indent << "  gyro[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.gyro[i]);
    }
    s << indent << "accl[]" << std::endl;
    for (size_t i = 0; i < v.accl.size(); ++i)
    {
      s << indent << "  accl[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.accl[i]);
    }
    s << indent << "magnet[]" << std::endl;
    for (size_t i = 0; i < v.magnet.size(); ++i)
    {
      s << indent << "  magnet[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.magnet[i]);
    }
    s << indent << "sas: ";
    Printer<double>::stream(s, indent + "  ", v.sas);
    s << indent << "obdVel1: ";
    Printer<double>::stream(s, indent + "  ", v.obdVel1);
    s << indent << "obdVel2: ";
    Printer<double>::stream(s, indent + "  ", v.obdVel2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAR_CAN_MESSAGE_CARCANDATA_H