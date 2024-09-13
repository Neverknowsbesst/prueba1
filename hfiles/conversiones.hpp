#ifndef CONVERSIONES_H
#define CONVERSIONES_H
#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>

std::string convertToString(char* a, int size) //Función para convertir un char array a string
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
std::vector<std::string> convertToVector(char* a, int size){ //Pasa de char array a vector de string
    std::string palabra = convertToString(a, size);
    std::vector<std::string> vec;
    std::stringstream ss(palabra);
    std::string s;
    while(getline(ss,s, ' ')){ //Loop que recorre el string, y si es que hay un espacio entonces ingresa letras consecutivas en un puntero del vector
        vec.push_back(s);
    }
    return vec;
}
#endif