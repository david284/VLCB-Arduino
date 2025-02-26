// Copyright (C) Martin Da Costa 2023 (martindc.merg@gmail.com)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include "Service.h"
#include <vlcbdefs.hpp>

namespace VLCB {

struct VlcbMessage;

class EventProducerService : public Service {
public:
  void setRequestEventHandler(void (*fptr)(byte index, const VlcbMessage *msg));
  virtual void process(const Action * action) override;

  virtual VlcbServiceTypes getServiceID() const override
  {
    return SERVICE_ID_PRODUCER;
  }
  virtual byte getServiceVersionID() const override
  {
    return 1;
  }
  void begin() override;
  void sendEvent(bool state, byte evValue);
  void sendEvent(bool state, byte evValue, byte data1);
  void sendEvent(bool state, byte evValue, byte data1, byte data2);
  void sendEvent(bool state, byte evValue, byte data1, byte data2, byte data3);
  void sendEventResponse(bool state, byte index);
  void sendEventResponse(bool state, byte index, byte data1);
  void sendEventResponse(bool state, byte index, byte data1, byte data2);
  void sendEventResponse(bool state, byte index, byte data1, byte data2, byte data3);
  

private:
  void (*requesteventhandler)(byte index, const VlcbMessage *msg);
  void handleProdSvcMessage(const VlcbMessage *msg);
  
  void setProducedEvents();
  byte createDefaultEvent(byte evValue);
  void findOrCreateEventByEv(byte evIndex, byte evValue, byte tarr[]);
  void sendMessage(VlcbMessage &msg, byte opCode, const byte *nn_en);

  bool uninit = false;
  
protected:
  unsigned int diagEventsProduced = 0;

};

}  // VLCB
