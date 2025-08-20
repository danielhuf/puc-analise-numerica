#include "metiter.h"
#include "matriz.h"
#include "vetor.h"
#include <math.h>
#include <stdlib.h>

int gaussseidel(int n, double **A, double *b, double *x, double tol) {
  double *r = vet_cria(n);
  int iter = 0;
  double norma_2_residuo = 2 * tol;

  while (norma_2_residuo > tol) {
    for (int i = 0; i < n; ++i) {
      double soma = 0.0;
      for (int j = 0; j < n; ++j) {
        if (j != i)
          soma += A[i][j] * x[j];
      }
      x[i] = (b[i] - soma) / A[i][i];
    }

    mat_multv(n, n, A, x, r);
    for (int i = 0; i < n; ++i)
      r[i] = b[i] - r[i];

    norma_2_residuo = vet_norma2(n, r);
    iter++;
  }

  vet_libera(r);
  return iter;
}

int sor_gaussseidel(int n, double **A, double *b, double *x, double tol,
                    double w) {
  double *r = vet_cria(n);
  int iter = 0;
  double norma_2_residuo = 2 * tol;

  while (norma_2_residuo > tol) {
    for (int i = 0; i < n; ++i) {
      double soma = 0.0;
      for (int j = 0; j < n; ++j) {
        if (j != i)
          soma += A[i][j] * x[j];
      }

      double x_novo = (b[i] - soma) / A[i][i];
      x[i] = (1.0 - w) * x[i] + w * x_novo;
    }

    mat_multv(n, n, A, x, r);
    for (int i = 0; i < n; ++i)
      r[i] = b[i] - r[i];

    norma_2_residuo = vet_norma2(n, r);
    iter++;
  }

  vet_libera(r);
  return iter;
}