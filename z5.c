#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 10

struct group
{
    char name[50]; // Nombre del grupo
    int order; // Número de elementos
    int identity; // Elemento identidad
    int elements[MAX_ELEMENTS]; // Elementos del grupo 
    int operation[MAX_ELEMENTS][MAX_ELEMENTS];

};


int is_identity(struct group *G, int e) // verificar identidad
{
    for (int i = 0; i < G -> order; i++)
    {
        if ( G-> operation[e][i] != i || G -> operation[e][i] != i)
        return 0;
    }
    return 1;
}

int inverse_of(struct group *G, int a) //Encontrar inversos
{
    for (int i = 0; i < G->order; i++)
    {
        if (G->operation[a][i] == G->identity &&
            G->operation[i][a] == G->identity)
            return i;
    }
    return -1; // No tiene inverso
}

int main(void)
{
    struct group Z5;

    strcpy(Z5.name, "Grupo ciclico Z5");
    Z5.order = 5;
    Z5.identity = 0;

    /* Definimos los elementos */
    for (int i = 0; i < Z5.order; i++)
    {
        Z5.elements[i] = i;
    }

    /* Definimos la operación: suma módulo 5 */
    for (int i = 0; i < Z5.order; i++)
    {
        for (int j = 0; j < Z5.order; j++)
        {
            Z5.operation[i][j] = (i + j) % Z5.order;
        }
    }

    /* Información básica del grupo */
    printf("Nombre del grupo: %s\n", Z5.name);
    printf("Orden del grupo: %d\n", Z5.order);
    printf("Identidad declarada: %d\n\n", Z5.identity);

     printf("Tabla de operacion:\n");
    for (int i = 0; i < Z5.order; i++)
    {
        for (int j = 0; j < Z5.order; j++)
        {
            printf("%d ", Z5.operation[i][j]);
        }
        printf("\n");
    }

    /* Verificación de la identidad */
    printf("Verificacion de identidad:\n");
    for (int i = 0; i < Z5.order; i++)
    {
        if (is_identity(&Z5, i))
        {
            printf("El elemento %d ES la identidad\n", i);
        }
        else
        {
            printf("El elemento %d NO es la identidad\n", i);
        }
    }

    /* Cálculo de inversos */
    printf("\nInversos en el grupo:\n");
    for (int i = 0; i < Z5.order; i++)
    {
        int inv = inverse_of(&Z5, i);
        if (inv != -1)
        {
            printf("El inverso de %d es %d\n", i, inv);
        }
        else
        {
            printf("El elemento %d no tiene inverso\n", i);
        }
    }

    return 0;
}
