#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct cliente {
	char nome[100];
	char cpf[15];
	char setorAtendimento[50];
};

void opcoesAtendimento() {
	printf("Digite uma das op��es de atendimento: \n");
	printf("1 - Abertura de Conta \n");
	printf("2 - Caixa \n");
	printf("3 - Gerente Pessoa F�sica \n");
	printf("4 - Gerente Pessoa Jur�dica \n");
}

void opcoesMenuInicial() {
	printf("Bem vindo ao sistema de atendimento \n");
	printf("Digite uma das op��es: \n");
	printf("1 - Solicitar Atendimento \n");
	printf("2 - Listar Atendimentos Registrados \n");
	printf("3 - Listar Atendimento por Setor \n");
	printf("4 - Sair \n");
}

struct cliente registrarCliente() {
	system("cls");
	struct cliente novoCliente;
	int opcao;
	
	printf("Op��o - Registrar Atendimento\n");
	printf("Digite o seu nome: \n");
	fflush(stdin);
	scanf("%s", &novoCliente.nome);
	printf("Digite o seu CPF: \n");
	fflush(stdin);
	scanf("%s", &novoCliente.cpf);
	
	opcoesAtendimento();
	fflush(stdin);
	scanf("%d", &opcao);
	
	//VALIDAR N�MEROS QUE SEJAM MAIOR QUE 1 E MENOR QUE 4
	while(opcao < 1 || opcao > 4){
		system("cls");
		printf("O n�mero digitado n�o � compat�vel com as op��es dispon�veis\n");
		opcoesAtendimento();
		fflush(stdin);
		scanf("%d", &opcao);
	}
	
	switch (opcao) {
		case 1: {
			strcpy(novoCliente.setorAtendimento, "Abertura de Conta");
			break;
		}
		case 2: {
			strcpy(novoCliente.setorAtendimento, "Caixa");
			break;
		}
		case 3: {
			strcpy(novoCliente.setorAtendimento, "Gerente Pessoa F�sica");
			break;
		}
		case 4: {
			strcpy(novoCliente.setorAtendimento, "Gerente Pessoa Jur�dica");
			break;
		}	
	}
	return novoCliente;
}

void mostrarCliente(struct cliente *vetorEspecifico, int tamanho) {
	system("cls");
	int i;
	for(i = 0; i < tamanho; i++) {
		if(strcmp(&vetorEspecifico[i].cpf, "NULL") != 0){
			printf("Nome: %s\n", &vetorEspecifico[i].nome);
			printf("CPF: %s\n", &vetorEspecifico[i].cpf);
			printf("Tipo Atendimento - %d - %s\n", i+1, &vetorEspecifico[i].setorAtendimento);
			printf("=========================================\n");
		}
	}
}

int main() {
	
	setlocale(LC_ALL, "");
	
	struct cliente vetorGeral[20];
	struct cliente vetorAberturaConta[5];
	struct cliente vetorCaixa[5];
	struct cliente vetorPessoaFisica[5];
	struct cliente vetorPessoaJuridica[5];
	
	//Inicializa��o do cpf em cada vetor
	int i;
	for(i=0; i<20; i++) {
		strcpy(vetorGeral[i].cpf, "NULL");
	}
	//PROBLEMA NA INICIALIZA��O, EST� MOSTRANDO CLIENTES INEXISTENTES
	for(i=0; i<5; i++) {
		strcpy(vetorAberturaConta[i].cpf, "NULL");
		strcpy(vetorCaixa[i].cpf, "NULL");
		strcpy(vetorPessoaFisica[i].cpf, "NULL");
		strcpy(vetorPessoaJuridica[i].cpf, "NULL");
	}
	
	int opcaoAtendimento;
	
	while(opcaoAtendimento != 4){
		
		opcoesMenuInicial();
		fflush(stdin);
		scanf("%d", &opcaoAtendimento);
		
		switch (opcaoAtendimento) {
			case 1: {
				int i;
				for(i = 0; i < 20; i++) {
					if (strcmp(vetorGeral[i].cpf, "NULL") == 0) {
						
						vetorGeral[i] = registrarCliente();
						struct cliente clienteCadastrado = vetorGeral[i];
						
						//Verifica��o e inclus�o do clienteCadastrado no vetor do setor espec�fico
						if(strcmp(clienteCadastrado.setorAtendimento, "Abertura de Conta") == 0) {
							int i;
							for(i=0;i<5;i++){
								if(strcmp(vetorAberturaConta[i].cpf, "NULL") == 0) {
									vetorAberturaConta[i] = clienteCadastrado;
									break;
								}
							}
						}
						if(strcmp(clienteCadastrado.setorAtendimento, "Caixa") == 0) {
							int i;
							for(i=0;i<5;i++){
								if(strcmp(vetorCaixa[i].cpf, "NULL") == 0) {
									vetorCaixa[i] = clienteCadastrado;
									break;
								}
							}
						}
						if(strcmp(clienteCadastrado.setorAtendimento, "Gerente Pessoa F�sica") == 0) {
							int i;
							for(i=0;i<5;i++){
								if(strcmp(vetorPessoaFisica[i].cpf, "NULL") == 0) {
									vetorPessoaFisica[i] = clienteCadastrado;
									break;
								}
							}
						}
						if(strcmp(clienteCadastrado.setorAtendimento, "Gerente Pessoa Jur�dica") == 0) {
							int i;
							for(i=0;i<5;i++){
								if(strcmp(vetorPessoaJuridica[i].cpf, "NULL") == 0) {
									vetorPessoaJuridica[i] = clienteCadastrado;
									break;
								}
							}
						}
						
						break;
					} else if(i == 19){
						printf("Este vetor j� est� completo de registros, n�o � poss�vel registrar mais.\n");
					}
				}
			break;
			}
			//Listagem geral de clientes
			case 2: {
				mostrarCliente(vetorGeral, 20);
				break;
			}
			//Listagem espec�fica de clientes por setor
			case 3: {
				int opcaoSetor;
				
				opcoesAtendimento();
				fflush(stdin);
				scanf("%d", &opcaoSetor);
				
				switch(opcaoSetor){
					case 1: {
						mostrarCliente(vetorAberturaConta, 5);
						break;
					}
					case 2: {
						mostrarCliente(vetorCaixa, 5);
						break;
					}
					case 3: {
						mostrarCliente(vetorPessoaFisica, 5);
						break;
					}
					case 4: {
						mostrarCliente(vetorPessoaJuridica, 5);
						break;
					}
				}	
			break;
			}
			//Sair do programa
			case 4: break;
			default: printf("O n�mero digitado n�o � compat�vel com as op��es dispon�veis\n");
			break;
		}
	}	
	return 0;
}
