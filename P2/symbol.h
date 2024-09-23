/**
 * @file simbolo.h
 * @author Adrián Padrón Espinosa
 * @brief 
 * @version 0.1
 * @date 2024-09-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>

class Symbol{
  public:
    //Constructores
    Symbol();
    Symbol(char);
    //Destructores
    ~Symbol();
    // Getter
    void getSymbol(char);

  private:
    char symbol_;
}



