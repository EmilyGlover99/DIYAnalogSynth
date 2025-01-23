#pragma once

#include <stdint.h> // For uint8_t, int8_t
#include <SynthVoiceController.h>

class SynthKeyController {
    private:
        // Maximum number of voices, constrained by the physical synthesizer components
        uint8_t maxNumOfVoices;

        // Number of physical keys on the keyboard
        uint8_t numOfPhysicalKeys;

        // Arduino pins for the keyboard matrix
        uint8_t keyboardMatrixInput_pins[10] = {45, 44, 43, 47, 46, 48, 49, 50, 42, 41};
        uint8_t keyboardMatrixOutput_pins[4] = {22, 23, 24, 25};
        
        // Pointer to store the current usage of physical voices
        uint8_t* voiceAllocation = nullptr;

        // Pointer to store the array of SynthVoice classes
        SynthVoiceController* synthVoices = nullptr;

        // Pointer to store the current usage of pressed keys
        bool* pressedKeys = nullptr;

    public:
        SynthKeyController(uint8_t maxNumOfVoices, uint8_t numOfPhysicalKeys);

        void resetVoiceAllocation();

        void resetPressedKeys();

        void updateVoice_pins(const uint8_t* DACCS_pins, const uint8_t* gate_pins);

        void updateCurrentlyPressedKeys();

        void removeDepressedKeysFromVoiceAllocation();

        void updateNewPressedKeys();

        void updateVoiceAllocation();

        void setOscillatorDACs();

        void setGatePins();

        void setOSCRelatedPins();

        void manageOSCs();

        uint8_t getNumOfPhysicalKeys();

        uint8_t getNumOfVoices();

        uint8_t** getAllVoice_pins();

};