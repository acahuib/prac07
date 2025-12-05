# Informe – Cuestionario 

## Integrantes
- **Cahui Benegas Anthony Ronaldo**

---

### 1. ¿Qué desventajas tiene el patrón Singleton en pruebas unitarias?

El patrón Singleton puede dificultar las pruebas unitarias por las siguientes razones:

- **Dificulta el uso de mocks o stubs**, ya que la instancia está fijada y no puede reemplazarse fácilmente por una versión falsa para pruebas.
- **Mantiene estado global**, lo cual puede afectar a pruebas que necesitan un entorno limpio para cada ejecución.
- **Dependencia oculta**, porque las clases que lo usan no declaran explícitamente esa dependencia, haciendo más difícil aislar la unidad bajo prueba.
- Puede provocar **efectos colaterales** entre pruebas si no se reinicia su estado.


---

### 2. ¿Cuándo no es recomendable usar Singleton?

No es recomendable usar Singleton en estos casos:

- Cuando la aplicación necesita **múltiples instancias** del objeto (por ejemplo, varias conexiones independientes o configuraciones distintas).
- Cuando el objeto tiene **mucha lógica o estados complejos**, ya que el estado global puede volverse difícil de controlar.
- En sistemas que requieren **alta escalabilidad**, porque el Singleton puede convertirse en un cuello de botella.
- En módulos que requieren **pruebas unitarias frecuentes**, porque el Singleton complica la inyección de dependencias.
- Cuando el uso de un Singleton solo sirve como “comodín global” ―en esos casos suele ser mejor usar DI (inyección de dependencias).


---

### 3. ¿Cómo se diferencia de una clase estática?

La diferencia principal entre un Singleton y una clase estática es:

| Característica | Singleton | Clase estática |
|----------------|-----------|----------------|
| Instancias | Tiene **una instancia** controlada | **No tiene instancias** |
| Estado | Mantiene estado interno que puede cambiar | Puede tener variables estáticas, pero no se crea un objeto |
| Herencia | **Sí** puede extender clases o implementar interfaces | **No** admite herencia |
| Polimorfismo | **Sí** permite polimorfismo | No se puede usar polimorfismo |
| Ciclo de vida | La instancia vive mientras el programa la use | La clase existe desde que se carga hasta que finaliza el programa |
| Uso en pruebas | Más fácil de mockear si se permite inyección | Muy difícil de reemplazar en pruebas |
