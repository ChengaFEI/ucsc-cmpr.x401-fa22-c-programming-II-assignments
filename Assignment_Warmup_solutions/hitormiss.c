// Copyright SPEL Technologies, Inc.
// Determines the number of hits and misses for a given number of requests to each of the following caches:
// 1-way set associative, 2-way set associative, 4-way set associative, 8-way set associative
// Uses the Least Recently Used cache replacement algorithm
//
// Warmup assignment problem 4

/************* DO NOT DISTRIBUTE *****************************************/

#include "hitormiss.h"

Cache * createCache(enum CacheType ctype, int blocks, int sets) {
	Cache *cache = (Cache *) calloc(sizeof(Cache), 1);
	cache->type = ctype;
	cache->numBlocksPerSet = blocks;
	cache->numSets = sets;
	return cache;
}

void initialize(Cache *cache) {
	// initialize valid to false
	for (int i = 0; i < MAXSIZE; i++) {
		for (int j = 0; j < MAXSIZE; j++) {
			cache->cacheBlock[i][j] = -1;
			cache->valid[i][j] = false;
			cache->LRUBits[i][j] = 8;
		}
	}
}

// find the setId for the requested memory block id (memBlockId), then check all the blocks
// in that set to see if the requested block is present - return true (hit)
// if it is present; otherwise, return
bool requestBlock(Cache *cache, int memBlockId) {
	// get the set number
	int setId = memBlockId % cache->numSets;

	bool hit = false;
	int emptyBlockId = -1; // id of any empty block in this set

	// check if block with given id is present in any valid location of cache of a set
	for (int j = 0; j < cache->numBlocksPerSet && (hit == false); j++) {
		if (cache->valid[setId][j]) {
			if (cache->cacheBlock[setId][j] == memBlockId) {
				hit = true;  // found requested block in cache
				// Updating LRU bit for requested block "
				updateLRUBits(cache, setId, j); // make this the MRU (most recently used) block, age the other blocks
			}

		} else {
			emptyBlockId = j; // store the id of this empty block
		}
	}

	if (!hit) {
		// memory block was not found in cache, find an empty cache block and read memory block into this cache block
		if (emptyBlockId != -1) { // an empty block is available
			// store the memory block in this empty block
			cache->cacheBlock[setId][emptyBlockId] = memBlockId;
			cache->valid[setId][emptyBlockId] = true; // valid block
			// Updating LRU bit for empty block inserted into cache
			updateLRUBits(cache, setId, emptyBlockId); // make this the MRU block, age the other blocks
		} else { // an empty block is not available
			// call the LRU algorithm to determine which block to replace
			int replacementBlockId = leastRecentlyUsed(cache, setId);
#ifdef DEBUG
			printf( "The replacement block id is %d  in set %d \n", replacementBlockId , setId);
#endif
			// replace this block in the cache with the memory block
			cache->cacheBlock[setId][replacementBlockId] = memBlockId;
			// update LRU bit for the block replaced in cache
			updateLRUBits(cache, setId, replacementBlockId); // make this the MRU block, age the other blocks
		}
	}
	return hit;
}

// Determines which block in the cache was least recently used (age)
// and return the id of this block (oldestBlock)
int leastRecentlyUsed(Cache *cache, int setId) {
	int age = INT_MIN;
	int oldestBlock;

	for (int id = 0; id < cache->numBlocksPerSet; id++) {
		// find a valid block with the greatest age and return it
		if (cache->valid[setId][id] && cache->LRUBits[setId][id] > age) {
			age = cache->LRUBits[setId][id];
			oldestBlock = id;
		}
	}
	return oldestBlock;
}

// When a block A is referenced, A's new LRUBit is set to 0.
// All blocks whose LRUBit is greater than A's old LRUBit are unchanged.
// All blocks whose LRUBit is less than A's old LRUBit have their
// LRUBit incremented by 1.
void updateLRUBits(Cache *cache, int setId, int blockId) {
	// make this the most recently used block, age the other blocks
	int A = blockId;                   // most recently used block with LRUBit 0
	int A_LRUBit = cache->LRUBits[setId][A];  // current LRU bit of A

	if (A_LRUBit != 0) {        // A is not the most recently used block
		cache->LRUBits[setId][A] = 0; // make A the most recently used block by setting its LRUBit to 0

		for (int j = 0; j < cache->numBlocksPerSet; j++) {
			//check all valid blocks in this set; if their LRUBit is less than A's old LRUBit,
			// then increment their LRUBit by 1 (i.e., age these blocks by 1)
			if (cache->valid[setId][j] && j != A && cache->LRUBits[setId][j] < A_LRUBit)
				++cache->LRUBits[setId][j];  // age the remaining blocks whose LRUBit is less than A's old LRUBit
		}
	}

}

int getNumSets(Cache *cache) {
	return cache->numSets;
}

int getNumBlocksPerSet(Cache *cache) {
	return cache->numBlocksPerSet;
}

void display(Cache *cache) {
	printf("The cache contents are:");
	for (int i = 0; i < getNumSets(cache); i++) {
		for (int j = 0; j < getNumBlocksPerSet(cache); j++) {
			printf("%d  ", cache->cacheBlock[i][j]);
		}
		printf("\n");
	}


	printf("The LRU bits are: \n");
	for (int i = 0; i < getNumSets(cache); i++) {
		for (int j = 0; j < getNumBlocksPerSet(cache); j++) {
			printf("%d ", cache->LRUBits[i][j]);
		}
		printf("\n");
	}

	printf("The valid bits are: \n");
	for (int i = 0; i < getNumSets(cache); i++) {
		for (int j = 0; j < getNumBlocksPerSet(cache); j++) {
			printf("%d ", cache->valid[i][j]);
		}
		printf("\n");
	}
	printf("\n \n");
}


int main() {

	int testi;

	Cache *oneWay = createCache(ONE_WAY, 1, 8);
	Cache *twoWay = createCache(TWO_WAY, 2, 4);
	Cache *fourWay = createCache(FOUR_WAY, 4, 2);
	Cache *eightWay = createCache(EIGHT_WAY, 8, 1);

	freopen("input_problem_4.txt", "r", stdin);
	int numTestCases;
	int numRequests, memBlockId;
	int numHits_oneway, numHits_twoway, numHits_fourway, numHits_eightway;
	scanf("%d", &numTestCases);
	for ( testi = 0; testi < numTestCases; testi++) {
		scanf("%d", &numRequests);
		numHits_oneway = 0;
		numHits_twoway = 0;
		numHits_fourway = 0;
		numHits_eightway = 0;
		initialize(oneWay);
		initialize(twoWay);
		initialize(fourWay);
		initialize(eightWay);

		for (int i = 0; i < numRequests; i++) {
			scanf("%d", &memBlockId);
#ifdef DEBUG
			printf("Request Block %d \n", memBlockId);
#endif
			// send request to 1-way cache
			bool hit = requestBlock(oneWay, memBlockId);
			if (hit)
				numHits_oneway++;

			// send request to 2-way cache
			bool hit1 = requestBlock(twoWay, memBlockId);

			if (hit1) {
				numHits_twoway++;
#ifdef DEBUG
				printf("Cache HIT");
#endif
			}
			else {
#ifdef DEBUG
				printf("Cache MISS \n");
#endif
			}

			// send request to 4-way cache
			hit = requestBlock(fourWay, memBlockId);
			if (hit)
				numHits_fourway++;

			// send request to 8-way cache
			hit = requestBlock(eightWay, memBlockId);
			if (hit)
				numHits_eightway++;

#ifdef DEBUG
			twoWay.display();
#endif
		}
		printf("Test case %d  Total hits \n",testi);
		printf("1-way: %d   2-way:  %d,  4-way: %d, 8-way: %d  \n", numHits_oneway, numHits_twoway, numHits_fourway, numHits_eightway);

	}
}



