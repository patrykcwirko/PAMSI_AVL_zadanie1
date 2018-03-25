#include "AVL.h"
#include "BST.h"

bool CAVL::dodaj(int klucz) {
    return CBST::dodaj( klucz );
}

int CAVL::zbalansuj() {
//    printf("\nCAVL::zbalansuj\n");
    TWezel * wezel = punktZwrotny;
    while ( wezel->rodzic && wezel->balans ) {
        if ( wezel->klucz < wezel->rodzic->klucz ) {
            --wezel->rodzic->balans;
            if ( wezel->rodzic->balans == WAGA_PLUS_EXTRA ) {
                if ( wezel->balans == WAGA_PLUS_JEDEN ) {
                    obrocLR( wezel->rodzic );
                } else {
                    obrocLL( wezel->rodzic );
                }
            }
        } else {
            ++wezel->rodzic->balans;
            if ( wezel->rodzic->balans == WAGA_MINUS_EXTRA ) {
                if ( wezel->balans == WAGA_MINUS_JEDEN ) {
                    obrocRL( wezel->rodzic );
                } else {
                    obrocRR( wezel->rodzic );
                }
            }
        }
        if ( wezel->rodzic == NULL ) {
            return true;
        }
        wezel = wezel->rodzic;
    }
    return true;
}

void CAVL::obrocLL(TWezel * wezel) {
    printf("LL\n");
}

void CAVL::obrocRR(TWezel * wezel) {
    printf("RR\n");
}

void CAVL::obrocLR(TWezel * wezel) {
    printf("LR\n");
}

void CAVL::obrocRL(TWezel * wezel) {
    printf("RL\n");
}
