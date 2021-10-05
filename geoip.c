#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IS_VALID(x) ((x>=0) && (x <=255))

int convertIP2int( char *adresse_ip );
bool findIP( int ip_decimal );

int main( int argc, char **argv )
{
    unsigned int ip_decimal;

    if (argc == 2) {
        // Affectation et test en une seule fois
        if ( (ip_decimal = convertIP2int(argv[1])) == -1 ) {
            fprintf( stderr, "Erreur adresse IP\n");
            exit(EXIT_FAILURE);
        } else {

            if ( findIP( ip_decimal ) ) {
                printf("Trouvé");
            } else {
                printf("Non trouvé\n");
            }
        }
        
        
    } else {
        printf("Usage:\n");
        printf("\t%s <adresse_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}


bool findIP( int ip_decimal )
{
    return(false);
}

// A revoir
// Si retourne -1, alors adresse invalide
int convertIP2int( char *adresse_ip )
{
    int ip0, ip1, ip2, ip3;
    int ip_dec;
    int retour_sscanf;

    retour_sscanf = sscanf( adresse_ip, "%d.%d.%d.%d", &ip0, &ip1, &ip2, &ip3 );

    if ( retour_sscanf == 4 && IS_VALID(ip0) && IS_VALID(ip1) && IS_VALID(ip2) && IS_VALID(ip3) ) {
        ip_dec = (ip0 << 24) + (ip1 << 16) + (ip2 << 8) + ip3;  
    } else {
        ip_dec = -1;
    }

    return(ip_dec);
}
/*
bool isValid( int ip_part )
{
    return((ip_part>=0) && (ip_part <=255));
}
*/