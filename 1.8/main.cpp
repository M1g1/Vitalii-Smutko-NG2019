#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int sizer;
    cout << "Vvedite razmer: ";
    cin>>sizer;
//////////Task1.8a/////////

    for(int i=0;i<sizer;i++)
    {
      for(int j=0;j<sizer;j++)
       {
        if (j<=i)
          cout<<'a';
       }
      cout<<'\n';
    }

///////////////////////////
    cout << '\n';
//////////Task1.8b/////////

    for(int i=0;i<sizer;i++)
    {
      for(int j=0;j<sizer;j++)
       {
        if (j>=i)
          cout<<'a';
       }
      cout<<'\n';
    }
///////////////////////////
    cout << '\n';
//////////Task1.8c/////////

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

    return 0;
}
