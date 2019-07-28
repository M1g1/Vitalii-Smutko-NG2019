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
        for (int j=2;j<=i*2;j++)
         {
            cout << '*';
         }
         cout << '\n';
     }
     for (int i=0;i<=sizer;i++)
      {
       if (i==sizer)
          cout << '*';
       else
          cout << ' ';
      }

    return 0;
}
