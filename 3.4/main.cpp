#include <iostream>

using namespace std;

int main()
{
    char str[256], alphabet[27], temp_ch;
    int count[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    i=0, j=0, temp=0;
    cout << "Enter your string: ";
    cin.getline(str, 256);
      while (str[i]!=0)
      {
       for(j=0;j<26;j++)
          if (str[i]=='a'+j || str[i]=='A'+j)
          {
            count[j]++;
            if(count[j]==1)
                alphabet[j]='A'+j;
          }
         i++;
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
