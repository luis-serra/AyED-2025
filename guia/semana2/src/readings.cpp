#include "readings.h"
#include <iostream>
#include <fstream>
#include <new>        // std::nothrow
#include <iomanip>    // std::setprecision

float* crear_arreglo(int size) {
    if (size <= 0) {
        return nullptr;
    }
    return new float[size];
}

void liberar_arreglo(float*& arr) {
    //TODO
}

int cargar_desde_archivo(const std::string& ruta, float* arr, int size) {
    //TODO
}

bool guardar_en_archivo(const std::string& ruta, const float* arr, int size) {
    // TODO
}

void imprimir(const float* arr, int size) {
    // TODO
}
