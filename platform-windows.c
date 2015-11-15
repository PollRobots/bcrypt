#include <assert.h>
#include <windows.h>
#include <wincrypt.h>

void platform_random(char *buffer, int length)
{
	assert(buffer != NULL && "Cannot call platform_random with a null pointer");
	assert(length > 0 && "Cannot call platform_random with a length of zero or less");

	HCRYPTPROV hcrypt;
	if (!CryptAcquireContext(&hcrypt, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT)) {
		assert(FALSE && "Call to CryptAcquireContext failed");
	}
	if (!CryptGenRandom(hcrypt, length, buffer)) {
		assert(FALSE && "Call to CryptGenRandom failed");
	}
	CryptReleaseContext(hcrypt, 0);
}
