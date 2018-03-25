#include "AVL.h"
#include "BST.h"

bool CAVL::dodaj(int klucz) {
    return CBST::dodaj( klucz );
}

int CAVL::zbalansuj() {
//    printf("\n CAVL::zbalansuj\n");
    TWezel * wezel = punktZwrotny;
    while ( wezel->rodzic && wezel->balans ) {
        if ( wezel->klucz < wezel->rodzic->klucz ) {
            --wezel->rodzic->balans;
            if ( wezel->rodzic->balans == WAGA_MINUS_EXTRA ) {
                if ( wezel->balans == WAGA_PLUS_JEDEN ) {
                    obrocLR( wezel->rodzic );
                } else {
                    obrocLL( wezel->rodzic );
                }
            }
        } else {
            ++wezel->rodzic->balans;
            if ( wezel->rodzic->balans == WAGA_PLUS_EXTRA ) {
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
    TWezel * dziecko = wezel->lewy;
    wezel->lewy = dziecko->prawy;
    if ( dziecko->prawy ) {
        dziecko->prawy->rodzic = wezel;
    }
    dziecko->prawy = wezel;
    dziecko->rodzic = wezel->rodzic;
    if ( wezel->rodzic ) {
        if ( dziecko->klucz < wezel->rodzic->klucz ) {
            wezel->rodzic->lewy = dziecko;
        } else {
            wezel->rodzic->prawy = dziecko;
        }
    } else {
        korzen = dziecko;
    }
    wezel->rodzic = dziecko;
    if ( dziecko->balans == WAGA_MINUS_JEDEN ) {
        wezel->balans = WAGA_ZERO;
        dziecko->balans = WAGA_ZERO;
    } else {
        wezel->balans = WAGA_MINUS_JEDEN;
        dziecko->balans = WAGA_PLUS_JEDEN;
    }
}

void CAVL::obrocRR(TWezel * wezel) {
    printf("RR\n");
    TWezel * dziecko = wezel->prawy;
    wezel->prawy = dziecko->lewy;
    if ( dziecko->lewy ) {
        dziecko->lewy->rodzic = wezel;
    }
    dziecko->lewy = wezel;
    dziecko->rodzic = wezel->rodzic;
    if ( wezel->rodzic ) {
        if ( dziecko->klucz < wezel->rodzic->klucz ) {
            wezel->rodzic->lewy = dziecko;
        } else {
            wezel->rodzic->prawy = dziecko;
        }
    } else {
        korzen = dziecko;
    }
    wezel->rodzic = dziecko;
    if ( dziecko->balans == WAGA_PLUS_JEDEN ) {
        wezel->balans = WAGA_ZERO;
        dziecko->balans = WAGA_ZERO;
    } else {
        wezel->balans = WAGA_PLUS_JEDEN;
        dziecko->balans = WAGA_MINUS_JEDEN;
    }
}

void CAVL::obrocLR(TWezel * wezel) {
    printf("LR\n");
    TWezel * dziecko = wezel->lewy;
    TWezel * nastepneDziecko = dziecko->prawy;
    int tmp = wezel->klucz;
    wezel->klucz = nastepneDziecko->klucz;
    nastepneDziecko->klucz = tmp;
    dziecko->prawy = nastepneDziecko->lewy;
    if ( nastepneDziecko->lewy ) {
        nastepneDziecko->lewy->rodzic = dziecko;
    }
    nastepneDziecko->lewy = nastepneDziecko->prawy;
    nastepneDziecko->prawy = wezel->prawy;
    if ( wezel->prawy ) {
        wezel->prawy->rodzic = nastepneDziecko;
    }
    wezel->prawy = nastepneDziecko;
    nastepneDziecko->rodzic = wezel;
    wezel->balans = ( nastepneDziecko->balans == WAGA_MINUS_JEDEN ) ? WAGA_PLUS_JEDEN : WAGA_ZERO;
    dziecko->balans = ( nastepneDziecko->balans == WAGA_PLUS_JEDEN ) ? WAGA_MINUS_JEDEN : WAGA_ZERO;
    nastepneDziecko->balans = WAGA_ZERO;
}

void CAVL::obrocRL(TWezel * wezel) {
    printf("RL\n");
    TWezel * dziecko = wezel->prawy;
    TWezel * nastepneDziecko = dziecko->lewy;
    int tmp = wezel->klucz;
    wezel->klucz = nastepneDziecko->klucz;
    nastepneDziecko->klucz = tmp;
    dziecko->lewy = nastepneDziecko->prawy;
    if ( nastepneDziecko->prawy ) {
        nastepneDziecko->prawy->rodzic = dziecko;
    }
    nastepneDziecko->prawy = nastepneDziecko->lewy;
    nastepneDziecko->lewy = wezel->lewy;
    if ( wezel->lewy ) {
        wezel->lewy->rodzic = nastepneDziecko;
    }
    wezel->lewy = nastepneDziecko;
    nastepneDziecko->rodzic = wezel;
    wezel->balans = ( nastepneDziecko->balans == WAGA_PLUS_JEDEN ) ? WAGA_MINUS_JEDEN : WAGA_ZERO;
    dziecko->balans = ( nastepneDziecko->balans == WAGA_MINUS_JEDEN ) ? WAGA_PLUS_JEDEN : WAGA_ZERO;
    nastepneDziecko->balans = WAGA_ZERO;
}
