#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int num, iterador = 0;

    while(scanf("%d", &num) != EOF) {
        iterador++;
    }

    printf("%d", iterador);

    return 0;
}
