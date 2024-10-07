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
#include <fstream>
#include <string>

#include "../include/codigo.h"

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
    Codigo variables;
    Codigo bucles; 

    outputFile << "PROGRAMM: " << argv[1] << std::endl; // Mostramos nombre del programa

    outputFile << "\nDESCRIPTION: " << std::endl; // Mostramos descripción del programa
    int line_number = 1;
    std::string outputComments;
    while (std::getline(inputFile, line)) {
        //Comentarios
        outputComments = variables.ObtainComments(line,line_number);
        if (outputComments != ""){
            outputFile << outputComments << std::endl;
        }
        line_number++;
    }


    line_number = 1;
    std::string outputInt;
    std::string outputDouble;
    outputFile << "\nVARIBALES: " << argv[1] << std::endl;
    while (std::getline(inputFile, line)) {
        //Variables Int
        outputInt = variables.ObtainInt(line,line_number);
        if (outputInt != ""){
            outputFile << outputInt << std::endl;
        }
        //Variables Double
        outputDouble = variables.ObtainDouble(line,line_number);
        if (outputDouble != ""){
            outputFile << outputDouble << std::endl;
        }
        line_number++;
    }

    line_number = 1;
    std::string outputFor;
    std::string outputWhile;
    outputFile << "\nSTATEMENTS: " << std::endl;
    while (std::getline(inputFile, line)) {
        //Bucle For
        outputFor = bucles.ObtainFor(line,line_number);
        if (outputFor != ""){
            outputFile << outputFor << std::endl;
        }
        //Bucle While
        outputWhile = bucles.ObtainWhile(line,line_number);
        if (outputWhile != ""){
            outputFile << outputWhile << std::endl;
        }
        line_number++;
    }

    line_number = 1;
    std::string outputMain;
    outputFile << "\nMAIN: " << std::endl;
    while (std::getline(inputFile, line)) {
        outputMain = variables.ObtainMain(line,line_number);
        outputFile << outputMain << std::endl;
    }

    outputFile << "\nCOMMENTS: " << std::endl;


    inputFile.close();
    outputFile.close();
    return 0;
}