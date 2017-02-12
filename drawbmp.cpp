#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream ofs;
  ofs.open("graph.bmp", ios::out | ios::trunc | ios::binary);
  if (!ofs.is_open())
  {
    cout << "Couldn't open file 'graph.bmp'." << endl;
    return 0;
  }

  char bitmap[0x7566] = {0x42,0x4d,0x66,0x75,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,
                               0x28,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x30,0x75,0x00,0x00,0x13,0x0b,0x00,0x00,0x13,0x0b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  for (int i = 0x36; i < 0x7566; i++) bitmap[i] = 0xff;

  ofs.write(bitmap, 0x7566);

  // ofs << "Hello, world!" << endl;

  ofs.close();
  return 0;
}
