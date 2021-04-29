#ifndef  FILA_H
#define  FILA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaração do tipo Pessoa
typedef struct Pessoa{
  char nome[100];
  int idade;
  int prioridade;
}Pessoa;
//Assinatura do metodo para imprimir uma pessoa
void print_pessoa(Pessoa p);
//Declaração do tipo Celula
typedef struct Celula{
  Pessoa dado;
  struct Celula *prox;
}Celula;
//Declaração do tipo Fila
typedef struct Fila{
  Celula *inicio;
  Celula *fim;
  int tam;
}Fila;
//Assinatura do metodo para criar uma nova celula
Celula *new_celula();
//Assinatura do metodo para criar uma nova fila
void new_fila(Fila *f);
//Assinatura do metodo para enfileirar o dado de uma pessoa na fila
void enqueue(Fila *f, Pessoa dado);
//Assinatura do metodo imprimir a fila
void print_fila(Fila *f);
//Assinatura do metodo para imprimir uma fila especifica de uma fase
void print_fila_especifica(Fila *f, int p);
//Assinatura do metodo para retornar o tamanho da fila
int size_fila(Fila *f);
//Assinatura do metodo para desinfileirar uma pessoa da fila

void print_posfila(Fila *f, char nome);

Pessoa dequeue(Fila *f);
//========================================
#endif 