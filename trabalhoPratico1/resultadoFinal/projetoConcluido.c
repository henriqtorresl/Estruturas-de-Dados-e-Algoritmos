#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

// Definindo o Produto
typedef struct {
  char category[30];
  float amount;
} Produto;

int main() {
  FILE *fp, *fpCopia;
  Produto *p, aux;
  clock_t start, end;
  double cpu_time_used;

  char input[2];
  do { 
    printf("Seu Dataset possui espacos entre as categorias? (s/n)\n");
    scanf("%s", input);
    if (input[0] != 'n' && input[0] != 's') {
      printf("Resposta invalida!\n");
    }
  } while (input[0] != 'n' && input[0] != 's');

  start = clock(); // Pegando o tempo de inicio do programa

  fp = fopen("amazonDataset.csv", "r"); // Abrindo o arquivo para leitura seguido de verificação de erro

  if (fp == NULL) {
    printf("Não foi possível abrir o arquivo!\n");
  } else {
    printf("Arquivo aberto com sucesso!\n");
  }

  p = (Produto *)malloc(1 * sizeof(Produto)); // Alocando o tamanho de 1 produto

  fpCopia = fopen("amazonDatasetOrdenado.csv", "w"); // Abrindo o outro arquivo para Saída

  int i = 0; // Contador para manipular a posição no Vetor
  if (input[0] == 's') {
    while (fscanf(fp, "%s %f", aux.category, &aux.amount) != EOF) {
      p = (Produto *)realloc(p, (i + 1) * sizeof(Produto));
      p[i].amount = aux.amount;
      strcpy(p[i].category, aux.category);
      i++;
    };
  } else {
    while (fscanf(fp, "%s", aux.category) != EOF) {
      char *category = strtok(aux.category, ";"); // Pegando a categoria
      strcpy(aux.category, category);

      char *amount = strtok(NULL, ";"); // Pegando o preço
      aux.amount = strtod(amount, NULL);

      // adicionando o ; no final da categoria
      strcat(aux.category, ";");
      // colocando no vetor p
      p = (Produto *)realloc(p, (i + 1) * sizeof(Produto));
      p[i].amount = aux.amount;
      strcpy(p[i].category, aux.category);
      i++;
    };
  }

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
  for (int l = 0; l < i; l++) {
    fprintf(fpCopia, "%s %f\n", p[l].category, p[l].amount);
  }
  printf("Arquivo de saida gerado!\n"); // se o código executar até aqui, quer dizer que foi gerado um arquivo de saída

  printf("A categoria com o maior valor: %s %f\n", p[0].category, p[0].amount);
  printf("A categoria com o menor valor: %s %f\n", p[i-1].category, p[i-1].amount);
  free(p);
  fclose(fp);

  end = clock(); // Pegando o tempo de fim do programa
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  fprintf(fpCopia, "O tempo de execução foi de: %f segundos\n", cpu_time_used); // Imprimindo na última linha o tempo de execução
  fprintf(fpCopia, "O metodo utilizado foi de Bubble sort que possui complexidade O(n^2) \n"); // Imprimindo a complexidade do código 
  
  printf("O tempo de execucao foi de: %f segundos\n", cpu_time_used); // Imprimindo na última linha o tempo de execução
  printf("O metodo utilizado foi de Bubble sort que possui complexidade O(n^2) \nSendo que para o melhor caso a complexidade diminui para O(n)");

  fclose(fpCopia);
  return 0;
}
