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
#include <regex>
#include <iostream>
#include <fstream> 
#include <string>
#include <utility>

class Codigo{
  public:
    //Constructor
    Codigo() = default;
    //Destructor
    ~Codigo() = default;

    //Métodos
    std::string ObtainComments(std::string content, int line_number);
    std::string ObtainInt(std::string content, int line_number);
    std::string ObtainDouble(std::string content, int line_number);
    std::string ObtainFor(std::string content, int line_number);
    std::string ObtainWhile(std::string content, int line_number);
    std::string ObtainMain(std::string content, int line_number);


  private:
    std::string variable_int_;
    std::string variable_double_;
    int line_number_;
};