/*
    skyName assigned 10 empty chars
    pteamName assigned a 32 bit pointer (I'll call x for now)
        pointer location is to the first bit of a 10 byte memory location
    
    skyName = "Sky UK"
    pTeamName = x still
        x = "Home comm\0" This is an error as it has been assigned 10 
            chars and has been given 18 chars so only the first 10 are stored
    
    print("%s: %s\n" skyName, pTeamName);

    out:
        "Sky UK: Home comm"

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_sky_team(void)
{
   char skyName[10];
   char* pTeamName = (char*) malloc(19);
   
   strcpy(skyName, "Sky UK");
   strcpy(pTeamName , "Home Comms SW Team");
       
   //print team name
   printf("%s: %s\n", skyName, pTeamName); 
}

int main()
{
    print_sky_team();
    return 0;
}