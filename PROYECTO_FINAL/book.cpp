#pragma once
#ifndef BOOK_LIB_CPP
#define BOOK_LIB_CPP
#include "book.h"
#include <fstream>
#include <iostream>
using namespace std;
Book::Book() {
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
	std::string title) {
	this->book_id = id;
	this->goodreads_d = goodread;
	this->best_book_id = best_book;
	this->work_id = work_id;
	this->books_count = book_count;
	this->isbn = isbn;
	this->isbn13 = isbn13;
	this->publication_year = pub_year;
	setAuthor(authors);
	setOriginalTitle(org_title);
	setTitle(title);
}
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
void Book::setAuthor(const std::string& authorString) {
	size_t length{ authorString.size() };
	length = (length < 15 ? length : 14);
	authorString.copy(authors, length);
	authors[length] = '\0'; // append null character to lastName
}
void Book::setPublicationYear(int publication_year) {
	this->publication_year = publication_year;
}
void Book::setOriginalTitle(const std::string& or_title_string) {
	size_t length{ or_title_string.size() };
	length = (length < 15 ? length : 14);
	or_title_string.copy(original_title, length);
	original_title[length] = '\0'; // append null character to lastName
}
void Book::setTitle(const std::string& title_string) {
	size_t length{ title_string.size() };
	length = (length < 15 ? length : 14);
	title_string.copy(title, length);
	title[length] = '\0'; // append null character to lastName
}
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

#endif