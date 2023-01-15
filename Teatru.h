#pragma once

#include <iostream>
using namespace std;

class Teatru
{
private:
	const int cod;
	static int teatru;
	char* denumire;
	int numarSali;
	int* sali;

public:
	Teatru() :cod(1)
	{
		this->denumire = new char[1];
		strcpy(this->denumire, "");
		this->numarSali = 0;
		this->sali = nullptr;
	}

	Teatru(int cod, char* denumire, int numarSali, int* sali) :cod(cod)
	{
		if (denumire != nullptr)
		{
			int len = strlen(denumire) + 1;
			this->denumire = new char[len];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy(this->denumire, "");
		}

		if (numarSali > 0)
		{
			this->numarSali = numarSali;
			this->sali = new int[numarSali];
			for (int i = 0; i < numarSali; i++)
			{
				this->sali[i] = sali[i];
			}
		}
		else
		{
			this->numarSali = 0;
			this->sali = nullptr;
		}
	}

	Teatru(const Teatru& c) : cod(c.cod)
	{
		if (c.denumire != nullptr)
		{
			int len = strlen(c.denumire) + 1;
			this->denumire = new char[len];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy(this->denumire, "");
		}

		if (c.numarSali > 0 && c.sali != nullptr)
		{
			this->numarSali = c.numarSali;
			this->sali = new int[c.numarSali];
			for (int i = 0; i < c.numarSali; i++)
			{
				this->sali[i] = c.sali[i];
			}
		}
		else
		{
			this->numarSali = 0;
			this->sali = nullptr;
		}
	}

	Teatru operator=(Teatru c)
	{
		if (sali != nullptr) {
			delete[] sali;
		}

		if (denumire != nullptr) {
			delete[] denumire;
		}

		if (c.denumire != nullptr)
		{
			int len = strlen(c.denumire) + 1;
			this->denumire = new char[len];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy(this->denumire, "");
		}

		if (c.numarSali > 0 && c.sali != nullptr)
		{
			this->numarSali = c.numarSali;
			this->sali = new int[c.numarSali];
			for (int i = 0; i < c.numarSali; i++)
			{
				this->sali[i] = c.sali[i];
			}
		}
		else
		{
			this->numarSali = 0;
			this->sali = nullptr;
		}

		return *this;
	}

	~Teatru()
	{
		if (sali != nullptr)
		{
			delete[] sali;
		}
		delete[] denumire;
	}


	int getCod()
	{
		return this->cod;
	}

	int getTeatru()
	{
		return this->teatru;
	}


	char* getDenumire()
	{
		if (this->denumire != nullptr)
		{
			char* copie = new char[strlen(this->denumire) + 1];
			strcpy(copie, this->denumire);
			return copie;
		}
	}

	int getNumarSali()
	{
		return this->numarSali;
	}

	int* getSali()
	{
		if (this->sali != nullptr)
		{
			int* copie = new int[this->numarSali];
			for (int i = 0; i < this->numarSali; i++)
			{
				copie[i] = sali[i];
			}
			return copie;
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

	void setNumarSali(int numarSali)
	{
		if (this->numarSali != 0) {
			this->numarSali = numarSali;

		}
	}

	void setLocuri(const int* sali)
	{
		if (this->sali != nullptr && this->numarSali != 0)
		{
			if (this->sali != nullptr)
			{
				delete[] this->sali;
				this->sali = nullptr;
			}
			this->sali = new int[this->numarSali];
			for (int i = 0; i < this->numarSali; i++)
			{
				this->sali[i] = sali[i];
			}
		}
	}

	bool operator>(int numarSaliComparare)
	{
		Teatru copy = *this;
		return (copy.numarSali > numarSaliComparare);
	}

	int& operator[](int pozitie) throw (exception)
	{
		if (pozitie >= 0 && pozitie < numarSali && sali != nullptr)
		{
			return sali[pozitie];
		}
		else
		{
			throw exception("Pozitie invalida!");
		}
	}

	explicit operator int()
	{
		return numarSali;
	}

	static void setTeatru(int teatru)
	{
		Teatru::teatru = teatru;
	}

	friend ostream& operator<<(ostream& out, Teatru t) {
		if (t.denumire != nullptr)
		{
			out << "Denumire: " << t.denumire << endl;
		}
		out << "Numar sali: " << t.numarSali << endl;
		out << "sali: ";
		if (t.sali != nullptr)
		{
			for (int i = 0; i < t.numarSali; i++)
			{
				out << t.sali[i] << " ";
			}
		}
		return out;
	}
	friend istream& operator>>(istream& in, Teatru& t) {
		delete[] t.denumire;
		char buffer[100];
		cout << "Denumire Teatru: ";
		in >> ws;
		in.getline(buffer, 99);
		t.denumire = new char[strlen(buffer) + 1];
		strcpy_s(t.denumire, strlen(buffer) + 1, buffer);


		if (t.sali != nullptr)
		{
			delete[] t.sali;
		}
		cout << "Numar sali: ";
		in >> t.numarSali;
		if (t.numarSali > 0)
		{
			t.sali = new int[t.numarSali];
			for (int i = 0; i < t.numarSali; i++)
			{
				cout << "Filmul[" << i << "] = ";
				in >> t.sali[i];
			}
		}
		else
		{
			t.numarSali = 0;
			t.sali = nullptr;
		}
		return in;
	}

};




