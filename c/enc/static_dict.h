/* Copyright 2013 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

/* Class to model the static dictionary. */

#ifndef BROTLI_ENC_STATIC_DICT_H_
#define BROTLI_ENC_STATIC_DICT_H_

#include "../common/dictionary.h"
#include "../common/platform.h"
#include <brotli/types.h>
#include "./encoder_dict.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#define BROTLI_MAX_DEFAULT_DICTIONARY_WORD 24
#define BROTLI_MAX_STATIC_DICTIONARY_MATCH_LEN 37
/* While 0xFFFFFFF is already sufficiently high, using an all one-bit value
   allows the compiler to optimize a loop with memset. */
static const uint32_t kInvalidMatch = 0xFFFFFFFF;

/* Matches data against static dictionary words, and for each length l,
   for which a match is found, updates matches[l] to be the minimum possible
     (distance << 5) + len_code.
   Returns 1 if matches have been found, otherwise 0.
   Prerequisites:
     matches array is at least BROTLI_MAX_STATIC_DICTIONARY_MATCH_LEN + 1 long
     all elements are initialized to kInvalidMatch */
BROTLI_INTERNAL BROTLI_BOOL BrotliFindAllStaticDictionaryMatches(
    const BrotliEncoderDictionary* dictionary,
    const uint8_t* data, size_t min_length, size_t max_length,
    uint32_t* matches);

/* Stripped down version of the above for the reduced dictionary. Takes in and
   transforms a matched word and produces possibly transformed match and its
   length as output.*/
BROTLI_INTERNAL void BrotliTransformReducedDictionaryMatch(
    const BrotliEncoderDictionary* dictionary, const uint8_t* data,
    size_t max_length, uint32_t* matches, DictWord w);

#if defined(__cplusplus) || defined(c_plusplus)
}  /* extern "C" */
#endif

#endif  /* BROTLI_ENC_STATIC_DICT_H_ */
