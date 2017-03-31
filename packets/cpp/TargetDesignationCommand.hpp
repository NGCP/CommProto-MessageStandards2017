/**
TargetDesignationCommand

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
#ifndef NGCP_TARGET_DESIGNATION_COMMAND_HPP
#define NGCP_TARGET_DESIGNATION_COMMAND_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct TargetDesignationCommand : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    TargetDesignationCommand(uint16_t vehicle_id = 0,
      uint8_t payload_id = 0,
      uint8_t target_id = 0,
      uint8_t target_type = 0,
      real32_t longitude = 0,
      real32_t latitude = 0,
      real32_t altitude = 0)
      : CHAIN_ABSPACKET(TargetDesignationCommand),
      vehicle_id(vehicle_id),
      payload_id(payload_id),
      target_id(target_id),
      target_type(target_type),
      longitude(longitude),
      latitude(latitude),
      altitude(altitude)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << payload_id;
      obj << target_id;
      obj << target_type;
      obj << longitude;
      obj << latitude;
      obj << altitude;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> altitude;
      obj >> latitude;
      obj >> longitude;
      obj >> target_type;
      obj >> target_id;
      obj >> payload_id;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the TargetDesignationCommand packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new TargetDesignationCommand();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    uint8_t payload_id;
    uint8_t target_id;
    uint8_t target_type;
    //radians
    real32_t longitude;
    //radians
    real32_t latitude;
    //meters
    real32_t altitude;
  };
} // ngcp
#endif // NGCP_TARGET_DESIGNATION_COMMAND_HPP

