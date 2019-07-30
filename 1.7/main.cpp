#include <iostream>

using namespace std;

int main()
{
    int sizer;
    cout << "Vvedite razmer elki: ";
    cin >> sizer;
    for (int i=1;i<=sizer;i++)
     {
       for (int k=0;k<=sizer-i;k++)
          cout << ' ';
        for (int j=1;j<i*2;j++)
         {
            cout << '*';
         }
         cout << '\n';
     }
     for (int i=0;i<sizer;i++)
          cout << ' ';
        cout << '*';
    return 0;
}
