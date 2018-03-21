#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include "stddef.h"

#define LEWY 'L'
#define PRAWY 'P'
#define KORZEN '#'

struct TWezel {
	int klucz;
	int balans;
	TWezel * rodzic;
	TWezel * lewy;
	TWezel * prawy;
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

    private:
        void print(char symbol, TWezel * rodzic, int poziom) const;
};

#endif
