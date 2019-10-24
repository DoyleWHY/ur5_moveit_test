// Auto-generated. Do not edit!

// (in-package main_node3.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class MsgTutorial {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stamp = null;
      this.data = null;
      this.cor_data = null;
    }
    else {
      if (initObj.hasOwnProperty('stamp')) {
        this.stamp = initObj.stamp
      }
      else {
        this.stamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = 0;
      }
      if (initObj.hasOwnProperty('cor_data')) {
        this.cor_data = initObj.cor_data
      }
      else {
        this.cor_data = new Array(3).fill(0);
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MsgTutorial
    // Serialize message field [stamp]
    bufferOffset = _serializer.time(obj.stamp, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _serializer.int32(obj.data, buffer, bufferOffset);
    // Check that the constant length array field [cor_data] has the right length
    if (obj.cor_data.length !== 3) {
      throw new Error('Unable to serialize array field cor_data - length must be 3')
    }
    // Serialize message field [cor_data]
    bufferOffset = _arraySerializer.float64(obj.cor_data, buffer, bufferOffset, 3);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MsgTutorial
    let len;
    let data = new MsgTutorial(null);
    // Deserialize message field [stamp]
    data.stamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [cor_data]
    data.cor_data = _arrayDeserializer.float64(buffer, bufferOffset, 3)
    return data;
  }

  static getMessageSize(object) {
    return 36;
  }

  static datatype() {
    // Returns string type for a message object
    return 'main_node3/MsgTutorial';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '62d0714983fcbcdfa996a71eafe20f3a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    time stamp
    int32 data
    float64[3] cor_data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MsgTutorial(null);
    if (msg.stamp !== undefined) {
      resolved.stamp = msg.stamp;
    }
    else {
      resolved.stamp = {secs: 0, nsecs: 0}
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = 0
    }

    if (msg.cor_data !== undefined) {
      resolved.cor_data = msg.cor_data;
    }
    else {
      resolved.cor_data = new Array(3).fill(0)
    }

    return resolved;
    }
};

module.exports = MsgTutorial;
