#ifndef PATIENT
#define PATIENT
using namespace std;

class Patient{
private:
    string name;
    string address;
    string telNo;
    string icNo;
    string age;
public:
    Patient(string icNo);
    Patient(string name, string icNo);
    Patient(string name, string address, string telNo, string icNo, string age);
    string getName();
    string getAddress();
    string getTelNo();
    string getIcNo();
    string getAge();
    void setName(string name);
    void setAddress(string address);
    void setTelNo(string telNo);
    void setIcNo(string icNo);
    void setAge(string age);
    virtual void display();
    void displayE();
};

#include "Patient.cpp"
#endif // PATIENT
