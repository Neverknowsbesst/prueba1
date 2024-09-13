#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // Para getenv()
#include "conversiones.hpp"

std::string esUsuario(char* n, char* c, int sizeU, int sizeP) { // Detecta si el usuario existe o no
    std::string nombre = convertToString(n, sizeU);
    std::string codigo = convertToString(c, sizeP); // Transforma el char array a string

    // Obtén la ruta del archivo desde la variable de entorno
    const char* envPath = std::getenv("BD_PATH");
    if (envPath == nullptr) {
        std::cerr << "Variable de entorno BD_PATH no esta configurada." << std::endl;
        return "null";
    }
    
    std::ifstream file(envPath); // Usa la ruta obtenida para abrir el archivo
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << envPath << std::endl;
        return "null";
    }

    std::string line;
    std::string pass;
    int v = 0;
    while (getline(file, line)) { // Recorre todas las líneas del archivo
        if (line.find(nombre) != std::string::npos) { // Se ejecuta si se encuentra el nombre de usuario ingresado
            while (line[v] != ';') { // Recorre la porción de nombre de usuario de la línea
                v++;
            }
            v++;
            while (line[v] != ';') { // Graba la contraseña relacionada con el usuario
                pass += line[v];
                v++;
            }
            v++;
            if (pass == codigo) {
                if (line[v] == 'A') {
                    return "admin";
                } else {
                    return "usuario";
                }
            } else {
                std::cout << "Usuario no registrado" << std::endl;
                return "null";
            }
        }
    }
    return "null";
}

#endif
