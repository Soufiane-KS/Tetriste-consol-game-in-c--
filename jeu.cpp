#include "jeu.h"
#include <cstdlib>
#include <ctime>
#include <string>

int getColorIndex(char c);
int getFormIndex(char f);
std::string convertColor(char c);

extern char formes[];
extern char couleurs[];

void jeu::insererCoul(Piece* Newp) {
    int colorIndex = getColorIndex(Newp->couleur);
    if (LstCoul[colorIndex].tete == nullptr) {
        LstCoul[colorIndex].tete = Newp;
        Newp->suivmmCouleur = Newp->prevmmCouleur = Newp;
    } else {
        Piece* lastPiece = LstCoul[colorIndex].tete->prevmmCouleur;
        Newp->suivmmCouleur = LstCoul[colorIndex].tete;
        Newp->prevmmCouleur = lastPiece;
        LstCoul[colorIndex].tete->prevmmCouleur = lastPiece->suivmmCouleur = Newp;
    }
}

void jeu::insererForm(Piece* Newp) {
    int formIndex = getFormIndex(Newp->forme);
    if (LstForm[formIndex].tete == nullptr) {
        LstForm[formIndex].tete = Newp;
        Newp->suivmmForme = Newp->prevmmForme = Newp;
    } else {
        Piece* lastPiece = LstForm[formIndex].tete->prevmmForme;
        Newp->suivmmForme = LstForm[formIndex].tete;
        Newp->prevmmForme = lastPiece;
        LstForm[formIndex].tete->prevmmForme = lastPiece->suivmmForme = Newp;
    }
}

Piece* jeu::generatePiece() {
    Piece* Newp = new Piece(formes[rand() % 4], couleurs[rand() % 4]);
    return Newp;
}
