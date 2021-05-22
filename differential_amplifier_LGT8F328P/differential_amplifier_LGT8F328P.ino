//============================================
// Differential Amplifier demo for LGT8F328x
// by dbuezas
// Using new differential_amplifier library.
// Differential read from all analog pin combinations
//============================================
#include "differential_amplifier.h"


void setup() {
  Serial.begin(230400);
  // analogReference(DEFAULT);  // 5v
}
void loop() {
  int value = analogDiffRead(A0, A1, GAIN_1);
  if (value < 0) {
    Serial.println("[ERROR] Cannot combine these PINs");
    return;
  }
  Serial.print((value*1.0 / 819));
  Serial.print("V\t");
  Serial.print(value);
  Serial.println();
  delay(100);
}
