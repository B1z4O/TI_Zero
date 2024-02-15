#include <stdio.h> //biblioteca de comunicação com o usuário!
#include <stdlib.h> //biblioteca de alocação de espaços de memória!
#include <locale.h> //biblioteca de alocações de texto por região!
#include <string.h> //biblioteca responsável por cuidar das string's!

int registro(){			//variável criada para a função de registrar os dados do cliente!
	
	//início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim.
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o CPF a ser cadastrado: "); //para pegar as informações do usuário
	scanf("%s", cpf);	//scanf lê o que foi digitado no printf acima e guarda na variável!
	
	strcpy(arquivo, cpf); //responsável por copiar as string's
	
	FILE *file; //cria o arquivo ('file' é o nome do arquivo)
	file = fopen(arquivo, "w"); //cria o arquivo ('w' de write, para escrever dentro do arquivo)
	fprintf(file, "CPF: ");		//exibe 'CPF' atrás na hora da consulta
	fprintf(file, cpf); //salva o valor da variável		//guarda o cpf, nossa infromação chave, dentro do arquivo criado
	fclose(file); //fecha o arquivo
	
	
	file = fopen(arquivo, "a"); //'a' (appended) serve para atualizar o código, guardar/anexar uma nova ou substituir uma informação.
	fprintf(file,"\nNome: ");	//exibe uma mensagem vinda do arquivo 'file' 	//exibe 'Nome' atrás na hora da consulta
	fclose(file); //fecha o arquivo
	
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //%s refere-se a string, no caso ele lê o que foi digitado, e guarda na variável como uma string!
	
	file = fopen(arquivo, "a"); //guarda no arquivo o nome da pessoa
	fprintf(file, nome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");	//exibe 'Sobrenome' atrás na hora da consulta
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //guarda no arquivo o sobrenome
	fprintf(file, sobrenome);
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: "); 	//exibe 'Cargo' atrás na hora da consulta
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


int consultar(){		//função de consulta
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; 			//cria variáveis para guardar string's
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //pede o cpf para procurar um arquivo de mesmo nome
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("Arquivo não encontrado!\n"); //se não houver um arquivo de mesmo nome que o cpf, exibe esta mensagem
	}
	
	printf("\nDados do usuário:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL){  //vai pegar o conteúdo guardado no arquivo criado em até 200 caractéres.
		printf("%s", conteudo);		//caso encontre um arquivo de mesmo nome, vai mostrar todo conteúdo guardado no arquivo como cpf, nome, sobrenome e cargo.
	}
	
	fclose(file);
	system("pause"); //da um tempo de descanso, exibindo a mensagem "Pressione qualquer tecla para continuar...".
}

int deletar(){		//função de deletar
	char cpf[40];
	int soun=0; 	//variável criada por mim para a possibilidade de escolha em "Tem certeza que deseja deletar?", como uma precaução para possíveis erros de delete.
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");		//'r' de read, vai ler o o conteúdo do arquivo e procurar pelo cpf
	fclose(file); //aqui fechamos arquivo, para que 'remove(cpf)' funcione!
	
	if(file != NULL){	//caso o arquivo exista, ele vai encontrar o cpf e vai seguir para as escolhas
	
		printf("\n\nTem certeza que deseja deletar?\n");
	
		printf("\t1 - Sim\n\t2 - Não\n\t3 - Voltar ao Menu\n");		//exibe as possibilidades de escolhas para continuar
		printf("Opção: ");
		scanf("%d", &soun);
		
		system("cls");
			
		switch(soun){		//switch foi utilizado para substituir a função 'if' e facilitar a estrutura do código
			case 1:
			remove(cpf);
			printf("O usuário foi deletado com sucesso!\n"); 	//neste caso (sim), apaga o arquivo que tenha o mesmo nome do cpf
			system("pause");
			break;
			
			case 2:
			deletar();		//aqui (não), ele volta para a função deletar para digitar o cpf do usuário novamente em caso de erro.
			break;	
			
			case 3:
			main(); 	//volta para o menu
			break;
			
			default:
			printf("Essa opção é inválida!\n");		//caso digite algo fora das escolhas, exibe uma mensagem e volta a função delete
			deletar();
			system("pause");
			break;	
		}
		
		system("cls");
	}
	
	else{
		printf("Esse usuário não existe!\n");		//caso contrário, ele exibirá esta mensagem
		system("pause");
	}
	
	fclose(file);
}

int main(){		//função de menu
	int opcao=0; //definição de variável
	int laco=1;
	
	for(laco=1;laco=1;){		//laço criadopara formar um loop, "o código vai repetir quando 'laço' que vale 1 valer 1", como já vale 1 e não tem limite de vezes, continua num loop.
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		system("cls"); 
		
		//começo do menu
		printf("### REGISTRO DE NOMES NA EBAC ###\n\n");		//escolhas do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("Opção:");
		//fim do menu
	
		scanf("%d", &opcao); //código para guardar a informação digitada na variável criada
		
		system("cls"); //código para limpar o as mensagens no bloco de comando
		
		switch(opcao){			//switch serviu para substituir o 'if' e 'else', assim ajudando a diminuir o código.
			
			case 1:				//caso aperte o número correspondente, mostra a função abaixo, neste caso, 'case 1' corresponde ao 1 digitado e mostra a função guardada na variável 'registro'.
			registro();			//chama a função registro 
			break;					//break finaliza o 'case'
				
			case 2:
			consultar();		//chama a função consultar
			break;
				
			case 3:
			deletar();		//chama a função deletar
			break;
			
			default:
			printf("A opção escolhida é inválida!\n");
			system("pause");									//system("pause"); da uma pausa na continuidade do código "aperte uma tecla para continuar".
			break;
		}
	
		printf("\n\n|CUIDADO! ESSE SOFTWARE ESTÁ SENDO CRIADO POR UM INICIANTE!|by Andrey"); //apenas uma mensagem final para o cmd, créditos.
	}
}
