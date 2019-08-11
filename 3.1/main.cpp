#include <iostream>

using namespace std;

int main()
{
    char str[100]={'\0'};
    int i=0, count=0;
    cout << "Enter your string: ";
    cin.getline(str, 100);
     while(str[i]!='\0')
     {
         if (str[i]<'A' || str[i]>'Z' && str[i]<'a' || str[i]>'z')
         {
             count++;
             if (str[i+1]<'A' || str[i+1]>'Z' && str[i+1]<'a' || str[i+1]>'z')
                count--;
         }
         i++;
     }
     if (str[0]>='A' && str[0]<='Z' || str[0]>='a' && str[0]<='z')
        count++;
     cout << "Word count: " << count;
}
