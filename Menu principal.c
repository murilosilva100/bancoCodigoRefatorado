#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>  // Usado para sleep
#include "Funcionarios.h"
#include "cliente.h"

//1

static char ADM[10] = "31031519", funcionario[10] = "12", cliente[10]= "13";

// Função para verificar a senha de funcionários e clientes
int verificar_senha(char tipo_usuario) {
    char senha[10];
    if (tipo_usuario == '1') {
        printf("Funcionário\nDigite sua senha: ");
        scanf(" %s", senha);
        if (strcmp(senha, funcionario) == 0) {
            return 1;  // A senha está correta
        }
    } else {
        printf("Cliente\nDigite sua senha: ");
        scanf(" %s", senha);
        if (strcmp(senha, cliente) == 0) {
            return 1;  // A senha está correta
        }
    }
    return 0;  // Senha incorreta
}

// Função para o menu do funcionário
void menu_funcionario(FILE *arquivo_cliente, FILE *arquivo_funcionario) {
    char menu_f;
    do {
        system("cls");
        printf("MENU Funcionário\n");
        printf("\n1 – Abertura de conta\n2 – Encerramento de conta\n3 – Consultar dados\n4 – Alterar dados\n5 – Cadastro de Funcionários\n6 – Gerar relatórios\n7 – Sair");
        printf("\n\nEscolha uma opção: ");
        
        menu_f = getchar();
        getchar(); // Limpa o buffer
        
        switch(menu_f) {
            case '1':
                abrir_conta(arquivo_cliente);
                break;
            case '2':
                excluir_conta_senha(ADM, arquivo_cliente);
                break;
            case '3':
                consultar_dados(arquivo_cliente, arquivo_funcionario);
                break;
            case '4':
                alterar_dados(ADM, arquivo_cliente, arquivo_funcionario);
                break;
            case '5':
                cadastro_funcionario(arquivo_funcionario, ADM);
                break;
            case '6':
                gerar_relatorio(funcionario);
                break;
            case '7':
                printf("\nVolte sempre :)\n");
                sleep(1);
                break;
            default:
                printf("\nOpção inválida!");
                break;
        }
    } while (menu_f != '7');
}

// Função para o menu do cliente
void menu_cliente(FILE *arquivo_cliente) {
    char menu_c;
    do {
        system("cls");
        printf("MENU Cliente\n");
        printf("\n1 - Saldo\n2 - Depósito\n3 - Saque\n4 - Extrato\n5 - Consultar limite\n6 - Sair");
        printf("\nEscolha uma opção: ");
        
        menu_c = getchar();
        getchar();  // Limpa o buffer
        
        switch(menu_c) {
            case '1':
                saldo_cliente(arquivo_cliente);
                break;
            case '2':
                deposito_cliente(arquivo_cliente);
                break;
            case '3':
                saque_cliente(arquivo_cliente);
                break;
            case '4':
                extrato_cliente(arquivo_cliente);
                break;
            case '5':
                consultarlimite_cliente(arquivo_cliente);
                break;
            case '6':
                printf("\nVoltando para o menu principal...\n");
                sleep(1);
                main();
                break;
            default:
                printf("\nOpção inválida. Tente novamente!");
                sleep(1);
                break;
        }
    } while (menu_c != '6');
}

// Função de verificação de senha e acesso
void verificacao(char opcao, FILE *arquivo_cliente, FILE *arquivo_funcionario) {
    int acesso = verificar_senha(opcao);  // Verifica a senha de acordo com o tipo de usuário

    if (acesso) {
        if (opcao == '1') {
            printf("\nBem-vindo Funcionário!\n");
            sleep(1);
            menu_funcionario(arquivo_cliente, arquivo_funcionario);
        } else {
            printf("\nBem-vindo Cliente!\n");
            sleep(2);
            menu_cliente(arquivo_cliente);
        }
    } else {
        printf("\nSenha incorreta!\n");
        sleep(2);
    }
}

int main() {
    // Abre os arquivos e define a linguagem
    setlocale(LC_ALL, "Portuguese");
    
    FILE *arquivo_cliente, *arquivo_funcionario;
    arquivo_cliente = fopen("dados_cliente.txt", "r+");
    arquivo_funcionario = fopen("dados_funcionario.txt", "r+");
    
    if (arquivo_cliente == NULL) {
        arquivo_cliente = fopen("dados_cliente.txt", "w+");
    }
    if (arquivo_funcionario == NULL) {
        arquivo_funcionario = fopen("dados_funcionario.txt", "w+");
    }
    if (arquivo_cliente == NULL || arquivo_funcionario == NULL) {
        printf("Não foi possível abrir os arquivos.\n");
        return 1;
    }
    
    char menu;
    
    // Menu principal
    do {
        system("cls");
        printf("MENU\n");
        printf("\n1 - Funcionário\n2 - Cliente\n3 - Sair\n");
        printf("\nEscolha uma opção: ");
        
        menu = getchar();
        getchar();  // Limpa o buffer
        
        switch(menu) {
            case '1':
                system("cls");
                verificacao(menu, arquivo_cliente, arquivo_funcionario);
                break;
            case '2':
                system("cls");
                verificacao(menu, arquivo_cliente, arquivo_funcionario);
                break;
            case '3':
                printf("\nVolte sempre :)\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                sleep(2);
                break;
        }
    } while (menu != '3');
    
    return 0;
}
