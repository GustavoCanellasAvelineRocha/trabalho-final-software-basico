#include <ctype.h>

static int ci_char(int c){ return tolower((unsigned char)c); }

static int ci_contains(const char *hay, const char *needle){
    if(!hay || !needle || !*needle) return 0;
    size_t nlen = strlen(needle);
    for(const char *p = hay; *p; ++p){
        size_t i = 0;
        while(p[i] && i < nlen && ci_char(p[i]) == ci_char(needle[i])) i++;
        if(i == nlen) return 1;
    }
    return 0;
}

int filmes_existe_id(int id){
    return filmes_obtem_filme_id(id) != NULL;
}

int filmes_insere(const filme_t *novo){
    if(!novo) return 0;
    if(num_filmes >= MAX_FILMES) return 0;
    if(filmes_existe_id(novo->id)) return 0;
    filmes[num_filmes] = *novo;
    num_filmes++;
    return 1;
}

int filmes_remove_por_id(int id){
    for(int i=0;i<num_filmes;i++){
        if(filmes[i].id == id){
            for(int j=i+1;j<num_filmes;j++) filmes[j-1] = filmes[j];
            num_filmes--;
            return 1;
        }
    }
    return 0;
}

int filmes_atualiza_por_id(int id, const char *novo_titulo, int novo_ano, int novo_id_diretor){
    filme_t *f = filmes_obtem_filme_id(id);
    if(!f) return 0;
    if(novo_titulo && *novo_titulo){
        strncpy(f->titulo, novo_titulo, TAM_TITULO);
        f->titulo[TAM_TITULO] = '\0';
    }
    if(novo_ano > 0) f->ano_lancamento = novo_ano;
    if(novo_id_diretor > 0) f->id_diretor = novo_id_diretor;
    return 1;
}

int filmes_busca_por_titulo(const char *termo, int *indices, int max_indices){
    if(!termo || !indices || max_indices<=0) return 0;
    int k = 0;
    for(int i=0;i<num_filmes;i++){
        if(ci_contains(filmes[i].titulo, termo)){
            if(k < max_indices) indices[k] = i;
            k++;
        }
    }
    return k;
}

void filmes_limpa(void){
    num_filmes = 0;
}

void filmes_mostra_filme(filme_t *filme) {
    if (!filme) return;
    diretor_t *diretor = diretores_obtem_diretor_id(filme->id_diretor);
    const char *nome_dir = (diretor && diretor->nome) ? diretor->nome : "(diretor desconhecido)";
    printf("[%d] %s (%d) - %s\n",
        filme->id,
        filme->titulo,
        filme->ano_lancamento,
        nome_dir);
}
