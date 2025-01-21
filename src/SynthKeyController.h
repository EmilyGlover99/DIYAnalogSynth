#pragma once

#include <stdint.h> // For uint8_t, int8_t

class SynthKeyController {
    private:
        // Maximum number of voices, constrained by the physical synthesizer components
        static const uint8_t maxNumOfVoices = 5;

        // Arduino pins for the keyboard matrix
        uint8_t keyboardMatrixInput_pins[10] = {45, 44, 43, 47, 46, 48, 49, 50, 42, 41};
        uint8_t keyboardMatrixOutput_pins[4] = {22, 23, 24, 25};
        
        // Voice allocation array to store the current usage of physical voices
        int8_t voiceAllocation[maxNumOfVoices] = {-1, -1, -1, -1, -1};

        // Store which keys are being pressed

        bool pressedKeys[36];

    public:
        SynthKeyController();

        void resetVoiceAllocation();

        void updateCurrentlyPressedKeys();

        void removeDepressedKeysFromVoiceAllocation();

        void updateNewPressedKeys();

        void updateVoiceAllocation();

        void setOscillatorDACs();

        void setGatePins();

        void setOSCRelatedPins();

        void manageOSCs();

};