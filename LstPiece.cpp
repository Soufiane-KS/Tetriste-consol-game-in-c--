#include "LstPiece.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int getColorIndex(char c) {
    switch (c) {
        case 'V':
            return 0;
            break;
        case 'R':
            return 1;
            break;
        case 'J':
            return 2;
            break;
        case 'B':
            return 3;
        default:
            cout << "invalid color !!!" << endl;
            break;
    }
    return 0;
}

int getFormIndex(char f) {
    switch (f) {
        case 'C':
            return 0;
            break;
        case 'L':
            return 1;
            break;
        case 'T':
            return 2;
            break;
        case 'R':
            return 3;
            break;
        default:
            cout << "invalid color !!!" << endl;
            break;
    }
    return 0;
}

string convertColor(char c) {
    switch (c) {
        case 'V':
            return "\033[32m";
            break;
        case 'R':
            return "\033[31m";
            break;
        case 'J':
            return "\033[33m";
            break;
        case 'B':
            return "\033[34m";
        default:
            cout << "invalid color !!!" << endl;
            break;
    }
    return "";
}
extern int score;

void LstPiece::insererDebut(Piece* Newp) {
    if (!tete) {
        tete = Newp;
        tete->suiv = tete;
    } else {
        Piece* tmp = tete;
        while (tmp->suiv != tete) {
            tmp = tmp->suiv;
        }
        tmp->suiv = Newp;
        Newp->suiv = tete;
        tete = Newp;
    }
}

void LstPiece::insererFin(Piece* Newp) {
    if (!tete) {
        tete = Newp;
        tete->suiv = tete;
    } else {
        Piece* tmp = tete;
        while (tmp->suiv != tete) {
            tmp = tmp->suiv;
        }
        tmp->suiv = Newp;
        Newp->suiv = tete;
    }
}

void LstPiece::insert(Piece* Newp, char pos) {
    if (pos == 'g' || pos == 'G') {
        insererDebut(Newp);
    } else if (pos == 'd' || pos == 'D') {
        insererFin(Newp);
    } else {
        cout << "invalid position !!!" << endl;
    }
    verifierSuppression();
}

void LstPiece::swap(Piece* P1, Piece* P2) {
    if (!P1 || !P2 || P1 == P2 || P1->suiv != P2) {
        return;
    }

    Piece* P1Prev = nullptr;
    Piece* tmp = tete;

    while (tmp && tmp->suiv != P1) {
        tmp = tmp->suiv;
    }
    if (tmp) {
        P1Prev = tmp;
    } else {
        return;
    }

    if (P1Prev) {
        P1Prev->suiv = P2;
    } else {
        tete = P2;
    }

    P1->suiv = P2->suiv;
    P2->suiv = P1;
}

void LstPiece::decalage(char choice) {
    if (choice != 'c' && choice != 'f') {
        cout << "Invalid choice. Please choose 'c' for color or 'f' for form." << endl;
        return;
    }

    char specificChoice;
    if (choice == 'c') {
        cout << "Enter color ('v' for green, 'b' for blue, 'r' for red, 'j' for yellow): ";
        cin >> specificChoice;
        if (specificChoice != 'v' && specificChoice != 'b' && specificChoice != 'r' && specificChoice != 'j') {
            cout << "Invalid color. Please choose 'v', 'b', 'r', or 'j'." << endl;
            return;
        }

        char dir;
        cout << "Entrer la direction de décalage";
        cin >> dir;

    } else if (choice == 'f') {
        cout << "Enter shape ('c' for circle, 'r' for rectangle, 't' for triangle, 'l' for line): ";
        cin >> specificChoice;
        if (specificChoice != 'c' && specificChoice != 'r' && specificChoice != 't' && specificChoice != 'l') {
            cout << "Invalid shape. Please choose 'c', 'r', 't', or 'l'." << endl;
            return;
        }
    }
}

void LstPiece::verifierSuppression() {
    if (!tete || !tete->suiv || !tete->suiv->suiv)
        return;

    Piece* tmp = tete;
    while (tmp->suiv->suiv->suiv != tete) {
        if ((tmp->suiv->couleur == tmp->suiv->suiv->couleur && tmp->suiv->suiv->couleur == tmp->suiv->suiv->suiv->couleur) ||
            (tmp->suiv->forme == tmp->suiv->suiv->forme && tmp->suiv->suiv->forme == tmp->suiv->suiv->suiv->forme)) {
            Piece* toDelete = tmp->suiv;
            tmp->suiv = tmp->suiv->suiv->suiv->suiv;
            delete toDelete;
            score += 100;
        } else {
            tmp = tmp->suiv;
        }
    }
}

void LstPiece::Afficher() {
    if (!tete) {
        cout << "La liste est vide " << endl;
    } else {
        Piece* tmp = tete;
        do {
            cout << convertColor(tmp->couleur) << tmp->forme << " ";
            cout << "\033[0m";
            tmp = tmp->suiv;
        } while (tmp != tete);
        cout << endl;
    }
}
