# Ejercicio 01 (Básico): Implementación directa del Singleton

Crear una clase `Configuracion` que almacene las configuraciones generales del sistema (por ejemplo, idioma y zona horaria).

## Requisitos

- Asegúrate de que solo exista **una instancia** de esta clase.
- Añade un método `mostrar_configuracion()` que imprima los valores actuales.
- Verifica en el `main` que aunque crees varios objetos, todos **apunten al mismo**.

---

## Solución

En este ejercicio se implementa el **patrón Singleton**, lo que garantiza que **solo exista una instancia** de la clase `Configuracion` durante todo el programa.  
Se muestra cómo crear varias referencias a la instancia, modificar la configuración desde una de ellas, y comprobar que todos los accesos apuntan a la misma instancia.


**Explicación de la salida del codigo:**

1. Al inicio, la instancia `c1` muestra el idioma por defecto `Español` y la zona horaria `GMT-5`.  
2. Se crea otra referencia `c2` a la misma instancia Singleton.  
3. Desde `c2` se cambia el idioma a `Inglés`.  
4. Al mostrar la configuración desde `c1` y `c2`, ambos reflejan el cambio porque **apuntan a la misma instancia**.  
5. Esto confirma que el patrón Singleton funciona correctamente: **no se crean múltiples instancias**, sino una única instancia compartida.


![Salida de Código](./image/ejer1.png)