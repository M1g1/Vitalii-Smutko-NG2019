#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int sizeSquare;
    cout << "Vvedite ramer kvadrata: ";
    cin >> sizeSquare;
   for(int i=0;i<sizeSquare;i++)
    {
      for(int j=0;j<sizeSquare;j++)
       {
         cout<<'*';
       }
      cout<<'\n';
    }
    return 0;
}
