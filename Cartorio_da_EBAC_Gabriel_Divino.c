#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>	//biblioteca respons�vel por cuidar das strings

int registrar() // Fun��o respons�vel por cadastrastar os usu�rios
{
	//inicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis
	
	printf("Digite o cpf a ser cadastrado: "); //coltando informa��o do usu�rio
	scanf("%s",cpf); //armazena o valor da string (%s)
	
	strcpy(arquivo,cpf); //respons�vel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); //cria o arquivo ("w" = escrever)
	fprintf(file, "CPF: "); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file, "|| Nome: "); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo	
		
	printf("Digite o nome a ser cadastrado: "); //coltando informa��o do usu�rio
	scanf("%s", nome); //armazena o valor da string (%s)
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file, "|| Sobrenome: "); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo	
	
	printf("Digite o sobrenome a ser cadastrado: "); //coltando informa��o do usu�rio
	scanf("%s", sobrenome); //armazena o valor da string 
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file,sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file, "|| Cargo: "); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coltando informa��o do usu�rio
	scanf("%s",cargo); //armazena o valor da string (%s)
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file,cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo ("a" = atualiza��o)
	fprintf(file, "||"); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	contreg(); //redirecionar para a fun��o contreg(continuar registrando)
	system("pause"); //pausa as informa��es da interface
	
} //fim da fun��o "registrar"

int consultar() // Fun��o respons�vel por consultar os usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de vari�veis
	
	printf("Digite o cpf a ser consultado: "); //coltando informa��o do usu�rio
	scanf("%s", cpf); //armazena o valor da string (%s)
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo ("r" = ler)
	
	if(file == NULL) //condi��o
	{
		fclose(file); //fecha o arquivo
		
		printf("\n\nN�o foi poss�vel acessar o arquivo, n�o localizado! \n\n");
		contconsul(); //redirecionar para a fun��o contconsul(continuar consultando)
	}
	
	while(fgets(conteudo,200,file) != NULL) //condi��o
	{
		printf("==================================================================================\n");
		printf("\n\tEssas s�o as informa��es do usu�rio: \n\n");
		printf(" %s",conteudo);
		printf("\n\n==================================================================================\n\n");
	}	
	fclose(file); //fecha o arquivo

	contconsul(); //redirecionar para a fun��o contconsul(continuar consultando)
	system("pause"); //pausar a interface
} //fim da fun��o "consultar"

int deletar() // Fun��o respons�vel por deletar os usu�rios
{
	int simenao=0; //definindo uma classe
	int lacoI=1; //definindo um la�o
	
	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de vari�veis
	char cpf[40];	
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //armazena o valor da string (%s)

	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo ("r" = ler)

	if(file == NULL) //condi��o
	{
		fclose(file); //fecha o arquivo

		printf("\n\tEsse usu�rio n�o existe!\n\n");
		contdel(); //redirecionando para a fun��o "contdel(constinuar deletando)"
		system("pause"); //pausar a interface
	}
	else
	{
		fclose(file);
		
		printf("\nVoc� tem certeza de que quer deletar esse usu�rio?\n\n");
		printf("\t1-Sim\n"); //op��o
		printf("\t2-N�o\n\n"); //op��o
		printf("op��o: "); //coletando informa��o do usu�rio
		scanf("%d", &simenao); //armazena o valor na vari�vel (%d)
		system("cls"); //limpar a interface
			
		switch(simenao) //inicio da sele��o
		{
			case 1: 
			remove(cpf); //exclui o cpf digitado
			printf("\n\tUsu�rio deletado com sucesso!\n\n");
			system("pause");
			contdel(); //redirecionando para a fun��o "contdel(constinuar deletando)"
			system("pause"); //pausar a interface
			break; //encerrando o "case"

			case 2:
			printf("\n\tVoc� desistiu de deletar o usu�rio!\n\n");
			fclose(file);
			contdel(); //redirecionando para a fun��o "contdel(constinuar deletando)"
			system("pause"); //pausar a interface
			break; //encerrando o "case"
			
			default:
			printf("\tEssa op��o n�o est� dispon�vel!\n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
			system("pause"); //pausar a interface
			programa();
			break; //encerrando o "case"		
		} //fim da sele��o
	}
	
} //fim da fun��o "deletar"

int fechar() // Fun��o respons�vel fechar o programa
{
	int opcao; //definindo uma classe
	
	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("Voc� tem certeza de que quer fechar o programa?\n\n");
	printf("\t1-Sim\n"); //op��o
	printf("\t2-N�o\n\n"); //op��o
	printf("op��o: "); //coltando informa��o do usu�rio
	
	scanf("%d", &opcao); //armazena o valor na vari�vel (%d)
	
	switch(opcao) //inicio da sele��o
	{
		case 1:
		system("cls"); //limpar a interface
		printf("\tObrigado por utilizar o sistema!\n\n");
		exit(0); //encerramento do programa	
		break; //encerrando o "case"
		
		case 2:
		programa(); //redirecionando para a fun��o "main" / fun��o principal
		break; //encerrando o "case"
		
		default:
		printf("\n\tEssa op��o n�o est� dispon�vel!\n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
		system("pause"); //pausar a interface
		programa(); //redirecionando para a fun��o "main" / fun��o principal
		break; //encerrando o "case"
	} //fim da sele��o
} //fim da fun��o "fechar"

int contreg() //fun��o para continuar registrando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar registrando?\n\n");
	printf("\t1-Sim\n"); //op��o
	printf("\t2-N�o\n\n"); //op��o
	printf("op��o: "); //coletando informa��o do usu�rio
	
	scanf("%d", &opcao); //armazena o valor na vari�vel (%d)
	
	switch(opcao) //inicio da sele��o
	{
		case 1:
		system("cls"); //limpar a interface
		registrar(); //redirecionando para a fun��o "registrar"
		break; //encerrando o "case"
			
		case 2:
		programa(); //redirecionando para a fun��o "main"
		break; //encerrando o "case"
			
		default:
		printf("\n\tEssa op��o n�o est� dispon�vel! \n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
		system("pause"); //pausar a interface
		system("cls"); // limpar a interface
		contreg();	
		break; //encerrando o "case"
	}
	
}

int contconsul() //fun��o para continuar consultando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar consultando?\n\n");
	printf("\t1-Sim\n"); //op��o
	printf("\t2-N�o\n\n"); //op��o
	printf("op��o: "); //coletando informa��o do usu�rio
	
	scanf("%d", &opcao); //armazena o valor na vari�vel (%d)
	
	switch(opcao) //inicio da sele��o
	{
		case 1:
		system("cls"); //limpar a interface
		consultar(); //redirecionando para a fun��o "consultar"
		break; //encerrando o "case"
			
		case 2:
		programa(); //redirecionando para a fun��o "main"
		break; //encerrando o "case"
			
		default:
		printf("\n\tEssa op��o n�o est� dispon�vel! \n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
		system("pause"); //pausar a interface
		system("cls");
		contconsul();		
		break; //encerrando o "case"
	}
	
}

int contdel() //fun��o para continuar deletando
{
	int opcao=0; // definindo uma classe
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("\n\nPretende continuar deletando?\n\n");
	printf("\t1-Sim\n"); //op��o
	printf("\t2-N�o\n\n"); //op��o
	printf("op��o: "); //coletando informa��o do usu�rio
	
	scanf("%d", &opcao); //armazena o valor na vari�vel (%d)
	
	switch(opcao) //inicio da sele��o
	{
		case 1:
		system("cls"); //limpar a interface
		deletar(); //redirecionando para a fun��o "deletar"
		break; //encerrando o "case"
			
		case 2:
		programa(); //redirecionando para a fun��o "programa"
		break; //encerrando o "case"
			
		default:
		printf("\n\tEssa op��o n�o est� dispon�vel! \n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
		system("pause"); //pausar a interface
		system("cls");
		contdel();
		break; //encerrando o "case"
	}
	
}

int cadastro_senha()
{
	char arquivo_senha[10];
	char senha[10];
	
	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("========== Cart�rio da EBAC ========== \n\n"); //inicio do menu
	printf("Digite a senha a ser cadastrada: ");
	scanf("%s", senha);
	
	strcpy(arquivo_senha,senha);
	
	FILE *file;
	
	file = fopen(arquivo_senha,"w");
	fprintf(file,senha);
	fclose(file);
	
	system("cls");
	printf("\tCadastrado com sucesso!\n\n");
	system("pause");
	main();
}

int login()
{
	char senha[10];
	
	
	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("========== Cart�rio da EBAC ========== \n\n"); //inicio do menu
	printf("Digite a sua senha: ");
	scanf("%s", senha);
	
	FILE *file;
	file = fopen(senha, "r");
	
	if (file != NULL)
	{
		system("cls");
		printf("\tAcesso autorizado!\n\n");
		system("pause");
		programa();
	}	
	
	else
	{
		system("cls");
		printf("\tSenha incorreta!\n\n");
		system("pause");
		main();
	}
	
	fclose(file);
}

int programa()
{	
	int opcao=0; //definindo uma classe
	int laco=1; //definindo o la�o de repeti��o
		
	for(laco=1;laco=1;) //inicio do la�o de repeti��o
	{
		system("cls"); //limpar a interface
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("========== Cart�rio da EBAC ========== \n\n"); //inicio do menu
		printf("Por favor, escolha a op��o desejada:\n\n");
		printf("\t1-Registrar nomes\n"); //op��o
		printf("\t2-Consultar nomes\n"); //op��o
		printf("\t3-Deletar nomes\n"); //op��o
		printf("\t4-Fechar o programa\n\n"); //op��o
		printf("op��o: "); //coltando informa��o do usu�rio
		//fim do menu
		
		scanf("%d", &opcao); //armazenar op��o escolhida
	
		system("cls"); //limpa a interface
	
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registrar(); //redirecionando para a fun��o "registrar"
			break; //encerrando o "case"
			
			case 2:
			consultar(); //redirecionando para a fun��o "consultar"
			break; //encerrando o "case"
			
			case 3:
			deletar(); //redirecionando para a fun��o "deletar"
			break; //encerrando o "case"
			
			case 4:
			fechar(); //redirecionando para a fun��o "fechar"
			break; //encerrando o "case"
			
			default:
			printf("\tEssa op��o n�o est� dispon�vel! \n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
			system("pause"); //pausar a interface
			programa();
			break; //encerrando o "case"
			
		} //fim da sele��o
	} //fim do la�o de repeti��o		
} //fim da fun��o "programa"


int main() // Fun��o principal do programa
{
	int cad_log = 0;

	system("cls"); //limpar a interface
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("========== Cart�rio da EBAC ========== \n\n"); //inicio do menu
	printf("Por favor, escolha uma das op��es: \n\n ");
	printf("\t1-Registrar\n");
	printf("\t2-Logar\n\n");
	printf("op��o: "); 
	
	scanf("%d", &cad_log);
	
	system("cls");
	
	switch(cad_log)
	{
		case 1:
		cadastro_senha();
		break;
		
		case 2:
		login();
		break;
		
		default:
		printf("\tEssa op��o n�o est� dispon�vel! \n\n"); //caso o usu�rio digite qualquer op��o n�o listada anteriormente
		system("pause"); //pausar a interface
		main();
		break; //encerrando o "case"	
			
	} //fim da sele��o
} //fim da fun��o "main"
