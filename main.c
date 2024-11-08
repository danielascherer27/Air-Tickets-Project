#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "passagens.h"
#include "relatorios.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    Passagem *passagens = NULL;
    int numPassagens = 0;
    int opcao;
    
    do {
        printf("\n\n-----  📋 MENU 📋 -----\n\n");
        printf("1.✈️ Adicionar Passagem\n\n");
        printf("2.👀 Visualizar Passagens\n\n");
        printf("3.✏️ Atualizar Passagem\n\n");
        printf("4.🗑️ Remover Passagem\n\n");
        printf("5.🛒 Carrinho de Compras\n\n");
        printf("6.📊 Emitir Relatorio Geral\n\n");
        printf("7.🌎 Emitir Relatorio por Destino\n\n");
        printf("0.❌ Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                adicionarPassagem(&passagens, &numPassagens);
                break;
            case 2:
                visualizarPassagens(passagens, numPassagens);
                break;
            case 3:
                atualizarPassagem(passagens, numPassagens);
                break;
            case 4:
                removerPassagem(&passagens, &numPassagens);
                break;
            case 5:
                adicionarAoCarrinho(passagens, numPassagens);
                break;
            case 6:
                emitirRelatorioGeral(passagens, numPassagens);
                break;
            case 7:
                emitirRelatorioPorDestino(passagens, numPassagens);
                break;
            case 0:
                printf("👋​ Saindo do programa.​\n\n");
                break;
            default:
                printf("⚠️ Opcao invalida!\n\n");
        }

        if (opcao != 0) { 
            system("pause");
            system("cls");
        }

    } while (opcao != 0);

    free(passagens);
    return 0;
}
    