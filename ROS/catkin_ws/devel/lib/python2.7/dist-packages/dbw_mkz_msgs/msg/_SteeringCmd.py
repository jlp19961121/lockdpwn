# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dbw_mkz_msgs/SteeringCmd.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class SteeringCmd(genpy.Message):
  _md5sum = "ff1fa11624bdc2aff2aeee5aa6014057"
  _type = "dbw_mkz_msgs/SteeringCmd"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """# Steering Wheel
float32 steering_wheel_angle_cmd        # rad, range -8.2 to 8.2
float32 steering_wheel_angle_velocity   # rad/s, range 0 to 8.7, 0 = maximum

# Enable
bool enable

# Clear driver overrides
bool clear

# Ignore driver overrides
bool ignore

# Disable the driver override audible warning
bool quiet

# Watchdog counter (optional)
uint8 count
"""
  __slots__ = ['steering_wheel_angle_cmd','steering_wheel_angle_velocity','enable','clear','ignore','quiet','count']
  _slot_types = ['float32','float32','bool','bool','bool','bool','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       steering_wheel_angle_cmd,steering_wheel_angle_velocity,enable,clear,ignore,quiet,count

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SteeringCmd, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.steering_wheel_angle_cmd is None:
        self.steering_wheel_angle_cmd = 0.
      if self.steering_wheel_angle_velocity is None:
        self.steering_wheel_angle_velocity = 0.
      if self.enable is None:
        self.enable = False
      if self.clear is None:
        self.clear = False
      if self.ignore is None:
        self.ignore = False
      if self.quiet is None:
        self.quiet = False
      if self.count is None:
        self.count = 0
    else:
      self.steering_wheel_angle_cmd = 0.
      self.steering_wheel_angle_velocity = 0.
      self.enable = False
      self.clear = False
      self.ignore = False
      self.quiet = False
      self.count = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2f5B.pack(_x.steering_wheel_angle_cmd, _x.steering_wheel_angle_velocity, _x.enable, _x.clear, _x.ignore, _x.quiet, _x.count))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 13
      (_x.steering_wheel_angle_cmd, _x.steering_wheel_angle_velocity, _x.enable, _x.clear, _x.ignore, _x.quiet, _x.count,) = _struct_2f5B.unpack(str[start:end])
      self.enable = bool(self.enable)
      self.clear = bool(self.clear)
      self.ignore = bool(self.ignore)
      self.quiet = bool(self.quiet)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2f5B.pack(_x.steering_wheel_angle_cmd, _x.steering_wheel_angle_velocity, _x.enable, _x.clear, _x.ignore, _x.quiet, _x.count))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 13
      (_x.steering_wheel_angle_cmd, _x.steering_wheel_angle_velocity, _x.enable, _x.clear, _x.ignore, _x.quiet, _x.count,) = _struct_2f5B.unpack(str[start:end])
      self.enable = bool(self.enable)
      self.clear = bool(self.clear)
      self.ignore = bool(self.ignore)
      self.quiet = bool(self.quiet)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2f5B = struct.Struct("<2f5B")
