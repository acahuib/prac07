#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <iostream>
#include <string>

class Configuracion {
private:
    std::string idioma;
    std::string zonaHoraria;

    // 1. Constructor privado
    Configuracion() {
        idioma = "Español";
        zonaHoraria = "GMT-5";
    }

    // 2. Evitar copia de la instancia
    Configuracion(const Configuracion&) = delete;
    Configuracion& operator=(const Configuracion&) = delete;

public:
    // 3. Método estático que devuelve la única instancia
    static Configuracion& getInstancia() {
        static Configuracion instanciaUnica; // se crea solo una vez
        return instanciaUnica;
    }

    // Métodos para mostrar y modificar
    void mostrarConfiguracion() const {
        std::cout << "Idioma: " << idioma << std::endl;
        std::cout << "Zona horaria: " << zonaHoraria << std::endl;
    }

    void setIdioma(const std::string& nuevoIdioma) {
        idioma = nuevoIdioma;
    }

    void setZonaHoraria(const std::string& nuevaZona) {
        zonaHoraria = nuevaZona;
    }
};

#endif

