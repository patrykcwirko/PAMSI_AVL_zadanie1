#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>

#define WYSWIETL 1

#define ILOSC 20

#include "AVL.h"

void wypelnijTablice(int * t, int cnt) {
	
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