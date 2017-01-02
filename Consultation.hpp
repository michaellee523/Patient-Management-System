#ifndef CONSULTATION
#define CONSULTATION

class Consultation:public Patient{
private:
    string date;
    string diagnosis;
    string prescription;
    double fee;
public:
    Consultation(string date, string name, string icNo, string diagnosis, string prescription, double fee);
    Consultation(string date, string name, string icNo, double fee);
    string getDate();
    string getDiagnosis();
    string getPrescription();
    double getFee();
    virtual void display();
    void displayE();
    void displayAll();
};

#include "Consultation.cpp"
#endif // CONSULTATION
