#include "BST.h"

TWezel * CBST::wyszukaj(int klucz) {
    TWezel * w = korzen;
    while ( true ) {
        if ( !w ) {
            return NULL;
        }
        if ( klucz == w->klucz ) {
            return w;
        }
        // jesli klucz < od wartosci klucza w wezle, to na lewo
        if ( klucz < w->klucz ) {
            w = w->lewy;
        // jesli klucz > od wartosci klucza w wezle, to na prawo
        } else {
            w = w->prawy;
        }
    }
}

bool CBST::dodaj(int klucz) {
	// 1. domyslnie tworzy wezla z zadanym kluczem
    TWezel * nowyWezel = new TWezel(klucz);
    if ( !korzen ) {
        korzen = nowyWezel;
        nowyWezel->rodzic = NULL;
        // niezadobre rozwiazanie, ale nie ma jak przekazac do potem do AVL
        punktZwrotny = korzen;
        return true;
    }
    TWezel * wezel = korzen;
    bool ok = false;
    while ( !ok ) {
        // 2. jesli klucz istnieje: kasuje domyslenego wezla i nic nie robi
        if ( klucz == wezel->klucz ) {
            delete nowyWezel;
            return false;
        // 3. w zalezniosci od porownania wart. szuka mniejsca do wstawienia:
        // 3.1. na lewo (wart. klucza < od wart. klucza w wezle
        } else if ( klucz < wezel->klucz ) {
            // 3.1.1 jesli jest cos na lewo wznawia szukanie od tego wezla ustawiajac wartosc korzenia
            if ( wezel->lewy ) {
                wezel = wezel->lewy;
            // 3.1.2 jesli nie ma nic na lewo wstawia tam nowy wezel
            } else {
                wezel->lewy = nowyWezel;
                nowyWezel->rodzic = wezel;
                --wezel->balans; //
                ok = true;
            }
        // 3.2. na prawo (wart. klucza > od wart. klucza w wezle
        } else {
            // 3.2.1 jesli jest cos na prawo wznawia szukanie od tego wezla ustawiajac wartosc korzenia
            if ( wezel->prawy ) {
                wezel = wezel->prawy;
            // 3.2.2 jesli nie ma nic na prawo wstawia tam nowy wezel
            } else {
                wezel->prawy = nowyWezel;
                nowyWezel->rodzic = wezel;
                ++wezel->balans; //
                ok = true;
            }
        }
   }
   // niezadobre rozwiazanie, ale nie ma jak przekazac do potem do AVL
   punktZwrotny = wezel;
   return true;
}

bool CBST::usun(int klucz) {
    // 1. wyszukuje wezel do usuniecia dla zadanego klucza
    TWezel * wezel = wyszukaj( klucz );
    if ( !wezel ) {
        return false;
    }
    // 2.1. jesli wezel nie ma potomkow
    if ( !wezel->lewy && !wezel->prawy ) {
        // 2.1.1. i znaleiony wezel jest korzeniem
        if ( wezel == korzen ) {
            korzen = NULL;
        } else {
            // 2.1.2. lub znaleziony wezel ma klucz < od klucza w swoim rodzicu,
            // ustawia na NULL odpowiednio
            if ( wezel->klucz < wezel->rodzic->klucz ) {
                wezel->rodzic->lewy = NULL;
            } else {
                wezel->rodzic->prawy = NULL;
            }
        }
    // 2.2. jesli wezel ma jednego potomkow
    } else if ( !wezel->lewy || !wezel->prawy ) {
        // 2.2.1.
        if ( wezel == korzen ) {
            // 2.2.1.1. jesli korzen ma odpowiednio na lewo lub prawo
            // przesuwa odpowiedniego jako korzen
            if ( wezel->lewy ) {
                korzen = wezel->lewy;
            } else {
                korzen = wezel->prawy;
            }
            korzen->rodzic = NULL;
        // 2.2.2. znaleziony wezel ma klucz < od klucza w rodzicu
        } else if ( wezel->klucz < wezel->rodzic->klucz ) {
            // 2.2.2.1 wiec jeli jest lewy to zamiana:
            if ( wezel->lewy ) {
                // w rodzicu z lewej na lewego z wezla
                wezel->rodzic->lewy = wezel->lewy;
                // w wezle rodzic lewego z rodzica wezla
                wezel->lewy->rodzic = wezel->rodzic;
            } else {
                // w rodzicu z lewej na prawego z wezla
                wezel->rodzic->lewy = wezel->prawy;
                wezel->prawy->rodzic = wezel->rodzic;
            }
        // 2.2.3.
        } else {
            if ( wezel->lewy ) {
                wezel->rodzic->prawy = wezel->lewy;
                wezel->lewy->rodzic = wezel->rodzic;
            } else {
                wezel->rodzic->prawy = wezel->prawy;
                wezel->prawy->rodzic = wezel->rodzic;
            }
        }
    // 2.3. jesli wezel ma obu potomkow
    } else {
        // 2.3.1. szuka nastepnego wezla (od prawego na lewo)
        TWezel * nowyWezel = nastepny( wezel );
        // podmienia relacje
        wezel->klucz = nowyWezel->klucz;
        if ( nowyWezel == wezel->prawy ) {
            wezel->prawy = nowyWezel->prawy;
            if ( nowyWezel->prawy ) {
                nowyWezel->prawy->rodzic = wezel;
            }
        } else {
            nowyWezel->rodzic->prawy = nowyWezel->prawy;
            if ( nowyWezel->prawy ) {
                nowyWezel->prawy->rodzic = nowyWezel->rodzic;
            }
        }
        wezel = nowyWezel;
    }
    delete wezel;
    return true;
}

int CBST::wysokosc(void) {
    if ( !korzen ) {
        return 0;
    }
    return wysokosc( korzen );
}

int CBST::wysokosc(TWezel * wezel) {
	if ( !wezel->lewy && !wezel->prawy ) {
        return 0;
    }
    // 1. najpierw sprawdza, czy nie ma nic na lewo i zlicza dalej na prawo
    if ( !wezel->lewy ) {
        return (wysokosc( wezel->prawy ) + 1);
    }
    // 2. jesli prawy jest pusty, to na lewo i zlicza dalej
    if ( !wezel->prawy ) {
        return (wysokosc( wezel->lewy) +1);
    }
    int l = wysokosc( wezel->lewy);
    int r = wysokosc( wezel->prawy);
    // wybiera wyzsza wartosc
    if ( l > r ) {
        return ++l;
    } else {
        return ++r;
    }
}

void CBST::print() const {
    if (korzen == NULL) {
        printf("# ---.\n");
    } else {
        print(KORZEN, korzen, 0);
    }
}

void CBST::print_inOrder() const {
    if (korzen == NULL) {
        printf("# ---.\n");
    } else {
        print_inOrder(KORZEN, korzen, 0);
    }
}

void CBST::print_postOrder() const {
    if (korzen == NULL) {
        printf("# ---.\n");
    } else {
        print_postOrder(KORZEN, korzen, 0);
    }
}

void CBST::print_preOrder() const {
    if (korzen == NULL) {
        printf("# ---.\n");
    } else {
        print_preOrder(KORZEN, korzen, 0);
    }
}

void CBST::print(char symbol, TWezel * rodzic, int poziom) const {
    if (rodzic == NULL) return;
    print(LEWY, rodzic->lewy, poziom+1);
    for (int i=0; i<poziom; i++) {
        printf(ODSTEP);
    }
    printf( "%c(%d)\n", symbol, rodzic->klucz );
    print(PRAWY, rodzic->prawy, poziom+1);
}

void CBST::print_inOrder(char symbol, TWezel * wezel, int poziom) const {
    if ( wezel == NULL ) return;
    print_inOrder(LEWY, wezel->lewy, poziom+1);
    for (int i=0; i<poziom; i++) {
        printf(ODSTEP);
    }
    printf( "%c(%d)\n", symbol, wezel->klucz );
    print_inOrder(PRAWY, wezel->prawy, poziom+1);
}

void CBST::print_preOrder(char symbol, TWezel * wezel, int poziom) const {
    if ( wezel == NULL ) return;
    for (int i=0; i<poziom; i++) {
        printf(ODSTEP);
    }
    printf( "%c(%d)\n", symbol, wezel->klucz );
    print_preOrder(LEWY, wezel->lewy, poziom+1);
    print_preOrder(PRAWY, wezel->prawy, poziom+1);
}

void CBST::print_postOrder(char symbol, TWezel * wezel, int poziom) const {
    if ( wezel == NULL ) return;
    print_postOrder(LEWY, wezel->lewy, poziom+1);
    print_postOrder(PRAWY, wezel->prawy, poziom+1);
    for (int i=0; i<poziom; i++) {
        printf(ODSTEP);
    }
    printf( "%c(%d)\n", symbol, wezel->klucz );
}

// poprzedni od lewego na prawo
TWezel * CBST::poprzedni(TWezel * wezel) {
    if ( !wezel->lewy ) {
        return NULL;
    }
    TWezel * dziecko = wezel->lewy;
    while ( dziecko->prawy ) {
        dziecko = dziecko->prawy;
    }
    return dziecko;
}

// nastepny od prawego na lewego
TWezel * CBST::nastepny(TWezel * wezel) {
    if (!wezel->prawy ) {
        return NULL;
    }
    TWezel * dziecko = wezel->prawy;
    while ( dziecko->lewy ) {
        dziecko = dziecko->lewy;
    }
    return dziecko;
}
