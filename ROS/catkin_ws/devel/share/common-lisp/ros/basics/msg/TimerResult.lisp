; Auto-generated. Do not edit!


(cl:in-package basics-msg)


;//! \htmlinclude TimerResult.msg.html

(cl:defclass <TimerResult> (roslisp-msg-protocol:ros-message)
  ((time_elapsed
    :reader time_elapsed
    :initarg :time_elapsed
    :type cl:real
    :initform 0))
)

(cl:defclass TimerResult (<TimerResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TimerResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TimerResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name basics-msg:<TimerResult> is deprecated: use basics-msg:TimerResult instead.")))

(cl:ensure-generic-function 'time_elapsed-val :lambda-list '(m))
(cl:defmethod time_elapsed-val ((m <TimerResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader basics-msg:time_elapsed-val is deprecated.  Use basics-msg:time_elapsed instead.")
  (time_elapsed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TimerResult>) ostream)
  "Serializes a message object of type '<TimerResult>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'time_elapsed)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'time_elapsed) (cl:floor (cl:slot-value msg 'time_elapsed)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TimerResult>) istream)
  "Deserializes a message object of type '<TimerResult>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time_elapsed) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TimerResult>)))
  "Returns string type for a message object of type '<TimerResult>"
  "basics/TimerResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TimerResult)))
  "Returns string type for a message object of type 'TimerResult"
  "basics/TimerResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TimerResult>)))
  "Returns md5sum for a message object of type '<TimerResult>"
  "5cf2a912daf51cc83cb45e261a19d4f1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TimerResult)))
  "Returns md5sum for a message object of type 'TimerResult"
  "5cf2a912daf51cc83cb45e261a19d4f1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TimerResult>)))
  "Returns full string definition for message of type '<TimerResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# 결과: 종료 시 서버가 보냄~%duration time_elapsed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TimerResult)))
  "Returns full string definition for message of type 'TimerResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# 결과: 종료 시 서버가 보냄~%duration time_elapsed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TimerResult>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TimerResult>))
  "Converts a ROS message object to a list"
  (cl:list 'TimerResult
    (cl:cons ':time_elapsed (time_elapsed msg))
))
