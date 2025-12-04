# Ejercicio 02 (Intermedio): Singleton con recursos compartidos

Implemente una clase `Logger` que registre mensajes de log en un archivo de texto (por ejemplo `bitacora.log`).

## Requisitos

- Solo debe existir **una instancia** de `Logger`.
- Implementa un método `log(mensaje)` que agregue el texto al archivo junto con la hora actual.
- Prueba el logger desde distintos puntos del programa y confirma que todos usan **el mismo archivo**.
