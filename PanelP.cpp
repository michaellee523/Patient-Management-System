#include "PanelP.hpp"

PanelP::PanelP(string nameEmp, double mAmount, string icNo):nameEmp(nameEmp), mAmount(mAmount), Patient(icNo)
{

}

string PanelP::getNameEmp()
{
    return nameEmp;
}

double PanelP::getmAmount()
{
    return mAmount;
}

void PanelP::display()
{
    cout << " 6. Employer name : " << getNameEmp() << endl
         << " 7. Max amount paid by company : " << getmAmount() << endl;
}

