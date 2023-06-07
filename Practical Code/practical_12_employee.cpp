#include <fstream>
// #include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>


using namespace std;
class student
{
    int rollno;
    char name[20];
    char branch[3];
    float marks;
    char grade;

public:
    void getdata()
    {
        cout << "Rollno: ";
        cin >> rollno;
        cout << "Name: ";
        cin >> name;
        cout << "Branch: ";
        cin >> branch;
        cout << "Marks: ";
        cin >> marks;
        if (marks >= 75)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
            
 
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }
    void putdata()
    {
        cout << "Rollno: " << rollno << "\tName: " << name << "\n";
        cout << "Marks: " << marks << "\tGrade: " << grade << "\n";
    }
    int getrno()
    {
        return rollno;
    }
    void modify();
} stud1, stud;

void student::modify()
{
    cout << "Rollno: " << rollno << "\n";
    cout << "Name: " << name << "\tBranch: " << branch << "\tMarks: " << marks << "\n";
    cout << "Enter new details.\n";
    char nam[20] = " ", br[3] = " ";
    float mks;
    cout << "New name:(Enter '.' to retain old one): ";
    cin >> nam;
    cout << "New branch:(Press '.' to retain old one): ";
    cin >> br;
    cout << "New marks:(Press -1 to retain old one): ";
    cin >> mks;
    if (strcmp(nam, ".") != 0)
    {
        strcpy(name, nam);
    }
    if (strcmp(br, ".") != 0)
    {
        
    strcpy(branch, br);
    }
    if (mks != -1)
    {
        marks = mks;
        if (marks >= 75)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }
    }
}

int main()
{
    // clrscr();
    fstream fio("marks.dat", ios::in | ios::out);
    char ans = 'y';
    while (ans == 'y' || ans == 'Y')
    {
        stud1.getdata();
        fio.write((char *)&stud1, sizeof(stud1));
        cout << "Record added to the file\n";
        cout << "\nWant to enter more ? (y/n)..";
        cin >> ans;
    }
    // clrscr();
    int rno;
    long pos;
    char found = 'f';
    cout << "Enter rollno of student whose record is to be modified: ";
    cin >> rno;
    fio.seekg(0);

    while (!fio.eof())
    {
        pos = fio.tellg();
        fio.read((char *)&stud1, sizeof(stud1));
        if (stud1.getrno() == rno)
        {
            stud1.modify();
            fio.seekg(pos);
            fio.write((char *)&stud1, sizeof(stud1));
            found = 't';
            break;
        }
    }

    if (found == 'f')
    {
        cout << "\nRecord not found in the file..!!\n";
        cout << "Press any key to exit...\n";
        // getch();
    }

    fio.seekg(0);
    cout << "Now the file contains:\n";
    while (!fio.eof())
    {
        fio.read((char *)&stud, sizeof(stud));
        stud.putdata();
    }
    fio.close();

    // getch();
    return 0;
}
