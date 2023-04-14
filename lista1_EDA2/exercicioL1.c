#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) {
    celula *p, *ant1, *ant2, *aux;
    ant1 = l1;
    ant2 = l2;
    p = le->prox;
    
    while (p != NULL) {
        if (p->mediaAtividades <= media) {
            aux = p->prox;
            ant1->prox = p;
            p->prox = NULL;
            ant1 = p;
            p = aux;
        } else {
            aux = p->prox;
            ant2->prox = p;
            p->prox = NULL;
            ant2 = p;
            p = aux;
        }
    }
}
