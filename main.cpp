#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "AVL.h"

#define PRT_DODAJ 0
#define PRT_USUN 0
#define PRT_ORDERS 0

#define ILOSC 10

using namespace std;

void wypelnijTablice(int * tablica, int ilosc) {
    int id;
    for (int i = 0 ; i < ilosc ; ++i) {
        tablica[i] = 0;
    }
    for (int i = 0 ; i < ilosc ; ++i) {
        do
        	id = rand() % ilosc;
        while (tablica[id]);
        tablica[id] = i + 1;
    }
}

int main(int argc, char *argv[]) {
    CAVL avl;
    int  wysokosc;
    char stop;
    int ilosc = ILOSC;
//        int tWartosci[] = { 60,30,20,10 }; //LL
//        int tWartosci[] = { 60,30,20,10,80,100,50 }; //RR
//        int tWartosci[] = { 60,30,20,10,100,120,50,80,70 }; //LR
    int initWartosci[] = { 60,30,20,10,100,120,50,80,70,54,57 }; //LR
    vector < int > tWartosci;
    for(int i=0; i<11; i++) {
        tWartosci.push_back(initWartosci[i]);
    }

    for (unsigned i=0; i<tWartosci.size() ; i++) {
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

    int liczba;
    do {
        printf("Czy chcesz dodac liczbe do drzewa.\n");
        printf("t - TAK\n");
        printf("n - NIE\n");
        cin >> stop;
        if( stop == 't' || stop == 'T' ) {
            printf("Podaj liczbe do dodania.\n");
            cin >> liczba;
            ilosc += 1;
            tWartosci.push_back(liczba);
            avl.dodaj(liczba);
            avl.print();
        }
    }while( stop == 't' || stop == 'T' );

    if(PRT_ORDERS) printf("\nin-order\n");
    if(PRT_ORDERS) avl.print_inOrder();
    if(PRT_ORDERS) printf("\npre-order\n");
    if(PRT_ORDERS) avl.print_preOrder();
    if(PRT_ORDERS) printf("\npost-order\n");
    if(PRT_ORDERS) avl.print_postOrder();

	wysokosc = avl.wysokosc();
    printf("\nWysokosc po dodaniu: %d\n", wysokosc);
    int wartosc;
    while (!tWartosci.empty())
    {
        if( avl.usun( tWartosci.back() ) ) {
            if(PRT_USUN) printf("Drzewo po usunieciu <%d>\n", tWartosci.back() );
            if(PRT_USUN) avl.print();
            if(PRT_USUN) stop = getchar();
        }
        tWartosci.pop_back();
    }

	wysokosc = avl.wysokosc();
    printf("Wysokosc po usunieciu: %d\n", wysokosc);
    avl.print();
    tWartosci.clear();
    return 0;
}
