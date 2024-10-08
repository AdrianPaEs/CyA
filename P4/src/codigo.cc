/**
 * @file struct.cc
 * @author Adrián Padrón Espinosa (alu0101323626@ull.edu.es)
 * @brief
 * @version 0.1
 * @date 2024-10-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/codigo.h"

std::string Codigo::ObtainDescription(std::string content, int line_number) {
  std::regex regex_description(
      R"(^\s*(\/\*\*|\*\/|\*\s*.*))"); // Expresion regular para buscar la
                                       // descripción del programa
  std::smatch match; // Clase que almacena los resultados de la busqueda
  if (std::regex_search(content, match, regex_description)) {
    line_number_ = line_number;
    std::string output = match.str();
    if (aux1_ < line_number_){
      aux2_ = line_number_;
    }
    else{
      aux1_ = line_number_;
    }
    aux_ = 1;
    return output;
  }
  return "";
}

std::string Codigo::ObtainInt(std::string content, int line_number) {
  std::regex regex_int(
      R"(^\s*int\s+([a-zA-Z_]\w*(\s*,\s*[a-zA-Z_]\w*)*)?\s*(=\s*\d+)?\s*;)"); // Expresion regular para buscar variables de tipo int
  std::smatch match;
  if (std::regex_search(
          content, match,
          regex_int)) // Busca la expresion regular en el contenido
  {
    line_number_ = line_number;
    variable_int_ = match.str();
    std::string output = "[Line " + std::to_string(line_number_) + "]" +
                         " INT: " + variable_int_;
    return output;
  }
  return "";
}

std::string Codigo::ObtainDouble(std::string content, int line_number) {
  std::regex regex_double(
      R"(^\s*double\s+([a-zA-Z_]\w*(\s*,\s*[a-zA-Z_]\w*)*)?\s*(=\s*\d+(\.\d+)?)?\s*;)");
  std::smatch match;
  if (std::regex_search(content, match, regex_double)) {
    line_number_ = line_number;
    variable_double_ = match.str();
    std::string output = "[Line " + std::to_string(line_number_) + "]" +
                         " DOUBLE: " + variable_double_;
    return output;
  }
  return "";
}

std::string Codigo::ObtainFor(std::string content, int line_number) {
  std::regex regex_for(R"(^\s*for\s*\()");
  std::smatch match;
  if (std::regex_search(content, match, regex_for)) {
    line_number_ = line_number;
    std::string output =
        "[Line " + std::to_string(line_number_) + "] LOOP: for";
    return output;
  }
  return "";
}

std::string Codigo::ObtainWhile(std::string content, int line_number) {
  std::regex regex_while(R"(^\s*while\s*\()");
  std::smatch match;
  if (std::regex_search(content, match, regex_while)) {
    line_number_ = line_number;
    std::string output =
        "[Line " + std::to_string(line_number_) + "] LOOP: while";
    return output;
  }
  return "";
}

std::string Codigo::ObtainMain(std::string content, int line_number) {
  std::regex regex_main(R"((\s*\D*)main\s*)");
  std::smatch match;
  if (std::regex_search(content, match, regex_main)) {
    std::string output = "TRUE";
    return output;
  } else {
    std::string output = "FALSE";
    return output;
  }
}

std::string Codigo::ObtainComments(std::string content, int line_number) {
  std::regex regex_comments1(R"(^\/\/(.)*)");
  std::smatch match;
  if (std::regex_search(content, match, regex_comments1)) {
    line_number_ = line_number;
    std::string output = "[Line " + std::to_string(line_number_) + "] " + match.str();
    return output;
  }
  if(aux_ == 1){
    std::string output = "[Line " + std::to_string(aux1_) + "-" + std::to_string(aux2_) + "] DESCRIPTION" ;
    aux_ = 2;
    return output;
  }
  return "";
}