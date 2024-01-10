#include "header.h"
Book::Book() { //constructor con todos los datos vacios
	book_id = 0;
	goodreads_d = 0;
	best_book_id = 0;
	work_id = 0;
	books_count = 0;
	isbn = 0;
	isbn13 = 0;
	publication_year = 0;
}
Book::Book(int id, long goodread, long best_book, long work_id, int book_count,
	double isbn, double isbn13, std::string authors, int pub_year, std::string org_title,
	std::string title) { //constructor en donde pasamos todos lso argumentos
	this->book_id = id;
	this->goodreads_d = goodread;
	this->best_book_id = best_book;
	this->work_id = work_id;
	this->books_count = book_count;
	this->isbn = isbn;
	this->isbn13 = isbn13;
	this->publication_year = pub_year;
	this->authors = authors;
	this->original_title = org_title;
	this->title = title;
}
//definicion de los setters
void Book::setBookID(int book_id) {
	this->book_id = book_id;
}
void Book::setGoodReadsId(long goodreads_id) {
	this->goodreads_d = goodreads_id;
}
void Book::setbestBookId(long best_book_id) {
	this->best_book_id = best_book_id;
}
void Book::setWorkId(long work_id) {
	this->work_id = work_id;
}
void Book::setBookCount(int book_count) {
	this->books_count = book_count;
}
void Book::setIsbn(double isbn) {
	this->isbn = isbn;
}
void Book::setIsbn13(double isbn13) {
	this->isbn13 = isbn13;
}
void Book::setAuthor(std::string& authorString) {
	this->authors = authorString;
}
void Book::setPublicationYear(int publication_year) {
	this->publication_year = publication_year;
}
void Book::setOriginalTitle(std::string& or_title_string) {
	this->original_title = or_title_string;
}
void Book::setTitle(std::string& title_string) {
	this->title = title_string;
}
void Book::incrementSearchCount() {
	searchCount++;
}
//definicion de los getters
int Book::getBookId() {
	return book_id;
}
long Book::getGoodReadsId() {
	return goodreads_d;
}
long Book::getBestBookId() {
	return best_book_id;
}
long Book::getWorkId() {
	return work_id;
}
int Book::getBookCount() {
	return books_count;
}
double Book::getIsbn() {
	return isbn;
}
double Book::getIsbn13() {
	return isbn13;
}
int Book::getPublicationYear() {
	return publication_year;
}
string Book::getAuthor() {
	return authors;
}
string Book::getOriginalTitle() {
	return original_title;
}
string Book::getTitle() {
	return title;
}
int Book::getSearchCount() const {
	return searchCount;
}
//definicion de la funcion para leer el archivo csv books
void readingBOOKCSV(std::vector<Book>& books) { //la funcion toma como parametros una referencia al vector books, esto para no tener que hacer una copia y
	//usar m�s memoria
	//leemos el archivo
	ifstream books_file("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\books.csv", ios::in);
	//control por si no se lee adecuadamente el archivo csv
	if (!books_file) {
		cerr << "El archivo de Books.csv no pudo ser accesado correctamente, favor de intentar de nuevo" << endl;
		exit(EXIT_FAILURE);
	}
	//declaramos el strng en donde vamos a almacenar lo leido del csv
	string linea;
	//leemos la primera linea del csv para saltarnos los encabezados de nuestra tabla inicial
	getline(books_file, linea);
	//volvemos a leer en este caso con el identificador de ','
	while (getline(books_file, linea, ',')) {
		//declaramos una variable temporal en donde vamos a almacenar lo leido con su tipo de dato respectivo
		int temp_book_id;
		//convertimos lo leido al tipo de dato adecuado
		temp_book_id = stoi(linea);
		// volvemos a usar la funcion getline para pasar a la siguiente entrada de nuestro archivo csv
		getline(books_file, linea, ',');
		//repetimos el mismo proceso
		//definimmos una variable temporal con el tipo de dato adecuado
		long temp_goodreads_d;
		//a partir del id, vamos a realizar una validacion en el caso de que el campo que intentamos leer este vacio
		//esto con el unico objetivo de evitar errores al momento de asignar los datos en las variables temporales
		if (linea == "\0") {
			temp_goodreads_d = 0; //en caso de que este vacio el espacio, declaramos el dato como 0
		}
		else {
			temp_goodreads_d = stol(linea); //en caso de que no este vacio, convertimos la string en el tipo de dato adecuado en la variable temporal
		}
		//repetimos el proceso
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
		// en este caso tenemos que hacer una validacion diferente
		//esto por que tenemos un campo en donde la entrada puede tener comas intermedias, pero toda la entrada encerrada entre unos " "
		// por lo que tenemos que hacer la siguiente validacion
		if (!linea.empty() && linea.front() == '"' && linea.back() != '"') { //ponemos un condicinoal if que se va a ejecutar en el caso de que
			//le linea no este vacia y el principio sea el caracter '"' y el final no sea '"'
			std::string temp; //declaramos un string temporal en donde vamos a ir agregando lo que siga de las comas
			temp += linea; //sumamos lo promero que se ley� en el primer getline
			while (getline(books_file, linea, ',')) { //volvemos a leer buscando m�s comas
				temp += linea; //sumamos lo leido a la variable temporal
				if (!linea.empty() && linea.back() == '"') { //hacemos un nuevo condicional en donde se va a entrar
					//en el caso de que la variable no este vacia y en el caso en que el final SI sea el caracter '"'
					break; // en ese caso ya terimnamos de leer, por lo que hacemo un break
				}
				else { //en al caso de que el caracter final no sea '"', entonces vamos a agregar
					//una , al final
					temp += ',';
				}
			} // asignamos todo lo leido en la variable temporal string en la linea que lee
			linea = temp;
		}


		// una vez realizado todo el proceso de validacion, repetimos el proceso
		// creamos una variable temporal, etc...
		std::string temp_authors;
		//validacion extra por si la linea esta vacia
		if (linea.empty()) {
			temp_authors = " ";
		}
		else {
			temp_authors = linea;
		}
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
		//validacion extra por si la linea esta vacia
		if (linea.empty()) {
			temp_original_title = " ";
		}
		else {
			temp_original_title = linea;
		}
		getline(books_file, linea);

		std::string temp_title;
		//validacion extra por si la linea esta vacia
		if (linea.empty()) {
			temp_title = " ";
		}
		else {
			temp_title = linea;
		}

		//al final de leer todas las lineas del archivo csv, metemos todas las variables
		//utilizando el constructor que utiliza todos los argumentos
		Book tempBook(temp_book_id, temp_goodreads_d, temp_best_book_id,
			temp_work_id, temp_books_count, temp_isbn, temp_isbn13,
			temp_authors, temp_publication_year, temp_original_title,
			temp_title);
		//metemos el nuevo objeto en el vector previamente creado
		books.push_back(tempBook);

	}
	//cerramos el archivo csv
	books_file.close();
	//imprimimos una confirmacion
	//std::cout << "El archivo Libros.csv fue leido correctamente" << endl;
}
Rating::Rating(int userId, int bookId, int rating, vector<Book>& books) : user_id(userId), book_id(bookId), rating(rating) {
	setTitle(books, bookId);
	incrementSearchCount();
} //constructor que toma todos los argumentos
Rating::Rating(int userId, int bookId, int rating, std::string title) {
	this->user_id = userId;
	this->book_id = bookId;
	this->rating = rating;
	this->title = title;
}

// definicion de los setters

void Rating::setUserId(int userId) {
	user_id = userId;
}
void Rating::setBookId(int bookId) {
	book_id = bookId;
}
void Rating::setRating(int newRating) {
	rating = newRating;
}
void Rating::setTitle(vector<Book>& books, int bookId) {
	for (int i = 0; i < books.size(); i++) {
		if (bookId == books[i].getBookId()) {
			this->title = books[i].getOriginalTitle();
			return;
		}
	}
}
void Rating::incrementSearchCount() {
	searchCount++;
}
//definicion de los getters
int Rating::getUserId() const {
	return user_id;
}
int Rating::getBookId() const {
	return book_id;
}
int Rating::getRating() const {
	return rating;
}
string Rating::getTitle() const {
	return title;
}
int Rating::getSearchCount() const {
	return searchCount;
}
//funcion para leer los archivos chunks csv y rellenar el vector
std::vector<Rating> Rating::readRatingsCSV(const std::string& filePath, vector<Book>& books) { //toma como argumento una referencia al string filepath que almacena la direccion
	// en donde se encuentra el archivo chunk que vamos a leer uno por uno
	std::vector<Rating> ratings;
	std::ifstream ratings_file(filePath);
	if (!ratings_file) {
		std::cerr << "Error al abrir el archivo ratings.csv" << std::endl;
		return ratings;
	}
	std::string line;
	std::getline(ratings_file, line);//leemos la primera linea de encabezados
	while (std::getline(ratings_file, line)) {
		std::stringstream ss(line);
		std::string token;

		// Leer campos del CSV separados por comas
		std::getline(ss, token, ','); // Lee user_id como cadena
		int userId = std::stoi(token);

		std::getline(ss, token, ','); // Lee book_id como cadena
		int bookId = std::stoi(token);

		std::getline(ss, token, ','); // Lee rating como cadena
		int ratingValue = std::stoi(token);

		// Asegurar que las cadenas tengan una longitud fija
		std::string userIdStr = std::to_string(userId);
		std::string bookIdStr = std::to_string(bookId);
		std::string ratingStr = std::to_string(ratingValue);

		userIdStr.resize(10, ' '); // Ajusta la longitud a 10 caracteres
		bookIdStr.resize(10, ' '); // Ajusta la longitud a 10 caracteres
		ratingStr.resize(10, ' '); // Ajusta la longitud a 10 caracteres

		// Crea un objeto Rating y agr�galo al vector
		Rating ratingObj(userId, bookId, ratingValue, books);
		ratings.push_back(ratingObj);
	}

	ratings_file.close();
	//std::cout << "Objetos creados correctamente." << std::endl; // Mensaje de confirmaci�n
	return ratings;
}

// Sobrecarga del operador de inserci�n para imprimir un objeto Rating
std::ostream& operator<<(std::ostream& out, const Rating& ratingObj) {
	out << "User ID: " << ratingObj.getUserId() << ", Book ID: " << ratingObj.getBookId() << ", Rating: " << ratingObj.getRating();
	return out;
}
// Definici�n de la funci�n para llenar el mapa de t�tulos para cada usuario
void fillUserTitleMap(const vector<Rating>& ratings, map<int, vector<string>>& userTitleMap) {
	for (const auto& rating : ratings) {
		// Obtener el user_id y el t�tulo del rating actual
		int userId = rating.getUserId();
		string bookTitle = rating.getTitle();

		// Verificar si el user_id ya est� en el mapa
		if (userTitleMap.find(userId) == userTitleMap.end()) {
			// Si no est� en el mapa, agregar una nueva entrada con el user_id y un vector que contiene el t�tulo
			userTitleMap[userId] = { bookTitle };
		}
		else {
			// Si ya est� en el mapa, agregar el t�tulo al vector existente
			userTitleMap[userId].push_back(bookTitle);
		}
	}
	//std::cout << "Mapa creado correctamente" << endl;
}
void read5RatinCsv(const vector<Rating>& ratings1, const vector<Rating>& ratings2, const vector<Rating>& ratings3, const vector<Rating>& ratings4, const vector<Rating>& ratings5, map<int, vector<string>>& userTitleMap) {
	fillUserTitleMap(ratings1, userTitleMap);
	fillUserTitleMap(ratings2, userTitleMap);
	fillUserTitleMap(ratings3, userTitleMap);
	fillUserTitleMap(ratings4, userTitleMap);
	fillUserTitleMap(ratings5, userTitleMap);
}
void printMenu() {
	cout << "Bienvenido a la biblioteca virtual" << endl;
	cout << "------------------------------------------" << endl;
	cout << "1.- Busqueda por titulo de libro" << endl;
	cout << "2.- Busqueda por a�o de publicacion" << endl;
	cout << "3.- Busqueda por ISBN" << endl;
	cout << "4.- Calificacion promedio de un libro" << endl; //promedio de calificaion de los usuarios
	cout << "5.- Busqueda de usuario" << endl;//lso datos de un usuario por medio de su id
	cout << "6.- Usuario con más ratings" << endl;
	cout << "7.- Nuevo CSV Ratings" << endl;
	cout << "8.- Cerrar la sesion" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Selccione una opci�n:" << endl;
}
void limpiarConsola() {
#ifdef _WIN32
	system("cls");
#else
	systema("clear");
#endif
}
void busquedaPorTitulo(vector<Book>& books) {
	limpiarConsola();
	string titulo;
	string exit;
	cout << "---Busqueda por titulo---" << endl;
	cout << "Introduzca el libro a buscar: " << endl;
	cin.ignore();
	getline(cin, titulo);
	for (int i = 0; i < books.size(); i++) {
		if (titulo == books[i].original_title) {
			cout << "" << endl;
			cout << "Datos del libro " << books[i].original_title << ": " << endl;
			cout << "ID: " << books[i].book_id << endl;
			cout << "Autor: " << books[i].authors << endl;
			cout << "A�o de publicacion: " << books[i].publication_year << endl;
			cout << "Isbn: " << books[i].isbn << endl;
			cout << "Presiona Enter para volver al menu..." << std::endl;
			cin.ignore();
			cin.get();
			return;
		}
	}
	cout << "No se encontro el libro, intente una vez mas" << endl;
	cout << "Presiona Enter para volver al menu..." << std::endl;
	cin.ignore();
	cin.get();
}
void busquedaPorAno(vector<Book>& books) {
	limpiarConsola();
	int ano;
	string exit;
	bool find_control = false;
	cout << "---Busqueda por A�o de publicacion---" << endl;
	cout << "Introduzca el a�o: " << endl;
	cin >> ano;
	cin.ignore();
	for (int i = 0; i < books.size(); i++) {
		if (ano == books[i].publication_year) {
			find_control = true;
			cout << "--------------------------------" << endl;
			cout << "Datos del libro " << books[i].original_title << ": " << endl;
			cout << "ID: " << books[i].book_id << endl;
			cout << "Autor: " << books[i].authors << endl;
			cout << "A�o de publicacion: " << books[i].publication_year << endl;
			cout << "Isbn: " << books[i].isbn << endl;
			cout << "--------------------------------" << endl;
		}
	}
	if (find_control) {
		cout << "Presiona Enter para volver al menu..." << std::endl;
		cin.get();
	}
	else {
		cout << "No se encontro el libro, intente una vez mas" << endl;
		cout << "Presiona Enter para volver al menu..." << std::endl;
		cin.get();

	}
}
void busquedaPorIsbn(vector<Book>& books) {
	limpiarConsola();
	double isbn;
	string exit;
	cout << "---Busqueda por ISBN---" << endl;
	cout << "Introduzca el ISBN del libro a buscar: " << endl;
	cin >> isbn;
	cin.ignore();
	for (int i = 0; i < books.size(); i++) {
		if (isbn == books[i].isbn) {
			cout << "" << endl;
			cout << "Datos del libro " << books[i].original_title << ": " << endl;
			cout << "ID: " << books[i].book_id << endl;
			cout << "Autor: " << books[i].authors << endl;
			cout << "A�o de publicacion: " << books[i].publication_year << endl;
			cout << "Isbn: " << books[i].isbn << endl;
			cout << "Presiona Enter para volver al menu..." << std::endl;
			cin.get();
			return;
		}
	}
	cout << "No se encontro el libro, intente una vez mas" << endl;
	cout << "Presiona Enter para volver al menu..." << std::endl;
	cin.get();
}
double calificacionPromedioPorTitulo(const vector<Rating>& ratings, const vector<Book>& books, string titulo) {
	limpiarConsola();
	double promedio = 0.0;
	// Buscar el libro por t�tulo
	auto it = find_if(ratings.begin(), ratings.end(), [titulo](const Rating& book) {
		return book.getTitle() == titulo;
		});
	if (it != ratings.end()) {
		int bookId = it->getBookId();

		// Filtrar los ratings del libro espec�fico
		vector<Rating> bookRatings;
		copy_if(ratings.begin(), ratings.end(), back_inserter(bookRatings), [bookId](const Rating& rating) {
			return rating.getBookId() == bookId;
			});
		// Calcular el promedio de calificaci�n

		for (const Rating& rating : bookRatings) {
			promedio += rating.getRating();
		}
		if (!bookRatings.empty()) {
			promedio /= bookRatings.size();
		}
	}
	else {
		cout << "No se encontr� el libro. Intente nuevamente." << endl;
	}
	return promedio;
	cin.ignore();
	cin.get();
}
void showPromedio(const vector<Rating>& ratings1, const vector<Rating>& ratings2, const vector<Rating>& ratings3, const vector<Rating>& ratings4, const vector<Rating>& ratings5, const vector<Book>& books) {
	string titulo;
	cout << "---Calificaci�n Promedio por T�tulo---" << endl;
	cout << "Introduzca el t�tulo del libro: " << endl;
	cin.ignore();
	getline(cin, titulo);
	double promedio1 = calificacionPromedioPorTitulo(ratings1, books, titulo);
	double promedio2 = calificacionPromedioPorTitulo(ratings2, books, titulo);
	double promedio3 = calificacionPromedioPorTitulo(ratings3, books, titulo);
	double promedio4 = calificacionPromedioPorTitulo(ratings4, books, titulo);
	double promedio5 = calificacionPromedioPorTitulo(ratings5, books, titulo);
	double promedioGeneral = (promedio1 + promedio2 + promedio3 + promedio4 + promedio5) / 5;
	// Imprimir el resultado
	cout << "El promedio de calificaci�n del libro " << titulo << " es: " << fixed << setprecision(2) << promedioGeneral << endl;
	cout << "Presiona Enter para volver al men�..." << endl;
	cin.ignore();
	cin.get();
}

void buscarUsuarioPorId(map<int, vector<string>>& userTitleMap,int userId) {
	bool usuarioEncontrado = false;

	for (const auto user : userTitleMap) {
		if (user.first == userId) {
			usuarioEncontrado = true;
			cout << "Datos del Usuario (ID: " << userId << "):" << endl;
			for (string libro : user.second) {
				cout << "Titulo del Libro: " << libro << endl;
			}
			break;
		}
	}
	if (!usuarioEncontrado) {
		cout << "Usuario no encontrado. Verifica el ID del usuario." << endl;
	}
	cout << "Presiona Enter para volver al men�..." << endl;
	cin.ignore();
	cin.get();
}
void usuarioConMasRatings(map<int, vector<string>>& userTitleMap) {
	cout << "---Usuario con mas ratings---" << endl;
	int maxStrings = 0;
	int userid = 1;
	for (auto user : userTitleMap) {
		if (user.second.size() > maxStrings) {
			maxStrings = user.second.size();
			userid = user.first;
		}
	}
	cout << "El usuario con más ratings es: " << endl;
	cout << "User Id: " << userid << endl;
	cout << "Numero de ratigns: " << maxStrings << endl;
	cout << "Presiona Enter para volver al menu..." << endl;
	cin.ignore();
	cin.get();
}

void crearNuevoCsv(const std::vector<Rating>& ratings, std::vector< Book>& books) {
	// Verificar si hay suficientes datos en las listas
	if (ratings.size() < 1000 || books.size() < 1000) {
		std::cerr << "No hay suficientes datos para crear el nuevo archivo CSV." << std::endl;
		return;
	}

	// Crear un nuevo archivo CSV
	std::ofstream newCsv("C:\\Users\\emili\\OneDrive\\Escritorio\\UP\\TERCER_SEMESTRE\\Programacion_avanzada\\PROYECTO_FINAL\\newCsv.csv", std::ios::out);
	if (!newCsv) {
		std::cerr << "Error al abrir el archivo para escribir." << std::endl;
		return;
	}

	// Escribir encabezados en el nuevo archivo CSV
	newCsv << "UserId,Book_id,Rating,Titulo" << std::endl;

	// Iterar sobre los primeros 1000 datos

	for (int i = 0; i < 1000; ++i) {
		int userId = ratings[i].getUserId();
		int bookId = ratings[i].getBookId();
		int rating = ratings[i].getRating();
		string title = ratings[i].getTitle();

		newCsv << userId << "," << bookId << "," << rating << "," << title << std::endl;


		// Escribir en el nuevo archivo CSV
	}

	std::cout << "Nuevo archivo CSV creado correctamente." << std::endl;
	cout << "Presiona Enter para volver al menu..." << endl;
	cin.ignore();
	cin.get();
}