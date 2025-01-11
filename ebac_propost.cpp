#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca de respons�vel por cuidar das strings
// Bruno S. Marzola - Developer - 10/01/2025
// Software para Cadastramento, Colsulta e Deletar usu�rio (demanda do curso EBAC)
// Software for Register, Consult and Delete users (demand of the EBAC course)
int registro() { //aqui vai ser onde o usu�rio vai ser cadastrado / Here is the where will be the user register
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
        printf("Erro ao abrir o arquivo!\n"); //c�digo de erro se falhar / error code if something is wrong
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

int consulta() {//aqui vai ser onde o usu�rio vai ser consultado / Here is the where will be the user consult 
    setlocale(LC_ALL, "Portuguese");
	/*adicionar uma op��o que exibe os usu�rios e mostra o valor total de usu�rios cadastrados
	1 - Consultar todos os usu�rios
	2 - Numeros de Usu�rios cadastrados
	3 - Voltar ao menu
	*/
    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("Arquivo n�o dispon�vel, arquivo n�o encontrado!\n\n");
        return 1;
    }

    printf("Essas s�o as informa��es do usu�rio:\n\n");
    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);

    system("pause");
    return 0;
}

int deletar() {//aqui vai ser onde o usu�rio vai ser deletado / Here is the where will be the user's delete
    char cpf[40];
	//adicionar uma op��o de checagem, "Quer mesmo deletar esse usu�rio?", "Se Sim, Pressione Y e Tecla enter", "Se N�o, Pressione "N" e a Tecla enter"
	//Isso previne de deletar usu�rios errados
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("O usu�rio n�o foi encontrado ou n�o existe no sistema.\n");
    }
    system("pause");
    return 0;
}// o fim do registro / the end of consult

int erro() {
    printf("Essa op��o n�o est� dispon�vel\n\n\n\n");
    system("pause");
    return 0;
}

int main() {// aqui � o menu, com um bunner e as op��es de escolha / here is the menu, with a banner and choose the options
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");//sele��o de idioma com base na biblioteca <locale.h> (Idioma Portugu�s) / language selection based on <locale.h> library (Portuguese language)

    do {
        system("cls");
        printf("#########################################\n");// um banner simples / a simple banner
        printf("#\tPortal de Cadastro EBAC\t\t#\n");
        printf("#########################################\n\n");
        printf("Op��es do Menu:\n\n");
        printf("\t1 - Cadastramento de Usu�rio\n");//option 1 - register user
        printf("\t2 - Busca de Usu�rio\n");// option 2 - consult user - the CPF is the key/value to consult
        printf("\t3 - Remo��o de Usu�rio\n");//option 3 - delete user
      	printf("\t4 - Sair\n\n");//option 4 - exit  
		printf("Op��o: ");
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
			printf("Saindo do sistema... At� mais\n");
            return 0;
            break;
        default:
            erro();
            break;
        }
    } while (opcao != 4);

    return 0;
}// o fim do menu / the end of menu
