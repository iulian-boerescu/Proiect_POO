#pragma once
#include<iostream>
using namespace std;

class Sala
{
private:
	const int cod;
	static int teatru;
	char* denumire;
	int numarLocuri;
	int* locuri;

public:
	Sala() :cod(1)
	{
		this->denumire = new char[1];
		strcpy_s(this->denumire, 1, "");
		this->numarLocuri = 0;
		this->locuri = nullptr;
	}

	Sala(int cod, char* denumire, int numarLocuri, int* locuri) :cod(cod)
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

		if (numarLocuri > 0)
		{
			this->numarLocuri = numarLocuri;
			this->locuri = new int[numarLocuri];
			for (int i = 0; i < numarLocuri; i++)
			{
				this->locuri[i] = locuri[i];
			}
		}
		else
		{
			this->numarLocuri = 0;
			this->locuri = nullptr;
		}
	}

	Sala(const Sala& s) : cod(s.cod)
	{
		if (s.denumire != nullptr)
		{
			int len = strlen(s.denumire) + 1;
			this->denumire = new char[len];
			strcpy_s(this->denumire, len, s.denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy_s(this->denumire, 1, "");
		}

		if (s.numarLocuri > 0 && s.locuri != nullptr)
		{
			this->numarLocuri = s.numarLocuri;
			this->locuri = new int[s.numarLocuri];
			for (int i = 0; i < s.numarLocuri; i++)
			{
				this->locuri[i] = s.locuri[i];
			}
		}
		else
		{
			this->numarLocuri = 0;
			this->locuri = nullptr;
		}
	}

	Sala operator=(Sala s)
	{
		if (locuri != nullptr) {
			delete[] locuri;
		}

		if (denumire != nullptr) {
			delete[] denumire;
		}

		if (s.denumire != nullptr)
		{
			int len = strlen(s.denumire) + 1;
			this->denumire = new char[len];
			strcpy_s(this->denumire, len, s.denumire);
		}
		else
		{
			this->denumire = new char[1];
			strcpy_s(this->denumire, 1, "");
		}

		if (s.numarLocuri > 0 && s.locuri != nullptr)
		{
			this->numarLocuri = s.numarLocuri;
			this->locuri = new int[s.numarLocuri];
			for (int i = 0; i < s.numarLocuri; i++)
			{
				this->locuri[i] = s.locuri[i];
			}
		}
		else
		{
			this->numarLocuri = 0;
			this->locuri = nullptr;
		}

		return *this;
	}

	~Sala()
	{
		if (locuri != nullptr)
		{
			delete[] locuri;
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
		else
		{
			return nullptr;
		}
	}

	int getNumarLocuri()
	{
		return this->numarLocuri;
	}

	int* getLocuri()
	{
		if (this->locuri != nullptr)
		{
			int* copie = new int[this->numarLocuri];
			for (int i = 0; i < this->numarLocuri; i++)
			{
				copie[i] = locuri[i];
			}
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

	void setNumarLocuri(int numarLocuri) 
	{
		if (this->numarLocuri != 0) {
			this->numarLocuri = numarLocuri;

		}
	}

	void setLocuri(const int* locuri)
	{
		if (this->locuri != nullptr && this->numarLocuri != 0)
		{
			if (this->locuri != nullptr)
			{
				delete[] this->locuri;
				this->locuri = nullptr;
			}
			this->locuri = new int[this->numarLocuri];
			for (int i = 0; i < this->numarLocuri; i++)
			{
				this->locuri[i] = locuri[i];
			}
		}
	}

	Sala operator++()
	{
		this->numarLocuri++;
		return *this;
	}

	Sala operator++(int i)
	{
		Sala copy = *this;
		this->numarLocuri++;
		return copy;
	}

	Sala operator+(int numarLocuriAdd)
	{
		if (numarLocuriAdd < 0)
		{
			throw 500;
		}
		else
		{
			Sala copy = *this;
			copy.numarLocuri += numarLocuriAdd;
			return copy;
		}
	}


	static void setSala(int cinema)
	{
		Sala::teatru = teatru;
	}

	friend ostream& operator<<(ostream& out, Sala s) {
		if (s.denumire != nullptr)
		{
			out << "Denumire: " << s.denumire << endl;
		}
		out << "Numar locuri: " << s.numarLocuri << endl;
		out << "Locul: ";
		if (s.locuri != nullptr)
		{
			for (int i = 0; i < s.numarLocuri; i++)
			{
				out << s.locuri[i] << " ";
			}
		}
		return out;
	}
	friend istream& operator>>(istream& in, Sala& s) {
		delete[] s.denumire;
		char buffer[100];
		cout << "Denumire: ";
		in >> ws;
		in.getline(buffer, 99);
		s.denumire = new char[strlen(buffer) + 1];
		strcpy_s(s.denumire, strlen(buffer) + 1, buffer);


		if (s.locuri != nullptr)
		{
			delete[] s.locuri;
		}
		cout << "Numar locuri: ";
		in >> s.numarLocuri;
		if (s.numarLocuri > 0)
		{
			s.locuri = new int[s.numarLocuri];
			for (int i = 0; i < s.numarLocuri; i++)
			{
				cout << "Locul[" << i << "] = ";
				in >> s.locuri[i];
			}
		}
		else
		{
			s.numarLocuri = 0;
			s.locuri = nullptr;
		}
		return in;
	}

};

