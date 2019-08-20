#include <iostream>

using namespace std;

void spaces(int size, int i)
{
    cout << ' ';
    if (size > i)
        spaces(size-1,i);
}

void stump(int size)
{
    cout << ' ';
     if (size > 1)
        stump(size-1);
     else
        cout << '*';
}

void stars(int size, int i)
{

    if(size < i*2-1)
        stars(size+1, i);
        cout << '*';
}

void tree(int size)
{
      for (int i=1;i<=size;i++)
     {
         spaces(size,i);
         stars(1,i);
         cout << '\n';
     }
     stump(size);

}

int main()
{
    int size;
    cout << "Vvedite razmer elki: ";
    cin >> size;
    tree(size);
    return 0;
}
