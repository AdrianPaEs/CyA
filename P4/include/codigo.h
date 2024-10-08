/**
 * @file Codigo.h
 * @author Adrián Padrón Espinosa (alu0101323626@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>

class Codigo {
 public:
  // Constructor
  Codigo() = default;
  // Destructor
  ~Codigo() = default;

  // Métodos
  std::string ObtainDescription(
      std::string content,
      int line_number);  // Obtiene la descripción del programa
  std::string ObtainInt(std::string content,
                        int line_number);  // Obtiene las variables de tipo int
  std::string ObtainDouble(
      std::string content,
      int line_number);  // Obtiene las variables de tipo double
  std::string ObtainFor(std::string content,
                        int line_number);  // Obtiene los bucles for
  std::string ObtainWhile(std::string content,
                          int line_number);  // Obtiene los bucles while
  std::string ObtainMain(std::string content,
                         int line_number);  // Obtiene la función main
  std::string ObtainComments(std::string content,
                             int line_number);  // Obtiene los comentarios

 private:
  // Atributos
  std::string variable_int_;
  std::string variable_double_;
  int line_number_;
  int aux_ = 0;
  int aux1_ = 1;
  int aux2_ = 1;

  std::string trimLeft(
      const std::string &str) {  // Elimina los espacios a la izquierda
    auto start = std::find_if_not(
        str.begin(), str.end(),
        ::isspace);  // Busca el primer caracter que no sea un espacio
    return std::string(
        start,
        str.end());  // Devuelve la cadena sin los espacios a la izquierda
  }
};