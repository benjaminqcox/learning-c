/*

    //  void get_sky_team_name(char* name)

    ptr is a memory address assigned 10 bytes

    strcpy() -> changes the value stored at address ptr to a string containing 18 bytes
    18 bytes > 10 bytes so an error will occur
    (or only the first 10 bytes are assigned to the ptr memory)
        -> "Home Comm\0"
    
    name (is a memory location assigned as char* pTeamName = NULL) = ptr

    ptr = NULL;

    free(ptr) -> ptr = NULL

    therefore as name points to the same memory locations as ptr 
        free, frees up the memory being pointed to by ptr

    //


    // int main()
    
    name = 10 chars of byte 1 each -> 10 bytes
    pTeamName is a pointer set to NULL

    name = "Sky UK"

    get_sky_team(char* name) is called in an infinite while loop
        which will cause a memory leak
    
    printf("%s: %s\n", skyName, pTeamName);
        skyName is undefined, lets rename it to name

    printf("%s: %s\n", name, pTeamName);
        out:
            "Sky UK: NULL" 
            "Sky UK: NULL" 
            "Sky UK: NULL" 



    //
*/

//Fixing the code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void  get_sky_team_name(char** name)
{
    char* ptr = (char*) malloc(19);
    
    //copy team name to pointer
    strcpy(ptr, "Home Comms SW Team");
    
    //return team name
    *name = ptr;

}
  
int main()
{
    char name[10];
    char* pTeamName = NULL;
    strcpy(name, "Sky UK");     
    
    while(1)
    {
        get_sky_team_name(&pTeamName);      
        
        //print team name
        printf("%s: %s\n", name, pTeamName);
        free(pTeamName);
        
        sleep(1);
    }
    
    return 0;
}