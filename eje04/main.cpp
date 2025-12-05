#include <iostream>
#include "ControlJuego.h"

void jugador() {
    ControlJuego::getInstancia().agregarPuntaje(100);
    ControlJuego::getInstancia().perderVida();
}

void enemigoDerrotado() {
    ControlJuego::getInstancia().agregarPuntaje(250);
}

void interfaz() {
    ControlJuego::getInstancia().mostrarEstado();
}

int main() {
    ControlJuego& c1 = ControlJuego::getInstancia();
    ControlJuego& c2 = ControlJuego::getInstancia();

    // Verificar Singleton
    std::cout << "c1 y c2 son la misma instancia? "
              << std::boolalpha
              << (&c1 == &c2) << "\n\n";

    c1.mostrarEstado();

    jugador();
    enemigoDerrotado();
    c2.subirNivel();

    interfaz(); // Estado final del juego

    return 0;
}
