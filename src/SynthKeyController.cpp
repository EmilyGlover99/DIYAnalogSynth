#include "SynthKeyController.h"
#include "Arduino.h"


SynthKeyController::SynthKeyController(){
    this->resetVoiceAllocation();
}

void SynthKeyController::resetVoiceAllocation(){
    for (int i = 0 ; i < this->maxNumOfVoices ; i++ ){
        this->voiceAllocation[i] = -1;
    }   
}

void SynthKeyController::updateCurrentlyPressedKeys(){
    // Scan through the key matrix to see which keys are being pressed
    uint8_t keyNumber = 0; 
    for (byte o=0 ; o < 4 ; o++){ //for each output pin
        digitalWrite(this->keyboardMatrixOutput_pins[o], HIGH); 
        for (byte i=0 ; i < 10 ; i++){ //for each input pin   
            this->pressedKeys[keyNumber] = digitalRead(this->keyboardMatrixInput_pins[i]);  
            keyNumber += 1;
        }  
        digitalWrite(keyboardMatrixOutput_pins[o], LOW);
    } 
}

void SynthKeyController::removeDepressedKeysFromVoiceAllocation() {
    // When a key is no longer being pressed, remove it from the voiceAllocation
    for (int voice = 0 ; voice < this->maxNumOfVoices ; voice++) {
        // Check if the voice is already assigned
        if (this->voiceAllocation[voice] != -1) {
            if (this->pressedKeys[this->voiceAllocation[voice]] != 1) {
            this->voiceAllocation[voice] = -1;
            }
        }
    }
}

void SynthKeyController::updateNewPressedKeys() {
    // Until the maximum number of voices is being used, loop through the pressed keys and allocate them a voice
    uint8_t numOfVoicesUsed = 0;

    for (int key = 0 ; key < 36 ; key++) {
        if (this->pressedKeys[key]) {
            // Check if the key is already in a voice
            bool keyAlreadyInVoiceArray = 0;

            for (int voice = 0 ; voice < this->maxNumOfVoices ; voice++) {
                if (this->voiceAllocation[voice] == key) {
                    keyAlreadyInVoiceArray = 1;
                    numOfVoicesUsed += 1;
                    break;
                }
            }

            if (keyAlreadyInVoiceArray == 0) {
                // The key wasn't pressed before but now is. We should add it to the voices array
                for (int voice = 0 ; voice < this->maxNumOfVoices ; voice++){
                    if (this->voiceAllocation[voice] == -1) {
                        this->voiceAllocation[voice] = key;
                        numOfVoicesUsed += 1;
                        break;
                    }
                } 
            }
            
            // Check if all the voices are full and break if they are
            if (numOfVoicesUsed == this->maxNumOfVoices) {
                break;
            }
        }
    }
}

void SynthKeyController::updateVoiceAllocation() {
    // Allocate each voice with a key (but don't overwrite existing voices that are still being used)
    this->updateCurrentlyPressedKeys();
    this->removeDepressedKeysFromVoiceAllocation();
    this->updateNewPressedKeys();
}

void SynthKeyController::setGatePins() {

}

void SynthKeyController::setOscillatorDACs() {

}

void SynthKeyController::setOSCRelatedPins() {
    this->setOscillatorDACs();
    this->setGatePins();

}

void SynthKeyController::manageOSCs() {
    // When this function is run, each key of the keyboard will be scanned and the relevant gate and cv signals will be output from the arduino
    this->updateVoiceAllocation();
    this->setOSCRelatedPins();
}


