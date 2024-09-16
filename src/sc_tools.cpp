#include "sc_tools.h"
#include "daisy_seed.h"
#include <cstdarg> // For va_list, va_start, va_end
#include <cstdio>  // For vsnprintf

using namespace daisy;
using namespace daisy::seed;

extern DaisySeed hw;

void debug_print(const char* format, ...)
{
    if (DEBUG)
    {
        char buffer[256];
        va_list args;
        va_start(args, format);
        vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        hw.PrintLine("%s", buffer);
    }
}