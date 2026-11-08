
#include <iostream>
#include <string>
#include "ArrayDyn.h"

using namespace std;

class Etudiant {
public:
    string nom;
    double moyenne;

    Etudiant(string n = "", double m = 0) {
        nom = n;
        moyenne = m;
    }

    void afficher() const {
        cout << nom << " : " << moyenne << endl;
    }
};

int main() {

	cout << " Tableau entiers " << endl;

    ArrayDyn<int> nombres;

    nombres.push_back(10);
    nombres.push_back(20);
    nombres.push_back(30);

    for (auto &e : nombres) {
        cout << e << " ";
    }

    cout << endl;


    cout << "\n Tableau String " << endl;

    ArrayDyn<string> noms;

    noms.push_back("Assiya");
    noms.push_back("Sara");
    noms.push_back("Salma");

    for (auto &e : noms) {
        cout << e << " ";
    }

    cout << endl;



    cout << "\nTableau Etudiant " << endl;

    ArrayDyn<Etudiant> etudiants;

    etudiants.push_back(Etudiant("Ali", 15.5));
    etudiants.push_back(Etudiant("Sara", 17));
    etudiants.push_back(Etudiant("Amine", 13));

    for (auto &e : etudiants) {
        e.afficher();
    }


    cout << "\n faire une copie " << endl;

    ArrayDyn<int> copie = nombres;

    for (auto &e : copie) {
        cout << e << " ";
    }

    cout << endl;


    cout << "\n Suppression " << endl;

    nombres.pop_back();

    for (auto &e : nombres) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}
