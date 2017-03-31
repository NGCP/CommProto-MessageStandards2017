/**
AirVehicleGroundRelativeState

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
#ifndef NGCP_AIR_VEHICLE_GROUND_RELATIVE_STATE_HPP
#define NGCP_AIR_VEHICLE_GROUND_RELATIVE_STATE_HPP


#include <CommProto/commproto.h>


namespace ngcp {

  struct AirVehicleGroundRelativeState : INHERITS_ABSPACKET {
    /**
    Creates an instance
    */
    AirVehicleGroundRelativeState(uint16_t vehicle_id = 0,
      real32_t angle_of_attack = 0,
      real32_t angle_of_sideslip = 0,
      real32_t true_airspeed = 0,
      real32_t indicated_airspeed = 0,
      real32_t north_wind_speed = 0,
      real32_t east_wind_speed = 0,
      real32_t north_ground_speed = 0,
      real32_t east_ground_speed = 0,
      real32_t barometric_pressure = 0,
      real32_t barometric_altitude = 0)
      : CHAIN_ABSPACKET(AirVehicleGroundRelativeState),
      vehicle_id(vehicle_id),
      angle_of_attack(angle_of_attack),
      angle_of_sideslip(angle_of_sideslip),
      true_airspeed(true_airspeed),
      indicated_airspeed(indicated_airspeed),
      north_wind_speed(north_wind_speed),
      east_wind_speed(east_wind_speed),
      north_ground_speed(north_ground_speed),
      east_ground_speed(east_ground_speed),
      barometric_pressure(barometric_pressure),
      barometric_altitude(barometric_altitude)
    {
    }


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
    //radians
    real32_t angle_of_attack;
    //radians
    real32_t angle_of_sideslip;
    //meters/second
    real32_t true_airspeed;
    //meters/second
    real32_t indicated_airspeed;
    //meters/second
    real32_t north_wind_speed;
    //meters/second
    real32_t east_wind_speed;
    //meters/second
    real32_t north_ground_speed;
    //meters/second
    real32_t east_ground_speed;
    //pascals
    real32_t barometric_pressure;
    //meters
    real32_t barometric_altitude;
  };
} // ngcp
#endif // NGCP_AIR_VEHICLE_GROUND_RELATIVE_STATE_HPP

