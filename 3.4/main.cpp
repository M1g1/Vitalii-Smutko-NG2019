#include <iostream>

using namespace std;

int main()
{
    char str[256], alphabet[26], temp_ch;
    int count[26], i=0, j=0, temp=0;
    cout << "Enter your string: ";
    cin.getline(str, 256);
    for(j=0; j<26; j++)
    {
     i=0;
     count[j]=0;
      while (str[i]!=0)
      {
       if (str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' )
        {
         if (str[i]==65+j || str[i]==97+j)
         {
         count[j]++;
         alphabet[j]=65+j;
         }
        }
        i++;
      }
    }
    //Sorting
    for(j=0; j<25; j++)
        for(i=0; i<25-j; i++)
            if (count[i]<count[i+1])
            {
                temp=count[i];
                temp_ch=alphabet[i];
                count[i]=count[i+1];
                alphabet[i]=alphabet[i+1];
                count[i+1]=temp;
                alphabet[i+1]=temp_ch;
            }
    for (j=0; j<26; j++)
        if(count[j]!=0)
          cout << alphabet[j] << " - " << count[j] << endl;

    return 0;
}
