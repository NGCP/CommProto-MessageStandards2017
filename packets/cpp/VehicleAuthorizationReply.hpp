/**
  VehicleAuthorizationReply Packet Template.
  
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
#ifndef NGCP_VEHICLE_AUTHORIZATION_REPLY_HPP  
#define NGCP_VEHICLE_AUTHORIZATION_REPLY_HPP  


#include <CommProto/commproto.h>


namespace ngcp {

  /**
    VehicleAuthorizationReply Template
  */
  class VehicleAuthorizationReply : INHERITS_ABSPACKET {
  public:

    VehicleAuthorizationReply(uint16_t id = 0, uint8_t type = 0, uint8_t authorized = 0, uint8_t granted = 0)
      : CHAIN_ABSPACKET(VehicleAuthorizationReply)
    { }

    /**
      Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream & obj) override {
      obj << vehicle_id;
      obj << vehicle_type;
      obj << authorized_serv;
      obj << granted_serv;
    }

    /**
      Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> granted_serv;
      obj >> authorized_serv;
      obj >> vehicle_type;
      obj >> vehicle_id;
    }

    /*
      Tells CommProtocol how to recreate the VehicleAuthorizationReply packet when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new VehicleAuthorizationReply();
    }

    /*
      Data.
    */
    uint16_t vehicle_id;
    uint8_t vehicle_type;
    uint8_t authorized_serv;
    uint8_t granted_serv;
  };
} //ngcp
#endif // NGCP_VEHICLE_AUTHORIZATION_REPLY_HPP  
