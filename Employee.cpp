#include "Employee.hpp"


Employee::Employee(int EmpID, string EmpName, string EmpIcNo):EmpID(EmpID), EmpName(EmpName), EmpIcNo(EmpIcNo)
{

}

int Employee::getEmpID()
{
    return EmpID;
}

string Employee::getEmpName()
{
    return EmpName;
}

string Employee::getEmpIcNo()
{
    return EmpIcNo;
}

void Employee::display()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " Welcome, " << getEmpName() << endl
         << " 1. Emp. ID       : " << getEmpID() << endl
         << " 2. Name          : " << getEmpName() << endl
         << " 3. IC Number     : " << getEmpIcNo() << endl;
}
