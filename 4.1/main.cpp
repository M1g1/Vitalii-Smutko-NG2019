#include <iostream>

using namespace std;

int sum(int num)
{
     if (num != 0)
        return sum(num/10) + num%10;
    else
        return 0;
}

int main()
{
    int num;
    cout << "Vvedite chislo: ";
    cin >> num;
    cout << "Summa vseh cifr v chisle = " << sum(num);
    return 0;
}
