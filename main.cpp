#include <iostream>
using namespace std;

void run(double x0, double v0, double a, double t);

int main()
{
  cout << "Welcome to Physica." << endl;

  double x0; cout << "x0:\t"; cin >> x0;
  double v0; cout << "v0:\t"; cin >> v0;
  double a; cout << "a:\t"; cin >> a;
  double t0; cout << "t0:\t"; cin >> t0;
  double dt; cout << "dt:\t"; cin >> dt;
  double t_max; cout << "t_max:\t"; cin >> t_max;

  double *px, *pv;

  if (t0 < t_max)
  {
    cout << endl << "t\t|x\t|v" << endl;
    for (int t = t0; t <= t_max; t += dt)
      run(x0, v0, a, t);
  }
  else
    cout << "t0 has to be smaller then t_max!" << endl;

  return 0;
}

void run(double x0, double v0, double a, double t)
{
  double dv = a * t;
  double v = v0 + dv;
  double vg = 0.5 * (v0 + v);
  double dx = vg * t;
  double x = x0 + dx;
  cout << t << "\t|" << x << "\t|" << v << endl;
}
