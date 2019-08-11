#include <iostream>

using namespace std;

int main()
{
    char str[100]={'\0'};
    char ch;
    int i=0;
    cout << "Enter your string: ";
    cin.getline(str, 100);
    cout << "Your string in uppercase: ";
     while (str[i]!='\0')
     {
      if (str[i]>=97 && str[i]<=122)
       ch = str[i]-32;
      else
       ch = str[i];
      cout << ch;
      i++;
     }
    return 0;
}
