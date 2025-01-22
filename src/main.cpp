#include <Arduino.h>
#include <SynthKeyController.h>

// Configurable constants
const uint8_t NUMBER_OF_VOICES = 5;
const uint8_t NUMBER_OF_KEYS = 36;
const uint8_t VOICE_DAC_PINS[NUMBER_OF_VOICES] = {1, 2, 3, 4, 5};
const uint8_t VOICE_GATE_PINS[NUMBER_OF_VOICES] = {6, 7, 8, 9, 10};

void setup() {
  // put your setup code here, to run once:
  SynthKeyController synthKeyController(NUMBER_OF_VOICES, NUMBER_OF_KEYS);

  synthKeyController.updateVoice_pins(VOICE_DAC_PINS, VOICE_GATE_PINS);


}

void loop() {
  // put your main code here, to run repeatedly:
}
