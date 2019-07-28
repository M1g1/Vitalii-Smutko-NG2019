#include <iostream>

using namespace std;

int main()
{
   float zarp;
   cout << "Vvedite vashu zarplatu ($): ";
   cin >> zarp;
    if (zarp>999)
    {
      if (zarp>999999)
        cout <<"Ti millioner";
      if (zarp<1000000)
        cout <<"Horosho";
    }
    if (zarp<1000)
    {
        cout <<"Rabotai bolshe";
    }
   cout << ", no ti molodec!";
   return 0;
}
