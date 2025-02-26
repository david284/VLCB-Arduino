#pragma once

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#define F(s) s

typedef unsigned char byte;

enum PinState {LOW = 0, HIGH = 1};
enum PinMode {OUTPUT, INPUT, INPUT_PULLUP};

unsigned long millis();
void delay(unsigned int);
byte highByte(unsigned int);
byte lowByte(unsigned int);
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
void pinMode(int, PinMode);
void digitalWrite(int, int);
byte digitalRead(int);

struct Serial_T
{
  void begin(int baudrate);

  bool available();
  char read();
  void flush();
  unsigned char readBytesUntil(int termChar, char *string, int length);
  void print(const char *);
  void println(const char *);
};
extern struct Serial_T Serial;