#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "passagens.h"

void adicionarPassagem(Passagem **passagens, int *numPassagens) {
    *passagens = realloc(*passagens, (*numPassagens + 1) * sizeof(Passagem));
    if (*passagens == NULL) {
        printf("❌ Erro ao alocar memoria!\n");
        return;
    }
    SetConsoleOutputCP(CP_UTF8);

    printf("\n🆔 ID: ");
    scanf("%d", &(*passagens)[*numPassagens].id);
    printf("\n📍 Destino: ");
    scanf(" %[^\n]s", (*passagens)[*numPassagens].destino);
    printf("\n💵 Preco: ");
    scanf("%f", &(*passagens)[*numPassagens].preco);
    printf("\n📅 Data: ");
    scanf(" %[^\n]s", (*passagens)[*numPassagens].data);
    printf("\n✈️ Companhia: ");
    scanf(" %[^\n]s", (*passagens)[*numPassagens].companhia);

    (*numPassagens)++;
}

void visualizarPassagens(Passagem *passagens, int numPassagens) {
    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < numPassagens; i++) {
        printf("\n\n🆔 ID: %d\n\n📍 Destino: %s\n\n💵 Preco: %.2f\n\n📅 Data: %s\n\n✈️ Companhia: %s\n\n",
               passagens[i].id, passagens[i].destino, passagens[i].preco,
               passagens[i].data, passagens[i].companhia);
    }
}

void atualizarPassagem(Passagem *passagens, int numPassagens) {
    int id, encontrado = 0;
    printf("\n\nInforme o ID da passagem a ser atualizada: ");
    scanf("%d", &id);
    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < numPassagens; i++) {
        if (passagens[i].id == id) {
            printf("\n📍 Novo Destino: ");
            scanf(" %[^\n]s", passagens[i].destino);
            printf("\n💵 Novo Preco: ");
            scanf("%f", &passagens[i].preco);
            printf("\n📅 Nova Data: ");
            scanf(" %[^\n]s", passagens[i].data);
            printf("\n✈️ Nova Companhia: ");
            scanf(" %[^\n]s", passagens[i].companhia);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n\n❌ Passagem com ID %d nao encontrada.\n\n", id);
    }
}

void removerPassagem(Passagem **passagens, int *numPassagens) {
    int id, encontrado = 0;
    printf("\nInforme o ID da passagem a ser removida: ");
    scanf("%d", &id);
    SetConsoleOutputCP(CP_UTF8);
    for (int i = 0; i < *numPassagens; i++) {
        if ((*passagens)[i].id == id) {
            for (int j = i; j < *numPassagens - 1; j++) {
                (*passagens)[j] = (*passagens)[j + 1];
            }
            *numPassagens -= 1;
            *passagens = realloc(*passagens, *numPassagens * sizeof(Passagem));
            encontrado = 1;
            printf("\n✅ Passagem removida com sucesso!\n\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Passagem com ID %d nao encontrada.\n\n", id);
    }
}

void adicionarAoCarrinho(Passagem *passagens, int numPassagens) {
    int id, mais = 1;
    float total = 0;

    while (mais) {
        printf("\nInforme o ID da passagem para adicionar ao carrinho: ");
        scanf("%d", &id);

        int encontrado = 0;
        for (int i = 0; i < numPassagens; i++) {
            if (passagens[i].id == id) {
                total += passagens[i].preco;
                printf("\nPassagem %s adicionada ao carrinho!\n\n", passagens[i].destino);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("\nPassagem com ID %d nao encontrada.\n\n", id);
        }

        printf("Deseja adicionar outra passagem? (1-Sim / 0-Nao): ");
        scanf("%d", &mais);
    }

    menuPagamento(total);
}

void menuPagamento(float totalCarrinho) {
    int opcao, parcelas;

    printf("\nTotal no carrinho: R$%.2f\n\n", totalCarrinho);
    printf("Escolha a forma de pagamento:\n\n1. A vista 💵\n\n2. Cartao de Credito 💳\n\n3. Pix 💸\n\n");
    printf("➡️ Opcao: ");
    scanf("%d", &opcao);

    system("cls");

    switch (opcao) {
        case 1:
            printf("\nPagamento a vista selecionado. \n\n💲Total: R$%.2f\n\n", totalCarrinho);
            break;
        case 2:
            printf("\nInforme o numero de parcelas: ");
            scanf("%d", &parcelas);
            system("cls"); 
            printf("\nPagamento parcelado em %d vezes de R$%.2f\n\n", parcelas, totalCarrinho / parcelas);
            break;
        case 3:
            printf("\nPagamento via Pix selecionado.\n\n💲Total: R$%.2f\n\n", totalCarrinho);
            break;
        default:
            printf("\n⚠️ Opcao invalida.\n\n");
    }
}
