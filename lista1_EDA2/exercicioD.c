#include <stdio.h>

int main() {

    int qnt, dia = 0, codigo, avaliacao;
    int maiorCodigo = 0;
    int maioravAliacao = 0;
    while(scanf("%d", &qnt) != EOF) {
        for(int i = 0; i < qnt; i++) {
            scanf("%d%d", &codigo, &avaliacao);
            if(avaliacao > maioravAliacao || (avaliacao == maioravAliacao && codigo < maiorCodigo)) {
                maiorCodigo = codigo;
                maioravAliacao = avaliacao;
            }
        }
        dia++;
        printf("Dia %d\n", dia);
        printf("%d\n\n", maiorCodigo);
    }

    return 0;
}