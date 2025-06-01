// diretores.h (Caio Batista; 01 junho 2025)

#define TAM_LOCAL 30
#define TAM_NOME 60 
#define MAX_DIRETORES 100

typedef struct {
    int dia;
    int mes;
    int ano;
} data_t;

typedef struct {
    int id;
    char nome[TAM_NOME+1];
    char local_nascimento[TAM_LOCAL+1];
    data_t data_nascimento;
    char local_falecimento[TAM_LOCAL+1];
    data_t data_falecimento;
} diretor_t;

int diretores_menor(diretor_t *a1, diretor_t *a2);
int diretores_carrega(char *nome_arq);
int diretores_num_diretores();
diretor_t *diretores_obtem_diretor_id(int id);
diretor_t *diretores_obtem_diretor_indice(int indice);
void diretores_mostra_diretor(diretor_t *diretor);
void diretores_mostra();
void diretores_ordena();
int diretores_salva(char *nome_arq);
