# &#x20;  Árbol BST — Organigrama Empresarial en C++

> \*\*Asignatura:\*\* Estructura de Datos  
> \*\*Tema:\*\* Árboles Binarios de Búsqueda (BST)  
> \*\*Universidad:\*\* Universidad Técnica de Ambato  
> \*\*Ciclo:\*\* Enero – Julio 2026  

\---

## &#x20;  Integrantes

|Rol|Nombre|Responsabilidad|
|-|-|-|
|Líder|Luis Manobanda|Coordina avance y revisa el repositorio|
|Programador 1|Luis Manobanda|Estructura Nodo y función insertar|
|Programador 2|Luis Manobanda|Búsqueda, eliminar y recorridos|
|Programador 3|Luis Manobanda|Altura, hojas y total de nodos|
|Documentador|Luis Manobanda|README, capturas y explicación|
|Expositor|Luis Manobanda|Presenta funcionamiento y conclusiones|

\---

## &#x20;  Objetivo

Implementar un **Árbol Binario de Búsqueda (BST)** en C++ para organizar empleados de una empresa de forma jerárquica, usando un código numérico como clave de búsqueda. El proyecto refleja el organigrama empresarial visto en clase, identificando raíz, niveles, nodos internos y hojas.

\---

## &#x20;  Estructura del Repositorio

```
Arbol-Binario-de-Busqueda/

arbol-bst-empresa-cpp/
│
├── src/
│   └── main.cpp          ← Código fuente principal
│
├── capturas/
│   ├── 01\_menu.png       ← Menú principal
│   ├── 02\_insertar.png   ← Inserción de empleados
│   ├── 03\_buscar.png     ← Búsqueda por código
│   ├── 04\_inorden.png    ← Recorrido inorden
│   ├── 05\_altura.png     ← Altura y hojas
│   └── 06\_eliminar.png   ← Eliminación de nodo
│
├── docs/
│   └── explicacion.md    ← Explicación teórica
│
└── README.md
```

\---

## &#x20;  Funcionalidades

|#|Función|Descripción|
|-|-|-|
|1|Insertar empleado|Agrega un nodo con código, nombre y cargo|
|2|Buscar empleado|Localiza un nodo por su código|
|3|Eliminar empleado|Elimina un nodo manteniendo la estructura BST|
|4|Mostrar raíz|Muestra el nodo principal del árbol|
|5|Recorrido Inorden|Muestra empleados en orden ascendente por código|
|6|Recorrido Preorden|Raíz → Izquierda → Derecha|
|7|Recorrido Postorden|Izquierda → Derecha → Raíz|
|8|Altura del árbol|Número máximo de niveles|
|9|Nodos hoja|Empleados sin subordinados|
|10|Total de empleados|Cuenta todos los nodos del árbol|

\---

## &#x20;  Datos de Prueba

El programa carga automáticamente estos empleados al iniciar:

```
Código  Nombre               Cargo
------  ------               -----
50      Empresa UTA          Raíz / Empresa
30      Gerente de Ventas    Nodo Interno
70      Gerente Finanzas     Nodo Interno
20      Empleado 1           Hoja - Ventas
40      Empleado 2           Hoja - Ventas
60      Empleado 3           Hoja - Finanzas
80      Empleado 4           Hoja - Finanzas
```

**Estructura resultante:**

```
            50
           /  \\
         30    70
        / \\   / \\
       20 40 60  80
```

\---

## &#x20;  Conceptos Clave

|Término|Definición|
|-|-|
|**Raíz**|Nodo principal del árbol, no tiene padre. En este caso: código 50|
|**Nodo interno**|Tiene al menos un hijo. Ej: códigos 30 y 70|
|**Hoja**|Nodo sin hijos. Ej: códigos 20, 40, 60, 80|
|**Nivel**|Cada generación dentro del árbol. La raíz está en nivel 0|
|**Altura**|Número máximo de niveles. Este árbol tiene altura 3|
|**BST**|Propiedad: izquierda < raíz < derecha en cada nodo|

\---

## &#x20;  Compilación y Ejecución

### Dev-C++ (Windows)

1. Abrir Dev-C++
2. `Archivo → Nuevo → Proyecto → Console Application`
3. Agregar `src/main.cpp` al proyecto
4. Compilar y ejecutar con **F11**

### Terminal (g++)

```bash
# Compilar
g++ src/main.cpp -o arbol

# Ejecutar (Linux/Mac)
./arbol

# Ejecutar (Windows)
arbol.exe
```

\---

## &#x20;  Capturas de Ejecución

> Las capturas se encuentran en la carpeta `/capturas`

|Pantalla|Descripción|
|-|-|
|`01\_menu.png`|Menú principal del programa|
|`02\_insertar.png`|Proceso de inserción de un empleado|
|`03\_buscar.png`|Búsqueda exitosa y fallida|
|`04\_inorden.png`|Lista ordenada de empleados|
|`05\_altura.png`|Cálculo de altura y nodos hoja|
|`06\_eliminar.png`|Eliminación de un nodo|

\---

## &#x20;  Conclusión

El Árbol Binario de Búsqueda permite organizar información jerárquica de manera eficiente. Gracias a la propiedad BST (izquierda < raíz < derecha), las búsquedas, inserciones y eliminaciones se realizan en tiempo **O(log n)** en el caso promedio, lo que lo hace ideal para representar organigramas y estructuras de datos empresariales.

\---

