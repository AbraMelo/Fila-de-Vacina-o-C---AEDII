#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

/*
Sistema para gerenciar uma Fila de Pessoas
 - Pessoa (Nome, Idade)
 - Enfileirar, Desenfileirar, Exibir, Tamanho
*/


//Função Menu que corresponde ao inicio do programa no console e retorna a opção do usuario
int menu(){
  int opcao = 0;
  printf("\n =====> Fila de Vacinação  <=====\n");
  printf(" Escolha uma opcao\n");
  printf(" 1 - Cadastrar uma pessoa na fila \n");
  printf(" 2 - Retirar uma pessoa da fila\n");
  printf(" 3 - Exibir a fila geral\n");
  printf(" 4 - Exibir a fila da fase 1\n");
  printf(" 5 - Exibir a fila da fase 2\n");
  printf(" 6 - Exibir a fila da fase 3\n");
  printf(" 7 - Exibir a fila da fase 4\n");
  printf(" 8 - Exibir a fila da fase 5\n");
  printf(" 9 - Consultar posicao na fila \n");
  printf(" 0 - Sair\n");
  printf(" Digite a opcao desejada:\n ");
  scanf("%d", &opcao);
  return opcao;
}
//Procedimento que recebe como parametro o objeto Pessoa e faz as perguntas ao usuario
void perguntas(Pessoa *p){
  //Perguntas
  p->prioridade=5;
  int resposta=0;
  printf(" Qual seu nome:\n");
  scanf("%s", p->nome);
  printf(" Qual sua idade: \n");
  scanf("%i", &p->idade);
  //Saber se é prioritario ou não
  while(resposta!=1 && resposta!=2){
    printf(" Você é trabalhador da Saúde ou vive em instituição de longa permanência? \n Digite: \n 1 - Sim \n 2 - Não \n");
    scanf("%i", &resposta);
  }
  //entra na prioridade fase 1
  if(resposta==1 || p->idade>=75){
    p->prioridade=1;
  }
  //entra na prioridade fase 2
  else if(p->idade>60 && p->idade<75){
    p->prioridade=2;
  }
  //entra na prioridade fase 3
  else{
    resposta=0;
    while(resposta!=1 && resposta!=2){
      printf(" Você possui comorbidades? \n Digite: \n 1 - Sim \n 2 - Não \n");
      scanf("%i", &resposta);
    }
    if(resposta==1){
      p->prioridade=3;
    }
    //entra na prioridade fase 4
    else{
      resposta=0;
      while(resposta!=1 && resposta!=2){
        printf(" Você é morador de rua, quilombola, possui deficiência, pessoa privada de liberdade ou trabalha em algum serviço considerado essencial? \nServiços Essenciais:\n- Professores\n- Forças de segurança\n- Funcionários  do Sistema prisional  \n Digite: \n 1 - Sim \n 2 - Não \n");
        scanf("%i", &resposta);
      }
      if(resposta==1){
        p->prioridade=4;
      }
      else{
        p->prioridade=5;
      }
    }
  }
}



int main(void) {

  //Declaração da fila
  Fila fila1;
  //Inicialização da nova fila
  new_fila(&fila1);

  char n[100];
  int op = 0;

  //Onde vai caber e imprimir cada fase prioritaria
  do{


    op = menu();

    switch(op){

      //Enfileirar uma pessoa
      case 1:
      {
        Pessoa p;
        perguntas(&p);
        enqueue(&fila1, p);
      }
      break;

      //Desenfileirar uma pessoa
      case 2:
      {
          Pessoa p = dequeue(&fila1);
          if(p.idade==-1){
            printf("\n Fila vazia ");
          } 
          printf("\nPessoa removida: ");
          print_pessoa(p);
      }
              
      break;

      //Imprimir fila geral
      case 3:
        print_fila(&fila1);
      break;
      //Imprimir fila fase 1
      case 4: 
        print_fila_especifica(&fila1,1);
      break;
      //Imprimir fila fase 2
      case 5: 
        print_fila_especifica(&fila1,2);
      break;
      //Imprimir fila 3
      case 6: 
        print_fila_especifica(&fila1,3);
      break;
      //Imprimir fila fase 4
      case 7: 
        print_fila_especifica(&fila1,4);
      break;
      //Imprimir fila fase 5
      case 8: 
        print_fila_especifica(&fila1,5);
      break;
      case 9:
        
        printf("Informe o nome \n");
        scanf("%s", n);
        print_posfila(&fila1, n);
      break;

    }

  }while(op != 0);

  return 0;
}