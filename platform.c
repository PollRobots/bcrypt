#include "platform.h"
#if defined(PLATFORM_RANDOM_UNIX)
#include "platform-linux.c"
#elif defined(PLATFORM_WINDOWS)
#include "platform-windows.c"
#endif
