#include <iostream>

using namespace std;

int main()
{
    int num_of_stars[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        maxElement=0, i=0, space_and_star;
     do
     {
         cout << "Vvedite chislo: ";
         cin >> num_of_stars[i];
          while(num_of_stars[i]%2==0 && num_of_stars[i]!=0)
          {
              cout <<" Error! Chislo dolzhno byt nechyotnym!" << endl;
              cout << "Vvedite chislo: ";
              cin >> num_of_stars[i];
          }
          if (num_of_stars[i]>maxElement)
              maxElement=num_of_stars[i];
         i++;
     }while (num_of_stars[i-1]!=0 && i<20);
     for (i=0; i<20 ; i++)
     {
       if (num_of_stars[i]>0)
       {
          for (space_and_star=0; space_and_star<(maxElement-num_of_stars[i])/2 ; space_and_star++) //cycle for space
              cout << ' ';
          for (space_and_star=0; space_and_star<num_of_stars[i] ; space_and_star++) //cycle for stars
              cout << '*';
       cout << endl;
       }
     }
    return 0;
}
