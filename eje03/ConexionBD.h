#ifndef CONEXIONBD_H
#define CONEXIONBD_H

#include <iostream>
#include <string>

class ConexionBD {
private:
    bool conectado;

    // Constructor privado
    ConexionBD() : conectado(false) {}

    // Evitar copia y asignación
    ConexionBD(const ConexionBD&) = delete;
    ConexionBD& operator=(const ConexionBD&) = delete;

public:
    // Método que devuelve la única instancia
    static ConexionBD& getInstancia() {
        static ConexionBD instancia;
        return instancia;
    }

    // Simular conexión
    void conectar() {
        if (!conectado) {
            conectado = true;
            std::cout << "Conectando a la base de datos..." << std::endl;
        } else {
            std::cout << "La conexión ya está activa." << std::endl;
        }
    }

    // Simular desconexión
    void desconectar() {
        if (conectado) {
            conectado = false;
            std::cout << "Desconectando de la base de datos..." << std::endl;
        } else {
            std::cout << "No hay conexión activa." << std::endl;
        }
    }

    // Estado actual
    void estado() const {
        std::cout << "Estado de la conexión: "
                  << (conectado ? "Conectado" : "Desconectado")
                  << std::endl;
    }
};

#endif
