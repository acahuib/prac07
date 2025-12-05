// main_threadsafe.cpp
#include <iostream>
#include <thread>
#include "ConexionBD_threadsafe.h"

void tarea(int id) {
    ConexionBD* c = ConexionBD::getInstancia();
    std::cout << "Hilo " << id << " obtiene instancia: " << c << std::endl;
    c->conectar();
    c->estado();
    c->desconectar();
}

int main() {
    std::thread h1(tarea, 1);
    std::thread h2(tarea, 2);
    std::thread h3(tarea, 3);

    h1.join();
    h2.join();
    h3.join();

    return 0;
}
