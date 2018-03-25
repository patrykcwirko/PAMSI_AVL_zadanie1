#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include "stddef.h"

#define LEWY 'L'
#define PRAWY 'P'
#define KORZEN '#'
#define ODSTEP "   "

struct TWezel {
	int klucz;
	int balans;
	TWezel * rodzic;
	TWezel * lewy;
	TWezel * prawy;
	TWezel(int kluczyk) : klucz(kluczyk), balans(0), rodzic(NULL), lewy(NULL), prawy(NULL) {}
};

class CBST {
	public:
		CBST(void) : korzen(NULL), punktZwrotny(NULL) {}
	    TWezel * wyszukaj(int klucz);
        bool dodaj(int klucz);
        bool usun(int klucz);
        int wysokosc(void);
        void print() const;

    protected:
        TWezel * korzen;
        TWezel * punktZwrotny;

        TWezel * poprzedni(TWezel * wezel);
        TWezel * nastepny(TWezel * wezel);

    private:
        int wysokosc(TWezel * wezel);
        void print(char symbol, TWezel * rodzic, int poziom) const;
};

#endif
