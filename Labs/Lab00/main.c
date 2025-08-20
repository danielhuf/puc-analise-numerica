#include "vetor.h"
#include "matriz.h"
#include <stdio.h>

int main (void)
{
  printf("\n=== VETOR ===\n");
  /* Exemplo de construção de vetor dinâmico */
  double* v = vet_cria(2);
  v[0] = 1.0;
  v[1] = 2.0;

  /* Exemplo de construção de vetor estático */
  double w[] = {1.0,2.0f};

  /* Imprime vetores (são iguais em conteúdo) */
  printf("\nVetor v: ");
  vet_imprime(2,v);
  printf("\nVetor w: ");
  vet_imprime(2,w);

  /* Teste de produto escalar */
  double escalar = vet_escalar(2, v, w);
  printf("\nProduto escalar de v e w: %.2f\n", escalar);

  /* Teste de multiplicação por escalar */
  double* resultado = vet_cria(2);
  vet_mults(2, v, 3.0, resultado);
  printf("\nv multiplicado por 3: ");
  vet_imprime(2, resultado);

  /* Teste de norma */
  double norma = vet_norma2(2, v);
  printf("\nNorma-2 de v: %.2f\n", norma);

  /* Teste de igualdade de vetores */
  int iguais = vet_iguais(2, v, w, 0.001);
  printf("\nVetores v e w são iguais? %s\n", iguais ? "Sim" : "Não");

  printf("\n=== MATRIZ ===\n");
  /* Exemplo de construção de matriz dinâmica */
  double** A = mat_cria(3,2);
  A[0][0] = 1.0;
  A[0][1] = 2.0;
  A[1][0] = 3.0;
  A[1][1] = 4.0;
  A[2][0] = 5.0;
  A[2][1] = 6.0;

  /* Exemplo de construção de matriz estática no formato ponteiro para ponteiro */
  double linha1[] = {1.0,2.0};
  double linha2[] = {3.0,4.0};
  double linha3[] = {5.0,6.0};
  double* B[] = {linha1,linha2,linha3};

  /* Imprime matrizes (são iguais em conteúdo) */
  printf("\nMatriz A:\n");
  mat_imprime(3,2,A);
  printf("\nMatriz B:\n");
  mat_imprime(3,2,B);

  /* Teste de matriz transposta */
  double** T = mat_cria(2, 3);
  mat_transposta(3, 2, A, T);
  printf("\nTransposta da matriz A:\n");
  mat_imprime(2, 3, T);

  /* Teste de multiplicação matriz-vetor */
  double* prod_mv = vet_cria(3);
  mat_multv(3, 2, A, v, prod_mv);
  printf("\nA * v = ");
  vet_imprime(3, prod_mv);

  /* Teste de multiplicação matriz-matriz */
  double** C = mat_cria(2, 2);
  C[0][0] = 1.0; C[0][1] = 2.0;
  C[1][0] = 3.0; C[1][1] = 4.0;
  printf("\nMatriz C:\n");
  mat_imprime(2, 2, C);

  double** resultado_mm = mat_cria(3, 2);
  
  /* Multiplicação de B por C */
  mat_multm(3, 2, 2, B, C, resultado_mm);
  printf("\nB * C = \n");
  mat_imprime(3, 2, resultado_mm);

  /* Apenas objetos dinâmicos podem ser liberados */
  vet_libera(v);
  vet_libera(resultado);
  vet_libera(prod_mv);
  mat_libera(3, A);
  mat_libera(2, T);
  mat_libera(2, C);
  mat_libera(3, resultado_mm);

  return 0; 
} 