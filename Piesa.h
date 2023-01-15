#pragma once
#include<iostream>
using namespace std;


class Piesa
{
private:
	const int cod;
	char* denumire;
	string gen;

public:
	Piesa() :cod(1)
	{
		this->denumire = new char[1];
		strcpy(this->denumire, "");
		this->gen = "";
	}

	Piesa(int cod, char* denumire, string gen) :cod(cod)
	{
		if (denumire != nullptr)
		{
			int len = strlen(denumire) + 1;
			this->denumire = new char[len];
			strcpy_s(this->denumire, len, denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy_s(this->denumire, 1, "");
		}

		this->gen = gen;
	}

	int getCod()
	{
		return this->cod;
	}

	string getGen()
	{
		return this->gen;
	}


	char* getDenumire()
	{
		if (this->denumire != nullptr)
		{
			char* copie = new char[strlen(this->denumire) + 1];
			strcpy(copie, this->denumire);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}


	void setDenumire(const char* denumire)
	{
		if (denumire != nullptr && strlen(denumire) != 0)
		{
			if (this->denumire != nullptr)
			{
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			cout << "Denumire necunoscuta!" << endl;
		}
	}

	void setGen(string gen) {
		if (this->gen != "") {
			this->gen = gen;

		}
	}

	Piesa(const Piesa& p) : cod(p.cod)
	{
		if (p.denumire != nullptr)
		{
			int len = strlen(p.denumire) + 1;
			this->denumire = new char[len];
			strcpy_s(this->denumire, len, p.denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy_s(this->denumire, 1, "");
		}

		this->denumire = p.denumire;
	}

	Piesa operator=(Piesa p)
	{
		if (denumire != nullptr) {
			delete[] denumire;
		}

		if (p.denumire != nullptr)
		{
			int len = strlen(p.denumire) + 1;
			this->denumire = new char[len];
			strcpy_s(this->denumire, len, p.denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy_s(this->denumire, 1, "");
		}

		this->gen = p.denumire;

		return *this;
	}

	~Piesa()
	{
		delete[] denumire;
	}


	bool operator==(char* denumire)
	{
		Piesa copy = *this;
		return (copy.denumire == denumire);
	}

	static void afisareMesaj()
	{
		cout << "Bine ati venit la spectacol!" << endl;
	}


	bool operator!()
	{
		return gen != "";
	}


	void verificareCod(int cod)
	{
		if (this->cod == cod)
		{
			cout << "Piesa corecta!" << endl;
		}
		else
		{
			cout << "Piesa incorecta!" << endl;
		}
	}

	void determinareGen()
	{
		
		if (this->gen == "Comedie")
			{
				cout << "Specatcolul este o comedie!" << endl;
			}
		else if (this->gen == "Drama")
			{
				cout << "Specatcolul este o drama!" << endl;
			}
		else if (this->gen == "Musical")
			{
				cout << "Specatcolul este un musical!" << endl;
			}
		else if (this->gen == "Romance")
			{
				cout << "Spectacolul este unul de tip romance" << endl;
			}
		else
			{
				cout << "Gen necunoscuyt" << endl;
			}	
		
	}

	virtual void afiseazaGen() {
		cout << "Genul piesei " << denumire << " este:" << gen << endl;
	}


	friend ostream& operator<<(ostream& out, Piesa p) {
		if (p.denumire != nullptr)
		{
			out << "Denumire: " << p.denumire << endl;
		}
		out << "Gen: " << p.gen << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Piesa& p) {
		delete[] p.denumire;
		char buffer[100];
		cout << "Denumire: ";
		in >> ws;
		in.getline(buffer, 99);
		p.denumire = new char[strlen(buffer) + 1];
		strcpy_s(p.denumire, strlen(buffer) + 1, buffer);


		cout << "Numar categorii de varsta: ";
		in >> p.gen;
		return in;
	}

};


