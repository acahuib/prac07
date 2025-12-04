#include <iostream>
#include "Logger.h"

void funcionA() {
    Logger::getInstancia().log("Mensaje desde funcionA()");
}

void funcionB() {
    Logger::getInstancia().log("Mensaje desde funcionB()");
}

int main() {
    Logger& log1 = Logger::getInstancia();
    Logger& log2 = Logger::getInstancia();

    // Probar Singleton
    std::cout << "log1 y log2 son la misma instancia? "
              << std::boolalpha
              << (&log1 == &log2) << std::endl;

    // Registrar mensajes
    log1.log("Inicio del programa.");
    funcionA();
    funcionB();
    log2.log("Fin del programa.");

    std::cout << "Revisa el archivo bitacora.log para ver los registros." << std::endl;

    return 0;
}
