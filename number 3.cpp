#include <iostream>
using namespace std;
class Person
{
private:
    string name;

public:

    Person(string a)
    {
        name = a;
    }


    string getName()
    {
        return name;
    }

};
class Student : public Person
{
private:
    string id;
    int marks = 0;
public:
    Student(string name) : Person(name) {}
    Student(string name, string b) : Person(name)
    {
        id = b;
    }


    void operator+(int n)
    {
        marks+=n;
    }
    void showMarks()
    {
        cout<<marks<<endl;
    }
};

int countVote(string name)
{
    cout<<"\nEnter the likeness (range from 1 to 5) for "<<name<<" : ";
    int n;
    cin>>n;
    while(1)
    {
        if(n<=5 and n>0) return n;
        else
        {
            cout<<"Invalid likeness number\n";
            cout<<"\nEnter the (valid)likeness (range from 1 to 5) for "<<" : ";
            cin>>n;
        }

    }

}

int main()
{
    Student student[5]=
    {
        Student("jamal"),
        Student("rashed"),
        Student("shuvu"),
        Student("zakir"),
        Student("zamayla"),
    };
    cout<<"Here are the 5 selected student, they will be voted.\n\n";

    for( int i=0; i<5; i++) cout<<i+1<<". "<<student[i].getName()<<endl;

    while(1)
    {
        cout<<"If you want to vote as a student type 's'.\nIf you want to vote as a teacher type 't'.\n";
        cout<<"(if you want to exit  type 'c' anytime)"<<endl;
        string str;
        cin>>str;
        if(str == "c")
        {
            for(int i=0; i<5; i++)
            {
                cout<<student[i].getName() <<" == ";
                student[i].showMarks();
            }
            break;
        }
        else if(str == "s" || str =="t")
        {
            if(str == "s") cout<<"Voting as a student\n";
            if(str == "t") cout<<"Voting as a teacher\n";
            cout<<"Enter student's serial number for whom you want to vote: ";
            int n;
            cin>>n;
            n--;

            while(1)
            {
                if(n<5 and n>=0)
                {
                    int a= countVote(student[n].getName());

                    student[n] + a;
                    break;
                }
                else
                {
                    cout<<"Invalid serial number.\n";
                    cout<<"Enter student's (valid) serial number for whom you want to vote: ";
                    cin>>n;
                }
            }
        }
        else
        {
            cout<<"Invalid character\n";
        }
    }

    return 0;

}
