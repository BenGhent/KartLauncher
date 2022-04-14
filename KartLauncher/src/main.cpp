#include <Arduino.h>
#include "Config/pins.h"
#include "SevenSegment/sevenSegment.h"

sevenSegment seg;

void setup() {
  // put your setup code here, to run once:
  seg.init(); // Init the data for seven segment
}

void loop() {
  // put your main code here, to run repeatedly:
}