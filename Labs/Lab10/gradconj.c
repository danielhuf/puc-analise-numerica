#include "matriz.h"
#include "vetor.h"
#include <math.h>
#include <stdlib.h>

int gradconj(int n, double **A, double *b, double *x, double tol) {
  int k;
  double *r = vet_cria(n);
  double *d = vet_cria(n);
  double *Ad = vet_cria(n);
  double *Ax = vet_cria(n);

  mat_multv(n, n, A, x, Ax);
  for (int i = 0; i < n; ++i) {
    r[i] = b[i] - Ax[i];
    d[i] = r[i];
  }

  for (k = 0; k < n; ++k) {
    double norma_r = vet_norma2(n, r);
    if (norma_r < tol)
      break;

    mat_multv(n, n, A, d, Ad);

    double rTr = vet_escalar(n, r, r);
    double dTAd = vet_escalar(n, d, Ad);
    double alpha = rTr / dTAd;

    for (int i = 0; i < n; ++i) {
      x[i] += alpha * d[i];
      r[i] -= alpha * Ad[i];
    }

    double rTr_novo = vet_escalar(n, r, r);
    double beta = rTr_novo / rTr;

    for (int i = 0; i < n; ++i)
      d[i] = r[i] + beta * d[i];
  }

  vet_libera(r);
  vet_libera(d);
  vet_libera(Ad);
  vet_libera(Ax);

  return k;
}

int gradconj_jacobi(int n, double **A, double *b, double *x, double tol) {
  int k;
  double *r = vet_cria(n);
  double *z = vet_cria(n);
  double *d = vet_cria(n);
  double *Ad = vet_cria(n);
  double *Ax = vet_cria(n);

  mat_multv(n, n, A, x, Ax);
  for (int i = 0; i < n; ++i) {
    r[i] = b[i] - Ax[i];
    z[i] = r[i] / A[i][i];
    d[i] = z[i];
  }

  for (k = 0; k < n; ++k) {
    double norma_r = vet_norma2(n, r);
    if (norma_r < tol)
      break;

    mat_multv(n, n, A, d, Ad);

    double rTz = vet_escalar(n, r, z);
    double dTAd = vet_escalar(n, d, Ad);
    double alpha = rTz / dTAd;

    for (int i = 0; i < n; ++i) {
      x[i] += alpha * d[i];
      r[i] -= alpha * Ad[i];
    }

    double *z_novo = vet_cria(n);
    for (int i = 0; i < n; ++i)
      z_novo[i] = r[i] / A[i][i];

    double rTz_novo = vet_escalar(n, r, z_novo);
    double beta = rTz_novo / rTz;

    for (int i = 0; i < n; ++i) {
      d[i] = z_novo[i] + beta * d[i];
      z[i] = z_novo[i];
    }

    vet_libera(z_novo);
  }

  vet_libera(r);
  vet_libera(z);
  vet_libera(d);
  vet_libera(Ad);
  vet_libera(Ax);

  return k;
}
