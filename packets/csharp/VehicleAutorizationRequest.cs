/*
	C# Wrapper VehicleAuthorization
	

	Copyright (C) 2016-2017  Northrup Grumman Collaboration Project.
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
  
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
  
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Comnet;

namespace NGCP
{ 
	/**
	 * VehicleAuthorizationRequest Packet Template. 
	 */
	class VehicleAuthorizationRequest : ABSPacket 
	{
		public VehicleAuthorizationRequest(UInt16 vehicleid = 0, 
			Byte vehicleType = 0, Byte authorizationServices = 0, 
			Byte grantedServices = 0) 
		: base("VehicleAuthorizationRequest") 
		{
		}

		public override ABSPacket Create() 
		{
			return new VehicleAuthorizationRequest();
		}

		public override void Pack(ObjectStream obj) 
		{
			obj.Input(VehicleId);
			obj.Input(VehicleType);
			obj.Input(AuthorizationServices);
			obj.Input(GrantedServices);
		}

		public override void Unpack(ObjectStream obj) 
		{
			GrantedServices = obj.OutputByte();
			AuthorizationServices = obj.OutputByte();
			VehicleType = obj.OutputByte();
			VehicleId = obj.OutputUInt16();
		}

		#region Data
		public UInt16 VehicleId { get; set; }
		public Byte VehicleType { get; set; }
		public Byte AuthorizationServices { get; set; }
		public Byte GrantedServices { get; set; }
		#endregion
	}
}