#include "interp.h"
#include <math.h>
#include <stdio.h>

#define PI 3.141592653589793

void regular(int n, double a, double b, double *xi) {
  double intervalo = (b - a) / (n - 1);
  for (int i = 0; i < n; i++)
    xi[i] = a + i * intervalo;
}

void chebyshev(int n, double a, double b, double *xi) {
  for (int i = 0; i < n; i++) {
    int beta = 2 * i + 1;
    xi[i] = ((b - a) / 2) * cos((beta * PI) / (2 * n)) + ((a + b) / 2);
  }
}

static double diferenca_dividida(int i, int j, double *xi,
                                 double (*f)(double)) {
  if (i == j)
    return f(xi[i]);
  else
    return (diferenca_dividida(i + 1, j, xi, f) -
            diferenca_dividida(i, j - 1, xi, f)) /
           (xi[j] - xi[i]);
}

void coeficientes(int n, double *xi, double (*f)(double), double *bi) {
  for (int i = 0; i < n; i++) {
    bi[i] = diferenca_dividida(0, i, xi, f);
  }
}

double avalia(int n, double *xi, double *bi, double x) {
  double result = bi[0];
  double termo = 1.0;

  for (int i = 1; i < n; i++) {
    termo *= (x - xi[i - 1]);
    result += bi[i] * termo;
  }

  return result;
}