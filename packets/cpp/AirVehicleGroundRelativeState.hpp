/**
  AirVehicleGroundRelativeState Packet Template.
  
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
#ifndef NGCP_Air_Vehicle_Ground_Relative_State_HPP
#define NGCP_Air_Vehicle_Ground_Relative_State_HPP


#include <CommProto/commproto.h>


namespace ngcp {
  
struct AirVehicleGroundRelativeState : INHERITS_ABSPACKET {
  AirVehicleGroundRelativeState(uint16_t vehicle_id = 0,
		float angle_of_attack = 0,
		float angle_of_sideslip = 0,
		float true_airspeed = 0,
		float indicated_airspeed = 0,
		float north_wind_speed = 0,
		float east_wind_speed = 0,
		float north_ground_speed = 0,
		float east_ground_speed = 0, 
		float barometric_presssure = 0,
		float barometric_altitude = 0) 
    : CHAIN_ABSPACKET(TargetAcknowledgement)
    , vehicle_id(vehicle_id)
		, angle_of_attack(angle_of_attack)
		, angle_of_sideslip(angle_of_sideslip)
		, true_airspeed(true_airspeed)
		, indicated_airspeed(indicated_airspeed)
		, north_wind_speed(north_wind_speed)
		, east_wind_speed(east_wind_speed)
		, north_ground_speed(north_ground_speed)
		, east_ground_speed(east_ground_speed)
		, barometric_pressure(barometric_pressure)
		, barometric_altitude(barometric_altitude)
    { }
  
  
  /**
    Pack data into the stream for sending out.
  */
  void Pack(comnet::ObjectStream &obj) override {
    obj << vehicle_id;
		obj << angle_of_attack;
		obj << angle_of_sideslip;
		obj << true_airspeed;
		obj << indicated_airspeed;
		obj << north_wind_speed;
		obj << east_wind_speed;
		obj << north_ground_speed;
		obj << east_ground_speed;
		obj << barometric_pressure;
		obj << barometric_altitude;
  }
  
  
  /**
    Unpack data back into this packet when receiving data.
  */
  void Unpack(comnet::ObjectStream &obj) override {
    obj >> barometric_altitude;
    obj >> barometric_pressure;
    obj >> east_ground_speed;
    obj >> north_ground_speed;
    obj >> east_wind_speed;
    obj >> north_wind_speed;
    obj >> indicated_airspeed;
    obj >> true_airspeed;
    obj >> angle_of_sideslip;
    obj >> angle_of_attack;
    obj >> vehicle_id;
  }
  
  
  /**
    Tells CommProtocol how to recreate the AirVehicleGroundRelativeState packet
    when receiving data.
  */
  comnet::AbstractPacket *Create() override {
    return new AirVehicleGroundRelativeState();
  }
    
  /**
    Data.
  */
  uint16_t vehicle_id;
	float angle_of_attack;
	float angle_of_sideslip;
	float true_airspeed;
	float indicated_airspeed;
	float north_wind_speed;
	float east_wind_speed;
	float north_ground_speed;
	float east_ground_speed; 
	float barometric_pressure;
	float barometric_altitude;
};
} // ngcp
#endif // NGCP_Air_Vehicle_Ground_Relative_State_HPP
