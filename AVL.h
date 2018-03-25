#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <stdio.h>
#include "stddef.h"

#include "BST.h"

#define WAGA_PLUS_EXTRA 2
#define WAGA_PLUS_JEDEN 1
#define WAGA_ZERO 0
#define WAGA_MINUS_JEDEN -1
#define WAGA_MINUS_EXTRA -2


class CAVL : public CBST
{
    public:
        CAVL(void) : CBST() {}
		bool dodaj(int klucz);
		int zbalansuj();

    private:
        void obrocLL(TWezel * wezel);
        void obrocRR(TWezel * wezel);
        void obrocLR(TWezel * wezel);
        void obrocRL(TWezel * wezel);
};

#endif
