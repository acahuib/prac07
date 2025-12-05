#ifndef CONEXIONBD_THREADSAFE_H
#define CONEXIONBD_THREADSAFE_H

#include <iostream>
#include <string>
#include <mutex>

class ConexionBD {
private:
    bool conectado;
    static ConexionBD* instancia;
    static std::mutex mtx;

    // Constructor privado
    ConexionBD() : conectado(false) {}

    // Evitar copia y asignación
    ConexionBD(const ConexionBD&) = delete;
    ConexionBD& operator=(const ConexionBD&) = delete;

public:
    // Obtener la única instancia (thread-safe)
    static ConexionBD* getInstancia() {
        if (instancia == nullptr) {
            std::lock_guard<std::mutex> lock(mtx);
            if (instancia == nullptr) {
                instancia = new ConexionBD();
            }
        }
        return instancia;
    }

    void conectar() {
        if (!conectado) {
            conectado = true;
            std::cout << "Conectando a la base de datos..." << std::endl;
        } else {
            std::cout << "La conexion ya esta activa." << std::endl;
        }
    }

    void desconectar() {
        if (conectado) {
            conectado = false;
            std::cout << "Desconectando de la base de datos..." << std::endl;
        } else {
            std::cout << "No hay conexion activa." << std::endl;
        }
    }

    void estado() const {
        std::cout << "Estado de la conexion: "
                  << (conectado ? "Conectado" : "Desconectado")
                  << std::endl;
    }
};

ConexionBD* ConexionBD::instancia = nullptr;
std::mutex ConexionBD::mtx;

#endif