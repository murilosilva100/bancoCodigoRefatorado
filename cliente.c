#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "cliente.h"

//1

static char funcionariosenha[10] = "11", clientesenha[10] = "12";

// Função para procurar cliente pelo CPF
int buscar_cliente(FILE *arquivo_cliente, int cpf, struct conta *cliente) {
    fseek(arquivo_cliente, 0, SEEK_SET);
    while (fread(cliente, sizeof(struct conta), 1, arquivo_cliente)) {
        if (cliente->cpf == cpf) {
            return 1;  // Cliente encontrado
        }
    }
    return 0;  // Cliente não encontrado
}

// Função para verificar senha do cliente
int verificar_senha(int senha_cliente, int senha_informada) {
    return senha_cliente == senha_informada;
}

void saldo_cliente(FILE *arquivo_cliente) {
    int cpf, senha;
    struct conta cliente;

    system("cls");
    printf("1 - Saldo\n");
    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    if (buscar_cliente(arquivo_cliente, cpf, &cliente)) {
        printf("\nDigite a senha do cliente: ");
        fflush(stdin);
        scanf("%d", &senha);

        if (verificar_senha(cliente.senha_cliente, senha)) {
            system("cls");
            printf("1 - Saldo\n");
            printf("\nCliente: %s (CPF: %d) \n\nSaldo: %.2f\n\n", cliente.nome, cliente.cpf, cliente.saldo);
        } else {
            printf("Senha incorreta!\n");
        }
    } else {
        printf("\nCliente não encontrado!\n\n");
    }
    system("pause");
}

void deposito_cliente(FILE *arquivo_cliente) {
    int cpf, senha;
    float valor;
    struct conta cliente;
    long posicao;

    system("cls");
    printf("2 - Depósito\n");
    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    if (buscar_cliente(arquivo_cliente, cpf, &cliente)) {
        printf("\nDigite a senha do cliente: ");
        fflush(stdin);
        scanf("%d", &senha);

        if (verificar_senha(cliente.senha_cliente, senha)) {
            printf("\nDigite o valor do depósito: ");
            scanf("%f", &valor);

            cliente.saldo += valor;
            fseek(arquivo_cliente, ftell(arquivo_cliente) - sizeof(struct conta), SEEK_SET);
            fwrite(&cliente, sizeof(struct conta), 1, arquivo_cliente);

            system("cls");
            printf("2 - Depósito\n");
            printf("\nDepósito realizado com sucesso! \n\nNome do cliente: %s (CPF: %d) \n\nSaldo após o depósito: %.2f\n\n", cliente.nome, cliente.cpf, cliente.saldo);
        } else {
            printf("\nSenha incorreta!\n\n");
        }
    } else {
        printf("\nCliente não encontrado!\n\n");
    }
    system("pause");
}

void saque_cliente(FILE *arquivo_cliente) {
    int cpf, senha;
    float valor;
    struct conta cliente;

    system("cls");
    printf("3 - Saque\n");
    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    if (buscar_cliente(arquivo_cliente, cpf, &cliente)) {
        printf("\nDigite a senha do cliente: ");
        fflush(stdin);
        scanf("%d", &senha);

        if (verificar_senha(cliente.senha_cliente, senha)) {
            printf("\nDigite o valor do saque: ");
            scanf("%f", &valor);

            if (cliente.saldo >= valor) {
                cliente.saldo -= valor;
                fseek(arquivo_cliente, ftell(arquivo_cliente) - sizeof(struct conta), SEEK_SET);
                fwrite(&cliente, sizeof(struct conta), 1, arquivo_cliente);

                system("cls");
                printf("3 - Saque\n");
                printf("\nSaque realizado com sucesso! Novo saldo: %.2f\n\n", cliente.saldo);
            } else {
                printf("\nSaldo insuficiente!\n");
            }
        } else {
            printf("\nSenha incorreta!\n\n");
        }
    } else {
        printf("\nCliente não encontrado!\n\n");
    }
    system("pause");
}

void extrato_cliente(FILE *arquivo_cliente) {
    system("cls");
    printf("4 - Extrato\n");
    printf("Funcionalidade em desenvolvimento.\n");
    system("pause");
}

void consultarlimite_cliente(FILE *arquivo_cliente) {
    int cpf, senha;
    struct conta cliente;

    system("cls");
    printf("5 - Consultar limite\n");
    printf("\nDigite o CPF do cliente: ");
    fflush(stdin);
    scanf("%d", &cpf);

    if (buscar_cliente(arquivo_cliente, cpf, &cliente)) {
        printf("\nDigite a senha do cliente: ");
        fflush(stdin);
        scanf("%d", &senha);

        if (verificar_senha(cliente.senha_cliente, senha)) {
            system("cls");
            printf("5 - Consultar limite\n");
            printf("\nNome do cliente: %s (CPF: %d) \n\nLimite disponível: %.2f\n\n", cliente.nome, cliente.cpf, cliente.limite);
        } else {
            printf("Senha incorreta!\n");
        }
    } else {
        printf("\nCliente não encontrado!\n\n");
    }
    system("pause");
}
