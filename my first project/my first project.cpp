#include <iostream>
#include<string>
using namespace std;

enum Day {
    Friday, Saturday, Sunday, Monday, Tuesday, Wednesday, Thrusday
};
struct Time {
    int hours, minutes, seconds;
};
struct Date {
    int year, month;
    Day day;
};
union Salary {
    float dollar, pounds;
};
struct expireyDATE {
    int year, month;
    Day day;
};
class Object {
protected:
    int ID;
    string name;
public:
    Object() {
        ID = 0;
        name = "";
    }
    Object(int id, string N) {
        ID = id;
        name = N;
    }

    void setobject(int id, string n) {
        ID = id;
        name = n;
    }
    int getid() {
        return ID;
    }
    string getname() {
        return name;
    }
    void display() {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
    }

};

class Doctor :public Object {
private:
    Date startdate;
    Time starttime;
    Salary salary;
public:
    Doctor() {
        ID = 0;
        name = "";
        startdate = { 2018, 8, Monday };
        starttime = { 0, 0, 0 };
        salary.pounds = 0;
    }
    Doctor(Date d, Time t, float s) {
        startdate = d;
        starttime = t;
        salary.dollar = s;
    }
    ~Doctor() {
        cout << "I am destructor \n";

    }
    void setD(int id, string n, Date d, Time t, float s) {
        Object::setobject(id, n);
        startdate = d;
        starttime = t;
        salary.dollar = s;
    }
    Date getSD() {
        return startdate;
    }
    Time getST() {
        return starttime;
    }
    Salary getsalary() {
        return salary;

    }
    void display() {
        Object::display();
        cout << "Start Date: " << startdate.year << "/" << startdate.month << "/" << startdate.day << endl;
        cout << "Start Time: " << starttime.hours << ":" << starttime.minutes << ":" << starttime.seconds << endl;
        cout << "Salary: " << salary.dollar << " dollars" << endl;
    }

};
class Medicine :public Object {
private:
    float UnitPrice;
    int Quantity;
    Date Expirydate;
    string Usage;
    string Classification;
    string SideEffects;
    float Concentration;
public:
    Medicine() {
        ID = 00;
        name = "";

        UnitPrice = 0;
        Quantity = 0;
        Usage = "";
        Expirydate = { 2029, 5, Monday };
        Classification = "";
        SideEffects = "";
        Concentration = 0;
    }
    Medicine(float UP, int Q, Date EX, string U, string c, string S, float ct) {
        UnitPrice = UP;
        Quantity = Q;
        Usage = U;
        Expirydate = EX;
        Classification = c;
        SideEffects = S;
        Concentration = ct;
    }

    void setm(int id, string n, float UP, int Q, Date EX, string U, string c, string S, float ct)
    {
        Object::setobject(id, n);
        UnitPrice = UP;
        Quantity = Q;
        Usage = U;
        Expirydate = EX;
        Classification = c;
        SideEffects = S;
        Concentration = ct;
    }
    float getUnitPrice() {
        return UnitPrice;
    }
    int getQuantity() {
        return Quantity;
    }
    Date getExpiryDate() {
        return Expirydate;
    }
    string getUsage() {
        return Usage;
    }
    string getClassification() {
        return Classification;
    }
    string getSideEffects() {
        return SideEffects;
    }
    float getConcentration() {
        return Concentration;
    }
    void display() {
        Object::display();
        cout << "Unit Price is: " << UnitPrice << " dollar" << endl;
        cout << "Quantity is : " << Quantity << endl;
        cout << "Expiry Date is : " << Expirydate.year << "/" << Expirydate.month << "/" << Expirydate.day << endl;
        cout << "Usage is : " << Usage << endl;
        cout << "Classificationm is :  " << Classification << endl;
        cout << "Side Effects is : " << SideEffects << endl;
        cout << "Active Material Concentrationis : " << Concentration << " ml" << endl;
    }

};

int main() {
    Object O;
    Doctor D;
    Medicine M;

    cout << "-----------------------------------------" << endl;
    cout << "        Pharmacy Management System     " << endl;
    cout << "-----------------------------------------" << endl;

    // Doctor Data
    cout << "Doctor Information Form" << endl;
    int DoctorID;
    cout << "Enter Doctor ID:" << endl;
    cin >> DoctorID;
    cin.ignore();

    string DoctorNAME;
    cout << "Enter Doctor Name in English please: " << endl;
    getline(cin, DoctorNAME);

    Date doctorDate;
    cout << "Enter Start Date (year month day as number 0-Friday ... 6-Thursday): " << endl;
    cin >> doctorDate.year >> doctorDate.month >> (int&)doctorDate.day;

    cout << "Enter Start Time (hours minutes seconds): " << endl;
    Time DoctorTime;
    cin >> DoctorTime.hours >> DoctorTime.minutes >> DoctorTime.seconds;

    float DoctorSalary;
    cout << "Enter Salary: " << endl;
    cin >> DoctorSalary;

    D.setD(DoctorID, DoctorNAME, doctorDate, DoctorTime, DoctorSalary);

    cout << "Doctor Information:" << endl;
    D.display();
    cout << "-----------------------------------------" << endl;


    cout << "Medicine Registration" << endl;

    int MEDID, MEDQuantity, MEDEXPYear, MEDEXPMonth, MEDEXPDay;
    string MEDName, MEDusage, MEDclassification, MEDsideEffects;
    float MEDprice, MEDconcentration;

    cout << "Enter Medicine ID: " << endl;
    cin >> MEDID;
    cin.ignore();

    cout << "Enter Medicine Name in English: " << endl;
    getline(cin, MEDName);

    cout << "Enter Unit Price: " << endl;
    cin >> MEDprice;

    cout << "Enter Quantity: " << endl;
    cin >> MEDQuantity;

    cout << "Enter Expiry Date (year month day as number 0-Friday ... 6-Thursday): " << endl;
    cin >> MEDEXPYear >> MEDEXPMonth >> MEDEXPDay;
    cin.ignore();

    cout << "Enter Therapeutic Indications: " << endl;
    getline(cin, MEDusage);

    cout << "Enter Classification(Category): " << endl;
    getline(cin, MEDclassification);

    cout << "Enter Side Effects: " << endl;
    getline(cin, MEDsideEffects);

    cout << "Enter Active Material Concentration (ml): " << endl;
    cin >> MEDconcentration;

    Date expDate = { MEDEXPYear, MEDEXPMonth, (Day)MEDEXPDay };
    M.setm(MEDID, MEDName, MEDprice, MEDQuantity, expDate, MEDusage, MEDclassification, MEDsideEffects, MEDconcentration);

    cout << "Medicine Information:" << endl;
    M.display();

    cout << "\n===== Data Saved Successfully =====\n";

    return 0;
}


