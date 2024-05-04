#ifndef JEU_H
#define JEU_H
#include "LstPiece.h"

class jeu {
public:
    LstPiece L;
    LstPiece LstCoul[4];
    LstPiece LstForm[4];

    void insererCoul(Piece* Newp);
    void insererForm(Piece* Newp);
    Piece* generatePiece();
};

#endif 
