
# **Participantes**: 

- **Abraão Melo Fagundes**
- **Gabriel França de Oliveira**
- **Milleny Teixeira de Souza**

Este Projeto foi desenvolvido para a disciplina **Algoritimos e Estrututras de Dados II**, lecionada pelo professor **Kleber Jacques Ferreira De Souza** no curso de **Engenharia de Computação da PUC-Minas**.

# **Introdução** 


O intuito do trabalho foi o desenvolvimento de um **sistema de fila de vacinação contra a COVID-19**. 

O sistema irá interagir com o usuário através de um menu, e, após a resposta de algumas perguntas,  ordená-lo em relação a sua prioridade na fila de vacinação contra a COVID-19. 

A classificação de cada fase foi realizada baseando na imagem abaixo:

![Classificação_Fila_de_Vacinação](/Fila_de_Vacinacao.png)



# **Desenvolvimento**

O codigo foi desenvolvido em **C**, utilizando a TAD **Fila de Prioridade Dinâmica**. 

A estrutura considerada foi a seguinte: 

```c
typedef struct Pessoa{
  char nome[100];
  int idade;
  int prioridade;
}Pessoa;
```

Métodos criados:
```c
void print_pessoa(Pessoa p){}
void new_fila(Fila *f){}
void enqueue(Fila *f, Pessoa dado){}
void dequeue(Fila *f){}
void print_fila(Fila *f){}
void print_fila_especifica(Fila *f, int p){}
void print_posfila(Fila *f, char nome){}

```

Os critérios para encaixe nas respectivas filas de vacinação seguiram a proposta do **Professor**, e, também os critérios seguidos pelo **Ministério da Saúde**, que pode ser consultado acima na sessão de **Introdução**.

O sistema foi implementado utilizando **Fila dinâmica**, por orientação do Professor, foi desenvolvido também utilizando **Fila estática**, que pode ser acessado pelo **link**: https://github.com/GabrielFOliveira/AED2-Fila_de_Vacinacao-Fila_com_Vetor

A necessidade da utilização da estrutura de Fila com Prioridade vem pela observação da necessidade de inserir os elementos(struct Pessoa) dentro da estrutura de forma ordenada.

Os testes feitos no trabalho se resumiram primeiramente numa lógica diferente da proposta, fazendo uma prioridade com a criação de 5 filas. No entanto, percebemos então que seria mais efetivo criamos um metodo de enfileirar com prioridade. Este método traz uma implementação em uma fila apenas e não repete a complexidade, tornando-o mais rápido.

# **Fila estática** vs **Fila dinâmica** 

Com a necessidade de implementação de duas estruturas diferentes, o método de inserção na fila com prioridade também muda. 

Na **fila dinâmica**, a implementação foi necessária a manipulação de ponteiros, e a inserção se deu através de um laço que percorre a estrutura, comparando as prioridades até que encontre um próximo elemento de maior prioridade e o insira no local apropriado.

Já na **fila estática**, por se tratar de vetor, é necessário além de encontrar a posição correta, também é necessário fazer o deslocamento de todos os outros elementos. 

# **Conclusão** 

A implementação do sistema envolveu a resolução da mesma problemática da mesma maneira. Assim, é possível praticar os conceitos e aprimorar a lógica, além de ampliar os horizontes no que tange a utilização de TADs.

Além disso, exercitamos também a análise de melhor implementação e performance, ao lidar com um embate real de trocar a utilização de cinco estruturas e trocar para apenas uma, mais otimizada. A comparação entre os códigos do sistema com arranjos e ponteiros fica claro da efetividade estática e dinâmica.


