#pragma once

#include <stdint.h>

class SynthVoiceController {
    private:
        uint8_t gate_pin;
        uint8_t DACcontrolVoltage_pin;
        float controlVoltageOffset;

    public:
        SynthVoiceController(uint8_t gate_pin, uint8_t DACcontrolVoltage_pin);

        float getOffsettedControlVoltage(float controlVoltage);

        float convertCVToDACSignal(float offsettedControlVoltage);

        void updateCVOffset(float newControlVoltageOffset);

}