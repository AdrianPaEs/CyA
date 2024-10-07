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

std::string Codigo::ObtainInt(std::string content, int line_number)
{
  std::regex regex_int("int\\s+([a-zA-Z]\\w*(,\\s*[a-zA-Z]\\w*)*)?\\s*(=\\s*[^;]*\\s*)?;"); // Expresion regular para encontrar variables int
  std::smatch match;                                                                        // Clase que almacena los resultados de la busqueda
  if (std::regex_search(content, match, regex_int))                                         // Busca la expresion regular en el contenido
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
  std::regex regex_double("double\\s+([a-zA-Z]\\w*(,\\s*[a-zA-Z]\\w*)*)?\\s*(=\\s*(\\+|\\-)?\\d*(\\,|\\.)\\s*\\d*)?;");
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
  std::regex regex_for("for\\s*\\(");
  std::smatch match;
  if (std::regex_search(content, match, regex_for))
  {
    line_number_ = line_number;
    std::string output = "[Line " + std::to_string(line_number_) + "] LOOP: for";
    return output;
  }
  return "";
}

// void Codigo::ObtainWhile(std::string content, int line_number)
// {
//   std::regex regex_while("while\\s*\\(");
//   std::smatch match;
//   if (std::regex_search(content, match, regex_while))
//   {
//     line_number_ = line_number;
//     std::cout << "[Line " << line_number_ << "] LOOP: while" << std::endl;
//   }
// }

// std::string Codigo::ShowWhile()
// {
//   return "while";
// }

// // void Codigo::ObtainComments(std::string content, int line_number){
// //   std::regex regex_comments("/\\*\\s*(.*?)\\s*\\*\\/");
// //   std::smatch match;
// //   if (std::regex_search(content, match, regex_comments))
// //   {
// //     line_number_ = line_number;
// //     std::cout << "[Line " << line_number_ << "] COMMENT: " << content << std::endl;
// //   }
// // }

// // void Codigo::ObtainMain(std::string content)
// // {
// //   std::regex regex_main("int\\s+main\\s*\\(");
// //   std::smatch match;
// //   std::cout << "MAIN: "<< std::endl;
// //   if (std::regex_search(content, match, regex_main))
// //   {
// //     x = 1;
// //   }
// //   return x;
// // }