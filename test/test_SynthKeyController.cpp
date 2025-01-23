#include <ArduinoFake.h>
#include <unity.h>
#include <SynthKeyController.h>

using namespace fakeit;

// Configurable constants
const uint8_t NUMBER_OF_VOICES = 5;
const uint8_t NUMBER_OF_KEYS = 36;
const uint8_t VOICE_DAC_PINS[NUMBER_OF_VOICES] = {1, 2, 3, 4, 5};
const uint8_t VOICE_GATE_PINS[NUMBER_OF_VOICES] = {6, 7, 8, 9, 10};

void test_NumberOfVoices() {
    SynthKeyController synthKeyController(NUMBER_OF_VOICES, NUMBER_OF_KEYS);
    TEST_ASSERT_EQUAL(NUMBER_OF_VOICES, synthKeyController.getNumOfVoices());
}
void test_NumberOfKeys() {
    SynthKeyController synthKeyController(NUMBER_OF_VOICES, NUMBER_OF_KEYS);
    TEST_ASSERT_EQUAL(NUMBER_OF_KEYS, synthKeyController.getNumOfPhysicalKeys());
}

void test_Voice_pins() {
    SynthKeyController synthKeyController(NUMBER_OF_VOICES, NUMBER_OF_KEYS);
    synthKeyController.updateVoice_pins(VOICE_DAC_PINS, VOICE_GATE_PINS);

    // uint8_t** voice_pins = synthKeyController.getAllVoice_pins();

    // for (uint8_t i = 0; i < NUMBER_OF_VOICES; i++) {
    //     TEST_ASSERT_EQUAL(voice_pins[0][i], VOICE_DAC_PINS[i]);
    //     TEST_ASSERT_EQUAL(voice_pins[1][i], VOICE_GATE_PINS[i]);
    // }

    // delete[] voice_pins[0];
    // delete[] voice_pins[1];
    // delete[] voice_pins;
}

void test_setup() {
    UNITY_BEGIN();

    RUN_TEST(test_NumberOfVoices);
    RUN_TEST(test_NumberOfKeys);
    RUN_TEST(test_Voice_pins);
    UNITY_END();
}

void test_loop(){
    // Do nothing
}

int main() {
    test_setup();
    // loop();
    return 0;
}