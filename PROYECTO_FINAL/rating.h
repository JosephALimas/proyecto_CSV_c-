#pragma once
#ifndef RATING_LIB_H
#define RATING_LIB_H

#include <iostream>
#include <vector>

class Rating {
private:
    int user_id;
    int book_id;
    int rating;
    std::string title;

public:
    //*************************************************************************
    // Prototipo de la función para leer datos del archivo CSV y crear objetos Rating
    //*************************************************************************


        // Constructor para crear objetos Rating a partir de datos del archivo CSV
    Rating(int userId, int bookId, int rating);

    void setUserId(int userId);
    void setBookId(int bookId);
    void setRating(int rating);
    void setTitle(const std::string& bookTitle);

    int getUserId() const;
    int getBookId() const;
    int getRating() const;
    std::string getTitle() const;
    // Función para leer datos del archivo CSV y crear objetos Rating
    static std::vector<Rating> readRatingsCSV(const std::string& filePath);
    // Sobrecarga del operador de inserción para imprimir un objeto Rating
    friend std::ostream& operator<<(std::ostream& out, const Rating& ratingObj);
};
// Prototipo de la función de sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& out, const Rating& ratingObj);

#endif
