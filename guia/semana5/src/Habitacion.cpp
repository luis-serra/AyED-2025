#include "Habitacion.h"
#include <iostream>

// ===== Constructores / básicos =====
Habitacion::Habitacion() : nombre("sin_nombre") {}
Habitacion::Habitacion(const std::string& n) : nombre(n) {}

const std::string& Habitacion::getNombre() const { return nombre; }
void Habitacion::setNombre(const std::string& n) { nombre = n; }

int  Habitacion::cantidadSensores() const { return (int)sensores.size(); }
bool Habitacion::vacia() const { return sensores.empty(); }

void Habitacion::agregarSensor(const Sensor& s) { sensores.push_back(s); }
void Habitacion::agregarSensor(const std::string& n, const std::string& u) {
    sensores.push_back(Sensor(n, u));
}

// ===== Helpers recursivos (head / tail) =====

void Habitacion::mostrarRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase) const {
    //DONE: imprimir la cabeza y llamar a la recursión con el resto
    if (it == fin){
        return;
    }else{
        std::cout << "Sensor[" << idxBase << "]" <<it->getNombre() << ": " << it->getValor() << " " << it->getUnidad() << std::endl;
        mostrarRec(std::next(it),fin,idxBase+1);
    }
}

int Habitacion::indiceDeRec(std::vector<Sensor>::const_iterator it,
                            std::vector<Sensor>::const_iterator fin,
                            int idxBase,
                            const std::string& nombreSensor) const {
    //DONE: devolver índice si la cabeza coincide, o recursión con el resto
    if (it->getNombre() == nombreSensor) return idxBase;
    if (it == fin) return -1;
    else{
        return indiceDeRec(std::next(it), fin, idxBase+1, nombreSensor);
    }
}

bool Habitacion::setValorRec(std::vector<Sensor>::iterator it,
                             std::vector<Sensor>::iterator fin,
                             const std::string& nombreSensor,
                             float nuevoValor) {
    //DONE: si la cabeza coincide cambiar valor, si no, recursión con el resto
    if (it->getNombre() == nombreSensor){
        it->setValor(nuevoValor);
        return true;
    }
    if (it == fin) return false;
    else{
        return setValorRec(std::next(it), fin, nombreSensor, nuevoValor);
    }
    return false;
}

bool Habitacion::setNombreRec(std::vector<Sensor>::iterator it,
                              std::vector<Sensor>::iterator fin,
                              const std::string& nombreActual,
                              const std::string& nombreNuevo) {
    //DONE: si la cabeza coincide cambiar nombre, si no, recursión con el resto
    if (it->getNombre() == nombreActual){
        it->setNombre(nombreNuevo);
        return true;
    }
    if (it == fin) return false;
    else{
        return setNombreRec(std::next(it), fin, nombreActual, nombreNuevo);
    }
    return false;
}

const Sensor* Habitacion::obtenerConstRec(std::vector<Sensor>::const_iterator it,
                                          std::vector<Sensor>::const_iterator fin,
                                          const std::string& nombreSensor) const {
    //DONE: devolver puntero al sensor si coincide, si no, recursión con el resto
    if (it->getNombre() == nombreSensor) return &(*it);
    if (it == fin) return nullptr;
    else{
        return obtenerConstRec(std::next(it), fin, nombreSensor);
    }
    return nullptr;
}

Sensor* Habitacion::obtenerRec(std::vector<Sensor>::iterator it,
                               std::vector<Sensor>::iterator fin,
                               const std::string& nombreSensor) {
    //DONE: devolver puntero al sensor si coincide, si no, recursión con el resto
    if (it->getNombre() == nombreSensor) return &(*it);
    if (it == fin) return nullptr;
    else{
        return obtenerRec(std::next(it), fin, nombreSensor);
    }
    return nullptr;
}

bool Habitacion::eliminarPorNombreRec(std::vector<Sensor>::iterator it,
                                      std::vector<Sensor>::iterator fin,
                                      const std::string& nombreSensor) {
    //DONE: si la cabeza coincide, borrar con erase; si no, recursión con el resto
    if (it->getNombre() == nombreSensor){
        sensores.erase(it);
        return true;
    }
    if (it == fin) return false;
    else{
        return eliminarPorNombreRec(std::next(it), fin, nombreSensor);
    }
    return false;
}

// ===== API pública (envoltorios) =====

void Habitacion::mostrar() const {
    std::cout << "Habitacion: " << nombre << "\n";
    if (sensores.empty()) { std::cout << "  (sin sensores)\n"; return; }
    mostrarRec(sensores.begin(), sensores.end(), 0);
}

int Habitacion::indiceDe(const std::string& nombreSensor) const {
    return indiceDeRec(sensores.begin(), sensores.end(), 0, nombreSensor);
}

bool Habitacion::existeSensor(const std::string& nombreSensor) const {
    return indiceDe(nombreSensor) != -1;
}

bool Habitacion::setValor(const std::string& nombreSensor, float nuevoValor) {
    return setValorRec(sensores.begin(), sensores.end(), nombreSensor, nuevoValor);
}

bool Habitacion::setNombreSensor(const std::string& nombreActual, const std::string& nombreNuevo) {
    return setNombreRec(sensores.begin(), sensores.end(), nombreActual, nombreNuevo);
}

const Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) const {
    return obtenerConstRec(sensores.begin(), sensores.end(), nombreSensor);
}

Sensor* Habitacion::obtenerSensor(const std::string& nombreSensor) {
    return obtenerRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorNombre(const std::string& nombreSensor) {
    return eliminarPorNombreRec(sensores.begin(), sensores.end(), nombreSensor);
}

bool Habitacion::eliminarSensorPorIndice(int idx) {
    if (idx < 0 || idx >= (int)sensores.size()) return false;
    sensores.erase(sensores.begin() + idx);
    return true;
}
