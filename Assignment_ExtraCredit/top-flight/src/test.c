// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// test.c
//
// Function: Test the top-flight program.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "topflight.h"
/*-----------------------------------------------------------------------------*/

// Change the path of input/output files here.
#define INPUT_FILEPATH "../test-case/inputs.txt"
#define OUTPUT_GRAPH_FILEPATH "../test-case/outputs_graphs.txt"
#define OUTPUT_LCP_FILEPATH "../test-case/outputs_lcps.txt"
#define OUTPUT_LCP_TRAN_FILEPATH "../test-case/outputs_lcps_tran.txt"
#define OUTPUT_LCP_LAYOVER_FILEPATH "../test-case/outputs_lcps_layover.txt"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provide pre-defined test cases.
ProcStat runTest1();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");

  clock_t startTime = clock();
  if (runTest1() == SUCCESS) {
    printf("Calculation terminates successfully!\n");
    printf("------------------------------------\n");
    printf("Please see graphs' adjacency matrix in the file: \n%s\n", OUTPUT_GRAPH_FILEPATH);
    printf("Please see graphs' lowest cost paths in the file: \n%s\n", OUTPUT_LCP_FILEPATH);    
    printf("Please see graphs' lowest cost paths with minimum layovers in the file: \n%s\n", OUTPUT_LCP_LAYOVER_FILEPATH);    
    printf("Please see graphs' lowest cost paths passing the transit vertex in the file: \n%s\n", OUTPUT_LCP_TRAN_FILEPATH);    
  } 
  clock_t endTime = clock();
  
  printf("------------------------------------\n");
  printf("Total execution time: %lfs.\n", (double) (endTime-startTime)/CLOCKS_PER_SEC);
  printf("\n");

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

/// @brief  Run the first test case.
/// @param  none
/// @return ProcStat -- the process status code.
/// @note   none
ProcStat runTest1()
{
  // Initialize the ProcStat.
  ProcStat procStat;

  // Initialize the graphList.
  GraphList *graphList = (GraphList *) malloc(sizeof(GraphList));
  if (graphList == NULL) return NULL_OBJECT;
  // Read data from the input file.
  procStat = readInputs(INPUT_FILEPATH, graphList);
  if (procStat != SUCCESS) return procStat;
  // Display graphs.
  procStat = printGraphList(graphList, OUTPUT_GRAPH_FILEPATH);
  if (procStat != SUCCESS) return procStat;
  // Find lowest cost paths for all graphs and display results.
  procStat = findLCPaths(graphList, OUTPUT_LCP_FILEPATH);
  if (procStat != SUCCESS) return procStat;
  // Find lowest cost paths passing the transit vertex for all graphs and display results.
  procStat = findLCPathsWithTranVert(graphList, OUTPUT_LCP_TRAN_FILEPATH);
  if (procStat != SUCCESS) return procStat;
  // Find lowest cost paths with minimum layovers for all graphs and display results.
  procStat = findLCPathsWithMinLayover(graphList, OUTPUT_LCP_LAYOVER_FILEPATH);
  if (procStat != SUCCESS) return procStat;
    // Free the graphList.
  procStat = freeGraphList(graphList);
  if (procStat != SUCCESS) return procStat;
  
  return SUCCESS;
}
/*-----------------------------------------------------------------------------*/
