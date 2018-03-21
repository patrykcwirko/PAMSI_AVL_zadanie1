#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <cstring>

#include "AVL.h"

#define ILOSC 10

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
//    int * tWartosci = new int[ilosc];
//    wypelnijTablice(tWartosci, ilosc);
//    int tWartosci[] = { 1,2,3,4,5 };
    int tWartosci[] = { -1,-2,-3,-4,-5 };

    int dlugosc = sizeof(tWartosci)/sizeof(int);
    for (int i = 0 ; i < dlugosc ; ++i) {
        if( avl.dodaj(tWartosci[i]) ) {
            avl.print();
            stop = getchar();
            avl.zbalansuj();
            avl.print();
            stop = getchar();
        }
        system("cls");
    }

	wysokosc = avl.wysokosc();
    printf("Wysokosc: %d", wysokosc);
    for (int i = 0 ; i < ilosc ; ++i) {
        avl.usun(i + 1);
    }

//    delete [] tWartosci;
    return 0;
}
