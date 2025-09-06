#include "sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void Sensor::mostrar(){
    cout << nombre << " " << valor << " " << unidad << endl;
}

void Sensor::cambiarValor(float nuevoValor){
    valor = nuevoValor;
}

void Sensor::cambiarNombre(const std::string nuevoNombre){
    nombre = nuevoNombre;
}