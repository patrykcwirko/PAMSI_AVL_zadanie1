#include "BST.h"

TWezel * CBST::wyszukaj(int kklucz) {
	return NULL;
}

bool CBST::dodaj(int klucz) {
	// 1. domyslnie tworzy wezla z zadanym kluczem
    TWezel * nowyWezel = new TWezel;
    nowyWezel->klucz = klucz;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    nowyWezel->balans = 0; //dla AVL, na potem...
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
	return false;
}

int CBST::wysokosc(void) {
	return 0;
}

void CBST::print() const {
    if (korzen == NULL) {
        printf("# ---.\n");
    } else {
        print(KORZEN, korzen, 0);
    }
}

void CBST::print(char symbol, TWezel * rodzic, int poziom) const {
    if (rodzic == NULL) return;
    print(LEWY, rodzic->lewy, poziom+1);
    for (int i=0; i<poziom; i++) {
        printf("  ");
    }
    printf( "%c(%d)\n", symbol, rodzic->klucz );
    print(PRAWY, rodzic->prawy, poziom+1);
}
