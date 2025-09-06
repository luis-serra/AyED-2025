#include <iostream>
#include "../include/sensor.h"

using namespace std;

int main() {
    // Instancia un objeto de la clase Sensor

    Sensor* sHabitacion = new Sensor;
    
    sHabitacion->mostrar();

    sHabitacion->cambiarValor(30.5);
    sHabitacion->mostrar();

    return 0;
}
