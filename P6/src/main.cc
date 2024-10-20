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
#include <set>

void printUsage() {
  std::cout << "<Modo de empleo: ./p06_automata_simulator input.fa input.txt\nPruebe ’p06_automata_simulator --help’ para m´as informaci´on." << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "ERROR: Número incorrecto de parámetros" << std::endl;
    printUsage();
    return 1;
  }
  if (std::string(argv[1]) == "--help") {
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt\n\n";
    std::cout << "Donde:\n";
    std::cout << "input.fa es el fichero de entrada con la definición del autómata finito.\n";
    std::cout << "input.txt es el fichero de entrada con la secuencia de símbolos a procesar.\n";
    return 0;
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