/**
VehicleModeCommand

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
#ifndef NGCP_VEHICLE_MODE_COMMAND_HPP
#define NGCP_VEHICLE_MODE_COMMAND_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleModeCommand : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleModeCommand(uint16_t vehicle_id = 0,
      uint8_t vehicle_mode = 0)
      : CHAIN_ABSPACKET(VehicleModeCommand),
      vehicle_id(vehicle_id),
      vehicle_mode(vehicle_mode)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << vehicle_mode;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> vehicle_mode;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleModeCommand packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleModeCommand();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    uint8_t vehicle_mode;
  };
} // ngcp
#endif // NGCP_VEHICLE_MODE_COMMAND_HPP

