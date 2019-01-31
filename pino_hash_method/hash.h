/*
Copyright (c) by respective owners including Yahoo!, Microsoft, and
individual contributors. All rights reserved.  Released under a BSD
license as described in the file LICENSE.
 */

//
// MurmurHash3, by Austin Appleby
//
// Originals at:
// http://code.google.com/p/smhasher/source/browse/trunk/MurmurHash3.cpp
// http://code.google.com/p/smhasher/source/browse/trunk/MurmurHash3.h
//
// Notes:
// 1) this code assumes we can read a 4-byte value from any address
//    without crashing (i.e non aligned access is supported). This is
//    not a problem on Intel/x86/AMD64 machines (including new Macs)
// 2) It produces different results on little-endian and big-endian machines.
//
// Adopted for VW and contributed by Ariel Faigon.
//

//-----------------------------------------------------------------------------
// MurmurHash3 was written by Austin Appleby, and is placed in the public
// domain. The author hereby disclaims copyright to this source code.

// Note - The x86 and x64 versions do _not_ produce the same results, as the
// algorithms are optimized for their respective platforms. You can still
// compile and run any of them on any platform, but your performance with the
// non-native version will be less than optimal.
//-----------------------------------------------------------------------------

#ifndef HASH_H
#define HASH_H

#include <sys/types.h>  /* defines size_t */
#include <stdint.h>

namespace test_hash {

  uint32_t uniform_hash( const void *key, size_t length, uint32_t initval);
  
  // Platform-specific functions and macros
  #if defined(_MSC_VER)                       // Microsoft Visual Studio
  #   include <stdint.h>
  
  #   include <stdlib.h>
  #   define ROTL32(x,y)  _rotl(x,y)
  #   define BIG_CONSTANT(x) (x)
  
  #else                                       // Other compilers
  #   include <stdint.h>   /* defines uint32_t etc */
  
      inline uint32_t rotl32 (uint32_t x, int8_t r)
      {
          return (x << r) | (x >> (32 - r));
      }
  
  #   define ROTL32(x,y)     rotl32(x,y)
  #   define BIG_CONSTANT(x) (x##LLU)
  
  #endif                                      // !defined(_MSC_VER)
  
  //-----------------------------------------------------------------------------
  // Block read - if your platform needs to do endian-swapping or can only
  // handle aligned reads, do the conversion here
  
  static inline uint32_t getblock (const uint32_t * p, int i)
  {
    return p[i];
  }
  
  //-----------------------------------------------------------------------------
  // Finalization mix - force all bits of a hash block to avalanche
  
  static inline uint32_t fmix (uint32_t h)
  {
    h ^= h >> 16;
    h *= 0x85ebca6b;
    h ^= h >> 13;
    h *= 0xc2b2ae35;
    h ^= h >> 16;
  
    return h;
  }
//-----------------------------------------------------------------------------
};

#endif

