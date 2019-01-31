#include "basic_hash.h"

/*
all code reference from  https://blog.csdn.net/g1036583997/article/details/51910598
*/

size_t basic_hash_ns::BKDRHash(const char* str) {
	size_t hash = 0;

	while (size_t ch = (size_t)*str++) {
		// hash = hash * 131 + ch;
		hash = (hash << 7) + (hash << 1) + hash + ch;
	}
	return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::SDBMHash(const char* str) {
	size_t hash = 0;

	while (size_t ch = (size_t)*str++) {
		// hash = 65599 * hash + ch;
		hash = ch + (hash << 6) + (hash << 16) - hash;
	}
	return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::RSHash(const char* str) {
	size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++) {
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::APHash(const char* str) {
	size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++) {
		if ((i & 1) == 0) {
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::JSHash(const char *str) {
	if(!*str)
		return 0;
	size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++) {
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::DEKHash(const char *str) {
	if(!*str)
		return 0;
	size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++)  
    {  
        hash = ((hash << 5) ^ (hash >> 27)) ^ ch;  
    }  
    return hash & 0x7FFFFFFF; 
}


size_t basic_hash_ns::FNVHash(const char *str) {
	if(!*str)
		return 0;
	size_t hash = 2166136261;
	while (size_t ch = (size_t)*str++)  
    {  
        hash *= 16777619;  
        hash ^= ch;  
    }  
    return hash & 0x7FFFFFFF; 
}


size_t basic_hash_ns::DJBHash(const char *str) {
	if(!*str)
		return 0;
	size_t hash = 5381;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash += (hash << 5) + ch;  
    }  
    return hash & 0x7FFFFFFF; 
}


size_t basic_hash_ns::DJB2Hash(const char *str) {
	if(!*str)
		return 0;
	size_t hash = 5381;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash = hash * 33 ^ ch;  
    }  
    return hash & 0x7FFFFFFF; 
}

size_t basic_hash_ns::PJWHash(const char *str) {
	static const size_t TotalBits = sizeof(size_t) * 8;
	static const size_t ThreeQuarters = (TotalBits  * 3) / 4;  
    static const size_t OneEighth = TotalBits / 8;  
    static const size_t HighBits = ((size_t)-1) << (TotalBits - OneEighth);

    size_t hash = 0;
    size_t magic = 0;

    while (size_t ch = (size_t)*str++)  
    {  
        hash = (hash << OneEighth) + ch;  
        if ((magic = hash & HighBits) != 0)  
        {  
            hash = ((hash ^ (magic >> ThreeQuarters)) & (~HighBits));  
        }  
    }  
    return hash & 0x7FFFFFFF;
}


size_t basic_hash_ns::ELFHash(const char *str) {
	static const size_t TotalBits       = sizeof(size_t) * 8;  
    static const size_t ThreeQuarters   = (TotalBits  * 3) / 4;  
    static const size_t OneEighth       = TotalBits / 8;  
    static const size_t HighBits        = ((size_t)-1) << (TotalBits - OneEighth);      
    size_t hash = 0;  
    size_t magic = 0;  
    while (size_t ch = (size_t)*str++)  
    {  
        hash = (hash << OneEighth) + ch;  
        if ((magic = hash & HighBits) != 0)  
        {  
            hash ^= (magic >> ThreeQuarters);  
            hash &= ~magic;  
        }         
    }  
    return hash & 0x7FFFFFFF;  
}



size_t basic_hash_ns::JAVAHash(const char* str) {
	size_t hash = 0;

	while (size_t ch = (size_t)*str++) {
		hash = hash * 31 + ch;
	}
	return hash & 0x7FFFFFFF;
}