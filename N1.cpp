#include <iostream>
#include<string>
#include<vector>
#include"my_info.cpp"
#include"Dashboard.cpp"
using namespace std;

enum RolesOf {StudentS = 1 , TeacherT = 2 , EmployeeE = 3};

class User
{
private:
    string Username , Password;
    RolesOf Role;

public:
    User(string UN , string PS , RolesOf R):Username(UN),Password(PS),Role(R){};
    ~User(){};
    virtual void viewInfo(){};
    virtual void putInfo(){};
    virtual void changeInfo(){};

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
    Student(string UN , string PS):User(UN,PS,StudentS){};
    ~Student(){};
    void putInfo() override
    {
        cout<<"Name :";
        getline(cin,S.name);
        
        cout<<"Age : ";
        cin>>S.age;
        cin.ignore();
    }

    void viewInfo() override
    {
        cout<<"Name :"<<S.name<<endl;
        cout<<"Age : "<<S.age<<endl;
    }

    void changeInfo() override 
    {
    cout << "Current Name: " << S.name << "\nNew Name (leave empty to keep): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) S.name = newName;

    cout << "Current Age: " << S.age << "\nNew Age (0 to keep): ";
    int newAge;
    cin >> newAge;
    cin.ignore();
    if (newAge != 0) S.age = newAge;
    }

};

int main()
{
    vector<User*> OurUsers;
    OurUsers.push_back(new Student("rere","zxcv"));

    
    OurUsers[0]->putInfo();
    OurUsers[0]->viewInfo();
    
    
    
    
    for (User* u : OurUsers)
        delete u;
    
    /*
    string x , y;

    cout<<"Find // \n";
    cout<<"Username : ";
    getline(cin,x);
    
    cout<<"Password : ";
    getline(cin,y);

    cout<<OurUsers[0].check(x,y,StudentS);
    
    */
    

}
