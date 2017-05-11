/**
ArmPosition

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
#ifndef NGCP_ARM_POSITION_HPP
#define NGCP_ARM_POSITION_HPP


#include <CommProto/commproto.h>



namespace ngcp {

  struct ArmPosition : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    ArmPosition(int32_t position1,
      int32_t position2,
      int32_t position3,
      int32_t position4)
      : CHAIN_ABSPACKET(ArmPosition),
      position1(position1),
      position2(position2),
      position3(position3),
      position4(position4)
    {
    }


    /**
    Pack data into the stream for sending out.
    */
    void Pack(comnet::ObjectStream &obj) override {
      obj << position1;
      obj << position2;
      obj << position3;
      obj << position4;
    }


    /**
    Unpack data back into this packet when receiving data.
    */
    void Unpack(comnet::ObjectStream &obj) override {
      obj >> position4;
      obj >> position3;
      obj >> position2;
      obj >> position1;
    }


    /**
    Tells CommProtocol how to recreate the ArmPosition packet
    when receiving data.
    */
    comnet::AbstractPacket *Create() override {
      return new ArmPosition(0, 0, 0, 0);
    }

    /**
    Data.
    */
    int32_t position1;
    int32_t position2;
    int32_t position3;
    int32_t position4;
  };
} // ngcp
#endif // NGCP_ARM_POSITION_HPP

