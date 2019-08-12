#include <iostream>

using namespace std;

int main()
{
    char str[100]={'\0'};
    int i=0, count=0, maxWordLen=0, endOfMaxWord=0;
    cout << "Enter your string: ";
    cin.getline(str, 100);
     while(str[i]!='\0')
     {
         if (str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z')
         {
             count++;
         }
         if (str[i+1]<'A' || str[i+1]>'Z' && str[i+1]<'a' || str[i+1]>'z')
         {

             if (count>maxWordLen)
                {
                 maxWordLen=count; //length of the longest word
                 endOfMaxWord=i;  //saved the end of the word
                }
             count=0;
         }
         i++;
     }
      if (maxWordLen==0)
        cout << "No words found!";
      else
      {
       cout << "The longest word: ";
        for(i=endOfMaxWord-maxWordLen+1;i<=endOfMaxWord;i++)
           cout << str[i];
      }
    return 0;
}
