// UCSC Silicon Valley Extension
// Advanced C Programming
// Extra Credit Assignment
//
// top-flight
// procstatus.h
//
// Enumeration: Process Status.
//
// Author: Cheng Fei
// Date: 12/31/2022

#include <stdlib.h>
/*-----------------------------------------------------------------------------*/

// Process status enumeration.
typedef enum {
  NULL_OBJECT    = -1,
  SUCCESS        = 0,
  OUT_OF_MEMORY  = 1,
  FILE_NOT_EXIST = 2,
  OUT_OF_BOUND   = 3
} ProcStat;
/*-----------------------------------------------------------------------------*/
