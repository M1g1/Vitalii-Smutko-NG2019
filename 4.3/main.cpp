#include <iostream>

using namespace std;

void chooseCard(int &numCard)
{
    cout << "Vvedi nomer kartochki: ";
    cin >> numCard;
    cin.clear();
    cin.sync();
}

void addMoney(float cards[], int numCard)
{
      float money;
      cout << "Skolko deneg polozhit: ";
      cin >> money;
      cin.clear();
      cin.sync();
      cards[numCard-1]+=money;
}


void cardOutput(float cards[], int amount)
{
      if(amount > 1)
         cardOutput(cards, amount-1);
     cout << cards[amount-1] << ' ';
}

void cashDispenser(float cards[])
{
    int numCard;
    chooseCard(numCard);
     if(numCard<1 || numCard>10)
        cout << "Takoi kartochki net!" << endl;
     else
     {
        addMoney(cards,numCard);
        cardOutput(cards,10);
        cout << endl;
    }
     cashDispenser(cards);
}


int main()
{
    float cards[10]={0,0,0,0,0,0,0,0,0,0};
    cashDispenser(cards);
    return 0;
}
