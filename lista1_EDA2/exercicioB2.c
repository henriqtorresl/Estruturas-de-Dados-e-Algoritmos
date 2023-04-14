#include <stdio.h>

int main(int argc, char const *argv[])
{
    int qnt, num, soma = 0;

    scanf("%d", &qnt);

    for(int i = 0; i < qnt; i++) {
        scanf("%d", &num);
        soma += num;
    }

    printf("%d", soma);

    return 0;
}
