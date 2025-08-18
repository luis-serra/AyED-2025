#include "readings.h"
#include <iostream>
#include <fstream>
#include <string>
#include <new>        // std::nothrow
#include <iomanip>    // std::setprecision
using namespace std;

float* crear_arreglo(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new float[size];
}

void liberar_arreglo(float*& arr) {
    delete[] arr;
    arr = nullptr;
}

int cargar_desde_archivo(const std::string& ruta, float* arr, int size) {
 ifstream archivoLecturas(ruta);
    if(!archivoLecturas.is_open()){
      return 0;
    }
    int count = 0;
    while (count < size && archivoLecturas >> arr[count]) {
       count ++;
    }
    archivoLecturas.close();
    return count;
}

bool guardar_en_archivo(const std::string& ruta, const float* arr, int size) {
    ofstream archivoSalida(ruta);
    if(!archivoSalida.is_open()){
      return false;
    }
    for (int i = 0; i < size; i++) {
      archivoSalida << arr[i] << "\n";
    }
    archivoSalida.close();
    return true;
}

void imprimir(const float* arr, int size) {
    cout << "lecturas obtenidas:\n";
    for (int i = 0; i < size; i++) {
      cout << arr[i] << "\n";
    }
}
