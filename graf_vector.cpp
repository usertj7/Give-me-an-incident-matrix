#include "graf_vector.h"

using namespace std;

void graf_vector::get_data_from_file()
{
	ifstream plik1;
	plik1.open("in_skierowany.txt", ios::in);
	if (plik1.good())
	{
		plik1 >> number_of_edges;
		/*
		pobiera dane z pliku, zapisuje je do dwoch wektorow
		vortex_1 - poczatek krawedzi
		vortex_2 - koniec krawedzi
		number_of_vortex - ilosc wierzcholkow
		*/
		number_of_vortex = 0;
		for (int i = 0; i <number_of_edges; i++)
		{
			plik1 >> a;
			plik1 >> b;
			if (a > number_of_vortex)number_of_vortex = a;
			else if (b > number_of_vortex) number_of_vortex = b;
			vortex_1.push_back(a);
			vortex_2.push_back(b);
		}
		
	}
	else exit(0);
}

void graf_vector::file_cleaner()
{
	fstream plik2;
	plik2.open("incident_matrix_by_vector.txt", ios::out | ios::trunc);
}

void graf_vector::get_incident_matrix()
{
	for (int i = 0; i <number_of_edges; i++)
	{
		for (int j = 1; j <= number_of_vortex; j++)
		{
			new_line = 0; // new_line==0 -> postaw tabulator przy zapisie do pliku 
			/*
			ustalanie wartosci macierzy incydntnosci
			*/
			if (vortex_1[i] == j) input_data = -1;
			else if (vortex_2[i] == j) input_data = 1;
			else input_data = 0;

			if(j== number_of_vortex)new_line = 1; // new_line==0 -> przejdz do nowej linii przy zapisie do pliku  
			input_to_file();
		}
	}
}

void graf_vector::input_to_file()
{
	ofstream plik;
	plik.open("incident_matrix_by_vector.txt", ios::out | ios::app);
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

void graf_vector::find_all_neighbours()
{
	for (int i = 0; i < number_of_vortex; i++) //tworzenie wektora 2D
	{
		neighbours.push_back(vortexs);
	}

	for (int i = 0; i < number_of_edges; i++) //wpisywanie sasiadow do wektora 2D
	{
		neighbours[vortex_1[i] - 1].push_back(vortex_2[i]);
	}

	for (int i = 0; i < number_of_vortex; i++)
	{
		_itoa_s(i + 1, buffor, 32); //zamienia 'i+1' na typ char
		v_n = "vortex`s number ";
		v_n += buffor;
		v_n += " neighbours: "; 
		new_line = -1;
		input_to_file();
		int q = 0;
		for (int j = 0; j < neighbours[i].size(); j++)
		{
			
			input_data = neighbours[i][j];
			new_line = 0;
			if (j == neighbours[i].size() - 1) new_line = 1;
			input_to_file();
		}
		
	}
	position(60, 3);
	cout << "DONE! ";
	system("pause");
}

void graf_vector::position(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


