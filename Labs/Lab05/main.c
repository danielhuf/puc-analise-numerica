#include "matriz.h"
#include "mmq.h"
#include "vetor.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

int main(void) {
  {
    int m = 5, n = 3;
    double **A = mat_cria(m, n);
    A[0][0] = 3;
    A[0][1] = -1;
    A[0][2] = 2;
    A[1][0] = 4;
    A[1][1] = 1;
    A[1][2] = 0;
    A[2][0] = -3;
    A[2][1] = 2;
    A[2][2] = 1;
    A[3][0] = 1;
    A[3][1] = 1;
    A[3][2] = 5;
    A[4][0] = -2;
    A[4][1] = 0;
    A[4][2] = 3;
    double b[] = {10, 10, -5, 15, 0};
    double x[n];

    // TODO: chamar método mmq
    printf("solucao:\n");
    double erro = mmq(m, n, A, b, x);
    vet_imprime(n, x, "x");
    double *Ax = vet_cria(m);
    mat_multv(m, n, A, x, Ax);
    printf("Ax:\n");
    vet_imprime(m, Ax, "Ax");
    printf("Erro: %.6g\n", erro);
    mat_libera(m, A);
    vet_libera(Ax);
  }
  printf("-------------------------\n");
  {
    int m = 5, n = 4;
    double **A = mat_cria(m, n);
    A[0][0] = 4;
    A[0][1] = 2;
    A[0][2] = 3;
    A[0][3] = 0;
    A[1][0] = -2;
    A[1][1] = 3;
    A[1][2] = -1;
    A[1][3] = 1;
    A[2][0] = 1;
    A[2][1] = 3;
    A[2][2] = -4;
    A[2][3] = 2;
    A[3][0] = 1;
    A[3][1] = 0;
    A[3][2] = 1;
    A[3][3] = -1;
    A[4][0] = 3;
    A[4][1] = 1;
    A[4][2] = 3;
    A[4][3] = -2;
    double b[] = {10, 0, 2, 0, 5};
    double x[n];

    // TODO: chamar método mmq
    printf("solucao:\n");
    double erro = mmq(m, n, A, b, x);
    vet_imprime(n, x, "x");
    double *Ax = vet_cria(m);
    mat_multv(m, n, A, x, Ax);
    printf("Ax:\n");
    vet_imprime(m, Ax, "Ax");
    printf("Erro: %.6g\n", erro);
    mat_libera(m, A);
    vet_libera(Ax);
  }
  printf("-------------------------\n");
  {
    double px[] = {-1, 0, 1, 2};
    double py[] = {1, 0, 0, -2};
    double a, b, c, d;

    // TODO: chamar ajuste de parabola
    printf("parabola:\n");
    double erro = ajuste_parabola(4, px, py, &a, &b, &c);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g\n", a, b, c);

    // TODO: chamar ajuste de cubica
    printf("cubica:\n");
    erro = ajuste_cubica(4, px, py, &a, &b, &c, &d);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g d = %.6g\n", a, b, c, d);
  }
  printf("-------------------------\n");
  {
    double px[] = {0, 1, 2, 5};
    double py[] = {0, 3, 3, 6};
    double a, b, c, d;

    // TODO: chamar ajuste de parabola
    printf("parabola:\n");
    double erro = ajuste_parabola(4, px, py, &a, &b, &c);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g\n", a, b, c);

    // TODO: chamar ajuste de cubica
    printf("cubica:\n");
    erro = ajuste_cubica(4, px, py, &a, &b, &c, &d);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g d = %.6g\n", a, b, c, d);
  }
  printf("-------------------------\n");
  {
    double px[] = {1, 3, 4, 6};
    double py[] = {2, 2, 1, 3};
    double a, b, c, d;

    // TODO: chamar ajuste de parabola
    printf("parabola:\n");
    double erro = ajuste_parabola(4, px, py, &a, &b, &c);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g\n", a, b, c);

    // TODO: chamar ajuste de cubica
    printf("cubica:\n");
    erro = ajuste_cubica(4, px, py, &a, &b, &c, &d);
    printf("Erro: %.6g\n", erro);
    printf("a = %.6g b = %.6g c = %.6g d = %.6g\n", a, b, c, d);
  }
  printf("-------------------------\n");
  {
    double px[] = {1950, 1955, 1960, 1965, 1970, 1975, 1980};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b;

    // TODO: chamar ajuste exponencial
    printf("exponencial:\n");
    double erro = ajuste_exponencial_exp(7, px, py, &a, &b);
    printf("Erroln: %.6g\n", erro);
    printf("a = %.6g b = %.6g\n", a, b);
  }
  printf("-------------------------\n");
  {
    double px[] = {0, 5, 10, 15, 20, 25, 30};
    double py[] = {53.05, 73.04, 98.31, 139.78, 193.48, 260.20, 320.39};
    double a, b;

    // TODO: chamar ajuste exponencial
    printf("exponencial:\n");
    double erro = ajuste_exponencial_exp(7, px, py, &a, &b);
    printf("Erroln: %.6g\n", erro);
    printf("a = %.6g b = %.6g\n", a, b);
  }

  return 0;
}
