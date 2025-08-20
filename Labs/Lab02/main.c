#include "raiz.h"
#include <math.h>
#include <stdio.h>

#define PI 3.1415926535897932384626433832795

// exemplo para contagem de avaliacoes da funcao
// defina N=0 antes de chamar o metodo da bissecao
int N;
static double f1(double x) {
  N++;
  return x * x * x + 2 * x * x - 2;
}

static double f2(double x) {
  N++;
  return x * x * x * x + x + 1;
}

static double f3(double m) {
  N++;
  double g = 9.8;  // aceleração da gravidade (m/s^2)
  double c = 15.0; // coeficiente de arrasto (Kg/s)
  double t = 9.0;  // tempo (s)
  double v = 35.0; // velocidade desejada (m/s)

  return (g * m / c) * (1 - exp(-c * t / m)) - v;
}

void testa_bissecao(const char *descricao, double a, double b,
                    double (*f)(double x)) {
  double c;
  int it;

  N = 0;
  printf(">>> %s de %.0f a %.0f: ", descricao, a, b);
  it = bissecao(a, b, f, &c);
  if (it == -1)
    printf("função não convergiu ");
  else
    printf("c: %.9f ", c);
  printf("it: %d av: %d\n", it, N);
}

int main(void) {
  // adicione aqui os seus testes...
  double c;
  int it;

  printf("it: iteracoes da bissecao, av: avaliacoes de f(x)\n");

  testa_bissecao("Q1", -3.0, 3.0, f1);
  testa_bissecao("Q2", -3.0, 3.0, f2);
  testa_bissecao("Q1", -5.0, 5.0, f1);
  testa_bissecao("Q3", 0.0, 150.0, f3);
  testa_bissecao("Q3", 0.0, 250.0, f3);
  testa_bissecao("Q3", 0.0, 50.0, f3);
  return 0;
}
