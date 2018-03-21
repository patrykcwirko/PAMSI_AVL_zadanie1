#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include <stdio.h>
#include "stddef.h"

#include "BST.h"

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
