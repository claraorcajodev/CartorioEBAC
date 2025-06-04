#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de texto por regi�o 
#include<string.h> // biblioteca respons�vel pelos strings


int registro() //inser��o de dados 
{
	// in�cio cria��o de vari�veis/ strings (conjunto de vari�veis)
	
	char arquivo[40];  //toda vez que for criado um usu�rio novo, o arquivo vai mudar 
	char cpf[40];    
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// fim da cria��o de vari�veis/ strings (conjunto de vari�veis)
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio
	scanf("%s", cpf); // s se refere a strings. Salva o string que foi inserido pelo usu�rio 
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings //copia do cpf para o arquivo
	
	FILE *file; //cria o arquivo no banco de dados//procura nas bibliotecas a estrutura file para criar o arquivo
	file = fopen(arquivo,"w");//cria o arquivo // abre o arquivo para criar uma vari�vel - w write -  com base nos dados inseridos pelo usu�rio
	
	fprintf(file,cpf);  //printf dentro do arquivo. Ao inv�s de passar para o usu�rio, salva o valor da vari�vel no arquivo
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); // a = atualizar a informa��o, modific�-la
	fprintf(file,",");
	
	fclose(file);
	
	printf("Digite o nome a ser cadastraado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // atualizando as informa��es do arquivo
	fprintf(file,nome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // tem que repetir, pois � uma fun��o diferente. 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = read, consultar
	
	if(file == NULL)  // == compara��o // se n�o houver o valor digitado pelo usu�rio, � null
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n");
	}
	
	//fgets = localizar no arquivo// tamanho do conte�do � 200, enquanto estiver no arquivo file ele vai procurar 200x
	
	while(fgets(conteudo, 200,file) != NULL) // while = enquanto // la�o de repeti��o - para salvar cada uma das vari�veis at� elas acabarem
	{// � para parar de procurar quando o arquivo for nulo, enquanto estiver diferente de null � para procurar
	
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}	

int deletar()

{
	setlocale(LC_ALL,"portuguese");
	char cpf[40]; // string cpf
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; // valida��o
	file = fopen(cpf,"r"); //ler o cpf
	
	if(file == NULL) // se a vari�vel for nula 
	{
		
		printf("Usu�rio n�o encontrado no sistema!\n");
		system("pause");
	
	}
	
	else 

  	{

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");

    system("pause");

  	}
}

int main()
{

	int opcao=0; // cria��o e atribui��o de valor neutro � vari�vel //definindo vari�veis 
	int laco=1; // la�o=1 para sempre entrar no for
	char senhadigitada[10]="a";
	int comparacao;
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cart�rio EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin"); // cria a compara��o das strings de senha e admin
	
	if(comparacao == 0) // se a senhadigitada corresponder a admin, o valor ser� zero
	{
		
		for (laco=1;laco=1;) // for = repita, fa�a. Depois das vari�veis, antes das defini��es. Fica no la�o do for sempre com la�o=1;la�o=1
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
			printf("### Cart�rio EBAC ###\n\n"); //in�cio do menu /
			printf("Escolha a op��o desejada no menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o:"); //fim do menu

			scanf("%d", &opcao); //identifica input do usu�rio; armazena a escolha do usu�rio; & indica a vari�vel que vai armazenar 
	
			system("cls"); // apagar informa��es anteriores da tela 
		
			switch (opcao)
			{
				case 1:
				registro(); //chamada de fun��es 
				break; // fecha as chaves ":"
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
			
				default: // caso n�o for nenhum deles,
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;			
			} //fim da sele��o 
	
		}
	}
	else
	printf ("Senha incorreta!"); 
}
