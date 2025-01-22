// #include <Arduino.h>
#include <unity.h>
#include <SynthKeyController.h>


// Configurable constants
const uint8_t NUMBER_OF_VOICES = 5;
const uint8_t NUMBER_OF_KEYS = 36;
const uint8_t VOICE_DAC_PINS[NUMBER_OF_VOICES] = {1, 2, 3, 4, 5};
const uint8_t VOICE_GATE_PINS[NUMBER_OF_VOICES] = {6, 7, 8, 9, 10};

void test_updateVoice_pins() {
    TEST_ASSERT_EQUAL(1, 1);
}

void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_updateVoice_pins);

    UNITY_END();
}

void loop(){
    // Do nothing
}

int main() {
    setup();
    // loop();
    return 0;
}