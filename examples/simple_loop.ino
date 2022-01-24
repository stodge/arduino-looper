#include "looper.hpp"

// Initialise looper
Looper looper;


void setup() {
  Serial.begin(9600);
  while (!Serial) {};

  // We can overwrite the interval (ms)
  looper.set_interval(1000);
}

void loop() {
  // Periodically write to serial
  if (looper.tick()) {
    Serial.println("Hello World!");
  }
}
