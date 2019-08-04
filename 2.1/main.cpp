#include <iostream>

using namespace std;

int main()
{
    int numSchools [10], i, findSchool;
    bool result=0;
    for (i=0; i<10 ; i++)
     {
       cout << "Vvedite nomer kakoi-to shkolu: ";
       cin >> numSchools[i];
     }
    cout << "A teper vvedite svoyu shkolu: ";
    cin >> findSchool;
    for (i=0; i<10 ; i++)
     {
       if (findSchool == numSchools[i])
       {
         result=1;
         break;
       }
     }
     if (result!=0)
      cout << "Ya znayu etu shkolu!";
     else
      cout << "Ya ne znayu etu shkolu!";

    return 0;
}
