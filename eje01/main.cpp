#include <iostream>
#include "Configuracion.h"

int main() {
    // Intento 1 de obtener instancia
    Configuracion& c1 = Configuracion::getInstancia();
    c1.mostrarConfiguracion();

    std::cout << "---------------------" << std::endl;

    // Intento 2 de obtener otra instancia
    Configuracion& c2 = Configuracion::getInstancia();

    // Cambiamos desde c2
    c2.setIdioma("Inglés");

    // Ambos deben mostrar lo mismo
    std::cout << "Desde c1:\n";
    c1.mostrarConfiguracion();

    std::cout << "Desde c2:\n";
    c2.mostrarConfiguracion();

    // Verificación de que son la misma instancia
    std::cout << "\n¿c1 y c2 son la misma instancia? "
              << std::boolalpha
              << (&c1 == &c2)
              << std::endl;

    return 0;
}
