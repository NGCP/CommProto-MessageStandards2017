/*
 VehicleBodySensedState
 

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
   * VehicleBodySensedState Packet Template. 
   */
  class VehicleBodySensedState : ABSPacket
  {
    public VehicleBodySensedState(UInt16 vehicle_id = 0,
      Int16 x_accel = 0,
      Int16 y_accel = 0,
      Int16 z_accel = 0,
      Int16 roll_rate = 0,
      Int16 pitch_rate = 0,
      Int16 yaw_rate = 0)
      : base("VehicleBodySensedState")
    {
      this.vehicle_id = vehicle_id;
      this.x_accel = x_accel;
      this.y_accel = y_accel;
      this.z_accel = z_accel;
      this.roll_rate = roll_rate;
      this.pitch_rate = pitch_rate;
      this.yaw_rate = yaw_rate;
    }

    public override ABSPacket Create()
    {
      return new VehicleBodySensedState();
    }

    public override void Pack(ObjectStream obj)
    {
      obj.Input(vehicle_id);
      obj.Input(x_accel);
      obj.Input(y_accel);
      obj.Input(z_accel);
      obj.Input(roll_rate);
      obj.Input(pitch_rate);
      obj.Input(yaw_rate);
    }

    public override void Unpack(ObjectStream obj)
    {
      yaw_rate = obj.OutputInt16();
      pitch_rate = obj.OutputInt16();
      roll_rate = obj.OutputInt16();
      z_accel = obj.OutputInt16();
      y_accel = obj.OutputInt16();
      x_accel = obj.OutputInt16();
      vehicle_id = obj.OutputUInt16();
    }

    #region Data
    public UInt16 vehicle_id { get; set; }
    public Int16 x_accel { get; set; }
    public Int16 y_accel { get; set; }
    public Int16 z_accel { get; set; }
    public Int16 roll_rate { get; set; }
    public Int16 pitch_rate { get; set; }
    public Int16 yaw_rate { get; set; }
    #endregion
  }
}

