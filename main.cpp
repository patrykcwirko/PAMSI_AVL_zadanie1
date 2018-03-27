#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>
#include <limits.h>
#include <cstring>

#include "AVL.h"

#define PRT_DODAJ 0
#define PRT_USUN 1
#define PRT_ORDERS 0

int main(int argc, char *argv[]) {
    CAVL avl;
    int  wysokosc;
    char stop;
    int ilosc;
//        int tWartosci[] = { 60,30,20,10 }; //LL
//        int tWartosci[] = { 60,30,20,10,80,100,50 }; //RR
//        int tWartosci[] = { 60,30,20,10,100,120,50,80,70 }; //LR
          int tWartosci[] = { 60,30,20,10,100,120,50,80,70,54,57 }; //LR

    ilosc = sizeof(tWartosci)/sizeof(int);
    for (int i = 0 ; i < ilosc ; ++i) {
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

    if(PRT_ORDERS) printf("\nin-order\n");
    if(PRT_ORDERS) avl.print_inOrder();
    if(PRT_ORDERS) printf("\npre-order\n");
    if(PRT_ORDERS) avl.print_preOrder();
    if(PRT_ORDERS) printf("\npost-order\n");
    if(PRT_ORDERS) avl.print_postOrder();

	wysokosc = avl.wysokosc();
    printf("\nWysokosc po dodaniu: %d\n", wysokosc);
    ilosc = sizeof(tWartosci)/sizeof(int);
    for (int i = 0 ; i < ilosc ; ++i) {
        if( avl.usun( tWartosci[i] ) ) {
            if(PRT_USUN) printf("Drzewo po usunieciu <%d>\n", tWartosci[i] );
            if(PRT_USUN) avl.print();
            if(PRT_USUN) stop = getchar();
        }
    }

	wysokosc = avl.wysokosc();
    printf("Wysokosc po usunieciu: %d\n", wysokosc);
    avl.print();

    return 0;
}
