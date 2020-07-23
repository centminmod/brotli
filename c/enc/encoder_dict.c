/* Copyright 2017 Google Inc. All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
*/

#include "./encoder_dict.h"

#include "../common/dictionary.h"
#include "../common/transform.h"
#include "./dictionary_hash.h"
#include "./hash.h"

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

void BrotliInitEncoderDictionary(BrotliEncoderDictionary* dict) {
  dict->words = BrotliGetDictionary();
  dict->num_transforms = (uint32_t)BrotliGetTransforms()->num_transforms;

  dict->hash_table_words = kStaticDictionaryHashWords;
  dict->hash_table_lengths = kStaticDictionaryHashLengths;
  dict->buckets = kStaticDictionaryBuckets;
  dict->dict_words = kStaticDictionaryWords;

  dict->cutoffTransformsCount = kCutoffTransformsCount;
  dict->cutoffTransforms = kCutoffTransforms;

  /* These fields are only used for the reduced dictionary and may be
     initialized later. */
  dict->use_transformed_dict = BROTLI_FALSE;
  dict->hist = NULL;
  dict->hash_lookups = NULL;
  dict->out_file = NULL;

  dict->bloom = NULL;
  dict->hash = NULL;
  dict->trie = NULL;
}

#if defined(__cplusplus) || defined(c_plusplus)
}  /* extern "C" */
#endif
