#include <stdio.h>
#include <string.h>
#include<windows.h>
#include "relatorios.h"
    
void emitirRelatorioGeral(Passagem *passagens, int numPassagens) {
    SetConsoleOutputCP(CP_UTF8); 
    FILE *arquivo = fopen("relatorio_geral.txt", "w");
    if (arquivo == NULL) {
        printf("❌ ​Erro ao abrir arquivo!\n\n");
        return;
    }

    for (int i = 0; i < numPassagens; i++) {
        fprintf(arquivo, "\n\n🆔 ID: %d\n\n📍 Destino: %s\n\n💵 Preco: %.2f\n\n📅 Data: %s\n\n✈️ Companhia: %s\n\n",
                passagens[i].id, passagens[i].destino, passagens[i].preco,
                passagens[i].data, passagens[i].companhia);
    }

    fclose(arquivo);
    printf("\n\n✅ Relatorio geral gerado com sucesso!\n\n");
}

void emitirRelatorioPorDestino(Passagem *passagens, int numPassagens) {
    char destino[50];
    SetConsoleOutputCP(CP_UTF8); 
    printf("📌​ Informe o destino para o relatorio: ");
    scanf(" %[^\n\n]s", destino);

    FILE *arquivo = fopen("relatorio_destino.txt", "w");
    if (arquivo == NULL) {
        printf("\n\n❌​ Erro ao abrir arquivo!\n\n");
        return;
    }

    for (int i = 0; i < numPassagens; i++) {
        if (strcmp(passagens[i].destino, destino) == 0) {
            fprintf(arquivo, "\n🆔 ID: %d\n💵 Preco: %.2f\n📅 Data: %s\n✈️ Companhia: %s\n\n",
                    passagens[i].id, passagens[i].preco,
                    passagens[i].data, passagens[i].companhia);
        }
    }

    fclose(arquivo);
    printf("\n✅​ Relatorio por destino gerado com sucesso!\n\n");
}
