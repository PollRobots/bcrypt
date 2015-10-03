#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void platform_random(char *buffer, size_t length)
{
    assert(buffer != NULL && "Cannot call platform_random with a null pointer");
    assert(length > 0 && "Cannot call platform_random with a length of zero or less");

    int r = open("/dev/urandom", O_RDONLY);
    size_t result = read(r, buffer, length);
    assert(result == length && "Error reading data from /dev/urandom");
    close(r);
}
