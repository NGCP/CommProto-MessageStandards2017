/**
VehicleModeCommand Packet.

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

  /**
  Constructs VehicleModeCommand assigning parameters to their corresponding fields
  Fields will be set to 0 if not specified.
  */
  struct VehicleModeCommand : INHERITS_ABSPACKET {
    VehicleModeCommand(uint16_t vehicle_id = 0, uint8_t vehicle_mode = 0)
      :CHAIN_ABSPACKET(VehicleModeCommand),
      vehicle_id(vehicle_id),
      vehicle_mode(vehicle_mode)
    {

    }

    /**
    Serializes data into stream for sending.
    */
    void Pack(REF_OBJECTSTREAM objOut) override
    {
      objOut << vehicle_id;
      objOut << vehicle_mode;
    }

    /**
    Deserializes fields from a stream when receiving.
    */
    void Unpack(REF_OBJECTSTREAM objIn) override
    {
     objIn >> vehicle_mode;
     objIn >> vehicle_id;
    }

    /**
    Creates a new instance of VehicleModeCommand. Used when receiving.
    */
    AbstractPacket* Create() override
    {
      return new VehicleModeCommand();
    }

    /**
    The id of the vehicle.
    */
    uint16_t vehicle_id;
    /**
    Represents values of enum that correspond to a mode.
    */
    uint8_t vehicle_mode;
  };
}  //ngcp

#endif  //NGCP_VEHICLE_MODE_COMMAND_HPP