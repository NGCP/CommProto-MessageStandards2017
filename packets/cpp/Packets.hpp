/**
  Packet Templates.
  
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
#ifndef __COMM_PACKETS_HPP
#define __COMM_PACKETS_HPP

/*

  FORWARD DECLARING ALL HEADERS

 
*/

/*
  Packets defining the State of the vehicle.
*/
#include "AirVehicleGroundRelativeState.hpp"
#include "Battery.hpp"

/*
  Packets defining Target status and acknowledgement.
*/
#include "TargetAcknowledgement.hpp"
#include "TargetDesignationCommand.hpp"
#include "TargetStatus.hpp"

/*
  Vehicle Command packets.
*/
#include "VehicleAuthorizationReply.hpp"
#include "VehicleAuthorizationRequest.hpp"
#include "VehicleIdentification.hpp"
#include "VehicleInertialState.hpp"
#include "VehicleModeCommand.hpp"
#include "VehicleSystemStatus.hpp"
#include "VehicleWaypointCommand.hpp"

#endif // __COMM_PACKETS_HPP