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

#ifndef AURA_GPSPROTOCOL_H_
#define AURA_GPSPROTOCOL_H_

//
// CGameProtocol
//

#define GPS_HEADER_CONSTANT 248

#define REJECTGPS_INVALID 1
#define REJECTGPS_NOTFOUND 2

class CGPSProtocol
{
public:
  enum Protocol
  {
    GPS_INIT      = 1,
    GPS_RECONNECT = 2,
    GPS_ACK       = 3,
    GPS_REJECT    = 4
  };

  CGPSProtocol();
  ~CGPSProtocol();

  // receive functions

  // send functions

  std::vector<uint_fast8_t> SEND_GPSC_INIT(uint_fast32_t version);
  std::vector<uint_fast8_t> SEND_GPSC_RECONNECT(uint_fast8_t PID, uint_fast32_t reconnectKey, uint_fast32_t lastPacket);
  std::vector<uint_fast8_t> SEND_GPSC_ACK(uint_fast32_t lastPacket);
  std::vector<uint_fast8_t> SEND_GPSS_INIT(uint_fast16_t reconnectPort, uint_fast8_t PID, uint_fast32_t reconnectKey, uint_fast8_t numEmptyActions);
  std::vector<uint_fast8_t> SEND_GPSS_RECONNECT(uint_fast32_t lastPacket);
  std::vector<uint_fast8_t> SEND_GPSS_ACK(uint_fast32_t lastPacket);
  std::vector<uint_fast8_t> SEND_GPSS_REJECT(uint_fast32_t reason);
};

#endif // AURA_GPSPROTOCOL_H_
