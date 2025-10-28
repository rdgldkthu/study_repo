/*
    제휴 관계 Association
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor; // forward declaration

class Patient
{
private:
    string m_name;
    vector<Doctor*> m_doctors;

public:
    Patient(const string& name_in)
        : m_name(name_in)
    {}

    void addDoctor(Doctor* new_doctor)
    {
        m_doctors.push_back(new_doctor);
    }

    void meetDoctors();
    
    friend class Doctor;
};

class Doctor
{
private:
    string m_name;
    vector<Patient*> m_patients;

public:
    Doctor(const string& name_in)
        : m_name(name_in)
    {}

    void addPatient(Patient* new_patient)
    {
        m_patients.push_back(new_patient);
    }

    void meetPatients()
    {
        for (auto& pat : m_patients)
        {
            cout << "Meet patient : " << pat->m_name << endl;
        }
    }

    friend class Patient;
};

void Patient::meetDoctors()
{
    for (auto& doc : m_doctors)
    {
        cout << "Meet doctor : " << doc->m_name << endl;
    }
}

int main()
{
    Patient* p1 = new Patient("Jack Jack");
    Patient* p2 = new Patient("Dash");
    Patient* p3 = new Patient("Violet");

    Doctor* d1 = new Doctor("Dr. K");
    Doctor* d2 = new Doctor("Dr. L");

    p1->addDoctor(d1);
    d1->addPatient(p1);

    p2->addDoctor(d2);
    d2->addPatient(p2);

    p2->addDoctor(d1);
    d1->addPatient(p2);

    p1->meetDoctors();

    d1->meetPatients();

    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0;
}