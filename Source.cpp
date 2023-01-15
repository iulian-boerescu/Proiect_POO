#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "Bilet.cpp"
#include "Piesa.cpp"
#include "Sala.cpp"
#include "Teatru.cpp"
using namespace std;


int afiseazaMeniu() {
        int choice;
        cout << "1. Vizualizaza bilete" << endl;
        cout << "2. Cumpara" << endl;
        cout << "3. Iesire" << endl;
        cin >> choice;
        return choice;
    }
int main() {
    vector<Bilet> bilete;
    Bilet bilet;
    bilet.deserialize();
    int optiune;
    do {
        afiseazaMeniu();
        cin >> optiune;
        switch (optiune) {
        case 1:
            bilet.cumparBilet();
            break;
        case 2:
            bilet.vizualizeazaBileteDisponibile();
            break;
        case 3:
            bilet.serialize();
            break;
        case 4:
            break;
        default:
            cout << "Invalid" << endl;
            break;
        }
    } while (optiune != 4);
}