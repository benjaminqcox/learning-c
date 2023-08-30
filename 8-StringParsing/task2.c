#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int wordCount(char* sentence)
{
    int wordCount = 0;
    bool wasSpace = true;
    for (int i = 0; i < strlen(sentence); i++)
    {
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
    char * rest = sentence;
    char * token;
    
        
    while ((token = strtok_r(rest, " ", &rest)))
    {
        counter++;
    }

    return counter;
}

int main()
{
    char randomWords[] = "Count the 4 words!";
    printf("%d\n", wordCount(randomWords));
    printf("%d\n", wordCountTokens(randomWords));
    // Tokens are editing the original string so that the only word stored is Count rather than the full sentence
    // I believe it is due to the setting of char * rest = sentence; but I am not sure how to counteract this.
    //printf("%s", randomWords);
}