// filmes.h (Caio Batista; 01 junho 2025)

#define TAM_TITULO 60
#define MAX_FILMES 100

typedef struct {
    int id;
    char titulo[TAM_TITULO+1];
    int ano_lancamento;
    int id_diretor;
} filme_t;

int filmes_menor(filme_t *a1, filme_t *a2);
int filmes_carrega(char *nome_arq);
int filmes_num_filmes();
filme_t *filmes_obtem_filme_id(int id);
filme_t *filmes_obtem_filme_indice(int indice);
void filmes_mostra_filme(filme_t *filme);
void filmes_mostra();
void filmes_ordena();
int filmes_salva(char *nome_arq);
