#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
// definicion de la clase book
class Book {
private:
	int book_id;
	long goodreads_d;
	long best_book_id;
	long work_id;
	int books_count;
	double isbn;
	double isbn13;
	string authors;
	int publication_year;
	string original_title;
	string title;
	int searchCount;
public:
	Book(); //constructor vacio
	Book(int id, long goodread, long best_book, long work_id, int book_count,
		double isbn, double isbn13, std::string authors, int pub_year, std::string org_title,
		std::string title); //constructor que toma todos los argumentos
	//setters
	void setBookID(int book_id);
	void setGoodReadsId(long goodreads_id);
	void setbestBookId(long best_book_id);
	void setWorkId(long work_id);
	void setBookCount(int book_count);
	void setIsbn(double isbn);
	void setIsbn13(double isbn13);
	void setAuthor(std::string& authorString);
	void setPublicationYear(int publication_year);
	void setOriginalTitle(std::string& or_title_string);
	void setTitle(std::string& title_string);
	void incrementSearchCount();
	//getters
	int getBookId();
	long getGoodReadsId();
	long getBestBookId();
	long getWorkId();
	int getBookCount();
	double getIsbn();
	double getIsbn13();
	int getPublicationYear();
	string getAuthor();
	string getTitle();
	string getOriginalTitle();
	int getSearchCount() const;
	//funcion para procesar los datos del csv libros
	// para poder guardarlos en el vector;
	friend void readingBOOKCSV(std::vector<Book>& books);
	friend void busquedaPorTitulo(vector<Book>& books);
	friend void busquedaPorAno(vector<Book>& books);
	friend void busquedaPorIsbn(vector<Book>& books);
};

class Rating {
private:
	int user_id;
	int book_id;
	int rating;
	std::string title;
	int searchCount;

public:
	Rating(int userId, int bookId, int rating, vector<Book>& books); //constructor con todos los argumentos
	Rating(int userId, int bookId, int rating, std::string title);
	//setters
	void setUserId(int userId);
	void setBookId(int bookId);
	void setRating(int rating);
	void setTitle(vector<Book>& books, int bookId);
	void incrementSearchCount();
	//getters
	int getUserId() const;
	int getBookId() const;
	int getRating() const;
	std::string getTitle() const;
	int getSearchCount() const;
	// Funci�n para leer datos del archivo CSV y crear objetos Rating
	static std::vector<Rating> readRatingsCSV(const std::string& filePath, vector<Book>& books);
	// Sobrecarga del operador de inserci�n para imprimir un objeto Rating
	friend std::ostream& operator<<(std::ostream& out, const Rating& ratingObj);
};
// Prototipo de la funci�n de sobrecarga del operador de inserci�n
std::ostream& operator<<(std::ostream& out, const Rating& ratingObj);
void fillUserTitleMap(const vector<Rating>& ratings, map<int, vector<string>>& userTitleMap);
void read5RatinCsv(const vector<Rating>& ratings1, const vector<Rating>& ratings2, const vector<Rating>& ratings3, const vector<Rating>& ratings4, const vector<Rating>& ratings5, map<int, vector<string>>& userTitleMap);

void limpiarConsola();
void printMenu();
//prototipo de las funciones extra
double calificacionPromedioPorTitulo(const vector<Rating>& ratings, const vector<Book>& books, string titulo);
void showPromedio(const vector<Rating>& ratings1, const vector<Rating>& ratings2, const vector<Rating>& ratings3, const vector<Rating>& ratings4, const vector<Rating>& ratings5, const vector<Book>& books);
void buscarUsuarioPorId(map<int, vector<string>>& userTitleMap, int userId);
void usuarioConMasRatings(map<int, vector<string>>& userTitleMap);
void crearNuevoCsv(const std::vector<Rating>& ratings, std::vector< Book>& books);
#endif