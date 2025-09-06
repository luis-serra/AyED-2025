#include "Recinto.h"
#include <iostream>

Recinto::Recinto(std::string nombre, int nSensores){
    this->nombre = nombre;
    this->nSensores = nSensores;
    this->sensores = new Sensor*[nSensores];
    for(int i=0; i<nSensores; i++) {
        this->sensores[i] = nullptr;
    }
}

Recinto::~Recinto(){
    delete[] sensores;
}

std::string Recinto::getNombre(){
    return nombre;
}

int Recinto::getCantSensores(){
    return nSensores;
}

void Recinto::setNombre(std::string nombreNuevo){
    this->nombre = nombreNuevo;
}

// ------------------ RECURSIVOS ------------------

float Recinto::_suma(Sensor** v, int n, std::string unidad){
    if(n == this->nSensores) return 0.0;
    if (v[n] != nullptr && v[n]->getUnidad() == unidad)
        return v[n]->getValor() + _suma(v, n+1, unidad);
    else
        return _suma(v, n+1, unidad);
}

int Recinto::_maximo(Sensor** v, int n, std::string unidad, int mejorPos){
    if(n==this->nSensores) return mejorPos;
    else {
        if (v[n]!=nullptr && v[n]->getUnidad()==unidad) {
            if (mejorPos == -1 || v[n]->getValor() > v[mejorPos]->getValor())
                return _maximo(v,n+1,unidad,n);
            else
                return _maximo(v,n+1,unidad,mejorPos);
        } else {
            return _maximo(v,n+1,unidad,mejorPos);
        }
    }
}

int Recinto::_buscar(Sensor** v, int n, const std::string& key){
    //TODO
}

Sensor* Recinto::_getSensor(Sensor** v, int n, int posBuscada){
    //TODO
}
