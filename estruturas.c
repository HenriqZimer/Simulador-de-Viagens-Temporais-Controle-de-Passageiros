#include "estruturas.h"

Era* inicializar_eras() {
  Era* e1 = malloc(sizeof(Era)); strcpy_simples(e1->nome, "Idade Media"); e1->limite = 2; e1->ocupacao = 0;
  Era* e2 = malloc(sizeof(Era)); strcpy_simples(e2->nome, "Era dos Dinossauros"); e2->limite = 2; e2->ocupacao = 0;
  Era* e3 = malloc(sizeof(Era)); strcpy_simples(e3->nome, "Ano 3000"); e3->limite = 2; e3->ocupacao = 0;
  Era* e4 = malloc(sizeof(Era)); strcpy_simples(e4->nome, "Corrida Espacial"); e4->limite = 2; e4->ocupacao = 0;
  Era* e5 = malloc(sizeof(Era)); strcpy_simples(e5->nome, "Revolucao Industrial"); e5->limite = 2; e5->ocupacao = 0;

  e1->prox = e2; e2->prox = e3; e3->prox = e4; e4->prox = e5; e5->prox = NULL;
  return e1;
}

void adicionar_espera(Passageiro** inicio, char nome[], char destino[]) {
  Passageiro* novo = malloc(sizeof(Passageiro));
  strcpy_simples(novo->nome, nome);
  strcpy_simples(novo->destino, destino);
  novo->prox = NULL;

  if (*inicio == NULL) *inicio = novo;
  else {
    Passageiro* aux = *inicio;
    while (aux->prox) aux = aux->prox;
    aux->prox = novo;
  }
}

void listar_espera(Passageiro* inicio) {
  int i = 1;
  while (inicio) {
    printf("%d. %s -> %s\n", i++, inicio->nome, inicio->destino);
    inicio = inicio->prox;
  }
}

Era* buscar_era(Era* eras, char destino[]) {
  while (eras) {
    if (strcmp_simples(eras->nome, destino) == 0) return eras;
    eras = eras->prox;
  }
  return NULL;
}

int embarcar_passageiro(Passageiro** espera, PassageiroEmbarcado** embarcados, Era* eras, int posicao) {
  if (*espera == NULL) return 0;
  Passageiro* anterior = NULL, * atual = *espera;
  for (int i = 1; atual && i < posicao; i++) {
    anterior = atual;
    atual = atual->prox;
  }
  if (!atual) return 0;

  Era* era = buscar_era(eras, atual->destino);
  if (!era || era->ocupacao >= era->limite) return 0;

  PassageiroEmbarcado* novo = malloc(sizeof(PassageiroEmbarcado));
  strcpy_simples(novo->nome, atual->nome);
  strcpy_simples(novo->destino, atual->destino);
  novo->ant = novo->prox = NULL;

  if (*embarcados == NULL) *embarcados = novo;
  else {
    PassageiroEmbarcado* aux = *embarcados;
    while (aux->prox) aux = aux->prox;
    aux->prox = novo;
    novo->ant = aux;
  }

  if (anterior == NULL) *espera = atual->prox;
  else anterior->prox = atual->prox;

  era->ocupacao++;
  log_acao("embarcado", novo->nome, novo->destino);
  free(atual);
  return 1;
}

void listar_embarcados(PassageiroEmbarcado* inicio) {
  int i = 1;
  while (inicio) {
    printf("%d. %s -> %s\n", i++, inicio->nome, inicio->destino);
    inicio = inicio->prox;
  }
}

int desembarcar_passageiro(PassageiroEmbarcado** embarcados, Era* eras, int posicao) {
  if (*embarcados == NULL) return 0;
  PassageiroEmbarcado* atual = *embarcados;
  for (int i = 1; atual && i < posicao; i++) {
    atual = atual->prox;
  }
  if (!atual) return 0;

  Era* era = buscar_era(eras, atual->destino);
  if (era) era->ocupacao--;

  if (atual->ant) atual->ant->prox = atual->prox;
  else *embarcados = atual->prox;
  if (atual->prox) atual->prox->ant = atual->ant;

  log_acao("desembarcado", atual->nome, atual->destino);
  free(atual);
  return 1;
}

void log_acao(const char* acao, const char* nome, const char* destino) {
  printf("[LOG] Passageiro '%s' %s para '%s'\n", nome, acao, destino);
}

void strcpy_simples(char* dest, const char* src) {
  while ((*dest++ = *src++));
}

int strcmp_simples(const char* s1, const char* s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char*)s1 - *(unsigned char*)s2;
}