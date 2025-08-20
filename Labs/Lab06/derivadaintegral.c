#include "derivadaintegral.h"
#include <math.h>
#include <stdio.h>

double derivada(double (*f)(double x), double x, double h) {
  return (f(x + h) - f(x - h)) / (2 * h);
}

double simpson(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;
  double soma = 0.0;
  double a_temp = a;

  for (int i = 0; i < n; i++) {
    soma += (h / 6.0) * (f(a_temp) + 4 * f(a_temp + h / 2.0) + f(a_temp + h));
    a_temp += h;
  }

  return soma;
}

double simpsonadaptativo(double (*f)(double), double a, double b, double tol) {
  double c = (a + b) / 2.0;

  double s_ab = simpson(f, a, b, 1);
  double s_ac = simpson(f, a, c, 1);
  double s_cb = simpson(f, c, b, 1);

  double delta = s_ab - (s_ac + s_cb);

  if (fabs(delta) > 15.0 * tol) {
    return simpsonadaptativo(f, a, c, tol / 2.0) +
           simpsonadaptativo(f, c, b, tol / 2.0);
  } else {
    return s_ac + s_cb - delta / 15.0;
  }
}