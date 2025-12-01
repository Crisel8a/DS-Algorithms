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
📐 Modelado de Teoría de Grupos en C

Este proyecto implementa una estructura algebraica de grupo usando el lenguaje C, conectando conceptos de teoría de grupos con programación de bajo nivel.

El objetivo es representar un grupo finito y verificar computacionalmente propiedades fundamentales como la identidad y los inversos.

🔢 Definición matemática

Un grupo es un par ordenado (G, ★), donde:

G es un conjunto no vacío

★ : G × G → G es una operación binaria

que satisface los siguientes axiomas:

Clausura
Para todo a, b ∈ G, se cumple que a ★ b ∈ G

Asociatividad
(a ★ b) ★ c = a ★ (b ★ c)

Elemento identidad
Existe un elemento e ∈ G tal que, para todo a ∈ G:
e ★ a = a ★ e = a

Elemento inverso
Para todo a ∈ G, existe un elemento a⁻¹ ∈ G tal que:
a ★ a⁻¹ = a⁻¹ ★ a = e

🧠 Modelado computacional

El grupo se representa en C mediante la estructura:

struct group
{
    char name[50];                      // Nombre del grupo
    int order;                          // Número de elementos |G|
    int identity;                       // Elemento identidad
    int elements[MAX_ELEMENTS];         // Conjunto de elementos
    int operation[MAX_ELEMENTS][MAX_ELEMENTS]; // Tabla de Cayley
};


Esta estructura representa directamente la terna (G, ★, e).

La tabla de Cayley permite definir explícitamente la operación binaria.

🔁 Grupo implementado: Z₅

Se implementa el grupo cíclico:

Z₅ = {0, 1, 2, 3, 4}

con la operación:

a ★ b = (a + b) mod 5

Propiedades del grupo:

Finito

Abeliano

Cíclico

De orden 5

✅ Verificación del elemento identidad

La función:

int is_identity(struct group *G, int e)


verifica si un elemento e cumple:

e ★ a = a y a ★ e = a para todo a ∈ G

confirmando así la identidad del grupo.

🔄 Cálculo de inversos

La función:

int inverse_of(struct group *G, int a)


busca un elemento b ∈ G tal que:

a ★ b = b ★ a = e

Si existe, b es el inverso de a.

En el grupo Z₅:

El inverso de 0 es 0

El inverso de 1 es 4

El inverso de 2 es 3

El inverso de 3 es 2

El inverso de 4 es 1

🖥️ Salida del programa

El programa imprime:

Información general del grupo

El elemento identidad

El inverso de cada elemento

demostrando cómo los axiomas del grupo pueden verificarse mediante código.

🚀 Posibles extensiones

Verificar automáticamente todos los axiomas de grupo

Implementar subgrupos

Trabajar con grupos no abelianos (ej. S₃)

Implementar homomorfismos e isomorfismos

🧮 Conclusión

Este proyecto muestra cómo una estructura abstracta de la teoría de grupos puede representarse computacionalmente en C, conectando matemáticas puras con programación de sistemas.
