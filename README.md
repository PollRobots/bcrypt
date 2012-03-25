# c-bcrypt

## Genealogy

This library is based on [Ricardo Garcia's wrapper](https://github.com/rg3/bcrypt "bcrypt") of [Solar Designer's implementation](http://www.openwall.com/crypt/ "crypt") of "[A future-adaptable password scheme](?)" by Niels Provos and David Mazières.

## Usage

Two routines, `bcrypt_gensalt()` and `bcrypt_hashpw()`, are all that's needed for hashing and verifying passwords.  See test.c and bcrypt.h for an explanation of their use.

You can safely store the hashed password in a database as the expected computational effort to brute-force the hashing scheme is on the order of several years for current (2011) hardware and a decent password.

## Structure of the hashed passwords
A password such as "$2a$10$VEVmGHy4F4XQMJ3eOZJAUeb.MedU0W10pTPCuf53eHdKJPiSE8sMK" is comprised of a prefix "$2a" identifying it as a bcrypt password, an integer "10" which specifies the "work factor" (i.e. how many passes of the Blowfish algorithm to use), a salt "VEVmGHy4F4XQMJ3eOZJAUe" which should be unique for each password stored, and the hashed password "b.MedU0W10pTPCuf53eHdKJPiSE8sMK" encoded in base-64.

## License

This code is released in the public domain.
