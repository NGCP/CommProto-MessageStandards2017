using Comnet;

namespace NGCP
{ 
	/**
	 * VehicleAuthorizationRequest Packet Template. 
	 */
	class VehicleAutorizationRequest : ABSPacket 
	{
		public VehicleAutorizationRequest(UInt16 vehicleid = 0, 
			Byte vehicleType = 0, Byte authorizationServices = 0, 
			Byte grantedServices = 0) 
		: base("VehicleAuthorizationRequest") 
		{
		}

		public override ABSPacket Create() 
		{
			return new VehicleAutorizationRequest();
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