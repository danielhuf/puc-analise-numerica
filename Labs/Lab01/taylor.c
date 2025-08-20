#include "taylor.h"
#include <stdlib.h>

double avalia_taylor(int n, double *c, double x0, double x) {
  double result = 0.0;
  double termo = 1.0; // O primeiro termo é (x - x0)^0 = 1
  double fat = 1.0;   // O fatorial de 0 é 1

  for (int i = 0; i < n; i++) {
    result += (c[i] / fat) * termo;
    termo *= (x - x0);
    fat *= (i + 1);
  }

  return result;
}

double avalia_seno(int n, double x) {
  double coef[n];

  // Geração dinâmica dos coeficientes do polinômio de Taylor para sen(x)
  // Para i = 0, 2, 4, ... -> coef[i] = 0.0
  // Para i = 1, 5, 9, ... -> coef[i] = 1.0
  // Para i = 3, 7, 11, ... -> coef[i] = -1.0
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      coef[i] = 0.0;
    } else {
      coef[i] = (i % 4 == 1) ? 1.0 : -1.0;
    }
  }

  return avalia_taylor(n, coef, 0.0, x);
}