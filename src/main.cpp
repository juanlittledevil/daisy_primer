#include "daisy_seed.h"
#include "sc_tools.h"
#include "sc_config.h"

using namespace daisy;
using namespace daisy::seed;

DaisySeed hw;

int main(void)
{
    // Initialize the Daisy Seed
    hw.Configure();
    hw.Init();

    if (DEBUG) 
    {
        // Start the Serial Logger
        hw.StartLog();

        // Print the Daisy Seed information
        debug_print("Daisy Seed Initialized");
    }

    Led led;

    // Configure pin for LED.
    led.Init(hw.GetPin(25), false);

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

        // Normalize the potentiometer value to a range of 0.0 to 1.0
        float normalized_value = static_cast<float>(pot_value) / 65535.0f;
        
        // Convert normalized value to percentage
        int percentage_value = static_cast<int>(normalized_value * 100);

        // Set the USER LED brightness based on the potentiometer value
        float brightness = hw.adc.GetFloat(0);
        led.Set(brightness);
        led.Update();

        if (DEBUG)
        {
            debug_print("Raw ADC Value: %d", pot_value);
            debug_print("Potentiometer Value: %d%%", percentage_value);
            debug_print("LED Brightness: " FLT_FMT(3), FLT_VAR(3, brightness));;
            // Delay to avoid flooding the serial output
            System::Delay(250);
        }
    }
}