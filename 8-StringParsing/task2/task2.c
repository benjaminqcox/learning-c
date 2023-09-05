#include <stdio.h>

#include "wordCount.h"

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