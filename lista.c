#include <stdio.h>
#include <stdlib.h>

struct ponto
{
    float x;
    float y;
    struct ponto *prox;
};

typedef struct ponto Ponto;

Ponto *listaPontos; // aponta para o inicio da lista

int length = 0;

void imprime(Ponto *p)
{
    if (p != NULL)
    {
        printf("\nPonto(%.1f,%.1f)", p->x, p->y);
        imprime(p->prox);
    }
}

void addIndex(float x, float y, int index)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    if (index > length)
    {
        printf("Posicao invalida");
    }
    else
    {
        if (index == 0)
        {
            p->prox = listaPontos; /* code */
            listaPontos = p;
        }
        else
        {
            Ponto *listaAux = listaPontos;
            int i = 0;
            while (i != index - 1)
            {
                listaAux = listaAux->prox;
                i++;
            }
            p->prox = listaAux->prox;

            listaAux->prox = p;
        }
        length++;
    }
}
void removeIndex(int index)
{
    if (index > length || length == 0)
    {
        printf("posicao invalida ou lista vazia");
    }
    else
    {
        if (index == 0)
        {
            listaPontos = listaPontos->prox;
        }
        else
        {
            Ponto *listaAux = listaPontos;
            int i = 0;
            while (i != index - 1)
            {
                listaAux = listaAux->prox;
                i++;
            }
            listaAux->prox = listaAux->prox->prox;
        }
        length--;
    }
}
int main()
{

    addIndex(1, 1, 0);
    addIndex(2.4, 1, 1);
    addIndex(4, 16, 2);
    addIndex(3, 9, 2);

    removeIndex(0);

    Ponto *auxLista = listaPontos;

    imprime(auxLista);

    return 0;
}
