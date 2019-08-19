#include <iostream>
#include <time.h>

using namespace std;

//fills a one-dimensional array with random numbers
void randomNum(int numbs[], int size)
{
    srand(time(0));
    for(int i=0;i<size;i++)
        numbs[i]=rand()%90000-9000;
}

//searching for the maximum number and return it
int maxNum(int numbs[], int size)
{
    int max=numbs[0];
    if (size<=1)
        return numbs[0];
    max = maxNum(numbs,size-1);
    if (numbs[size-1]>max)
        return numbs[size-1];
    else
        return max;
}

//searching for the minimum number and return it
int minNum(int numbs[], int size)
{
    int min=numbs[0];
    if (size<=1)
        return numbs[0];
    min = minNum(numbs,size-1);
    if (numbs[size-1]<min)
        return numbs[size-1];
    else
        return min;
}

//parity or odd check
bool parity_or_odd(int numbs[], int elem)
{
    if (numbs[elem]%2==0)
        return true;
    else
        return false;
}

//multiplies all odd numbers in the array by 2, and takes 1 from even numbers
void manArr(int numbs[], int size)
{
    if (numbs[size-1]%2==0)
        numbs[size-1]--;
    else
        numbs[size-1]*=2;
    if(size>1)
        manArr(numbs, size-1);
}


//nullifies an array
void toZero(int numbs[], int size)
{
    numbs[size-1]=0;
    if (size>1)
        toZero(numbs,size-1);
}

void num_or_let(int num)
{
    if (num>=97 && num<=122 || num>=65 && num<=90)
        cout << (char)num << endl;
    else
        cout << num << endl;
}

int main()
{
     int size = 0, chet=0;
     cout << "Vvedite razmer massiva: ";
     cin >> size;
     int num[size];
     randomNum(num,size);
     cout << "Max = " << maxNum(num,size) << endl;
     cout << "Min = " << minNum(num,size) << endl;
     cout << "Vvedite element kotoryj proverit na chetnost (1 - chet.) (2 - nechet): ";
     cin >> chet;
     if (chet<1 || chet>size)
        cout << "Takogo elementa net!" << endl;
     else
        cout << "Chislo " << num[chet-1] << " - " << parity_or_odd(num,chet) << endl;
     toZero(num,size);
     int number;
     cout << "Vvedite chislo: ";
     cin >> number;
     num_or_let(number);
     for (int i=0;i<size;i++)
       cin >> num[i];
     manArr(num, size);
     for (int i=0;i<size;i++)
        cout << num[i] << endl;
    return 0;
}


