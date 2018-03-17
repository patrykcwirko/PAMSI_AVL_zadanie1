#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>

#define WYSWIETL 1

#define ILOSC 20

#include "AVL.h"

void ustawZiarnoRanda() {
    struct timeval te;
    gettimeofday(&te, NULL);
    unsigned int iseed = te.tv_usec;
    srand (iseed);
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
    int ilosc = ILOSC;
    int  wysokosc;
    int * tWartosci = new int[ilosc];

    wypelnijTablice(tWartosci, ilosc);

    for (int i = 0 ; i < ilosc ; ++i) {
        avl.dodaj(tWartosci[i]);
    }
    if(WYSWIETL) avl.print();

	wysokosc = avl.wysokosc();
    printf("Wysokosc: %d", wysokosc);
    for (int i = 0 ; i < ilosc ; ++i) {
        avl.usun(i + 1);
    }

    delete [] tWartosci;
    return 0;
}
