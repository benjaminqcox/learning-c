#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

int main()
{
    // Set a string with words to count, can add punctuation and random spaces
    char randomWords[] = "Count the 4 words!";
    // Display the program output
    printf("Sentence used: %s\n", randomWords);
    // Custom function to count words
    printf("Words found without tokens: %d\n", wordCount(randomWords));
    // Word counter using strtok_r()
    printf("Words found with tokens: %d\n", wordCountTokens(randomWords));
    
}