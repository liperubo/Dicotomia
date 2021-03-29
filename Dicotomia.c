// ------------------------- Cabeçalho --------------------------- //
/*Projeto Dicotomia - Métodos Númericos

Integrantes:
Felipe Eler de Oliveira Machado 200738
Felipe Victorino Sarubo 200574

Turma: CP004TIM2*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ------------------------- Estruturas --------------------------- //

typedef struct Dicotomia
{
	float A;
  float B;
  float M;
  float fa;
  float fb;
  float fm;
} Dicotomia;

// ------------------------- Protótipos de Funções ---------------- //

void alocaDicotomia(Dicotomia **p, int tam);
void alocaInt(int **p, int m);
void recebeDados(Dicotomia *p);
float substitui(int *p, int exp, float V);

// ------------------------- Main --------------------------------- //

int main()
{
  int *pFunc= NULL;
  Dicotomia *pDico = NULL;
  alocaInt(&pFunc, 10);
  alocaDicotomia(&pDico, 2);

  int exp = 0, k = 0;
  float E = 0.00f;
  int i;

  //func representa a função que queremos as raizes, ela recebe o valor que acompanha até 9 expoentes e um independente
  //onde o indice 0 é independente, indice 1 é x, indice 2 é x^2 e assim por diante.
  //receber "6 0 -3 5" significa "6x^3 - 3x + 5"

  // Receber a Func (Função):
  //   Receber o maior Exp (Expoente)
  printf("\nDigite o maior expoente: ");
  scanf("%i",&exp);
  fflush(stdin);

  //   Loop (For):
  //     Receber os Coeficientes em ordem decrescente
  for (i = exp; i >= 0; i--)
  {
    if (i == 0){printf("Digite o valor independente: ");}
    else if (i == 1){printf("Digite o valor que acompanha x: ");}
    else{printf("Digite o valor que acompanha x^%i: ", i);}
    
    scanf("%i",(pFunc + i));
    fflush(stdin);
  }

  // Receber A e B (Limites)
  printf("Digite primeiro o limite (A): ");
  scanf("%f", &((pDico+k)->A));
  fflush(stdin);

  printf("Digite segundo o limite (B): ");
  scanf("%f", &((pDico+k)->B));
  fflush(stdin);

  // Receber E (Erro)
  printf("Digite o erro (E): ");
  scanf("%f", &E);
  fflush(stdin);
  
  printf("i\tA\tM\tB\tfA\tfM\tfB");
  // Loop (While):
  do
  {
    //   Calcular M (média de A e B)
    (pDico+k)->M = ((pDico+k)->A + (pDico+k)->B)/2;

    //   Substituir A, M, B na função
    (pDico+k)->fa = substitui(pFunc, exp, (pDico+k)->A);
    (pDico+k)->fb = substitui(pFunc, exp, (pDico+k)->B);
    (pDico+k)->fm = substitui(pFunc, exp, (pDico+k)->M);

    alocaDicotomia(&pDico, k+2);

    //   Decisão: 
    //     Se((F(A[i]) < 0 && F(M[i]) > 0) || (F(A[i]) > 0 && F(M[i]) < 0)): B[i+1] = M[i]
    //     Se((F(B[i]) < 0 && F(M[i]) > 0) || (F(B[i]) > 0 && F(M[i]) < 0)): A[i+1] = M[i]
    if((pDico+k)->fm * (pDico+k)->fa < 0){
      (pDico+k+1)->A = (pDico+k)->A;
      (pDico+k+1)->B = (pDico+k)->M;
    }else if((pDico+k)->fm * (pDico+k)->fb < 0){
      (pDico+k+1)->A = (pDico+k)->M;
      (pDico+k+1)->B = (pDico+k)->B;
    }

    printf("\n%i\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t", k, (pDico+k)->A, (pDico+k)->M, (pDico+k)->B, (pDico+k)->fa, (pDico+k)->fm, (pDico+k)->fb);
    k++;
    //   Até que F(M[i]) <= E
  } while (fabs((pDico+k-1)->fm) >= E);
  
  // "O zero real da função é M[i], com erro de aproximadamente +/- F(M[i])"
  printf("\nO zero real da funcao \x82 %.3f, com erro de aproximadamente +/- %.3f\n", (pDico+k-1)->M, (pDico+k-1)->fm);
  return 0;
}

// ------------------------- Funções ------------------------------ //

void alocaDicotomia(Dicotomia **p, int m)
{
	if ((*p = (Dicotomia *)realloc(*p, m * sizeof(Dicotomia))) == NULL)
	{
		printf("\nErro na alocacao. O programa sera encerrado!");
		exit(1);
	}
}

void alocaInt(int **p, int m){
  if((*p = (int*)realloc(*p, m * sizeof(int))) == NULL)
  {
    printf("\nErro na alocacao. O programa sera encerrado!");
		exit(1);
  }
}

float substitui(int *p, int exp, float V){
  int i = 0.0f;
  float result = 0.0f;
  for (i = exp; i >= 0; i--)
  {
    result += *(p + i) * powf(V, i);
  }
  return result;
}

// ------------------------- To Do List --------------------------- //
/*
Processamento:
  Receber a Func (Função):
    Receber o maior Exp (Expoente)
    Loop (For):
      Receber os Coeficientes em ordem decrescente
  Receber A e B (Limites)
  Receber E (Erro)
  Loop (While):
    Calcular M (média de A e B)
    Substituir A, M, B na função
    Decisão: 
      Se((F(A[i]) < 0 && F(M[i]) > 0) || (F(A[i]) > 0 && F(M[i]) < 0)): B[i+1] = M[i]
      Se((F(B[i]) < 0 && F(M[i]) > 0) || (F(B[i]) > 0 && F(M[i]) < 0)): A[i+1] = M[i]
    Até que F(M[i]) <= E
  "O zero real da função é M[i], com erro de aproximadamente +/- F(M[i])"
*/
