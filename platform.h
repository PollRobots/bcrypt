#ifndef _BCRYPT_PLATFORM_H_
#define _BCRYPT_PLATFORM_H_

#include "config.h"

#if defined(HAVE_ARC4RANDOM_IN_LIB_C)
/* for example: on OS X arc4random is in lib c */
#define GEN_RANDOM(buf, len) arc4random_buf(buf, len)
#elif defined(HAVE_SYS_BSD_H) && defined (HAVE_ARC4RANDOM_IN_LIB_BSD)
/* for example: on a system with lib bsd installed*/
#include <sys/bsd.h>
#define GEN_RANDOM(buf, len) arc4random_buf(buf, len)
#elif !defined(BCRYPT_WINDOWS)
/* on an arbitrary unix system, we'll just read from /dev/urandom */
#include <stdlib.h>
#define PLATFORM_RANDOM_UNIX
#define GEN_RANDOM(buf, len) platform_random(buf, len)
#ifdef __cplusplus
extern "C" {
#endif
void platform_random(char *buffer, size_t length);
#ifdef __cplusplus
}
#endif
#else
#define PLATFORM_WINDOWS
#define GEN_RANDOM(buf, len) platform_random(buf, len)
#ifdef __cplusplus
extern "C" {
#endif
void platform_random(char *buffer, int length);
#ifdef __cplusplus
}
#endif
#endif

#endif
