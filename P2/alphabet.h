/**
 * @file alfabeto.h
 * @author Adrián Padrón Espinosa
 * @brief 
 * @version 0.1
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <set>

#include "symbol.h"

class Alphabet{
  public:
    // Constructores
    Alphabet();
    Alphabet(Symbol<>);
    // Destructor
    ~Alphabet();
    // Getter
    void getAlphabet(std::set<Symbol>);

  private:
    std::set<Symbol> alphabet_;

}