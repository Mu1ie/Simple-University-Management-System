#include <iostream>
#include <string>
#include <vector>
#include "my_info.cpp"
using namespace std;

enum RolesOf {AdminA = 0, StudentS = 1, TeacherT = 2, EmployeeE = 3};

class User
{
private:
    string Username, Password;
    RolesOf Role;

public:
    //User Constructor & Destructor:
    User(string UN, string PS, RolesOf R): Username(UN), Password(PS), Role(R){};
    ~User(){};

    // Methods:
    virtual void view_Personal_info(){};
    virtual void putInfo(){};
    void handleDashboardChoice(){};
    virtual void Dashboard(){};
    bool check(string username, string password, RolesOf role)
    {
        return (username == Username && password == Password && role == Role);
    }
};

class Student : public User
{
private:
    StudentInfo S;
public:
    //Student Constructor & Destructor:
    Student(string UN, string PS): User(UN, PS, StudentS){};
    ~Student(){};

    //Methods :
    
    void putInfo() override
    {
        cout << "Name :";
        getline(cin, S.name);

        cout << "Date of birth : \n";
        
        cin >> S.Date_Of_Birth;
        S.age = S.Date_Of_Birth.Year - currentYear;
        cin.ignore();
    }
    void view_Personal_info() override
    {
        cout << "\nName :" << S.name << endl;
        cout << "Age : " << S.age << endl;
        cout << "Gender : " << S.Student_Gender << endl;
        cout << "Department : " << S.Department <<endl;
        cout << "Stage : " << S.stage << endl;
        cout << "Date of Birth : " << S.Date_Of_Birth.Year << "/" <<S.Date_Of_Birth.Month << "/" << S.Date_Of_Birth.Day << endl;
        cout << "Start Year : " << S.Start_Year <<endl;
    }

    void handleDashboardChoice(int DashChoose)
    {
        switch (DashChoose)
        {
        case 1: view_Personal_info();
            break;
        
        case 2:
            break;
        }
    }

    
    void Dashboard() override
    {
        cout << "Welcome , " << S.name << "\n------------------" << endl;
        cout << "1.Personal Information" << endl;
        cout << "2.Registered Courses" << endl;
        cout << "3.Grades" << endl;
        cout << "4.Timetable" << endl;
        cout << "0.close" << endl;
        int DashChoose;
        cin>>DashChoose;
}

};