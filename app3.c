/* 
**
** Nome do Arquivo: app3.c
**
** Nome do Autor: Caio Araujo Batista
**
** Finalidade do Programa: Testar as funções de filmes
**
** Data de criação: 01/06/2025
**
*/

#include <stdio.h>
#include "filmes.h"
#include "diretores.h"

int main() {
  if ( !diretores_carrega("diretores.txt") ) return 0;
  if ( !filmes_carrega("filmes.txt") ) return 0;
  printf("----------\n");
  filmes_mostra();
  filmes_ordena();
  if ( !filmes_salva("filmes.txt.out") ) return 0;
  printf("----------\n");
  filmes_mostra();
  printf("----------\n");
  return 0;
}
