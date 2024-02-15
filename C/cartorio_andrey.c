#include <stdio.h> //biblioteca de comunica��o com o usu�rio!
#include <stdlib.h> //biblioteca de aloca��o de espa�os de mem�ria!
#include <locale.h> //biblioteca de aloca��es de texto por regi�o!
#include <string.h> //biblioteca respons�vel por cuidar das string's!

int registro(){			//vari�vel criada para a fun��o de registrar os dados do cliente!
	
	//in�cio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim.
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser cadastrado: "); //para pegar as informa��es do usu�rio
	scanf("%s", cpf);	//scanf l� o que foi digitado no printf acima e guarda na vari�vel!
	
	strcpy(arquivo, cpf); //respons�vel por copiar as string's
	
	FILE *file; //cria o arquivo ('file' � o nome do arquivo)
	file = fopen(arquivo, "w"); //cria o arquivo ('w' de write, para escrever dentro do arquivo)
	fprintf(file, "CPF: ");		//exibe 'CPF' atr�s na hora da consulta
	fprintf(file, cpf); //salva o valor da vari�vel		//guarda o cpf, nossa infroma��o chave, dentro do arquivo criado
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //'a' (appended) serve para atualizar o c�digo, guardar/anexar uma nova ou substituir uma informa��o.
	fprintf(file,"\nNome: ");	//exibe uma mensagem vinda do arquivo 'file' 	//exibe 'Nome' atr�s na hora da consulta
	fclose(file); //fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string, no caso ele l� o que foi digitado, e guarda na vari�vel como uma string!
	
	file = fopen(arquivo, "a"); //guarda no arquivo o nome da pessoa
	fprintf(file, nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");	//exibe 'Sobrenome' atr�s na hora da consulta
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //guarda no arquivo o sobrenome
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: "); 	//exibe 'Cargo' atr�s na hora da consulta
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
		
	file = fopen(arquivo, "a");
	fprintf(file, cargo);		//guarda o cargo no arquivo
	fprintf(file, "\n\n");
	fclose(file);
	
	printf("\nDados salvos!\n");
	
	system("pause");
}


int consultar(){		//fun��o de consulta
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; 			//cria vari�veis para guardar string's
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //pede o cpf para procurar um arquivo de mesmo nome
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Arquivo n�o encontrado!\n"); //se n�o houver um arquivo de mesmo nome que o cpf, exibe esta mensagem
	}
	
	printf("\nDados do usu�rio:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL){  //vai pegar o conte�do guardado no arquivo criado em at� 200 caract�res.
		printf("%s", conteudo);		//caso encontre um arquivo de mesmo nome, vai mostrar todo conte�do guardado no arquivo como cpf, nome, sobrenome e cargo.
	}
	
	fclose(file);
	system("pause"); //da um tempo de descanso, exibindo a mensagem "Pressione qualquer tecla para continuar...".
}

int deletar(){		//fun��o de deletar
	char cpf[40];
	int soun=0; 	//vari�vel criada por mim para a possibilidade de escolha em "Tem certeza que deseja deletar?", como uma precau��o para poss�veis erros de delete.
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");		//'r' de read, vai ler o o conte�do do arquivo e procurar pelo cpf
	fclose(file); //aqui fechamos arquivo, para que 'remove(cpf)' funcione!
	
	if(file != NULL){	//caso o arquivo exista, ele vai encontrar o cpf e vai seguir para as escolhas
	
		printf("\n\nTem certeza que deseja deletar?\n");
	
		printf("\t1 - Sim\n\t2 - N�o\n\t3 - Voltar ao Menu\n");		//exibe as possibilidades de escolhas para continuar
		printf("Op��o: ");
		scanf("%d", &soun);
		
		system("cls");
			
		switch(soun){		//switch foi utilizado para substituir a fun��o 'if' e facilitar a estrutura do c�digo
			case 1:
			remove(cpf);
			printf("O usu�rio foi deletado com sucesso!\n"); 	//neste caso (sim), apaga o arquivo que tenha o mesmo nome do cpf
			system("pause");
			break;
			
			case 2:
			deletar();		//aqui (n�o), ele volta para a fun��o deletar para digitar o cpf do usu�rio novamente em caso de erro.
			break;	
			
			case 3:
			main(); 	//volta para o menu
			break;
			
			default:
			printf("Essa op��o � inv�lida!\n");		//caso digite algo fora das escolhas, exibe uma mensagem e volta a fun��o delete
			deletar();
			system("pause");
			break;	
		}
		
		system("cls");
	}
	
	else{
		printf("Esse usu�rio n�o existe!\n");		//caso contr�rio, ele exibir� esta mensagem
		system("pause");
	}
	
	fclose(file);
}

int main(){		//fun��o de menu
	int opcao=0; //defini��o de vari�vel
	int laco=1;
	
	for(laco=1;laco=1;){		//la�o criadopara formar um loop, "o c�digo vai repetir quando 'la�o' que vale 1 valer 1", como j� vale 1 e n�o tem limite de vezes, continua num loop.
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		system("cls"); 
		
		//come�o do menu
		printf("### REGISTRO DE NOMES NA EBAC ###\n\n");		//escolhas do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Op��o:");
		//fim do menu
	
		scanf("%d", &opcao); //c�digo para guardar a informa��o digitada na vari�vel criada
		
		system("cls"); //c�digo para limpar o as mensagens no bloco de comando
		
		switch(opcao){			//switch serviu para substituir o 'if' e 'else', assim ajudando a diminuir o c�digo.
			
			case 1:				//caso aperte o n�mero correspondente, mostra a fun��o abaixo, neste caso, 'case 1' corresponde ao 1 digitado e mostra a fun��o guardada na vari�vel 'registro'.
			registro();			//chama a fun��o registro 
			break;					//break finaliza o 'case'
				
			case 2:
			consultar();		//chama a fun��o consultar
			break;
				
			case 3:
			deletar();		//chama a fun��o deletar
			break;
			
			default:
			printf("A op��o escolhida � inv�lida!\n");
			system("pause");									//system("pause"); da uma pausa na continuidade do c�digo "aperte uma tecla para continuar".
			break;
		}
	
		printf("\n\n|CUIDADO! ESSE SOFTWARE EST� SENDO CRIADO POR UM INICIANTE!|by Andrey"); //apenas uma mensagem final para o cmd, cr�ditos.
	}
}
