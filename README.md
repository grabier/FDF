# 🌐 FdF (Fil de Fer) - 3D Wireframe Visualizer

> "Simplicity is the ultimate sophistication."

[![C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics](https://img.shields.io/badge/Graphics-MinilibX-ff69b4?style=for-the-badge)](https://github.com/42Paris/minilibx-linux)
[![42](https://img.shields.io/badge/School-42-000000?style=for-the-badge&logo=42)](https://42.fr/)

## 🏔️ Introducción

FdF es un proyecto de algoritmia gráfica. El objetivo es representar un mapa topográfico (una malla de puntos con coordenadas X, Y, Z) en una ventana 2D, creando una representación "wireframe" (alambre) mediante proyección isométrica pura.

Este proyecto se centra en la **precisión del renderizado** y la implementación manual de algoritmos de trazado de líneas, prescindiendo de ayudas visuales externas o motores gráficos.

---

## 📸 Resultado

![FdF Screenshot](assets/fdf.png)
*(Renderizado del mapa en proyección isométrica estricta)*

---

## ⚙️ Ingeniería detrás del píxel

Al no utilizar librerías gráficas de alto nivel (como OpenGL), toda la lógica de dibujo está escrita en C:

1.  **Lectura y Parsing:** Conversión de mapas de texto (`.fdf`) a estructuras de datos en memoria, manejando coordenadas y asignación dinámica de memoria.
2.  **Proyección Isométrica:** Transformación matemática de cada punto `(x, y, z)` del espacio tridimensional a un plano 2D `(x, y)` para simular profundidad.
3.  **Algoritmo de Bresenham:** Implementación del clásico algoritmo para trazar líneas rectas perfectas entre dos puntos en una cuadrícula de píxeles, optimizando el uso de la CPU (uso de enteros en lugar de coma flotante donde es posible).

---

## 🛠️ Instalación y Uso

Este proyecto requiere las librerías básicas del sistema (MinilibX requiere X11 en Linux).

```bash
# 1. Clona el repositorio
git clone [https://github.com/grabier/FdF.git]

# 2. Entra al directorio y compila
cd FdF && make

# 3. Ejecuta con un mapa
./fdf test_maps/42.fdf
