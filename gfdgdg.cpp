#include<iostream>
#include<string>
#include "my_info.cpp"
using namespace std;

StudentInfo S;

void putInfo()
    {
        cout << "Name : ";
        getline(cin, S.name);
        cout << "Department : ";
        cin >> S.Department;
        cout << "Gender (1 = Male , 2 = Female) : ";
        cin >> S.Student_Gender;
        cout << "---Date of birth---\n";
        cout << "Year : ";
        cin >> S.Date_Of_Birth.Year;
        cout << "Month : ";
        cin >> S.Date_Of_Birth.Month;
        cout << "Day : ";
        cin >> S.Date_Of_Birth.Day;
        S.age = S.Date_Of_Birth.Year - currentYear;
        cout << ""
        cin.ignore();
    }