/**
VehicleAttitude

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
#ifndef NGCP_VEHICLE_ATTITUDE_HPP
#define NGCP_VEHICLE_ATTITUDE_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleAttitude : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleAttitude(uint16_t vehicle_id = 0,
      real32_t roll = 0,
      real32_t pitch = 0,
      real32_t yaw = 0)
      : CHAIN_ABSPACKET(VehicleAttitude),
      vehicle_id(vehicle_id),
      roll(roll),
      pitch(pitch),
      yaw(yaw)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << roll;
      obj << pitch;
      obj << yaw;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> yaw;
      obj >> pitch;
      obj >> roll;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleAttitude packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleAttitude();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    //radians
    real32_t roll;
    //radians
    real32_t pitch;
    //radians
    real32_t yaw;
  };
} // ngcp
#endif // NGCP_VEHICLE_ATTITUDE_HPP

