#include "header.h"

void readingBOOKCSV(std::vector<Book>& books) {

	ifstream books_file("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programación_avanzada\\PROYECTO_FINAL\\books.csv", ios::in);
	// leemos el archivo

	if (!books_file) { //control por si no abre el archivo
		cerr << "El archivo de Books.csv no pudo ser accesado correctamente, favor de intentar de nuevo" << endl;
		exit(EXIT_FAILURE);
	}

	string linea;
	getline(books_file, linea);  //leemos la primera linea del csv
	while (getline(books_file, linea, ',')) {
		int temp_book_id;
		temp_book_id = stoi(linea);
		//
		getline(books_file, linea, ',');
		long temp_goodreads_d;
		if (linea == "\0") {
			temp_goodreads_d = 0;
		}
		else {
			temp_goodreads_d = stol(linea);
		}
		getline(books_file, linea, ',');

		long temp_best_book_id;
		if (linea == "\0") {
			temp_best_book_id = 0;
		}
		else {
			temp_best_book_id = stol(linea);
		}
		getline(books_file, linea, ',');

		long temp_work_id;
		if (linea == "\0") {
			temp_work_id = 0;
		}
		else {
			temp_work_id = stol(linea);
		}
		getline(books_file, linea, ',');

		int temp_books_count;
		if (linea == "\0") {
			temp_books_count = 0;
		}
		else {
			temp_books_count = stoi(linea);
		}
		getline(books_file, linea, ',');
		double temp_isbn;

		if (linea == "\0") {
			temp_isbn = 0;
		}
		else {
			temp_isbn = stod(linea);
		}

		getline(books_file, linea, ',');
		double temp_isbn13;
		if (linea == "\0") {
			temp_isbn13 = 0;
		}
		else {
			temp_isbn13 = stod(linea);
		}

		getline(books_file, linea, ',');
		//
		if (!linea.empty() && linea.front() == '"' && linea.back() != '"') {
			std::string temp;
			temp += linea;
			while (getline(books_file, linea, ',')) {
				temp += linea;
				if (!linea.empty() && linea.back() == '"') {
					break;
				}
				else {
					temp += ',';
				}
			}
			linea = temp;
		}

		std::string temp_authors;
		temp_authors = linea;
		getline(books_file, linea, ',');

		int temp_publication_year;
		if (linea == "\0") {
			temp_publication_year = 0;
		}
		else {
			temp_publication_year = stoi(linea);
		}
		getline(books_file, linea, ',');

		std::string temp_original_title;
		temp_original_title = linea;
		getline(books_file, linea);

		std::string temp_title;
		temp_title = linea;

		Book tempBook(temp_book_id, temp_goodreads_d, temp_best_book_id,
			temp_work_id, temp_books_count, temp_isbn, temp_isbn13,
			temp_authors, temp_publication_year, temp_original_title,
			temp_title);
		books.push_back(tempBook);

	}

	std::cout << "El archivo Libros.csv fue leido correctamente" << endl;
}

// Definición de la función para llenar el mapa de títulos para cada usuario
void fillUserTitleMap(const vector<Rating>& ratings, map<int, vector<string>>& userTitleMap) {
	for (const auto& rating : ratings) {
		// Obtener el user_id y el título del rating actual
		int userId = rating.getUserId();
		string bookTitle = rating.getTitle();

		// Verificar si el user_id ya está en el mapa
		if (userTitleMap.find(userId) == userTitleMap.end()) {
			// Si no está en el mapa, agregar una nueva entrada con el user_id y un vector que contiene el título
			userTitleMap[userId] = { bookTitle };
		}
		else {
			// Si ya está en el mapa, agregar el título al vector existente
			userTitleMap[userId].push_back(bookTitle);
		}
	}
}
