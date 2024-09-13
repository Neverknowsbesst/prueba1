#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "conversiones.hpp"

void esPalindromo(char* p, int sizeT){ //Busca palíndromos en la frase
    std::vector<std::string> palabra = convertToVector(p, sizeT);
    for(int t=0; t < int(palabra.size()); t++){
        for(int i=0; i < int(palabra[t].length()/2); i++){
            if(palabra[t][i] != palabra[t][palabra[t].length()-i-1]){ //Si la letra x de izquierda a derecha es distinta a la letra x de derecha a izquierda
                std::cout << "La palabra '" << palabra[t] << "' no es palíndromo." << std::endl;  //ya no es palíndromo por lo tanto termina la iteración
                break;
            }
            if(i+1==int(palabra[t].length()/2)){
                std::cout << "La palabra '" << palabra[t] << "' es palíndromo." << std::endl;
            }
        }
    }
    return;
}

bool esVocal(char letra){
    letra = toupper(letra);
    return((letra=='A') || (letra=='E') || (letra=='I') || (letra=='O') || (letra=='U'));
    
} 

void vocales (char* ch, int sizeT){ //Función principal para buscar vocales
    int numVocales = 0;
    for (int i=0; i<sizeT; i++){
        while(ch[i] ==' '){i++;} //mientras el caracter sea un espacio, lo salta
        if(ch[i] == '\0'){break;} //Termina las iteraciones si el caracter no está en el rango
        if (esVocal(ch[i])){
            ++numVocales;
        }
    }
    std::cout << "La frase escrita '" << ch << "' tiene " << numVocales << " vocales." << std::endl;
}

void letras(char* ch, int sizeT){
    int letra = 0;
    std::string frase = convertToString(ch, sizeT);
    for(int i=0; i<sizeT; i++){
        if(isalpha(frase[i])){letra++;}
    }
    std::cout << "La frase '" << ch << "' tiene " << letra << " letras." << std::endl;
}

float calculo(float num){ //Calcula el numero ingresado para la opción 5
    float resultado = 5*num*num; 
    resultado += float(1)/float(num);
    return resultado;
}

float sumVector(std::vector<float> numeros, int size){ //Devuelve la sumatoria de números en el vector ingresado
    float resultado = 0;
    for(int i=0; i<=size; i++){
        resultado += numeros[i];
    }
    return resultado;
}

float promVector(std::vector<float> numeros, int size){ //Devuelve el promedio de números en el vector ingresado
    float resultado = 0;
    for(int i=0; i<=size; i++){
        resultado += numeros[i];
    }
    resultado = resultado/(size+1);
    return resultado;
}
// Función para contar palabras en un archivo
void contarPalabras() {
    // Implementar el proceso externo aquí
    system("./contar_palabras");
}


#endif