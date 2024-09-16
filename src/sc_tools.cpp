#include "sc_tools.h"
#include "daisy_seed.h"
#include <cstdarg> // For va_list, va_start, va_end
#include <cstdio>  // For vsnprintf
#include <cstring> // For strstr

using namespace daisy;

extern DaisySeed hw;

void debug_print(const char* format, ...)
{
    if (DEBUG)
    {
        char buffer[256];
        va_list args;
        va_start(args, format);

        // Check if the format string contains a floating-point specifier
        if (strstr(format, "%f") != nullptr)
        {
            // Handle floating-point numbers using FLT_FMT and FLT_VAR macros
            float float_arg = va_arg(args, double); // float is promoted to double in va_arg
            snprintf(buffer, sizeof(buffer), format, FLT_VAR(3, float_arg)); // Adjust precision as needed
        }
        else
        {
            // Handle non-floating-point numbers
            vsnprintf(buffer, sizeof(buffer), format, args);
        }

        va_end(args);
        hw.PrintLine("%s", buffer);
    }
}