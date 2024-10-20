/**
 * @file transition.h
 * @author Adrián Padrón Espinosa (alu0101323626@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-10-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

class Transition {
public:
    char symbol;
    int nextState;

    Transition(char sym, int next) : symbol(sym), nextState(next) {}
};