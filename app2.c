// app2.cpp (Roland Teodorowitsch; 14 maio 2025)

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
