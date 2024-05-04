#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "jeu.h"
#include "LstPiece.h"

using namespace std;

char formes[] = {'C', 'L', 'T', 'R'};
char couleurs[] = {'V', 'R', 'J', 'B'};
int score = 0;

int getColorIndex(char c);
int getFormIndex(char f);
string convertColor(char c);

int main() {
    srand(time(nullptr));
    LstPiece L;
    jeu j;

    while (true) {
        Piece *p = j.generatePiece();
        cout << "Piece suivante : " << convertColor(p->couleur) << p->forme << " "
             << "\033[0m" << endl;
        char c;

        cout << "Tapez 'd | D' ou 'g | G' pour inserer" << endl;
        cout << "score :" << score << endl;
        c = _getch();
        if (c == 'q') {
            cout << "Game Over" << endl;
            break;
        } else if (c == 's' || c == 'S') {
            cout << "forme f ou color c : ";
            char k;
            cin >> k;
            L.decalage(k);
        } else {
            L.insert(p, c);
            system("cls");
            L.Afficher();
        }
    }

    return 0;
}
