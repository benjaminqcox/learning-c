#include <stdio.h>
#include <stdlib.h>

int main()
{
    char * fName = "NewFile.txt";


    // Write to file
    FILE * wfptr;

    wfptr = fopen(fName, "w");

    if (wfptr == NULL)
    {
        fprintf(stderr, "Failed to open or create the chosen file.\n");
        exit(EXIT_FAILURE);
    }

    // Write to file
    char * myName = "Benjamin Cox";
    fprintf(wfptr, "My name is: %s", myName);
    
    fclose(wfptr);



    // Read from file
    FILE * rfptr;

    rfptr = fopen(fName, "r");

    // Check if file opened
    if (rfptr == NULL)
    {
        fprintf(stderr, "Failed to open the chosen file.\n");
        exit(EXIT_FAILURE);
    }


    char * fContents = (char *) malloc(64*sizeof(char));
    while ((fContents = fgets(fContents, 64, rfptr)))
    {
        puts(fContents);
    }

    fclose(rfptr);

    return 0;
}