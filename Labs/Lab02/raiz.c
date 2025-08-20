#include "raiz.h"
#include <math.h>

int bissecao(double a, double b, double (*f)(double x), double *r) {
  double c;
  double emax = 0.5e-8;
  int iter = 0;
  double fa = f(a);
  double fb = f(b);

  // Verifica se há mudança de sinal no intervalo inicial
  if (fa * fb >= 0.0)
    return -1;

  while ((b - a) / 2.0 > emax) {
    // Calcula o ponto médio do intervalo
    c = (a + b) / 2.0;
    double fc = f(c);
    iter++;

    // Interrompe se |f(c)| < 10^-12
    if (fabs(fc) < 1e-12) {
      *r = c;
      return iter;
    }

    // Verifica em qual subintervalo está a raíz
    if (fa * fc < 0.0) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }
  }

  // Calcula o ponto médio do último intervalo e atribui à raiz
  c = (a + b) / 2.0;
  *r = c;

  return iter;
}