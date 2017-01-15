/**
  VehicleInertialState Packet Template.
  
  Copyright (C) 2016-2017 Northrup Grumman Collaboration Project.
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (At your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef NGCP_VEHICLE_INERTIAL_STATE_HPP
#define NGCP_VEHICLE_INERTIAL_STATE_HPP


#include <CommProto/commproto.h>


namespace ngcp {
  

  /**
    VehicleInertialState Template
  */
  class VehicleInertialState :INHERITS_ABSPACKET {
  public:

    VehicleInertialState(uint16_t id = 0, double_t latitude = 0.0, double_t longitude = 0.0, float_t altitude = 0.0,
      float_t roll = 0.0, float_t pitch = 0.0, float_t heading = 0.0, float_t north_speed = 0.0, float_t east_speed = 0.0,
      float_t vertical_speed = 0.0, float_t roll_rate = 0.0, float_t pitch_rate = 0.0, float_t yaw_rate = 0.0,
      float_t north_accel = 0.0, float_t east_accel = 0.0, float_t vertical_accel = 0.0)
      : CHAIN_ABSPACKET(VehicleInertialState)
    { }

    /**
      Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream & obj) override {
      obj << vehicle_id;
      obj << latitude;
      obj << longitude;
      obj << altitude;
      obj << roll;
      obj << pitch;
      obj << heading;
      obj << north_speed;
      obj << east_speed;
      obj << vertical_speed;
      obj << roll_rate;
      obj << pitch_rate;
      obj << yaw_rate;
      obj << north_accel;
      obj << east_accel;
      obj << vertical_accel;
    }

    /**
      Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream & obj) override {
      obj >> vertical_accel;
      obj >> east_accel;
      obj >> north_accel;
      obj >> yaw_rate;
      obj >> pitch_rate;
      obj >> roll_rate;
      obj >> vertical_speed;
      obj >> east_speed;
      obj >> north_speed;
      obj >> heading;
      obj >> pitch;
      obj >> roll;
      obj >> altitude;
      obj >> longitude;
      obj >> latitude;
      obj >> vehicle_id;
    }

    /**
      Tells CommProtocol how to recreate the VehicleInertialState packet
      when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleInertialState();
    }

    /*
      Data.
    */
    uint16_t vehicle_id;
    double_t latitude;
    double_t longitude;
    float_t altitude;
    float_t roll;
    float_t pitch;
    float_t heading;
    float_t north_speed;
    float_t east_speed;
    float_t vertical_speed;
    float_t roll_rate;
    float_t pitch_rate;
    float_t yaw_rate;
    float_t north_accel;
    float_t east_accel;
    float_t vertical_accel;
  };
} // ngcp
#endif // NGCP_VEHICLE_INERTIAL_STATE_HPP