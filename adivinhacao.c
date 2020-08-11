// (c) COPYRIGHT 2020 HST CARD TECNOLOGY Ltda,
// Campinas (SP), Brasil
// ALL RIGHTS RESERVED – TODOS OS DIREITOS RESERVADOS
// CONFIDENTIAL, UNPUBLISHED PROPERTY OF HST E. E. Ltda
// PROPRIEDADE CONFIDENCIAL NAO PUBLICADA DA HST Ltda. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int secretNumber = rand() % 100;
    int kick = 0;
    int win = 0;
    int attemptCount = 1;
    int attemptNumber = 0;
    int level = 0;
	double point = 1000;
    
    //Print the header of our game
    printf("          P  /_\\  P                                       \n");                 
    printf("         /_\\_|_|_/_\\                                     \n");
    printf("     n_n | ||. .|| | n_n                 Bem vindo ao      \n");
    printf("    |_|_|nnnn nnnn|_|_|           Jogo de Adivinhação!     \n");
    printf("   |" "  |  |_|  |  " "|                                   \n");
    printf("   |_____| ' _ ' |_____|                                   \n");
    printf("         \\__|_|__/                                    \n\n\n");
    
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil \n\n");
    printf("Escolha: ");
    scanf("%d", &level);
    
    switch(level)
    {
        case 1:
            attemptNumber = 20;
            break;
        case 2:
            attemptNumber = 13;
            break;
        default:
            attemptNumber = 6;
            break;
    }
    
    for(int i = 0; i < attemptNumber; i++)
    {
        printf("Tentativa %d!\n", attemptCount);
        do
        {
            printf("Qual é o seu chute? ");
            scanf("%d", &kick);
            printf("Seu chute foi %d.\n", kick);
            if(kick < 0)
            {
                printf("Você não pode chutar números negativos!\n");
            }
        }while(kick < 0);
        
        if(secretNumber == kick)
        {
            win = 1;
            break;
        }
        else
        {
            printf("Você errou!\n");
            printf("Mas não desanime, tente de novo e para isso vou te dar uma dica!\n");
        
            if(secretNumber > kick)
            {
                printf("Seu chute foi menor que o número secreto!\n");
            }
            else
            {
                printf("Seu chute foi maior que o número secreto!\n");
            }
        }
        attemptCount++;
        point = point - abs(kick - secretNumber) / 2.0;
    }
    //print end game
    printf("*****************************************\n");
    printf("************* Fim do jogo!! *************\n");
    printf("*****************************************\n\n");
    
    if(win)
    {
        printf("Parabéns! Você acertou!\n\n");
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");
        printf("Você gastou %d tentativas!\n", attemptCount);
        printf("Total de pontos: %.1f\n", point);
        printf("Jogue de novo, você é um bom jogador!\n");
    }
    else
    {
        printf("Infelismente não foi dessa vez, você perdeu!!\n\n");
        printf("       \\|/ ____ \\|/      \n");
        printf("        @~/ ,. \\~@        \n");
        printf("       /_( \\__/ )_\\      \n");
        printf("          \\__U_/        \n\n");
    }
    return 0;
}

