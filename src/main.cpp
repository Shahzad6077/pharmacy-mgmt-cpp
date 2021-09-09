#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
#include <windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
int todaydate, year, month, day,GlobleDay,GlobleMonth,GlobleYear;
int Toint(std::string s) //The conversion function
{
    return atoi(s.c_str());
}

void showdate(long yyyymmdd)//ye function yar date ko number mai ly kr year month day ko extrct krwa kr seperate variables mai rakhwa raha hai.
{
	
	year=int(yyyymmdd/10000.0); //extrct year
	month=int((yyyymmdd-year*10000.0)/100.0); //extrct the month
	day=int(yyyymmdd-year*10000.0-month*100.0); //extrct day
	
}
void dateExtrctor(long yyyymmdd, int found=0)
{
	if(found==0)
	{
		GlobleYear=int(yyyymmdd/100.0); //extrct year
		//cout<<"Year "<<GlobleYear;
		GlobleMonth=int(yyyymmdd%100); //extrct the month
		//cout<<"Month "<<GlobleMonth;
	}
	if(found==1)
	{
		GlobleYear=int(yyyymmdd/10000.0); //extrct year
		GlobleMonth=int((yyyymmdd-GlobleYear*10000.0)/100.0); //extrct the month
		GlobleDay=int(yyyymmdd-GlobleYear*10000.0-GlobleMonth*100.0); //extrct day
	}
	
}
void InputDate();
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

// this class is for rough use bcz variable of this class is use various location i.e like in file handling.

class rough
{
	
	private:
		float profits;
	public:
		rough()
		{
			profits=0.0;
		 } 
		float getf()
		{
			return profits;
		}
		void set(float p)
		{
			profits=p;
		}
};
// bills record ko save wgra k liye 
class IDbill
{
	public:
	char id[20];
	int quantity;
	
	void inputId()
	{
		cin.getline(id,19);
	}
	int inputQTY()
	{
		char qty[20];
		quantity=-6767;
		cout<<"Enter the Quantity: ";
		cin.getline(qty,10);
		quantity= atoi(qty);
		//cin>>quantity;
		return quantity;
	}
	string getID()
	{
		return id;
	}
	int getquantity()
	{
		return quantity;
	}
	void setId(const char *s)
	{
		strcpy(id,s);
	}
	
};
// security wali class---------------------------------------------------------.
class PW
{
	private:
		char lol[100];
		int lop;
		char adminpw[20];
		char enduserpw[20];
		char lox[20];
	public:
	/*	PW()
		{
			strcpy(lol,"hahaha please close this file, if you don\'t close it , you COMP will shutdown automateicly");
			strcpy(lox,"When dear old Mrs. Hay went back to town after staying with the Burnells she sent the children a doll's house. It was so big that the carter and Pat carried it into the courtyard, and there it stayed, propped up on two wooden boxes beside the feed-room door. No harm could come of it; it was summer. And perhaps the smell of paint would have gone off by the time it had to be taken in");
			lop=2132;
		} */
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
			fwrite.open("settings\\adminpw.dat",ios::out|ios::binary);
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
			fwrite.open("settings\\userpw.dat",ios::out|ios::binary);
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
//------------------------------------------------------------------------------
// ye medicine wali class hogi ab..
class Medicine
{
	private:
		char id[14];
		char name[20];
		char company[10];
		int mfg_date;
		int exp_date;
		int quantity;
		long retailPrice;
		long price;
		
	public:
		void insetStockMed()
		{
			char mgf[12],exp[12],qty[10],rp[10],p[10];
			int x;
			cout<<"Enter Id: ";
			cin.ignore();
			cin.getline(id,13);
			cout<<"Enter the Name: ";
			cin.getline(name,19);
			cout<<"Enter the Company Name: ";
			cin.getline(company,9);
		
			a:
			x=0;
			cout<<"Enter the Manufacturing Date (yyyymmdd) : ";
			cin.getline(mgf,11);
			x=Toint(mgf);
			if(x==0 || x<0)
			{
				cout<<"Invalid..!\n";
				goto a;
			}
			mfg_date=x;
			b:
			x=0;
			cout<<"Enter the Expiry Date (yyyymmdd) : ";
			cin.getline(exp,11);
			x=Toint(exp);
			if(x==0 || x<0)
			{
				cout<<"Invalid..!\n";
				goto b;
			}
			exp_date=x;
			c:
			x=0;
			cout<<"Enter the Quantity: ";
			cin.getline(qty,8);
			x=Toint(qty);
			if(x==0 || x<0)
			{
				cout<<"Invalid..!\n";
				goto c;
			}
			quantity=x;
			d:
			x=0;
			cout<<"Enter the Retail price: ";
			cin.getline(rp,8);
			x=Toint(rp);
			if(x==0 || x<0)
			{
				cout<<"Invalid..!\n";
				goto d;
			}
			retailPrice=x;
			e:
			x=0;
			cout<<"Enter the Price: ";
			cin.getline(p,8);
			x=Toint(p);	
			if(x==0 || x<0)
			{
				cout<<"Invalid..!\n";
				goto a;
			}
			price=x;
			
			
		}	
		void showitems()
		{
			cout<<" ";
			//cout<<left<<setw(10)<<"ID"<<left<<setw(15)<<"Name"<<left<<setw(13)<<"Company"<<left<<setw(7)<<"QTY()"<<left<<setw(10)<<"mfg_date"<<left<<setw(10)<<"exp_date"<<left<<setw(8)<<"R_Price"<<left<<"Price"<<endl;
		//	showdate(mfg_date);
		//	std::cout<<"  ";
		//	showdate(exp_date);
		//	std::cout<<"  ";
			std::cout<<std::left<<std::setw(10)<<id<<std::left<<std::setw(13)<<name<<std::left<<std::setw(11)<<company<<std::left<<std::setw(8)<<quantity<<std::left<<std::setw(10)<<mfg_date<<std::left<<std::setw(10)<<exp_date<<std::right<<std::setw(7)<<retailPrice<<std::right<<setw(6)<<price<<std::endl;
		}
		void showtab()
		{
			cout<<left<<setw(15)<<"ID"<<id<<endl
				<<left<<setw(15)<<"Name"<<name<<endl
				<<left<<setw(15)<<"Company"<<company<<endl
				<<left<<setw(15)<<"Quantity"<<quantity<<endl
				<<left<<setw(15)<<"MFG Date"<<mfg_date<<endl
				<<left<<setw(15)<<"EXP Date"<<exp_date<<endl
				<<left<<setw(15)<<"Retail Price"<<retailPrice<<endl
				<<left<<setw(15)<<"Price"<<price<<endl;
		}
		string getID()
		{
			return id;
		}
		string getName()
		{
			return name;
		}
		int getExpDate()
		{
			return exp_date;
		}
		int getQty()
		{
			return quantity;
		}
		int getRprice()
		{
			return retailPrice;
		}
		int getPrice()
		{
			return price;
		}
		void setID(char *a)
		{
			strcpy(id,a);
		}
		void setName(char *a)
		{
			strcpy(name,a);
		}
		void setCompny(char *a)
		{
			strcpy(company,a);
		}
		void setMfg(int n)
		{
			mfg_date=n;
		}
		void setExp(int n)
		{
			exp_date=n;
		}
		void setQty(int n)
		{
			quantity=n;
		}
		void setRprice(int n)
		{
			retailPrice=n;
		}
		void setPrice(int n)
		{
			price=n;
		}
	
};


// yes function sb takreeban security or menu sy related hain.
void loading();
void wlcmpage();
void titleWLCM();
int securityCHK(int n);
int controlpanal();
void settingAcount();
int AdminMenu();
int WorkerMenu();
void box(int left, int top, int right, int bottom);
//ye function sales records k liye
void RecordOfSale(IDbill id_q[5000] , int indexStore, char name[35],float t);
void SellingReport();
void DateBYdateRecord(char nameOfRecord[100]);
void ProfitRecord(float p);
void showProfit();
void checksale();
// ye functions ab wo hai jo medicine k stocks sy related hai or unki functionalty ko perform krny k liye.

void ShowAllstock();
void InsertItem();
void FindItem();
void DeleteItem();
void Updateitem();
void notification();
void BuyMedicine();



int main()
{
	
	box(20,3,62,6);
	wlcmpage();
	loading();
	top1:
	
	int choiceAccount,check;
	titleWLCM();
	choiceAccount=controlpanal();
	switch(choiceAccount)
	{
		case 1:
			check=AdminMenu();
			if( check == 1)
				break;
			else if( check == 0 )
				goto end;
		
		case 2:
			check=WorkerMenu();
			if( check == 1)
				break;
			else if( check == 0 )
				goto end;
		case 0:
			goto end;
	/*	default:
			cout<<"Wrong Choice Entered...!";
			cout<<"Press any key to Be Continue.....";
			getch(); */
	}
	goto top1;
	end:
		cout<<"\n\t\t      Turning OFF Program..\n"
			<<"\t\t      Press any key........";
	return 0;
}
void titleWLCM()
{
	cout<<"\n\n\t\t-------------------------------------------"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t|  Welcome To Pharmacy Management System  |"<<endl;
	cout<<"\t\t|                                         |"<<endl;
	cout<<"\t\t-------------------------------------------"<<endl<<endl;
	
}

void box(int left, int top, int right, int bottom)
{
	//box(20,8,60,11);
	int  i;

	system("cls");
	gotoXY(left,top);
	cout<<char(218);
	for( i=0; i<right-left-1; i++)
	{
		cout<<char(196);
	}
	cout<<char(191);
	
	for(i=1; i<bottom-top; i++)
	{
		gotoXY(left, top+i);
		cout<<char(179);
		gotoXY(right, top+i);
		cout<<char(179);
	}
	
	gotoXY(left, bottom);
		cout<<char(192);
	
	for( i=0; i<right-left-1; i++)
	{
		cout<<char(196);
	}
	cout<<char(217);
	
	
}

int securityCHK(int n)
{
	int wrongtimes=0;
	again:
	PW password;
	string pass="";
	char ch;
	
	if(n==1)
	{

	   cout << "\n\t\t     Enter the PassWord: ";
	   ch = _getch();
	   while(ch != 13)
	   {//character 13 is enter
	      pass.push_back(ch);
	      cout << '*';
	      ch = _getch();
	   }
	   if(pass==password.pwadmin())
	   {
	   		cout<<"\n\t\t     ACCESS is granted.\n";
	   		cout<<"\n\t\t     Press any Key....";
	   		getch();
	   		return 111;
	   }
	   else
	   {
			
	   		cout<<"\n\t\t     You Entered Wrong password: ";
	   		goto again;
	   }
	}
	else if(n==2)
	{
		cout << "\n\t\t     Enter the PassWord: ";
	   ch = _getch();
	   while(ch != 13)
	   {//character 13 is enter
	      pass.push_back(ch);
	      cout << '*';
	      ch = _getch();
	   }
		if(pass==password.pwuser())
	   {
	   		cout<<"\n\t\t     ACCESS is granted.\n";
	   		cout<<"\n\t\t     Press any Key....";
	   		getch();
	   		return 222;
	   }
	   else
	   {
			
	   		cout<<"\n\t\t     You Entered Wrong password: ";
	   		goto again;
	   }	
		
	}
}
int controlpanal()
{
	top1:
		
	system("cls");
	char choiceAcount,ch[5];
	int found=0;
	//titleWLCM();
	box(20,8,62,11);
	gotoXY(23,10);
	cout<<"     Pharmacy Management System";
	cout<<"\n\n";
	cout<<"\t\t      ";for(int line=1;line<=13;line++){cout<<char(196);}
	cout<<"Control Panel";for(int line=1;line<=13;line++){cout<<char(196);}
	cout<<"\n\n"
		<<"\t\t        1. Admin Account. \n"
		<<"\t\t        2. Workers Account. \n"
		<<"\t\t        E. Exit.\n\n"
		<<"\t\t      ";for(int line=1;line<=39;line++){cout<<char(196);}
		cout<<"\n\n"
		<<"\t\t      Enter Your Choice... : ";
		cin>>ch;
		for(int ii=1; ch[ii]!='\0';ii++)
		{
			if(ch[ii]>='1' || ch[ii]<='9' || ch[ii]>='a' || ch[ii]>='A' || ch[ii]<='z' || ch[ii]<='Z')
			{
				found=1;
			}
		}
		if(found ==0)
			choiceAcount=ch[0];
	switch(choiceAcount)
	{
		case '1':
			
			securityCHK(1);
			return 1;
			break;
		case '2':
			securityCHK(2);
			
			return 2;
			break;
		case 'e':
		case 'E':
			return 0;
			break;
		
		default:
			cout<<"\n\t\t   You Entered Wrong Choice."
				<<"\n\t\t   Press Any key.....";
				getch();
	}
	goto top1;
	


}

void wlcmpage()
{

	box(20,8,62,12);
	gotoXY(23,10);
	cout<<"Welcome To Pharmacy Management System";
	Sleep(300);
}
void loading()
{
	char ch=-79, date[12];
	int x=0;
	
	gotoXY(38,13);
	cout<<"LOADING....";
	for(int i=30; i<55 ; i++)
	{
		gotoXY(i,14);
		cout<<ch;
		for(int a=0; a<200000; a++);
	
	}
	gotoXY(28,15);
	cout<<"Press any key to continue.....";
	getch();
	InputDate();
	
}

void InputDate()
{
	system("cls");
	char date[12];
	int x;
	a:
	x=0;
	cout<<"\nPlease Enter The Today Date(yyyymmdd): ";
	cin.getline(date,11);
	x=atoi(date);
	if(x==0 || x<0)
	{
		cout<<"Invalid...!\n";
		goto a;
	}
	todaydate=x;
	showdate(todaydate);
	if( (month<=0 || month >=13) || (day<=0 || day>=32) )
	{
		cout<<"Invalid...!\n";
		goto a;
	}
	system("cls");
}

void settingAcount()
{
	top1:
	PW p;
	char choice;
	system("cls");
	cout<<"\t\t_________________________________________\n"
		<<"\t\t                SETTING               \n"
		<<"\t\t_________________________________________\n\n"
		<<"\t 1. To Change Admin Password. \n"
		<<"\t 2. To Change End-User Password. \n"
		<<"\t R. Return to Back Menu.\n"
		<<"\t Enter your Choice...: ";
	cin>>choice;
	switch(choice)
	{
		case '1':
			cout<<"\n\t ADMIN\n";
			p.setPwadmin();
			break;
		case '2':
			cout<<"\n\t END_USER\n";
			p.setPwuser();
			break;
		case 'r':
		case 'R':
			return;
			break;
		default:
			cout<<"\n\t You Entered WRONG Choice";
			cout<<"\n\t Press Any key....";
			getch();
			goto top1;
	}
	goto top1;
	
		
}

int WorkerMenu()
{
	top1:
	char choice;
	system("cls");
	
	cout<<"\t\t_________________________________________\n"
		<<"\t\t             END-USER MENU               \n"
		<<"\t\t_________________________________________\n";
	cout<<"\t 1. Sale Medicine.\n"
		<<"\t 2. Show All Medicine Stock.\n"
		<<"\t 3. Find Stock Items.\n"
		<<"\t 4. Notification.\n"
		<<"\t R. Return to Back Panel.\n"
		<<"\t E. Exit.\n\n"
		<<"\t Enter your Choice...: ";
	cin>>choice;
	switch(choice)
	{
		case '1':
			BuyMedicine();
			break;
		case '2':
			ShowAllstock();
			cout<<".\n.\nPress any key.........";
			getch();
			break;
		case '3':
			FindItem();
			break;
		case '4':
			notification();
			break;
		case 'R':
		case 'r':
			return 1;
		case 'e':
		case 'E':
			return 0;
		
		default:
			cout<<"\n\t\tYour Entered Wrong Choice."
				<<"\n\t\tPress any key.... ";
			getch();
		
	}
	goto top1;
	
	
	
	
}
int AdminMenu()
{
	Medicine medico;
	top1:
	char choice;
	system("cls");
	cout<<"\t\t_________________________________________\n"
		<<"\t\t                ADMIN MENU               \n"
		<<"\t\t_________________________________________\n\n";
	cout<<"\t 1. Sale Medicine.\n"
		<<"\t 2. Show All Medicine Stock.\n"
		<<"\t 3. Insert New Items in Stock.\n"
		<<"\t 4. Update Stock Items.\n"
		<<"\t 5. Delete Stock Items.\n"
		<<"\t 6. Find Stock Items.\n"
		<<"\t 7. Selling Reports.\n"
		<<"\t 8. Notification.\n"
		<<"\t 9. Settings.\n"
		<<"\t R. Return to Back Panel.\n"
		<<"\t E. Exit.\n\n"
		<<"\t Enter your Choice...: ";
	cin>>choice;
	switch(choice)
	{
		case '1':
			BuyMedicine();
			break;
		case '2':
			system("cls");
			cout<<"\t\t\t___________________________________\n"
				<<"\t\t\t         ENTIRE STOCK ITEMS        \n"
				<<"\t\t\t___________________________________\n";
			ShowAllstock();
			cout<<".\n.\nPress any key.........";
			getch();
			break;
		case '3':
			InsertItem();
			break;
		case '4':
			Updateitem();
			break;
		case '5':
			DeleteItem();
			break;
		case '6':
			FindItem();
			break;
		case '7':
			SellingReport();
			break;
		case '8':
			notification();
			break;
		case '9':	
			settingAcount();
			break;
		case 'R':
		case 'r':
			return 1;
		case 'e':
		case 'E':
			return 0;
		
		default:
			cout<<"\n\tYour Entered Wrong Choice."
				<<"\n\tPress any key.... ";
			getch();
		
	}
	goto top1;


}
void ShowAllstock()
{
	//system("cls");
	ifstream ifile;
	ifile.open("Database\\stock.dat",ios::in|ios::binary);
	Medicine medico;
	
	cout<<"_______________________________________________________________________________\n\n";
	cout<<" "<<left<<setw(10)<<"ID"<<left<<setw(13)<<"NAME"<<left<<setw(11)<<"COMPANY"<<left<<setw(7)<<"QTY()"<<left<<setw(11)<<" MFG_DATE"<<left<<setw(10)<<"EXP_DATE"<<left<<setw(8)<<"R_PRICE"<<left<<"PRICE";
	cout<<"\n_______________________________________________________________________________\n\n";
	while( ifile.read((char *)&medico, sizeof(medico)) )
	{
		medico.showitems();
	}
	ifile.close();
	
}
void InsertItem()
{
	
	top:
	system("cls");
	ofstream writeMedFile("Database\\stock.dat", ios::binary | ios::app);
	ifstream rfile;
	rfile.open("Database\\stock.dat", ios::in|ios::binary);
	Medicine medico,chk;
	char sure[5];
	cout<<"\t\t_________________________________________\n"
		<<"\t\t               STOCK ENTERY              \n"
		<<"\t\t_________________________________________\n";
	char ch;
	do
	{
		medico.insetStockMed();
		cout<<"\nAre you Sure to save this item(y/n)..: ";
		cin.getline(sure,4);
		if(strcmp(sure,"y")==0 || strcmp(sure,"Y")==0)
		{
		
			while( rfile.read((char *)&chk,sizeof(chk)) )
			{
				if(medico.getID()==chk.getID())
				{
					cout<<"\n Please enter again Item \n"
						<<"\n This ID already Exist. \n"
						<<"\n Press any key.....";
						getch();
						rfile.close();
						writeMedFile.close();
						goto top;
				}
			}
			getch();
			writeMedFile.write((char *)&medico,sizeof(medico));
			cout<<"\nDo you want to enter again record??(y/n)..";
			cin>>ch;
		}
		else
		{
			return;
		}
	}while(ch=='y' || ch=='Y');
	writeMedFile.close();
}

void FindItem()
{
	top1:
	system("cls");
	
	ifstream fileSrch;
	fileSrch.open("Database\\stock.dat", ios::in|ios::binary);
	Medicine medico;
	char choice;
	int found=0;
	
	cout<<"\n\n";
	cout<<"\t\t__________________________________________ \n"
		<<"\t\t              SEARCHING MEDICINE           \n"
		<<"\t\t__________________________________________ \n\n";
	cout<<"\t\t 1. By ID.\n"
		<<"\t\t 2. By Name.\n"
		<<"\t\t 3. Return to Back Menu.\n\n";
		
	cout<<"\t\t Enter Your Choice...: ";
	cin>>choice;
	switch(choice)
	{
		case '1':
			
			char srchID[14];
			cout<<"\t\t Enter the ID of Medicine: ";
			cin.ignore();
			cin.getline(srchID,13);
			while( fileSrch.read((char *)&medico, sizeof(medico)) )
			{
				if(medico.getID()==srchID)
				{
					cout<<"_______________________________________________________________________________\n\n";
					cout<<left<<setw(10)<<"ID"<<left<<setw(13)<<"NAME"<<left<<setw(14)<<"COMPANY"<<left<<setw(8)<<"QUANTITY"<<left<<setw(10)<<" MFG_DATE"<<left<<setw(10)<<"EXP_DATE"<<left<<setw(8)<<"R_PRICE"<<left<<"PRICE";
					cout<<"\n_______________________________________________________________________________\n\n";
					
					medico.showitems();
					found=1;
					break;
				}
			}
			if(found==0)
			{
				cout<<"\n\t\t Medicine Does Not Found In Stock..!!";
				cout<<"\n\t\t Press any key.......";
				getch();
			}
			getch();
			break;
		case '2':
			char srchName[20];
			cout<<"\t\t Enter the Name Of Medicine: ";
			cin.ignore();
			cin.getline(srchName,19);
			
			while( fileSrch.read((char *)&medico, sizeof(medico)) )
			{
				if(medico.getName()==srchName)
				{
					cout<<"\n______________________________________________________________________________\n\n";
					cout<<left<<setw(10)<<"ID"<<left<<setw(15)<<"Name"<<left<<setw(13)<<"Company"<<left<<setw(7)<<"QTY()"<<left<<setw(10)<<"mfg_date"<<left<<setw(10)<<"exp_date"<<left<<setw(8)<<"R_Price"<<left<<"Price"<<endl;
					cout<<"______________________________________________________________________________\n";
					
					medico.showitems();
					found=1;
					break;
				}
			}
			if(found==0)
			{
				cout<<"\n\t\t Medicine Does Not Found In Stock..!!";
				cout<<"\n\t\t Press any key.......";
				getch();
			}
			getch();
			break;
		case '3':
			return;
		default:
			cout<<"\n\t\t Your Entered Wrong Choice."
				<<"\n\t\t Press any key.... ";
			getch();
	}
	goto top1;
	
	
}


void DeleteItem()
{
	system("cls");
	Medicine medico;
	ifstream fin;
	ofstream fout;
	fin.open("Database\\stock.dat", ios::in|ios::binary);
	char Del_id[15];
	char oldname[] ="Database\\tempfile.dat";
  	char newname[] ="Database\\stock.dat";
  	int found=0,result;
  	
  	cout<<"\t\t___________________________________\n";
  	cout<<"\t\t        DELETING STOCK ITEM        \n";
	cout<<"\t\t___________________________________\n\n";
	cout<<"\t\t Enter the ID of Item: ";
	cin.ignore();
	cin.getline(Del_id,14);
	if(!fin)
	{
		cout<<"\n\t\tFile Not Found..!!\a";
	}
	else
	{
		fout.open("Database\\tempfile.dat", ios::out|ios::binary);
		while( fin.read((char *)&medico, sizeof(medico)) )
		{
			if(medico.getID()!=Del_id)
			{
				fout.write((char *)&medico, sizeof(medico));
				
			}
			else
			{
				found=1;
			}	
		
		}
		fin.close();
		fout.close();
		if( remove( "Database\\stock.dat" ) != 0 )
    		perror( "\n\t\t ....." );
  		else
    		puts( "\n\t\t ." );
		
		result= rename( oldname , newname );
  		if ( result == 0 )
    		puts ( "\n\t\t ." );
  		else
    		perror( "\n\t\t ....." );
		if(found==0)
		{
			cout<<"\n\t\t This ID is Not Found in Stock..!!\a";
			cout<<"\n\t\t Press any key....";
			getch();
			
		}
		else if(found==1)
		{
			cout<<"\n\t\t ID is Deleted in Stock Successfully..!!\a";
			cout<<"\n\t\t Press any key....";
			getch();
		}
		
	}
}

void Updateitem()
{
	top1:
	Medicine medico;
	fstream file;
	file.open("Database\\stock.dat", ios::in|ios::out|ios::binary);
	file.seekg(0);
		char Nid[14],idfind[14],choice_22[10];
		char Nname[20],mgf[10],exp[10],rp[10],pr[10],qt[10];
		char Ncompany[10];
		int Nmfg_date;
		int Nexp_date;
		int Nquantity;
		int NretailPrice;
		int Nprice;
	char choice_1,choice_2;
	int found=0,pos;
	long x=0;
	system("cls");
	cout<<"\t\t_________________________________________\n"
		<<"\t\t                UPDATION                 \n"
		<<"\t\t_________________________________________\n";
	cout<<"\t\t 1. Enter The ID of Medcine to Updated.\n"
		<<"\t\t R. Return to Back Menu.\n\n"
		<<"\t\t Enter your Choice...: ";
	cin>>choice_22;
	choice_1=choice_22[0];
	switch(choice_1)
	{
		case '1':
			//top2:
				system("cls");
				cout<<"\t\t Enter The ID : ";
				cin.ignore();
				cin.getline(idfind,13);
			
			while(file.read((char *)&medico, sizeof(medico)))
			{
				if(medico.getID()==idfind)
				{
					found=1;
					cout<<"\n\t\tItem is Founded in Stock..!\n";
					cout<<"\t\t_________________________________________\n"
						<<"\t\t                UPDATION                 \n"
						<<"\t\t_________________________________________\n";
						cout<<"\t\t 1. Update Item With All New Values.\n"
							<<"\t\t 2. Update ID.\n"
							<<"\t\t 3. Update Name.\n"
							<<"\t\t 4. Update Company Name.\n"
							<<"\t\t 5. Update Manufacturing Date.\n"
							<<"\t\t 6. Update Expiry Date.\n"
							<<"\t\t 7. Update Quantity.\n"
							<<"\t\t 8. Update Retail Price.\n"
							<<"\t\t 9. Update Price.\n"
							<<"\t\t R. Return To Back Menu.\n";
					top3:
						cout<<"\n\t\tEnter Your Choice.....: ";
					cin>>choice_2;
					switch(choice_2)
					{
						case '1':
							cout<<"\n\t\tEnter The New Values.\n";
							medico.insetStockMed();
							break;
						case '2':
							cout<<"\n\t\tEnter The New ID: ";
							cin.ignore();
							cin.getline(Nid, 13);
							medico.setID(Nid);
							break;
						case '3':
							cout<<"\n\t\tEnter The New Name: ";
							cin.ignore();
							cin.getline(Nname, 19);
							medico.setName(Nname);
							break;
						case '4':
							cout<<"\n\t\tEnter The New Company name: ";
							cin.ignore();
							cin.getline(Ncompany, 9);
							medico.setCompny(Ncompany);
							break;
						case '5':
							cin.ignore();
							a:
							cout<<"\n\t\tEnter the New Manufacturing Date (yyyymmdd) : ";

								cin.getline(mgf,9);
								x=Toint(mgf);
								if(x==0 || x<0)
								{
									cout<<"\t\tInvalid..!\n";
									goto a;
								}
								dateExtrctor(x,1);
								if( (GlobleMonth>12)||(GlobleMonth<=0) || (GlobleDay>31)||(GlobleDay<=0) ||(GlobleYear<=0))
								{
									cout<<"\t\tInvalid..!\n";
									goto a;
								}
								Nmfg_date=x;
							medico.setMfg(Nmfg_date);
							break;
						case '6':
							b:
							cout<<"\n\t\tEnter the New Expiry Date (yyyymmdd) : ";
							
							cin.getline(exp,9);
								x=Toint(exp);
								if(x==0 || x<0)
								{
									cout<<"\t\tInvalid..!\n";
									goto b;
								}
								dateExtrctor(x,1);
								if( (GlobleMonth>12)||(GlobleMonth<=0) || (GlobleDay>31)||(GlobleDay<=0) ||(GlobleYear<=0))
								{
									cout<<"\t\tInvalid..!\n";
									goto b;
								}
								Nexp_date=x;
							
							medico.setExp(Nexp_date);
							break;
						case '7':
							c:
							x=0;
							cout<<"\n\t\tEnter the New Quantity: ";
							
							cin.getline(qt,9);
								x=Toint(qt);
								if(x==0 || x<0)
								{
									cout<<"\t\tInvalid..!\n";
									goto c;
								}
								
								Nquantity=x;
							medico.setQty(Nquantity);
							break;
						case '8':
							d:
							x=0;
							cout<<"\n\t\tEnter the New Retail price: ";
							
							cin.getline(rp,9);
								x=Toint(rp);
								if(x==0 || x<0)
								{
									cout<<"\t\tInvalid..!\n";
									goto d;
								}
								
								NretailPrice=x;
							medico.setRprice(NretailPrice);
							break;
						case '9':
							e:
							x=0;
							cout<<"\n\t\tEnter the New Price: ";
							cin.getline(pr,9);
								x=Toint(pr);
								if(x==0 || x<0)
								{
									cout<<"Invalid..!\n";
									goto e;
								}
								Nprice=x;
							medico.setPrice(Nprice);
							break;
						case 'r':
						case 'R':
							file.close();
							return;
						default:
							cout<<"\n\t\tYou Entered Wrong Choice.."
								<<"\n\t\tPress Any key....";
							getch();
							goto top3;
					}				
				
					pos=file.tellg()-sizeof(medico);
					file.seekp(pos,ios::beg);
					file.write((char *)&medico,sizeof(medico));
					break;					
				
				}
			
			}
			if(found==0)
			{
				cout<<"\n\t\tItem is not Found ..";
				
					
			}
			else if(found ==1)
				cout<<"\n\t\tItem in Stock is updated Successfully.";
			file.close();
			getch();
			break;
		case 'r':
		case 'R':
			return;
			break;
		default:
			cout<<"\n\t\tYour entered wrong choice...\n\t\tRead choices Carefully again..";
			cout<<"\n\t\tPress Any key...";
			getch();
	}
	goto top1;
}

void notification()
{
	system("cls");
	Medicine medico;
	int q, d,chk1=0,chk2=0;
	ifstream file;
	file.open("Database\\stock.dat",ios::in|ios::binary);
	for(int space=0; space<=10; space++)
	{
		cout<<" ";
	}
	for(int space=0; space<=17; space++)
	{
		cout<<char(196);
	}
	cout<<"Notifcation Panal";
	for(int space=0; space<=15; space++)
	{
		cout<<char(196);
	}
	cout<<endl;
	while( file.read((char *)&medico, sizeof(medico)))
	{
		chk1=chk2=0;
		d=medico.getExpDate();
		q=medico.getQty();
		if(d<todaydate)
		{
			chk1=1;
		}
		if(q<=5)
		{
			if(q==0)
			{
				chk2=2;
			}
			else
			
				chk2=1;
		}
	//	cout<<"value of q: "<<q<<endl;
		//getch();
		if( chk1==1 || ( chk2==1 || chk2==2 ) )
		{
			if(chk1==1)
			{
				if(chk2==2)
				{
					medico.showtab();
					cout<<left<<setw(15)<<"Description";
					cout<<"Update This Item \n\t       item is Out Of Date..!\n\t       Quantity is \'ZERO\' So End in Stock \n\n";
					cout<<"\t\t";
					for(int i=0; i<35 ; i++)
					{
						cout<<char(196);
					}
					cout<<"\n\n";
					
				}
				else if(chk2==1)
				{
					medico.showtab();
					cout<<left<<setw(15)<<"Description";
					cout<<"Update This Item \n\t       item is Out Of Date..!\n\t       Quantity is \'LOW\'\n\n";
					cout<<"\t\t";
					for(int i=0; i<35 ; i++)
					{
						cout<<char(196);
					}
					cout<<"\n\n";
				}
				else
				{
					medico.showtab();
					cout<<left<<setw(15)<<"Description";
					cout<<"Update This Item \n\t       item is Out Of Date..!\n\n";
					cout<<"\t\t";
					for(int i=0; i<35 ; i++)
					{
						cout<<char(196);
					}
					cout<<"\n\n";
				}
				
			}
			else if(( chk2==1 || chk2==2 ))
				{
					if(chk2==1)
					{
						medico.showtab();
						cout<<left<<setw(15)<<"Description";
						cout<<"Update This Item \n\t       Quantity Is \'LOW\'\n\n";
						cout<<"\t\t";
						for(int i=0; i<35 ; i++)
						{
							cout<<char(196);
						}
						cout<<"\n\n";
					}
					else if(chk2==2)
					{
						medico.showtab();
						cout<<left<<setw(15)<<"Description";
						cout<<"Update This Item \n\t       Quantity Is \'ZERO\'\n\t       Item is End In Stock\n\n";
						cout<<"\t\t";
						for(int i=0; i<35 ; i++)
						{
							cout<<char(196);
						}
						cout<<"\n\n";
					}
				}
			
		}
		
	}


	cout<<"\n\nPress any key....";
	getch();
}


void BuyMedicine()
{
	system("cls");
	
	
	
	Medicine medico;
	cout<<"\t\t_______________________________________\n"
		<<"\t\t             BUYER\'s POINT            \n"
		<<"\t\t_______________________________________\n";
	ShowAllstock();
	char customer_name[25],chooseEditOrBuy[5],surechoice[5], getId[20];
	//string cname;
	IDbill id_item[5000];
	int indexofSaleitem=0, storeIndex, tempQTY,pos;
	bool purchase;
	int itemTrue = 0,found=0;
	float price=0.0, Rprice=0.0 ,total=0.0, profit=0.0;
	
	cout<<"\n                ______________________________________\n";
	for(indexofSaleitem=0; ; indexofSaleitem++)
	{
		again1:
		cin.ignore();
		cout<<"Enter a Column ID\'s (q to exit): ";
		id_item[indexofSaleitem].inputId();
		storeIndex=indexofSaleitem;
		//ye entry end krny k liye hai....
	
		if (id_item[indexofSaleitem].getID().compare("q") == 0)
        {
            break;
        }
        //............
        
       	ifstream fileRead;
		fileRead.open("Database\\stock.dat", ios::in|ios::binary);
		while( fileRead.read( (char *)&medico,sizeof(medico)) )
		{
			if(id_item[indexofSaleitem].getID() == medico.getID())
			{
				cout<<"found\n";
				if(medico.getQty()==0)
				{
					cout<<"This medicine is not Available...!";
					goto again1;
				}
				qtyagain: 
				int q=1;
				q=id_item[indexofSaleitem].inputQTY();
				if( (q > medico.getQty() ) || ( q <=0 ) || (q ==-6767) )
				{
					system("color FC");
					cout<<"\nInvalid Quantity..!\n";
					Sleep(1000);
					system("color 07");
					goto qtyagain;
				}
				found= 1;
				break;
			}
			else
			{
				found=0;
			}
		}
		if(found==0)
		{
			cout << "Enter a valid ID.." << endl;
            //indexofSaleitem--;
            itemTrue = false;
            goto again1;
		}
		
		
	}
	//while();
	
	cout<<"You Choose this item ID\'s : ";
	for(indexofSaleitem=0 ; indexofSaleitem< storeIndex ; indexofSaleitem++)
	{
		cout<<left<<setw(15)<<id_item[indexofSaleitem].getID()<<left<<" QTY("<<id_item[indexofSaleitem].getquantity()<<")"<<endl<<"\t\t\t    ";
	}
	//control move
	CHOOSEEDITORBUY:
	
	cout << endl <<"Do you want to edit items(e) , buy this items(b) or No (n) : ";
	cin>>chooseEditOrBuy;
	
	
	if(strcmp(chooseEditOrBuy,"e")== 0  || strcmp(chooseEditOrBuy,"E")== 0)
	{
		
            cout << "Enter Remove item id's (q to exit): ";
            cin.ignore();
            gets(getId);
            cin.ignore();
			if (strcmp(getId,"q")==0 )
            {
            	goto there;
                
            }
            else if(strcmp(getId,"q")!=0)
            {
                for (int j = 0;j < storeIndex;j++)
                {
                    if (id_item[j].getID().compare(getId) == 0 )
                    {
                        for (int k = j; k < storeIndex; k++)
                        {
                            id_item[k] = id_item[k+1];
                        }
                        storeIndex--;
                    }
                }
                
            }
            
        	
		there:
        cout << "You choose this item id's: ";
        for (int i = 0; i < storeIndex; i++)
        {
            cout<<left<<setw(15)<<id_item[i].getID()<<left<<" QTY("<<id_item[i].getquantity()<<")"<<endl<<"\t\t\t    ";
        }
		
		
        goto CHOOSEEDITORBUY;
	}
	else if(strcmp(chooseEditOrBuy,"b")== 0  || strcmp(chooseEditOrBuy,"B")== 0)
	{
		cout<<"Are you sure to Buy this items (y/n)..: ";
		cin>>surechoice;
		if(strcmp(surechoice,"n")==0 || strcmp(surechoice,"N")==0  )
		{
			cout<<"\n";
			goto CHOOSEEDITORBUY;
		}
		for(int i=0; i < storeIndex ;i++)
		{
			fstream file;
			file.open("Database\\stock.dat",ios::in|ios::out|ios::binary);
			file.seekg(0);
			while( file.read((char *)&medico, sizeof(medico) ))
			{
				if( id_item[i].getID().compare(medico.getID())==0)
				{
					tempQTY= medico.getQty()- id_item[i].getquantity();
					medico.setQty(tempQTY);
					profit +=(medico.getPrice()-medico.getRprice())*id_item[i].getquantity();
					total+=medico.getPrice()*id_item[i].getquantity();
					
					pos=file.tellg()-sizeof(medico);
					file.seekp(pos,ios::beg);
					file.write((char *)&medico,sizeof(medico));
					break;	
				}
				
			}
		}
		cout << endl << "Purchase Successfully Done." << endl;
        cout << endl << "Total Price: " << total << endl;
		
		
	}
	else if(strcmp(chooseEditOrBuy,"n")== 0  || strcmp(chooseEditOrBuy,"N")== 0)
	{
		return;
	}
	else
	{
		cout<<"\nEntered Wrong Choice..\n";
		goto CHOOSEEDITORBUY;
	}
	char n[30];
	cout<<"\nEnter The Customer Name: ";
	cin.ignore();
	cin.getline(n,29);
	cout<<"Thank you  "<<n;
	//cout<<"\n"<<storeIndex;
	
	
	
	
	
	getch();
	RecordOfSale(id_item,storeIndex,n,total);
	ProfitRecord(profit);

	char a[20],printfile[100]="notepad /p SaleRecord\\", choice21;
    cout<<"\nAre you want to Print the Invoice( y/n)..: ";
    cin>>a;
    choice21=a[0];
    switch(choice21)
    {
    	case 'y':
    	case 'Y':
    	strcat(printfile,n);
	    strcat(printfile,".txt");
		cout<<"break....";
	    getch();
	    
	    system(printfile);
	    cout<<"Printing.";
		case 'n':
		case 'N':
			break;
	}
    
	getch();
	
	
} 


void RecordOfSale(IDbill id_q[5000], int indexStore, char name[35],float t)
{
	
	char c[200]="SaleRecord\\";
	strcat(c,name);
	strcat(c,".txt");
	ofstream ofile;
	ofile.open(c, ios::out);
	//------------
	string monthstr[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"},str1;
	stringstream dstr,mstr,ystr;
	Medicine medico;
	dstr<<day;
	mstr<<monthstr[month-1];
	ystr<<year;
	string s0="\n         ******** Sale Slip ********         \n\n",
           s1="Custmer Name: ";
           s1.append(name);
	string s2="\nDate: "+dstr.str()+"-"+mstr.str()+"-"+ystr.str()+"\n",
		   s3="--------------------------------------------\n",
		   s4="ID             Name            Qty       Amt    \n",
		   s41="--------------------------------------------\n",
		   s5=s0+s1+s2+s3+s4+s41+"\n";
	ofile<<s5;
	for(int i=0; i<indexStore ; i++ )
	{
		stringstream s;
		ifstream readFromDt;
		readFromDt.open("Database\\stock.dat",ios::in|ios::binary);
		while(readFromDt.read((char *)&medico, sizeof(medico)))
		{
			if(id_q[i].getID().compare(medico.getID())==0)
			{
				
				ofile<<medico.getID();
				int lengthspace=medico.getID().length();
				for(int loops=1 ; loops<=(15-lengthspace) ; loops++)
				{
					ofile<<" ";
				}

				ofile<<medico.getName();
				
				lengthspace=medico.getName().length();
				for(int loops=1 ; loops<=(16-lengthspace); loops++)
				{
					ofile<<" ";
				}
				
				ofile<<id_q[i].getquantity();
				
				s<<id_q[i].getquantity();
				str1=s.str();
				lengthspace=str1.length();
				for(int loops=1 ; loops<=(10-lengthspace) ; loops++)
				{
					ofile<<" ";
				}
				ofile<<medico.getPrice();
				ofile<<"\n";
				break;
			}
			
		}
		readFromDt.close();
	}
	ofile<<"--------------------------------------------\n";
	ofile<<"Total: "<<t<<"\n";
	ofile<<"--------------------------------------------\n";
	ofile<<"Thankyou For Visiting Us. <3\n";
	ofile.close();
	
	DateBYdateRecord(name);
	
	
}

void DateBYdateRecord(char nameOfRecord[100])
{
	string data;
	char name[30]="SaleRecord\\", srchName[30]="SaleRecord\\", word;
	stringstream date;
	date<<todaydate;
	string s=date.str();
	strcat(name,s.c_str());
	strcat(name,".txt");
	ofstream file;
	file.open(name, ios::out|ios::app|ios::ate);
	strcat(srchName,nameOfRecord);
	strcat(srchName,".txt");
	ifstream readFile;
	readFile.open(srchName, ios::in);
	if(!readFile)
	{
		cout<<"!..\a";
		return;
	}
	file<<"\n\n\n";
	while(!readFile.eof())
	{
		readFile.get(word);
		file.put(word);
	}
	readFile.close();
	file.close();
	return;
}

void ProfitRecord(float p)
{
	rough vf;
	string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"},filename;
// assigning ending.
	stringstream opp;
	opp<<year;
	string s1=opp.str();
	filename="SaleRecord\\"+months[month-1]+s1+".dat";
	ifstream readfile;
	readfile.open(filename.c_str(),ios::in|ios::binary);
	if(!readfile)
	{
		ofstream f;
		f.open(filename.c_str(), ios::out|ios::binary);
		f.write( (char *)&vf, sizeof(vf));
		f.close();		
	}
	else
	{
		readfile.read((char *)&vf, sizeof(vf));
		readfile.close();
	}
	float pp;
//	cout<<"p is:"<<p<<"vf is: "<<vf.getf();
	pp=vf.getf()+p;
//	cout<<"pp is "<<pp;
	vf.set(pp);
//	cout<<"value of profit is: "<<vf.getf();
	ofstream writefile;
	writefile.open(filename.c_str(), ios::out|ios::binary);
	writefile.seekp(0,ios::beg);
	writefile.write((char *)&vf,sizeof(vf));
	writefile.close();
	
	
	return;
}

void showProfit()
{
	
	system("cls");
	string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	string date,file_name,monthday;
	string m,y;
	long x=0;
	
	cout<<"\t\t_________________________________________\n"
		<<"\t\t                REPORT PORTAL                 \n"
		<<"\t\t_________________________________________\n\n";
		top2:
	cout<<"\tEnter the month and Year (yyyymm): ";
	cin>>date;
	x=Toint(date);
	if(x==0|| x<0)
	{
		
		cout<<"\n\tInvalid..!\n";
		goto top2;
		
	}
	else
	{
		dateExtrctor(x);
		
		if( (GlobleMonth>0 )&& (GlobleMonth<13) )
		{
			
			
			rough p;
			stringstream d11;
			d11<<GlobleYear;
			monthday=months[GlobleMonth-1];
			file_name="SaleRecord\\"+monthday+d11.str()+".dat";
			cout<<"file "<<file_name;
			ifstream filep;
			filep.open(file_name.c_str() , ios::binary|ios::in );
			if(!filep)
			{
				cout<<"\n\tFile not Found..!";
				getch();
				return;
			}
			filep.read((char *)&p, sizeof(p));
			cout<<"\n\tMonthly Profit is: "<<p.getf();
			cout<<"\n\tPress any key.....";
			getch();
			return;
			
			
				
		}
		else
		{
			cout<<"\n\tInvalid..!\n"<<GlobleMonth;
			goto top2;
		}

	}
	
}

void checksale()
{
	
	system("cls");
	string date;
	long x=0;
	
	cout<<"\t\t_________________________________________\n"
		<<"\t\t                REPORT PORTAL                 \n"
		<<"\t\t_________________________________________\n\n";	
	top2:
	cout<<"\tEnter The date (yyyymmdd) : ";
	cin>>date;
	x=Toint(date);
	if( x==0 || x<0)
	{
		cout<<"\n\tInvalid..!\n";
		goto top2;
	}
	else
	{
		dateExtrctor(x,1);
		if( (GlobleMonth>12)||(GlobleMonth<=0) || (GlobleDay>31)||(GlobleDay<=0) ||(GlobleYear<=0))
		{
			//cout<<"dates : "<<GlobleMonth<<"   "<<GlobleDay<<"   "<<GlobleYear;
			cout<<"\n\tInvalid..!\n";
			goto top2;
		}
		else
		{
			string filename;
			filename="SaleRecord\\"+date+".txt";
			ifstream file;
			file.open(filename.c_str(), ios::in);
			if(!file)
			{
				cout<<"\n\tFile not Found....";
				getch();
			}
			else
			{
				while(!file.eof() )
				{
					char word;
					file.get(word);
					cout.put(word);
				}
			}
		}
	}
	getch();
	
}

void SellingReport()
{
	top1:
	system("cls");
	 cout<<"\t\t_________________________________________\n"
		<<"\t\t                REPORT PORTAL                 \n"
		<<"\t\t_________________________________________\n";
	cout<<"\t\t 1. Check Profit.\n"
		<<"\t\t 2. Check Sales.\n"
		<<"\t\t R. Return.\n"
		<<"\t\tEnter your choice..: ";
	char ch[5],choice;
	cin>>ch;
	choice=ch[0];
	switch(choice)
	{
		case '1':
			showProfit();
			break;
		case '2':
			checksale();
			break;
		case 'r':
		case 'R':
			return;
		default:
			cout<<"\n\t You Entered WRONG Choice";
			cout<<"\n\t Press Any key....";
			getch();
			
	} 
	goto top1;
}









