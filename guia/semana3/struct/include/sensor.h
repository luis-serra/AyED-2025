#ifndef SENSOR_H
#define SENSOR_H

#include <string>
using namespace std;

// Declarar un struct Sensor que tenga un nombre (string), valor (flotante) y unidad (string
struct Sensor {
    string nombre;
    float valor;
    string unidad;
};
// Prototipos
void imprimir(const Sensor* lista, int n);

int cargarDesdeArchivo(const std::string& ruta, Sensor* lista, int n);

float promedioValores(const Sensor* lista, int n, std::string unidad);

int contarSensores(const Sensor* lista, int n, std::string unidad);

#endif