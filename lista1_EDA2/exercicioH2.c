#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[21];
    int problemas_resolvidos;
};

int main() {
    int n, i, min_problemas_resolvidos;
    struct Aluno alunos[100], aluno_reprovado;

    int instancia = 1;

    while (scanf("%d", &n) == 1) {
        // Leitura dos dados dos alunos
        for (i = 0; i < n; i++) {
            scanf("%s %d", alunos[i].nome, &alunos[i].problemas_resolvidos);
        }

        // Ordenação dos alunos pelo número de problemas resolvidos
        for (i = 0; i < n; i++) {
            int j;
            struct Aluno tmp = alunos[i];
            for (j = i; j > 0 && (alunos[j-1].problemas_resolvidos < tmp.problemas_resolvidos || (alunos[j-1].problemas_resolvidos == tmp.problemas_resolvidos && strcmp(alunos[j-1].nome, tmp.nome) > 0)); j--) {
                alunos[j] = alunos[j-1];
            }
            alunos[j] = tmp;
        }

        // O aluno reprovado é o último da lista ordenada
        aluno_reprovado = alunos[n-1];
        
        // Impressão dos resultados
        printf("Instancia %d\n", instancia++);
        printf("%s\n\n", aluno_reprovado.nome);
    }

    return 0;
}
