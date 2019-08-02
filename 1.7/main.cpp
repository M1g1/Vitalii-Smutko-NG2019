#include <iostream>

using namespace std;

int main()
{
    int sizer, i, k;
    cout << "Vvedite razmer elki: ";
    cin >> sizer;
    for (i=1;i<=sizer;i++)
     {
       for (k=0;k<=sizer-i;k++)
          cout << ' ';
        for (k=1;k<i*2;k++)
         {
            cout << '*';
         }
         cout << '\n';
     }
     for (i=0;i<sizer;i++)
          cout << ' ';
        cout << '*';
    return 0;
}
