#ifndef SC_TOOLS_H
#define SC_TOOLS_H

#include <cstdio>

// Function to convert a float to a string with a specified number of decimal places
void FloatToString(float value, char* buffer, int decimal_places = 2)
{
    // Create the format string for snprintf
    char format[10];
    snprintf(format, sizeof(format), "%%.%df", decimal_places);

    // Convert the float to a string using snprintf
    snprintf(buffer, 50, format, value);
}

#endif // SC_TOOLS_H
