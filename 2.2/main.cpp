#include <iostream>

using namespace std;

int main()
{
    float cards[10]={0,0,0,0,0,0,0,0,0,0};
    float money;
    int numCard;
    for (;;)
    {
      cout << "Vvedi nomer kartochki: ";
      cin >> numCard;
       while (numCard<1 || numCard>10)
       {
          cout << " ERROR: Takoi kartochki net!" << endl
               << "Vvedi nomer kartochki: ";
          cin >> numCard;
       }
      cout << "Skolko deneg polozhit: ";
      cin >> money;
      cards[numCard-1]+=money;
      for (int i=0; i<10 ; i++)
        cout << cards[i] << ' ';
      cout << endl;
    }
    return 0;
}
