// diretores.c (Caio Batista; 01 junho 2025)

#include "diretores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 200

diretor_t diretores[MAX_DIRETORES];
int num_diretores = 0;

int diretores_menor(diretor_t *a1, diretor_t *a2) {
    return strcmp(a1-> nome, a2-> nome) < 0;
}

int diretores_carrega(char *nome_arq) {
    FILE *in = fopen(nome_arq,"r");
    if(in == NULL) return 0;
    char linha[TAM_LINHA+1];
    size_t t;

    while(1) {
        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        diretores[num_diretores].id = atoi(linha);

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        t = strlen(linha);
        if(linha[t-1] == '\n') linha[t-1] = '\0';
        strncpy(diretores[num_diretores].nome, linha, TAM_NOME);
        diretores[num_diretores].nome[TAM_NOME] = '\0';

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        t = strlen(linha);
        if(linha[t-1] == '\n') linha[t-1] = '\0';
        strncpy(diretores[num_diretores].local_nascimento, linha, TAM_LOCAL);
        diretores[num_diretores].local_nascimento[TAM_LOCAL] = '\0';

        data_t data_nascimento;

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_nascimento.dia = atoi(linha);

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_nascimento.mes = atoi(linha);

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_nascimento.ano = atoi(linha);

        diretores[num_diretores].data_nascimento = data_nascimento;

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        t = strlen(linha);
        if(linha[t-1] == '\n') linha[t-1] = '\0';
        strncpy(diretores[num_diretores].local_falecimento, linha, TAM_LOCAL);
        diretores[num_diretores].local_falecimento[TAM_LOCAL] = '\0';

        data_t data_falecimento;

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_falecimento.dia = atoi(linha);

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_falecimento.mes = atoi(linha);

        if(fgets(linha, TAM_LINHA, in) == NULL) break;
        data_falecimento.ano = atoi(linha);

        diretores[num_diretores].data_falecimento = data_falecimento;

        ++num_diretores;

        if(num_diretores == MAX_DIRETORES) break;
    }
    fclose(in);
    return 1;
}

int diretores_num_diretores() {
    return num_diretores;
}

diretor_t *diretores_obtem_diretor_id(int id) {
    for (int i = 0; i < num_diretores; i++) {
        if (diretores[i].id == id) {
            return &diretores[i];
        }
    }
    return NULL;
}

diretor_t *diretores_obtem_diretor_indice(int indice) {
    if (indice >= 0 && indice < num_diretores) {
        return &diretores[indice];
    }
    return NULL;
}

void diretores_mostra_diretor(diretor_t *diretor) {
    if (!diretor) return;
    printf("[%d] %s (* %s, %02d/%02d/%04d)\n",
        diretor->id,
        diretor->nome,
        diretor->local_nascimento,
        diretor->data_nascimento.dia,
        diretor->data_nascimento.mes,
        diretor->data_nascimento.ano
    );
}
void diretores_mostra() {
    for (int i = 0; i < num_diretores; i++) {
        diretores_mostra_diretor(&diretores[i]);
    }
}

void diretores_ordena() {
    for(int i = 0; i < num_diretores; i++) {
        int men = i;
        for(int j = i+1; j < num_diretores; j++) {
            if(diretores_menor(&diretores[j], &diretores[men])) {
                men = j;
            }
        }

        if(men != i) {
            diretor_t aux = diretores[men];
            diretores[men] = diretores[i];
            diretores[i] = aux;
        }
    }
}

int diretores_salva(char *nome_arq) {
    FILE *out = fopen(nome_arq, "w");
    if(out == NULL) return 0;
    for(int i = 0; i < num_diretores; i++) {
        fprintf(out, "%d\n", diretores[i].id);
        fprintf(out, "%s\n", diretores[i].nome);
        fprintf(out, "%s\n", diretores[i].local_nascimento);
        fprintf(out, "%d\n", diretores[i].data_nascimento.dia);
        fprintf(out, "%d\n", diretores[i].data_nascimento.mes);
        fprintf(out, "%d\n", diretores[i].data_nascimento.ano);
        fprintf(out, "%s\n", diretores[i].local_falecimento);
        fprintf(out, "%d\n", diretores[i].data_falecimento.dia);
        fprintf(out, "%d\n", diretores[i].data_falecimento.mes);
        fprintf(out, "%d\n", diretores[i].data_falecimento.ano);
    }
    return 1;
}
