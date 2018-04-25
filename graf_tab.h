#ifndef GRAF_TAB_H
#define GRAF_TAB_H
#include<iostream>
#include<string>
#include<fstream>
#include <stack>
#include <windows.h>


using namespace std;

class graf_tab {
private:
	int **edges_tab = nullptr;
	int **idcident_tab = nullptr;
	int **neighbours_tab = nullptr;

	string v_n;
	char buffor[32];
	int a, b, number_of_edges, number_of_vortex, input_data, new_line;
public:
	/*
	funkcja lokujaca pamiec na tablice 2d 
	*/
	int** create2Dtable(int columns, int rows);
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