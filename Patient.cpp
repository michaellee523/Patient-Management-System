#include "Patient.hpp"
using namespace std;


Patient::Patient(string icNo):icNo(icNo)
{

}

Patient::Patient(string name, string icNo):name(name), icNo(icNo)
{

}

Patient::Patient(string name, string address, string telNo, string icNo, string age):name(name), address(address), telNo(telNo), icNo(icNo), age(age)
{

}

string Patient::getName()
{
    return name;
}

string Patient::getAddress()
{
    return address;
}

string Patient::getTelNo()
{
    return telNo;
}

string Patient::getIcNo()
{
    return icNo;
}

string Patient::getAge()
{
    return age;
}

void Patient::setName(string name)
{
    this->name = name;
}

void Patient::setAddress(string address)
{
    this->address = address;
}
void Patient::setTelNo(string telNo)
{
    this->telNo = telNo;
}

void Patient::setIcNo(string icNo)
{
    this->icNo = icNo;
}

void Patient::setAge(string age)
{
    this->age = age;
}

void Patient::display()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " 1. Name          : " << getName() << endl
         << " 2. Address       : " << getAddress() << endl
         << " 3. Phone number  : " << getTelNo() << endl
         << " 4. IC Number     : " << getIcNo() << endl
         << " 5. Age           : " << getAge() << endl;
}

void Patient::displayE()
{
    cout << getName() << endl << " -> " << getIcNo() << endl;
}
