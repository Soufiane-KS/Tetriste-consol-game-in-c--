#ifndef LSTPIECE_H
#define LSTPIECE_H
#include "Piece.h"
#include <string>

class LstPiece {
public:
    Piece* tete = nullptr;

    void insererDebut(Piece* Newp);
    void insererFin(Piece* Newp);
    void insert(Piece* Newp, char pos);
    void swap(Piece* P1, Piece* P2);
    void decalage(char choice);
    void verifierSuppression();
    void Afficher();
};

#endif 
