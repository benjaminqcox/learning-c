#include <stdio.h>

typedef struct ProtFields {
    u_int16_t ID : 7;
    u_int16_t Priority : 3;
    u_int16_t Type : 6;
    // ^ Total = 2 bytes (7bits + 3bits + 6bits = 16bits)
    //u_int16_t == unsigned short int;
    //type "_t" means typedef (name assignment of other type)
} ProtFields;

union Prot {
    unsigned short int hCode; // 2 bytes
    ProtFields pf; // Stores 2 bytes
} Prot;

int main()
{
    unsigned short int hexCode = 0xB7B2;

    // Prot with bit shifting
    ProtFields pf = {hexCode, hexCode >> 7, hexCode >> 10};
    printf("Size of protFields%lu\n", sizeof(pf));
    printf("ID: %d, Priority: %d, Type: %d\n", pf.Type, pf.Priority, pf.ID);

    // Prot with union
    union Prot p = {hexCode};
    printf("Size of prot: %lu\n", sizeof(p));
    printf("ID: %d, Priority: %d, Type: %d\n", p.pf.Type, p.pf.Priority, p.pf.ID);

    return 0;
}