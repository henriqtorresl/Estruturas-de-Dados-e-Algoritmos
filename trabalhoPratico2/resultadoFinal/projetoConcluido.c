#include <stdio.h>
#include <stdlib.h>

typedef struct {    // struct que vai armazenar os valores do arquivo
    int salaryUsd;  // salary_in_usd -> chave
    int linha;      // linha em que aparece a chave
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

void desalocar(TABP *a) {   // desaloca os nós no sentido crescente..
    if(a == NULL) {
        return;
    } else if(a->esquerda == NULL && a->direita == NULL) {  // tratamento especial para evitar algumas recurssões
        free(a);
        a = NULL;
    } else{
        desalocar(a->esquerda);
        desalocar(a->direita);
        free(a);
        a = NULL;   // apontando o ponteiro pra NULL pra evitar que ele aponte pra algum lixo de memória
    }
}

int main(int argc, char const *argv[]) {
    
    FILE *fp; 
    TABP *raiz = NULL; // criando um ponteiro que vai apontar pra raiz...
    TABP *raizAux;  // Ponteiro que vai me auxiliar na hora de imprimir os dados...
    salary sAux;    // criando uma struct auxiliar, para pegar os valores do arquivo e jogar em um nó da árvore 
    int escolha;
    
    do{
        printf("Trabalho Pratico 2\n");
        printf("1. Carregar arquivo de dados\n");
        printf("2. Emitir Relatorio\n");
        printf("3. Sair\n");
        scanf("%d", &escolha);
        system("cls || clear");
        
    switch(escolha){
        case 1:

            fp = fopen("dataset_salaries.csv", "r");

            if (fp == NULL) {
                printf("Erro na abertura do arquivo!\n");
            } else {
                printf("Arquivo aberto com sucesso!\n");
            }

            fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd);
            raiz = create(sAux);    // inicializando a arvore e pegando os primeiros valores

            while(fscanf(fp, "%d %d", &sAux.linha, &sAux.salaryUsd) != EOF) {   // pegando os valores do arquivo e jogando na arvore
                adicionar(raiz, sAux);
            }

            printf("\n");  

            break;
            
        case 2:

            if(raiz == NULL) {
                printf("Arquivo vazio!\n");
            } else {
                raizAux = raiz;   // criando uma raiz auxiliar para mostrar os valores da arvore
                imprime(raizAux);
            }

            printf("\n");

            break;
            
        case 3:

            desalocar(raiz);    // desalocando os nós da árvore
            
            printf("\n");

            break;
            
        default:

            printf("Opcao invalida! Escolha entre as opcoes 1, 2 e 3.\n\n");
    }
    
    } while(escolha!=3);
    
    return 0;
}