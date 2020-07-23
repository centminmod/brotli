We include the BSD-licensed C radix library rax
(https://github.com/antirez/rax/commits/master). The code is based on commit
1927550 and includes minor modifications to add prototypes for low-level
functions for use in brotli and to add a simplified version of one function
which makes it possible to quickly find the last node where a given string
fully matches a word in the radix trie.
