#include "header.h"
int main() {
	cout << "leyendo archivos..." << endl;
	vector<Book> books; //declaramos el vector donde vamos a almacenar los objetos de tipo book
	//declaramos los cinco vectores en donde vamos a almacener los objetos de tipo rating
	vector<Rating> ratin_1;
	vector<Rating> ratin_2;
	vector<Rating> ratin_3;
	vector<Rating> ratin_4;
	vector<Rating> ratin_5;
	//utilizamos la funcion para rellenar el vector de libros leyendo el archivo csv
	readingBOOKCSV(books);
	cout << "[==________]25%" << endl;

	//utilizamos la funcion para rellenar cada uno de los cinco vectores con los objetos de tipo rating leyendo los cinco chunks de archivo csv
	ratin_1 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\chunk_1.csv", books);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[===_______]35%" << endl;
	ratin_2 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\chunk_2.csv", books);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[====______]45%" << endl;
	ratin_3 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\chunk_3.csv", books);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[=====_____]55%" << endl;
	ratin_4 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\chunk_4.csv", books);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[======____]65%" << endl;
	ratin_5 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\chunk_5.csv", books);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[=======___]75%" << endl;
	// Crear el mapa con el user_id como clave y un vector de títulos como valor
	map<int, vector<string>> userTitleMap;
	// Llenar el mapa utilizando los vectores de ratings
	read5RatinCsv(ratin_1, ratin_2, ratin_3, ratin_4, ratin_5, userTitleMap);
	
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[========__]80%" << endl;
	fillUserTitleMap(ratin_2, userTitleMap);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[=======-__]85%" << endl;
	fillUserTitleMap(ratin_3, userTitleMap);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[=========_]90%" << endl;
	fillUserTitleMap(ratin_4, userTitleMap);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[========-_]95%" << endl;
	fillUserTitleMap(ratin_5, userTitleMap);
	limpiarConsola();
	cout << "leyendo archivos..." << endl;
	cout << "[=========]100%" << endl;
	//confirmacion de lectura correcta
	cout << "Los datos fueron cargados correctamente" << endl;

	//declaramos una variable de control
	bool control_flag = true;
	int opcion;
	while (control_flag) {
		printMenu();
		opcion = 0;
		cin >> opcion;
		int user_id = 0;
		switch (opcion) {
		case 1:
			busquedaPorTitulo(books);
			limpiarConsola();
			break;
		case 2:
			busquedaPorAno(books);
			limpiarConsola();
			break;
		case 3:
			busquedaPorIsbn(books);
			limpiarConsola();
			break;
		case 4:
			showPromedio(ratin_1, ratin_2, ratin_3, ratin_4, ratin_5, books);
			limpiarConsola();
			break;
		case 5:
			int userId;
			cout << "Ingrese el ID del usuario: ";
			cin >> userId;

			buscarUsuarioPorId(userTitleMap, userId);
			limpiarConsola();
			break;
		case 6:
			usuarioConMasRatings(userTitleMap);
			limpiarConsola();
			break;
		case 7:
			crearNuevoCsv(ratin_1, books);
			limpiarConsola();
			break;

		case 8:
			control_flag = false;
			limpiarConsola();
			break;
		}
	}
	return 0;
}