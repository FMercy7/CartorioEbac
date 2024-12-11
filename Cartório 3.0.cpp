#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca para manipula��o de strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios
{
	//inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o de usu�rio
    scanf("%s", cpf); //%s refere-sea string
    
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
    
    FILE *file = fopen(arquivo, "w"); // cria o arquivo
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1; // Encerra a fun��o em caso de erro
    }
    fprintf(file, "%s", cpf); // salva o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return 1;
    }
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return 1;
    }
    fprintf(file, "%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return 1;
    }
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return 1;
    }
    fprintf(file, "%s", sobrenome);
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para adicionar dados.\n");
        return 1;
    }
    fprintf(file, "%s", cargo);
    fclose(file);
    
    system("pause");
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");
	  
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema.\n");
    	system("pause");
	}
	
}

int main()
{
    int opcao = 0; // defini��o de vari�veis
    while (1) // loop infinito at� o usu�rio decidir sair
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese");

        printf("Escolha a op��o desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
        printf("Op��o: ");//fim do menu

        scanf("%d", &opcao); // armazenamento da escolha do usu�rio

        system("cls"); //responsavel por limpar a tela

        switch(opcao) //inicio das sele��es
        {
            case 1:
                registro(); //chamada de fun��es
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 4:
                printf("Saindo...\n");
                exit(0); // Encerra o programa
                break;

            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }

}

