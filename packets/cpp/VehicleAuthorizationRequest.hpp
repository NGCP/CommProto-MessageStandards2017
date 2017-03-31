/**
VehicleAuthorizationRequest

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
#ifndef NGCP_VEHICLE_AUTHORIZATION_REQUEST_HPP
#define NGCP_VEHICLE_AUTHORIZATION_REQUEST_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct VehicleAuthorizationRequest : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    VehicleAuthorizationRequest(uint16_t vehicle_id = 0,
      uint8_t vehicle_type = 0,
      uint8_t authorized_services = 0,
      uint8_t granted_services = 0)
      : CHAIN_ABSPACKET(VehicleAuthorizationRequest),
      vehicle_id(vehicle_id),
      vehicle_type(vehicle_type),
      authorized_services(authorized_services),
      granted_services(granted_services)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << vehicle_id;
      obj << vehicle_type;
      obj << authorized_services;
      obj << granted_services;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> granted_services;
      obj >> authorized_services;
      obj >> vehicle_type;
      obj >> vehicle_id;
    }


    /**
    Tells CommProtocol how to recreate the VehicleAuthorizationRequest packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleAuthorizationRequest();
    }

    /**
    Data.
    */
    uint16_t vehicle_id;
    uint8_t vehicle_type;
    uint8_t authorized_services;
    uint8_t granted_services;
  };
} // ngcp
#endif // NGCP_VEHICLE_AUTHORIZATION_REQUEST_HPP

