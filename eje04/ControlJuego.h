#ifndef CONTROLJUEGO_H
#define CONTROLJUEGO_H

#include <iostream>

class ControlJuego {
private:
    int nivel;
    int puntaje;
    int vidas;

    // Constructor privado
    ControlJuego() : nivel(1), puntaje(0), vidas(3) {}

    // Evitar copia y asignación
    ControlJuego(const ControlJuego&) = delete;
    ControlJuego& operator=(const ControlJuego&) = delete;

public:
    // Obtener la única instancia
    static ControlJuego& getInstancia() {
        static ControlJuego instancia;
        return instancia;
    }

    // Métodos para modificar el estado del juego
    void subirNivel() {
        nivel++;
        std::cout << "Subiendo al nivel " << nivel << std::endl;
    }

    void agregarPuntaje(int puntos) {
        puntaje += puntos;
        std::cout << "Puntaje aumentado: +" << puntos << " (Total: " << puntaje << ")" << std::endl;
    }

    void perderVida() {
        if (vidas > 0) {
            vidas--;
            std::cout << "Perdiste una vida. Vidas restantes: " << vidas << std::endl;
        }
    }

    void mostrarEstado() {
        std::cout << "=== ESTADO DEL JUEGO ===" << std::endl;
        std::cout << "Nivel: " << nivel << std::endl;
        std::cout << "Puntaje: " << puntaje << std::endl;
        std::cout << "Vidas: " << vidas << std::endl;
        std::cout << "=========================" << std::endl;
    }
};

#endif
