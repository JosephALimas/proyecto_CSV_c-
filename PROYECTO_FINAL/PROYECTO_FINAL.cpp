#include "header.h"
int main() {
	//declaramos las estructuras de datos que vamos a utilizar
	//para almacenar los datos de los csv
	vector<Book> books; //declaramos el vector para almacenar los libros
	vector<Rating> ratin_1; //declaramos los vectores para almacenar los ratings
	vector<Rating> ratin_2;
	vector<Rating> ratin_3;
	vector<Rating> ratin_4;
	vector<Rating> ratin_5;
	map<int, vector<std::string>> mapa; //declaramos el mapa

	readingBOOKCSV(books);//leemos los datos del csv books y creamos los objetos en el vector
	//leemos los datos del archivo ratings csv y sus 5 chunks
	ratin_1 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\chunk_1.csv");
	ratin_2 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\chunk_2.csv");
	ratin_3 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\chunk_3.csv");
	ratin_4 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\chunk_4.csv");
	ratin_5 = Rating::readRatingsCSV("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\chunk_5.csv");

	// Crear el mapa con el user_id como clave y un vector de títulos como valor
	map<int, vector<string>> userTitleMap;

	// Llenar el mapa utilizando los vectores de ratings
	fillUserTitleMap(ratin_1, userTitleMap);
	fillUserTitleMap(ratin_2, userTitleMap);
	fillUserTitleMap(ratin_3, userTitleMap);
	fillUserTitleMap(ratin_4, userTitleMap);
	fillUserTitleMap(ratin_5, userTitleMap);

	// Resto del código

	return 0;
}