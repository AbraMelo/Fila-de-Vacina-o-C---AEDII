#include "fila.h"

//Impelemntação do método print do tipo void que recebe como parametro um objeto Pessoa e retorna a impressão
void print_pessoa(Pessoa p){
  printf("{nome: %s, idade: %d, fase: %d}\n", p.nome, p.idade, p.prioridade);
}

//Implementação do metodo new celula do tipo Celula que não recebe parametro e faz a criação de uma nova celula e retorna uma variavel temporaria
Celula *new_celula(){
  //alocação dinamica de memoria
  Celula *tmp = (Celula*) malloc(sizeof(Celula));
  //tempo que aponta para o proximo recebe NULL
  tmp->prox = NULL;
  return tmp;
}

//Implementação do metodo new fila do tipo void que recebe uma fila como paramentro e faz a criação de uma nova fila
void new_fila(Fila *f){
  //atribuição de uma nova celula
  Celula *nova = new_celula();
  //atribuição da fila na nova celula
  f->inicio = nova;
  f->fim = nova;
  //nova fila tem o tamanho 0
  f->tam = 0;
}

//Implementação do metodo enqueue do tipo void que recebe como paramtro uma fila e o dado de uma pessoa e adiciona uma pessoa na fila enfileirando-a
void enqueue(Fila *f, Pessoa dado){
  //Declaração de duas variaveis do tipo celula
  Celula *ant = f->inicio;
  Celula *temp=f->inicio->prox;
  //Declaração de uma variavel que recebe uma nova celula
  Celula *nova = new_celula();
  nova->dado = dado;
  //no final da fila entra as pessoas sem prioridade
  if(dado.prioridade==5){ 
    f->fim->prox = nova;
    f->fim = nova;
    f->tam++;
  }
  else{
    while(temp!=NULL &&   temp->dado.prioridade <= dado.prioridade ){
      ant=ant->prox;
      temp=temp->prox;
    }
    nova->prox=temp;
    ant->prox=nova;
    f->tam++;

  }

}

//Implementaçao do metodo print fila do tipo void que recebe uma fila como parametro e imprimi-a 
void print_fila(Fila *f){

  Celula *tmp = f->inicio->prox;

  //celula temporaria não pode apontar para NULL
  while(tmp != NULL){
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}

//Implementação do metodo print fila especifica do tipo void que recebe uma fila como paramentro e um inteiro p
void print_fila_especifica(Fila *f, int p){

  Celula *tmp = f->inicio->prox;
 while(tmp!=NULL &&   tmp->dado.prioridade < p ){
      tmp=tmp->prox;
    }
  
  while(tmp != NULL && tmp->dado.prioridade==p){
    print_pessoa(tmp->dado);
    tmp = tmp->prox;
  }
}

void print_posfila(Fila *f, char nome){

  Celula *tmp = f->inicio->prox;

  int cont=0;

  //celula temporaria não pode apontar para NULL
  while(tmp != NULL && tmp->dado.nome!=nome){
    tmp = tmp->prox;
    cont++;
  }

   printf("posicao na fila : %d}", cont);
}
//Implementação  do metodo size_fila que recebe uma fila como parametro e retorna o tamanho da fila
int size_fila(Fila *f){
  return f->tam;
}


//Implementação do metodo dequeue do tipo Pessoa que recebe uma fila como parametro e retorna o ultimo dado removido
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