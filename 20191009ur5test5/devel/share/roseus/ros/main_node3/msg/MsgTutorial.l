;; Auto-generated. Do not edit!


(when (boundp 'main_node3::MsgTutorial)
  (if (not (find-package "MAIN_NODE3"))
    (make-package "MAIN_NODE3"))
  (shadow 'MsgTutorial (find-package "MAIN_NODE3")))
(unless (find-package "MAIN_NODE3::MSGTUTORIAL")
  (make-package "MAIN_NODE3::MSGTUTORIAL"))

(in-package "ROS")
;;//! \htmlinclude MsgTutorial.msg.html


(defclass main_node3::MsgTutorial
  :super ros::object
  :slots (_stamp _data _cor_data ))

(defmethod main_node3::MsgTutorial
  (:init
   (&key
    ((:stamp __stamp) (instance ros::time :init))
    ((:data __data) 0)
    ((:cor_data __cor_data) (make-array 3 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _data (round __data))
   (setq _cor_data __cor_data)
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:cor_data
   (&optional __cor_data)
   (if __cor_data (setq _cor_data __cor_data)) _cor_data)
  (:serialization-length
   ()
   (+
    ;; time _stamp
    8
    ;; int32 _data
    4
    ;; float64[3] _cor_data
    (* 8    3)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; int32 _data
       (write-long _data s)
     ;; float64[3] _cor_data
     (dotimes (i 3)
       (sys::poke (elt _cor_data i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _data
     (setq _data (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64[3] _cor_data
   (dotimes (i (length _cor_data))
     (setf (elt _cor_data i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get main_node3::MsgTutorial :md5sum-) "62d0714983fcbcdfa996a71eafe20f3a")
(setf (get main_node3::MsgTutorial :datatype-) "main_node3/MsgTutorial")
(setf (get main_node3::MsgTutorial :definition-)
      "time stamp
int32 data
float64[3] cor_data

")



(provide :main_node3/MsgTutorial "62d0714983fcbcdfa996a71eafe20f3a")


