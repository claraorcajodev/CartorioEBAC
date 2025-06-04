#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de texto por região 
#include<string.h> // biblioteca responsável pelos strings


int registro() //inserção de dados 
{
	// início criação de variáveis/ strings (conjunto de variáveis)
	
	char arquivo[40];  //toda vez que for criado um usuário novo, o arquivo vai mudar 
	char cpf[40];    
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// fim da criação de variáveis/ strings (conjunto de variáveis)
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", cpf); // s se refere a strings. Salva o string que foi inserido pelo usuário 
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings //copia do cpf para o arquivo
	
	FILE *file; //cria o arquivo no banco de dados//procura nas bibliotecas a estrutura file para criar o arquivo
	file = fopen(arquivo,"w");//cria o arquivo // abre o arquivo para criar uma variável - w write -  com base nos dados inseridos pelo usuário
	
	fprintf(file,cpf);  //printf dentro do arquivo. Ao invés de passar para o usuário, salva o valor da variável no arquivo
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); // a = atualizar a informação, modificá-la
	fprintf(file,",");
	
	fclose(file);
	
	printf("Digite o nome a ser cadastraado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // atualizando as informações do arquivo
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
	setlocale(LC_ALL, "Portuguese"); // tem que repetir, pois é uma função diferente. 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = read, consultar
	
	if(file == NULL)  // == comparação // se não houver o valor digitado pelo usuário, é null
	{
		printf("Não foi possível abrir o arquivo, não localizado! .\n");
	}
	
	//fgets = localizar no arquivo// tamanho do conteúdo é 200, enquanto estiver no arquivo file ele vai procurar 200x
	
	while(fgets(conteudo, 200,file) != NULL) // while = enquanto // laço de repetição - para salvar cada uma das variáveis até elas acabarem
	{// é para parar de procurar quando o arquivo for nulo, enquanto estiver diferente de null é para procurar
	
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}	

int deletar()

{
	setlocale(LC_ALL,"portuguese");
	char cpf[40]; // string cpf
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file; // validação
	file = fopen(cpf,"r"); //ler o cpf
	
	if(file == NULL) // se a variável for nula 
	{
		
		printf("Usuário não encontrado no sistema!\n");
		system("pause");
	
	}
	
	else 

  	{

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");

    system("pause");

  	}
}

int main()
{

	int opcao=0; // criação e atribuição de valor neutro à variável //definindo variáveis 
	int laco=1; // laço=1 para sempre entrar no for
	char senhadigitada[10]="a";
	int comparacao;
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cartório EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin"); // cria a comparação das strings de senha e admin
	
	if(comparacao == 0) // se a senhadigitada corresponder a admin, o valor será zero
	{
		
		for (laco=1;laco=1;) // for = repita, faça. Depois das variáveis, antes das definições. Fica no laço do for sempre com laço=1;laço=1
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
			printf("### Cartório EBAC ###\n\n"); //início do menu /
			printf("Escolha a opção desejada no menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção:"); //fim do menu

			scanf("%d", &opcao); //identifica input do usuário; armazena a escolha do usuário; & indica a variável que vai armazenar 
	
			system("cls"); // apagar informações anteriores da tela 
		
			switch (opcao)
			{
				case 1:
				registro(); //chamada de funções 
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
			
				default: // caso não for nenhum deles,
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;			
			} //fim da seleção 
	
		}
	}
	else
	printf ("Senha incorreta!"); 
}
