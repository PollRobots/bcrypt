#ifndef _BCRYPT_PLATFORM_H_
#define _BCRYPT_PLATFORM_H_

#if defined(THING_OSX)
#define GEN_RANDOM(buf, len) arc4random_buf(buf, len)
#elif defined(THING_LINUX)
#include <stdlib.h>
#define GEN_RANDOM(buf, len) platform_random(buf, len)

void platform_random(char *buffer, size_t length);
#else
#error Unknown operating system
#endif

#endif
