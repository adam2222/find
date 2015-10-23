/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"



/**
 * Returns true if value is in array of n values, else false.
 */

bool search(int value, int values[], int n)
{
    
    // Function prototype declaration
    bool binSearch (int target, int list[], int start, int end);

    bool answer = binSearch (value, values, 0, n-1);
    
    return answer;
}

/**
 * Recursive binary-search function called by "search()". Defines middle of current search range,
 * determined by averaging the start and end indexes.
 * Returns true/false to calling search() function.
 */
bool binSearch (int target, int list[], int start, int end)
{
    int middle = (start + end) / 2;
    
    //initializes "answer" to false
    bool answer = false; 
    
    if(target == list[middle])
    {
        answer = true;
    }      
    
   // base case: if everything has been searched
    else if(start >= end)
    {
        answer = false;
    }
   
    else if(target < list[middle])
    {
        // Shifts the end point to the current middle -1
        // (since looking to the left of middle value).
        end = middle - 1;
 
        answer = binSearch(target, list, start, end);
    }
    
    else if(target > list[middle])
    {   
        // Shifts the start point to the current middle +1
        // (since looking to the right of middle value).
        start = middle + 1;
        
        answer = binSearch(target, list, start, end);
    } 
    
   return answer;
}


/**
 * Sorts array of n values (selection sort).
 */
void sort(int values[], int n)
{
    // List of 1 or 0 elements is already sorted 
    if(n < 2)
        return;
        
    // Outer loop determines where unsorted portion of list begins.
    // First run-through is entire list.  2nd run through starts at values[1], 
    // 3rd at values[2] etc. For each run through, the min of unsorted elements is placed at
    // end of sorted portion (values[0], values[1] etc).
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        
        // Compare successive elements with current minimum of unsorted elements.
        // Re-define min as going through unsorted list if current element is smaller.
        for(int j = i + 1; j < n; j++)
        {    if(values[j] < values[min])
            {
                min = j;
            }
        }   
        // At end of each run-through to determine min, switch values[min] with 
        // values[i] (the first unsorted element).
        int temp = values[i];
        values[i] = values[min];
        values[min] = temp;
    }
    
    return;
}
