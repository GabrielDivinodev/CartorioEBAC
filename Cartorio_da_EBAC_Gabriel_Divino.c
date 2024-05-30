#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>	//biblioteca responsável por cuidar das strings

int registrar() // Função responsável por cadastrastar os usuários
{
	//inicio da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis
	
	printf("Digite o cpf a ser cadastrado: "); //coltando informação do usuário
	scanf("%s",cpf); //armazena o valor da string (%s)
	
	strcpy(arquivo,cpf); //responsável por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //cria o arquivo ("w" = escrever)
	fprintf(file, "CPF: "); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file, "|| Nome: "); //salva o valor da variável
	fclose(file); //fecha o arquivo	
		
	printf("Digite o nome a ser cadastrado: "); //coltando informação do usuário
	scanf("%s", nome); //armazena o valor da string (%s)
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file, "|| Sobrenome: "); //salva o valor da variável
	fclose(file); //fecha o arquivo	
	
	printf("Digite o sobrenome a ser cadastrado: "); //coltando informação do usuário
	scanf("%s", sobrenome); //armazena o valor da string 
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file, "|| Cargo: "); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coltando informação do usuário
	scanf("%s",cargo); //armazena o valor da string (%s)
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualização)
	fprintf(file, "||"); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	contreg(); //redirecionar para a função contreg(continuar registrando)
	system("pause"); //pausa as informações da interface
	
} //fim da função "registrar"

int consultar() // Função responsável por consultar os usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variáveis
	char cpf[40];
	char conteudo[200];
	//fim da criação de variáveis
	
	printf("Digite o cpf a ser consultado: "); //coltando informação do usuário
	scanf("%s", cpf); //armazena o valor da string (%s)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo ("r" = ler)
	
	if(file == NULL) //condição
	{
		printf("\n\nNão foi possível acessar o arquivo, não localizado! \n\n");
		contconsul(); //redirecionar para a função contconsul(continuar consultando)
	}
	
	while(fgets(conteudo,200,file) != NULL) //condição
	{
		printf("==================================================================================\n");
		printf("\n\tEssas são as informações do usuário: \n\n");
		printf(" %s",conteudo);
		printf("\n\n==================================================================================\n\n");
	}	
	
	contconsul(); //redirecionar para a função contconsul(continuar consultando)
	system("pause"); //pausar a interface
	fclose(file); //fecha o arquivo
} //fim da função "consultar"

int deletar() // Função responsável por deletar os usuários
{
	int simenao=0; //definindo uma classe
	int lacoI=1; //definindo um laço
	
	for(lacoI=1;lacoI=1;) //inicio do laço de repetição
	{
		system("cls"); //limpar a interface
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//inicio da criação de variáveis
		char cpf[40];	
		//fim da criação de variáveis
		
		printf("Digite o CPF do usuário a ser deletado: "); //coltando informação do usuário
		scanf("%s",cpf); //armazena o valor da string (%s)
	
		FILE *file; //cria o arquivo
		file = fopen(cpf,"r"); //abre o arquivo ("r" = ler)
	
		if(file == NULL) //condição
		{
			printf("\n\tEsse usuário não existe!\n\n");
			contdel(); //redirecionando para a função "contdel(constinuar deletando)"
			system("pause"); //pausar a interface
		}
		fclose(file); //fecha o arquivo
			
		printf("\nVocê tem certeza de que quer deletar esse usuário?\n\n");
		printf("\t1-Sim\n"); //opção
		printf("\t2-Não\n\n"); //opção
		printf("opção: "); //coletando informação do usuário
		scanf("%d", &simenao); //armazena o valor na variável (%d)
		system("cls"); //limpar a interface
			
		switch(simenao) //inicio da seleção
		{
			case 1: 
			remove(cpf); //exclui o cpf digitado
			printf("\n\tUsuário deletado com sucesso!\n\n");
			contdel(); //redirecionando para a função "contdel(constinuar deletando)"
			system("pause"); //pausar a interface
			break; //encerrando o "case"

			case 2:
			printf("\n\tVocê desistiu de deletar o usuário!\n\n");
			contdel(); //redirecionando para a função "contdel(constinuar deletando)"
			system("pause"); //pausar a interface
			break; //encerrando o "case"
			
			default:
			printf("\tEssa opção não está disponível!\n\n"); //caso o usuário digite qualquer opção não listada anteriormente
			system("pause"); //pausar a interface
			break; //encerrando o "case"		
		} //fim da seleção
	} //fim do laço de repetição
} //fim da função "deletar"

int fechar() // Função responsável fechar o programa
{
	int opcao; //definindo uma classe
	
	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("Você tem certeza de que quer fechar o programa?\n\n");
	printf("\t1-Sim\n"); //opção
	printf("\t2-Não\n\n"); //opção
	printf("opção: "); //coltando informação do usuário
	
	scanf("%d", &opcao); //armazena o valor na variável (%d)
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		system("cls"); //limpar a interface
		printf("Obrigado por utilizar o sistema!\n\n");
		exit(0); //encerramento do programa	
		break; //encerrando o "case"
		
		case 2:
		main(); //redirecionando para a função "main" / função principal
		break; //encerrando o "case"
		
		default:
		printf("\n\nEssa opção não está disponível!\n\n"); //caso o usuário digite qualquer opção não listada anteriormente
		system("pause"); //pausar a interface
		main(); //redirecionando para a função "main" / função principal
		break; //encerrando o "case"
	} //fim da seleção
} //fim da função "fechar"

int contreg() //função para continuar registrando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar registrando?\n\n");
	printf("\t1-Sim\n"); //opção
	printf("\t2-Não\n\n"); //opção
	printf("opção: "); //coletando informação do usuário
	
	scanf("%d", &opcao); //armazena o valor na variável (%d)
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		system("cls"); //limpar a interface
		registrar(); //redirecionando para a função "registrar"
		break; //encerrando o "case"
			
		case 2:
		main(); //redirecionando para a função "main"
		break; //encerrando o "case"
			
		default:
		printf("\tEssa opção não está disponível! \n\n"); //caso o usuário digite qualquer opção não listada anteriormente
		system("pause"); //pausar a interface
		break; //encerrando o "case"
	}
	
}

int contconsul() //função para continuar consultando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar consultando?\n\n");
	printf("\t1-Sim\n"); //opção
	printf("\t2-Não\n\n"); //opção
	printf("opção: "); //coletando informação do usuário
	
	scanf("%d", &opcao); //armazena o valor na variável (%d)
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		system("cls"); //limpar a interface
		consultar(); //redirecionando para a função "consultar"
		break; //encerrando o "case"
			
		case 2:
		main(); //redirecionando para a função "main"
		break; //encerrando o "case"
			
		default:
		printf("\tEssa opção não está disponível! \n\n"); //caso o usuário digite qualquer opção não listada anteriormente
		system("pause"); //pausar a interface
		break; //encerrando o "case"
	}
	
}

int contdel() //função para continuar deletando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar deletando?\n\n");
	printf("\t1-Sim\n"); //opção
	printf("\t2-Não\n\n"); //opção
	printf("opção: "); //coletando informação do usuário
	
	scanf("%d", &opcao); //armazena o valor na variável (%d)
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		system("cls"); //limpar a interface
		deletar(); //redirecionando para a função "deletar"
		break; //encerrando o "case"
			
		case 2:
		main(); //redirecionando para a função "main"
		break; //encerrando o "case"
			
		default:
		printf("\tEssa opção não está disponível! \n\n"); //caso o usuário digite qualquer opção não listada anteriormente
		system("pause"); //pausar a interface
		break; //encerrando o "case"
	}
	
}

int main() // Função principal do programa
{
	
	int opcao=0; //definindo uma classe
	int laco=1; //definindo o laço de repetição
		
	for(laco=1;laco=1;) //inicio do laço de repetição
	{
		system("cls"); //limpar a interface
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("========== Cartório da EBAC ========== \n\n"); //inicio do menu
		printf("Por favor, escolha a opção desejada:\n\n");
		printf("\t1-Registrar nomes\n"); //opção
		printf("\t2-Consultar nomes\n"); //opção
		printf("\t3-Deletar nomes\n"); //opção
		printf("\t4-Fechar o programa\n\n"); //opção
		printf("opção: "); //coltando informação do usuário
		//fim do menu
		
		scanf("%d", &opcao); //armazenar opção escolhida
	
		system("cls"); //limpa a interface
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registrar(); //redirecionando para a função "registrar"
			break; //encerrando o "case"
			
			case 2:
			consultar(); //redirecionando para a função "consultar"
			break; //encerrando o "case"
			
			case 3:
			deletar(); //redirecionando para a função "deletar"
			break; //encerrando o "case"
			
			case 4:
			fechar(); //redirecionando para a função "fechar"
			break; //encerrando o "case"
			
			default:
			printf("\tEssa opção não está disponível! \n\n"); //caso o usuário digite qualquer opção não listada anteriormente
			system("pause"); //pausar a interface
			break; //encerrando o "case"
		} //fim da seleção
	} //fim do laço de repetição
} //fim da função "main"
