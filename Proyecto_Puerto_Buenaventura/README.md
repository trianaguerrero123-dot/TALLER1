# Sistema de cargas del Puerto de Buenaventura en C

Proyecto académico para practicar `struct`, apuntadores, memoria dinámica, modularidad y algoritmos de ordenamiento.

## Archivos

- `main.c`: contiene el menú principal.
- `carga.h` y `carga.c`: definen y manejan los registros de carga.
- `ordenamiento.h` y `ordenamiento.c`: implementan Bubble Sort, Selection Sort e Insertion Sort.
- `.gitignore`: evita subir archivos ejecutables y temporales.

## Datos de cada carga

- Código único (sin espacios).
- Peso en toneladas.
- Tipo de mercancía (sin espacios; se puede usar `_`).
- Bahía asignada.

## Compilar con GCC

Abre la terminal en la carpeta del proyecto y ejecuta:

```bash
gcc main.c carga.c ordenamiento.c -o puerto_manager
```

En Windows, ejecuta el programa con:

```powershell
.\puerto_manager.exe
```

En Linux o macOS:

```bash
./puerto_manager
```

## Cómo probarlo

1. Ejecuta el programa.
2. Selecciona `1` para registrar dos o más cargas.
3. Selecciona `2` para ver los registros.
4. Selecciona `3`, elige un algoritmo y después el orden ascendente o descendente.
5. Selecciona `4` para salir.

## Conceptos usados

- `struct`: reúne los datos de una carga en una sola estructura.
- Apuntadores: permiten enviar y modificar registros mediante direcciones de memoria.
- `realloc`: ajusta el espacio de memoria cuando se agrega otra carga.
- `free`: libera la memoria reservada antes de terminar.
- Modularidad: divide el programa en archivos para organizar mejor el código.
- Ordenamiento: compara los pesos y cambia de posición las cargas según el método seleccionado.

## Subir a GitHub

Desde la terminal, dentro de esta carpeta:

```bash
git init
git add .
git commit -m "Primer avance: sistema de cargas en C"
```

Después crea un repositorio vacío en GitHub y sigue las instrucciones que GitHub te muestre para conectar el repositorio remoto y ejecutar `git push`.
