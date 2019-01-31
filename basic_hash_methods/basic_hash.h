#ifndef BASIC_HASH_H
#define BASIC_HASH_H
#include <sys/types.h>  /* defines size_t */
#include <stdint.h>


namespace basic_hash_ns {

	size_t BKDRHash(const char* str);

	size_t SDBMHash(const char* str);

	size_t RSHash(const char* str);

	size_t APHash(const char* str);

	size_t JSHash(const char* str);

	size_t DEKHash(const char* str);

	size_t FNVHash(const char* str);

	size_t DJBHash(const char* str);

	size_t DJB2Hash(const char* str);

	size_t PJWHash(const char* str);

	size_t ELFHash(const char* str);

	size_t JAVAHash(const char* str);
};
#endif