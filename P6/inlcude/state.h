/**
 * @file state.h
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

class State {
public:
    int id;
    bool isAccepting;
    std::vector<Transition> transitions;

    State(int id, bool accepting) : id(id), isAccepting(accepting) {}

    void addTransition(char symbol, int nextState) {
        transitions.emplace_back(symbol, nextState);
    }
};