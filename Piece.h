#ifndef PIECE_H
#define PIECE_H

class Piece {
public:
    char couleur, forme;
    Piece* suiv;
    Piece* suivmmCouleur;
    Piece* prevmmCouleur;
    Piece* suivmmForme;
    Piece* prevmmForme;
    Piece(char f, char c);
};

#endif 
