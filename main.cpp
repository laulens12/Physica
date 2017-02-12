#include <iostream>
#include <fstream>
using namespace std;

void run(double x0, double v0, double a, double t, double *pt, double *px, double *pv);
void scaleArrays(double *px, double *pv, int *px_g, int *pv_g);
void drawbmp(int *px_g, int *pv_g);

int main()
{
  cout << "Welcome to Physica." << endl;

  double x0; cout << "x0:\t"; cin >> x0;
  double v0; cout << "v0:\t"; cin >> v0;
  double a; cout << "a:\t"; cin >> a;
  double t_max; cout << "t_max:\t"; cin >> t_max;

  double dt = t_max / 99.0;

  double pt[100] = {}, px[100] = {}, pv[100] = {};
  int px_g[100] = {}, pv_g[100] = {};

  for (double t = 0.0; t <= t_max; t += dt)
    run(x0, v0, a, t, pt, px, pv);

  scaleArrays(px, pv, px_g, pv_g);
  drawbmp(px_g, pv_g);

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

void scaleArrays(double *px, double *pv, int *px_g, int *pv_g)
{
  double maxpx = 0, maxpv = 0;
  for (int i = 0; i < 100; i++)
  {
    if (maxpx < px[i]) maxpx = px[i];
    if (maxpv < pv[i]) maxpv = pv[i];
  }

  for (int i = 0; i < 100; i++)
  {
    px_g[i] = px[i] / maxpx * 99.0;
    pv_g[i] = pv[i] / maxpv * 99.0;
  }
}

void drawbmp(int *px_g, int *pv_g)
{
  ofstream ofs;
  ofs.open("graph.bmp", ios::out | ios::trunc | ios::binary);
  if (!ofs.is_open())
  {
    cout << "Couldn't open file 'graph.bmp'." << endl;
    return;
  }

  char bitmap[0x7566] = {0x42,0x4d,0x66,0x75,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,
                         0x28,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x30,0x75,0x00,0x00,0x13,0x0b,0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  // for (int i = 0x36; i < 0x7566; i++) bitmap[i] = 0xff;

  for (int row = 0; row < 100; row++)
    for (int col = 0; col < 100; col++)
    {
      static int addr = 54;

      //if (row == col) bitmap[addr] = 0xff;
      if (px_g[col] == row) { bitmap[addr] = 0xff; }
      if (pv_g[col] == row) { bitmap[addr+2] = 0xff; }

      addr += 3;
    }

  ofs.write(bitmap, 0x7566);

  // ofs << "Hello, world!" << endl;

  cout << "Chart saved as './graph.bmp'." << endl;

  ofs.close();

  return;
}
