# Ejercicio 03 (Aplicado): Conexión simulada a base de datos

Crea una clase `ConexionBD` que simule la conexión a una base de datos.

## Requisitos

- Solo debe haber **una conexión activa** (Singleton).
- Incluye métodos como `conectar()`, `desconectar()` y `estado()`.
- Si alguien intenta crear otra conexión, debe devolverse **la misma instancia** ya existente.
