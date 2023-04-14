#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100         // tamanho máximo de cada string da pilha serão 100 caracteres

typedef struct No{    
    char str[TAM_MAX];     // armazena o tamanho maximo de caracteres + 1 (para o caracter nulo de terminação)
    struct No *prox;
} No;     // representa um nó da pilha

typedef struct Pilha {
    No *topo;    // representa o elemento que está no topo da pilha
} Pilha;    

void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

void empilhar(Pilha *p, char *str) {
    No *ptr = (No*) malloc(sizeof(No));
    if (ptr == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    strcpy(ptr->str, str);
    ptr->prox = p->topo;
    p->topo = ptr;
}

char* desempilhar(Pilha *p) {
    if(p->topo == NULL) {   
        return "NULL";
    } else {
        char *str;
        str = p->topo->str;
        p->topo = p->topo->prox;
        return str;
    }
}

int main(int argc, char const *argv[]) {

    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    inicializarPilha(p);

    char str[TAM_MAX+8];
    char strInserir[TAM_MAX];

    while (fgets(str, TAM_MAX+8, stdin) != NULL) {
        if (sscanf(str, "inserir %[^\n]", strInserir) == 1) {
            empilhar(p, strInserir);
        } else if (strcmp(str, "desfazer\n") == 0) {
            printf("%s\n", desempilhar(p));
        }
    }
    return 0;

    free(p);

    return 0;
}
