#include "menu.h"
#include "graf_vector.h"
#include "graf_tab.h"
#include "list_graf.h"
using namespace std;




int main()
{


	graf_tab gt;
	
	void(graf_tab::*graf_tab_func[4])();
	graf_tab_func[0] = &graf_tab::file_cleaner;
	graf_tab_func[1] = &graf_tab::get_data_from_file;
	graf_tab_func[2] = &graf_tab::get_incident_matrix;
	graf_tab_func[3] = &graf_tab::find_all_neighbours;

	graf_vector gv;
	
	void(graf_vector::*vector_tab_func[4])();
	vector_tab_func[0] = &graf_vector::file_cleaner;
	vector_tab_func[1] = &graf_vector::get_data_from_file;
	vector_tab_func[2] = &graf_vector::get_incident_matrix;
	vector_tab_func[3] = &graf_vector::find_all_neighbours;

	neighbours_list nt;

	void(neighbours_list::*list_tab_func[3])();
	list_tab_func[0] = &neighbours_list::get_vertex_tab;
	list_tab_func[1] = &neighbours_list::input_data_from_file;
	list_tab_func[2] = &neighbours_list::output;



	string menu_options_tab[] = { "UTWORZ MACIERZ INCYDENCJI ZA POMOCA TABLICY 2D", "UTWORZ MACIERZ INCYDENCJI ZA POMOCA KONTENERA TABLICY","UTWORZ TABLICE LIST INCYDENCJI - GRAF NIESKIEROWANY", "ESC TO EXIT" };
	int x_as[3] = { 1,0,0 };
	int y_as[3] = { 1,2,3 };

	Menu<graf_tab, void, graf_vector, neighbours_list>m;
	m._menu(x_as, y_as, menu_options_tab, 4, gt, graf_tab_func, 4, gv, vector_tab_func, 4, nt,  list_tab_func,3);
	

}


