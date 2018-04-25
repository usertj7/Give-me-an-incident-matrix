#ifndef GRAF_VECTOR_H
#define GRAF_VECTOR_H
#include<iostream>
#include<string>
#include<fstream>
#include <stack>
#include <windows.h>
#include <vector>
#include <windows.h>

using namespace std;

class graf_vector {
private:
	vector<int>vortex_1;
	vector<int>vortex_2;
	vector< vector <int> > neighbours;
	vector<int>vortexs;
	string v_n;
	char buffor[32];
	int a, b, number_of_edges, number_of_vortex, input_data, new_line;
public:
	/*
	funkcja czyszczaca plik
	*/
	void file_cleaner();
	/*
	funkcja wyznaczajaca macierz incydentna
	*/
	void get_incident_matrix();
	/*
	funkcja pobierajaca dane z pliku  
	*/
	void get_data_from_file();
	/*
	funkcja wpisujaca dane do pliku
	*/
	void input_to_file();
	/*
	funkcja znajdujaca sasiadow danego kazdego wierzcholka 
	*/
	void find_all_neighbours();

	void position(const int x, const int y);
};

#endif