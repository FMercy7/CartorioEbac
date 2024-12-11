#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca para manipulação de strings

int registro() //Função responsável por cadastrar os usuários
{
	//inicio criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação de usuário
    scanf("%s", cpf); //%s refere-sea string
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
    
    FILE *file = fopen(arquivo, "w"); // cria o arquivo
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1; // Encerra a função em caso de erro
    }
    fprintf(file, "%s", cpf); // salva o valor da variável
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
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
    	printf("O usuário não se encontra no sistema.\n");
    	system("pause");
	}
	
}

int main()
{
    int opcao = 0; // definição de variáveis
    while (1) // loop infinito até o usuário decidir sair
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese");

        printf("Escolha a opção desejada do menu: \n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n\n");
        printf("Opção: ");//fim do menu

        scanf("%d", &opcao); // armazenamento da escolha do usuário

        system("cls"); //responsavel por limpar a tela

        switch(opcao) //inicio das seleções
        {
            case 1:
                registro(); //chamada de funções
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
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }

}

