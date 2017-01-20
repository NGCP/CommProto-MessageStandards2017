/*
 TargetDesignationCommand
 

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
  /**
   * TargetDesignationCommand Packet Template. 
   */
  class TargetDesignationCommand : ABSPacket
  {
    public TargetDesignationCommand(UInt16 vehicle_id = 0,
      Byte payload_id = 0,
      Byte target_id = 0,
      Byte target_type = 0,
      Int32 latitude = 0,
      Int32 longitude = 0,
      Int32 altitude = 0)
      : base("TargetDesignationCommand")
    {
      this.vehicle_id = vehicle_id;
      this.payload_id = payload_id;
      this.target_id = target_id;
      this.target_type = target_type;
      this.latitude = latitude;
      this.longitude = longitude;
      this.altitude = altitude;
    }

    public override ABSPacket Create()
    {
      return new TargetDesignationCommand();
    }

    public override void Pack(ObjectStream obj)
    {
      obj.Input(vehicle_id);
      obj.Input(payload_id);
      obj.Input(target_id);
      obj.Input(target_type);
      obj.Input(latitude);
      obj.Input(longitude);
      obj.Input(altitude);
    }

    public override void Unpack(ObjectStream obj)
    {
      altitude = obj.OutputInt32();
      longitude = obj.OutputInt32();
      latitude = obj.OutputInt32();
      target_type = obj.OutputByte();
      target_id = obj.OutputByte();
      payload_id = obj.OutputByte();
      vehicle_id = obj.OutputUInt16();
    }

    #region Data
    public UInt16 vehicle_id { get; set; }
    public Byte payload_id { get; set; }
    public Byte target_id { get; set; }
    public Byte target_type { get; set; }
    public Int32 latitude { get; set; }
    public Int32 longitude { get; set; }
    public Int32 altitude { get; set; }
    #endregion
  }
}

