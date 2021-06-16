#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/* constante para determinar o tamanho do vetor */
#define MAX 3

/* Define uma estrutura que representa uma conta banc�ria */
typedef struct {
	int numero;
	char nome[20];
	float saldo;
} conta;

/* Uma outra forma de declarar a estrutura conta seria assim:
struct conta {
	int numero;
	char nome[20];
	float saldo;
};

Na hora de declarar um vetor de contas ficaria assim:
struct conta contas[MAX];
*/

/* Fun��o menu que mostra as op��es e retorna a op��o escolhida */
int menu() {
	int opcao;
	
	system("cls");
	printf("\n*** MENU ***\n");
	printf("\n1. Cadastrar contas");
	printf("\n2. Visualizar contas");
	printf("\n3. Exibir conta de menor saldo");
	printf("\n0. Sair");
	printf("\nDigite uma op��o: ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	return opcao;
}

/* Prodecimento que pausa a aplica��o */
void pausar() {
	printf("\nDigite qualquer tecla para continuar...");
	getch();
}

int main() {
	setlocale(LC_ALL,"");
	
	// declara um vetor do tipo conta de tamanho MAX
	conta contas[MAX];
	// declara as vari�veis para representar:
	// op��o: opc
	// i: variavel de controle do loop
	// encontrou: vari�vel para indicar se encontrou conta com o nome buscado
	// indMenorSaldo: guarda o indice no vetor com conta de menor saldo
	int opc, i, encontrou, indMenorSaldo;
	// declara string para guardar o nome a ser buscado
	char nome[20];
	// declara variavel para guardar o menor saldo
	float menorSaldo = 99999.99;
	
	// opc recebe o n�mero retornado pela fun��o menu()
	opc = menu();
	
	// enquanto opc for diferente de zero, repita:
	while (opc != 0) {
		
		// testa a op��o digitada
		switch(opc) {
			case 1: // insere as contas dentro do vetor
				
				// percorre o vetor para preencher com os dados
				for (i = 0; i < MAX; i++) {
					printf("Digite n�mero da conta: ");
					scanf("%d", &contas[i].numero);
					fflush(stdin);
					
					printf("Digite nome do cliente: ");
					fgets(contas[i].nome, 20, stdin);
					fflush(stdin);
					
					printf("Digite o saldo da conta: ");
					scanf("%f", &contas[i].saldo);
					fflush(stdin);
				}
				
				pausar();
				break;
			case 2: // exibe todas as contas de um determinado cliente
				printf("Digite o nome para a busca: ");
				fgets(nome, 20, stdin);
				fflush(stdin);
				// encontrou recebe zero para marcar que 
				// ainda n�o foi encontrado nenhuma conta
				// com o nome digitado pelo usu�rio
				encontrou = 0;
				
				
				// percorre o vetor para buscar o nome digitado
				for (i = 0; i < MAX; i++) {
					// compara o nome digitado com o nome da conta na posi��o 'i'
					if(strcmp(nome, contas[i].nome) == 0) {
						printf("\n*** EXIBI��O ***\n");
						printf("\nN�mero: %d", contas[i].numero);
						printf("\nNome: %s", contas[i].nome);
						printf("\nSaldo: R$%.2f", contas[i].saldo);
						encontrou++; // encontrou = encontrou + 1
					}
				}
				
				// caso o nome n�o foi encontrado no vetor contas...
				if(encontrou == 0) {
						printf("\nNome digitado n�o foi encontrado!");
					} 
				
				pausar();
				break;
			case 3: // Exibe conta de menor saldo
			
				// percorre o vetor contas para encontra conta de menor saldo
				for (i = 0; i < MAX; i++) {
					// verifica se o saldo da conta 'i' � menor do que menorSaldo
					if (contas[i].saldo < menorSaldo) {
						menorSaldo = contas[i].saldo;
						// guarda o �ndice do vetor com a conta de menor saldo
						indMenorSaldo = i;
					}
				}
				
				printf("\n*** CONTA DE MENOR SALDO ***\n");
				printf("\nN�mero: %d", contas[indMenorSaldo].numero);
				printf("\nNome: %s", contas[indMenorSaldo].nome);
				printf("\nSaldo: R$%.2f", contas[indMenorSaldo].saldo);
				
				pausar();
				break;
			default:
				printf("\nOp��o digitada inv�lida!\n");
				pausar();
				break;
		}
		
		opc = menu();
	}
	
	return 0;
}
