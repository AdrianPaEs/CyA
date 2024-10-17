/**
 * @file main.cc
 * @author Adrián Padrón Espinosa (alu0101323626@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2024-10-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <string>
#include <fstream>

void printUsage() {
  std::cout << "Usage: ./p06_automata_simulator <input.fa> <input.txt>" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "ERROR: Número incorrecto de parámetros" << std::endl;
    printUsage();
    return 1;
  }
  // std::string filename = argv[1];
  // std::vector<std::string> lines;
  // file.open(filename);
  // if (file.is_open()) {
  //   while (std::getline(file, line)) {
  //     lines.push_back(line);
  //   }
  //   file.close();
  // } else {
  //   std::cerr << "Error: could not open file." << std::endl;
  //   return 1;
  // }

}