#include <iostream>
#include <fstream>
#include <filesystem>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <unistd.h>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

void contarPalabrasEnArchivo(const fs::path& archivo, map<string, int>& conteoPalabras) {
    ifstream archivoEntrada(archivo);
    string palabra;

    while (archivoEntrada >> palabra) {
        // Normaliza la palabra (puedes agregar más normalizaciones si lo deseas)
        transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
        conteoPalabras[palabra]++;
    }
}

void procesarArchivos(const fs::path& carpetaEntrada, const fs::path& carpetaSalida, const string& extension) {
    if (!fs::exists(carpetaEntrada) || !fs::is_directory(carpetaEntrada)) {
        cerr << "La carpeta de entrada no existe o no es un directorio." << endl;
        return;
    }

    if (!fs::exists(carpetaSalida)) {
        fs::create_directory(carpetaSalida);
    }
    int archivosProcesados = 0;
    for (const auto& archivo : fs::directory_iterator(carpetaEntrada)) {
        if (archivo.path().extension() == extension) {

            archivosProcesados++;
            map<string, int> conteoPalabras;
            contarPalabrasEnArchivo(archivo.path(), conteoPalabras);

            ofstream archivoSalida(carpetaSalida / archivo.path().filename());
            for (const auto& [palabra, conteo] : conteoPalabras) {
                archivoSalida << palabra << ";" << conteo << endl;
            }

            cout << "archivo " << (carpetaSalida / archivo.path().filename()).string()
                 << ", " << conteoPalabras.size() << " palabras distintas" << endl;
        }
    }
    if (archivosProcesados == 0) {
        cout << "No se encontraron archivos con la extensión " << extension 
             << " en la carpeta " << carpetaEntrada << endl;
    }
}

int main() {
    cout << "PID: " << getpid() << endl;

    string extension, carpetaEntrada, carpetaSalida;

    cout << "Ingrese la extensión de archivos a procesar (por ejemplo, .txt): ";
    cin >> extension;
    cout << "Ingrese el path de la carpeta a procesar: ";
    cin >> carpetaEntrada;
    cout << "Ingrese el path de la carpeta que contendrá la respuesta: ";
    cin >> carpetaSalida;
    

    if (extension.empty() || carpetaEntrada.empty() || carpetaSalida.empty()) {
        cerr << "Debe ingresar todos los datos." << endl;
        return 1;
    }

    procesarArchivos(carpetaEntrada, carpetaSalida, extension);

    return 0;
}
