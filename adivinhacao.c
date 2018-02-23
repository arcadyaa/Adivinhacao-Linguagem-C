#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //acentos

int main() 
{
	setlocale(LC_ALL, "Portuguese"); //acentos
	
	// Imprime cabe�alho do nosso jogo.
	printf("        *************************************\n");
	printf("        * BEM VINDO AO JOGO DE ADIVINHA��O! *");
	printf("\n        *************************************\n");
	
	int segundos = time(0);
	srand(segundos);
	
	int numerogrande = rand();
	
	int numerosecreto = numerogrande % 100;
	int chute;
	int tentativas = 1;
	double  pontos = 1000;
	
	int acertou = 0;
	
	int nivel;
	printf("Qual o n�vel de dificuldade?\n");
	printf("(1) F�cil (2) M�dio (3)Dif�cil\n\n");
	printf("Escolha: ");
	scanf("%d", &nivel);
	
	int numerodetentativas;
	
	switch(nivel){
		case 1: 
			numerodetentativas = 20; 
			break;
		case 2: 
			numerodetentativas = 15; 
			break;
		default: 
			numerodetentativas = 6;  
			break;
	}

	for(int i = 1; i <= numerodetentativas; i++)
	{
		printf("\nTentativa %d\n", tentativas);
		printf("\nChute um n�mero qualquer: ");
		
		scanf("%d", &chute);
		printf("Seu chute foi %d\n", chute);
		
		if(chute < 0){
			printf("Voc� n�o pode chutar n�meros negativos!\n");
			continue;
		}
		
		int acertou = (chute == numerosecreto);
		int maior = chute > numerosecreto;
		
		if(acertou)
		{
			break;
		}
		
		else if(maior){
			printf("Seu chute foi maior que o n�mero secreto.\n");
		} 
		 
		else {
			printf("Seu chute foi menor que o n�mero secreto.\n");
		}
	
		tentativas++;
		
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
	}
	
	printf("\nFIM DE JOGO!\n");
	
	if(acertou) {
		printf("Voc� ganhou!\n");
		printf("Voc� acertou em %d tentativas\n", tentativas);
		printf("Total de pontos: %.1f\n", pontos);
	} else {
		printf("Voc� perdeu! Tente novamente!");
	}
	
	getch();
	return 0;
}
