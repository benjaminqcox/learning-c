#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "wordCount.h"

int wordCount(char* sentence)
{
    int wordCount = 0;
    bool wasSpace = true;
    // Loop through sentence character by character
    for (int i = 0; i < strlen(sentence); i++)
    {
        // If the current character is a space and the previous character
        //  was not a space, increment the word counter
        // Otherwise set the previous character to a space
        //  This deals with leading, middle and end spaces
        if (sentence[i] != ' ')
        {
            if (wasSpace)
            {
               wordCount++;
               wasSpace = false;
            }
        }
        else
        {
            wasSpace = true;
        }
    }
    return wordCount;
}

int wordCountTokens(char* sentence)
{
    unsigned int counter = 0;
    // Calculate the amout of memory the sentence takes up (including the null terminator)
    size_t numBytes = strlen(sentence)+1 * sizeof(char);
    // Allocate memory equal to the memory of sentence
    char * rest = (char *) malloc(numBytes);
    // Ensure the memory has been assigned correctly
    if (rest == NULL)
    {
        printf("Memory could not be allocated, the program will exit now.");
        exit(0);
    }
    // Copy the sentence to a variable named rest
    strlcpy(rest, sentence, numBytes);
    char * token;
    
    // Loop through rest until a NULL value is returned by strtok_r()
    while ((token = strtok_r(rest, " ", &rest)) != NULL)
    {
        counter++;
    }

    return counter;
}