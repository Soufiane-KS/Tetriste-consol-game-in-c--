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

void displayHomeScreen() {
    system("cls"); 
    
    cout << "\033[1;32m"; 
    cout << "******************************" << endl;
    cout << "*      Welcome to Teriste    *" << endl;
    cout << "*    Press any key to start  *" << endl;
    cout << "*        Press 'q' to quit   *" << endl;
    cout << "******************************" << endl;
    cout << "\033[0m"; 
}

int main() {
    srand(time(nullptr));
    LstPiece L;
    jeu j;
    
    displayHomeScreen();
    
    _getch();
    
    while (true) {
        
        
        
        Piece* p = j.generatePiece();
        
        cout << "Next Piece: " << convertColor(p->couleur) << p->forme << "\033[0m" << endl;
        
        cout << "Press 'd' to insert on the right or 'g' to insert on the left." << endl;
        char choice = _getch();
        if(choice == 'q' || choice == 'Q'){
            break;
            exit(0);
        }
        L.insert(p, choice);
        
        system("cls");
        L.Afficher();
    }
    
    return 0;
}