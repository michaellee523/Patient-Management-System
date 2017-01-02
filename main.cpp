#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include "Patient.hpp"
#include "PanelP.hpp"
#include "Consultation.hpp"
#include "Employee.hpp"
using namespace std;

void displayMenu();
void displayPageP();
void displayBanner();
bool missI = true;
bool missV = true;
bool missE = true;
bool menuLoop = true;
bool subLoop1 = true;
bool subLoop2 = true;
bool subLoop3 = true;
bool subLoop4 = true;
bool subLoop5 = true;
bool subLoop6 = true;
string menuChoice;
string YoC;
string choiceP;
string choicePU;
string choiceE;
string tempName;
string tempAddress;
string tempTelNo;
string tempIcNo;
string tempDate;
string tempAge;
string tempDiagnosis;
string tempPrescription;
double tempFee;
int tempEmpID;
string tempInfo;
string tempNameEmp;
double tempmAmount;


bool compareN(const Patient & a, const Patient & b)
{
    return Patient(a).getName() < Patient(b).getName();
}

bool compareD(const Consultation & a, const Consultation & b)
{
    return Consultation(a).getDate() < Consultation(b).getDate();
}


void searchPinfo(string Ic, vector <Patient> p);
void searchPvisit(string Ic, vector <Consultation> c);
void searchPpanel(string Ic,vector <PanelP> pp);
void searchE(int Ic, vector<Employee> e);
void changeInfo(string ChoicePU, string Ic, string Info, vector <Patient>& p);


int main(){
    vector <Patient> p;
    p.push_back(Patient ("Michael", "Sungai Petani", "0113456789", "960101020101", "20"));
    p.push_back(Patient ("Jeff", "Ipoh", "0123456789", "960202020202", "20"));
    p.push_back(Patient ("Kenneth", "Sungai Petani", "0133456789", "960303020303", "20"));
    p.push_back(Patient ("Andy", "Seremban", "0143456789", "960404020404", "20"));
    p.push_back(Patient ("Zixiang", "Kelantan", "0153456789", "960505020505", "20"));
    p.push_back(Patient ("Weibin", "Batu Caves", "0163456789", "960606020606", "20"));
    p.push_back(Patient ("Chun Wei", "Kepong", "0173456789", "960707020707", "20"));
    p.push_back(Patient ("Jacky", "Sri Kembangan", "0183456789", "960808020808", "20"));

    vector <PanelP> pp;
    pp.push_back(PanelP ("Great Eastern", 90000.00, "960101020101"));
    pp.push_back(PanelP ("Media Corp.", 10000.00, "960202020202"));
    pp.push_back(PanelP ("MMU Medical", 30000.00, "960303020303"));
    pp.push_back(PanelP ("Prudential", 10000.00, "960505020505"));

    vector <Consultation> c;
    c.push_back(Consultation ("150819", "Zixiang", "960505020505","Fever", "Give panadol", 255.20));
    c.push_back(Consultation ("150320", "Kenneth", "960303020303","Stomachache", "Give Panadol", 1003.20));
    c.push_back(Consultation ("150601", "Jacky", "960808020808","Denggi", "Give Panadol", 3530.80));
    c.push_back(Consultation ("150101", "Weibin", "960606020606","Brain pain", "Give Panadol", 8001.10));


    vector <Employee> e;
    e.push_back(Employee (1001, "Boon Ping","960523021234"));
    e.push_back(Employee (1002, "Lecturer","NA"));

    do{
        displayMenu();
        cin >> menuChoice;

        if (menuChoice == "1")
        {
            do{
                displayBanner();
                cout << " ----------ENTER 0 TO BACK TO MENU!----------" << endl;
                cout << " Are you paid the bill by yourself or company? " << endl;
                cout << " 1. Yourself " << endl;
                cout << " 2. Company " << endl;
                cout << " -> ";
                cin >> YoC;
                if (YoC =="0")
                {
                    subLoop5 = false;
                    system("cls");
                }
                else if (YoC =="1")
                {
                    system("cls");
                    displayBanner();
                    cout << " You are required to create a new record. "<< endl;
                    cout << " Please enter the details below to store into system. " << endl;
                    cout << " Name          : ";
                    cin >> tempName;
                    cout << " Address       : ";
                    cin >> tempAddress;
                    cout << " Phone number  : ";
                    cin >> tempTelNo;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    cout << " Age           : ";
                    cin >> tempAge;
                    p.push_back(Patient (tempName, tempAddress, tempTelNo, tempIcNo, tempAge));
                    p[p.size()-1].display();
                    cout << " -> Your information is stored!" << endl;
                    system("pause");
                    system("cls");
                    subLoop5 = false;
                }
                else if (YoC =="2")
                {
                    system("cls");
                    displayBanner();
                    cout << " You are required to create a new record. "<< endl;
                    cout << " Please enter the details below to store into system. " << endl;
                    cout << " Please replace space with *" << endl;
                    cout << " Name          : ";
                    cin >> tempName;
                    cout << " Address       : ";
                    cin >> tempAddress;
                    cout << " Phone number  : ";
                    cin >> tempTelNo;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    cout << " Age           : ";
                    cin >> tempAge;
                    cout << " Employer name : ";
                    cin >> tempNameEmp;
                    cout << " Max amount paid by company :";
                    cin >> tempmAmount;
                    pp.push_back(PanelP (tempNameEmp, tempmAmount, tempIcNo));
                    p.push_back(Patient (tempName, tempAddress, tempTelNo, tempIcNo, tempAge));
                    p[p.size()-1].display();
                    pp[pp.size()-1].display();
                    cout << " -> Your information is stored!" << endl;
                    system("pause");
                    system("cls");
                    subLoop5 = false;
                }
                else
                {
                    cout << "Please enter your choice properly! (Number from 0 - 3)" << endl;
                    system("pause");
                    system("cls");
                }
            }while (subLoop5 == true);
        }
        else if (menuChoice == "2")
        {
            do{
                subLoop1 = true;
                displayPageP();
                cin >> choiceP;
                if (choiceP == "1")
                {
                    cout << " Please enter the requirement to search the record : " << endl;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    searchPinfo(tempIcNo, p);
                    searchPpanel(tempIcNo, pp);
                    system("pause");
                    system("cls");
                }
                else if (choiceP =="2")
                {
                    cout << " Please enter the requirement to search the record : " << endl;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    searchPinfo(tempIcNo, p);
                    system("pause");
                    if (missI == false)
                    {
                        do{
                            system("cls");
                            searchPinfo(tempIcNo, p);
                            cout << " Which details you want to update? (Number 1-5)" << endl;
                            cout << " -> ";
                            cin >> choicePU;
                            if (choicePU == "1"|| choicePU == "2"|| choicePU == "3"|| choicePU == "4"|| choicePU == "5")
                            {
                                cout << " Please enter your info that you want to change : " << endl;
                                cout << " Please replace space with *" << endl;
                                cout << " -> ";
                                cin >> tempInfo;
                                changeInfo(choicePU, tempIcNo, tempInfo, p);
                                subLoop3 = false;
                            }
                            else
                            {
                                cout << "Please enter your choice properly! (Number from 1 - 5)" << endl;
                                system("pause");
                                system("cls");
                            }
                        }while(subLoop3 == true);

                    }
                }
                else if (choiceP == "3")
                {
                    cout << " Please enter the requirement to search the record : " << endl;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    searchPvisit(tempIcNo, c);
                    system("pause");
                    system("cls");
                }
                else if (choiceP == "4")
                {
                    displayBanner();
                    cout << " Please enter the details below to store into system. " << endl
                         << " Please replace space with *" << endl
                         << " Example for date -> 161231 (Year Month Day) " << endl;
                    cout << " Date          : ";
                    cin >> tempDate;
                    cout << " Name          : ";
                    cin >> tempName;
                    cout << " IC number     : ";
                    cin >> tempIcNo;
                    cout << " Diagnosis     : ";
                    cin >> tempDiagnosis;
                    cout << " Prescription  : ";
                    cin >> tempPrescription;
                    cout << " Fee           : ";
                    cin >> tempFee;
                    c.push_back(Consultation (tempDate, tempName, tempIcNo, tempDiagnosis, tempPrescription, tempFee));
                    c[c.size()-1].display();
                    cout << " -> Your information is stored!" << endl;
                    system("pause");
                    system("cls");

                }
                else if (choiceP == "0")
                {
                    system("cls");
                    subLoop1 = false;
                }
                else
                {
                    cout << "Please enter your choice properly! (Number from 0 - 3)" << endl;
                    system("pause");
                    system("cls");
                }
            }while(subLoop1 == true);
        }
        else if (menuChoice =="3")
        {
            do{

                system("cls");
                displayBanner();
                cout << " ----ENTER 0 TO BACK TO MENU!----" << endl;
                cout << " Please enter your employee id : " << endl;
                cout << " -> ";
                cin >> tempEmpID;
                if (tempEmpID == 0)
                {
                    subLoop2 = false;
                    system("cls");
                }
                else if (tempEmpID == 1001 ||tempEmpID ==1002)
                {
                    missE = true;
                    searchE(tempEmpID, e);
                    system("pause");
                    system("cls");
                    do{
                        if (missE == false)
                        {
                            displayBanner();
                            cout << " Please enter your choice : \n"
                                 << " 1. Insert consultation record of patient" <<endl
                                 << " 2. Retrieve number of patient record" << endl
                                 << " 3. Retrieve consultation record of patient (Sort by name)" << endl
                                 << " 4. Retrieve consultation record of patient (Sort by date)" << endl
                                 << " 5. Save " << endl
                                 << " 6. Load " << endl
                                 << " 0. Back to menu " << endl;
                            cout << " -> ";
                            cin >> choiceE;

                            if (choiceE == "1")
                            {
                                displayBanner();
                                cout << " Please enter the details below to store into system. " << endl
                                     << " Please replace space with *" << endl
                                     << " Example for date -> 161231 (Year Month Day) " << endl;
                                cout << " Date          : ";
                                cin >> tempDate;
                                cout << " Name          : ";
                                cin >> tempName;
                                cout << " IC number     : ";
                                cin >> tempIcNo;
                                cout << " Fee           : ";
                                cin >> tempFee;
                                c.push_back(Consultation (tempDate, tempName, tempIcNo, tempFee));
                                c[c.size()-1].displayE();
                                cout << " -> Your information is stored!" << endl;
                                system("pause");
                                system("cls");
                            }
                            else if (choiceE == "2")
                            {
                                displayBanner();
                                cout << " We have " << p.size() << " patient in system." << endl;
                                cout << " First row is name, second row is IC number." << endl;
                                for(int i=0; i < p.size(); i++)
                                {
                                    int num = 0;
                                    num = i+1;
                                    cout << " " << num << ". ";
                                    p[i].displayE();
                                    cout << endl;
                                }
                                system("pause");
                            }

                            else if (choiceE == "3")
                            {
                                displayBanner();
                                sort(c.begin(), c.end(), compareN);
                                for (int i=0; i<c.size(); i++)
                                {
                                    c[i].displayAll();
                                }
                                system("pause");
                                system("cls");
                            }
                            else if (choiceE == "4")
                            {
                                displayBanner();
                                sort(c.begin(), c.end(), compareD);
                                for (int i=0; i<c.size(); i++)
                                {
                                    c[i].displayAll();
                                }
                                system("pause");
                                system("cls");
                            }
                            else if (choiceE == "5")
                            {
                                ofstream patientFile,consultationFile;
                                patientFile.open("Patient.txt");
                                consultationFile.open("Consultation.txt");
                                for (int i=0; i<p.size(); i++)
                                {
                                    patientFile << " Patient : " << p[i].getName() << "     " << p[i].getAddress() << "     " << p[i].getTelNo()<< "     " << p[i].getIcNo() << "     " << p[i].getAge() << endl;
                                }
                                for (int i=0; i<pp.size(); i++)
                                {
                                    patientFile << " Panel : " << pp[i].getNameEmp() << "     " << pp[i].getmAmount() << endl;
                                }
                                for (int i=0; i<c.size(); i++)
                                {
                                    consultationFile << " Visit consultation : " << c[i].getDate() << "     "  << c[i].getName() << "     "  << c[i].getIcNo() << "     "  << c[i].getDiagnosis() << "     "  << c[i].getPrescription() << "     "  << c[i].getFee() << endl;
                                }
                                for (int i=0; i<c.size(); i++)
                                {
                                    consultationFile << " Daily consultation : " << c[i].getDate() << "     " << c[i].getName() << "     " << c[i].getFee() << endl;
                                }
                                displayBanner();
                                cout << " Two text file is created. \n"
                                     << " 1. Patient record is saved into Patient.txt. \n\n"
                                     << " 2. Consultation record is saved into Consultation.txt. \n\n";
                                system("pause");
                            }
                            else if (choiceE =="0")
                            {
                                subLoop6 = false;
                                subLoop2 = false;
                                system("cls");
                            }
                            else
                            {
                                cout << "Please enter your choice properly! (Number from 0 - 3)" << endl;
                                system("pause");
                                system("cls");
                            }
                        }
                    }while(subLoop6== true);
                }
                else
                {
                    cout << "Please enter your choice properly! (Number from 0 - 3)" << endl;
                    system("pause");
                    system("cls");
                }
            }while(subLoop2 == true);


        }
        else if (menuChoice =="0")
        {
            menuLoop = false;
        }
        else
        {
            cout << "Please enter your choice properly! (Number from 0 - 3)" << endl;
            system("pause");
            system("cls");
        }
    }while(menuLoop == true);
}











void displayMenu()
{
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " Welcome to our clinic.\n"
         << " ----------------------\n"
         << " Please enter your choice : \n"
         << " 1. New patient\n"
         << " 2. Existing patient\n"
         << " 3. Employee \n"
         << " 0. Exit\n"
         << " -> ";
}

void displayPageP()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n"
         << " Please enter your choice : \n"
         << " 1. Retrieve the basic information \n"
         << " 2. Update the record \n"
         << " 3. Retrieve visit record \n"
         << " 4. Update visit record \n"
         << " 0. Back to menu \n"
         << " -> ";


}

void displayBanner()
{
    system("cls");
    cout << "           -------------------------------------\n"
         << "           ---- PATIENT MANAGEMENT SYSTEM ------\n"
         << "           -------------------------------------\n\n";

}

void searchPinfo(string Ic, vector <Patient> p)
{
    missI = true;
    for (int i=0; i<p.size(); i++)
    {
        if (Ic == p[i].getIcNo())
        {
            p[i].display();
            missI = false;
        }
    }

    if (missI == true)
    {
        cout << " -> Your record are missing!" << endl;
    }


}

void searchPvisit(string Ic, vector <Consultation> c)
{
    for (int i=0; i<c.size(); i++)
    {
        if (Ic == c[i].getIcNo())
        {
            c[i].display();
            missV = false;
        }
    }

    if (missV == true)
    {
        cout << " -> Your record are missing!" << endl;
    }
}

void searchPpanel(string Ic,vector <PanelP> pp)
{
    for (int i=0; i<pp.size(); i++)
    {
        if (Ic == pp[i].getIcNo())
        {
            pp[i].display();
        }
    }
}

void changeInfo(string ChoicePU, string Ic, string Info, vector <Patient>& p)
{
    for (int i=0; i<p.size(); i++)
    {
        if (Ic == p[i].getIcNo())
        {
            if (ChoicePU == "1")
            {
                system("pause");
                p[i].setName(Info);
            }
            if (ChoicePU == "2")
            {
                system("pause");
                p[i].setAddress(Info);
            }
            if (ChoicePU == "3")
            {
                system("pause");
                p[i].setTelNo(Info);
            }
            if (ChoicePU == "4")
            {
                system("pause");
                p[i].setIcNo(Info);
            }
            if (ChoicePU == "5")
            {
                system("pause");
                p[i].setAge(Info);
            }
        }
    }
}

void searchE(int Ic, vector<Employee> e)
{
    for (int i=0; i<e.size(); i++)
    {
        if (Ic == e[i].getEmpID())
        {
            e[i].display();
            missE = false;
        }
    }

    if (missE == true)
    {
        cout << " -> Your record are missing!" << endl;
    }
}
