#include "SynthVoiceController.h"
#include "Arduino.h"

SynthVoiceController::SynthVoiceController(uint8_t gate_pin, uint8_t DACcontrolVoltage_pin) {
    this->gate_pin = gate_pin;
    pinMode(this->gate_pin, OUTPUT);
    this->DACcontrolVoltage_pin = DACcontrolVoltage_pin;
    pinMode(this->DACcontrolVoltage_pin, OUTPUT);
    this->controlVoltageOffset = 0;
}

float SynthVoiceController::getOffsettedControlVoltage(float controlVoltage) {
    float sumControlVoltage = controlVoltage + controlVoltageOffset;
    return this->convertCVToDACSignal(sumControlVoltage);

}

float SynthVoiceController::convertCVToDACSignal(float controlVoltage) {
      //Set this for the DAC being used. In the case of MCP 4822, 1000 = 1v and 2000 = 2v.
      return controlVoltage;
    }

void SynthVoiceController::updateCVOffset (float newControlVoltageOffset) {
    this->controlVoltageOffset = newControlVoltageOffset;
}
