#include "bcrypt.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ASSERT_EQ(expected, actual) assert_eq((expected), (actual), #actual, __LINE__, __FILE__)

void assert_eq(int expected, int actual, const char *expr, int line, const char *file) {
	if (expected != actual) {
		fprintf(stderr, "Assertion failed: expecting %d, got %d from \"%s\", at %s(%d)\n",
				expected, actual, expr, file, line);
		exit(1);
	}
}

int main() {
	clock_t before, after;
	char salt[BCRYPT_HASHSIZE];
	char hash[BCRYPT_HASHSIZE];

	ASSERT_EQ(0, bcrypt_gensalt(12, salt));
	printf("Generated salt: %s\n", salt);
	before = clock();
	ASSERT_EQ(0, bcrypt_hashpw("testtesttest", salt, hash));
	after = clock();
	printf("Hashed password: %s\n", hash);
	printf("Time taken: %f seconds\n", (float)(after - before) / CLOCKS_PER_SEC);
	
	const char pass[] = "hi,mom";
	const char hash1[] = "$2a$10$VEVmGHy4F4XQMJ3eOZJAUeb.MedU0W10pTPCuf53eHdKJPiSE8sMK";
	const char hash2[] = "$2a$10$3F0BVk5t8/aoS.3ddaB3l.fxg5qvafQ9NybxcpXLzMeAt.nVWn.NO";

	ASSERT_EQ(0, bcrypt_hashpw(pass, hash1, hash));
	ASSERT_EQ(0, strcmp(hash1, hash));
	printf("First hash check: %s\n", (strcmp(hash1, hash) == 0) ? "OK" : "FAIL");
	ASSERT_EQ(0, bcrypt_hashpw(pass, hash2, hash));
	ASSERT_EQ(0, strcmp(hash2, hash));
	printf("Second hash check: %s\n", (strcmp(hash2, hash) == 0) ? "OK" : "FAIL");

	return 0;
}
