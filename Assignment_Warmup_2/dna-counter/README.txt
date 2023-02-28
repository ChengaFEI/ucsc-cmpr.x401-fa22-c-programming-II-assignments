//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 3
//
//  main.c
//  dna-counter
//

This program counts the number of RNA codons of the longest DNA from the given word matrix.
The genetic code is comprised of the set of all possible codons. Each RNA sequence consists of a set of codons such as AUG, CUA, UUC, and UAA. The four codons AUG, UAA, UAG, and UGA have a special meaning: AUG indicates start of the RNA sequence, and UAA, UAG, UGA indicates the end of the sequence.


Specification:
1.   All of the following cases count:
1.1. Forward/Backward order in rows
1.2. Downward/Upward order in columns

2.   All characters must appear consistently.

3.   Valid DNAs must start with AUG and end with           
     UAA, UAG, or UGA, and have no AUG in 
     between,
