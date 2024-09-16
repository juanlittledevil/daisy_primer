#include "daisy_seed.h"
#include "sc_tools.h"
#include "sc_config.h"

using namespace daisy;

DaisySeed hw;

int main(void)
{
    // Initialize the Daisy Seed
    hw.Configure();
    hw.Init();

    // Start the USB peripheral, but only if we are in debug mode
    // Debug mode is configured in sc_config.h file. See /include/sc_config.h
    if (DEBUG) 
    {
        // Start the Serial Logger
        hw.StartLog();
    }

    // Print the Daisy Seed information
    debug_print("Daisy Seed Initialized");

    Led led;

    // Configure pin for LED.
    led.Init(seed::D18, false);
    led.SetSampleRate(10000.0f); // 10kHz update rate for smooth brightness changes.

    // Configure the ADC for the potentiometer
    AdcChannelConfig adc_cfg;
    adc_cfg.InitSingle(seed::A0);

    // Initialize the ADC with our configuration
    hw.adc.Init(&adc_cfg, 1);

    // Start the ADC conversions in the background
    hw.adc.Start();

    while(1)
    {
        // Read the potentiometer value
        uint16_t pot_value = hw.adc.Get(0);
        debug_print("Raw ADC Value: %d", pot_value);

        // Normalize the potentiometer value to a range of 0.0 to 1.0
        float normalized_value = static_cast<float>(pot_value) / 65535.0f;
        
        // Convert normalized value to percentage
        int percentage_value = static_cast<int>(normalized_value * 100);
        debug_print("Potentiometer Value: %d%%", percentage_value);

        // Set the USER LED brightness based on the potentiometer value
        float brightness = hw.adc.GetFloat(0);
        debug_print("LED Brightness: " FLT_FMT(3), FLT_VAR(3, brightness));;
        led.Set(brightness);
        led.Update();

        if (DEBUG)
        {
            // Delay to avoid flooding the serial output
            // NOTE: This delay will impact the LED brightness.
            // Only use it for debugging purposes.
            System::Delay(250);
        }
    }
}