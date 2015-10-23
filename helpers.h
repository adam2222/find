/**
 * helpers.h
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

/**
 * Recursive binary-search function called by "search()". Defines middle of current search range,
 * determined by averaging the start and end indexes.
 * Returns true/false to calling search() function.
 */
bool binSearch (int target, int list[], int start, int end);
