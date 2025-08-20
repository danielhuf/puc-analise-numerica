#include "taylor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

int main(void) {
  double valores_x[] = {PI / 12.0, PI / 9.0, PI / 7.0, PI / 4.0, PI / 3.0};
  const char *nomes_x[] = {"PI/12.0", "PI/9.0", "PI/7.0", "PI/4.0", "PI/3.0"};
  int valores_termos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printf("Seno:\n");
  // Avaliação das aproximações
  for (int i = 0; i < 5; i++) {
    double x = valores_x[i];
    double sin_real = sin(x);

    printf("Test: x:%.10f (%s) esperado: %.10f\n", x, nomes_x[i], sin_real);

    for (int j = 0; j < 10; j++) {
      int n_termos = valores_termos[j];
      double aprox = avalia_seno(n_termos, x);
      double erro = sin_real - aprox;

      printf("%d termo(s) - f(x): %.10f diff: %.10f\n", n_termos, aprox, erro);

      // Calculo do residuo máximo usando o Teorema de Taylor
      // Residuo <= (f[k+1](c) * (x - x0)^(k+1)) / (k+1)!
      // Para sen(x), a n-ésima derivada tem valor máximo 1
      // Como x0 = 0, o residuo máximo é <= x^(k+1) / (k+1)!
      double termo = pow(x, n_termos); // Não usei n_termos + 1 pois
                                       // valores_termos começa em 1, não em 0
      double fat = 1.0;
      for (int k = 1; k <= n_termos;
           k++) { // Não usei n_termos + 1 pois
                  // valores_termos começa em 1, não em 0
        fat *= k;
      }
      double residuo_max = termo / fat;

      printf("Resíduo máximo pelo Teorema de Taylor: %12.10e\n", residuo_max);

      if (erro <= residuo_max) {
        printf("✓ Erro dentro do limite previsto pelo teorema\n");
      } else {
        printf("✗ Erro excede o limite previsto pelo teorema\n");
      }
      printf("------------------------------------------\n");
    }
    printf("\n");
  }

  printf("--------------- FIM DOS TESTES ---------------\n");
  return 0;
}
