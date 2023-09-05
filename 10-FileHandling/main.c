#include <stdio.h>
#include <stdlib.h>
#include "../8-StringParsing/task2/wordCount.c"


int main()
{
    // Set filename
    const char * fName = "NewFile.txt";

    // Initialise a file pointer
    FILE * wfptr;

    // Open file in write mode
    wfptr = fopen(fName, "w");

    // Ensure the file was opened/created correctly
    if (wfptr == NULL)
    {
        fprintf(stderr, "Failed to open or create the chosen file.\n");
        exit(EXIT_FAILURE);
    }

    // Write to file
    char * myName = "Benjamin Cox";
    fprintf(wfptr, "My name is: %s", myName);
    
    // Close the file
    fclose(wfptr);



    // Initialise a file pointer
    FILE * rfptr;

    // Open file in read mode
    rfptr = fopen(fName, "r");

    // Ensure the file was opened correctly
    if (rfptr == NULL)
    {
        fprintf(stderr, "Failed to open the chosen file.\n");
        exit(EXIT_FAILURE);
    }

    // Set initial word count and allocate memory buffer
    int wordCount = 0;
    char * fContents = (char *) malloc(64*sizeof(char));
    // Loop through the file in chunks of 64 bytes until the eof
    while ((fContents = fgets(fContents, 64, rfptr)) != NULL)
    {
        // Count the number of words in the read contents, keeping a tally
        wordCount += wordCountTokens(fContents);
        // Print the current contents
        puts(fContents);
    }

    // Ensure file was read correctly as there is no distinction between fgets output returning eof and ferror
    if(ferror(rfptr) != 0)
    {
        fprintf(stderr, "Failed to read file.\n");
        exit(EXIT_FAILURE);
    }
    // Close the file
    fclose(rfptr);
    // Display the total words found
    printf("The file contains %d words\n", wordCount);

    return 0;
}