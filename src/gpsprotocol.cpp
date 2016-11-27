/*

   Copyright [2010] [Josko Nikolic]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

 */

#include "aura.h"
#include "util.h"
#include "gpsprotocol.h"

//
// CGPSProtocol
//

CGPSProtocol::CGPSProtocol() = default;

CGPSProtocol::~CGPSProtocol() = default;

///////////////////////
// RECEIVE FUNCTIONS //
///////////////////////

////////////////////
// SEND FUNCTIONS //
////////////////////

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSC_INIT(uint_fast32_t version)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_INIT, 8, 0};
  AppendByteArray(packet, version, false);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSC_RECONNECT(uint_fast8_t PID, uint_fast32_t reconnectKey, uint_fast32_t lastPacket)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_RECONNECT, 13, 0, PID};
  AppendByteArray(packet, reconnectKey, false);
  AppendByteArray(packet, lastPacket, false);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSC_ACK(uint_fast32_t lastPacket)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_ACK, 8, 0};
  AppendByteArray(packet, lastPacket, false);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSS_INIT(uint_fast16_t reconnectPort, uint_fast8_t PID, uint_fast32_t reconnectKey, uint_fast8_t numEmptyActions)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_INIT, 12, 0};
  AppendByteArray(packet, reconnectPort, false);
  packet.push_back(PID);
  AppendByteArray(packet, reconnectKey, false);
  packet.push_back(numEmptyActions);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSS_RECONNECT(uint_fast32_t lastPacket)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_RECONNECT, 8, 0};
  AppendByteArray(packet, lastPacket, false);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSS_ACK(uint_fast32_t lastPacket)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_ACK, 8, 0};
  AppendByteArray(packet, lastPacket, false);
  return packet;
}

std::vector<uint_fast8_t> CGPSProtocol::SEND_GPSS_REJECT(uint_fast32_t reason)
{
  std::vector<uint_fast8_t> packet = {GPS_HEADER_CONSTANT, GPS_REJECT, 8, 0};
  AppendByteArray(packet, reason, false);
  return packet;
}
