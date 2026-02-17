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
    User(string UN, string PS, RolesOf R): Username(UN), Password(PS), Role(R){};
    ~User(){};
    virtual void viewInfo(){};
    virtual void putInfo(){};
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
    Student(string UN, string PS): User(UN, PS, StudentS){};
    ~Student(){};
    
    void putInfo() override
    {
        cout << "Name :";
        getline(cin, S.name);

        cout << "Date of birth : \n";
        
        cin >> S.Date_Of_Birth;
        S.age = S.Date_Of_Birth.Year - currentYear;
        cin.ignore();
    }
    void viewInfo() override
    {
        cout << "\nName :" << S.name << endl;
        cout << "Age : " << S.age << endl;
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
        switch (DashChoose)
        {
        case 1:
            viewInfo();
            break;
        
        default:
            break;
        }



    }
};

class Admin : public User
{
public:
    Admin(string UN, string PS): User(UN, PS, AdminA){};
    ~Admin(){};
    void Dashboard() override
    {
        cout << "Welcome to Admin Dashboard" << "\n-----------------------" << endl;
        cout << "1.Personal Information" << endl;
        cout << "2.Manage Users" << endl;
        cout << "3.System Settings" << endl;
        cout << "4.Reports" << endl;
        cout << "0.close" << endl;
        int Admin_DashChoose;
        cin>>Admin_DashChoose;
    }
};


int main()
{
    vector<User*> OurUsers;
    User* D = new Admin("ManOfHaji","6769");
    OurUsers.push_back(D);
    int Choose;
    bool run_login_as = true;
    while(run_login_as)
    {
        cout << "=== Login as ===\n";
        cout << "\n1.User\n";
        cout << "2.Admin\n";
        cout << "\n: ";
        cin >> Choose;
        
        switch (Choose)
        {
            case 1: // User
            {
                int RoleChoose;
                cout << "\n=== What is your role? ===\n";
                cout << "\n1.Student\n";
                cout << "2.Teacher\n";
                cout << "3.Employee\n";
                cout << "\n0.back";
                cout << "\n: ";
                cin >> RoleChoose;
                bool Run_RoleChoose = true;
                while(Run_RoleChoose)
                {
                    switch(RoleChoose)
                    {
                        case 1: // student
                        {
                            int LoginType;
                            string inputUsername, inputPassword;
                            cout << "=== Welcome Student ===\n\n";
                            cout << "1.Register\n";
                            cout << "2.login\n";
                            cout << "\n0. return\n";
                            cout << ": ";
                            cin >> LoginType;
                            switch (LoginType)
                            {
                                case 1: // register
                                {
                                    cout << "\n=== Welcome new Student ===\n";
                                    cout<<"Please Enter Your Information\n";
                                    cin.ignore();
                                    cout << "Username : ";
                                    getline(cin, inputUsername);
                                    cout << "Password : ";
                                    getline(cin, inputPassword);
                                    Student *s = new Student(inputUsername, inputPassword);
                                    s->putInfo();
                                    OurUsers.push_back(s);
                                    char anykey;
                                    cout << "\nPress any key to continue. : ";
                                    if(cin>>anykey) run_login_as = false;
                                    break;
                                } // end of case 1 (register)



                                case 2: // login
                                {
                                    cout << "\nLogin\n-----------\n";
                                    cin.ignore();
                                    cout << "Username : ";
                                    getline(cin, inputUsername);
                                    cout << "\nPassword : ";
                                    getline(cin, inputPassword);

                                    for (int i = 0; i < OurUsers.size(); i++)
                                    {
                                        if(OurUsers[i]->check(inputUsername, inputPassword, StudentS))
                                        {
                                            run_login_as = false;
                                            Run_RoleChoose = false;
                                            cout<<"\n";
                                            OurUsers[i]->Dashboard();
                                        }
                                    }
                                    
                                    break;
                                } // end of case 2 (login)
                                

                                case 0:
                                {
                                    Run_RoleChoose = true;
                                    break;
                                }


                            } // end of LoginType switch
                            break;
                        
                        } // end of case 1 (student)





                        case 2://Teacher
                        {
                            int LoginType;
                            cout << "Welcome Teacher\n---------------\n";
                            cout << "1.Register\n2.login\n";
                            cout << ": ";
                            break;
                        } // end of case 2 (teacher)






                        case 3://Employee
                        {
                            int LoginType;
                            cout << "Welcome Employee\n---------------\n";
                            cout << "1.Register\n2.login\n";
                            cout << ": ";
                            break;
                        } // end of case 3 (employee)






                        case 0: //Back
                        {
                            Run_RoleChoose = false;
                        }
                    } // end of RoleChoose switch
                }
                break;
            } // end of case 1 (User)





            case 2: // Admin
                {
                    string AdminPassword;
                    RolesOf A = AdminA;
                    cout << "Enter Admin Password :";
                    cin.ignore();
                    getline(cin,AdminPassword);
                    if(OurUsers[0]->check("ManOfHaji",AdminPassword,A))
                    {
                        OurUsers[0]->Dashboard();
                        run_login_as = false;  
                    }
                    else
                    {
                        cout << "Wrong password\n";
                    }
                    
                    break;

                }// end of case 2 (Admin)
            
            case 0:
            {
                run_login_as = false;
                break;
            }

            default:
            {
                cout << "invalid\n";
                break;
            }

        } // end of Choose switch
    }//end of while















    return 0;
} // end of main()
