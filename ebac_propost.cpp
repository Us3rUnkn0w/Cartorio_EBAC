#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca de responsável por cuidar das strings
// Bruno S. Marzola - Developer - 10/01/2025
// Software para Cadastramento, Colsulta e Deletar usuário (demanda do curso EBAC)
// Software for Register, Consult and Delete users (demand of the EBAC course)
int registro() { //aqui vai ser onde o usuário vai ser cadastrado / Here is the where will be the user register
	char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); //registro do CPF / CPF register
    
    strcpy(arquivo, cpf);
    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n"); //código de erro se falhar / error code if something is wrong
        return 1;
    }
    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o Nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "%s,", cargo);
    fclose(file);
	
    system("pause");
    return 0;
}//fim do registro / the end of register

int consulta() {//aqui vai ser onde o usuário vai ser consultado / Here is the where will be the user consult 
    setlocale(LC_ALL, "Portuguese");
	/*adicionar uma opção que exibe os usuários e mostra o valor total de usuários cadastrados
	1 - Consultar todos os usuários
	2 - Numeros de Usuários cadastrados
	3 - Voltar ao menu
	*/
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("Arquivo não disponível, arquivo não encontrado!\n\n");
        return 1;
    }

    printf("Essas são as informações do usuário:\n\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);

    system("pause");
    return 0;
}

int deletar() {//aqui vai ser onde o usuário vai ser deletado / Here is the where will be the user's delete
    char cpf[40];
	//adicionar uma opção de checagem, "Quer mesmo deletar esse usuário?", "Se Sim, Pressione Y e Tecla enter", "Se Não, Pressione "N" e a Tecla enter"
	//Isso previne de deletar usuários errados
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("O usuário não foi encontrado ou não existe no sistema.\n");
    }
    system("pause");
    return 0;
}// o fim do registro / the end of consult

int erro() {
    printf("Essa opção não está disponível\n\n\n\n");
    system("pause");
    return 0;
}

int main() {// aqui é o menu, com um bunner e as opções de escolha / here is the menu, with a banner and choose the options
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");//seleção de idioma com base na biblioteca <locale.h> (Idioma Português) / language selection based on <locale.h> library (Portuguese language)

    do {
        system("cls");
        printf("#########################################\n");// um banner simples / a simple banner
        printf("#\tPortal de Cadastro EBAC\t\t#\n");
        printf("#########################################\n\n");
        printf("Opções do Menu:\n\n");
        printf("\t1 - Cadastramento de Usuário\n");//option 1 - register user
        printf("\t2 - Busca de Usuário\n");// option 2 - consult user - the CPF is the key/value to consult
        printf("\t3 - Remoção de Usuário\n");//option 3 - delete user
      	printf("\t4 - Sair\n\n");//option 4 - exit  
		printf("Opção: ");
        scanf("%d", &opcao);
        system("cls");//limpeza de tela / clear screen
        
        switch (opcao) {
            case 1:
            registro();
            break;
            	
			case 2:
            consulta();
            break;
            	
			case 3:
            deletar();
            break;
        		
			case 4:
			printf("Saindo do sistema... Até mais\n");
            return 0;
            break;
        default:
            erro();
            break;
        }
    } while (opcao != 4);

    return 0;
}// o fim do menu / the end of menu
