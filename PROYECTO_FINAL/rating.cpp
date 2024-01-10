#pragma once
#ifndef RATING_LIB_CPP
#define RATING_LIB_CPP
#include "rating.h"
#include <fstream>
#include <sstream>
#include <iomanip> // Para establecer longitud fija en cadenas

Rating::Rating(int userId, int bookId, int rating) : user_id(userId), book_id(bookId), rating(rating) {}

void Rating::setUserId(int userId) {
    user_id = userId;
}

void Rating::setBookId(int bookId) {
    book_id = bookId;
}

void Rating::setRating(int newRating) {
    rating = newRating;
}

void Rating::setTitle(const std::string& bookTitle) {
    title = bookTitle;
}
int Rating::getUserId() const {
    return user_id;
}

int Rating::getBookId() const {
    return book_id;
}

int Rating::getRating() const {
    return rating;
}

std::string Rating::getTitle() const {
    return title;
}

std::vector<Rating> Rating::readRatingsCSV(const std::string& filePath) {
    std::vector<Rating> ratings;
    std::cout << filePath << std::endl;
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

        // Crea un objeto Rating y agrégalo al vector
        Rating ratingObj(userId, bookId, ratingValue);
        ratings.push_back(ratingObj);
    }

    ratings_file.close();
    std::cout << "Objetos creados correctamente." << std::endl; // Mensaje de confirmación
    return ratings;
}

// Sobrecarga del operador de inserción para imprimir un objeto Rating
std::ostream& operator<<(std::ostream& out, const Rating& ratingObj) {
    out << "User ID: " << ratingObj.getUserId() << ", Book ID: " << ratingObj.getBookId() << ", Rating: " << ratingObj.getRating();
    return out;
}
#endif
