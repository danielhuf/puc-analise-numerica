#include "matriz.h"
#include "sistlinear.h"
#include "vetor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double mmq(int m, int n, double **A, double *b, double *x) {
  double **At = mat_cria(n, m);
  mat_transposta(m, n, A, At);

  double **AtA = mat_cria(n, n);
  mat_multm(n, m, n, At, A, AtA);

  double *Atb = vet_cria(n);
  mat_multv(n, m, At, b, Atb);

  gauss(n, AtA, Atb, x);

  double *Ax = vet_cria(m);
  mat_multv(m, n, A, x, Ax);

  double *r = vet_cria(m);
  for (int i = 0; i < m; ++i)
    r[i] = b[i] - Ax[i];

  double erro = vet_norma2(m, r);

  mat_libera(n, At);
  mat_libera(n, AtA);
  vet_libera(Atb);
  vet_libera(Ax);
  vet_libera(r);

  return erro;
}

double ajuste_parabola(int n, double *px, double *py, double *a, double *b,
                       double *c) {
  int cols = 3;
  double **A = mat_cria(n, cols);

  for (int i = 0; i < n; ++i) {
    A[i][0] = 1.0;
    A[i][1] = px[i];
    A[i][2] = px[i] * px[i];
  }

  double *coef = vet_cria(cols);
  double erro = mmq(n, cols, A, py, coef);

  *a = coef[0];
  *b = coef[1];
  *c = coef[2];

  mat_libera(n, A);
  vet_libera(coef);

  return erro;
}

double ajuste_cubica(int n, double *px, double *py, double *a, double *b,
                     double *c, double *d) {
  int cols = 4;
  double **A = mat_cria(n, cols);

  for (int i = 0; i < n; ++i) {
    A[i][0] = 1.0;
    A[i][1] = px[i];
    A[i][2] = px[i] * px[i];
    A[i][3] = px[i] * px[i] * px[i];
  }

  double *coef = vet_cria(cols);
  double erro = mmq(n, cols, A, py, coef);

  *a = coef[0];
  *b = coef[1];
  *c = coef[2];
  *d = coef[3];

  mat_libera(n, A);
  vet_libera(coef);

  return erro;
}

double ajuste_exponencial_exp(int n, double *px, double *py, double *a,
                              double *b) {
  int cols = 2;
  double **A = mat_cria(n, cols);
  double *ln_y = vet_cria(n);

  for (int i = 0; i < n; ++i) {
    if (py[i] <= 0) {
      printf("Erro: py[%d] <= 0\n", i);
      exit(1);
    }
    A[i][0] = 1.0;
    A[i][1] = px[i];
    ln_y[i] = log(py[i]);
  }

  double *coef = vet_cria(cols);
  double erro = mmq(n, cols, A, ln_y, coef);

  *a = exp(coef[0]);
  *b = coef[1];

  mat_libera(n, A);
  vet_libera(ln_y);
  vet_libera(coef);

  return erro;
}