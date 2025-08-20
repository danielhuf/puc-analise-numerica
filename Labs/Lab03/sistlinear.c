#include "sistlinear.h"
#include <math.h>
#include <stdlib.h>

void gauss(int n, double **a, double *b, double *x) {
  for (int j = 0; j < n - 1; ++j) {
    // Algoritmo de pivoteamento
    int p = j;
    for (int k = j + 1; k < n; ++k) {
      if (fabs(a[k][j]) > fabs(a[p][j]))
        p = k;
    }
    for (int k = j; k < n; ++k) {
      double tmp = a[p][k];
      a[p][k] = a[j][k];
      a[j][k] = tmp;
    }
    double tmp = b[p];
    b[p] = b[j];
    b[j] = tmp;

    // Algoritmo de eliminacao de Gauss
    for (int i = j + 1; i < n; ++i) {
      double f = a[i][j] / a[j][j];
      for (int k = j; k < n; ++k)
        a[i][k] -= f * a[j][k];
      b[i] -= b[j] * f;
    }
  }

  // Algoritmo de retro-substituicao
  for (int i = n - 1; i >= 0; --i) {
    double s = 0;
    for (int j = i + 1; j < n; ++j)
      s += a[i][j] * x[j];
    x[i] = (b[i] - s) / a[i][i];
  }
}