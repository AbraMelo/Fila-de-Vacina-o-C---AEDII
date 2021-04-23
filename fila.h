#ifndef  FILA_H
#define  FILA_H
//========================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//========================================
typedef struct Pessoa{
  char nome[100];
  int idade;
  int prioridade;
}Pessoa;
void print_pessoa(Pessoa p);
//========================================
typedef struct Celula{
  Pessoa dado;
  struct Celula *prox;
}Celula;
//========================================
typedef struct Fila{
  Celula *inicio;
  Celula *fim;
  int tam;
}Fila;
//========================================
Celula *new_celula();
//========================================
void new_fila(Fila *f);
//========================================
void enqueue(Fila *f, Pessoa dado);
//========================================
void print_fila(Fila *f);
//========================================
void print_fila_especifica(Fila *f, int p);
//========================================
int size_fila(Fila *f);
//========================================
Pessoa dequeue(Fila *f);
//========================================
#endif 