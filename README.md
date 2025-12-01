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

Este proyecto implementa una estructura algebraica de grupo usando el lenguaje C, conectando directamente los conceptos de teoría de grupos con estructuras y funciones de programación de bajo nivel.

El objetivo es representar computacionalmente un grupo finito y verificar algunas de sus propiedades fundamentales, como la identidad y los inversos.

🔢 Definición matemática

Un grupo es un par ordenado

(
𝐺
,
⋆
)
(G,⋆)

donde:

𝐺
G es un conjunto no vacío de elementos

⋆
:
𝐺
×
𝐺
→
𝐺
⋆:G×G→G es una operación binaria

cumpliendo los siguientes axiomas:

Clausura

∀
𝑎
,
𝑏
∈
𝐺
,
𝑎
⋆
𝑏
∈
𝐺
∀a,b∈G,a⋆b∈G

Asociatividad

(
𝑎
⋆
𝑏
)
⋆
𝑐
=
𝑎
⋆
(
𝑏
⋆
𝑐
)
(a⋆b)⋆c=a⋆(b⋆c)

Elemento identidad

∃
𝑒
∈
𝐺
 tal que 
∀
𝑎
∈
𝐺
,
𝑒
⋆
𝑎
=
𝑎
⋆
𝑒
=
𝑎
∃e∈G tal que ∀a∈G,e⋆a=a⋆e=a

Elemento inverso

∀
𝑎
∈
𝐺
,
∃
𝑎
−
1
∈
𝐺
 tal que 
𝑎
⋆
𝑎
−
1
=
𝑎
−
1
⋆
𝑎
=
𝑒
∀a∈G,∃a
−1
∈G tal que a⋆a
−1
=a
−1
⋆a=e
🧠 Modelado computacional

En este proyecto, un grupo finito se modela mediante la estructura:

struct group
{
    char name[50];                      // Nombre del grupo
    int order;                          // Cardinalidad |G|
    int identity;                       // Elemento identidad e
    int elements[MAX_ELEMENTS];         // Conjunto de elementos
    int operation[MAX_ELEMENTS][MAX_ELEMENTS]; // Tabla de Cayley
};


Esto corresponde directamente a la formulación matemática:

(
𝐺
,
⋆
,
𝑒
)
(G,⋆,e)

La tabla de Cayley permite representar explícitamente la operación binaria del grupo.

🔁 Grupo implementado: 
𝑍
5
Z
5
	​


Se implementa el grupo cíclico:

𝑍
5
=
{
0
,
1
,
2
,
3
,
4
}
Z
5
	​

={0,1,2,3,4}

con la operación:

𝑎
⋆
𝑏
=
(
𝑎
+
𝑏
)
 
m
o
d
 
5
a⋆b=(a+b)mod5

Este grupo es:

Finito

Abeliano

Cíclico

De orden 5

✅ Verificación del elemento identidad

La función:

int is_identity(struct group *G, int e)


verifica si un elemento 
𝑒
e cumple:

∀
𝑎
∈
𝐺
,
𝑒
⋆
𝑎
=
𝑎
y
𝑎
⋆
𝑒
=
𝑎
∀a∈G,e⋆a=aya⋆e=a

Esto permite confirmar de forma algorítmica la identidad del grupo.

🔄 Cálculo de inversos

La función:

int inverse_of(struct group *G, int a)


busca un elemento 
𝑏
∈
𝐺
b∈G tal que:

𝑎
⋆
𝑏
=
𝑏
⋆
𝑎
=
𝑒
a⋆b=b⋆a=e

Si dicho elemento existe, se devuelve como el inverso de 
𝑎
a.
En caso contrario, la función retorna -1.

En 
𝑍
5
Z
5
	​

, los inversos son:

0
−
1
	
=
0


1
−
1
	
=
4


2
−
1
	
=
3


3
−
1
	
=
2


4
−
1
	
=
1
0
−1
1
−1
2
−1
3
−1
4
−1
	​

=0
=4
=3
=2
=1
	​

🖥️ Salida del programa

El programa imprime:

Información básica del grupo

Verificación de qué elemento es la identidad

El inverso de cada elemento del grupo

Esto demuestra cómo los axiomas algebraicos pueden ser evaluados mediante código.

🚀 Posibles extensiones

Verificación completa de los axiomas de grupo

Implementación de subgrupos

Grupos no abelianos (por ejemplo 
𝑆
3
S
3
	​

)

Homomorfismos e isomorfismos

Representación por generadores y relaciones

🧮 Conclusión

Este proyecto muestra cómo la estructura abstracta de un grupo puede ser representada de forma explícita en C utilizando:

struct para el conjunto y sus datos

funciones para las propiedades algebraicas

Es un puente directo entre álgebra abstracta y programa
