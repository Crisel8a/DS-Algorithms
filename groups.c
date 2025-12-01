#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct group
{
    char name[50];
    int order;
    int identity;
    int *elements;
    int **operation;
};

/* Construye el grupo ciclico Z_n */
void build_Zn(struct group *G, int n)
{
    G->order = n;
    G->identity = 0;
    strcpy(G->name, "Grupo ciclico Z_n");

    G->elements = malloc(n * sizeof(int));
    G->operation = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        G->elements[i] = i;
        G->operation[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G->operation[i][j] = (i + j) % n;
}

/* Imprime la tabla de Cayley */
void print_table(struct group *G)
{
    printf("\nTabla de Cayley:\n\n");

    printf("  * |");
    for (int i = 0; i < G->order; i++)
        printf(" %2d", G->elements[i]);
    printf("\n");

    printf("----");
    for (int i = 0; i < G->order; i++)
        printf("---");
    printf("\n");

    for (int i = 0; i < G->order; i++)
    {
        printf(" %2d |", G->elements[i]);
        for (int j = 0; j < G->order; j++)
            printf(" %2d", G->operation[i][j]);
        printf("\n");
    }
}

/* Verifica si un elemento es identidad */
int is_identity(struct group *G, int e)
{
    for (int i = 0; i < G->order; i++)
    {
        if (G->operation[e][i] != i || G->operation[i][e] != i)
            return 0;
    }
    return 1;
}

/* Encuentra el inverso de un elemento */
int inverse_of(struct group *G, int a)
{
    for (int i = 0; i < G->order; i++)
    {
        if (G->operation[a][i] == G->identity &&
            G->operation[i][a] == G->identity)
            return i;
    }
    return -1;
}

/* Libera la memoria */
void free_group(struct group *G)
{
    for (int i = 0; i < G->order; i++)
        free(G->operation[i]);

    free(G->operation);
    free(G->elements);
}

int main(void)
{
    struct group G;
    int n;

    printf("Ingrese el orden del grupo (n): ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Entrada invalida.\n");
        return 1;
    }

    build_Zn(&G, n);

    printf("\nNombre del grupo: %s\n", G.name);
    printf("Orden del grupo: %d\n", G.order);
    printf("Identidad declarada: %d\n", G.identity);

    /* Tabla */
    print_table(&G);

    /* Verificacion de identidad */
    printf("\nVerificacion del elemento identidad:\n");
    for (int i = 0; i < G.order; i++)
    {
        if (is_identity(&G, i))
            printf("Elemento %d ES la identidad\n", i);
    }

    /* Inversos */
    printf("\nInversos del grupo:\n");
    for (int i = 0; i < G.order; i++)
    {
        int inv = inverse_of(&G, i);
        if (inv != -1)
            printf("Inverso de %d es %d\n", i, inv);
        else
            printf("Elemento %d no tiene inverso\n", i);
    }

    free_group(&G);
    return 0;
}
