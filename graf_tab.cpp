#include "graf_tab.h"

using namespace std;

void graf_tab::get_data_from_file()
{
	ifstream plik1;
	plik1.open("in_skierowany.txt", ios::in);
	if (plik1.good())
	{
		plik1 >> number_of_edges;
		edges_tab = create2Dtable(number_of_edges, 2);
		/*
		pobiera dane z pliku, zapisuje je do dwoch wektorow
		edges_tab[i][0] - poczatek krawedzi
		edges_tab[i][1] - koniec krawedzi
		number_of_vortex - ilosc wierzcholkow
		*/
		number_of_vortex = 0;
		for (int i = 0; i <number_of_edges; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				plik1 >> edges_tab[i][j];
				if (edges_tab[i][j] > number_of_vortex)number_of_vortex = edges_tab[i][j];
			}
		}
	}
	else exit(0);
}

int ** graf_tab::create2Dtable(int rows, int columns)
{
	
		int**tab = nullptr;
		try
		{
			tab = new int*[rows];
		}
		catch (bad_alloc)
		{
			cout << "blad alokacji";
			exit(0);
		}


		for (int i = 0; i < rows; i++)
			try
		{
			tab[i] = new int[columns];
		}
		catch (bad_alloc)
		{
			cout << "blad alokacji";
			exit(0);
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				tab[i][j] = 0;
			}
		}
		return tab;
	
}

void graf_tab::file_cleaner()
{
	fstream plik2;
	plik2.open("incident_matrix_by_tab.txt", ios::out | ios::trunc);
}


void graf_tab::get_incident_matrix()
{
	for (int i = 0; i <number_of_edges; i++)
	{
		for (int j = 1; j <= number_of_vortex; j++)
		{
			new_line = 0; // new_line==0 -> postaw tabulator przy zapisie do pliku
			/*
			ustalanie wartosci macierzy incydntnosci
			edges_tab - macierz krawedzi 
			*/
			if (edges_tab[i][0] == j) input_data = -1;
			else if (edges_tab[i][1] == j) input_data = 1;
			else input_data = 0;

			if (j == number_of_vortex)new_line = 1; // new_line==0 -> przejdz do nowej linii przy zapisie do pliku  
			input_to_file();
		}
	}
}


void graf_tab::input_to_file()
{
	ofstream plik;
	plik.open("incident_matrix_by_tab.txt", ios::out | ios::app);
	if (plik.good())
	{
		if (new_line == -1)
		{
			plik << v_n; //v_n = "vortex`s number i neighbours:"
		}
		else
		{
			plik << input_data;
			if (new_line) plik << endl;
			else plik << " ";
		}

	}
	else exit(0);
}

void graf_tab::find_all_neighbours()
{
	neighbours_tab = create2Dtable(number_of_vortex, number_of_vortex - 1); //tablica sasiadow, liczba column jest rowna liczbi wierzcholkow - 1 bo tyle moze byc max sasaiadow
	
	for (int i = 0; i < number_of_edges; i++) //wpisywanie sasiadow do tablicy 2D
	{
		int j = 0;
		while (neighbours_tab[edges_tab[i][0] - 1][j]) // jesli na pozycji i,j jest juz cos wpisane inkrementuj j (domyslnie neighbours_tab wypelniona jest zerami)
		{
			j++;
		}
		neighbours_tab[edges_tab[i][0] - 1][j] = edges_tab[i][1]; //wpisz sasiada 
	}

	
	for (int i = 0; i <number_of_vortex; i++)
	{
		_itoa_s(i + 1, buffor, 32); //zamienia 'i+1' na typ char
		v_n = "vortex`s number ";
		v_n += buffor;
		v_n += " neighbours: ";
		new_line = -1;
		input_to_file();
		for (int j = 0; j < number_of_vortex-1; j++)
		{
			if (neighbours_tab[i][j]) //jesli na pozycji i,j nie ma zera czyli jest sasiad 
			{
				new_line = 0;	
				input_data = neighbours_tab[i][j];
				if (!neighbours_tab[i][j+1])  new_line = 1; //jesli na kolejnej pozycji jest wpisane zero czyli nie ma juz sasiada to new_line=1 -> oznacza to przejscie w pliku do nowej linii 
				input_to_file();
			}
		}
	}
	position(60, 1);
	cout << "DONE! ";
	system("pause");
}

void graf_tab::position(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}




