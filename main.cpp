#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <cstring>

#include "AVL.h"

#define ILOSC 10
#define PRT_DODAJ 0
#define PRT_USUN 0

int main(int argc, char *argv[]) {
    CAVL avl;
    int  wysokosc;
    char stop;
    int ilosc = ILOSC;
    int dlugosc;
    int tWartosci[] = { 6,3,2,1 };

    dlugosc = sizeof(tWartosci)/sizeof(int);
    for (int i = 0 ; i < dlugosc ; ++i) {
        if( avl.dodaj(tWartosci[i]) ) {
            if(PRT_DODAJ) printf("Dodanie <%d> przed zbalansowaniem\n", tWartosci[i] );
            if(PRT_DODAJ) avl.print();
            avl.zbalansuj();
            if(PRT_DODAJ) printf("Zbalansowanie dla <%d>\n\n", tWartosci[i] );
            if(PRT_DODAJ) avl.print();
            if(PRT_DODAJ) stop = getchar();
        }
        system("cls");
    }
    printf("Zbalansowane drzewo BST/AVL\n");
    avl.print();
    stop = getchar();

	wysokosc = avl.wysokosc();
    printf("Wysokosc po dodaniu: %d\n", wysokosc);
    dlugosc = sizeof(tWartosci)/sizeof(int);
    for (int i = 0 ; i < dlugosc ; ++i) {
        if( avl.usun( tWartosci[i] ) ) {
            if(PRT_USUN) avl.print();
            if(PRT_USUN) avl.zbalansuj();
            if(PRT_USUN) printf("\n");
            if(PRT_USUN) avl.print();
            if(PRT_USUN) stop = getchar();
        }
//        system("cls");
    }

	wysokosc = avl.wysokosc();
    printf("Wysokosc po usunieciu: %d\n", wysokosc);
    avl.print();

//    delete [] tWartosci;
    return 0;
}
