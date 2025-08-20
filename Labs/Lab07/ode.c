#include <math.h>
#include <stdio.h>

double RungeKutta(double t0, double t1, double h, double y0,
                  double (*f)(double t, double y)) {
  double t = t0;
  double y = y0;

  while (t < t1) {
    h = fmin(h, t1 - t);

    double k1 = h * f(t, y);
    double k2 = h * f(t + h / 2.0, y + k1 / 2.0);
    double k3 = h * f(t + h / 2.0, y + k2 / 2.0);
    double k4 = h * f(t + h, y + k3);

    y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
    t += h;
  }

  return y;
}

double RungeKuttaAdapt(double t0, double t1, double y0,
                       double (*f)(double t, double y), double tol) {
  double t = t0;
  double y = y0;
  double h = 1e-7;

  while (t < t1) {
    h = fmin(h, t1 - t);

    double k1 = h * f(t, y);
    double k2 = h * f(t + h / 2.0, y + k1 / 2.0);
    double k3 = h * f(t + h / 2.0, y + k2 / 2.0);
    double k4 = h * f(t + h, y + k3);
    double y1 = y + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;

    double h2 = h / 2.0;

    double k1_1 = h2 * f(t, y);
    double k2_1 = h2 * f(t + h2 / 2.0, y + k1_1 / 2.0);
    double k3_1 = h2 * f(t + h2 / 2.0, y + k2_1 / 2.0);
    double k4_1 = h2 * f(t + h2, y + k3_1);
    double ym = y + (k1_1 + 2.0 * k2_1 + 2.0 * k3_1 + k4_1) / 6.0;

    double k1_2 = h2 * f(t + h2, ym);
    double k2_2 = h2 * f(t + h2 + h2 / 2.0, ym + k1_2 / 2.0);
    double k3_2 = h2 * f(t + h2 + h2 / 2.0, ym + k2_2 / 2.0);
    double k4_2 = h2 * f(t + h, ym + k3_2);
    double y2 = ym + (k1_2 + 2.0 * k2_2 + 2.0 * k3_2 + k4_2) / 6.0;

    double delta = (y1 - y2) / 15.0;
    double erro_y2 = fabs(delta);

    double f = pow(tol / erro_y2, 1.0 / 5.0);

    if (f >= 1.0) {
      y = y2 + delta;
      t += h;
      h *= fmin(1.2, f);
    } else {
      h *= 0.8 * f;
    }
  }

  return y;
}