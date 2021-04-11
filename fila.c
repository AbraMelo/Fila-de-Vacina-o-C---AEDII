#include "fila.h"
//========================================
void print_pessoa(Pessoa p){
  printf("{nome: %s, idade: %d, fase: %d}\n", p.nome, p.idade, p.prioridade);
}
//========================================
Celula *new_celula(){
  Celula *tmp = (Celula*) malloc(sizeof(Celula));
  tmp->prox = NULL;
  return tmp;
}
//========================================
void new_fila(Fila *f){

  Celula *nova = new_celula();

  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}
//========================================
void enqueue(Fila *f, Pessoa dado){

  Celula *nova = new_celula();
  nova->dado = dado;

  f->fim->prox = nova;
  f->fim = nova;
  f->tam++;
}
//========================================
void print_fila(Fila *f){

  Celula *tmp = f->inicio->prox;

  while(tmp != NULL){
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}
//========================================
int size_fila(Fila *f){
  return f->tam;
}
//========================================
Pessoa dequeue(Fila *f){

  if(f->tam == 0){
    Pessoa p = {"Invalido", -1};
    return p;
  }


  Celula *tmp = f->inicio;

  f->inicio = f->inicio->prox;  
  
  free(tmp);

  f->tam--;

  return f->inicio->dado;

}