/**
 * @file main.cc
 * @author Adrián Padrón Espinosa (alu0101323626@ull.edu.es)
 * @brief Programa que analiza el contenido de ficheros de código.
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "../include/codigo.h"

void printUsage() {
  std::cout << "Uso: ./p04_code_analyzer <fichero_entrada> <fichero_salida>\n";
}

int main(int argc, char *argv[]) {
  // Verificar número de argumentos
  if (argc != 3) {
    std::cout << "ERROR: Número incorrecto de parámetros" << std::endl;
    printUsage();
    return 1;
  }

  std::string inputFileName = argv[1];
  std::string outputFileName = argv[2];

  std::ifstream inputFile(inputFileName);
  if (!inputFile.is_open()) {
    std::cout << "Error: No se puede abrir el fichero de entrada: "
              << inputFileName << std::endl;
    return 1;
  }

  std::ofstream outputFile(outputFileName);
  if (!outputFile.is_open()) {
    std::cout << "Error: No se puede crear el fichero de salida: "
              << outputFileName << "\n"; // Cambiado a std::cerr
    return 1;
  }

  std::string line;
  Codigo variables;
  Codigo bucles;

  outputFile << "PROGRAMM: " << argv[1]
             << std::endl; // Mostramos nombre del programa

  std::vector<std::string> filetxt;
  while (std::getline(inputFile, line)) {
    filetxt.emplace_back(line);
  }

  int line_number = 1;
  std::string outputDescription;
  outputFile << "\nDESCRIPTION: "
             << std::endl; // Mostramos descripción del programa
  for (int i = 0; i < filetxt.size(); i++) {
    // Descripción
    outputDescription = variables.ObtainDescription(filetxt[i], line_number);
    if (outputDescription != "") {
      outputFile << outputDescription << std::endl;
    }
    line_number++;
  }

  line_number = 1;
  std::string outputInt;
  std::string outputDouble;
  outputFile << "\nVARIBALES: " << argv[1]
             << std::endl; // Mostramos variables del programa
  for (int i = 0; i < filetxt.size(); i++) {
    // Variables Int
    outputInt = variables.ObtainInt(filetxt[i], line_number);
    if (outputInt != "") {
      outputFile << outputInt << std::endl;
    }
    // Variables Double
    outputDouble = variables.ObtainDouble(filetxt[i], line_number);
    if (outputDouble != "") {
      outputFile << outputDouble << std::endl;
    }
    line_number++;
  }

  line_number = 1;
  std::string outputFor;
  std::string outputWhile;
  outputFile << "\nSTATEMENTS: " << std::endl; // Mostramos bucles del programa
  for (int i = 0; i < filetxt.size(); i++) {
    // Bucle For
    outputFor = bucles.ObtainFor(filetxt[i], line_number);
    if (outputFor != "") {
      outputFile << outputFor << std::endl;
    }
    // Bucle While
    outputWhile = bucles.ObtainWhile(filetxt[i], line_number);
    if (outputWhile != "") {
      outputFile << outputWhile << std::endl;
    }
    line_number++;
  }

  line_number = 1;
  std::string outputMain;
  outputFile << "\nMAIN: " << std::endl;
  bool main = false;
  for (int i = 0; i < filetxt.size(); i++) {
    outputMain = variables.ObtainMain(filetxt[i], line_number);
    if (outputMain == "TRUE") {
      outputFile << outputMain << std::endl;
      main = true;
      break;
    }
  }
  if (!main) {
    outputFile << "FALSE" << std::endl;
  }

  line_number = 1;
  std::string outputComments;
  outputFile << "\nCOMMENTS: "
             << std::endl; // Mostramos comentarios del programa
  for (int i = 0; i < filetxt.size(); i++) {
    // Descripción
    outputComments = variables.ObtainComments(filetxt[i], line_number);
    if (outputComments != "") {
      outputFile << outputComments << std::endl;
    }
    line_number++;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}