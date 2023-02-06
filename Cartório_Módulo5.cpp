#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se à string / scanf() armazena o valor informado na string cpf
	
	strcpy(arquivo, cpf);//responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados/pasta
	file = fopen(arquivo, "w");	// abre o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digeite o nome a ser cadastrado: ");
	scanf("%s",nome); //%s refere-se à string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, nome);//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome); //%s refere-se à string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, sobrenome);//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file,",");//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); //%s refere-se à string / scanf() armazena o valor informado na string cpf
	
	file = fopen(arquivo, "a");// abre o arquivo e o "a" significa alterar
	fprintf(file, cargo);//salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //%s refere-se à string / scanf() armazena o valor informado na string cpf
	
	FILE *file; //Seleciona o arquivo no banco de dados/pasta
	file= fopen(cpf, "r");  //Abre o arquivo para leitura com o parâmetro "r"
	
	
	if(file==NULL)//Condicionante p/ opção nula informada pelo usuário
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //Mensagem informada quando a opção do usuário não é válida
	}
	
	while(fgets(conteudo, 200, file) !=NULL)//laço de repetição
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //Armazena os dados informados pelo usiário na string
		printf("\n\n");//Cada \n abre uma linha de espaço. Função para melhor visualização da tela
	}
	fclose(file); //Fecha o arquivo
	system("pause"); //Pausa o sistema
	
}

int deletar() // Início da função deletar
{
	char cpf[40]; // Cria uma string "cpf" do tipo char (caracteres) c/ espaço p/ até 40 variáveis
	
	printf("Digite o CPF do usuário a ser deletado: "); //Imprime na tela a instrução para o usuário indicar qual registro apagar
	scanf("%s",cpf); //Armazena a opção digitada pelo usuário na string "cpf"
	
	remove(cpf); //Apaga o registro do banco de dados com base na string cpf informada
	
	FILE *file; //Entrar na referência FILE na biblioteca e puxar o parâmetro file 
	file = fopen(cpf,"r"); //Abre o arquivo na pasta para leitura com o parâmetro "r" o campo cpf
	
	
	if(file == NULL) //Condicionante para o caso do registro não existir
	{
		printf("O usuário não se encontra no sistema\n"); //Aviso que o registro não existe
		system("pause"); // Pausa o sistema 
	}

	else
	{
		printf("Usuário deletado com sucesso!\n");
		printf("\n\n");
		system("pause");
	}
	
	
}

int main() //É a função principal. Sempre é executada primeiro!
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo valor p/ a variável laco
	
	for(laco=1;laco=1;) //Laço de repetição
	{
		
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("### Escolha a opção desejada do menu:\n\n"); //Cabeçalho/instruções do menu
		printf("\t1 - Registrar nomes\n"); //Cabeçalho/instrução de registro
		printf("\t2 - Consultar nomes\n"); //Cabeçalho/instrução de consulta
		printf("\t3 - Deletar nomes\n\n"); //Cabeçalho/instrução de deletar
		printf("\t4 - Sair do sistema\n\n"); //Cabeçalho para sair do sistema
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //limpa a tela
		
		
		switch(opcao) //início da seleção do menu
		{
			case 1: //compara a opçãp do cliente se é 1
			registro(); //chamada de funções conforme escolha do usuário
			break; // encerra a chamada da opção registro
			
			case 2: //compara a opçãp do cliente se é 2
			consulta(); //chamada de funções conforme escolha do usuário
			break; // encerra a chamada da opção consulta
			
			case 3: //compara a opçãp do cliente se é 3
			deletar(); //chamada de funções conforme escolha do usuário
			break; // encerra a chamada da opção deletar
			
			case 4: //opção do cliente para sair do sistema
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //Retorna 0 para o sistema e, com isso, quebra o laço/função e sai do sistema.
			break; // encerra a chamada da opção sair
			
			default: // Em caso de nenhuma das opções válidas ter sido ecolhido pelo usuário
			printf("Essa opção não está disponível!\n");
			system("pause"); // Pausa o sistema para mostrar ao usuário a mensagem
			break;
			// fim da seleção
		}
		
		
	}
}
