#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocção de espaço em memória
#include <locale.h> //Biblioteca de alicações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//Inicio criação de variáveis (string)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final criação de variáveis (string)
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	FILE *file; //Cria o arquivo no nosso banco de daddos (PC)
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta, o "W" significa escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta, o "a" significa atualizar
	fprintf(file,","); //Salva a variavel separando por virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome);//%s refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta, o "a" significa atualizar
	fprintf(file,nome);  //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //Salva a variavel separando por virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta, o "a" significa atualizar
	fprintf(file,sobrenome);  //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta, o "a" significa atualizar
	fprintf(file,","); //Salva a variavel separando por virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Cria o arquivo na pasta, o "a" significa atualizar
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	system("pause");

}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF a ser contultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não foi localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssa são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do uduário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("_____ Cartório da EBAC _____\n\n"); //Inicio do MENU
		printf("Escolha a opção desejada do MENU:\n\n");
		printf("\t1) - Registrar nomes\n");
		printf("\t2) - Consultar nomes\n");
		printf("\t3) - Deletar nomes\n");
		printf("\t4) - Sair do sistema\n\n"); 
		printf("Opção desejada: "); //Fim do MENU
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário

		system("cls"); //Reponsavél por limpar a tela
		
		
		switch(opcao) //Inicio da seleção do MENU
		{
			case 1:
			registro(); //Chamada da função de registro
			break;
			
			case 2:
			consulta(); //Chamada da função de consulta
			break;
			
			case 3:
			deletar(); //Chamada da função de deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponivél! Tente novamente!\n");
			system("pause");
			break;
			//Fim da seleção do MENU
		}
		
	}
}

