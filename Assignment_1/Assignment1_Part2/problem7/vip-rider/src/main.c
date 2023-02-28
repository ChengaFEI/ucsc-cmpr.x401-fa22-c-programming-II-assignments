// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1: Recursion and Time Complexity
// Problem 7
//
// main.c
// vip-rider
// 
// Function: Select a set of riders for a driver to maximize the overall revenue without violating constraints of the maximum distance, the maximum number of riders, and the VIP exclusive rule.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rider.h"

// Change the file path of inputs/outputs here.
#define INPUT_FILEPATH "../test-case/inputs.txt"
#define OUTPUT_FILEPATH "../test-case/outputs.txt"
/*-----------------------------------------------------------------------------*/

// Step functions:
// Functions in this group are in charge of the major parts of the program.
void readTestCase(FILE *inputFile, int *maxDist, int *maxRider, rider *firstRider);
void findMaxRevenue(rider *currRider, int cumRevenue, int maxDist, int maxRider, int *maxRevenue);
// Helper functions:
// Functions in this group helps with the step functions' implementation.
void freeRiders(rider *currRider);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  // Basic variables.
  size_t numCase;   // The number of test cases.
  int casei;         // Test case iterator.
  int maxRevenue;    // The maximum revenue a driver can achieve.
  int maxDist;       // The maximum distance a driver can drive.
  int maxRider;      // The maximum number of riders a driver can serve.
  rider *firstRider; // Pointer to first rider in the linked list.

  // Open the file stream.
  printf("\n");
  FILE *inputFile = fopen(INPUT_FILEPATH, "r");
  if (inputFile == NULL) {
    printf("Error opening the input file: %s\n\n", INPUT_FILEPATH);
    return EXIT_FAILURE;
  }
  FILE *outputFile = fopen(OUTPUT_FILEPATH, "w");
  if (outputFile == NULL) {
    printf("Error opening the output file: %s\n\n", OUTPUT_FILEPATH);
    fclose(inputFile);
    return EXIT_FAILURE;
  }

  // Read the number of test case.
  fscanf(inputFile, "%zu", &numCase);
  // Run the algorithm for each case.
  clock_t start_time, end_time;
  double totalRunTime;
  for (casei = 0; casei < numCase; casei++){
    // Step 0: Reset the maximum revenue.
    maxRevenue = 0;
    // Step 1: Read data for the current test case.
    firstRider = (rider *) malloc(sizeof(rider));
    readTestCase(inputFile, &maxDist, &maxRider, firstRider);    
    // Step 2: Find the maximum revenue for the driver.
    start_time = clock();
    findMaxRevenue(firstRider, 0, maxDist, maxRider, &maxRevenue);
    end_time = clock();
    totalRunTime = ((double) end_time - start_time) / CLOCKS_PER_SEC;
    // Step X: Log the algorithm's results.
    fprintf(outputFile, "Test case: %d\n", casei+1);
    fprintf(outputFile, "Max revenue: %d\n", maxRevenue);
    printf("Test case %d runs for %lf seconds\n", casei+1, totalRunTime);
    freeRiders(firstRider); // Release dynamic memories.
  }
  printf("\n");

  // Close the file stream.
  fclose(inputFile);
  fclose(outputFile);
  printf("The program runs successfully.\n");
  printf("Please read the outputs in the file: %s\n\n", OUTPUT_FILEPATH);

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// readTestCase() reads data from the input file, including the maximum distance, the maximum number of riders, the overall number of riders, and the riders' list.
// @Param:   inputFile  -- the input file stream.
// @Param:   maxDist    -- pointer to the maximum distance a driver can drive.
// @Param:   maxRider   -- pointer to the maximum number of riders a driver can serve.
// @Param:   numRider   -- pointer to the total number of riders in the list.
// @Param:   firstRider -- pointer to the first rider in the list.
// @Return:  maxDist, maxRider, numRider, firstRider.
// @Require: inputFile is not NULL.
void readTestCase(FILE *inputFile, int *maxDist, int *maxRider, rider *firstRider)
{
  // Basic variables.
  int rideri;                   // The rider iterator.
  int numRider;                 // The number of riders.
  rider *currRider, *lastRider; // pointer to the current/last rider's data.

  // Read the maximum distance.
  fscanf(inputFile, "%d", maxDist);
  // Read the maximum number of riders.
  fscanf(inputFile, "%d", maxRider);
  // Read the total number of riders.
  fscanf(inputFile, "%d", &numRider);
  // Read the list of riders.
  currRider = lastRider = firstRider;
  for (rideri = 0; rideri < numRider; rideri++) {
    fscanf(inputFile, "%d %d %d", &currRider->dist, &currRider->revenue, &currRider->vip);
    currRider->next = (rider *) malloc(sizeof(rider));
    lastRider = currRider;
    currRider = currRider->next;
  }
  // Discard the last rider (this rider has no data).
  lastRider->next = NULL;
  free(currRider);
}
/*-----------------------------------------------------------------------------*/

// findMaxRevenue() traverses all riders in the list and finds the maximum revenue a driver can achieve from these riders based on constraints of distance, number of riders, and exclusive VIP.
// @Param:   currRider  -- pointer to the current rider in the list.
// @Param:   cumRevenue -- the cumulative revenue a driver has earned preceding to the current ride.
// @Param:   maxDist    -- the maximum distance a driver can drive later.
// @Param:   maxRider   -- the maximum number of riders a driver can serve later.
// @Param:   maxRevenue -- pointer to the shared maximum revenue.
// @Return:  maxRevenue.
// @Require: none
void findMaxRevenue(rider *currRider, int cumRevenue, int maxDist, int maxRider, int *maxRevenue)
{
  // If all riders are traversed, end the recursion, and update the maximum revenue.
  if (currRider == NULL) {
    *maxRevenue = cumRevenue > *maxRevenue ? cumRevenue : *maxRevenue;
    return;
  }

  // Retrive the current rider's data.
  int distance = currRider->dist;
  int revenue = currRider->revenue;
  int vip = currRider->vip;
  // Scenario 1: Don't give the current rider a ride.
  findMaxRevenue(currRider->next, cumRevenue, maxDist, maxRider, maxRevenue);
  // Scenario 2: Give the current rider a ride.
  if (1 == vip) {
    // 2.1: If the rider is a VIP.
    // Only when no other riders are served, serve this VIP, and end the recursion.
    if (0 == cumRevenue && distance <= maxDist && maxRider >= 1) {
      *maxRevenue = revenue > *maxRevenue ? revenue : *maxRevenue;
      return;
    }
  } else {
    // 2.2: If the rider is a non_VIP.
    // 2.2.1: Update the maximum allowed distance and the maximum allowed number of riders.
    maxDist -= currRider->dist;
    maxRider--;
    // 2.2.2: If the maximum allowed distance or the maximum allowed number of riders is negatice, end the recursion, and update the maximum revenue.
    if (maxDist < 0 || maxRider < 0) {
      *maxRevenue = cumRevenue > *maxRevenue ? cumRevenue : *maxRevenue;
      return;
    }  
    // 2.2.3: If the constraints are not violated, continue the recursion.
    cumRevenue += currRider->revenue;
    findMaxRevenue(currRider->next, cumRevenue, maxDist, maxRider, maxRevenue);
  }
}
/*-----------------------------------------------------------------------------*/

// freeRiders() frees all the dynamic memories occupied by the linked list of rider objects.
// @Param:   currRider -- pointer to the first rider in the list to be freed.
// @Return:  none
// @Require: none
void freeRiders(rider *currRider) 
{
  if (currRider == NULL) return;
  // Free the rider objects linked to the current rider object.
  if (currRider->next != NULL) freeRiders(currRider->next);
  free(currRider);
}
/*-----------------------------------------------------------------------------*/
