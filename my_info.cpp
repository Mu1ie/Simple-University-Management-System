#include<iostream>
#include<string>
using namespace std;

int currentYear = 2026;


enum Gender {
    Male = 1 , Female = 2
};

struct Date{
    int Year , Month , Day;
};

enum StudentYears {
    FirstStage = 1 , SecondStage = 2 , ThirdStage = 3 , ForthStage = 4
};
struct StudentInfo {
    string name = "userman";
    int age;
    StudentYears stage = FirstStage;
    string Department;
    Date Date_Of_Birth;
    Date Start_Year;
    Gender Student_Gender;

};