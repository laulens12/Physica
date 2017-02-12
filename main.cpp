#include <iostream>
using namespace std;

void run(double x0, double v0, double a, double t, double *pt, double *px, double *pv);

int main()
{
  cout << "Welcome to Physica." << endl;

  double x0; cout << "x0:\t"; cin >> x0;
  double v0; cout << "v0:\t"; cin >> v0;
  double a; cout << "a:\t"; cin >> a;
  double t_max; cout << "t_max:\t"; cin >> t_max;

  double dt = t_max / 99.0;

  double pt[100] = {}, px[100] = {}, pv[100] = {};

  for (double t = 0.0; t <= t_max; t += dt)
    run(x0, v0, a, t, pt, px, pv);

  for (int i = 0; i < 100; i++)
    cout << endl << "t:" << pt[i] << endl << "\tx: " << px[i] << endl << "\t\tv: " << pv[i] << endl;

  return 0;
}

void run(double x0, double v0, double a, double t, double *pt, double *px, double *pv)
{
  static int count = 0;

  double dv = a * t;
  double v = v0 + dv;
  double vg = 0.5 * (v0 + v);
  double dx = vg * t;
  double x = x0 + dx;

  pt[count] = t;
  px[count] = x;
  pv[count] = v;

  count++;
}
