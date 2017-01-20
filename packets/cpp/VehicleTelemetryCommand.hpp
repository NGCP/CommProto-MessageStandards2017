/**
VehicleTelemetryCommand

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
#ifndef NGCP_VEHICLE_TELEMETRY_COMMAND_HPP
#define NGCP_VEHICLE_TELEMETRY_COMMAND_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleTelemetryCommand : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleTelemetryCommand(uint16_t vehicle_id = 0,
      uint8_t telemetry_select = 0,
      uint8_t telemetry_rate = 0)
      : CHAIN_ABSPACKET(VehicleTelemetryCommand),
      vehicle_id(vehicle_id),
      telemetry_select(telemetry_select),
      telemetry_rate(telemetry_rate)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << telemetry_select;
      obj << telemetry_rate;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> telemetry_rate;
      obj >> telemetry_select;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleTelemetryCommand packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleTelemetryCommand();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    uint8_t telemetry_select;
    //In milliseconds
    uint8_t telemetry_rate;
  };
} // ngcp
#endif // NGCP_VEHICLE_TELEMETRY_COMMAND_HPP

