#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>          // biblioteca da função 'isdigit()'

int main(int argc, char const *argv[])
{
    int qntStr;
    char str[101];      // tamanho max da string é 100 + 1 (char do '\0')
    int somaDig = 0;

    scanf("%d", &qntStr);
    for(int i = 0; i < qntStr; i++) {
        scanf("%s", str);   // lendo a string..
        somaDig = 0;    // garantindo que vai resetar o valor de somaDig, na hora de somar a proxima str...
        for(int j = 0; j < strlen(str); j++) {   // percorrer a string
            if(isdigit(str[j])) {   // verifica se o char é ou não um digito inteiro
                somaDig += str[j] - '0';  // convertendo o char em int...
            }
        }
        printf("%d\n", somaDig);
    }

    return 0;
}