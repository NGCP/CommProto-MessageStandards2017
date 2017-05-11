/**
ArmCommand

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
#ifndef NGCP_ARM_COMMAND_HPP
#define NGCP_ARM_COMMAND_HPP


#include <CommProto/commproto.h>



namespace ngcp {

  struct ArmCommand : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    ArmCommand(uint8_t id = 0,
      int32_t position = 0)
      : CHAIN_ABSPACKET(ArmCommand),
      id(id),
      position(position)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << id;
      obj << position;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> position;
      obj >> id;
    }


    /**
    Tells CommProtocol how to recreate the ArmCommand packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new ArmCommand();
    }

    /**
    Data.
    */
    uint8_t id;
    int32_t position;
  };
} // ngcp
#endif // NGCP_ARM_COMMAND_HPP

