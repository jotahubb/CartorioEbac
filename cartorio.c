#include <stdio.h>    // Biblioteca para comunicação com o usuário (entrada e saída)
#include <stdlib.h>   // Biblioteca para alocação de memória e outras funções utilitárias
#include <locale.h>   // Biblioteca para configurar localização (idioma e formatação regional)
#include <string.h>   // Biblioteca para manipulação de strings

int registro() // Função para registrar um novo usuário
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado:");
    scanf("%s", cpf); // Lê o CPF digitado pelo usuário
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file;
    file = fopen(arquivo, "w"); // Cria um arquivo com o nome do CPF para escrita
    fprintf(file, cpf); // Escreve o CPF no arquivo
    fclose(file); // Fecha o arquivo
    
    file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar mais informações
    fprintf(file, ","); // Adiciona uma vírgula para separar os campos
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // Lê o nome do usuário

    file = fopen(arquivo, "a");
    fprintf(file, nome); // Adiciona o nome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // Lê o sobrenome do usuário

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome); // Adiciona o sobrenome no arquivo
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // Lê o cargo do usuário

    file = fopen(arquivo, "a");
    fprintf(file, cargo); // Adiciona o cargo no arquivo
    fclose(file);
    
    system("pause"); // Pausa o sistema para que o usuário veja a mensagem final
}

int consulta() // Função para consultar informações de um usuário
{
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para português
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // Lê o CPF a ser consultado
    
    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo com o CPF
    
    if(file == NULL) // Verifica se o arquivo existe
    {
        printf("Arquivo não localizado!!!");
        return 1; // Retorna 1 indicando erro
    }
    
    while(fgets(conteudo, 200, file) != NULL) // Lê o conteúdo do arquivo linha por linha
    {
        printf("\nEssas são as informações do usuário:");
        printf("%s", conteudo); // Imprime o conteúdo do arquivo
        printf("\n\n");
    }
    
    fclose(file); // Fecha o arquivo
    system("pause"); // Pausa o sistema para que o usuário veja a mensagem final
    return 0; // Retorna 0 indicando sucesso
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para português
    
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf); // Lê o CPF do usuário a ser deletado
    
    if (remove(cpf) == 0) // Remove o arquivo com o CPF e verifica se a remoção foi bem-sucedida
    {
        printf("Usuário deletado com sucesso!\n");
    }
    else
    {
        printf("Erro ao deletar o usuário! Arquivo não encontrado.\n");
    }
    
    system("pause"); // Pausa o sistema para que o usuário veja a mensagem final
    
    return 0; // Retorna 0 indicando que a função terminou
}


int main() // Função principal do programa
{
    int opcao = 0; // Variável para armazenar a opção do menu
    int laco = 1; // Variável de controle do laço
    char senhadigitada[40];
    int comparacao;
    
    printf("### Cartório da Ebac ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0)
	{
    	

    	while(laco == 1) // Laço infinito até o usuário decidir sair
    	{
        	system("cls"); // Limpa a tela
        
        	setlocale(LC_ALL, "Portuguese"); // Configura a localização para português
        
       		// Exibe o menu para o usuário
       		printf("### Cartório da Ebac ###\n\n");
        	printf("Escolha a opção desejada do menu:\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Sair do sistema\n\n");
        	printf("Opção: ");

        	scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        
        	system("cls"); // Limpa a tela novamente
        
        	switch(opcao) // Estrutura de decisão para executar a função correspondente
        	{
            	case 1:
           	    	registro(); // Chama a função de registro
                	break;
            
            	case 2:
                	consulta(); // Chama a função de consulta
                	break;
            
            	case 3:
                	deletar(); // Chama a função de deletar
                	break;
                
            	case 4: 
            		printf("Obrigado por utilizar o nosso sistema!");
            		return 0;
            		break;
            
            	default:
                	printf("Essa opção não está disponível!");
                	system("pause");
                	break;
            }
    	}
    }
    
    else
    	printf("Senha incorreta!");
}

