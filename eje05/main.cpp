// main_threadsafe.cpp
#include <iostream>
#include <thread>
#include "ConexionBD_threadsafe.h"
#include <mutex>

std::mutex cout_mtx;
void tarea(int id) {
    ConexionBD* c = ConexionBD::getInstancia();
    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "Hilo " << id << " obtiene instancia: " << c << std::endl;
    }

    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        c->conectar();
        c->estado();
        c->desconectar();
    }
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
