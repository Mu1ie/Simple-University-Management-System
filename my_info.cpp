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

enum Departments {
    CompEng = 1, ElectricalEng = 2, CyberEng = 3, AIEng = 4, ControlEng = 5, BioMedEng = 6, AeroEng = 7
};

//Student :
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