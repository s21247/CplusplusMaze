#include <iostream>
#include <string>

using namespace std;

int* poczatek(char labirynt[][6]);
char przedToba(char labirynt[7][6], char ruch);
char kompas(char ruch, char kierunek);
void kierunek(char kierunek);
void podmien();

int x=0, y=0; // wspolrzedne / xy miejsce w ktorym zaczyna
string wynik = "";

int main()
{
	char labirynt1[7][6];
	char labirynt[7][6] =
	{ {'#','#','#','#','#','#'},
		{'#','.','#','@','#','#'},
		{'#','#','.','.','#','#'},
		{'#','.','.','#','#','#'},
		{'#','#','.','.','#','#'},
		{'#','#','#','.','$','#'},
		{'#','#','#','#','#','#'},
	};
	char labirynt2[7][6] =
	{ {'#','#','#','#','#','#'},
		{'#','.','#','$','#','#'},
		{'#','#','.','.','.','#'},
		{'#','.','.','#','.','#'},
		{'#','#','.','#','#','#'},
		{'#','#','.','.','@','#'},
		{'#','#','#','#','#','#'},
	};
	char labirynt3[7][6] =
	{
		{'#','#','#','#','#','#'},
		{'#','#','$','.','#','#'},
		{'#','.','.','#','.','#'},
		{'#','.','#','.','.','#'},
		{'#','.','.','.','#','#'},
		{'#','#','.','.','@','#'},
		{'#','#','#','#','#','#'},
	};
	int zmienna;
	cout << "Podaj ktory labirynt 1,2 lub 3" << endl;
	cin >> zmienna;
	switch (zmienna)
	{
	case 1:
	{
		for (int x = 0; x < 7; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				labirynt1[x][y] = labirynt[x][y];
				cout << labirynt1[x][y];
			}
			cout << endl;
		}break;
	}
	case 2:
	{
		for (int x = 0; x < 7; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				labirynt1[x][y] = labirynt2[x][y];
				cout << labirynt1[x][y];
			}
			cout << endl;
		}break;
	}
	case 3:
	{
		for (int x = 0; x < 7; x++)
		{
			for (int y = 0; y < 6; y++)
			{
				labirynt1[x][y] = labirynt3[x][y];
				cout << labirynt1[x][y];
			}
			cout << endl;
		}break;
	}	default:
	{
		cout << "Nie ma takiego labiryntu" << endl;
		break;
	}
}
	int* tabXY = poczatek(labirynt1);
	x = tabXY[0];
	y = tabXY[1];

	bool gameend = false;
	char ruch = 'G'; // w ktora strone jest skierowany
	while (gameend != true)
	{
		if (przedToba(labirynt1, kompas(ruch, 'G')) == '.' || przedToba(labirynt1, kompas(ruch, 'G')) == '$' || przedToba(labirynt1, kompas(ruch, 'G')) == '@')
		{
			wynik += kompas(ruch, 'G');
			ruch = kompas(ruch, 'G');
			kierunek(ruch); //idz do przodu
			if (labirynt1[x][y] == '@') { gameend = true; }  // jesli trafimy na malpe, gra sie konczy
		}
		else
		{
			if (przedToba(labirynt1, kompas(ruch, 'P')) == '.' || przedToba(labirynt1, kompas(ruch, 'P')) == '$' || przedToba(labirynt1, kompas(ruch, 'P')) == '@')
			{
				wynik += kompas(ruch, 'P');
				ruch = kompas(ruch, 'P'); //obroc sie w prawo
				kierunek(ruch); //idz do przodu
				if (labirynt1[x][y] == '@') { gameend = true; }  // jesli trafimy na malpe, gra sie konczy
			}
			else
			{
				if (przedToba(labirynt1, kompas(ruch, 'L')) == '.' || przedToba(labirynt1, kompas(ruch, 'L')) == '$' || przedToba(labirynt1, kompas(ruch, 'L')) == '@')
				{
					wynik += kompas(ruch, 'L');
					ruch = kompas(ruch, 'L'); //obroc sie w lewo
					kierunek(ruch); //idz do przodu
					if (labirynt1[x][y] == '@') { gameend = true; }  // jesli trafimy na malpe, gra sie konczy
				}
				else
				{
					if (przedToba(labirynt1, kompas(ruch, 'D')) == '.' || przedToba(labirynt1, kompas(ruch, 'D')) == '$' || przedToba(labirynt1, kompas(ruch, 'D')) == '@')
					{
						wynik += kompas(ruch, 'D');
						ruch = kompas(ruch, 'D'); //obroc sie do tylu
						kierunek(ruch); //idz do przodu
						if (labirynt1[x][y] == '@') { gameend = true; }  // jesli trafimy na malpe, gra sie konczy
					}
				}
			}
		}
	}
	podmien();
	cout << 'S';
	cout << wynik;
	cout << 'K' << endl;
	cout << "Mam nadzieje, ze algorytm sie spodobal" << endl;
	getchar(); getchar();
}
char kompas(char ruch, char kierunek) //zmienia kierunek wzgledny na bezwzgledny
{
	if (ruch == 'G') //gora
	{
		if (kierunek == 'G')
			return 'G';
		else if (kierunek == 'P')
			return 'P';
		else if (kierunek == 'D')
			return 'D';
		else if (kierunek == 'L')
			return 'L';
	}
	else if (ruch == 'P') //prawo
	{
		if (kierunek == 'G')
			return 'P';
		else if (kierunek == 'P')
			return 'D';
		else if (kierunek == 'D')
			return 'L';
		else if (kierunek == 'L')
			return 'G';
	}
	else if (ruch == 'D') //dol
	{
		if (kierunek == 'G')
			return 'D';
		else if (kierunek == 'P')
			return 'L';
		else if (kierunek == 'D')
			return 'G';
		else if (kierunek == 'L')
			return 'P';
	}
	else if (ruch == 'L') //lewo
	{
		if (kierunek == 'G')
			return 'L';
		else if (kierunek == 'P')
			return 'G';
		else if (kierunek == 'D')
			return 'P';
		else if (kierunek == 'L')
			return 'D';
	}
}
void kierunek(char kierunek) //porusza sie po x i y
{
	if (kierunek == 'G')
	{
		x++; // gora i dol
	}
	else if (kierunek == 'P')
	{
		y++; // prawo i lewo
	}
	else if (kierunek == 'D')
	{
		x--;
	}
	else if (kierunek == 'L')
	{
		y--;
	}
}
int* poczatek(char labirynt[][6])
{
	int wynik[2];
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			if (labirynt[x][y] == '$')
			{
				wynik[0] = x;
				wynik[1] = y;
			}
		}
	}

	return wynik;
}
char przedToba(char labirynt[7][6], char ruch)
{
	char jakiZnak;
	if (ruch == 'G')
	{
		jakiZnak = labirynt[x + 1][y];
	}
	else if (ruch == 'P')
	{
		jakiZnak = labirynt[x][y + 1];
	}
	else if (ruch == 'D')
	{
		jakiZnak = labirynt[x - 1][y];
	}
	else if (ruch == 'L')
	{
		jakiZnak = labirynt[x][y - 1];
	}
	return jakiZnak;
}
void podmien()
{
	string wynik2 = ""; // problem gora dol
	for (int x = 0; x < wynik.length(); x++)
	{
		if (wynik.at(x) == 'G') //at sprawdza literke na okreslonej pozycji 
			wynik2 += 'D';
		else if (wynik.at(x) == 'D')
			wynik2 += 'G';
		else
			wynik2 += wynik.at(x);
	}
	wynik = wynik2;
}
