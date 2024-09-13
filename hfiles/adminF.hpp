#ifndef ADMINFUNC_H
#define ADMINFUNC_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
//#include <conio.h>

void deleteLine(const char *archivo, int n) { //Borra una línea del .txt
    std::ifstream is(archivo); 
    std::ofstream ofs; 
    ofs.open("temp.txt",std:: ofstream::out); 
    char c; 
    int line_no = 1; 
    while (is.get(c)) 
    { 
        if (c == '\n') 
        line_no++; 
  
        if (line_no != n) 
            ofs << c; 
    } 
    ofs.close(); 
    is.close(); 

    remove(archivo); 

    rename("temp.txt", archivo); 
} 

void listaUsuarios(){ //Imprime a los usuarios registrados y sus roles
    std::ifstream file("BD.txt"); //Recibe el .txt de los datos de usuarios
    std::string line;
    std::string temp;
    int i;

    while (getline(file, line)) { //Loop para cada linea que lee
        i=0;
        while(line[i] != ';'){ //Loop para cargar el temp string con el nombre de usuario
            temp += line[i];
            i++;
        }
        i++;
        std::cout << "Usuario: " << temp << "   ";
        while(line[i] != ';'){ //Loop para saltarse el codigo del usuario
            i++;
        }
        temp.clear();
        i++;
        if(line[i]=='A'){ //Si la primera letra es "A", se sabe que es admin y se realizan las acciones correspondientes
            std::cout << "Rol: Admin" << std::endl;
        }else{
            std::cout << "Rol: Usuario genérico" << std::endl;
        }
    }
    return;
}

void addUsuario(){
    std::string line;
    std::string password;
    std::string secure;
    std::string usuario;
    std::string rol;
    int i=0;
    bool letra = false;
    bool num = false;
    bool check = false;

    std::cout << "Ingrese el nombre del usuario que quiere registrar: ";
    std::cin >> usuario;
    while(check==false){
        if(usuario == "0"){return;}
        for(i=0; i<int(usuario.length()); i++){
            if(isalpha(usuario[i])==false){
                std::cout << "Usuario solo debe tener letras alfabéticas, ingrese de nuevo: ";
                std::cin >> usuario;
                if(usuario == "0"){return;}
                break;
            }
        }
        if(i<3){
            std::cout << "Usuario debe tener al menos 3 letras, ingrese de nuevo: ";
            std::cin >> usuario;
        }else{check=true;}
    }

    check = false;
    std::cout << "Ingrese el nombre la contraseña: ";
    std::cin >> password;
    while(check==false){
        if(password == "0"){return;}
        for(i=0; i<int(password.length()); i++){
            if(isalpha(password[i])){letra=true;}
            if(isdigit(password[i])){num=true;}
        }
        if(letra==false || num==false){
            std::cout << "Contraseña debe tener sólo letras y números, ingrese de nuevo: ";
            std::cin >> password;
            if(password == "0"){return;}
        }else{
            if(i<6){
                std::cout << "Usuario debe tener al menos 6 letras con números, ingrese de nuevo: ";
                std::cin >> password;
                if(password == "0"){return;}
            }else{check=true;}
        }
    }

    check = false;
    std::cout << "Repita la contraseña ingresada: ";
    std::cin >> secure;
    while(check==false){
        if(secure!=password){
            if(secure == "0"){return;}
            std::cout << "Contraseñas no coinciden, reintentar: ";
            std::cin >> secure;
        }else{check=true;}
    }

    while(true){ //Loop that breaks if the answer is "s" or "n"
        std::cout << "Su rol es de admin? [s/n]: ";
        std::cin >> rol;
        if(rol == "0"){return;}

        if(rol=="n" || rol=="s"){ break; }
        else{
            std::cout << "Escriba 's' para que que sea admin, 'n' para que no " << std::endl;
        }
    }if(rol=="s"){
        line = usuario + ";" + password + ";Admin"; 
    }else{line = usuario + ";" + password + ";Usuario genérico"; }
    std::ofstream file;
    file.open("BD.txt", std::ios_base::app);
    file << line << '\n';
    std::cout << "Usuario " << usuario << " agregado exitosamente" << std::endl;
    return;
}

void eliminarUsuario(){
    std::ifstream file("BD.txt"); //Recibe el .txt de los datos de usuarios
    std::string line;
    std::string nombre;
    std::string temp;
    std::string check="null";
    int i; //Contador de caracter recorrido
    int n=0; //Contador de la linea a eliminar

    std::cout << "Ingrese el nombre de usuario a remover: ";
    std::cin >> nombre;
    if(nombre == "0"){return;}

    while (getline(file, line)) {
        if(check=="null"){n++;}
        i=0;
        temp.clear();
        while(line[i] != ';'){ //Loop para cargar el temp string con el nombre de usuario
            temp += line[i];
            i++;
        }
        if(temp==nombre){
            while(true){ //Corrobora si el usuario quiere eliminar a otro o no
                std::cout << "De verdad quiere eliminar el usuario? [s/n] ";
                std::cin >> check;
                if(check=="n" || check=="s"){ break; }
                else{
                    std::cout << "Escriba 's' para que que sea admin, 'n' para que no " << std::endl;
                }
            }
        }
    }
    if(check=="null"){ //Regresa si no hay usuario
        std::cout << "Nombre no se encuentra en la lista. " << std::endl;
        return;
    }
    if(check=="n"){ //Regresa si el usuario se arrepiente
        return; 
    }else if(check=="s"){
        deleteLine("BD.txt", n); //Función de eliminar línea
        std::cout << "Usuario eliminado exitosamente" << std::endl;
    }
    return;
}
#endif