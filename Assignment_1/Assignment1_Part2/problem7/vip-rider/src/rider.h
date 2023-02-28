// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1: Recursion and Time Complexity
// Problem 7
//
// rider.h
// vip-rider
// 
// Object: The rider.

#include <stdlib.h>
/*-----------------------------------------------------------------------------*/

// Rider is an element in a linked list, with the data about the distance, revenue, VIP, and next rider.
typedef struct rider_t {
  int dist;             // The distance between the rider and the driver.
  int revenue;          // The revenue a driver gets from serving the rider.
  int vip;              // Whether the rider is a VIP. (VIP must be served alone)
                        // 1 indicates a VIP, 0 indicates a non-VIP.
  struct rider_t *next; // Next rider in the list.
} rider;