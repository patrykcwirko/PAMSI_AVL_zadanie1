#ifndef _BSTREE_H_
#define _BSTREE_H_

#include <stdio.h>
#include "stddef.h"

struct TWezel {
	int klucz;
	int balans;
	TWezel * rodzic;
	TWezel * lewy;
	TWezel * prawy;
};

class CBST {
	public:
		CBST(void) {}
	    TWezel * wyszukaj(int klucz);
        bool dodaj(int klucz);
        bool usun(int klucz);
        int wysokosc(void);
        void print() const;
};



#endif
