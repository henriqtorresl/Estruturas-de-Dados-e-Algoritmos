#include <stdio.h>
#include <stdlib.h>

typedef struct {    // struct que vai armazenar os valores do arquivo
    int salaryUsd;  // salário
    int linha;      // linha em que aparece o salário
} salary;

typedef struct ABP {    // definindo um nó...
    salary s;
    struct ABP *esquerda;
    struct ABP *direita;
} TABP;

TABP* create(salary s) {    // função que vai criar um nó da árvore
    TABP *a = (TABP *) malloc(sizeof(TABP));
    a->s = s;
    a->esquerda = NULL;
    a->direita = NULL;

    return a;
}

int tamanhoArq(FILE *pArq) {        // função que mede o tamanho de um arquivo
    FILE *pArqAux;
    int tam = 0;
    char c;

    pArqAux = pArq;

    while(c != EOF) {
        c = fgetc(pArqAux);
        if (c == '\n' || c == EOF) {
            tam++;
        }
    }

    fclose(pArqAux);
    return tam;
}

void adicionar(TABP *a, salary s) {
    if(s.salaryUsd < a->s.salaryUsd) {     // se for menor eu insiro a esquerda...
        if (a->esquerda == NULL) {    // se nn tiver nada a esquerda posso inserir diretamente
            a->esquerda = create(s);
        } else {
            adicionar(a->esquerda, s);
        }
    } else {
        if(a->direita == NULL) {    // se nn tiver nada a direita posso inserir diretamente
            a->direita = create(s);
        } else {
            adicionar(a->direita, s); 
        }
    }
}

void imprime(TABP *a) {
    if(a == NULL) {
        return;
    } else {
        imprime(a->esquerda);
        printf("%d %d\n", a->s.salaryUsd, a->s.linha);
        imprime(a->direita);
    }
}

FILE* abrirArquivo(char* nomeArq) {     // função que abre um arquivo
    return fopen(nomeArq, "r");
}

void desalocar(TABP *a) {
    if (a == NULL) {
        return NULL;
    } else {   
        desalocar(a->esquerda);
        desalocar(a->direita);
        free(a);
    }
}


int main(int argc, char const *argv[]) {
    
    FILE *fp;
    TABP *raiz;
    salary sAux;

    fp = abrirArquivo("dataset_salaries.csv");

    if(fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    raiz = (TABP*) malloc(sizeof(TABP));                // inicializando a arvore e pegando os primeiros valores
    fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd);
    raiz->s = sAux;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    while(fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd) != EOF) {
        adicionar(raiz, sAux);
    }

    TABP *raizAux = raiz;
    imprime(raiz);

    desalocar(raiz);
    desalocar(raizAux);
    fclose(fp);

    if(raiz != NULL) {
        printf("%d %d\n", raiz->s.linha, raiz->s.salaryUsd);
    } else {
        printf("Raiz desalocado!\n");
    }

    return 0;
}