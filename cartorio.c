#include <stdio.h>    // Biblioteca para comunica��o com o usu�rio (entrada e sa�da)
#include <stdlib.h>   // Biblioteca para aloca��o de mem�ria e outras fun��es utilit�rias
#include <locale.h>   // Biblioteca para configurar localiza��o (idioma e formata��o regional)
#include <string.h>   // Biblioteca para manipula��o de strings

int registro() // Fun��o para registrar um novo usu�rio
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:");
    scanf("%s", cpf); // L� o CPF digitado pelo usu�rio
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file;
    file = fopen(arquivo, "w"); // Cria um arquivo com o nome do CPF para escrita
    fprintf(file, cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar mais informa��es
    fprintf(file, ","); // Adiciona uma v�rgula para separar os campos
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // L� o nome do usu�rio

    file = fopen(arquivo, "a");
    fprintf(file, nome); // Adiciona o nome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // L� o sobrenome do usu�rio

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome); // Adiciona o sobrenome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // L� o cargo do usu�rio

    file = fopen(arquivo, "a");
    fprintf(file, cargo); // Adiciona o cargo no arquivo
    fclose(file);
    
    system("pause"); // Pausa o sistema para que o usu�rio veja a mensagem final
}

int consulta() // Fun��o para consultar informa��es de um usu�rio
{
    setlocale(LC_ALL, "Portuguese"); // Configura a localiza��o para portugu�s
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // L� o CPF a ser consultado
    
    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo com o CPF
    
    if(file == NULL) // Verifica se o arquivo existe
    {
        printf("Arquivo n�o localizado!!!");
        return 1; // Retorna 1 indicando erro
    }
    
    while(fgets(conteudo, 200, file) != NULL) // L� o conte�do do arquivo linha por linha
    {
        printf("\nEssas s�o as informa��es do usu�rio:");
        printf("%s", conteudo); // Imprime o conte�do do arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo
    system("pause"); // Pausa o sistema para que o usu�rio veja a mensagem final
    return 0; // Retorna 0 indicando sucesso
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Configura a localiza��o para portugu�s
    
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf); // L� o CPF do usu�rio a ser deletado
    
    if (remove(cpf) == 0) // Remove o arquivo com o CPF e verifica se a remo��o foi bem-sucedida
    {
        printf("Usu�rio deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao deletar o usu�rio! Arquivo n�o encontrado.\n");
    }
    
    system("pause"); // Pausa o sistema para que o usu�rio veja a mensagem final
    
    return 0; // Retorna 0 indicando que a fun��o terminou
}


int main() // Fun��o principal do programa
{
    int opcao = 0; // Vari�vel para armazenar a op��o do menu
    int laco = 1; // Vari�vel de controle do la�o
    char senhadigitada[40];
    int comparacao;
    
    printf("### Cart�rio da Ebac ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
	{
    	

    	while(laco == 1) // La�o infinito at� o usu�rio decidir sair
    	{
        	system("cls"); // Limpa a tela
        
        	setlocale(LC_ALL, "Portuguese"); // Configura a localiza��o para portugu�s
        
       		// Exibe o menu para o usu�rio
       		printf("### Cart�rio da Ebac ###\n\n");
        	printf("Escolha a op��o desejada do menu:\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Sair do sistema\n\n");
        	printf("Op��o: ");

        	scanf("%d", &opcao); // L� a op��o escolhida pelo usu�rio
        
        	system("cls"); // Limpa a tela novamente
        
        	switch(opcao) // Estrutura de decis�o para executar a fun��o correspondente
        	{
            	case 1:
           	    	registro(); // Chama a fun��o de registro
                	break;
            
            	case 2:
                	consulta(); // Chama a fun��o de consulta
                	break;
            
            	case 3:
                	deletar(); // Chama a fun��o de deletar
                	break;
                
            	case 4: 
            		printf("Obrigado por utilizar o nosso sistema!");
            		return 0;
            		break;
            
            	default:
                	printf("Essa op��o n�o est� dispon�vel!");
                	system("pause");
                	break;
            }
    	}
    }
    
    else
    	printf("Senha incorreta!");
}

