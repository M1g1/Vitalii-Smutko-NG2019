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

void cashDispenser(float cards[], int size)
{
    int numCard;
    chooseCard(numCard);
     if(numCard<1 || numCard>size)
        cout << "Takoi kartochki net!" << endl;
     else
     {
        addMoney(cards,numCard);
        cardOutput(cards, size);
        cout << endl;
    }
     cashDispenser(cards, size);
}


int main()
{
    float cards[10]={0,0,0,0,0,0,0,0,0,0};
    cashDispenser(cards, 10);
    return 0;
}
