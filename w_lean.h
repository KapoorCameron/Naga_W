#pragma once

// tell windows.h to not include commonly unneeded stuff (like API):
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// Windows min/max values != C++ min/max values- we don't want windows values:
#ifndef NOMINMAX
#define NOMINMAX
#endif

#include<windows.h>