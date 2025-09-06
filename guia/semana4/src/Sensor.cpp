#include "Sensor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sensor::Sensor(std::string nombre, std::string unidad) {
    this->nombre = nombre;
    this->valor = 0;
    this->unidad = unidad;
}

std::string Sensor::getNombre(){
    return nombre;
}

void Sensor::setNombre(std::string nombreNuevo){
    nombre = nombreNuevo;
}


float Sensor::getValor(){
    return valor;
}

void Sensor::setValor(float valorNuevo){
    valor = valorNuevo;
}

std::string Sensor::getUnidad(){
    return unidad;
}