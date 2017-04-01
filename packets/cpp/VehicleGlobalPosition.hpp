/**
VehicleGlobalPosition

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
#ifndef NGCP_VEHICLE_GLOBAL_POSITION_HPP
#define NGCP_VEHICLE_GLOBAL_POSITION_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleGlobalPosition : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleGlobalPosition(uint16_t vehicle_id = 0,
      real32_t longitude = 0,
      real32_t latitude = 0,
      real32_t altitude = 0,
      real32_t x_speed = 0,
      real32_t y_speed = 0,
      real32_t z_speed = 0)
      : CHAIN_ABSPACKET(VehicleGlobalPosition),
      vehicle_id(vehicle_id),
      longitude(longitude),
      latitude(latitude),
      altitude(altitude),
      x_speed(x_speed),
      y_speed(y_speed),
      z_speed(z_speed)
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
      obj << x_speed;
      obj << y_speed;
      obj << z_speed;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> z_speed;
      obj >> y_speed;
      obj >> x_speed;
      obj >> altitude;
      obj >> latitude;
      obj >> longitude;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleGlobalPosition packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleGlobalPosition();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    //radians
    real32_t longitude;
    //radians
    real32_t latitude;
    //meters
    real32_t altitude;
    //meters/second
    real32_t x_speed;
    //meters/second
    real32_t y_speed;
    //meters/second
    real32_t z_speed;
  };
} // ngcp
#endif // NGCP_VEHICLE_GLOBAL_POSITION_HPP

