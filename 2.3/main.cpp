#include <iostream>

using namespace std;

int main()
{
    int num_of_stars[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        number_of_entered_numbers=0, maxElement, i=0, space_and_star;
     do
     {
         cout << "Vvedite chislo: ";
         cin >> num_of_stars[i];
         number_of_entered_numbers++;
         i++;
     }while (num_of_stars[i-1]!=0 && i<20);
     maxElement=num_of_stars[0];
     for (i=1 ; i<number_of_entered_numbers ; i++) //to find the maximum number entered
        if (num_of_stars[i]>maxElement)
          maxElement=num_of_stars[i];
     for (i=0; i<number_of_entered_numbers ; i++)
     {
      for (space_and_star=0; space_and_star<(maxElement-num_of_stars[i])/2.0 ; space_and_star++) //cycle for space
         cout << ' ';
       for (space_and_star=0; space_and_star<num_of_stars[i] ; space_and_star++) //cycle for stars
          cout << '*';
       cout << endl;
     }
    return 0;
}
