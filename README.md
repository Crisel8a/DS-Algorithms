<h1 align="center">
  <a href="#">
    Structs and Groups
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

# 📐 Modelado de Teoría de Grupos en C

Este proyecto implementa una **estructura algebraica de grupo** utilizando el lenguaje **C**, conectando conceptos de **teoría de grupos** con programación de bajo nivel.

El objetivo principal es representar un **grupo finito** y verificar computacionalmente propiedades fundamentales como la **identidad** y los **inversos**.

---

## 🔢 Definición matemática

Un grupo es un par ordenado:

$$
(G, \star)
$$

donde:

- \( G \) es un conjunto no vacío
- \( \star : G \times G \to G \) es una operación binaria

que satisface los axiomas:

1. **Clausura**
$$
\forall a,b \in G,\quad a \star b \in G
$$

2. **Asociatividad**
$$
(a \star b) \star c = a \star (b \star c)
$$

3. **Elemento identidad**
$$
\exists e \in G \text{ tal que } \forall a \in G,\quad
e \star a = a \star e = a
$$

4. **Elemento inverso**
$$
\forall a \in G,\quad \exists a^{-1} \in G \text{ tal que }
a \star a^{-1} = a^{-1} \star a = e
$$

---

## 🧠 Modelado computacional

El grupo se modela mediante la siguiente estructura en C:

```c
struct group
{
    char name[50];                      // Nombre del grupo
    int order;                          // Orden |G|
    int identity;                       // Elemento identidad e
    int elements[MAX_ELEMENTS];         // Conjunto de elementos
    int operation[MAX_ELEMENTS][MAX_ELEMENTS]; // Tabla de Cayley
};
