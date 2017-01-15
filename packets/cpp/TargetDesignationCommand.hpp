#ifndef NGCP_Target_Designation_Command_HPP
#define NGCP_Target_Designation_Command_HPP


#include <CommProto/abstractpacket.h>


namespace ngcp {
  
struct TargetDesignationCommand : INHERITS_ABSPACKET {
  TargetDesignationCommand(uint16_t dest_id = 0,
    uint16_t vehicle_id = 0, 
    uint8_t payload_id = 0,
    uint8_t target_id = 0,
    uint8_t target_type = 0,
    int32_t latitude = 0,
    int32_t longitutude = 0,
    int32_t altitude = 0) 
    : CHAIN_ABSPACKET(TargetDesignationCommand)
		, dest_id(dest_id)
    , vehicle_id(vehicle_id)
    , payload_id(payload_id)
    , target_id(target_id)
		, target_type(target_type)
		, latitude(latitude)
		, longitude(longitude)
		, altitude(altitude)
    { }
  
  
  /**
    Pack data into the stream for sending out.
  */
  void Pack(comnet::ObjectStream &obj) override {
    obj << dest_id;
    obj << vehicle_id;
    obj << payload_id;
		obj << target_id;
		obj << target_type;
		obj << latitude;
		obj << longitude;
		obj << altitude;
  }
  
  
  /**
    Unpack data back into this packet when receiving data.
  */
  void Unpack(comnet::ObjectStream &obj) override {
    obj >> altitude;
    obj >> longitude;
    obj >> latitude;
    obj >> target_type;
    obj >> target_id;
    obj >> payload_id;
    obj >> vehicle_id;
    obj >> dest_id;
  }
  
  
  /**
    Tells CommProtocol how to recreate the TargetDesignationCommand packet
    when receiving data.
  */
  comnet::AbstractPacket *Create() override {
    return new TargetDesignationCommand();
  }
    
  /**
    Data.
  */
  uint16_t dest_id;
	uint16_t vehicle_id;
	uint8_t payload_id;
	uint8_t target_id;
	uint8_t target_type;
	int32_t latitude;
	int32_t longitude;
	int32_t altitude;
};
} // ngcp
#endif // NGCP_Target_Designation_Command_HPP
