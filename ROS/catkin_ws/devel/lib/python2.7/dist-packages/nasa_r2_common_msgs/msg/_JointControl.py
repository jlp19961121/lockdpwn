# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from nasa_r2_common_msgs/JointControl.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class JointControl(genpy.Message):
  _md5sum = "e38c02f4ffdedb57646a4576b7e0ccf6"
  _type = "nasa_r2_common_msgs/JointControl"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string publisher
float64 timeStamp
string joint
uint32 registerValue
bool enableBridge
bool enableMotor
bool releaseBrake
bool embeddedMotCom
uint16 controlMode
bool clearFaults
"""
  __slots__ = ['publisher','timeStamp','joint','registerValue','enableBridge','enableMotor','releaseBrake','embeddedMotCom','controlMode','clearFaults']
  _slot_types = ['string','float64','string','uint32','bool','bool','bool','bool','uint16','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       publisher,timeStamp,joint,registerValue,enableBridge,enableMotor,releaseBrake,embeddedMotCom,controlMode,clearFaults

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(JointControl, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.publisher is None:
        self.publisher = ''
      if self.timeStamp is None:
        self.timeStamp = 0.
      if self.joint is None:
        self.joint = ''
      if self.registerValue is None:
        self.registerValue = 0
      if self.enableBridge is None:
        self.enableBridge = False
      if self.enableMotor is None:
        self.enableMotor = False
      if self.releaseBrake is None:
        self.releaseBrake = False
      if self.embeddedMotCom is None:
        self.embeddedMotCom = False
      if self.controlMode is None:
        self.controlMode = 0
      if self.clearFaults is None:
        self.clearFaults = False
    else:
      self.publisher = ''
      self.timeStamp = 0.
      self.joint = ''
      self.registerValue = 0
      self.enableBridge = False
      self.enableMotor = False
      self.releaseBrake = False
      self.embeddedMotCom = False
      self.controlMode = 0
      self.clearFaults = False

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
      _x = self.publisher
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_d.pack(self.timeStamp))
      _x = self.joint
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_I4BHB.pack(_x.registerValue, _x.enableBridge, _x.enableMotor, _x.releaseBrake, _x.embeddedMotCom, _x.controlMode, _x.clearFaults))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.publisher = str[start:end].decode('utf-8')
      else:
        self.publisher = str[start:end]
      start = end
      end += 8
      (self.timeStamp,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.joint = str[start:end].decode('utf-8')
      else:
        self.joint = str[start:end]
      _x = self
      start = end
      end += 11
      (_x.registerValue, _x.enableBridge, _x.enableMotor, _x.releaseBrake, _x.embeddedMotCom, _x.controlMode, _x.clearFaults,) = _struct_I4BHB.unpack(str[start:end])
      self.enableBridge = bool(self.enableBridge)
      self.enableMotor = bool(self.enableMotor)
      self.releaseBrake = bool(self.releaseBrake)
      self.embeddedMotCom = bool(self.embeddedMotCom)
      self.clearFaults = bool(self.clearFaults)
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
      _x = self.publisher
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_struct_d.pack(self.timeStamp))
      _x = self.joint
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      if python3:
        buff.write(struct.pack('<I%sB'%length, length, *_x))
      else:
        buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_I4BHB.pack(_x.registerValue, _x.enableBridge, _x.enableMotor, _x.releaseBrake, _x.embeddedMotCom, _x.controlMode, _x.clearFaults))
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
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.publisher = str[start:end].decode('utf-8')
      else:
        self.publisher = str[start:end]
      start = end
      end += 8
      (self.timeStamp,) = _struct_d.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.joint = str[start:end].decode('utf-8')
      else:
        self.joint = str[start:end]
      _x = self
      start = end
      end += 11
      (_x.registerValue, _x.enableBridge, _x.enableMotor, _x.releaseBrake, _x.embeddedMotCom, _x.controlMode, _x.clearFaults,) = _struct_I4BHB.unpack(str[start:end])
      self.enableBridge = bool(self.enableBridge)
      self.enableMotor = bool(self.enableMotor)
      self.releaseBrake = bool(self.releaseBrake)
      self.embeddedMotCom = bool(self.embeddedMotCom)
      self.clearFaults = bool(self.clearFaults)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_I4BHB = struct.Struct("<I4BHB")
_struct_d = struct.Struct("<d")
