#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se � string / scanf() armazena o valor informado na string cpf
	
	strcpy(arquivo, cpf);//respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados/pasta
	file = fopen(arquivo, "w");	// abre o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digeite o nome a ser cadastrado: ");
	scanf("%s",nome); //%s refere-se � string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, nome);//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //%s refere-se � string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, sobrenome);//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //%s refere-se � string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, cargo);//salvo o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se � string / scanf() armazena o valor informado na string cpf
	
	FILE *file; //Seleciona o arquivo no banco de dados/pasta
	file= fopen(cpf, "r");  //Abre o arquivo para leitura com o par�metro "r"
	
	
	if(file==NULL)//Condicionante p/ op��o nula informada pelo usu�rio
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //Mensagem informada quando a op��o do usu�rio n�o � v�lida
	}
	
	while(fgets(conteudo, 200, file) !=NULL)//la�o de repeti��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //Armazena os dados informados pelo usi�rio na string
		printf("\n\n");//Cada \n abre uma linha de espa�o. Fun��o para melhor visualiza��o da tela
	}
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o sistema
	
}

int deletar() // In�cio da fun��o deletar
{
	char cpf[40]; // Cria uma string "cpf" do tipo char (caracteres) c/ espa�o p/ at� 40 vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Imprime na tela a instru��o para o usu�rio indicar qual registro apagar
	scanf("%s",cpf); //Armazena a op��o digitada pelo usu�rio na string "cpf"
	
	remove(cpf); //Apaga o registro do banco de dados com base na string cpf informada
	
	FILE *file; //Entrar na refer�ncia FILE na biblioteca e puxar o par�metro file 
	file = fopen(cpf,"r"); //Abre o arquivo na pasta para leitura com o par�metro "r" o campo cpf
	
	
	if(file == NULL) //Condicionante para o caso do registro n�o existir
	{
		printf("O usu�rio n�o se encontra no sistema\n"); //Aviso que o registro n�o existe
		system("pause"); // Pausa o sistema 
	}

	else
	{
		printf("Usu�rio deletado com sucesso!\n");
		printf("\n\n");
		system("pause");
	}
	
	
}

int main() //� a fun��o principal. Sempre � executada primeiro!
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo valor p/ a vari�vel laco
	
	for(laco=1;laco=1;) //La�o de repeti��o
	{
		
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("### Escolha a op��o desejada do menu:\n\n"); //Cabe�alho/instru��es do menu
		printf("\t1 - Registrar nomes\n"); //Cabe�alho/instru��o de registro
		printf("\t2 - Consultar nomes\n"); //Cabe�alho/instru��o de consulta
		printf("\t3 - Deletar nomes\n\n"); //Cabe�alho/instru��o de deletar
		printf("\t4 - Sair do sistema\n\n"); //Cabe�alho para sair do sistema
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //limpa a tela
		
		
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1: //compara a op��p do cliente se � 1
			registro(); //chamada de fun��es conforme escolha do usu�rio
			break; // encerra a chamada da op��o registro
			
			case 2: //compara a op��p do cliente se � 2
			consulta(); //chamada de fun��es conforme escolha do usu�rio
			break; // encerra a chamada da op��o consulta
			
			case 3: //compara a op��p do cliente se � 3
			deletar(); //chamada de fun��es conforme escolha do usu�rio
			break; // encerra a chamada da op��o deletar
			
			case 4: //op��o do cliente para sair do sistema
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //Retorna 0 para o sistema e, com isso, quebra o la�o/fun��o e sai do sistema.
			break; // encerra a chamada da op��o sair
			
			default: // Em caso de nenhuma das op��es v�lidas ter sido ecolhido pelo usu�rio
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); // Pausa o sistema para mostrar ao usu�rio a mensagem
			break;
			// fim da sele��o
		}
		
		
	}
}
