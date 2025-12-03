<h1 align="center">
  <a href="#">
    DS & Algorithms
  </a>
</h1>

<p align="center">
  <strong>Crisel Escalante Dic 1, 2025</strong><br>
  
</p>

<p align="center">
  <a href="#">
        <img src="https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54" />
    </a>
   <a href="#">
        <img src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white" />
    </a>
    <a href="#">
        <img src="https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white" />
    </a>  
  
</p>

# 📐 Teoría de Grupos en C

Este proyecto implementa una **estructura algebraica de grupo** utilizando el lenguaje **C**, con el objetivo de conectar conceptos de **álgebra abstracta** con **programación de bajo nivel**.

Se modela un **grupo finito** y se verifican computacionalmente propiedades fundamentales como el **elemento identidad** y los **inversos**.

---

## 🔢 Definición de grupo

Un **grupo** es un par (G, ★), donde:

- G es un conjunto no vacío
- ★ es una operación binaria definida en G

que satisface los siguientes axiomas:

1. **Clausura**  
   Para todo a, b en G, el resultado de a ★ b pertenece a G.

2. **Asociatividad**  
   (a ★ b) ★ c = a ★ (b ★ c) para todo a, b, c en G.

3. **Elemento identidad**  
   Existe un elemento e en G tal que:
   - e ★ a = a
   - a ★ e = a  
   para todo a en G.

4. **Elemento inverso**  
   Para todo a en G, existe un elemento a⁻¹ en G tal que:
   - a ★ a⁻¹ = e
   - a⁻¹ ★ a = e

---

## 🧠 Modelado computacional

El grupo se representa en C usando la siguiente estructura:

```c
struct group
{
    char name[50];                      // Nombre del grupo
    int order;                          // Número de elementos
    int identity;                       // Elemento identidad
    int elements[MAX_ELEMENTS];         // Conjunto de elementos
    int operation[MAX_ELEMENTS][MAX_ELEMENTS]; // Tabla de Cayley
}; 
