#include "list_graf.h"

void neighbours_list::input_data_from_file()
{
	fstream plik;
	plik.open("in_nieskierowany.txt", ios::in);
	if (plik.good())
	{
		plik >> number_of_edges;
		for (int i = 0; i < number_of_edges; i++)
		{
			plik >> a;
			plik >> b;
			push_next_neighbour(a, b);
			push_next_neighbour(b, a);
		}
	}
	else exit(0);
}

void neighbours_list::push_next_neighbour(int vertex, int value)
{
	neighbour *new_val_1 = new neighbour;
	new_val_1->val = value;
	neighbour *temp_1 = new neighbour;
	temp_1 = incident_list[vertex - 1];
	while (temp_1->next)  //szukaj dopoki nie znajdziesz ostatniego
	{
		temp_1 = temp_1->next;
	}
	temp_1->next = new_val_1;
	new_val_1->next = 0;
}

void neighbours_list::output()
{
	ofstream plik;
	plik.open("tab_incident_lists.txt", ios::out | ios::trunc);
	if (plik.good())
	{
		for (int i = 0; i < 5; i++)
		{
			plik << "vertex`s number " << i + 1 << " neighbours: ";
			neighbour* new_temp = new neighbour;
			new_temp = incident_list[i]->next;
			int weight = 0;
			while (new_temp)
			{
				weight++;
				plik << new_temp->val << " ";
				new_temp = new_temp->next;

			}
			plik << "weight: " << weight;
			plik << endl;
		}
	}
	else exit(0);

	position(60, 5);
	cout << "DONE! ";
	system("pause");
}

void neighbours_list::position(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

neighbour::neighbour()
{
	next = 0;
}

neighbours_list::neighbours_list()
{
	first = 0;
}
void neighbours_list::get_vertex_tab()
{
	
	for (int i = 0; i < 5; i++)
	{
		neighbour *vertex = new neighbour;
		vertex->val = i + 1;
		first = vertex;
		incident_list.push_back(first);
	}
}
