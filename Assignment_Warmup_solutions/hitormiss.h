/*
 * hitormiss.h
 *
 *  Created on: Feb 12, 2020
 *      Author: rgrover
 */

#ifndef HITORMISS_H_
#define HITORMISS_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXSIZE 8
//#define DEBUG

// type of cache = 1-way, 2-way, 4-way, 8-way
enum CacheType { ONE_WAY, TWO_WAY, FOUR_WAY, EIGHT_WAY };

typedef struct Cache_t {
	enum CacheType type;
	int numBlocksPerSet;
	int numSets;
	int cacheBlock[MAXSIZE][MAXSIZE];    // stores the block ids
	bool valid[MAXSIZE][MAXSIZE];   // set to true if cache contains actual block
	uint8_t LRUBits[MAXSIZE][MAXSIZE]; // used to implement least recently used algorithm
} Cache;

int leastRecentlyUsed(Cache *cache, int setId);
void updateLRUBits(Cache *cache, int setId, int blockId);
Cache * createCache(enum CacheType ctype, int blocks, int sets);
void initialize(Cache *cache);
bool requestBlock(Cache *cache, int memBlockId) ;
int leastRecentlyUsed(Cache *cache, int setId);
void updateLRUBits(Cache *cache, int setId, int blockId);
int getNumSets(Cache *cache);
int getNumBlocksPerSet(Cache *cache);
void display(Cache *cache);

#endif /* HITORMISS_H_ */
