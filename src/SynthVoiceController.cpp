#include "SynthVoiceController.h"
#include "Arduino.h"

SynthVoiceController::SynthVoiceController() {
    this->controlVoltageOffset = 0;
}

float SynthVoiceController::getOffsettedControlVoltage(float controlVoltage) {
    float sumControlVoltage = controlVoltage + controlVoltageOffset;
    return this->convertCVToDACSignal(sumControlVoltage);

}

void SynthVoiceController::setGatePin(uint8_t gate_pin) {
    this->gate_pin = gate_pin;
}

void SynthVoiceController::setDACCSPin(uint8_t DACcontrolVoltage_pin) {
    this->DACcontrolVoltage_pin = DACcontrolVoltage_pin;
}

void SynthVoiceController::setPinModes() {
    pinMode(this->gate_pin, OUTPUT);
    pinMode(this->DACcontrolVoltage_pin, OUTPUT);
}

float SynthVoiceController::convertCVToDACSignal(float controlVoltage) {
      //Set this for the DAC being used. In the case of MCP 4822, 1000 = 1v and 2000 = 2v.
      return controlVoltage;
    }

void SynthVoiceController::updateCVOffset (float newControlVoltageOffset) {
    this->controlVoltageOffset = newControlVoltageOffset;
}
