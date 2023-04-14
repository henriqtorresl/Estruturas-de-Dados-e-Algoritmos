#include <stdio.h>

int main(int argc, char const *argv[])
{

    int n, depositoJoao, depositoZe, numTeste = 0;

    scanf("%d", &n);

    while (n != 0) {
        int diferenca = 0;

        numTeste++;
        printf("Teste %d\n", numTeste);

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &depositoJoao, &depositoZe);
            diferenca += depositoJoao - depositoZe;
            printf("%d\n", diferenca);
        }

        printf("\n");

        scanf("%d", &n);
    }
    
    return 0;
}
