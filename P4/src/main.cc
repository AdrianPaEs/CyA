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

#include <regex>
#include <iostream>
#include <fstream>  // Añadido para manejar archivos
#include <string>
using namespace std;

void printUsage()
{
    std::cout << "Uso: ./p04_code_analyzer <fichero_entrada> <fichero_salida>\n";
}

int main(int argc, char *argv[])
{
    // Verificar número de argumentos
    if (argc != 3)
    {
        std::cout << "ERROR: Número incorrecto de parámetros" << std::endl; 
        printUsage();
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cout << "Error: No se puede abrir el fichero de entrada: " << inputFileName << std::endl; 
        return 1;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cout << "Error: No se puede crear el fichero de salida: " << outputFileName << "\n"; // Cambiado a std::cerr
        return 1;
    }

    std::string line;
    std::string content;
    while (std::getline(inputFile, line)) {
        content += line + "\n"; // Agrega la línea al contenido y un salto de línea
    }

    // Muestra el contenido
    std::cout << "Contenido del archivo:\n" << content;

    inputFile.close();
    outputFile.close();
    return 0;
}
