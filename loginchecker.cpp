#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class student{
	char name[50],email[70],password[20];
	public:
		void olddata();
		void newdata();
		string emailid();
		
};
void student::olddata()
{
	int value=0;
	char line[80];
	cout<<"Enter your email id\n";
	cout<<"email id: ";
	cin>>email;
	ifstream fin("record.txt");
	while(fin)
	{
		fin.getline(line,80);
	    if(strcmp(line,email)==0)
	    {
	    	cout<<"WELCOME!!\n\n";	
		    cout<<"Email is verified,you can proceed!!\n";
            value=1;
	
		}
	}
	if(value!=1)
	{
	    cout<<"Email id didn't match,try again...\n\n\n";	
	    olddata();

	}
	fin.close();
}
void student::newdata()
{
	cout<<"Enter your name\n";
	cout<<"Name: ";
	cin>>name;
	cout<<"Please submit your email id,this id will used next time you login\n";
	cout<<"email id: ";
	cin>>email;
	ofstream fout("record.txt",ios::app);
	fout<<name<<endl<<email<<endl<<endl;
	cout<<"You have successfully created your account!!\n";
	fout.close();

}
string student::emailid()
{
	return email;
}
int main()
{
	string id;
	student s1;
	cout<<"Hey student!!\n";
	cout<<"Press 1 if you have already an account else press 2 if you are a new student: ";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		s1.olddata();
	}
	else if(choice==2)
	{
		s1.newdata();
		
	}
	cout<<"\n\nWe provide study material for 2 classes:- 11th and 12th----------Press 1 or 2 accordingly: ";
	int Choice;
	cin>>Choice;
	if(Choice==1)
	{
		cout<<"We have the following streams:\n";
		cout<<"a) Science\nb) Commerce\nc) Arts\n";
		cout<<"Choose a, b or c:";
		char ch;
		cin>>ch;
		switch(ch)
			{
				case 'a':
					{
						id=s1.emailid();
						ofstream outf("11_science.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 11th SCIENCE stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}
				case 'b':
					{
						id=s1.emailid();
						ofstream outf("11_commerce.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 11th COMMERCE stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}
				case 'c':
					{
						id=s1.emailid();
						ofstream outf("11_arts.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 11th ARTS stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}

			}

	}
	else if(Choice==2)
	{
		cout<<"We have the following streams:\n";
		cout<<"a) Science\nb) Commerce\nc) Arts\n";
		cout<<"Choose a, b or c:";
		char Ch;
		cin>>Ch;
		switch(Ch)
			{
				case 'a':
					{
						id=s1.emailid();
						ofstream outf("12_science.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 12th SCIENCE stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}

				case 'b':
					{
						id=s1.emailid();
						ofstream outf("12_commerce.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 12th COMMERCE stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}
					
				case 'c':
					{
						id=s1.emailid();
						ofstream outf("12_arts.txt",ios::app);
						outf<<id;
						outf<<endl;
						outf.close();
						cout<<"\nContent for class 12th ARTS stream will be sent to your registered email id ASAP.\n";
						cout<<"\nThanks for visiting here!!!\n";
						break;
					}
					
			}

		
	}
	else
	{
		cout<<"\nWrong choice!";
	}
}
