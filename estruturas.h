
// estruturas.h
#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// TAD Era (lista encadeada simples)
typedef struct Era {
  char nome[50];
  int limite;
  int ocupacao;
  struct Era* prox;
} Era;

// TAD Passageiro na espera (lista encadeada simples)
typedef struct Passageiro {
  char nome[50];
  char destino[50];
  struct Passageiro* prox;
} Passageiro;

// TAD Passageiro embarcado (lista duplamente encadeada)
typedef struct PassageiroEmbarcado {
  char nome[50];
  char destino[50];
  struct PassageiroEmbarcado* ant;
  struct PassageiroEmbarcado* prox;
} PassageiroEmbarcado;

// Funções públicas
Era* inicializar_eras();
void listar_espera(Passageiro* inicio);
void adicionar_espera(Passageiro** inicio, char nome[], char destino[]);
int embarcar_passageiro(Passageiro** espera, PassageiroEmbarcado** embarcados, Era* eras, int posicao);
void listar_embarcados(PassageiroEmbarcado* inicio);
int desembarcar_passageiro(PassageiroEmbarcado** embarcados, Era* eras, int posicao);
void log_acao(const char* acao, const char* nome, const char* destino);
Era* buscar_era(Era* eras, char destino[]);

#endif