#include <iostream>

using namespace std;

int main()
{
    int num_of_stars[5]={0,0,0,0,0}, maxElement, i;
     for (i=0 ; i<5 ; i++)
     {
         cout << "Zvezdochek v " << i+1 << "-om stolbike: ";
         cin >> num_of_stars[i];
     }
     maxElement=num_of_stars[0];
     for (i=1 ; i<5 ; i++) //to find the maximum number entered
        if (num_of_stars[i]>maxElement)
           maxElement=num_of_stars[i];
     for (i=0 ; i<maxElement ; i++)
     {
        for (int j=0 ; j<5 ; j++)
        {
            if (num_of_stars[j]<=0)
               cout << ' ';
            else
               cout << '*';
          num_of_stars[j]--;
        }
        cout << endl;
     }
    return 0;
}
