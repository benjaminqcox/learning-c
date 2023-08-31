#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define WORDS_MATCH 0

void stripSentence(char * sentence)
{
    // Strip sentence to make matching more accurate
    // Go through each letter in the string and if it is uppercase, convert to lower case
    // if it is punctuation, replace it with a space (words seperated by punct are not a single word except )
    // could do dynamic memory allocation but this seems safer and the memory has already been allocated so
    // we know that we have that space free
    for (int i = 0; i < strlen(sentence); i++)
    {
        if (isupper(sentence[i]))
        {
            sentence[i] = tolower(sentence[i]);
        }
        else if (ispunct(sentence[i]))
        {
            sentence[i] = ' ';
        }
    }
}

unsigned int countOccurences(char * sentence, char * word)
{
    unsigned int counter = 0;
    // Calculate the amout of memory the sentence takes up (including the null terminator)
    size_t numBytes = strlen(sentence)+1 * sizeof(char);
    // Allocate memory equal to the memory of sentence
    char * rest = (char *) malloc(numBytes);
    // If memory failed to allocate, exit the program
    if (rest == NULL)
    {
        printf("Memory could not be allocated, the program will exit now.");
        exit(0);
    }
    // Copy the sentence to a variable named rest
    strlcpy(rest, sentence, numBytes);

    // Set token variable which is a pointer to a char array that is returned by strtok_r()
    char * token;
    
    // Loop through rest until a NULL value is returned by strtok_r()
    while ((token = strtok_r(rest, " ", &rest)))
    {
        // If the token mathes the word increment the counter by 1
        if(strcmp(token, word) == WORDS_MATCH)
        {
           counter++; 
        }
    }

    return counter;
}

unsigned int countOccurencesStrstr(char * sentence, char * word)
{
    // Allocate memory for a copy of the sentence string
    unsigned int counter = 0;
    unsigned int wordLen = strlen(word);
    size_t numBytes = strlen(sentence)+1 * sizeof(char);
    char * subString = (char *) malloc(numBytes);
    // If memory could not be allocated, exit the program
    if (subString == NULL)
    {
        printf("Memory could not be allocated, the program will exit now.");
        exit(0);
    }
    // Make a copy of the string as to not edit the original
    strlcpy(subString, sentence, numBytes);
    // Loop while there is a matching substring (if word is found in sentence) or the word is an empty string
    while((subString = strstr(subString, word)) != NULL && strcmp(word, "") != WORDS_MATCH)
    {
        // Set substring pointer to the start position of the found word + the length of the word
        // Increment the counter
        subString = subString + wordLen;
        counter++;
    }
    return counter;
}

int main()
{
    // Setup initial sentence string and the word to find string
    char originalSentence[] = "When I say work, I mean work, you stupid program!";
    char findMe[] = "work";

    // Allocate memory equal to the sizo of the original string
    size_t sentenceSize = sizeof(originalSentence)/sizeof(char);
    char *sentence = (char *) malloc(sentenceSize);
    //Ensure the memory was allocated correctly
    if (sentence == NULL)
    {
        printf("Memory could not be allocated, the program will exit now.");
        exit(0);
    }
    // Make a copy of the original string
    strlcpy(sentence, originalSentence, sentenceSize);

    // Strip the copy string of all characters that cannot be classified as words (punctuation and make everything lowercase)
    stripSentence(sentence);

    // Count word occurences using a custom made function
    unsigned int occurencesFound = countOccurences(sentence, findMe);
    printf("In the sentence: %s\nThe word \"%s\" was found %d times.\n", originalSentence, findMe, occurencesFound);
    // Count word occurences using the strstr function
    unsigned int occurencesFoundStrstr = countOccurencesStrstr(sentence, findMe);
    printf("In the sentence: %s\nThe word \"%s\" was found %d times.\n", originalSentence, findMe, occurencesFoundStrstr);
    return 0;
}