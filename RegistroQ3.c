#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//typedef struct {
//	int codigo;
//	char nome[10];
//} tipo_servico;

typedef struct {
	int numero;
	float valor;
	int codigo_servico;
	int codigo_cliente;
} servico;

int menu() {
	int opc;
	
	system("cls");
	printf("\n*** MENU ***\n");
	printf("\n1. Cadastrar os tipos de servi�os");
	printf("\n2. Cadastrar os servi�os prestados");
	printf("\n3. Mostrar os servi�os prestados no dia");
	printf("\n0. Sair");
	printf("\nDigite a op��o desejada: ");
	
	scanf("%d", &opc);
	fflush(stdin);
	system("cls");
	return opc;
	
}

void pausar() {
	printf("\nDigite qualquer tecla para continuar...");
	getch();
}

int main() {
	setlocale(LC_ALL, "");
	// um vetor de strings para guardar os tipos de servi�o
	char tipos[4][10];
	// um vetor de servico para guardar os tr�s servi�os di�rios
	servico servicos[3];
	int i, opcao, contador = 0;
	
	opcao = menu();
	
	while(opcao != 0) {
		
		switch(opcao) {
			case 1: // cadastra os tipos de servi�os
				for(i = 0; i < 4; i++) {
					printf("Digite o tipo de servi�o: ");
					fgets(tipos[i], 10, stdin);
					fflush(stdin);
				}
				pausar();
				break;
			case 2: // cadastra os servi�os prestados no dia
				
//				for (i = 0; i < 3; i++) {
//					printf("Digite n�mero do servi�o: ");
//					scanf("%d", &servicos[i].numero);
//					fflush(stdin);
//					
//					printf("Digite o valor do servi�o: ");
//					scanf("%f", &servicos[i].valor);
//					fflush(stdin);
//					
//					printf("Digite o c�digo do servi�o: ");
//					scanf("%d", &servicos[i].codigo_servico);
//					fflush(stdin);
//					
//					printf("Digite o c�digo do cliente: ");
//					scanf("%d", &servicos[i].codigo_cliente);
//				}
				
				if(contador < 3) {
					printf("Digite n�mero do servi�o: ");
					scanf("%d", &servicos[i].numero);
					fflush(stdin);
					
					printf("Digite o valor do servi�o: ");
					scanf("%f", &servicos[i].valor);
					fflush(stdin);
					
					printf("Digite o c�digo do servi�o: ");
					scanf("%d", &servicos[i].codigo_servico);
					fflush(stdin);
					
					printf("Digite o c�digo do cliente: ");
					scanf("%d", &servicos[i].codigo_cliente);
					
					contador++;
				} else {
					printf("Quantidade m�xima de servi�os por dia atingido!\n");
				}
				
				pausar();
				break;
			case 3: // exibe os servi�os do dia
				printf("\n*** SERVI�OS DO DIA ***\n");
				
				for (i = 0; i < 3; i++) {
					printf("\nN�mero: %d", servicos[i].numero);
					printf("\nValor: R$%.2f", servicos[i].valor);
					printf("\nC�digo do Servi�o: %d", servicos[i].codigo_servico);
					printf("\nC�digo do Cliente: %d", servicos[i].codigo_cliente);
				}
				
				pausar();
				break;
			default:
				printf("\nOp��o digitada inv�lida!\n");
				pausar();
				break;
		}
		
		opcao = menu();
	}
	
	
	return 0;
}
