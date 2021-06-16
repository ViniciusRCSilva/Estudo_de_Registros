#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define TAM 3

// declara um registro para armazenar
// os dados do candidato
typedef struct {
	char nome[20];
	float nota;
} candidato;

// função retorna a opção
// escolhida pelo usuário
int menu() {
	int opt;
	
	system("cls");
	printf("\n*** MENU ***\n");
	printf("\n1. Inserir notas e nomes");
	printf("\n2. Exibir media geral");
	printf("\n3. Imrpimir maior e menor notas");
	printf("\n4. Buscar candidato");
	printf("\n0. Sair do programa");
	printf("\n\nDigite uma opcao: ");
	
	scanf("%d", &opt);
	fflush(stdin);
	
	system("cls");
	return opt;
}

int main() {
	// declara um vetor do tipo candidato
	candidato candidatos[TAM];
	// declara as variáveis com maior menor nota
	float maior = 0.0, menor = 9999.9;
	// declara variáveis de controle
	int i, opcao;
	// variáveis que armazenam os indices
	int indice, i_menor, i_maior, i_busca = -1;
	// declara string para realizar a busca
	char nome_busca[20];
	// variável para calcular a média geral
	float media = 0;
	
	// chama a função que retorna a opção escolhida
	opcao = menu();
	
	// enquanto opção for diferente de zero, faça:
	while (opcao != 0) {
		
		// escolha a opção
		switch (opcao) {
			case 1: // inserir dados no vetor candidatos
				for(i = 0; i < TAM; i++) {
					printf("Digite nome: ");
					gets(candidatos[i].nome);
					
					printf("Digite nota: ");
					scanf("%f", &candidatos[i].nota);
					fflush(stdin);
				}
				
				printf("\n\nDigite qualquer tecla para continuar...");
				getch();
				break;
			case 2: // Calcular a média geral de notas
				printf("\n\nImprimindo a media geral...\n\n");
				for (i = 0; i < TAM; i++) {
					media += candidatos[i].nota;
				}
				
				media /= TAM;
				
				printf("\nMedia Geral: %.1f", media);
				
				printf("\n\nDigite qualquer tecla para continuar...");
				getch();
				break;
			case 3:
				printf("\n\nImprimindo a menor e maior notas...\n\n");
				for (i = 0; i < TAM; i++) {
					if(candidatos[i].nota > maior) {
						maior = candidatos[i].nota;
						// guarda o indice da maior nota
						// encontrada até agora
						i_maior = i;
					}
					
					if(candidatos[i].nota < menor) {
						menor = candidatos[i].nota;
						// guarda o indice da menor nota
						// encontrada até agora
						i_menor = i;
					}
				}
				
				printf("\nMaior Nota\n");
				printf("\nNome: %s", candidatos[i_maior].nome);
				printf("\nNota:%.1f", candidatos[i_maior].nota);
				
				printf("\nMenor Nota\n");
				printf("\nNome: %s", candidatos[i_menor].nome);
				printf("\nNota:%.1f", candidatos[i_menor].nota);
				
				printf("\n\nDigite qualquer tecla para continuar...");
				getch();
				break;
			case 4:
				printf("\n\nPesquisando um candidato...\n\n");
				
				printf("Digite nome: ");
				gets(nome_busca);
				
				for(i = 0; i < TAM; i++) {
					// compara candidatos[i].nome com nome_busca
					if(strcmp(candidatos[i].nome, nome_busca)) {
						// guarda o indice onde o nome da busca está
						i_busca = i;
					}
				}
				
				// caso i_busca seja < 0 
				if( i_busca < 0) {
					printf("\nCandidato nao encontrado!\n");
				} else {
					printf("\nNome: %s", candidatos[i_busca].nome);
					printf("\nNota: %.1f", candidatos[i_busca].nota);
				}
				
				i_busca = -1;
				
				printf("\n\nDigite qualquer tecla para continuar...");
				getch();
				
				break;
			default:
				printf("\nOpcao invalida!\n");
				printf("\n\nDigite qualquer tecla para continuar...");
				getch();		
		}
		
		opcao = menu();
	}	
	return 0;
}
