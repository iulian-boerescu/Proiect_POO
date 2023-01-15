#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class Bilet
{
private:
	const int cod;
	string denumirePiesa;
	int pret;

public:

	vector<Bilet> bilete;

	Bilet() :cod(1)
	{
		this->denumirePiesa = "";
		this->pret = 0;
	}

	Bilet(int cod, string denumirePiesa, int pret) :cod(cod)
	{
		this->pret = pret;

		if (denumirePiesa != "")
		{
			this->denumirePiesa = denumirePiesa;
		}
		

	}

	Bilet(const Bilet& b) : cod(b.cod)
	{
		this->pret = b.pret;

		this->denumirePiesa = b.denumirePiesa;
	}

	Bilet operator=(Bilet b)
	{

		this->pret = b.pret;

		this->denumirePiesa = b.denumirePiesa;
		return *this;
	}

	~Bilet()
	{
	}


	void cumparBilet() {
		string denumirePiesa;
		int pret;
		int cod;

		cout << "Introduceti numele piesei:" << endl;
		cin >> denumirePiesa;
		cout << "Introduceti pretul:" << endl;
		cin >> pret;
		cout << "Introduceti codul:" << endl;
		cin >> cod;


		Bilet biletCumparat(cod, denumirePiesa, pret);
		bilete.push_back(biletCumparat);
		cout << "Bilet cumparat !" << endl;
	}

	void serialize()
	{
		ofstream f("bilet.txt", ios::binary);
		short dim = this->denumirePiesa.length();
		f.write((char*)&cod, sizeof(cod));
		f.write((char*)&pret, sizeof(pret));
		f.write((char*)&dim, sizeof(dim));
		f.write(denumirePiesa.c_str(), dim + 1);
		f.close();
	}

	void deserialize() {
		ifstream f("bilet.txt", ios::binary);
		short dim = 0;
		f.read((char*)&cod, sizeof(cod));
		f.read((char*)&dim, sizeof(dim));
		char* n = new char[dim + 1];
		f.read(n, dim + 1);
		denumirePiesa = n;
		delete[] n;
		f.read((char*)&dim, sizeof(dim));
		n = new char[dim + 1];
		f.read(n, dim + 1);
		f.read((char*)&pret, sizeof(pret));
		f.close();
	}

	void vizualizeazaBileteDisponibile() {
		if (bilete.size() == 0) {
			cout << "Bilete epuizate." << endl;
			return;
		}
		for (int i = 0; i < bilete.size(); i++) {
			cout << "Biletul " << i + 1 << ":" << endl;
			cout << "Numele piesei: " << bilete[i].denumirePiesa << endl;
			cout << "Pretul: " << bilete[i].pret << endl;
		
		}
	}



	friend ostream& operator<<(ostream& out, Bilet b) {
		out << "Denumire: " << b.denumirePiesa << endl;

		out << b.pret << endl;

		return out;
	}
	friend istream& operator>>(istream& in , Bilet& b) {
		cout << "Denumire Piesa: ";
		in >> b.denumirePiesa;
		cout << "Pret:";
		in >> b.pret;
		return in;
	}

};

