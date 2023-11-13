#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

using namespace std;

class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

class Employee : public AbstractEmployee
{
private:
    int Age;
    string Company;
    int yrsWorking;
    int salary;

protected:
    string Name;
    double increment;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setYrs(int yrs)
    {
        yrsWorking = yrs;
    }
    int getYrs()
    {
        return yrsWorking;
    }
    void setsal(int sal)
    {
        salary = sal;
    }
    int getsal()
    {
        return salary;
    }
    double getIncrement()
    {
        return increment;
    }
    void intro()
    {
        cout << "Name - " << Name << endl;
        cout << "Age - " << Age << endl;
        cout << "Company - " << Company << endl;
        cout << "Time - " << yrsWorking << " yrs" << endl;
        cout << "Salary - " << salary << endl;
    }
    Employee(string name, int age, string company, int yrs, int sal)
    {
        Name = name;
        Age = age;
        Company = company;
        yrsWorking = yrs;
        salary = sal;
        increment = 0;
    }
    void AskForPromotion()
    {
        if (yrsWorking >= 5)
        {
            cout << Name << " got a promotion!!" << endl;
        }
        else
        {
            cout << Name << " doesnt have enough experience to get a promotion" << endl;
        }
    }
    void Work()
    {
        cout << Name << " is checking task logs" << endl;
    }
    void getincr()
    {
        if (yrsWorking >= 5 && yrsWorking < 10)
        {
            cout << Name << " got a 5% increment" << endl;
            increment += 0.05;
        }
        else if (yrsWorking >= 10)
        {
            cout << Name << " got a 10% increment" << endl;
            increment += 0.10;
        }
        else
        {
            cout << Name << " no increment" << endl;
        }
    }
    void newSal()
    {
        int sal = salary + (salary * increment);
        cout << Name << " now your salary : " << sal << endl;
    }
};

int main()
{
    vector<Employee> employees;
    int choice = 0;
    string name;
    int age;
    string company;
    int yrs;
    double salary;
    double increment;

    int index;
    string newName;
    int newAge;
    string newCompany;
    int newYrs;
    double newSalary;
    while (choice != 5)
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Edit employee" << endl;
        cout << "3. Display all employees" << endl;
        cout << "4. Check for increment" << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee age: ";
            cin >> age;
            cout << "Enter employee company: ";
            cin >> company;
            cout << "Enter employee years of working: ";
            cin >> yrs;
            cout << "Enter employee salary: ";
            cin >> salary;

            employees.push_back(Employee(name, age, company, yrs, salary));
            break;
        case 2:

            cout << "Enter the index of the employee you want to edit: ";
            cin >> index;

            if (index < 0 || index >= employees.size())
            {
                cout << "Invalid index" << endl;
                break;
            }

            cout << "Enter new name: ";
            cin >> newName;

            cout << "Enter new age: ";
            cin >> newAge;
            employees[index].setAge(newAge);

            cout << "Enter new company: ";
            cin >> newCompany;
            employees[index].setCompany(newCompany);

            cout << "Enter total working years now: ";
            cin >> newYrs;
            employees[index].setYrs(newYrs);

            cout << "Enter new salary: ";
            cin >> newSalary;
            employees[index].setsal(newSalary);

            break;
        case 3:
            for (int i = 0; i < employees.size(); i++)
            {
                cout << "Employee #" << i << endl;
                cout << "\nName: " << employees[i].getName() << endl;
                cout << "Age: " << employees[i].getAge() << endl;
                cout << "Company: " << employees[i].getCompany() << endl;
                cout << "Year of Working: " << employees[i].getYrs() << endl;
                cout << "Salary: " << employees[i].getsal() << endl;
            }
            break;
        case 4:

            for (int i = 0; i < employees.size(); i++)
            {
                employees[i].getincr();                                                                                 // check increment and update the increment for each employee
                employees[i].newSal();                                                                                  // calculate new salary with updated increment
                cout << employees[i].getName() << "'s increment: " << employees[i].getIncrement() * 100 << "%" << endl; // output the increment for each employee
            }
            break;

        case 5:
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}