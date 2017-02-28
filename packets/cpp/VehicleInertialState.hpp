/**
VehicleInertialState

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

  struct VehicleInertialState : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleInertialState(uint16_t vehicle_id = 0,
      real64_t longitude = 0,
      real64_t latitude = 0,
      real32_t altitude = 0,
      real32_t roll = 0,
      real32_t pitch = 0,
      real32_t heading = 0,
      real32_t north_speed = 0,
      real32_t east_speed = 0,
      real32_t vertical_speed = 0,
      real32_t roll_rate = 0,
      real32_t pitch_rate = 0,
      real32_t yaw_rate = 0,
      real32_t north_accel = 0,
      real32_t east_accel = 0,
      real32_t vertical_accel = 0)
      : CHAIN_ABSPACKET(VehicleInertialState),
      vehicle_id(vehicle_id),
      longitude(longitude),
      latitude(latitude),
      altitude(altitude),
      roll(roll),
      pitch(pitch),
      heading(heading),
      north_speed(north_speed),
      east_speed(east_speed),
      vertical_speed(vertical_speed),
      roll_rate(roll_rate),
      pitch_rate(pitch_rate),
      yaw_rate(yaw_rate),
      north_accel(north_accel),
      east_accel(east_accel),
      vertical_accel(vertical_accel)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << longitude;
      obj << latitude;
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
    void Unpack(comnet::ObjectStream &obj) override {
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
      obj >> latitude;
      obj >> longitude;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleInertialState packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleInertialState();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    real64_t longitude;
    real64_t latitude;
    real32_t altitude;
    real32_t roll;
    real32_t pitch;
    real32_t heading;
    real32_t north_speed;
    real32_t east_speed;
    real32_t vertical_speed;
    real32_t roll_rate;
    real32_t pitch_rate;
    real32_t yaw_rate;
    real32_t north_accel;
    real32_t east_accel;
    real32_t vertical_accel;
  };
} // ngcp
#endif // NGCP_VEHICLE_INERTIAL_STATE_HPP

