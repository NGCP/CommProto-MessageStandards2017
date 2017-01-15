/**
  VehicleSystemStatus Packet Template.
  
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
#ifndef NGCP_VEHICLE_SYSTEM_STATUS_HPP
#define NGCP_VEHICLE_SYSTEM_STATUS_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  /**
    VehicleSystemStatus Template
  */
  class VehicleSystemStatus : INHERITS_ABSPACKET {
  public:

    VehicleSystemStatus(uint16_t id = 0, uint8_t mode = 0, uint8_t state = 0)
      : CHAIN_ABSPACKET(VehicleSystemStatus)
    { }

    /**
      Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream & obj) override {
      obj << vehicle_id;
      obj << vehicle_mode;
      obj << vehicle_state;
    }

    /**
      Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream & obj) override {
      obj >> vehicle_state;
      obj >> vehicle_mode;
      obj >> vehicle_id;
    }

    /**
      Tells CommProtocol how to recreate the VehicleSystemStatus packet
      when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleSystemStatus();
    }
    /**
      Data.
    */
    uint16_t vehicle_id;
    uint8_t vehicle_mode;
    uint8_t vehicle_state;
  };
} // ngcp
#endif // NGCP_VEHICLE_SYSTEM_STATUS_HPP