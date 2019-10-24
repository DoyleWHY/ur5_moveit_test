; Auto-generated. Do not edit!


(cl:in-package main_node3-msg)


;//! \htmlinclude MsgTutorial.msg.html

(cl:defclass <MsgTutorial> (roslisp-msg-protocol:ros-message)
  ((stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (data
    :reader data
    :initarg :data
    :type cl:integer
    :initform 0)
   (cor_data
    :reader cor_data
    :initarg :cor_data
    :type (cl:vector cl:float)
   :initform (cl:make-array 3 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass MsgTutorial (<MsgTutorial>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgTutorial>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgTutorial)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name main_node3-msg:<MsgTutorial> is deprecated: use main_node3-msg:MsgTutorial instead.")))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <MsgTutorial>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader main_node3-msg:stamp-val is deprecated.  Use main_node3-msg:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <MsgTutorial>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader main_node3-msg:data-val is deprecated.  Use main_node3-msg:data instead.")
  (data m))

(cl:ensure-generic-function 'cor_data-val :lambda-list '(m))
(cl:defmethod cor_data-val ((m <MsgTutorial>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader main_node3-msg:cor_data-val is deprecated.  Use main_node3-msg:cor_data instead.")
  (cor_data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgTutorial>) ostream)
  "Serializes a message object of type '<MsgTutorial>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let* ((signed (cl:slot-value msg 'data)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'cor_data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgTutorial>) istream)
  "Deserializes a message object of type '<MsgTutorial>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'data) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:setf (cl:slot-value msg 'cor_data) (cl:make-array 3))
  (cl:let ((vals (cl:slot-value msg 'cor_data)))
    (cl:dotimes (i 3)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgTutorial>)))
  "Returns string type for a message object of type '<MsgTutorial>"
  "main_node3/MsgTutorial")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgTutorial)))
  "Returns string type for a message object of type 'MsgTutorial"
  "main_node3/MsgTutorial")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgTutorial>)))
  "Returns md5sum for a message object of type '<MsgTutorial>"
  "62d0714983fcbcdfa996a71eafe20f3a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgTutorial)))
  "Returns md5sum for a message object of type 'MsgTutorial"
  "62d0714983fcbcdfa996a71eafe20f3a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgTutorial>)))
  "Returns full string definition for message of type '<MsgTutorial>"
  (cl:format cl:nil "time stamp~%int32 data~%float64[3] cor_data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgTutorial)))
  "Returns full string definition for message of type 'MsgTutorial"
  (cl:format cl:nil "time stamp~%int32 data~%float64[3] cor_data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgTutorial>))
  (cl:+ 0
     8
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'cor_data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgTutorial>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgTutorial
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':data (data msg))
    (cl:cons ':cor_data (cor_data msg))
))
