# CommProto-MessageStandards2017
Message Standards for the Communication Protocol - as of 2017.
  
Message standards are held to be official for all Platforms in order to maintain 
well-documented packets. These standards describe:
  
  - Packet Structure
  - Data type size structure
  - Measurement units
  - Packet descriptions
  
Once packets are official, platforms must implement them into their source code for 
universal communications toward one another. This helps maintain robustness, as well as
organization and freedom of implementation, as long as packets are communicated as described
by the standard documents in this repository.

# Obtaining Defined Messaging Packets
For ease of use, this repository contains the Packet Templates of the offical messages covered.
Message Packets are written for C++ and C# use. Look inside the 'packets' directory and 
determine the files you need for your platform. C++ is implemented as header-only files,
while C# is the usual .cs files. Keep in mind that these files are merely templates for each
packet and its structure, so it is up to the platforms to determine how to use them in their
software.