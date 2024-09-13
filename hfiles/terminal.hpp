#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include <vector>
#include "funciones.hpp"
#include "conversiones.hpp"
#include "adminF.hpp"

void userTerminal(int i, int v, int n, std::vector<float> vec, char *frase, float numeros, char *vecChar, char* us, int sizeU){
    std::string usuario = convertToString(us, sizeU);
    std::cout << "-------------------------" << std::endl;
    std::cout << "SISTEMA " <<  getpid() << std::endl;
    std::cout << "Nombre de usuario: " << usuario << std::endl;
    std::cout << "Rol: Usuario genérico" << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "0 . Salir" << std::endl;
    if(i!=0){ 
        std::cout << "1 . Detectar palíndromos" << std::endl;
        std::cout << "2 . Contar vocales" << std::endl;
        std::cout << "3 . Contar letras" << std::endl;
    }
    if(v!=0){ std::cout << "4 . Promediar y sumar vector" << std::endl; }
    if(n!=0){ std::cout << "5 . Calcular 5x*x+1/x" << std::endl; }
    std::cout << "6 . Contar palabras" << std::endl;
    std::cout << "-------------------------" << std::endl;

    int var;
    std::cout << "Ingrese opción: ";
    std::cin >> var;
    int z = 0;
    
    while(z==0){ //Loop infinito que solo se puede salir si se usa el comando en pantalla para cerrar el programa
        while(0>var || var>6){ //Caso en que se ingrese un input que no corresponde a las opciones
            std::cout << "Error, ingrese el número de alguna de las opciones en pantalla" << std::endl;
        std::cout << ">";
            std::cin >> var;
        }
        std::cout << var << std::endl;
        switch(var){ //Opciones que se pueden ejecutar
            case 1 : //Detecta palíndromos
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                esPalindromo(frase, i); //Llama a función en funciones.hpp
                break;
            case 2 : //Contar vocales
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                vocales(frase, i); //Llama a función en funciones.hpp
                break;
            case 3 : //Cantidad de letras
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                letras(frase, i);
                break;
            case 4 : //Calcula lo del vector
                if(v==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                std::cout << "Sea el vector ingresado '" << vecChar << "'" << std::endl;
                std::cout << "La suma de los números del vector: " << sumVector(vec, v) << std::endl;
                std::cout << "El promedio de los números del vector: " << promVector(vec, v) << std::endl;
                break;
            case 5 : //Realiza el cálculo
                if(n==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                std::cout << "El resultado al ingresar " << numeros << " a la función, es " << calculo(numeros) << std::endl;
                    break;
            case 6 : 
                contarPalabras(); //Llama a función en adminF.hpp
                break;
            case 0 : //Sale del programa y lo apaga
                return;
        }
        std::cout << "-------------------------" << std::endl;
        std::cout << "Desea realizar otra operación?" << std::endl;
        std::cout << "1. Si      2. No" << std::endl;
        std::cout << ">";
        std::cin >> var;
        while(var<1 || var>2){
            std::cout << "Ingrese '1' para aceptar ó '2' para declinar" << std::endl;
            std::cout << ">";
            std::cin >> var;
        }
        if(var==2){
            return;
        } else{
            std::string usuario = convertToString(us, sizeU);
        std::cout << "###########################" << std::endl;
        std::cout << "SISTEMA " <<  getpid() << std::endl;
        std::cout << "Nombre de usuario: " << usuario << std::endl;
        std::cout << "Rol: Usuario genérico" << std::endl;

        std::cout << "-------------------------" << std::endl;
        std::cout << "0 . Salir" << std::endl;
        if(i!=0){ 
            std::cout << "1 . Detectar palíndromos" << std::endl;
            std::cout << "2 . Contar vocales" << std::endl;
            std::cout << "3 . Contar letras" << std::endl;
        }
        if(v!=0){ std::cout << "4 . Promediar y sumar vector" << std::endl; }
        if(n!=0){ std::cout << "5 . Calcular 5x*x+1/x" << std::endl; }
        std::cout << "6 . Contar palabras" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cout << "Ingrese opción: ";
        std::cin >> var;
            }
        }
    return;
}

void adminTerminal(int i, int v, int n, std::vector<float> vec, char *frase, float numeros, char *vecChar, char* us, int sizeU){
    std::string usuario = convertToString(us, sizeU);
    std::cout << "-------------------------" << std::endl;
    std::cout << "SISTEMA " <<  getpid() << std::endl;
    std::cout << "Nombre de usuario: " << usuario << std::endl;
    std::cout << "Rol: Usuario genérico" << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "0 . Salir" << std::endl;
    if(i!=0){ 
        std::cout << "1 . Detectar palíndromos" << std::endl;
        std::cout << "2 . Contar vocales" << std::endl;
        std::cout << "3 . Contar letras" << std::endl;
    }
    if(v!=0){ std::cout << "4 . Promediar y sumar vector" << std::endl; }
    if(n!=0){ std::cout << "5 . Calcular 5x*x+1/x" << std::endl; }
    std::cout << "6 . Contar palabras" << std::endl;
    std::cout << "7 . Listar Usuarios" << std::endl;
    std::cout << "8 . Añadir usuarios" << std::endl;
    std::cout << "9 . Eliminar usuarios" << std::endl;
    std::cout << "-------------------------" << std::endl;

    int var;
    std::cout << "Ingrese opción: ";
    std::cin >> var;
    int z = 0;
    
    while(z==0){ //Loop infinito que solo se puede salir si se usa el comando en pantalla para cerrar el programa
        while(0>var || var>9){ //Caso en que se ingrese un input que no corresponde a las opciones
            std::cout << "Error, ingrese el número de alguna de las opciones en pantalla" << std::endl;
        std::cout << ">";
            std::cin >> var;
        }
        std::cout << var << std::endl;
        switch(var){ //Opciones que se pueden ejecutar
            case 1 : //Detecta palíndromos
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                esPalindromo(frase, i); //Llama a función en funciones.hpp
                break;
            case 2 : //Contar vocales
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                vocales(frase, i); //Llama a función en funciones.hpp
                break;
            case 3 : //Cantidad de letras
                if(i==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                letras(frase, i);
                break;
            case 4 : //Calcula lo del vector
                if(v==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                std::cout << "Sea el vector ingresado '" << vecChar << "'" << std::endl;
                std::cout << "La suma de los números del vector: " << sumVector(vec, v) << std::endl;
                std::cout << "El promedio de los números del vector: " << promVector(vec, v) << std::endl;
                break;
            case 5 : //Realiza el cálculo
                if(n==0){
                    std::cout << "Acceso denegado" << std::endl;
                    break;
                }
                std::cout << "El resultado al ingresar " << numeros << " a la función, es " << calculo(numeros) << std::endl;
                    break;
            case 6 : //Listar usuarios
                contarPalabras(); //Llama a función en adminF.hpp
                break;
            case 7 : //Listar usuarios
                listaUsuarios(); //Llama a función en adminF.hpp
                break;
            case 8 : //Listar usuarios
                addUsuario(); //Llama a función en adminF.hpp
                break;
            case 9 : //Eliminar usuario
                eliminarUsuario();
                break;
            case 0 : //Sale del programa y lo apaga
                return;
        }
        std::cout << "-------------------------" << std::endl;
        std::cout << "Desea realizar otra operación?" << std::endl;
        std::cout << "1. Si      2. No" << std::endl;
        std::cout << ">";
        std::cin >> var;
        while(var<1 || var>2){
            std::cout << "Ingrese '1' para aceptar ó '2' para declinar" << std::endl;
            std::cout << ">";
            std::cin >> var;
        }
        if(var==2){
            return;
        } else{
            std::string usuario = convertToString(us, sizeU);
        std::cout << "###########################" << std::endl;
        std::cout << "SISTEMA " <<  getpid() << std::endl;
        std::cout << "Nombre de usuario: " << usuario << std::endl;
        std::cout << "Rol: Usuario genérico" << std::endl;

        std::cout << "-------------------------" << std::endl;
        std::cout << "0 . Salir" << std::endl;
        if(i!=0){ 
            std::cout << "1 . Detectar palíndromos" << std::endl;
            std::cout << "2 . Contar vocales" << std::endl;
            std::cout << "3 . Contar letras" << std::endl;
        }
        if(v!=0){ std::cout << "4 . Promediar y sumar vector" << std::endl; }
        if(n!=0){ std::cout << "5 . Calcular 5x*x+1/x" << std::endl; }
        std::cout << "6 . Contar palabras" << std::endl;
        std::cout << "7 . Listar Usuarios" << std::endl;
        std::cout << "8 . Añadir usuarios" << std::endl;
        std::cout << "9 . Eliminar usuarios" << std::endl;
        std::cout << "-------------------------" << std::endl;

        std::cout << "Ingrese opción: ";
        std::cin >> var;
            }
        }
    return;
}
#endif