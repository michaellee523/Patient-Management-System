#include "Consultation.hpp"


Consultation::Consultation(string date, string name, string icNo, string diagnosis, string prescription, double fee):date(date), Patient(name,icNo),diagnosis(diagnosis), prescription(prescription), fee(fee)
{

}

Consultation::Consultation(string date, string name, string icNo, double fee):date(date), Patient(name,icNo), fee(fee)
{

}

string Consultation::getDate()
{
    return date;
}

string Consultation::getDiagnosis()
{
    return diagnosis;
}

string Consultation::getPrescription()
{
    return prescription;
}

double Consultation::getFee()
{
    return fee;
}

void Consultation::display()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " This is your last consultation details. " << endl
         << " Date                : " << getDate() << endl
         << " Name                : " << getName() << endl
         << " IC number           : " << getIcNo() << endl
         << " Diagnosis           : " << getDiagnosis() << endl
         << " Prescription        : " << getPrescription() << endl
         << " Consultation fee    : " << "RM " << getFee() << endl;
}

void Consultation::displayE()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " Date                : " << getDate() << endl
         << " Name                : " << getName() << endl
         << " Consultation fee    : " << "RM " << getFee() << endl;
}

void Consultation::displayAll()
{
    cout << " Name                : " << getName() << endl
         << " Date                : " << getDate() << endl
         << " Consultation fee    : " << "RM " << getFee() << endl
         << " ---------------------------------------- " << endl << endl;
}

