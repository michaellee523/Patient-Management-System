#ifndef EMPLOYEE
#define EMPLOYEE

class Employee{
private:
    int EmpID;
    string EmpName;
    string EmpIcNo;
public:
    Employee(int EmpID, string EmpName, string EmpIcNo);
    int getEmpID();
    string getEmpName();
    string getEmpIcNo();
    void display();
};

#include "Employee.cpp"
#endif // EMPLOYEE
