/* 
**
** Nome do Arquivo: app2.c
**
** Nome do Autor: Caio Araujo Batista
**
** Finalidade do Programa: Testar as funções de diretores
**
** Data de criação: 01/06/2025
**
*/

#include <stdio.h>
#include "diretores.h"

int main() {
  if ( !diretores_carrega("diretores.txt") ) return 0;
  printf("----------\n");
  diretores_mostra();
  diretores_ordena();
  if ( !diretores_salva("diretores.txt.out") ) return 0;
  printf("----------\n");
  diretores_mostra();
  printf("----------\n");
  return 0;
}
