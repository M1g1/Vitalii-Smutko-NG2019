#include <iostream>

using namespace std;

int main()
{
    int num_of_stars[5]={0,0,0,0,0}, maxElement=0, i;
     for (i=0 ; i<5 ; i++)
     {
         cout << "Zvezdochek v " << i+1 << "-om stolbike: ";
         cin >> num_of_stars[i];
         if (num_of_stars[i]>maxElement)
           maxElement=num_of_stars[i];
     }
     for (i=0 ; i<maxElement ; i++)
     {
        for (int j=0 ; j<5 ; j++)
        {
            if (num_of_stars[j]-i<=0)
               cout << ' ';
            else
               cout << '*';
        }
        cout << endl;
     }
    return 0;
}
