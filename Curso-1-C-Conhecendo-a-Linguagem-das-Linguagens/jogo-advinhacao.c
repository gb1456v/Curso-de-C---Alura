#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	printf("******************************************\n");
	printf("* Bem vindo ao nosso jogo de adivinhacao *\n");	
	printf("******************************************\n");
    int segundos = time(0);
    srand(segundos);
    int numero_grande=rand();
	int numero_secreto = numero_grande % 100;
	int chute=0;
    int ganhou=0; 
    int tentativas=0;
    int nivel=0;
    double pontos = 1000;
    printf("Escolha o nível de dificuldade: (1) Fácil (2) Médio (3) Difícil\n");
    scanf("%d", &nivel);
    switch(nivel) {
        case 1:
            tentativas = 20;
            break;
        case 2:
            tentativas = 14;
            break;
        case 3:
            tentativas = 6;
            break;
    }
    for(int i= 1; i <= tentativas; i++) {
        printf("Qual número você acha que é?\n");
        scanf("%d", &chute);
        if(chute==numero_secreto) {
            printf("Parabéns!! Você acertou o número secreto!\n",tentativas);
            break;
        } else {
            printf("\nVocê chutou o número %d\n", chute);
            printf("\nVocê errou!\n");
            if(chute>numero_secreto) {
                printf("O numero secreto é menor do que o número que você digitou!\n");
            } else {
                printf("\nO numero secreto é maior do que o número que você digitou!\n");
            }
            double pontos_perdidos = abs(((double)chute - numero_secreto) /2);
            pontos = pontos-pontos_perdidos;
            if(tentativas > 1) {
                printf("Você ainda tem %d tentativas\n", (tentativas - i));
            } else {
                printf("Você ainda tem %d tentativa\n", (tentativas - i));
            }
            
            printf("Você tem %2.lf pontos nesta rodada!\n", pontos);
        }
    }
    printf("Fim de jogo!");
}