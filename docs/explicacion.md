# Explicación Teórica — Árbol BST

## ¿Qué es un Árbol Binario de Búsqueda?

Un **Árbol Binario de Búsqueda (BST)** es una estructura de datos no lineal donde:
- Cada nodo tiene **máximo 2 hijos** (izquierdo y derecho).
- El hijo **izquierdo** siempre tiene un valor **menor** que el padre.
- El hijo **derecho** siempre tiene un valor **mayor** que el padre.

## Elementos del árbol en este proyecto

```
            [50] Empresa UTA        ← RAÍZ (nivel 0)
           /         \
    [30] G.Ventas   [70] G.Finanzas  ← NODOS INTERNOS (nivel 1)
       /    \          /    \
   [20]    [40]     [60]   [80]      ← HOJAS (nivel 2)
```

## Recorridos

| Recorrido | Orden de visita | Resultado con datos de prueba |
|-----------|----------------|-------------------------------|
| Inorden | Izq → Raíz → Der | 20, 30, 40, 50, 60, 70, 80 |
| Preorden | Raíz → Izq → Der | 50, 30, 20, 40, 70, 60, 80 |
| Postorden | Izq → Der → Raíz | 20, 40, 30, 60, 80, 70, 50 |

## Complejidad

| Operación | Caso promedio | Peor caso |
|-----------|--------------|-----------|
| Insertar | O(log n) | O(n) |
| Buscar | O(log n) | O(n) |
| Eliminar | O(log n) | O(n) |

## ¿Por qué usarlo en un organigrama?

Porque permite representar jerarquías reales (empresa → gerentes → empleados) y realizar búsquedas eficientes por código, sin recorrer todos los registros.
