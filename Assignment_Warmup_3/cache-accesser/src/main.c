//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 4
//
//  main.c
//  cache-accesser
//

#include <stdio.h>
#include <stdlib.h>

// Function Prototype.
void calculateHits(int, int, int, const int[], int *, int *);

int main(void) {
  // Helper variables settings.
  int numTestCases, numAccesses;
  int casei, accessi; // Iterators.
  int bestScheme, mostHits; // Record the best scenario.
  // Load basic variables.
  freopen("input.txt", "r", stdin);
  scanf("%d", &numTestCases);
  for (casei = 0; casei < numTestCases; casei++) {
    // Reset for each case.
    bestScheme = -1; mostHits = 0;
    printf("Test Case %d:\n", casei);
    scanf("%d", &numAccesses);
    int accesses[numAccesses];
    // Load memory addresses of all accesses.
    for (accessi = 0; accessi < numAccesses; accessi++) {
      scanf("%d", &accesses[accessi]);
    }

    // 1-way set associative cache.
    printf("1-way set associative: ");
    calculateHits(8, 1, numAccesses, accesses, &bestScheme, &mostHits);
    // 2-way set associative cache.
    printf("2-way set associative: ");
    calculateHits(4, 2, numAccesses, accesses, &bestScheme, &mostHits);
    // 4-way set associative cache.
    printf("4-way set associative: ");
    calculateHits(2, 4, numAccesses, accesses, &bestScheme, &mostHits);
    // 8-way set associative cache.
    printf("8-way set associative: ");
    calculateHits(1, 8, numAccesses, accesses, &bestScheme, &mostHits);

    // Best scheme:
    printf("Best scheme: %d-way set associative\n", bestScheme);
    printf("-------------------------------------------\n");
  }

  return EXIT_SUCCESS;
}

// Calculate hits and misses of a specific cache scenarios in a specific case.
// @Params: currNumSets -- total number of cache sets.
// @Params: currBlockPerSet -- total number of cache blocks in each cache set.
// @Params: numAccesses -- total number of memory accesses in the specified case.
// @Params: accesses -- int array with all the memory accesses.
// @Params: bestScheme -- store the index of the best cache scheme.
// @Params: mostHits -- store the maximum number of hits among all cache schemes.
// @Returns: return the best cache scheme's index to bestScheme variable.
// @Returns: return the maximum number of hits to the mostHits variable.
void calculateHits(int currNumSets, int currBlockPerSet, int numAccesses, const int accesses[], int *bestScheme, int *mostHits) {
  int storedAccesses[8]; // Store the remembered accesses.
  int headPointers[currNumSets]; // Store the index of the head pointers in each cache set.
  int accessi, currAccess, currSetIndex, currHead, currPointer, access;
  int currHit = 0, currMiss = 0;
  // Reset remembered accesses.
  for (int i = 0; i < 8; i++) storedAccesses[i] = -1;
  // Reset the head locations.
  for (int i = 0; i < currNumSets; i++) headPointers[i] = 0;
  // Loop over all accesses.
  for (accessi = 0; accessi < numAccesses; accessi++) {
    currAccess = accesses[accessi];
    currSetIndex = currAccess % currNumSets;
    currHead = headPointers[currSetIndex] + currBlockPerSet * currSetIndex;
    currPointer = currHead;
    // Loop over stored accesses in the current cache set.
    int found = 0;
    for (int blocki = 0; blocki < currBlockPerSet; blocki++) {
      access = storedAccesses[currPointer];
      if (access == -1) {
        storedAccesses[currPointer] = currAccess;
        currMiss++;
        found = 1;
        break;
      }
      if (access == currAccess) {
        currHit++;
        found = 1;
        break;
      }
      currPointer++;
      if (currPointer >= currBlockPerSet * (currSetIndex+1)) {
        currPointer = currBlockPerSet * currSetIndex;
      }
    }
    if (0 == found) {
      storedAccesses[currHead] = currAccess;
      currMiss++;
      headPointers[currSetIndex]++;
      if (headPointers[currSetIndex] == currBlockPerSet) {
        headPointers[currSetIndex] = 0;
      }
    }
  }
  printf("hits: %d misses: %d\n", currHit, currMiss);
  *bestScheme = currHit >= *mostHits ? currBlockPerSet : *bestScheme;
  *mostHits = currHit >= *mostHits ? currHit : *mostHits;
}