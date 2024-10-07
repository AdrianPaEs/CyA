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

std::string Codigo::ObtainComments(std::string content, int line_number){
  std::regex regex_comments(R"(^(\s*(\/\*\*\d*))|(\s*\*\s*((\D|\d)*\s*)*)*|(\s*\*\/)$)");
  std::smatch match;
  if (std::regex_search(content, match, regex_comments))
  {
    std::string output = match.str();
    return output;
  }
}

std::string Codigo::ObtainInt(std::string content, int line_number)
{
  std::regex regex_int(R"(^\s*int\s+([a-zA-Z]\w*(,\s*[a-zA-Z]\w*)*)?\s*(=\s*\d*\s*)?;)"); // Expresion regular para encontrar variables int
  std::smatch match;                                                                      // Clase que almacena los resultados de la busqueda
  if (std::regex_search(content, match, regex_int))                                       // Busca la expresion regular en el contenido
  {
    line_number_ = line_number;
    variable_int_ = match.str();
    std::string output = "[Line " + std::to_string(line_number_) + "]" + " INT: " + variable_int_;
    return output;
  }
  return "";
}

std::string Codigo::ObtainDouble(std::string content, int line_number)
{
  std::regex regex_double(R"(^\s*double\s+([a-zA-Z]\w*(,\s*[a-zA-Z]\w*)*)?\s*(=\s*\d+\s*((,|.)\d)*)?;)");
  std::smatch match;
  if (std::regex_search(content, match, regex_double))
  {
    line_number_ = line_number;
    variable_double_ = match.str();
    std::string output = "[Line " + std::to_string(line_number_) + "]" + " DOUBLE: " + variable_double_;
    return output;
  }
  return "";
}

std::string Codigo::ObtainFor(std::string content, int line_number)
{
  std::regex regex_for(R"(^\s*for\s*\()");
  std::smatch match;
  if (std::regex_search(content, match, regex_for))
  {
    line_number_ = line_number;
    std::cout << line_number_ << std::endl;
    std::string output = "[Line " + std::to_string(line_number_) + "] LOOP: for";
    return output;
  }
  return "";
}

std::string Codigo::ObtainWhile(std::string content, int line_number)
{
  std::regex regex_while("while\\s*\\(");
  std::smatch match;
  if (std::regex_search(content, match, regex_while))
  {
    line_number_ = line_number;
    std::string output = "[Line " + std::to_string(line_number_) + "] LOOP: while";
    return output;
  }
  return "";
}

std::string Codigo::ObtainMain(std::string content, int line_number)
{
  std::regex regex_main(R"(^\s*\d*main\s*\)");
  std::smatch match;
  if (std::regex_search(content, match, regex_main))
  {
    std::string output = "True";
    return output;
  }
  else
  {
    std::string output = "False";
    return output;
  }
}