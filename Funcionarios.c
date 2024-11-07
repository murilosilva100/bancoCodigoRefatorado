#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Funcionarios.h"

//1

struct conta_f {
    int codigo_f;
    char cargo_f[25];
    char nome_f[25];
    int cpf_f;
    int data_nascimento_f;
    int telefone_f;
    char endereco_f[25];
    int cep_f;
    char local_f[25];
    int numero_da_casa_f;
    char bairro_f[25];
    char cidade_f[25];
    char estado_f[25];
    int senha_funcionario;
};

struct conta {
    int tipo;
    int agencia;
    int numero_da_conta;
    float limite;
    int data_vencimento;
    char nome[50];
    int cpf;
    int data_nascimento;
    int telefone;
    char endereco[50];
    int cep;
    char local[25];
    int numero_da_casa;
    char bairro[25];
    char cidade[25];
    char estado[25];
    int senha_cliente;
    float saldo;
};

int verificar_senhas(char senha_do_sistema[]) {
    char senha[10];
    fflush(stdin);
    fgets(senha, sizeof(senha) - 1, stdin);
    return (strcmp(senha, senha_do_sistema) == 0);
}

// Função auxiliar para tratar entradas de string
void ler_string_completa(char *string, size_t tamanho) {
    fflush(stdin);
    fgets(string, tamanho, stdin);
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';  // Remove a nova linha
    }
}

// Função auxiliar para ler inteiros
void ler_inteiro(int *valor) {
    fflush(stdin);
    scanf("%d", valor);
}

void recebe_dados(FILE *arquivo_cliente, int tipo_conta) {
    system("cls");
    struct conta conta_temp;
    size_t tamanho;

    if (tipo_conta == 1) {
        printf("1 – AGÊNCIA: ");
        ler_inteiro(&conta_temp.agencia);

        printf("\n2 – NUMERO DA CONTA: ");
        ler_inteiro(&conta_temp.numero_da_conta);

        printf("\n3 – NOME DO CLIENTE: ");
        ler_string_completa(conta_temp.nome, sizeof(conta_temp.nome));

        printf("\n4 – CPF DO CLIENTE: ");
        ler_inteiro(&conta_temp.cpf);

        printf("\n5 – DATA DE NASCIMENTO: ");
        ler_inteiro(&conta_temp.data_nascimento);

        printf("\n6 – TELEFONE DE CONTATO: ");
        ler_inteiro(&conta_temp.telefone);

        printf("\n7 – ENDEREÇO DO CLIENTE: ");
        ler_string_completa(conta_temp.endereco, sizeof(conta_temp.endereco));

        printf("\n8 – CEP: ");
        ler_inteiro(&conta_temp.cep);

        printf("\n9 – LOCAL: ");
        ler_string_completa(conta_temp.local, sizeof(conta_temp.local));

        printf(" \n10 – NUMERO DA CASA: ");
        ler_inteiro(&conta_temp.numero_da_casa);

        printf("\n11 – BAIRRO: ");
        ler_string_completa(conta_temp.bairro, sizeof(conta_temp.bairro));

        printf("\n12 – CIDADE: ");
        ler_string_completa(conta_temp.cidade, sizeof(conta_temp.cidade));

        printf("\n13 – ESTADO: ");
        ler_string_completa(conta_temp.estado, sizeof(conta_temp.estado));

        printf("\n14 – SENHA DO CLIENTE: ");
        ler_inteiro(&conta_temp.senha_cliente);

        conta_temp.tipo = 1;
        conta_temp.saldo = 0.0;
        conta_temp.limite = 0;
        conta_temp.data_vencimento = 0;

        fseek(arquivo_cliente, 0, SEEK_END);
        if (fwrite(&conta_temp, sizeof(conta_temp), 1, arquivo_cliente)) {
            printf("Conta cadastrada com sucesso!\n");
        } else {
            printf("Erro ao cadastrar o usuário!");
            fclose(arquivo_cliente);
            exit(1);
        }
        rewind(arquivo_cliente);
    } else {
        printf("1 – AGÊNCIA: ");
        ler_inteiro(&conta_temp.agencia);

        printf("\n2 – NUMERO DA CONTA: ");
        ler_inteiro(&conta_temp.numero_da_conta);

        printf("\n3 – LIMITE DA CONTA: ");
        fflush(stdin);
        scanf("%f", &conta_temp.limite);

        printf("\n4 DATA DE VENCIMENTO: ");
        ler_inteiro(&conta_temp.data_vencimento);

        printf("\n5– NOME DO CLIENTE: ");
        ler_string_completa(conta_temp.nome, sizeof(conta_temp.nome));

        printf("\n6 – CPF DO CLIENTE: ");
        ler_inteiro(&conta_temp.cpf);

        printf("\n7 – DATA DE NASCIMENTO: ");
        ler_inteiro(&conta_temp.data_nascimento);

        printf("\n8 – TELEFONE DE CONTATO: ");
        ler_inteiro(&conta_temp.telefone);

        printf("\n9 – ENDEREÇO DO CLIENTE: ");
        ler_string_completa(conta_temp.endereco, sizeof(conta_temp.endereco));

        printf("\n10 – CEP: ");
        ler_inteiro(&conta_temp.cep);

        printf("\n11 – LOCAL: ");
        ler_string_completa(conta_temp.local, sizeof(conta_temp.local));

        printf(" \n12 – NUMERO DA CASA: ");
        ler_inteiro(&conta_temp.numero_da_casa);

        printf("\n13 – BAIRRO: ");
        ler_string_completa(conta_temp.bairro, sizeof(conta_temp.bairro));

        printf("\n14 – CIDADE: ");
        ler_string_completa(conta_temp.cidade, sizeof(conta_temp.cidade));

        printf("\n15 – ESTADO: ");
        ler_string_completa(conta_temp.estado, sizeof(conta_temp.estado));

        printf("\n16  - SALDO: ");
        fflush(stdin);
        scanf("%f", &conta_temp.saldo);

        printf("\n17 – SENHA DO CLIENTE: ");
        ler_inteiro(&conta_temp.senha_cliente);

        conta_temp.tipo = 2;

        fseek(arquivo_cliente, 0, SEEK_END);
        if (fwrite(&conta_temp, sizeof(conta_temp), 1, arquivo_cliente)) {
            printf("Conta cadastrada com sucesso!\n");
        } else {
            printf("Erro ao cadastrar o usuário!");
            fclose(arquivo_cliente);
            exit(1);
        }
        rewind(arquivo_cliente);
    }
    system("pause");
}

void abrir_conta(FILE *arquivo_cliente) {
    char menu_f;
    do {
        system("cls");
        printf("Abetura de conta");
        printf("\n\n1 - Conta poupanca - CP \n2 - Conta corrente - CC \n3 - voltar");
        printf("\n\nEscolha uma opção: ");
        
        menu_f = getch();
        
        switch(menu_f) {
            case '1':
                recebe_dados(arquivo_cliente, 1);
                break;
            case '2':
                recebe_dados(arquivo_cliente, 2);
                break;
            case '3':
                break;
        }
    } while(menu_f != '3');
}

void excluir_conta(FILE *arquivo_cliente) {
    system("cls");
    const char *nome_antigo = "dados cliente.txt";
    const char *nome_novo = "dados cliente temporario.txt";
    
    FILE *arquivo_cliente_temp = fopen(nome_novo, "w+");
    if (arquivo_cliente_temp == NULL) {
        printf("Ocorrreu um erro ao abrir os arquivos");
        exit(5);
    }
    struct conta conta_analisada;
    int codigo_cliente, encontrado = 0;
    
    printf("Digite o número da conta para encerramento: ");
    fflush(stdin);
    scanf("%d", &codigo_cliente);
    
    fseek(arquivo_cliente, 0, SEEK_SET);
    while(fread(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente)) {
        if (codigo_cliente != conta_analisada.agencia) {
            fseek(arquivo_cliente_temp, 0, SEEK_END);
            fwrite(&conta_analisada, sizeof(conta_analisada), 1, arquivo_cliente_temp);
        } else {
            encontrado = 1;
        }
    }
    if (encontrado) {
        fclose(arquivo_cliente_temp);
        fclose(arquivo_cliente);
        remove(nome_antigo);
        rename(nome_novo, nome_antigo);
        
        arquivo_cliente = fopen("dados cliente.txt", "r+");
        printf("Cliente removido com sucesso!\n");
    } else {
        fclose(arquivo_cliente_temp);
        remove(nome_novo);
        printf("\nNão foram encontrados clientes com esse código.");
    }
    system("pause");
}

void consultar_dados(FILE *arquivo_cliente, FILE *arquivo_funcionario) {
    char menu_f;
    struct conta conta_cliente;
    struct conta_f conta_funcionario;

    do {
        system("cls");
        printf("1 - Consultar conta \n2 - Consultar funcionário \n3 - Consultar cliente \n4 - Sair\n");
        printf("Escolha uma das opções: ");
        menu_f = getch();

        switch(menu_f) {
            case '1': {
                system("cls");
                fseek(arquivo_cliente, 0, SEEK_SET);
                while (fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) {
                    if (conta_cliente.tipo == 1) {
                        printf("Tipo de conta: Conta poupança \nNome do cliente: %s \nCPF do cliente: %d \nSaldo da conta: %.2f \nData de vencimento: %d \n\n",
                            conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.data_vencimento);
                    } else {
                        printf("Tipo de conta: Conta atual \nNome do cliente: %s \nCPF do cliente: %d \nSaldo da conta: %.2f \nData de vencimento: %d \n\n",
                            conta_cliente.nome, conta_cliente.cpf, conta_cliente.saldo, conta_cliente.data_vencimento);
                    }
                }
                system("pause");
                break;
            }
            case '2': {
                system("cls");
                fseek(arquivo_funcionario, 0, SEEK_SET);
                while (fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) {
                    printf("CODIGO: %d \nCARGO: %s \nNOME DO FUNCIONÁRIO: %s \nCPF DO FUNCIONÁRIO: %d \nDATA DE NASCIMENTO: %d \nTELEFONE: %d \n",
                        conta_funcionario.codigo_f, conta_funcionario.cargo_f, conta_funcionario.nome_f, conta_funcionario.cpf_f, 
                        conta_funcionario.data_nascimento_f, conta_funcionario.telefone_f);
                    printf("LOCAL (endereço): %s \nNÚMERO DA CASA: %d \nCEP: %d \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s\n\n", 
                        conta_funcionario.endereco_f, conta_funcionario.numero_da_casa_f, conta_funcionario.cep_f, conta_funcionario.bairro_f, 
                        conta_funcionario.cidade_f, conta_funcionario.estado_f);
                }
                system("pause");
                break;
            }
            case '3': {
                system("cls");
                fseek(arquivo_cliente, 0, SEEK_SET);
                while(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) {
                    printf("NOME DO CLIENTE: %s \nCPF DO CLIENTE: %d \nDADOS DE NASCIMENTO: %d \nTELEFONE: %d \nLOCAL (ENDEREÇO) : %s \n",
                        conta_cliente.nome, conta_cliente.cpf, conta_cliente.data_nascimento, conta_cliente.telefone, conta_cliente.local);
                    printf("NÚMERO DA CASA: %d \nCEP: %d \nBAIRRO: %s \nCIDADE: %s \nESTADO: %s \n\n", 
                        conta_cliente.numero_da_casa, conta_cliente.cep, conta_cliente.bairro, conta_cliente.cidade, conta_cliente.estado);
                }
                system("pause");
                break;
            }
            case '4':
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (menu_f != '4');
}

void alterar_dados(char ADM[], FILE *arquivo_cliente, FILE *arquivo_funcionario) {
    system("cls");
    struct conta conta_cliente;
    struct conta_f conta_funcionario;
    char menu_f;
    size_t tamanho;
    int contador, escolha;

    printf("Coloque a senha do administrador: ");
    if (verificar_senhas(ADM)) {
        do {
            system("cls");
            printf("1 – ALTERAR CONTA \n2 – ALTERAR FUNCIONÁRIO \n3 – ALTERAR CLIENTE \n4 – VOLTAR\n");
            printf("Escolha a opção desejada: ");
            menu_f = getch();

            switch(menu_f) {
                case '1': {
                    system("cls");
                    contador = -1;
                    fseek(arquivo_cliente, 0, SEEK_SET);
                    printf("Contas disponíveis\n\n");
                    while(fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente)) {
                        contador++;
                        printf("Nome do cliente %d: %s\n\n", contador + 1, conta_cliente.nome);
                    }
                    printf("Escolha o número do cliente que deseja modificar: ");
                    scanf("%d", &escolha);

                    if (escolha > contador + 1 || escolha < 1) {
                        printf("Opção inválida");
                        sleep(1);
                    } else {
                        sistema("cls");
                        escolha--;
                        fseek(arquivo_cliente, 0, SEEK_SET);
                        fseek(arquivo_cliente, sizeof(conta_cliente) * escolha, SEEK_SET);
                        fread(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente);
                        fseek(arquivo_cliente, sizeof(conta_cliente), SEEK_CUR);
                        printf("Escolha o que deseja alterar: \n\n1 - TIPO DE CONTA \n2 - LIMITE DISPONÍVEL \n3 - DATA DE VENCIMENTO \n");
                        scanf("%d", &escolha);
                        
                        switch(escolha) {
                            case 1:
                                system("cls");
                                printf("Alterar tipo de conta: ");
                                flush(stdin);
                                conta_cliente.tipo = (conta_cliente.tipo == 1) ? 2 : 1;
                                if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente))
                                    printf("\nAlterado com sucesso!");
                                else
                                    printf("\nOcorreu um erro ao alterar a informação!");
                                sleep(1);
                                break;

                            case 2:
                                system("cls");
                                printf("Coloque o novo limite: ");
                                flush(stdin);
                                scanf("%f", &conta_cliente.limite);
                                if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente))
                                    printf("\nAlterado com sucesso!");
                                else
                                    printf("\nOcorreu um erro ao alterar a informação!");
                                sleep(1);
                                break;

                            case 3:
                                system("cls");
                                printf("Coloque a nova data de vencimento:");
                                fflush(stdin);
                                scanf("%d", &conta_cliente.data_vencimento);
                                if (fwrite(&conta_cliente, sizeof(conta_cliente), 1, arquivo_cliente))
                                    printf("\nAlterado com sucesso!");
                                else
                                    printf("\nOcorreu um erro ao alterar a informação!");
                                break;

                            default:
                                printf("\nOpção inválida\n");
                                break;
                        }
                    }
                    break;
                }

                case '2': {
                    system("cls");
                    contador = -1;
                    fseek(arquivo_funcionario, 0, SEEK_SET);
                    while(fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario)) {
                        contador++;
                        printf("Nome do funcionário %d: %s\n\n", contador + 1, conta_funcionario.nome_f);
                    }
                    printf("Escolha o número do funcionário que deseja modificar: ");
                    scanf("%d", &escolha);

                    if (escolha > contador + 1 || escolha < 1) {
                        printf("Opção inválida");
                        sleep(1);
                    } else {
                        system("cls");
                        escolha--;
                        fseek(arquivo_funcionario, 0, SEEK_SET);
                        fseek(arquivo_funcionario, sizeof(conta_funcionario) * escolha, SEEK_SET);
                        fread(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario);
                        fseek(arquivo_funcionario, sizeof(conta_funcionario), SEEK_CUR);
                        printf("Escolha o que deseja alterar \n\n1- CÓDIGO FUNCIONÁRIO \n2 - CARGO \n3 - TELEFONE \n4 - LOCAL (ENDEREÇO) \n5 - Nº DA CASA \n6 - CEP \n7 - BAIRRO \n8 - CIDADE \n9 - ESTADO\n");
                        scanf("%d", &escolha);

                        switch(escolha) {
                            case 1:
                                system("cls");
                                printf("Coloque o novo código do funcionário: ");
                                flush(stdin);
                                scanf("%d", &conta_funcionario.codigo_f);
                                if (fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario))
                                    printf("\nAlterado com sucesso!");
                                else
                                    printf("\nOcorreu um erro ao alterar a informação!");
                                sleep(1);
                                break;

                            case 2:
                                system("cls");
                                printf("Coloque a nova carga do funcionário: ");
                                flush(stdin);
                                fgets(conta_funcionario.cargo_f, sizeof(conta_funcionario.cargo_f), stdin);
                                tamanho = strlen(conta_funcionario.cargo_f);
                                if (conta_funcionario.cargo_f[tamanho - 1] == '\n') {
                                    conta_funcionario.cargo_f[tamanho - 1] = '\0';
                                }
                                if (fwrite(&conta_funcionario, sizeof(conta_funcionario), 1, arquivo_funcionario))
                                    printf("\nAlterado com sucesso!");
                                else
                                    printf("\nOcorreu um erro ao alterar a informação!");
                                sleep(1);
                                break;
  
                            // Continue similar modifications for other options ...
  
                            default:
                                printf("Opção inválida\n");
                                break;
                        }
                    }
                    break;
                }

                case '3': {
                    // Implement similar case for alterar dados do cliente.
                }

                case '4':
                    break;

                default:
                    printf("Opção inválida\n");
                    break;
            }
        } while (menu_f != '4');
    }
}

