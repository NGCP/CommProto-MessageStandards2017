/**
  Battery Packet Template.
  
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
#ifndef NGCP_Battery_HPP
#define NGCP_Battery_HPP


#include <CommProto/commproto.h>


namespace ngcp {
  
struct Battery : INHERITS_ABSPACKET {
  Battery(uint32_t battery_percentage = 0) 
    : CHAIN_ABSPACKET(Battery)
    , battery_percentage(battery_percentage)
    { }
  
  
  /**
    Pack data into the stream for sending out.
  */
  void Pack(comnet::ObjectStream &obj) override {
    obj << battery_percentage;
  }
  
  
  /**
    Unpack data back into this packet when receiving data.
  */
  void Unpack(comnet::ObjectStream &obj) override {
    obj >> battery_percentage;
  }
  
  
  /**
    Tells CommProtocol how to recreate the Battery packet
    when receiving data.
  */
  comnet::AbstractPacket *Create() override {
    return new Battery();
  }
    
  /**
    Data.
  */
  uint32_t battery_percentage;
};
} // ngcp
#endif // NGCP_Battery_HPP
