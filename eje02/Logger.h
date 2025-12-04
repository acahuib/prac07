#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
private:
    std::ofstream archivo;

    // Constructor privado
    Logger() {
        archivo.open("bitacora.log", std::ios::app);
        if (!archivo) {
            std::cerr << "Error al abrir el archivo de log." << std::endl;
        }
    }

    // Evitar copia o asignación
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Obtener hora actual
    std::string obtenerHoraActual() {
        std::time_t ahora = std::time(nullptr);
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&ahora));
        return buffer;
    }

public:
    // Instancia única
    static Logger& getInstancia() {
        static Logger instancia;
        return instancia;
    }

    // Método para registrar mensajes
    void log(const std::string& mensaje) {
        if (archivo) {
            archivo << "[" << obtenerHoraActual() << "] " << mensaje << std::endl;
        }
    }

    // Destructor (cierra el archivo)
    ~Logger() {
        if (archivo.is_open()) {
            archivo.close();
        }
    }
};

#endif
