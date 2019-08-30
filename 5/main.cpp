#include <iostream>
#include <iomanip>
#define qPlaces 100

using namespace std;

//String to uppercase

string toupperStr(string str)
{
    for(int i=0; str[i]!=0; i++)
        if (str[i]>=97 && str[i]<=122)
            str[i] = str[i]-32;
        else
            str[i] = str[i];
    return str;
}

struct Student
{
    string name = "-";
    string surname = "-";
    int    age = 0;
    string gender = "-";
};

struct Curator
{
    string name = "-";
    string surname = "-";
    int    age = 0;
    string gender = "-";
    string academicDegree = "-";
};


class studGroup
{
public:
    studGroup();
    void OutputStud();      //Output students
    void AddStud();         //Adding students
    void DelStud();         //Deletion students
    void surnameSorting();  //Sorting by surname
    void searchName();      //Search by name
    void searchSurname();   //Search by surname
    void searchGender();    //Search by gender
    void searchAge();       //Search by age
    void setCurator();      //Set curator
    Curator retCurator() {return curator;}; //returns the group curator
    void setFacult();       //Create faculty

private:
    int numStud; //number of students
    bool setF;   //for checking faculty definition
    Student students[qPlaces]; //qPalaces - maximum number of places for students in a group
    Curator  curator;
    string facultName;
};


studGroup::studGroup()
{
    numStud = 0;
    facultName = "-";
    setF = false;
}

//Create faculty

void studGroup::setFacult()
{
    if (setF)
        cout << "\n ERROR! Nelzya pomenyat fakultet opyat!" << endl;
    else
    {
        cout << "\nVvedite nazvanie faculteta: ";
        getline(cin,facultName);
        setF = true;
    }
}

//Output students

void studGroup::OutputStud()
{
    if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
        cout << "\n\t---------------- Spisok studentov gruppy ----------------" << endl;
        cout << endl << "\tFamiliya" << "\t\tImya" << "\t\tVozrast" << "\t\tPol" << endl << endl;
        for (int i=0; i<numStud; i++)
            cout << setw(16) << students[i].surname << setw(20) << students[i].name
                 << setw(19) << students[i].age << setw(12) << students[i].gender << endl;
    }
}

//Adding students

void studGroup::AddStud()
{
    if (numStud < qPlaces)
    {
        cout << "\nVvedite dannye studenta!" << endl;
        cout << "\nFamiliya: ";
        getline(cin,students[numStud].surname);
        cout << "Imya: ";
        getline(cin,students[numStud].name);
        cout << "Vozrast: ";
        cin >> students[numStud].age;
        cin.clear();
        cin.sync();
        cout << "Pol: ";
        getline(cin,students[numStud].gender);
        cout << "\n Student dobavlen v spisok!" << endl;
        numStud++;
    }
    else
        cout << "\n Net mesta!" << endl;
}

//Deletion students

void studGroup::DelStud()
{
    if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
      bool chekForDel = false;
      int age_del;
      string surname_del, name_del, gender_del;
      cout << "\nVvedite dannye studenta na udalenie!" << endl;
      cout << "\nFamiliya: ";
      getline(cin,surname_del);
      cout << "Imya: ";
      getline(cin,name_del);
      cout << "Vozrast: ";
      cin >> age_del;
      cin.clear();
      cin.sync();
      cout << "Pol: ";
      getline(cin,gender_del);
      for (int i=0; i<numStud; i++)
        if (toupperStr(surname_del) == toupperStr(students[i].surname)
            && toupperStr(name_del) == toupperStr(students[i].name)
            && age_del == students[i].age
            && toupperStr(gender_del) == toupperStr(students[i].gender))
        {
            for (int k=i; k<qPlaces; k++)
                 students[k] = students[k+1];
            chekForDel = true;
            numStud--;
            break;
        }
        if (chekForDel)
            cout << "\n Udaleno!" << endl;
        else
            cout << "\n Takogo studenta net!" << endl;
    }
}

//Sorting by surname

 void studGroup::surnameSorting()
 {
    Student tempStd;
    for(int i=0;i<numStud-1;i++)
        for(int j=i+1;j<numStud;j++)
            if(toupperStr(students[i].surname) > toupperStr(students[j].surname))
            {   tempStd=students[i];
                students[i]=students[j];
                students[j]=tempStd;
            }
    cout << "\n Studenty otsortirovany po familii!" << endl;
 }

//Search by name

void studGroup::searchName()
{
    if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
      bool chekForSearch = false;
      string searchName;
      cout << "\nVvedite imya: ";
      getline(cin, searchName);
      for (int i=0; i<numStud; i++)
        if (toupperStr(searchName) == toupperStr(students[i].name))
            chekForSearch = true;
      if (chekForSearch)
      {
       cout << "\n\t---------------- Rezultat poiska po imeni ----------------" << endl;
       cout << endl << "\tImya" << "\t\tFamiliya" << "\t\tVozrast" << "\t\tPol" << endl << endl;
       for (int i=0; i<numStud; i++)
        if (toupperStr(searchName) == toupperStr(students[i].name))
        {
            cout << setw(12) << students[i].name << setw(20) << students[i].surname
                 << setw(23) << students[i].age << setw(12) << students[i].gender << endl;
        }
      }
      else
        cout << "\n Nechego ne naideno" << endl;
    }
}

//Search by surname

void studGroup::searchSurname()
{
    if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
      bool chekForSearch = false;
      string searchSurname;
      cout << "\nVvedite familiyu: ";
      getline(cin, searchSurname);
      for (int i=0; i<numStud; i++)
        if (toupperStr(searchSurname) == toupperStr(students[i].surname))
           chekForSearch = true;
        if(chekForSearch)
        {
         cout << "\n\t---------------- Rezultat poiska po familii ----------------" << endl;
         cout << endl << "\tFamiliya" << "\t\tImya" << "\t\tVozrast" << "\t\tPol" << endl << endl;
         for (int i=0; i<numStud; i++)
            if (toupperStr(searchSurname) == toupperStr(students[i].surname))
            {
                cout << setw(16) << students[i].surname << setw(20) << students[i].name
                     << setw(19) << students[i].age << setw(12) << students[i].gender << endl;
            }
        }
        else
            cout << "\n Nechego ne naideno!" << endl;
    }
}

//Search by gender

void studGroup::searchGender()
{
     if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
      bool chekForSearch = false;
      string searchGender;
      cout << "\nVvedite pol: ";
      getline(cin, searchGender);
      for (int i=0; i<numStud; i++)
         if (toupperStr(searchGender) == toupperStr(students[i].gender))
            chekForSearch = true;
      if(chekForSearch)
      {
       cout << "\n\t---------------- Rezultat poiska po polu ----------------" << endl;
       cout << endl << "\tPol" << "\t\tFamiliya" << "\t\tImya" << "\t\tVozrast" << endl << endl;
       for (int i=0; i<numStud; i++)
          if (toupperStr(searchGender) == toupperStr(students[i].gender))
          {
                cout << setw(11) << students[i].gender << setw(21) << students[i].surname << setw(20) << students[i].name
                     << setw(19) << students[i].age << endl;
          }
      }
      else
        cout << "\n Nechego ne naideno!" << endl;
    }
}

//Search by age

void studGroup::searchAge()
{
     if (numStud < 1)
        cout << "\n V gruppe net studentov!" << endl;
    else
    {
      bool chekForSearch = false;
      int searchAge;
      cout << "\nVvedite vozrast: ";
      cin >> searchAge;
      cin.clear();
      cin.sync();

      for (int i=0; i<numStud; i++)
         if (searchAge == students[i].age)
            chekForSearch = true;

      if (chekForSearch)
      {
       cout << "\n\t---------------- Rezultat poiska po vozrastu ----------------" << endl;
       cout << endl << "\tVozrast" << "\t\tFamiliya" << "\t\tImya" << "\t\tPol" <<  endl << endl;
       for (int i=0; i<numStud; i++)
          if (searchAge == students[i].age)
          {
                cout << setw(15) << students[i].age << setw(17) << students[i].surname << setw(20) << students[i].name
                     << setw(15) << students[i].gender << endl;
          }
      }
      else
        cout << "\n Nechego ne naideno" << endl;
    }
}

//Set curator

void studGroup::setCurator()
{
    cout << "\nVvedite dannye curatora!" << endl;
    cout << "\nFamiliya: ";
    getline(cin,curator.surname);
    cout << "Imya: ";
    getline(cin,curator.name);
    cout << "Vozrast: ";
    cin >> curator.age;
    cin.clear();
    cin.sync();
    cout << "Pol: ";
    getline(cin,curator.gender);
    cout << "Uchyonoe zvanie: ";
    getline(cin,curator.academicDegree);
}



int main()
{
   studGroup group;
   int choice;
   while(1)
   {
    cout << "\n(1)-AddStud\n(2)-DelStud\n(3)-outputStud\n"
         << "(4)-setCurator\n(5)-outputCurator\n(6)-setFacult\n"
         << "(7)-searchName\n(8)-seachSurname\n(9)-searchGender\n(10)-searchAge\n(11)-surnameSorting\n>> ";
    cin >> choice;
    cin.clear();
    cin.sync();
    switch (choice)
    {
       case 1: group.AddStud(); break;
       case 2: group.DelStud(); break;
       case 3: group.OutputStud(); break;
       case 4: group.setCurator();break;
       case 5:
           cout << "\n Dannye curatora" << endl
                << "\nFamiliya: " << group.retCurator().surname << endl
                << "Imya: " << group.retCurator().name << endl
                << "Vozrast: " << group.retCurator().age <<endl
                << "Pol: " << group.retCurator().gender << endl
                << "Uchyonoe zvanie: " << group.retCurator().academicDegree << endl;
           break;
       case 6: group.setFacult(); break;
       case 7: group.searchName(); break;
       case 8: group.searchSurname(); break;
       case 9: group.searchGender(); break;
       case 10: group.searchAge(); break;
       case 11: group.surnameSorting(); break;
       default: break;
    }
   }
}
