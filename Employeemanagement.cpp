 #include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<Windows.h>
//#include<dos.h>
#include<bits/stdc++.h>
//#include<string>
//#include<map>
#include <typeinfo>
#define ENTER 13
#define TAB 9
#define BKSP 8

//#include "AdminAccess.h"




using namespace std;
int menu();



class EmployeeAccess
{
      private:
            
            int eICNumber;
            long int eId;
			int cal[5][7]={{1,1,1,0,1,1,1},{1,0,1,1,1,1,1},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1},{1,1,0,0,0,0,0}};
	        string  eDateJoined, eNationality, eDOB;// ePassword, eUsername; 
	        char eUsername[15], ePassword[15], eName[20], eGender[5], eQualification[20], eDesignation[10], eDepartment[10], eMaritalStatus[5];
	        //char eName[25];
			friend class AdminAccess;
               
      public:
	  		 void showheader();
	  		void employeeMenu();
             void addemployee();
             void showinfo();
			 void myprofile();
             void addinfo();
             void viewinfo();
             void searchemployee();
             void deleteEmployee();
             void viewEmployeeList();
             void updateEmployee();
			 void calculateSalary();
			 void showholiday();
             //////////////////////////
             void getName();
             //void getEmployeeDetails();
            void getPassword();
	        void getGender();
	        void getQualification();
	        void getDesignation();
	        void getDepartment();
	        void getDateJoined();
            void getMaritalStatus();
			void loginPage();
			void login();
			void getId();
			int showcalender();
			 
			int getSalary(char desig[20]);
};
class AdminAccess:public EmployeeAccess
{
	private:
		char str[100];
		friend class EmployeeAccess;
	public:
	void getnote();
	void adminLogin();
	void adminOptions();
	void viewList();
	void Anotice();
};
void EmployeeAccess::loginPage()
{
	system("cls");
	
	system("COLOR 4F");
	int loginChoice;
	cout<<"\n"<<setw(65)<<right<<"----------------------------------------";
	cout<<"\n"<<setw(65)<<right<<"  WELCOME TO EMPLOYEE MANAGMENT SYSTEM  ";
	cout<<"\n"<<setw(65)<<right<<"----------------------------------------";
	//cout<<"\n\n\n"<<setw(47)<<right<<"PLEASE LOGIN...\n\n";
	cout<<"\n\n"<<setw(41)<<right<<"[1] SIGN UP";
	cout<<"\n\n"<<setw(51)<<right<<"[2] LOGIN AS EMPLOYEE";
	cout<<"\n\n"<<setw(48)<<right<<"[3] LOGIN AS ADMIN";
	cout<<"\n\n"<<setw(38)<<right<<"[4] EXIT";
	cout<<"\n\n\n"<<setw(48)<<right<<"ENTER YOUR CHOICE ";
	cin>>loginChoice;
	EmployeeAccess e;
	AdminAccess a;
			
	switch (loginChoice)
	{
		case 1:
			e.addemployee();
			loginPage();
		break;
	case 2:
        e.login();
		break;
	case 3:
		a.adminLogin();
		break;
	case 4:
		system("cls");
		exit(0);
		break;
	default:
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<loginChoice;
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
		cin.get();
		cin.get();
		loginPage();

	}
	//int choice = getType(" Who are you?");
}
void EmployeeAccess::login()
{
	system("cls");
	system("COLOR 4F");
    char password[20];
    int count=0;
	int userid;
    cout<<"\n\n\n"<<setw(48)<<right<<"ENTER THE USER_ID   : ";
    cin>>userid;
    cout<<"\n\n\n"<<setw(48)<<right<<"ENTER YOUR PASSWORD : ";
    cin>>password;
    //ifstream fin;
    //fin.open(filename,ios::in|ios::binary);
    //fin.read((char*)this,sizeof(*this));
	//fin=fopen("employeedetails.txt",ios::in|ios::binary);
	EmployeeAccess e1;
	ifstream fin;
	fin.open("bookfile.txt",ios::in|ios::binary);
	//file.seekg(0);
	if(!fin)
         cout<<"File not found";
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(eICNumber==userid)
			{
				if(!strcmp(ePassword,password))
				{
	            	cout<<"employee founded\n";
                	system("cls");
                	e1.employeeMenu();
                	break;
				}
            }
            count++;
			fin.read((char*)this,sizeof(*this));
        }
    }
    if(count==0)
	{
        cout<<"\nINVALID";
		getch();
		login();
	}
	fin.close();
}

int menu()
{
    
    system("cls");
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n"<<setw(51)<<right<<"  EMPLOYEE MENU  ";
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n\n"<<setw(49)<<right<<"[1] MY PROFILE\n";
	cout<<setw(56)<<right<<"[2] VIEW ALL EMPLOYEE LIST\n";
	cout<<setw(58)<<right<<"[3] SEARCH  EMPLOYEE\n";
	cout<<setw(56)<<right<<"[4] UPDATE EMPLOYEE PROFILE\n";
	cout<<setw(56)<<right<<"[5] DELETE EMPLOYEE PROFILE\n";
	cout<<setw(57)<<right<<"[6] CALCULATE SALARY PACKAGE\n";
	cout<<setw(57)<<right<<"[7] VIEW NOTICE              \n";
	
	cout<<setw(57)<<right<<"[8] VIEW EVENTS             \n";
	cout<<setw(39)<<right<<"[9] LOGOUT\n";
	cout<<"\n"<<setw(46)<<right<<"ENTER YOUR CHOICE ";
	
    
    
    int ch;
    cin>>ch;
    return(ch);
}
void EmployeeAccess::employeeMenu()
{
	EmployeeAccess e;
	AdminAccess a;
	int ch;
    ch=menu();
    switch(ch)
    {
        case 1:
			e.viewinfo();
			getch();
			//menu();
			e.employeeMenu();
       	 	//b.addempolyee();
        	//b.addinfo();
        	break;                        
	    case 2:
		{
        	e.viewEmployeeList();
			getch();
			e.employeeMenu();
		}break;
        case 3:
        {	e.searchemployee();
    	
		}break;
    	case 4:
        {	e.updateEmployee();

		}break;
        case 5: 
        {	e.deleteEmployee();;
		
		}break;
        case 6:
		{	e.calculateSalary();
			getch();
			e.employeeMenu();
		}
		break;
		case 7:
		{
			a.getnote();
			a.Anotice();
			getch();
			e.employeeMenu();
		}
		break;
		case 8:
		{
			e.showholiday();
			getch();
			e.employeeMenu();
		}
		break;
		case 9:
		{
			a.getnote();
			a.Anotice();
			getch();
			e.employeeMenu();
		}
		break;
		default:
		{
        	cout<<"Enter Valid choice";
			menu();
		}
	}
    getch();
}
                        
void EmployeeAccess::showheader()
{
     cout<<left;
     cout<<"\nSR.NO.\t\t"<<setw(10)<<"EMP_ID"<<setw(10)<<"NAME"<<"\n";
}
/*void EmployeeAccess::addempolyee()
{
     cout<<"Enter details : \n";
     fflush(stdin);
     //gets(title);
     //cout<<"Price of Book: ";
     //cin>>price;
     //bookid=allotbookid();
    ifstream fin;
	EmployeeAccess temp;
    int id = 0;
    fin.open("bookfile.txt",ios::in|ios::binary);
    if(!fin)
	{
           id = id+1;
	}
    else
    {
        fin.read((char*)&temp, sizeof(temp));
        while(!fin.eof())
        {
			id=temp.eICNumber;
			fin.read((char*)&temp, sizeof(temp));
        }
        id++;
	}

	eId= id;
    
	
    cout<<"\n"<<setw(68)<<right<<"___________________________________________________";

	cout<<"\n\n"<<right<<setw(25)<<"";
	cout<<setw(30)<<left<<"Employee ID:";
	cin>>eICNumber;
	
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Name:";
	cin>>eName;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Password:";
	cin>>ePassword;

	cout<<"\n\n"<<right<<setw(25)<<" ";
    cout<<setw(30)<<left<<"Employee Gender:";
	cin>>eGender;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Qualification:";
	cin>>eQualification;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Designation:";
	cin>>eDesignation;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Department";
	cin>>eDepartment;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Joining:";
	cin>>eDateJoined;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Nationality:";
	cin>>eNationality;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Birth:";
	cin>>eDOB;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Marital Status:";
	cin>>eMaritalStatus;
	cout<<"\n\n"<<setw(68)<<right<<"___________________________________________________";
	


    //getEmployeeDetails();
}*//////////////////////////////////////////////////////////
////duplicate/////
void EmployeeAccess::addemployee()
{
	system("cls");
	system("COLOR 7F");
    getId();
    getName();
	getPassword();
	getGender();
	getQualification();
	getDesignation();
	getDepartment();
	getDateJoined();

	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Nationality:";
	cin>>eNationality;

	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Birth";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"[DD/MM/YYYY]:";
	cin>>eDOB;

	getMaritalStatus();
	addinfo();

}
void EmployeeAccess::addinfo()
{

     ofstream fout;
     fout.open("bookfile.txt",ios::out|ios::app|ios::binary);
     if(!fout)
              cout<<"File can not open";
     else
              fout.write((char*)this,sizeof(*this));
     fout.close();
     cout<<"saved succesfully\n\n";
}
void EmployeeAccess::showinfo()
{
	system("cls");
	system("COLOR 3F");
     cout<<"\n"<<setw(68)<<right<<"___________________________________________________";

	cout<<"\n\n"<<right<<setw(25)<<"";
	cout<<setw(30)<<left<<"Employee ID:";
	cout<<eICNumber;
	
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Name:";
	cout<<eName;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Password:";
	cout<<"*********";
	//cout<<ePassword;
	cout<<"\n\n"<<right<<setw(25)<<" ";
    cout<<setw(30)<<left<<"Employee Gender:";
	cout<<eGender;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Qualification:";
	cout<<eQualification;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Designation:";
	cout<<eDesignation;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Department";
	cout<<eDepartment;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Joining:";
	cout<<eDateJoined;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Nationality:";
	cout<<eNationality;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Birth:";
	cout<<eDOB;

	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Marital Status:";
	cout<<eMaritalStatus;
	cout<<"\n\n"<<setw(68)<<right<<"___________________________________________________";
	

}


void EmployeeAccess::viewinfo()
{
     ifstream fin;
     fin.open("bookfile.txt",ios::in|ios::binary);
     if(!fin)
             cout<<"File not found";
     else
     {
         //showheader();
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
            
          	showinfo();
			
          	fin.read((char*)this,sizeof(*this));
         }
     }
     fin.close();
}
void EmployeeAccess::searchemployee()
{
    

     int choice;
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n\n"<<setw(51)<<right<<"[1] SEARCH BY IC NUMBER\n";
	cout<<setw(53)<<right<<"[2] SEARCH BY DESIGNATION\n";
	cout<<setw(52)<<right<<"[3] SEARCH BY DEPARTMENT\n";
	cout<<setw(39)<<right<<"[4] GO BACK\n";
	cout<<"\n"<<setw(45)<<right<<"ENTER YOUR CHOICE ";
	cin>>choice;
	switch(choice)
	{
	case 1:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			int eID;
			fin.open("bookfile.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Employee ID : ";
			cin>>eID;
			if(!fin)
			cout<<"File not found";
			else
			{
				fin.read(reinterpret_cast<char*>(this) ,sizeof(*this));
				while(!fin.eof())
				{
					if(eICNumber == eID)
					{
                        showinfo();
						cout<<"\n\n"<<setw(63)<<right<<"Press ENTER to go back to Main Menu...";
						break;
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
					cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
			}
			fin.close();
			//cin.get();
            
		}break;

	case 2:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			string designation;
			fin.open("bookfile.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Designation : ";
			cin>>designation;
			if(!fin)
				cout<<"File not found";
			else
			{
				fin.read((char*)this ,sizeof(*this));
				//showHeading();
				while(!fin.eof())
				{
					
					if(designation == eDesignation)
					{
						showinfo();
					}
					fin.read((char*)this,sizeof(*this));	
				}
				if(fin.eof())
				{
					//cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
				}
			}
			fin.close();
			cin.get();
			cin.get();
		}break;

	case 3:
		{
			system("cls");
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			cout<<"\n"<<setw(54)<<right<<"  SEARCH EMPLOYEE PROFILE  ";
			cout<<"\n"<<setw(54)<<right<<"---------------------------";
			ifstream fin;
			string department;
			fin.open("bookfile.txt",ios::in|ios::binary);
			cout<<"\n\n"<<setw(50)<<right<<"Enter Department : ";
			cin>>department;
			if(!fin)
				cout<<"File not found";
			else
			{
				fin.read(reinterpret_cast<char*>(this) ,sizeof(*this));
				//showHeading();
				while(!fin.eof())
				{
					if(eDepartment == department)
					{
						showinfo();
					}
					fin.read((char*)this,sizeof(*this));
				}
				if(fin.eof())
				{
					//cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
				}
			}
			fin.close();
			cin.get();
			cin.get();
		}break;
	//case 4:
	//	adminOptions();
	default:
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<choice;
		cout<<"\n"<<setw(56)<<right<<"____________________________";
		cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
		cin.get();
		cin.get();
        searchemployee();
	}
    getch();
    system("cls");
    //menu();
	
}
void EmployeeAccess::updateEmployee()
{
     int id,r=0,ch;
     fstream file;
     file.open("bookfile.txt",ios::in|ios::out|ios::ate|ios::binary);
     cout<<"\nEnter the employee-ID which one you want to modify: ";
     cin>>id;
     file.seekg(0);
     if(!file)
             cout<<"File not found";
     else
     {
         file.read((char*)this,sizeof(*this));
        
         while(!file.eof())
         {
           
           if(this->eICNumber==id)
           {
               r++;
             //showheader();
             showinfo();
             cout<<"PRESS  ENTER TO RE-WRITE\n";
             getch();

             system("cls");
             cout<<"SELECT WHICH DATA YOU WANT TO  MODIFY   : \n";
                cout<<setw(30)<<left<<"[1.]  Employee ID    :\n";
                cout<<setw(30)<<left<<"[2.]  Department     :\n";
                cout<<setw(30)<<left<<"[3.]  Designation    :\n";
                cout<<setw(30)<<left<<"[4.]  Marital status :\n";
                cout<<setw(30)<<left<<"[5.]  EXIT           :\n";
                
                cout<<setw(30)<<left<<"- - - - - - - - - - - - - - - - \n";
                cout<<setw(30)<<left<<"Please Enter your choice : ";
                cin>>ch;
                switch (ch)
                {
                    case 1:
                        cout<<setw(30)<<left<<"ENTER NEW EMPLOYEE ID :- ";
                        cin>>eICNumber;
                        break;
                    case 2:
                        getDepartment();
                        break;
                    case 3:
                        getDesignation();
                        break;
                    case 4:
                        getMaritalStatus();
                        break;
                    case 5:
                        menu();
                    break;
                    default:
                         break;
                }
             
             }
             
             //please write code for which information want to change



             /*cout<<"\nRe-enter book details:\n";
             cout<<"Enter book title:";
             fflush(stdin);
             gets(title);
             cout<<"Enter book price";
             cin>>price;*/
             file.seekp((r-1)*sizeof(EmployeeAccess),ios::beg);
             file.write((char*)this,sizeof(*this));
             break;
           }
           file.read((char*)this,sizeof(*this));
         }
         if(r!=0)
                      cout<<"Record not found";    
         file.close();
}
void EmployeeAccess::deleteEmployee()
{
     ifstream fin;
     ofstream fout;
     int id;
     char x;
     fin.open("bookfile.txt",ios::in|ios::binary);
     fout.open("tempfile.txt",ios::out|ios::app|ios::binary);
     cout<<"Enter employee ID  to delete his/her record";
     cin>>id;
     if(!fin)
             cout<<"File not found";
     else
     {
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
          if(this->eICNumber==id)
          {
            cout<<"Record you want to delete is:\n\n";
            showheader();
            showinfo();
            cout<<"\nAre you sure you want to delete this record(y/n): ";
            fflush(stdin);
            cin>>x;
            if(x=='n')
                         fout.write((char*)this,sizeof(*this));
            else
                         cout<<"\nRecord is deleted";
          }
          else
              fout.write((char*)this,sizeof(*this));
          fin.read((char*)this,sizeof(*this));
         }
         fin.close();
         fout.close();     
        
        
                      system("erase bookfile.txt");
                      getch();
                      system("rename tempfile.txt bookfile.txt");
        
        
     }
}
void EmployeeAccess::viewEmployeeList()
{
	system("cls");
	ifstream fin;
    fin.open("bookfile.txt",ios::in|ios::binary);
    if(!fin)
         cout<<"File not found";
    else
    {
		int i=1;
        showheader();
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            cout<<"\n"<<"["<<i++<<"]\t\t"<<setw(10)<<eICNumber<<setw(10)<<eName<<"\n";
		    cout<<"\n"<<setw(10)<<"--------------------------------------------\n";
          	fin.read((char*)this,sizeof(*this));
        }
    }
    fin.close();
	cout<<"PRESS ENTER \n";
	getch();
	//EmployeeAccess e;
	//
	
}
void EmployeeAccess::showholiday()
{
	system("cls");
	system("COLOR 3F");
	fstream file;
	file.open("holiday.csv",ios::in);
	int i = 0;
	cout<<"[ DAY ]\t\t\t[ DATE ]\t\t\t[ HOLIDAY NAME ]  \n";
	while(file.good()){
		string line1,line2,line3;
		getline(file,line1,',');
		getline(file,line2,',');
		getline(file,line3,'\n');
		cout<<line1<<"\t\t"<<line2<<"\t\t"<<line3<<"\n";
	}
}
/////////////////////////////get details///////////////////////////////
void EmployeeAccess::getId()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Create ID  (4 char):";
	cin>>eICNumber;
	/*if(strlen(eICNumber) <)
	{
		
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"ID is too short...try again";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getId();
	}*/
}


void EmployeeAccess::getName()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	
    fflush(stdin);
    system("cls");
    cout<<setw(30)<<left<<"Employee Name:";
	gets(eName);
	/*for (int i=0; i<20; i++)
	{
        
        int b=(int)eName[i];
        cout<<"ascii "<<b<<endl;
		if (b>0&&b<49||b>122&&b<127||(b>48&&b<65)||(b>90&&b<97))
		{
			cout<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<right<<setw(25)<<" ";
			cout<<setw(30)<<left<<"Name cannot contain SPECIAL CHARACTERS...";
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			//getName();
		}

	}*/	
}

void EmployeeAccess::getPassword()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Create Password (> 5 char):";
	gets(ePassword);
	if(strlen(ePassword) <6)
	{
		
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Password is too short...try again";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getPassword();
	}
}

void EmployeeAccess::getGender()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Enter Gender [M/F]:";
	fflush(stdin);
	gets(eGender);
	if((strcmp(eGender,"M")!=0 && strcmp(eGender,"m")!=0 && strcmp(eGender,"F")!=0 && strcmp(eGender,"f")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Invalid Gender Status...Enter [M/UF]"<<eGender;
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getGender();
	}

}

void EmployeeAccess::getQualification()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Qualification:";
	cin>>eQualification;
	/*for (int i=0; i<20; i++)
	{
		int b=(int)eQualification[i];
		if (b>0&&b<48||b>122&&b<127||(b>57&&b<65)||(b>90&&b<97))
		{
			cout<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<right<<setw(25)<<" ";
			cout<<setw(30)<<left<<"Password is too short...try again";
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			getName();
		}
	}*/	

}

void EmployeeAccess::getDesignation()
{
	cout<<"\n\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Designation:";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"(CEO/MD/MGR/GM/AM/SPV/LBR):";
	fflush(stdin);
	gets(eDesignation);
	if((strcmp(eDesignation,"CEO")!=0) && (strcmp(eDesignation,"MD")!=0) && (strcmp(eDesignation,"MGR")!=0)&& (strcmp(eDesignation,"GM")!=0)&& (strcmp(eDesignation,"AM")!=0) && (strcmp(eDesignation,"SPV")!=0)&& (strcmp(eDesignation,"LBR")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(17)<<" ";
		cout<<setw(30)<<left<<"Enter Valid Designation (CEO/MD/MGR/GM/AM/SPV/LBR)";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getDesignation();
	}
}

void EmployeeAccess::getDepartment()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Department";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"(HR/MKT/PRO/QA):";
	fflush(stdin);
	gets(eDepartment);
	if((strcmp(eDepartment,"HR")!=0) && (strcmp(eDepartment,"MKT")!=0) && (strcmp(eDepartment,"PRO")!=0)&& (strcmp(eDepartment,"QA")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(17)<<" ";
		cout<<setw(30)<<left<<"Enter Valid Department (HR/MKT/PRO/QA)";
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getDepartment();
	}

}

void EmployeeAccess::getDateJoined()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Date of Joining";
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"[DD/MM/YYYY]:";
	cin>>eDateJoined;
}

void EmployeeAccess::getMaritalStatus()
{
	cout<<"\n"<<right<<setw(25)<<" ";
	cout<<setw(30)<<left<<"Employee Marital Status [M/U]:";
	fflush(stdin);
	gets(eMaritalStatus);
	if((strcmp(eMaritalStatus,"M")!=0 && strcmp(eMaritalStatus,"m")!=0 && strcmp(eMaritalStatus,"U")!=0 && strcmp(eMaritalStatus,"u")!=0))
	{
		cout<<setw(68)<<right<<"___________________________________________________";
		cout<<"\n\n"<<right<<setw(25)<<" ";
		cout<<setw(30)<<left<<"Invalid Marital Status...Enter [M/U]"<<eMaritalStatus;
		cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
		getMaritalStatus();
	}

}


int EmployeeAccess::showcalender()
{
	
	int count=0;
	cout<<"SUN  MON  TUE  WED  THU  FRI  SUT \n";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<cal[i][j]<<"    ";
			if(cal[i][j]==0)
				count++;
		}
		cout<<"\n";
	}
	count=count-5;
	return count;
}
//typedef map<string,int> salary;
int EmployeeAccess::getSalary(char desig[20])
{
	//FIRST YOU STORE ALL VALUE BY THEIR DESIGNATION
	//AND AFTER THAT USING IF STATEMENT CHECK AND ALLOTE ;
	
	map<string,int> salary;
	salary["CEO"]=100000;
	salary["MD"]=50000;
	salary["MGR"]=30000;
	salary["GM"]=20000;
	salary["AM"]=10000;
	salary["SPV"]=10000;
	salary["LBR"]=5000;

	map<string,int> ::iterator it=salary.begin();
	
    for(it=salary.begin();it!=salary.end();it++)
    {
		
        if(it->first==desig)
          return it->second;
    }
}
void EmployeeAccess::calculateSalary()
{
	system("cls");
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	cout<<"\n"<<setw(53)<<right<<"  VIEW EMPLOYEE SALARY  ";
	cout<<"\n"<<setw(54)<<right<<"---------------------------";
	ifstream fin;
	int eID;
	fin.open("bookfile.txt",ios::in|ios::binary);
	cout<<"\n\n"<<setw(51)<<right<<"ENTER EMPLOYEE ID : ";
	cin>>eID;
	EmployeeAccess e;
	//e.getSalary();//only assign the value to all designation
	
	if(!fin)
		cout<<"File not found";
	else
	{
		fin.read((char*)(this) ,sizeof(*this));
		while(!fin.eof())
		{
			if(eICNumber == eID)
			{
				cout<<"desig==========="<<eDesignation<<endl;
				//e.showEmployee();
				int day=e.showcalender();
				cout<<"TOTAL ABSENT IN THIS MONTH IS :-  "<<day<<endl;

				double basicSalary, finalSalary;
				basicSalary=e.getSalary(eDesignation);

				finalSalary=basicSalary-day*(basicSalary*0.05);
				
				
				cout<<"\n\n"<<setw(54)<<right<<"EMPLOYEE SALARY PACKAGE OF THIS MONTH : "<<finalSalary;
				cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
				cout<<"\n\n"<<setw(63)<<right<<"Press ENTER to go back to Main Menu...";
				break;
			}
			fin.read((char*)this,sizeof(*this));
		}
		if(fin.eof())
			cout<<"\n"<<setw(50)<<right<<"  RECORD NOT FOUND  ";
	}
	fin.close();
	getch();
}



////////////////////////////////////
///////////////////////////////////
//////////////////////////////////
////////admin////////////////////

void AdminAccess::adminLogin()
{
	system("cls");
	system("COLOR 6F");
	//AdminAccess a;
	char pwd[100];
    int i=0;
	int A_userId=966070;
	char A_password[20]="adminlalit";
    char password[20];
    int count=0;
	int userid;
    cout<<"\n\n\n"<<setw(48)<<right<<"ENTER THE USER_ID   : ";
    cin>>userid;
    cout<<"\n\n\n"<<setw(48)<<right<<"ENTER YOUR PASSWORD : ";
    cin>>password;
	if(A_userId==userid)
	{
		if(!strcmp(A_password,password))
		{
			adminOptions();
			
		}
		else
		{
			cout<<"invalid Password\n";
			adminLogin();
		}
	}
	else
	{
		cout<<"invalid ADMIN  USER ID  \n";
		adminLogin();
	}
	
}
void AdminAccess::viewList()
{
    AdminAccess a;
	ifstream fin;
    fin.open("bookfile.txt",ios::in|ios::binary);
    if(!fin)
         cout<<"File not found";
    else
    {
		int i=0;
        a.showheader();
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            cout<<"\n"<<i<<setw(10)<<eICNumber<<setw(10)<<eName<<"\n";
		    cout<<"\n"<<setw(10)<<"--------------------------------------------\n";
          	fin.read((char*)this,sizeof(*this));
            getch();
        }
	//a.adminOptions();
    }
    fin.close();
    
	//adminOptions();
}
void AdminAccess::adminOptions()
{
	int adminChoice;
	system("cls");
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n"<<setw(51)<<right<<"  ADMINISTRATOR MENU  ";
	cout<<"\n"<<setw(52)<<right<<"------------------------";
	cout<<"\n\n"<<setw(49)<<right<<"[1] ADD NEW EMPLOYEE\n";
	cout<<setw(56)<<right<<"[2] SEARCH EMPLOYEE PROFILE\n";
	cout<<setw(58)<<right<<"[3] VIEW ALL EMPLOYEE PROFILE\n";
	cout<<setw(56)<<right<<"[4] UPDATE EMPLOYEE PROFILE\n";
	cout<<setw(56)<<right<<"[5] DELETE EMPLOYEE PROFILE\n";
	cout<<setw(57)<<right<<"[6] CALCULATE SALARY PACKAGE\n";
	cout<<setw(57)<<right<<"[7] ADD NOTICE              \n";
	
	cout<<setw(57)<<right<<"[8] VIEW EVENTS             \n";
	cout<<setw(39)<<right<<"[9] LOGOUT\n";
	cout<<"\n"<<setw(46)<<right<<"ENTER YOUR CHOICE ";
	cin>>adminChoice;
	AdminAccess a1;
	EmployeeAccess e1;
	switch(adminChoice)
	{
	case 1:
		{
			a1.addemployee();
			getch();
			adminOptions();
		}
		break;
	case 2:
		{
			a1.searchemployee();
			getch();
			adminOptions();
		}
		break;
	case 3:
		{
            a1.viewEmployeeList();
            getch();
			adminOptions();
		}
		break;
	case 4:
		{
			a1.updateEmployee();
			getch();
			adminOptions();
		}
		break;
	case 5:
		{
			a1.deleteEmployee();
			//cin.get();
			getch();
			adminOptions();
		}
		break;
	case 6:
		{
			a1.calculateSalary();
			getch();
			adminOptions();
		}
		break;
	case 7:
	{
		
		a1.Anotice();
		getch();
		a1.adminOptions();
	}
	break;
	case 8:
	{
		e1.showholiday();
		cout<<"PRESS ENTER TO BECK TO THE MENU ";
		getch();
		a1.adminOptions();
	}
	break;
	case 9:
		{
			cout<<"\n"<<setw(68)<<right<<"___________________________________________________";
			cout<<"\n\n"<<setw(55)<<right<<"Are you SURE want to LOGOUT";
			cout<<"\n\n"<<setw(46)<<right<<"[Y/N] : ";
			char YN;
			cin>>YN;
			if(YN == 'Y' || YN=='y')
				loginPage();
			else
				adminOptions();
		}
		break;
	default:
		{
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(48)<<right<<"INVALID CHOICE "<<adminChoice;
			cout<<"\n"<<setw(56)<<right<<"____________________________";
			cout<<"\n\n"<<setw(52)<<right<<"PRESS ENTER TO RENTER...";
			getch();
		}
	}
}
void AdminAccess::getnote()
{
	//string str;
	cout<<"enter note :-\n";
	//char input[100];
	cin>>str;
}
void AdminAccess::Anotice()
{
	AdminAccess a1;
	a1.getnote();

	ofstream fout;
     fout.open("notice1.txt",ios::out|ios::trunc|ios::binary);
     if(!fout)
              cout<<"File can not open";
     else{
		 	
              fout.write((char*)this,sizeof(*this));
	 			cout<<"inside\n";
				 getch();
	 }
     fout.close();
     cout<<"saved succesfully\n\n";

}




int main()
{
	EmployeeAccess e;
    e.loginPage();
	//showholiday();
	return 0;
    
}  