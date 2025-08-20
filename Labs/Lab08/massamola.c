#include "massamola.h"
#include <math.h>

void forca(double t, double x, double y, double *fx, double *fy) {
  double k = 0.3;
  double r = 200.0;
  double m = 2.0;
  double g_y = 9.8;
  double w_x = 10.0;

  double fg_x = 0.0;
  double fg_y = m * g_y;

  double fw_x = w_x * exp(-t / 20.0);
  double fw_y = 0.0;

  double norma_p = sqrt(x * x + y * y);
  double fk_x = 0.0;
  double fk_y = 0.0;
  if (norma_p != 0.0) {
    double temp = -k * (norma_p - r) / norma_p;
    fk_x = temp * x;
    fk_y = temp * y;
  }

  *fx = fg_x + fw_x + fk_x;
  *fy = fg_y + fw_y + fk_y;
}

double evolui(double t, double h, double x, double y, double xp, double yp,
              double *xn, double *yn) {
  double m = 2.0;
  double delta = 0.002;

  double fx, fy;
  forca(t, x, y, &fx, &fy);

  *xn = x + (1.0 - delta) * (x - xp) + (h * h * fx) / m;
  *yn = y + (1.0 - delta) * (y - yp) + (h * h * fy) / m;

  return t + h;
}

void simula(double x0, double y0, double t, int n, double *x, double *y) {
  double h = t / n;
  double t_zero = 0.0;
  double xp = x0, yp = y0;
  double xc = x0, yc = y0;

  for (int i = 0; i < n; i++) {
    double xn, yn;

    t_zero = evolui(t_zero, h, xc, yc, xp, yp, &xn, &yn);

    x[i] = xn;
    y[i] = yn;

    xp = xc;
    yp = yc;
    xc = xn;
    yc = yn;
  }
}
