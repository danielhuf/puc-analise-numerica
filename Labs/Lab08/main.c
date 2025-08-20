#include "massamola.h"
#include <stdio.h>

void testaforca(double t, double x, double y) {
  double fx, fy;
  forca(t, x, y, &fx, &fy);                // TODO: chamar funcao 'forca'
  printf("[fx, fy]: %.6f %.6f\n", fx, fy); // TODO: imprimir forca fx e fy
}

void testaevolui(double t, double h, double x1, double y1, double x0,
                 double y0) {
  double x2, y2;
  double th =
      evolui(t, h, x1, y1, x0, y0, &x2, &y2); // TODO: chamar funcao 'evolui'
  printf("[x, y]: %.6f %.6f (%.6f)\n", x2, y2,
         th); // TODO: imprimir resultado de evolui
}

int main(void) {
  testaforca(0.0, 300.0, 0.0);
  testaforca(1.0, 200.0, 0.0);
  testaforca(2.0, 100.0, 0.0);
  testaforca(3.0, 300.0, 100.0);
  testaforca(4.0, 200.0, 100.0);
  testaforca(5.0, 100.0, 100.0);

  testaevolui(0.0, 0.2, 300.0, 0.0, 300.0, 0.0);
  testaevolui(1.0, 0.2, 200.0, 0.0, 200.0, 0.0);
  testaevolui(2.0, 0.2, 100.0, 0.0, 100.0, 0.0);
  testaevolui(3.0, 0.2, 300.0, 100.0, 300.0, 100.0);
  testaevolui(4.0, 0.2, 200.0, 100.0, 200.0, 100.0);
  testaevolui(5.0, 0.2, 100.0, 100.0, 100.0, 100.0);

  // Completar teste da funcao simula
  double x0 = 200.0, y0 = 0.0;
  double t = 100.0;
  int n = 1000;
  double x[n], y[n];
  simula(x0, y0, t, n, x, y);   // TODO: chama simula
  for (int i = 0; i < n; i++) { // TODO: imprimir cada x e y
    printf("(%.6f, %.6f), \n", x[i], y[i]);
  }

  return 0;
}
