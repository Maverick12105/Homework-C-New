#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int x, y, z, m;
    char nickname[11];

} address_t;

int scan_address(address_t* IPs);
void print_address(address_t IPs);
int local_address(address_t IP_a, address_t IP_b);

int main()
{
    address_t IPs[100];
    int i;

    i = -1;
    do
    {
        ++i;
        scan_address(&IPs[i]);
    } while (IPs[i].x != 0 && IPs[i].y != 0 && IPs[i].z != 0 && IPs[i].m != 0 && IPs[i].nickname != "none");
    printf("\n");

    for (int j = 0; j < i; ++j)
        for (int u = j + 1; u < i; ++u) 
            if (local_address(IPs[j], IPs[u]) == 1)
                printf("Machine %s and %s are on the same local network.\n", IPs[j].nickname, IPs[u].nickname);
    printf("\n");

    i = -1;
    do
    {
        ++i;
        print_address(IPs[i]);
    } while (IPs[i].x != 0 && IPs[i].y != 0 && IPs[i].z != 0 && IPs[i].m != 0 && IPs[i].nickname != "none");
    printf("\n");

    system("pause");

    return(0);
}

int scan_address(address_t* IPs)
{
    int output = scanf("%u.%u.%u.%u %s", &IPs->x, &IPs->y, &IPs->z, &IPs->m, IPs->nickname);

    if (output == 5)
        return(1);
    if (output != EOF)
        return(0);
    else
        return(EOF);
}

void print_address(address_t IPs)
{
    printf("%u.%u.%u.%u %s\n", IPs.x, IPs.y, IPs.z, IPs.m, IPs.nickname);
}

int local_address(address_t IP_a, address_t IP_b)
{
    return(IP_a.x == IP_b.x &&
           IP_a.y == IP_b.y);
}

/*
    Numeric addresses for computers on the international network Internet are composed of four parts, separated by periods, of the form
        xx.yy.zz.mm
    where xx, yy, zz, and mm are positive integers.
    Locally, computers are usually known by a nickname as well.
    You are designing a program to process a list of Internet addresses, identifying all pairs of computers from the same locality.
    Create a structure type called address_t with components for the four integers of an Internet address and a fifth component 
    in which to store an associated nickname of ten characters.
    Your program should read a list of up to 100 addresses and nicknames terminated by a sentinel address of all zeros 
    and a sentinel nickname.

    Sample Data
        111.22.3.44 platte
        555.66.7.88 wabash
        111.22.5.66 green
        0.0.0.0     none
    
    The program should display a list of messages identifying each pair of computers from the same locality, that is, 
    each pair of computers with matching values in the first two components of the address.
    In the messages, the computers should be identified by their nicknames.

    Example Message
        Machine platte and green are on the same local network.

    Follow the messages by a display of the full list of addresses and nicknames.
    Include in your program a scan_address function, a print_address function, and a local_address function.
    Function local_address should take two address structures as input parameters and return 1 (for true)
    if the addresses are on the same local network, and 0 (for false) otherwise.
*/