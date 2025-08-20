#include "otimizacao.h"
#include <math.h>
#include <stdio.h>

int msa(double a, double b, double (*f)(double x), double tol, double *xmin) {
  double g = (sqrt(5.0) - 1.0) / 2.0;
  int max_iter = 50;
  int iter = 0;
  double x1 = a + (1 - g) * (b - a);
  double x2 = a + g * (b - a);
  double fx1 = f(x1);
  double fx2 = f(x2);

  while ((b - a) / 2.0 > tol && iter < max_iter) {
    iter++;
    if (fx1 <= fx2) {
      b = x2;
      x2 = x1;
      fx2 = fx1;
      x1 = a + (1 - g) * (b - a);
      fx1 = f(x1);
    } else {
      a = x1;
      x1 = x2;
      fx1 = fx2;
      x2 = a + g * (b - a);
      fx2 = f(x2);
    }
  }

  *xmin = (a + b) / 2.0;
  return iter;
}

int mips(double r, double delta, double (*f)(double x), double tol,
         double *xmin) {
  double tol_denominador = 1e-10;
  int max_iter = 50;
  int iter = 0;
  double s = r - delta;
  double t = r + delta;
  double fr = f(r);
  double fs = f(s);
  double ft = f(t);

  while (iter < max_iter) {
    iter++;

    double numerador = (fs - fr) * (t - r) * (t - s);
    double denominador = 2.0 * ((s - r) * (ft - fs) - (fs - fr) * (t - s));

    double x;
    if (fabs(denominador) < tol_denominador) {
      x = (r + s + t) / 3.0;
    } else {
      x = ((r + s) / 2.0) - numerador / denominador;
    }

    r = s;
    fr = fs;
    s = t;
    fs = ft;
    t = x;
    ft = f(x);

    if (iter > 3 && fabs(fs - ft) <= tol) {
      *xmin = (s + t) / 2.0;
      return iter;
    }
  }

  return 0;
}