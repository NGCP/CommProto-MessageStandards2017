/**
  TargetStatus Packet Template.
  
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
#ifndef NGCP_Target_Status_HPP
#define NGCP_Target_Status_HPP


#include <CommProto/commproto.h>


namespace ngcp {
  
struct TargetStatus : INHERITS_ABSPACKET {
  TargetStatus(double target_radius = 0,
    double target_angle = 0, 
    double target_altitude = 0) 
    : CHAIN_ABSPACKET(TargetStatus)
    , target_radius(target_radius)
    , target_angle(target_angle)
    , target_altitude(target_altitude)
    { }
  
  
  /**
    Pack data into the stream for sending out.
  */
  void Pack(comnet::ObjectStream &obj) override {
    obj << target_radius;
    obj << target_angle;
    obj << target_altitude;
  }
  
  
  /**
    Unpack data back into this packet when receiving data.
  */
  void Unpack(comnet::ObjectStream &obj) override {
    obj >> target_altitude;
    obj >> target_angle;
    obj >> target_radius;
  }
  
  
  /**
    Tells CommProtocol how to recreate the TargetStatus packet
    when receiving data.
  */
  comnet::AbstractPacket *Create() override {
    return new TargetStatus();
  }
    
  /**
    Data.
  */
  double target_radius;
  double target_angle;
  double target_altitude;
};
} // ngcp
#endif // NGCP_Target_Status_HPP
