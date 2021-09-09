#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;




class PW
{
	private:
		char lol[100];
		int lop;
		char adminpw[20];
		char enduserpw[20];
		char lox[20];
	public:
	
		string pwadmin()
		{
			ifstream readPW;
			
			readPW.open("settings\\adminpw.dat",ios::in|ios::binary);
			readPW.read((char *)this,sizeof(*this));
			return adminpw;
			
		}
		string pwuser()
		{
			ifstream readPW;
			
			readPW.open("settings\\userpw.dat",ios::in|ios::binary);
			readPW.read((char *)this,sizeof(*this));
			return enduserpw;
		}
		void setPwadmin()
		{
			
			ofstream fwrite;
			fwrite.open("adminpw.dat",ios::out|ios::binary);
			string pass ="";
		   	char ch;
			cout<<"\t Enter The new Password: ";
			
			   ch = _getch();
			   while(ch != 13)
			   {//character 13 is enter
			      pass.push_back(ch);
			      cout << '*';
			      ch = _getch();
			   }
			strcpy(adminpw,pass.c_str());
			fwrite.write((char *)this,sizeof(* this));
		   	cout<<"\n\t Password changed Successfully.";
			cout<<"\n\t Press Any key....";
			getch();
		   
		}
		void setPwuser()
		{
			ofstream fwrite;
			fwrite.open("userpw.dat",ios::out|ios::binary);
			string pass ="";
		   	char ch;
			cout<<"\t Enter The new Password: ";
			
		   ch = _getch();
		   while(ch != 13){//character 13 is enter
		      pass.push_back(ch);
		      cout << '*';
		      ch = _getch();
		   }
			strcpy(enduserpw,pass.c_str());
			fwrite.write((char *)this,sizeof(* this));
		   	cout<<"\n\t Password changed Successfully.";
			cout<<"\n\t Press Any key....";
			getch();
		}
		
	
};
int main()
{
	PW a;
	char ch;
	cout<<"Developer Mode\n"
		<<"1. change Admin pw\n"
		<<"2. change End-User\n"
		<<"Enter your choice....";
		cin>>ch;
	switch(ch)
	{
		case '1':
			a.setPwadmin();
			break;
		case '2':
			a.setPwuser();
			break;
	}		
	return 0;
}
