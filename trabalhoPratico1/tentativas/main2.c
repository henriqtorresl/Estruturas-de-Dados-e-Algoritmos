#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

//Definindo o Produto
typedef struct {
  char category[30];
  float amount;
} Produto;

int main() {
  FILE *fp, *fpSaida;
  Produto *p, aux;
  clock_t start, end;
  double cpu_time_used;

  start = clock(); //Pegando o tempo de inicio do programa

  fp = fopen("amazonDataset.csv", "r"); //Abrindo o arquivo para leitura seguido de verificação de erro

  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
  } else {
    printf("Arquivo aberto com sucesso!\n");
  }

  p = (Produto *)malloc(1 * sizeof(Produto)); // Alocando o tamanho de 1 produto

  
  fpSaida = fopen("amazonDatasetOrdenado.csv", "w"); // Abrindo o outro arquivo para Saída

  int i = 0; // Contador para manipular a posição no Vetor
  while(fscanf(fp, "%s %f", aux.category, &aux.amount) != EOF) {
    p = (Produto*) realloc(p, (i+1) * sizeof(Produto));
    p[i].amount = aux.amount;
    strcpy(p[i].category,aux.category);
    i++;
  };

  // Ordenado os precos usando lógica BubbleSort
  for (int h = i; h > 0; h--) {
    for (int j = 0; j < h; j++) {
      if (p[j].amount < p[j + 1].amount) {
        aux.amount = p[j].amount;
        strcpy(aux.category, p[j].category);

        p[j].amount = p[j + 1].amount;
        strcpy(p[j].category, p[j + 1].category);

        p[j + 1].amount = aux.amount;
        strcpy(p[j + 1].category, aux.category);
      }
    }
  }

  // Escrevendo no arquivo de Saída
  char str[20];
  strcpy(str, "Category;Amount");
  fprintf(fpSaida, "%s\n", str);
  for (int l = 0; l < i; l++) {
    fprintf(fpSaida, "%s %f\n", p[l].category, p[l].amount);
    printf("%s %f\n", p[l].category, p[l].amount);
  }
  printf("Arquivo de saida gerado!\n"); // se o código executar até aqui, quer dizer que foi gerado um arquivo de saída

  free(p);
  fclose(fp);

  end = clock(); //Pegando o tempo de fim do programa
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  fprintf(fpSaida, "O tempo de execução foi de: %f segundos\n", cpu_time_used); // Imprimindo na última linha o tempo de execução

  fclose(fpSaida);
  return 0;
}