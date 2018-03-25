#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <cstring>

#include "AVL.h"

#define ILOSC 10
#define PRT_DODAJ 1
#define PRT_USUN 0

void ustawZiarnoRanda() {
    struct timeval te;
    gettimeofday(&te, NULL);
    unsigned int ziarno = te.tv_usec;
    srand (ziarno);
}

void wypelnijTablice(int * t, int cnt) {
    int id;
    memset(t,0,cnt);
    ustawZiarnoRanda();
    for (int i = 0 ; i < cnt ; ++i) {
        //unika dodawania zer
        do
        	id = rand() % cnt;
        while (t[id]);
        t[id] = i + 1;
    }
}

int main(int argc, char *argv[]) {
    CAVL avl;
    int  wysokosc;
    char stop;
    int ilosc = ILOSC;
    int dlugosc;
//    int * tWartosci = new int[ilosc];
//    wypelnijTablice(tWartosci, ilosc);
//    int tWartosci[] = { 6,1,3,2,15,13,10,5,14,7,11,18 };
    int tWartosci[] = { 6,3,2,5 };
//    int tWartosci[] = { 6,3,2,5,15,13 };

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
//        system("cls");
    }
    printf("Skonczone drzewo BST/AVL\n");
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

//    delete [] tWartosci;
    return 0;
}
