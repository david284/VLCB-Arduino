// Copyright (C) Sven Rosvall (sven@rosvall.ie)
// This file is part of VLCB-Arduino project on https://github.com/SvenRosvall/VLCB-Arduino
// Licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
// The full licence can be found at: http://creativecommons.org/licenses/by-nc-sa/4.0/

#pragma once

#include "Service.h"

namespace VLCB
{

class Configuration;

class MinimumNodeService : public Service
{

public:

  virtual void setController(Controller *cntrl) override;
  virtual void process(UserInterface::RequestedAction requestedAction) override; 
  virtual Processed handleMessage(unsigned int opc, CANFrame *msg) override;

  virtual byte getServiceID() override { return 1; }
  virtual byte getServiceVersionID() override { return 1; }
  void setHeartBeat(bool f) { noHeartbeat = !f; }

private:

  Controller *controller;
  Configuration * module_config;  // Shortcut to reduce indirection code.
  
  bool bModeChanging = false;
  unsigned long timeOutTimer;
  void checkModeChangeTimeout();
  void indicateMode(byte mode);
  void initSetup();
  void setNormal();
  void setUninitialised();
  void initSetupFromNormal();
  void renegotiate();
  void heartbeat();
  
  unsigned long lastHeartbeat = 0;
  byte heartbeatSequence = 0;
  bool noHeartbeat = false;
  unsigned int heartRate = 5000;
};

}