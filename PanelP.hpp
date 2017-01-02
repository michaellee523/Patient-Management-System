#ifndef PANELP
#define PANELP

class PanelP:public Patient{
private:
   string nameEmp;
   double mAmount;
public:
    PanelP(string nameEmp, double mAmount, string icNo);
    string getNameEmp();
    double getmAmount();
    virtual void display();

};

#include "PanelP.cpp"
#endif // PANELP
