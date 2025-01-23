#pragma once

#include <stdint.h>

class SynthVoiceController {
    private:
        uint8_t gate_pin;
        uint8_t DACCS_pin;
        float controlVoltageOffset;

    public:
        SynthVoiceController();

        void setGatePin(uint8_t gate_pin);

        void setDACCSPin(uint8_t DACcontrolVoltage_pin);

        void setPinModes();

        float getOffsettedControlVoltage(float controlVoltage);

        float convertCVToDACSignal(float offsettedControlVoltage);

        void updateCVOffset(float newControlVoltageOffset);

        uint8_t getGatePin();

        uint8_t getDACCSPin();

};