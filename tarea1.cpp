#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "hfiles/usuarios.hpp"
#include "hfiles/terminal.hpp"
#include "hfiles/adminF.hpp"
#include <getopt.h>

using namespace std;
std::ifstream ifs;

int main (int argc, char* argv[]){
    int c;
    int k=0;
    int j=0;
    int i=0;
    int v=0;
    int h=0;
    int n=0;
    string p;
    string derechos;
    vector<float> vec; //Vector que va a contener los números a sumar y promediar
    float numeros; //int que contiene el número ingresado
    char *password; //Char array que contiene la contraseña
    char *usuario; //Char array coneninendo el nombre de usuario
    char *frase; //Char array de la frase ingresada
    char *numChar; //Char array de numeros
    char *vecChar; //Variables para obtener los datos del puntero a un data type utilizable
    
    while((c=getopt(argc,argv, "u:p:t:v:n:"))!=-1){ //Recolección de argumentos de línea
        switch(c){
         case 'u': //Ingreso de nombre de usuario
         {
            ifs.open(optarg, std::ifstream::in);
            usuario = optarg; //'usuario' se utlizará para el login
            ifs.close();
            while(usuario[k] != '\0'){ //Mientras no sea NULL va a agregar datos
                k++;
            }
            break;
         }
         case 'p': //Ingreso de contraseña de usuario
         {
            ifs.open(optarg, std::ifstream::in);
            password = optarg; //'password' se utlizará para el login
            ifs.close();
            while(password[j] != '\0'){ //Mientras no sea NULL va a agregar datos
                j++;
            }
            break;
         }
         case 't': //Ingreso de frase 
         {
            ifs.open(optarg, std::ifstream::in);
            frase = optarg;
            ifs.close();
            while(frase[i] != '\0'){ //Mientras no sea NULL va a agregar datos
                i++;
            }
            break;
         }
         case 'v': //Ingreso de vector
         {
            ifs.open(optarg, std::ifstream::in);
            vecChar = optarg;
            ifs.close();
            while(vecChar[v] != '\0'){ //Mientras no sea NULL va a agregar datos
                if(isdigit(vecChar[v])){ //Si es un digito, agrega a un contador
                    h++;
                }else if(vecChar[v] == '.'){
                    h++;
                }   
                else{ //Si es un caracter no numérico, ingresa el número anterior a un vector
                    while(h!=0){ //Loop que agrega de a 1 los digitos a un string
                        p = p + vecChar[v-h]; //Agrega un número de a un digito, de izquierda a derecha
                        h--;
                    }
                    vec.push_back(stoi(p)); //Agrega el string como int al vector con stoi()
                    p.clear(); //Borra los contenidos del string para la siguiente iteración
                }
                v++;
            }
            v = v/2 - 1 ;
            break;
         }
         case 'n': //Ingreso de número
         {
            ifs.open(optarg, std::ifstream::in);
            numChar = optarg;
            ifs.close();
            while(numChar[n] != '\0'){ //Mientras no sea NULL va a agregar datos
                n++;
            }
            numeros = atof(numChar); //Transforma los datos del int array a un único int
            break;
         }
        }
    }
    derechos = esUsuario(usuario, password, k, j); //Usa la función de usuarios.hpp
    cout<<derechos;
    if(derechos == "null"){ //Caso en que el usuario no exista en el sistema
        cout << "Usuario erróneo, ingrese el comando otra vez" << endl;
        return 0;
    }else if(derechos=="admin"){
        adminTerminal(i, v, n, vec, frase, numeros, vecChar, usuario, k); //Usa la función para administradores en terminal.hpp
    }else{
        userTerminal(i, v, n, vec, frase, numeros, vecChar, usuario, k); //Usa la función para usuarios generales en terminal.hpp
    }
    return 0;
}