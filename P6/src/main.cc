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
#include <fstream>
#include <vector>
#include <string>

void printUsage() {
  std::cout << "Usage: ./p06_automata_simulator <input.fa> <input.txt>" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "ERROR: Número incorrecto de parámetros" << std::endl;
    printUsage();
    return 1;
  }
  std::string InputFileName = argv[1];
  std::string OutputFileName = argv[2];
  std::vector<std::string> content;
  std ::string line;
  std::ifstream inputFile(InputFileName);

  if (inputFile.is_open()) {
    while (std::getline(inputFile, line)) {
      content.push_back(line);
    }
    inputFile.close();
    for (const auto& str : content) {
      std::cout << str << std::endl;
    }
  } else {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }
  // std::string filename = argv[2];
  // file.open(filename);
  // if (file.is_open()) {
  //   for (const auto& linea : lines) {
  //     filename << linea << std::endl; 
  //   }
  //   file.close();
  // } 

}