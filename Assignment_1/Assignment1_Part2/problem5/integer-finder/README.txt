// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1: Recursion and Time Complexity
// Problem 5
//
// main.c
// grid-visitor
// 
// Function: Find whether a given array has two integers whose sum equals a given integer.



Time complexity and space complexity analysis:

Problem:
Given an array of n integers and an integer S, write an algorithm that only returns true if the array contains two numbers whose sum is S.

Question1:
Find the recurrence relation of an algorithm that uses an exhaustive search and solve it to find the (best-case and worst-case) running time of the algorithm.

Question2:
Can you find a better algorithm to solve the problem? What is the time complexity (best case and worst case) of the algorithm? What is the space complexity of the algorithm?

Question3:
Implement both algorithms and determine the execution times of the corresponding program for different input sizes with randomized inputs. Plot the values on a graph and find the curve equation fitting the data points. Do the results agree with the theoretical analysis of part (c)?



Answer1:
The best-case time complexity is O(1). It only happens when the sum of the first two (or first few) integers is the target.
The worst-case time complexity is O(n^2). It happens when the integers are not found or at the end of the array. It requires the algorithm to traverse all integers in the array.

Answer2:
A better algorithm is to first sort the array in ascending order and then search for the sum. The algorithm will break out of the loop when the sum is larger than the target.
The best-case time complexity is O(1). It only happens when the sum of the first two (or first few) integers is the target.
The worst-case time complexity is O(n^2). It happens when the integers are not found or at the end of the array. It requires the algorithm to traverse all integers in the array.

Answer3:
The result agrees.