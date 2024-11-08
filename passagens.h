#ifndef PASSAGENS_H
#define PASSAGENS_H

typedef struct {
    int id;
    char destino[50];
    float preco;
    char data[20];
    char companhia[50];
} Passagem;

void adicionarPassagem(Passagem **passagens, int *numPassagens);
void visualizarPassagens(Passagem *passagens, int numPassagens);
void atualizarPassagem(Passagem *passagens, int numPassagens);
void removerPassagem(Passagem **passagens, int *numPassagens);

void adicionarAoCarrinho(Passagem *passagens, int numPassagens);
void menuPagamento(float totalCarrinho);

#endif
