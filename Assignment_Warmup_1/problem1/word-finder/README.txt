//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 1
//
//  main.c
//  word-finder
//

This program counts the occurrence of input words in the given word matrix.

Specification:
1.   All of the following cases count:
1.1. Forward/Backward order in rows
1.2. Downward/Upward order in columns
1.3. Positive/Reverse order in diagonals
1.4. Positive/Reverse order in anti-diagonals

2.   All characters must appear consistently.

3.   Examples:
3.1. 
Words to find: ALPHA, BETA, GAMMA
Word Matrix:
A L P H A 
B O F L A 
B C P Z T 
B H H A E
A T X Y B
Output: ALPHA 2  BETA 1  GAMMA 0 
3.2.
Words to find: ALPHA BETA GAMMA 
Word Matrix: 
A L P H A 
B O F L A 
B C P Z T 
B H H A E
A A T E B
Output: ALPHA 2  BETA 2  GAMMA 0
3.3. 
Words to find: ALPHA BETA GAMMA 
Word Matrix:
A L P H A A L B H A 
B O F L A A L E H A 
B C P Z T A L T H A 
G A M M A B H A A E
A A T E B A L P H A 
A L P H A A L P H A 
B O F L A A L P H A 
B E P Z T A L P H A 
B E T A E B H H A E
A A T A B A T E H A 
Output: ALPHA 6  BETA 5  GAMMA 1





