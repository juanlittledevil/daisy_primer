#ifndef SC_TOOLS_H
#define SC_TOOLS_H

#include "sc_config.h"

void debug_print(const char* format, ...);
long map(long x, long in_min, long in_max, long out_min, long out_max);
float map(float x, float in_min, float in_max, float out_min, float out_max);

#endif // SC_TOOLS_H