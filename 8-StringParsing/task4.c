#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * sortString(char * original)
{
    // Allocate memory for a copy of the original string
    unsigned int origLen = strlen(original);
    size_t origSize = origLen+1*sizeof(char);
    char * sortedVersion = (char*) malloc(origSize);

    // Ensure the memory was allocated correctly
    if (sortedVersion == NULL)
    {
        printf("Memory could not be allocated, the program will exit now.");
        exit(0);
    }
    // Make a copy of the string as to not edit the original
    strlcpy(sortedVersion, original, origSize);

    // Set a temporary variable named temp for swapping letters during the sort
    char tmp;

    // Standard (non-optimal) sort algorithm
    // Loop the penultimate of the array
    //      Loop from the current element to the length of the array
    //          Swap the element x with y if the ASCII value of x is greater than y
    //              (tolower has been used during the comparison to sort capital letters correctly)
    for (int i = 0; i < origLen-1; i++)
    {
        for (int j = i+1; j < origLen; j++)
        {
            if (tolower(sortedVersion[i]) > tolower(sortedVersion[j]))
            {
                tmp = sortedVersion[i];
                sortedVersion[i] = sortedVersion[j];
                sortedVersion[j] = tmp;
            }
        }
    }
    return sortedVersion;
}


int main()
{
    // Define string to be sorted
    char * originalStr = "This should be sorted alphabetically! IT EVEN DEALS WITH CAPITAL LETTERS. I will add some random letters now. ;qzjoerc.23";
    // Store sorted string in new array
    char * sortedStr = sortString(originalStr);
    // Print results
    printf("Before sorting: %s\nAfter sorting: %s\n", originalStr, sortedStr);
    return 0;
}