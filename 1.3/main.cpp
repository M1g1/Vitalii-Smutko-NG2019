#include <iostream>

using namespace std;

int main()
{
    float first_num=0,second_num=0;
    short int action=0;
    cout << "Enter the first number: ";
     cin >> first_num;
    cout << "Enter the second number: ";
     cin >> second_num;
    cout << "Choose action on numbers 1 (+), 2 (-), 3 (*), 4 (/): ";
     cin >> action;
     if (action<1 || action>4)
        cout << " ERROR: Action does not exist ...";
     if (action==1)
        cout << "Result: " << first_num+second_num;
     if (action==2)
        cout << "Result: " << first_num-second_num;
     if (action==3)
        cout << "Result: " << first_num*second_num;
     if (action==4)
        if (second_num==0)
          cout << " ERROR: Division by 0 is impossible ...";
       else
          cout << "Result: " << first_num/second_num;
    return 0;
}
