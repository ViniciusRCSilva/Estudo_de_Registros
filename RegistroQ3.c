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
	printf("\n1. Cadastrar os tipos de serviços");
	printf("\n2. Cadastrar os serviços prestados");
	printf("\n3. Mostrar os serviços prestados no dia");
	printf("\n0. Sair");
	printf("\nDigite a opção desejada: ");
	
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
	// um vetor de strings para guardar os tipos de serviço
	char tipos[4][10];
	// um vetor de servico para guardar os três serviços diários
	servico servicos[3];
	int i, opcao, contador = 0;
	
	opcao = menu();
	
	while(opcao != 0) {
		
		switch(opcao) {
			case 1: // cadastra os tipos de serviços
				for(i = 0; i < 4; i++) {
					printf("Digite o tipo de serviço: ");
					fgets(tipos[i], 10, stdin);
					fflush(stdin);
				}
				pausar();
				break;
			case 2: // cadastra os serviços prestados no dia
				
//				for (i = 0; i < 3; i++) {
//					printf("Digite número do serviço: ");
//					scanf("%d", &servicos[i].numero);
//					fflush(stdin);
//					
//					printf("Digite o valor do serviço: ");
//					scanf("%f", &servicos[i].valor);
//					fflush(stdin);
//					
//					printf("Digite o código do serviço: ");
//					scanf("%d", &servicos[i].codigo_servico);
//					fflush(stdin);
//					
//					printf("Digite o código do cliente: ");
//					scanf("%d", &servicos[i].codigo_cliente);
//				}
				
				if(contador < 3) {
					printf("Digite número do serviço: ");
					scanf("%d", &servicos[i].numero);
					fflush(stdin);
					
					printf("Digite o valor do serviço: ");
					scanf("%f", &servicos[i].valor);
					fflush(stdin);
					
					printf("Digite o código do serviço: ");
					scanf("%d", &servicos[i].codigo_servico);
					fflush(stdin);
					
					printf("Digite o código do cliente: ");
					scanf("%d", &servicos[i].codigo_cliente);
					
					contador++;
				} else {
					printf("Quantidade máxima de serviços por dia atingido!\n");
				}
				
				pausar();
				break;
			case 3: // exibe os serviços do dia
				printf("\n*** SERVIÇOS DO DIA ***\n");
				
				for (i = 0; i < 3; i++) {
					printf("\nNúmero: %d", servicos[i].numero);
					printf("\nValor: R$%.2f", servicos[i].valor);
					printf("\nCódigo do Serviço: %d", servicos[i].codigo_servico);
					printf("\nCódigo do Cliente: %d", servicos[i].codigo_cliente);
				}
				
				pausar();
				break;
			default:
				printf("\nOpção digitada inválida!\n");
				pausar();
				break;
		}
		
		opcao = menu();
	}
	
	
	return 0;
}
