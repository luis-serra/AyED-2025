#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Declarar una clase Sensor que tenga un nombre (string), valor (flotante) y unidad (string)
// Metodos para mostrar el sensor, cambiar el valor, cambiar el nombre.

class Sensor {
private:
    std::string nombre;
    float valor;
    std::string unidad;
public:
    void mostrar();
    void cambiarValor(float nuevoValor);
    void cambiarNombre(const std::string& nuevoNombre); 
};
#endif
