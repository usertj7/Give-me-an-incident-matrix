#ifndef LIST_GRAF_H
#define LIST_GRAF_H
#include <fstream>
#include <vector>
#include <iostream>
#include <windows.h>
using namespace std;

class neighbours_list {
	friend class neighbour;
public:
	neighbours_list();
	/*
	funkcja tworzaca wektor wskaznikow do poczatkow list incydencji
	*/
	void get_vertex_tab();
	/*
	pobiera dane z pliku i uzupelnia nimi listy incydencji dla danych wierzcholkow
	*/
	void input_data_from_file();
	/*
	funkcja dodajaca kolejnych sasiadow do listy incydencji 
	*/
	void push_next_neighbour(int vertex, int value);
	/*
	funkcja wpisuje dane do pliku 
	*/
	void output();

	void position(const int x, const int y);

private:
	int a, b, number_of_edges;
	vector <neighbour*> incident_list;
	neighbour*first;  //wskaznik na pierwszy element listy
	int value;
};

class neighbour {
	friend class neighbours_list;
private:
	int weight;
	int val;
	neighbour* next; //wskaznik na nastepny element listy
	neighbour();
public:
	
};

#endif

