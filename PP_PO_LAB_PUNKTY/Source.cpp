#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <time.h>

using namespace std;

void menu(); void sort();

struct punkty {
	string name;
	int X;
	int Y;
	int Z;
};

class Punkt_1D
{
protected:
	string nazwa;
	int x;
public:
	Punkt_1D(string nazwaa, int xx)
	{
		nazwa = nazwaa;
		x = xx;
	};

	Punkt_1D()
	{
		srand(time(NULL));
		nazwa = rand() % 100;
		x = rand() % 100;
	}
	
	void zapisz()
	{
		fstream plik;
		plik.open("Punkty.txt", ios::out | ios::app);
		plik << nazwa << endl;
		plik << x << endl;
		plik.close();
	}
};

class Punkt_2D : public Punkt_1D
{
protected:
	int y;
	
public:
	Punkt_2D(string nazwaa, int xx, int yy)
	{
		nazwa = nazwaa;
		x = xx;
		y = yy;
	};

	Punkt_2D()
	{
		srand(time(NULL));
		nazwa = rand() % 100;
		x = rand() % 100;
		y = rand() % 100;
	}

	void zapisz()
	{
		fstream plik;
		plik.open("Punkty.txt", ios::out | ios::app);
		plik << nazwa << endl;
		plik << x << ',' << y << endl;
		plik.close();
	}

};

class Punkt_3D : public Punkt_2D
{
protected:
	int z;
	
public:
	Punkt_3D(string nazwaa, int xx, int yy, int zz)
	{
		nazwa = nazwaa;
		x = xx;
		y = yy;
		z = zz;
	};

	Punkt_3D()
	{
		srand(time(NULL));
		nazwa = rand() % 100;
		x = rand() % 100;
		y = rand() % 100;
		z = rand() % 100;
	}

	void zapisz()
	{
		fstream plik;
		plik.open("Punkty.txt", ios::out | ios::app);
		plik << nazwa << endl;
		plik << x << ',' << y << ',' << z << endl;
		plik.close();
	}

};

int main()
{
	system("cls");
	menu();
	return 0;
}

void wczytaj()
{
	fstream plik;
	string nazwa;
	int x;
	plik.open("Punkty.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie ma takiego pliku" << endl;
		exit(0);
	}
	string linia;
	int nr_li = 1;
	while (getline(plik, linia))
	{
		switch (nr_li)
		{
		case 1: nazwa = linia;
			cout << nazwa << endl;
			break;
		case 2: x = atoi(linia.c_str());
			cout << x << endl;
			break;
		}
		
	}
	plik.close();
	cout << endl;
	system("pause");
}

void sort() {
	/*
	ifstream ifs("Punkty.txt");

	while (ifs.good()) {
		struct foo;
		ifs >> foo.name >> foo.a >> foo.b >> foo.c;
	}

	ifs.close();
	*/
	fstream plik;
	string nazwa;
	int x;
	plik.open("Punkty.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie ma takiego pliku" << endl;
		exit(0);
	}
	string linia;
	int nr_li = 1;
	while (getline(plik, linia))
	{
		punkty nazwa;
		switch (nr_li)
		{
		case 1:
		{
			
			nazwa.name = linia;
			cout << nazwa.name << endl;
			nr_li++;
		}
			break;
		case 2:
		{
			string XYZ = linia;
			vector<int> VEC;

			stringstream ss(XYZ);

			int I;
			int ILE = 0;
			while (ss >> I)
			{
				ILE++;
				VEC.push_back(I);

				if (ss.peek() == ',')
					ss.ignore();
			}

			if (ILE == 1) {
				nazwa.X = VEC[0];
				nazwa.Y = 0;
				nazwa.Z = 0;
			}
			if (ILE == 2) {
				nazwa.X = VEC[0];
				nazwa.Y = VEC[1];
				nazwa.Z = 0;
			}
			if (ILE == 3) {
				nazwa.X = VEC[0];
				nazwa.Y = VEC[1];
				nazwa.Z = VEC[2];
			}
		}
			//x = atoi(linia.c_str());
			//cout << x << endl;
			break;
		}
	}
	cout << pkt3d.x << pkt3d.y;
	plik.close();
	cout << endl;
	system("pause");
}

void menu() {
	int menu;
	cout << "++++++++++++++	 MENU	++++++++++++++" << endl;
	cout << "1. Wyswietl punkty z pliku txt" << endl;
	cout << "2. Wyswietl posortowane z pliku txt " << endl;
	cout << "3. Wprowadz punkt" << endl;
	cout << "9. Wyjdz z programu" << endl;
	cout << "5. Usun wybrany punkt [WIP]" << endl;
	cout << "6. Wyczysc liste punktow [WIP]" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Opcja: ";
	cin >> menu;
	system("cls");
	switch (menu)
	{
	case 1:
		wczytaj();
		main();
		break;
	case 2:
		sort();
		main();
		break;
	case 3:
	{
		cout << "Wprowadz pkt wg. wzoru: \"NAZWA X,Y,Z\"" << endl;
		int x = 0, y = 0, z = 0;
		string nazwa;

		string input_xyz;
		vector<int> vec;

		getline(cin, nazwa, ' ');

		getline(cin, input_xyz);
		stringstream ss(input_xyz);

		int i;
		int ile = 0;
		while (ss >> i)
		{
			ile++;
			vec.push_back(i);

			if (ss.peek() == ',')
				ss.ignore();
		}
		cout << endl;

		switch (ile)
		{
		case 1:
		{
			x = vec[0];
			Punkt_1D p1(nazwa, x);
			p1.zapisz();
			main();
		}
		break;
		case 2:
		{
			x = vec[0];
			y = vec[1];
			Punkt_2D p2(nazwa, x, y);
			p2.zapisz();
			main();
		}
		break;
		case 3:
		{
			x = vec[0];
			y = vec[1];
			z = vec[2];
			Punkt_3D p3(nazwa, x, y, z);
			p3.zapisz();
			main();
		}
		break;
		default:
		{
			cout << "Blad!" << endl;
			cout << "Za duzo wspolrzednych!";
			Sleep(2000);
			main();
		}
		break;
		}
	}
		break;
	case 9:
	{
		exit(0);
	}
		break;
	case 6:
	{
	
	}
		break;
	case 5:
	{

	}
		break;
	default:
		break;
	}
}