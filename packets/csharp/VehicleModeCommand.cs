/*
 C# Wrapper VehicleModeCommand
 

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
using Comnet.Serialization;

namespace NGCP
{
  class VehicleModeCommand : ABSPacket
  {
    public VehicleModeCommand(UInt16 vehicleID = 0, Byte vehicleMode = 0)
      : base("VehicleModeCommand")
    {

    }

    public override void Pack(ObjectStream objOut)
    {
      objOut.Input(VehicleID);
      objOut.Input(VehicleMode);
    }

    public override void Unpack(ObjectStream obj)
    {
      VehicleMode = obj.OutputByte();
      VehicleID = obj.OutputUInt16();
    }

    public override ABSPacket Create()
    {
      return new VehicleModeCommand();
    }

    #region Data
    public UInt16 VehicleID { get; set; }
    public Byte VehicleMode { get; set; }
    #endregion
  }
}
