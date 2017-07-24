# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from localization_gazebo/CarCanData.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CarCanData(genpy.Message):
  _md5sum = "aad0b4ce5de8f6b9c2d6a08270853f6e"
  _type = "localization_gazebo/CarCanData"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 t
float64[3] gyro
float64[3] accl
float64[3] magnet
float64 sas
float64 obdVel1
float64 obdVel2
"""
  __slots__ = ['t','gyro','accl','magnet','sas','obdVel1','obdVel2']
  _slot_types = ['float64','float64[3]','float64[3]','float64[3]','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       t,gyro,accl,magnet,sas,obdVel1,obdVel2

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CarCanData, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.t is None:
        self.t = 0.
      if self.gyro is None:
        self.gyro = [0.,0.,0.]
      if self.accl is None:
        self.accl = [0.,0.,0.]
      if self.magnet is None:
        self.magnet = [0.,0.,0.]
      if self.sas is None:
        self.sas = 0.
      if self.obdVel1 is None:
        self.obdVel1 = 0.
      if self.obdVel2 is None:
        self.obdVel2 = 0.
    else:
      self.t = 0.
      self.gyro = [0.,0.,0.]
      self.accl = [0.,0.,0.]
      self.magnet = [0.,0.,0.]
      self.sas = 0.
      self.obdVel1 = 0.
      self.obdVel2 = 0.

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
      buff.write(_struct_d.pack(self.t))
      buff.write(_struct_3d.pack(*self.gyro))
      buff.write(_struct_3d.pack(*self.accl))
      buff.write(_struct_3d.pack(*self.magnet))
      _x = self
      buff.write(_struct_3d.pack(_x.sas, _x.obdVel1, _x.obdVel2))
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
      end += 8
      (self.t,) = _struct_d.unpack(str[start:end])
      start = end
      end += 24
      self.gyro = _struct_3d.unpack(str[start:end])
      start = end
      end += 24
      self.accl = _struct_3d.unpack(str[start:end])
      start = end
      end += 24
      self.magnet = _struct_3d.unpack(str[start:end])
      _x = self
      start = end
      end += 24
      (_x.sas, _x.obdVel1, _x.obdVel2,) = _struct_3d.unpack(str[start:end])
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
      buff.write(_struct_d.pack(self.t))
      buff.write(self.gyro.tostring())
      buff.write(self.accl.tostring())
      buff.write(self.magnet.tostring())
      _x = self
      buff.write(_struct_3d.pack(_x.sas, _x.obdVel1, _x.obdVel2))
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
      end += 8
      (self.t,) = _struct_d.unpack(str[start:end])
      start = end
      end += 24
      self.gyro = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=3)
      start = end
      end += 24
      self.accl = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=3)
      start = end
      end += 24
      self.magnet = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=3)
      _x = self
      start = end
      end += 24
      (_x.sas, _x.obdVel1, _x.obdVel2,) = _struct_3d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_d = struct.Struct("<d")
_struct_3d = struct.Struct("<3d")
