#include "bcrypt.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
	clock_t before, after;
	char salt[BCRYPT_HASHSIZE];
	char hash[BCRYPT_HASHSIZE];

	assert(bcrypt_gensalt(12, salt) == 0);
	printf("Generated salt: %s\n", salt);
	before = clock();
	assert(bcrypt_hashpw("testtesttest", salt, hash) == 0);
	after = clock();
	printf("Hashed password: %s\n", hash);
	printf("Time taken: %f seconds\n", (float)(after - before) / CLOCKS_PER_SEC);
	
	const char pass[] = "hi,mom";
	const char hash1[] = "$2a$10$VEVmGHy4F4XQMJ3eOZJAUeb.MedU0W10pTPCuf53eHdKJPiSE8sMK";
	const char hash2[] = "$2a$10$3F0BVk5t8/aoS.3ddaB3l.fxg5qvafQ9NybxcpXLzMeAt.nVWn.NO";

	assert(bcrypt_hashpw(pass, hash1, hash) == 0);
	printf("First hash check: %s\n", (strcmp(hash1, hash) == 0) ? "OK" : "FAIL");
	assert(bcrypt_hashpw(pass, hash2, hash) == 0);
	printf("Second hash check: %s\n", (strcmp(hash2, hash) == 0) ? "OK" : "FAIL");

	return 0;
}