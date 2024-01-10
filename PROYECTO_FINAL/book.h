#pragma once
#ifndef BOOK_LIB_H
#define BOOK_LIB_H
//#include "header.h"
#include <vector>
#include<string>
using namespace std;
class Book {
private:
	int book_id;
	long goodreads_d;
	long best_book_id;
	long work_id;
	int books_count;
	double isbn;
	double isbn13;
	char authors[50];
	int publication_year;
	char original_title[50];
	char title[50];
public:
	Book();
	Book(int id, long goodread, long best_book, long work_id, int book_count,
		double isbn, double isbn13, std::string authors, int pub_year, std::string org_title,
		std::string title);
	void setBookID(int book_id);
	void setGoodReadsId(long goodreads_id);
	void setbestBookId(long best_book_id);
	void setWorkId(long work_id);
	void setBookCount(int book_count);
	void setIsbn(double isbn);
	void setIsbn13(double isbn13);
	void setAuthor(const std::string& authorString);
	void setPublicationYear(int publication_year);
	void setOriginalTitle(const std::string& or_title_string);
	void setTitle(const std::string& title_string);
	int getBookId();
	long getGoodReadsId();
	long getBestBookId();
	long getWorkId();
	int getBookCount();
	double getIsbn();
	double getIsbn13();
	int getPublicationYear();
	friend void readingBOOKCSV(std::vector<Book>& books);//funcion para procesar los datos del csv libros
	// para poder guardarlos en el vector;
};
//void readingBOOKCSV(std::vector<Book>& books);

#endif