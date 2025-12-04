#include <iostream>
#include "ConexionBD.h"

void funcionX() {
    ConexionBD::getInstancia().estado();
}

void funcionY() {
    ConexionBD::getInstancia().conectar();
}

int main() {
    ConexionBD& c1 = ConexionBD::getInstancia();
    ConexionBD& c2 = ConexionBD::getInstancia();

    // Verificar si ambos son la misma instancia
    std::cout << "¿c1 y c2 son la misma instancia? "
              << std::boolalpha
              << (&c1 == &c2) << std::endl;

    c1.estado();
    c1.conectar();
    funcionX();
    funcionY();
    c2.desconectar();

    return 0;
}
