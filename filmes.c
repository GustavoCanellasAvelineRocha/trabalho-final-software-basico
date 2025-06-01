// filmes.c (Caio Batista; 01 junho 2025)

#include "filmes.h"
#include "diretores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_LINHA 200

filme_t filmes[MAX_FILMES];
int num_filmes = 0;

int filmes_menor(filme_t *a1, filme_t *a2) {
    return strcmp(a1->titulo, a2->titulo) < 0;
}

int filmes_carrega(char *nome_arq) {
    FILE *in = fopen(nome_arq, "r");
    if (in == NULL) return 0;
    char linha[TAM_LINHA+1];
    size_t t;

    while (1) {
        if (fgets(linha, TAM_LINHA, in) == NULL) break;
        filmes[num_filmes].id = atoi(linha);

        if (fgets(linha, TAM_LINHA, in) == NULL) break;
        t = strlen(linha);
        if (linha[t-1] == '\n') linha[t-1] = '\0';
        strncpy(filmes[num_filmes].titulo, linha, TAM_TITULO);
        filmes[num_filmes].titulo[TAM_TITULO] = '\0';

        if (fgets(linha, TAM_LINHA, in) == NULL) break;
        filmes[num_filmes].ano_lancamento = atoi(linha);

        if (fgets(linha, TAM_LINHA, in) == NULL) break;
        filmes[num_filmes].id_diretor = atoi(linha);

        ++num_filmes;
        if (num_filmes == MAX_FILMES) break;
    }
    fclose(in);
    return 1;
}

int filmes_num_filmes() {
    return num_filmes;
}

filme_t *filmes_obtem_filme_id(int id) {
    for (int i = 0; i < num_filmes; i++) {
        if (filmes[i].id == id) {
            return &filmes[i];
        }
    }
    return NULL;
}

filme_t *filmes_obtem_filme_indice(int indice) {
    if (indice >= 0 && indice < num_filmes) {
        return &filmes[indice];
    }
    return NULL;
}

void filmes_mostra_filme(filme_t *filme) {
    if (!filme) return;
    diretor_t *diretor = diretores_obtem_diretor_id(filme->id_diretor);
    printf("[%d] %s (%d) - %s\n", 
        filme->id, 
        filme->titulo, 
        filme->ano_lancamento, 
        diretor->nome);
}

void filmes_mostra() {
    for (int i = 0; i < num_filmes; i++) {
        filmes_mostra_filme(&filmes[i]);
    }
}

void filmes_ordena() {
    for(int i = 0; i < num_filmes; i++) {
        int men = i;
        for(int j = i+1; j < num_filmes; j++) {
            if(filmes_menor(&filmes[j], &filmes[men])) {
                men = j;
            }
        }

        if(men != i) {
            filme_t aux = filmes[men];
            filmes[men] = filmes[i];
            filmes[i] = aux;
        }
    }
}

int filmes_salva(char *nome_arq) {
    FILE *out = fopen(nome_arq, "w");
    if (out == NULL) return 0;
    for (int i = 0; i < num_filmes; i++) {
        fprintf(out, "%d\n", filmes[i].id);
        fprintf(out, "%s\n", filmes[i].titulo);
        fprintf(out, "%d\n", filmes[i].ano_lancamento);
        fprintf(out, "%d\n", filmes[i].id_diretor);
    }
    fclose(out);
    return 1;
}
