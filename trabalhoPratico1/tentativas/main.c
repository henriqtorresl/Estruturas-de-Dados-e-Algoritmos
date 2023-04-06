#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
  char category[100];
  float amount;
} Produto;

int tamanhoArquivo(FILE *fp) {      // essa função está dando erro, pois com o fgetc() eu tiro o conteúdo todo de fp, ai fica impossível eu fazer as manipulações no arquivo fp
    /*
    char c;
    int tam = 0;
    while(c != EOF) {
        c = fgetc(fp);
        if (c == '\n' || c == EOF) {    // se "c == '\n" isso quer dizer que chegou ao fim de uma linha, "c == EOF" para contar a última linha
           tam++;                       // contando as linhas
        }
    }
    return tam;
    */
}

int main() {
    FILE *fp;
    Produto aux; 
    Produto *p;
    fp = fopen("amazonDataset.csv", "r");

    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    // Alocação dinâmica    --> resolver problema da alocação dinâmica
    int tam = 128975; // int tam = tamanhoArquivo(fp);  -> função tamanhoArquivo está com problema
    p = (Produto*) malloc(tam * sizeof(Produto));

    // criando outro arquivo para formatar e manipular o dataSet
    FILE *fpCopia;
    fpCopia = fopen("amazonDatasetCopia.csv", "w");
    
    char c;
    while(c != EOF) {
        c = fgetc(fp);
        if(c == EOF) {  // para não escrever nada alem do conteudo desejado
            break;
        }
        fputc(c, fpCopia);  // escrevendo caracter por caracter no novo arquivo
        if(c == ';') {      // acrescentando um espaço em branco após a virgula
            fputc(' ', fpCopia);
        }
    }

    fclose(fpCopia);
    fpCopia = fopen("amazonDatasetCopia.csv", "r");  // aqui estou abrindo novamente, pois agora quero ler o arquivo e nn escrever nele

    // Inserindo os valores de fp em p
    for(int i = 0; i < tam ; i++) {
       fscanf(fpCopia, "%s %f", p[i].category, &p[i].amount);       // o problema dos zeros está aqui...
       printf("%s %.2f\n", p[i].category, p[i].amount);
    }
    

    // Ordenado os preços bubble
    for(int i = tam; i > 0; i--){       
        for(int j = 0; j < i; j++) {
            if (p[j].amount < p[j+1].amount) {
                aux.amount = p[j].amount;
                strcpy(aux.category, p[j].category);
              
                p[j].amount = p[j+1].amount;
                strcpy(p[j].category , p[j+1].category);
              
                p[j+1].amount = aux.amount;
                strcpy(p[j+1].category, aux.category);
            }
        }
    }
   
    // Imprimindo os valores ordenados
    /*
    for(int i = 1; i < tam; i++) {
        printf("%.2f %s\n", p[i].amount, p[i].category );     -> deixei essa parte do código comentada pois não quero imprimir os valores no console..
    }
    */
    
    // Gerando um arquivo de saída
    FILE *fpSaida;
    fpSaida = fopen("amazonDatasetOrdenado.csv", "w");

    // escrevendo a primeira linha do arquivo de saída ("Category, Amount")
    char str[20];
    strcpy(str, "Category; Amount");
    fprintf(fpSaida, "%s\n", str);
    for(int i = 0; i < tam ; i++) {
        fprintf(fpSaida, "%s %.2f\n", p[i].category, p[i].amount);
    }

    printf("Arquivo de saida gerado!\n");  // se o código executar até aqui, quer dizer que foi gerado um arquivo de saída

    free(p);
    fclose(fp);
    fclose(fpCopia);
    fclose(fpSaida);
    return 0;
}