#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>
#include<MENU.h>


int Searchstudentn(char[]);
char Searchstudenta(int);
void removestudent(int);
void writestudent(void);
void updatestudent1(void);
int Searchbyname(char[25]);
void searchstudent1(void);
char studentsmenu1(void);
char searchstudent(void);
void studentsprg(void);
void viewstudent1(void);
void payfees1();
void checkfees1();
void showstudfee1();
void putpayfees(int);
void showstudfee(int);
void writestudfee(int,char[]);
void writestreamfee(int);
int programmenu(void);
void delayprg(void);

int flagG=1,flagF=1;
char ch;

class student
{
	int    admno;
	char   name[25];
	int   std;
	char   division;
	char   gender;
	char   blood[4];
	char   address[50];
	char   adharno[15];
	char   phno[15];
	char   mothername[25];
	char   fathername[25];
	char   stream[15];
	char   substream[6];
	struct dob{ int d,m,y;}dob;

   public:
	
	void addstudent(int);
    void displaystudent(void);
	void modifystudent(void);
	void dispstudent(void);

	int   retadmno()      {return admno;}			
	char* retname()       {return name;}			
	char  retgender()     {return gender;}		
	char* retadharno()    {return adharno;}		
	char* retaddress()    {return address;}		
	int   retclass()      {return std;}			
	char  retdivision()   {return division;}		
	char* retblood()      {return blood;}			
	char* retphno()       {return phno;}			
	char* retmothername() {return mothername;}		
	char* retfathername() {return fathername;}		
	char* retstream()     {return stream;}			

};

class studfee
 {
	int admnos;
	int streamnos;
	char initials;
	char terms[3];

	public:

	studfee(int admission,char streams[15]);
	studfee(){}

	void checkfee();
	void payfee(int aterm);



	int retadmnos()    {return admnos;}
	char retinitials() {return initials;}
	char retterm1()    {return terms[0];}
	char retterm2()    {return terms[1];}
	char retterm3()    {return terms[2];}
};

studfee::studfee(int admission,char streams[15])
	{
		admnos=admission;
		if(strcmpi(streams,"Bio-Maths")==0)
			streamnos=1;
		else if(strcmpi(streams,"Bio-IP")==0)
			streamnos=2;
		else if(strcmpi(streams,"computer")==0)
			streamnos=3;
		else if(strcmpi(streams,"Commerce-IP"))
			streamnos=4;
		else
			streamnos=5;

		for(int i=0;i<3;i++)
			terms[i]='N';
		initials='N';
	}

void student::addstudent(int x)
    {
	    border();
	    admno=x;        
	    gotoxy(4,4);  cout<<"Enter the details of the student";
		gotoxy(4,5);  cout<<" Name           : ";  gets(name);
		gotoxy(4,6);  cout<<" Class          : ";  cin>>std;
		gotoxy(4,7);  cout<<" DOB(In number) : DAY-    ";  cin>>dob.d;
		gotoxy(4,8);  cout<<"                   MONTH- ";  cin>>dob.m;
		gotoxy(4,9);  cout<<"                   YEAR-  ";  cin>>dob.y;
		gotoxy(4,10); cout<<" Gender(M/F)    : ";  gender=getche();
		gotoxy(4,11); cout<<" Address        : ";  gets(address);
		gotoxy(4,12); cout<<" Aadhar number  : ";  gets(adharno);
		gotoxy(4,13); cout<<" Phone number   : ";  gets(phno);
		gotoxy(4,14); cout<<" Blood group    : ";  gets(blood);
		gotoxy(4,15); cout<<" Father's name  : ";  gets(fathername);
		gotoxy(4,16); cout<<" Mother's name  : ";  gets(mothername);
		gotoxy(4,18); cout<<"Enter the STREAM of student";
		gotoxy(4,19); cout<<"(Bio-maths/Bio-IP/Computer/Commerce)    :";  gets(stream);

		
		if(strcmpi(stream,"bio-IP")==0)
			division='A';
		else if(strcmpi(stream,"bio-maths")==0)
			division='B';
		else if(strcmpi(stream,"computer")==0)
			division='C';
		else if(strcmpi(stream,"commerce")==0)
			division='D';

		if(strcmpi(stream,"commerce")==0)
			{
				gotoxy(4,20);cout<<"Enter the substream(IP/EP/Maths)";
				gotoxy(4,21);cin>>substream;
				
				if(strcmpi(substream,"IP")==0)
					strcat(stream,"-IP");
				else if(strcmpi(substream,"EP")==0)
					strcat(stream,"-EP");
				else if(strcmpi(substream,"Maths")==0)
					strcat(stream,"-Maths");
			}

		writestudfee(admno,stream);
	}

 void student::displaystudent(void)
    {
		border();
		gotoxy(4,4);  cout<<" Admission No   : ";  cout<<admno;
		gotoxy(4,5);  cout<<" Name           : ";  cout<<name;
		gotoxy(4,6);  cout<<" Class          : ";  cout<<std;
		gotoxy(4,7);  cout<<" Division       : ";  cout<<division;
		gotoxy(4,8);  cout<<" DOB            : ";  cout<<dob.d<<"-"<<dob.m<<"-"<<dob.y;
		gotoxy(4,9);  cout<<" Stream         : ";  cout<<stream;
		gotoxy(4,10); cout<<" Gender(M/F)    : ";  cout<<gender;
		gotoxy(4,11); cout<<" Address        : ";  cout<<address;
		gotoxy(4,12); cout<<" Aadhar number  : ";  cout<<adharno;
		gotoxy(4,13); cout<<" Blood group    : ";  cout<<blood;
		gotoxy(4,14); cout<<" Phone number   : ";  cout<<phno;
		gotoxy(4,15); cout<<" Father's name  : ";  cout<<fathername;
		gotoxy(4,16); cout<<" Mother's name  : ";  cout<<mothername;
		getch();
	}
	
void student::modifystudent(void)
	{
		int choice2;
		dispstudent();
		gotoxy(4,17);cout<<"Enter the field of midification";  cin>>choice2;
		
		switch(choice2)
		{
			case 1: gotoxy(4,18);cout<<"Current Name: "<<name;
					gotoxy(4,19);cout<<"Enter the new Name: "; gets(name); break;

			case 2: gotoxy(4,18);cout<<"Current Class: "<<std;
					gotoxy(4,19);cout<<"Enter the new Class: ";cin>>std;  break;

			case 3: gotoxy(4,18);cout<<"Current Stream: "<<stream;
					gotoxy(4,19);cout<<"Enter the new Stream: "; gets(stream);
					if(strcmpi(stream,"commerce")==0)
					{
						gotoxy(4,21);cout<<"Enter the substream(IP/EP/Maths)";
						gotoxy(4,22);cin>>substream;
						
						if(strcmpi(substream,"IP")==0)
							strcat(stream,"-IP");
						else if(strcmpi(substream,"EP")==0)
							strcat(stream,"-EP");
						else if(strcmpi(substream,"Maths")==0)
							strcat(stream,"-Maths");
					}
						break;

			case 4: gotoxy(4,18);cout<<"Current DOB    : "<<dob.d<<"-"<<dob.m<<"-"<<dob.y;
					gotoxy(4,19);cout<<"Enter the DOB  : "; cin>>dob.d>>dob.m>>dob.y;  break;

			case 5: gotoxy(4,18);cout<<"Current Gender:"<<gender;
					gotoxy(4,19);cout<<"Modification(Male-M/Femlale-F):"; gender=getche(); break;

			case 6: gotoxy(4,18);cout<<"Current Address:"<<address;
					gotoxy(4,19);cout<<"New Address:"; gets(address);  break;

			case 7: gotoxy(4,18);cout<<"Current Aadhar number: "<<adharno;
					gotoxy(4,19);cout<<"Enter the Aadhar number: "; cin>>adharno; break;

			case 8: gotoxy(4,18);cout<<"Current Blood group : "<<blood;
					gotoxy(4,19);cout<<"Enter the Blood group:"; gets(blood); break;

			case 9: gotoxy(4,18);cout<<"Current Phone number : "<<phno;
					gotoxy(4,19);cout<<"New Phone number:"; gets(phno);  break;

			case 10:gotoxy(4,18);cout<<"Father's name  : "<<fathername;
					gotoxy(4,19);cout<<"Enter Name     : "; gets(fathername);		break;

			case 11:gotoxy(4,18);cout<<"Mother's name  : "<<mothername;
					gotoxy(4,19);cout<<"Enter Name     : "; gets(mothername); break;

		}
	}
	
void student::dispstudent(void)
	{
		border();
		gotoxy(4,6);  cout<<" 1. Name           : ";  cout<<name;
		gotoxy(4,7);  cout<<" 2. Class          : ";  cout<<std;
		gotoxy(4,8);  cout<<" 3. Stream         : ";  cout<<stream;
		gotoxy(4,9);  cout<<" 4. DOB            : ";  cout<<dob.d<<"-"<<dob.m<<"-"<<dob.y;
		gotoxy(4,10); cout<<" 5. Gender(M/F)    : ";  cout<<gender;
		gotoxy(4,11); cout<<" 6. Address        : ";  cout<<address;
		gotoxy(4,12); cout<<" 7. Aadhar number  : ";  cout<<adharno;
		gotoxy(4,13); cout<<" 8. Blood group    : ";  cout<<blood;
		gotoxy(4,14); cout<<" 9. Phone number   : ";  cout<<phno;
		gotoxy(4,15); cout<<"10. Father's name  : ";  cout<<fathername;
		gotoxy(4,16); cout<<"11. Mother's name  : ";  cout<<mothername;
	}

class fee
{
	
	int establish;
	int exam,library,PT,ID,medical;
	int laboratory,computer,caution;
	int total,tution,std;
	
	public:
	
	void getfee(int);
	void changefee();
	
	int retstd()        {return std;}
    int retestablish()  {return establish;}
	int retexam()       {return exam;}
	int retlibrary()    {return library;}
	int retPT()         {return PT;}
	int retID()         {return ID;}
	int retmedical()    {return medical;}
	int retlaboratory() {return laboratory;}
	int retcomputer()   {return computer;}
	int retcaution()    {return caution;}
	int rettution()     {return tution;}
	int rettotal()      {return total;}
}FEE;

void fee::getfee(int a)
{
	border();
	std=a;
	gotoxy(4,4);  cout<<":----------------------------------:";
	gotoxy(4,5);  cout<<":  Enter the fee details           :";
	gotoxy(4,6);  cout<<":__________________________________:";
	gotoxy(4,8);  cout<<"  1. Establishment Fee    : ";  cin>>establish;
	gotoxy(4,9);  cout<<"  2. Exam Fee             : ";  cin>>exam;
	gotoxy(4,10); cout<<"  3. Library Fee          : ";  cin>>library;
	gotoxy(4,11); cout<<"  4. Sports & Games       : ";  cin>>PT;
	gotoxy(4,12); cout<<"  5. ID card              : ";  cin>>ID;
	gotoxy(4,13); cout<<"  6. Medical Fee          : ";  cin>>medical;
	gotoxy(4,14); cout<<"  7. Laboratory Fee       : ";  cin>>laboratory;
	gotoxy(4,15); cout<<"  8. Computer Fee         : ";  cin>>computer;
	gotoxy(4,16); cout<<"  9. Caution Deposit      : ";  cin>>caution;
	gotoxy(4,17); cout<<" 10. Tution Fee           : ";  cin>>tution;
}

void fee::changefee()
{
	int sfm;
	border();
	gotoxy(4,4);  cout<<":----------------------------------:";
	gotoxy(4,5);  cout<<":  Enter the fee details           :";
	gotoxy(4,6);  cout<<":__________________________________:";
	gotoxy(4,8);  cout<<"          Class : ";  cout<<std;
	gotoxy(4,9);  cout<<"  1. Establishment Fee   : ";  cout<<establish;
	gotoxy(4,10); cout<<"  2. Exam Fee            : ";  cout<<exam;
	gotoxy(4,11); cout<<"  3. Library Fee         : ";  cout<<library;
	gotoxy(4,12); cout<<"  4. Sports & Games      : ";  cout<<PT;
	gotoxy(4,13); cout<<"  5. ID card             : ";  cout<<ID;
	gotoxy(4,14); cout<<"  6. Medical Fee         : ";  cout<<medical;
	gotoxy(4,15); cout<<"  7. Laboratory Fee      : ";  cout<<laboratory;
	gotoxy(4,16); cout<<"  8. Computer Fee        : ";  cout<<computer;
	gotoxy(4,17); cout<<"  9. Caution Deposit     : ";  cout<<caution;
	gotoxy(4,18); cout<<" 10: Tution Fee          : ";  cout<<tution;
	gotoxy(4,20); cout<<"Enter the field to change";
	cin>>sfm;
    
    switch(sfm)
	{
		case 1 : gotoxy(4,21);cout<<"Enter the Establishment Fee : "; cin>>establish; break;
		case 2 : gotoxy(4,21);cout<<"Enter the Exam Fee : "; cin>>exam; break;
		case 3 : gotoxy(4,21);cout<<"Enter the Library Fee : ";  cin>>library; break;
		case 4 : gotoxy(4,21);cout<<"Enter the Sports & Games fee : ";  cin>>PT; break;
		case 5 : gotoxy(4,21);cout<<"Enter the fee for ID card : ";  cin>>ID; break;
		case 6 : gotoxy(4,21);cout<<"Enter the Medical Fee : ";  cin>>medical; break;
		case 7 : gotoxy(4,21);cout<<"Enter the Laboratory Fee : ";  cin>>laboratory; break;
		case 8 : gotoxy(4,21);cout<<"Enter the Computer Fee : ";  cin>>computer; break;
		case 9 : gotoxy(4,21);cout<<"Enter the Caution Deposit : ";  cin>>caution; break;
		case 10: gotoxy(4,21);cout<<"Enter the Tution Fee : ";  cin>>tution; break;
	}
}

class streamfees
{
	 int streamno;
	 char streamf[15];
	 int stdf;
	 int initial;
	 int payfee;
	 int schoice;



    public:

	void getstreamfee(int afee,int a);

	int retinitial()   {return initial;}	
    int retpayfee()    {return payfee;}
	int retstreamno()  {return streamno;}
	char* retstreamf() {return streamf;}
	int retstdfs()     {return stdf;}
};

void streamfees::getstreamfee(int afee,int a)
{
	stdf=a;
	switch(afee)
	{
		case 1:strcpy(streamf,"Bio-Maths"); streamno=afee;
		case 2:strcpy(streamf,"Bio-IP"); streamno=afee;
		case 3:strcpy(streamf,"Compu ter"); streamno=afee;
		case 4:strcpy(streamf,"Commerce-IP"); streamno=afee;
		case 5:strcpy(streamf,"Commerce-EP/Maths"); streamno=afee;
	}

	initial=F.retestablish()+F.retexam()+F.retlibrary()+F.retPT()+F.retID()+F.retmedical()+F.retcaution();
	payfee=F.rettution();

	switch(afee)
	{
		case 1:
		case 2:
		case 3:	initial+=F.retlaboratory();break;
	}

	if(afee==2||afee==3||afee==4)
		{ payfee+=F.retcomputer();}
}

void studfee::checkfee()
	{
		border();
		
		if(initials=='N')
		{
			gotoxy(5,5); cout<<"Initial Amount: Not paid";
		}
		else
		{
			gotoxy(5,5); cout<<"Initial Amount: Paid";
		}

		for(int i=0;i<3;i++)
		{
			if(terms[i]=='N')
			{
				gotoxy(5,i+6);cout<<" Term-"<<i+1<<" Fee : Not Paid";
			}

			else
			{
				gotoxy(5,i+6);cout<<" Term-"<<i+1<<" Fee: Paid";
			}
		}
		getch();
	}
	
void studfee::payfee(int aterm)
	{
		border();
		char paychoice;
		if(toupper(initials)=='N')
		{
			gotoxy(4,4);cout<<"Initial amount not paid.....Ask to pay";   getch();		
			delay(500);
			
			gotoxy(4,5);cout<<"Has the amount Initial amount paid(Y/N)";
			cin>>paychoice;
			if(toupper(paychoice)=='Y')
				initials='Y';
			else
				initials='N';
		}
		if(toupper(terms[aterm])=='Y')
		{
			gotoxy(5,7); cout<<"Term fee already paid";
		}
		else
		{
			if(initials=='Y')
			{
				gotoxy(5,7); cout<<"Ask to pay the amount for Term-"<<aterm;
				gotoxy(5,8); cout<<"Has the amount for Term-"<<aterm<<" fee paid(Y/N) : ";
				cin>>paychoice;
				
				if(tolower(paychoice)=='y')
					terms[aterm]='Y';
				else
					terms[aterm]='N';
			}
		}
	}

void writefee(void)
{
	border();
	char chf;
	int flagf=0;
	int s=0;
	ifstream fin("fee.DAT",ios::in|ios::binary);
	ofstream fout("temp.DAT",ios::out|ios::binary);

	if(!fout)
	   {  border(); gotoxy(8,10); cout<<"File not opened correctly";    getch();   exit (0);}

	fee F,F1;

	gotoxy(4,4);cout<<"Enter the class ";  cin>>s;

	while(fin.read((char*)&F,sizeof(F)))
	{
		if(F.retstd()==s)
		{
			flagf=1;
			gotoxy(4,6); cout<<"Record already exists";
			gotoxy(4,7); cout<<"Do you want to renew it(Y/N)  : "; chf=getche();
			if(tolower(chf)=='y')
				F.getfee(s);

		}	

		fout.write((char*)&F,sizeof(F));
	}

	if(flagf==0)
	{
		F.getfee(s);
		fout.write((char*)&F,sizeof(F));
	}
	fin.close();
	fout.close();
	remove("fee.DAT");
	rename("temp.DAT","fee.DAT");
	writestreamfee();
}

void rewritefee(void)
{
	border();
	int rcls,flags=0;
	fstream fin("fee.DAT",ios::in|ios::binary);
	ofstream ftemp("temp.DAT",ios::out|ios::binary|ios::app);
	
	if(!fin||!ftemp)
	{cout<<"File not opened correctly";    getch();   exit (0);}

	fee F;

	fin.seekg(0,ios::end);
	if(fin.tellg()==0)
	{gotoxy(6,7); cout<<"No fee data available to change"; getch(); return;}
	fin.seekg(0,ios::beg);

	gotoxy(4,4);cout<<"Enter the class";
	cin>>rcls;
	while(fin.read((char*)&F,sizeof(F)))
	{
		if(rcls==F.retstd())
		{
			F.changefee();
			flags=1;
		}

		ftemp.write((char*)&F,sizeof(F));
	}
	if(flags==0)
		{ gotoxy(4,5); cout<<"Record of class : "<<rcls<<" not found to change "; getch(); }

	fin.close();
	ftemp.close();
	remove("fee.DAT");
	rename("temp.DAT","fee.DAT");
	writestreamfee();
}

void writestreamfee()
{
	ifstream fin("fee.DAT",ios::in|ios::binary);
	ofstream temp("temp.DAT",ios::out|ios::binary|ios::app);

	streamfee S;

	while(fin.read((char*)&FEE,sizeof(FEE)))
	{
	  for(int i=11;i<=12;i++)
		if(FEE.retstd()==i)
		  for(int i1=0;i1<5;i1++)
		  {
			S.getstreamfee(i1,i);
			temp.write((char*)&S,sizeof(S));
		  }
	}
	fin.close();
	temp.close();
	remove("streamfee.DAT");
	rename("temp.DAT","streamfee.DAT");
}

void writestudfee(int no,char string[15])
{
	studfee S(no,string);
	ofstream fout("studfee.DAT",ios::in|ios::binary|ios::app);
	fout.write((char*)&S,sizeof(S));
	fout.close();
}

void putpayfees(int n)
{
	border();
	int a;
	ifstream fin("studfee.DAT",ios::in|ios::binary);
	ofstream fout("temp.DAT",ios::out|ios::binary);
	studfee F;
	while(fin.read((char*)&F,sizeof(F)))
	{
		if(F.retadmnos()==n)
		{
			gotoxy(4,4);cout<<"Enter the Term of fee to be paid : ";
			cin>>a;
			F.payfee(a);
		}
		fout.write((char*)&F,sizeof(F));
	}
	fin.close();
	fout.close();
	remove("studfee.DAT");
	rename("temp.DAT","studfee.DAT");
}

void showstudfee(int s,int a)
{
	int flags=1;
	ifstream fin("streamfee.DAT",ios::in|ios::binary);
	streamfees F;
	if(!fin){cout<<"File opening ...ERROR....."; getch(); exit (0);}

	while(fin.read((char*)&F,sizeof(F)))
	{
		if(F.retstdfs()==s)
		{
			flags=0;
			if(F.retstreamno()==a)
			{
				border();
				gotoxy(4,5);cout<<"Payable by student at starting of year :"<<F.retinitial()<<" Rs";
				gotoxy(4,6);cout<<"Fees in each term                      :"<<F.retpayfee()<<" Rs";
				getch();
			}
		}
	}
	if(flags==1)
		{ cout<<"Entered class not found"; getch(); }

	fin.close();
}

void checkfees(int a)
{
	ifstream fin("studfee.DAT",ios::in|ios::binary);
	studfee S;
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(S.retadmnos()==a)
		{
			S.checkfee();
			return;
		}
	}	
	
}
void checkfees1(void)
{
	int ckf;
	char chp;
	int adm;
	char A[25];

	while(flagG)
	{
		border();
		gotoxy(4,5);cout<<"Get student by:";
		gotoxy(4,6);cout<<"1.Admission number";
		gotoxy(4,7);cout<<"2.Name";
		gotoxy(4,8);cout<<"3.GO BACK";
		gotoxy(4,9);cin>>ckf;
		if(ckf==1)
		{
			gotoxy(4,11);cout<<"Enter the admission number : ";
			cin>>adm;
			chp=Searchstudenta(adm);
			if(chp=='y')
				checkfees(adm);                    /*function call*/   ///function not written
			else
				gotoxy(4,12);cout<<"Student not Found";
		}

		else if(ckf==2)
		{   
			gotoxy(4,11);cout<<"Enter the student name: ";
			gotoxy(4,12); gets(A);
			adm=Searchbyname(A);
			if(adm!=0)
				checkfees(adm);                       /*function call*/   ///function not written
			else
				gotoxy(4,14);cout<<"Student not Found";
		}

		else if(ckf==3)
			flagG=0;

		else
		{
			gotoxy(4,5);cout<<"WRONG CHOICE......TRY AGAIN....";
			getch();
		}
	}
	flagG=1;
}

void payfees1(void)
{
	char chp;
	int kkm;
	int adm;
	flagG=1;
	char A[25];
	while(1)
	{
		border();
		gotoxy(4,5); cout<<"Get student by:";
		gotoxy(4,6); cout<<"1.Admission number";
		gotoxy(4,7); cout<<"2.Name";
		gotoxy(4,8); cout<<"3.GO BACK";
		gotoxy(4,9); cin>>kkm;


		if(kkm==1)
		{
			gotoxy(4,11);cout<<"Enter the admission number : ";
			cin>>adm;
			chp=Searchstudenta(adm);
			if(chp=='y')
				putpayfees(adm);
			else
				gotoxy(4,13);cout<<"Student not Found";
		}

		else if(kkm==2)
		{   
			gotoxy(4,11);cout<<"Enter the name of student: "; 
			gotoxy(4,12);gets(A);
			adm=Searchbyname(A);
			if(adm!=0)
				putpayfees(adm);
			else
				gotoxy(4,14);cout<<"Student not Found";
		}
	
		else if(kkm==3)
			return;
			
		else
		{
			gotoxy(4,11);cout<<"WRONG CHOICE......TRY AGAIN....";
			getch();
		}
		
   }
}

//not in real program: written to check whether the file is written correctly
void showstudfee1(void)  
{
 border();
 streamfees F;
 ifstream fin("streamfee.DAT",ios::in|ios::binary);
 int i=4;
 while(fin.read((char*)&F,sizeof(F)))
	{
		border();
		gotoxy(4,i); cout<<F.retstdfs();
		gotoxy(4,i+1); cout<<F.retinitial();
		gotoxy(4,i+2);cout<<F.retpayfee();
		gotoxy(4,i+5); cout<<F.retstreamf();
		gotoxy(4,i+4); cout<<F.retstreamno();
		getch();
	}
}
void writestudent(void)
 {

    int x1;
	char ch2;
	fstream fp("Gstudent.DAT",ios::binary|ios::out|ios::in);
	
    if(!fp)
    {
      gotoxy(8,7);cout<<"File opening ERROR!!!!";
      getch();
      return;
    }
	
	while(1)
	 {
	    border();
	    student S;
		fp.seekg(0,ios::end);
		
	    if(fp.tellg()==0)    
		    x1=1031;

	    else
		{
		  fp.seekp(fp.tellg()-sizeof(S));
		  fp.read((char*)&S,sizeof(S));
		  x1=S.retadmno();
		  x1+=1;
		}

		S.addstudent(x1);
		fp.write((char*)&S,sizeof(S));
		
		border();
		
		gotoxy(4,4);cout<<"Do you want to add another student(Y/N):"; ch2=getche();
		             
		if(tolower(ch2)!='y')
		{
			fp.close();
				return;
		}
		
	 }

 }
 	
void viewstudent1(void) 
 {
	border();
	int v1=0; 
	int check=0;
	int flags=0;
 
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
   
	if(!fin)
		{
			gotoxy(5,6);cout<<"File not opened correctly"; getch(); return;
		}
	student S;
   
	while(fin)
		{
			border();
			for(v1=0;v1<10;v1++)
			{
				if(fin.read((char*)&S,sizeof(S)))
				{
					if(check!=S.retadmno())
						gotoxy(4,v1+4); cout<<S.retadmno()<<" : "<<S.retname();
					flags=1;
				}
			
				else 
				{
					gotoxy(4,v1+6);cout<<"END OF STUDENT LIST";
					while(v1<10)
					{
						v1++;
						gotoxy(4,v1+6); cout<<"......";
					}
					flagG=0;
					flags=0;
				}
				
				if(flags==1)
					check=S.retadmno();
		}
		gotoxy(8,v1+6);cout<<"PRESS ENTER";
		getch();
	}
	flagG=1;
	fin.close();	
 } 	
 
 int Searchbyname(char A[25])
 {  
	student S;
	char ch3;
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);  ///file opening
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(strcmpi(A,S.retname())==0)
		{
			S.displaystudent();                              
			gotoxy(4,18);cout<<" Is this the required student(Y/N)";
			ch3=getche();

			if(tolower(ch3)=='y')
			{
				fin.close(); 
				return (S.retadmno());
			}
		}
	}
	border();
	gotoxy(10,10); cout<<"STUDENT NOT FOUND";
	getch();
	fin.close();
	return 0;
}

void updatestudent(int a)                       
{
	border();
	int choice2;
	student S;
	
	ofstream ftemp("temp.DAT",ios::out|ios::binary|ios::app);
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
	
	if(!ftemp||!fin)  { gotoxy(10,10); cout<<"File not opened correctly"; getch(); return;}

	while(fin.read((char*)&S,sizeof(S)))
	{
		if(S.retadmno ()==a)
		{
			S.modifystudent();

		}
		ftemp.write((char*)&S,sizeof(S));
	}
	ftemp.close();
	fin.close();
	remove("Gstudent.DAT");
	rename("temp.DAT","Gstudent.DAT");
}	

void removestudent(int a)
{
	int choice2;
	student S;
	studfee F;
	ofstream ftemp("temp.DAT",ios::out|ios::binary|ios::app);
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
	ofstream fftemp("ftemp.DAT",ios::out|ios::binary|ios::app);
	ifstream ffin("studfee.DAT",ios::in|ios::binary);
	
	if(!fin||!ffin||!ftemp||!fftemp)
		{  border(); gotoxy(8,10); cout<<"File not opened correctly";    getch();   exit (0);}

	
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(S.retadmno()!=a)
			ftemp.write((char*)&S,sizeof(S));	
	}	
	while(ffin.read((char*)&F,sizeof(F)))
	{
		if(F.retadmnos()!=a)
			fftemp.write((char*)&F,sizeof(F));
	}
	
	ftemp.close();   fin.close();   fftemp.close();   ffin.close();
	remove("studfee.DAT");        rename("ftemp","studfee.DAT");
	remove("Gstudent.DAT");       rename("temp.DAT","Gstudent.DAT");
}

char Searchstudenta(int adm)
{
	
	border();
	char ch3;
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
	student S;
	while(fin.read((char*)&S,sizeof(S)))
	{
		if(adm==S.retadmno())
		{
			S.displaystudent();
			gotoxy(4,19);cout<<"Is this the required student(Y/N)";
			cin>>ch3;
			if(tolower(ch3)=='y')
			{ 
				fin.close();
				return ch3;
			}
		
			else
			{
				ch3='n';
				fin.close();
				return ch3;
			}
		}
	}
	ch3='n';
	fin.close();
	return ch3;
}

void searchstudentn(char A[25])
{
	border();
	student S;
	char ch3;
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
	while(fin.read((char*)&S,sizeof(S)))
	{
		border();
		if(strcmpi(A,S.retname())==0)
		{
			S.displaystudent();
			gotoxy(4,18);cout<<"Is this the required student(Y/N) : ";
			ch3=getche();
			ch3=tolower(ch3);
			
			if(ch3=='y')
			{
				gotoxy(6,20);cout<<"Press 'Enter'";  getch();
				fin.close();
				return;
			}
		}
	}
	border();
	gotoxy(8,10);cout<<"STUDENT NOT FOUND";	getch();
	fin.close();
}

void searchstudenta(int a) 
{
	student S;
	ifstream fin("Gstudent.DAT",ios::in|ios::binary);
	while(fin.read((char*)&S,sizeof(S)))
	{
		border();
		if(S.retadmno()==a)
		{
			S.displaystudent();
			getch();
			fin.close();
			return;
		}
	}
	border();
	gotoxy(4,7);cout<<"Student with admission number "<<a<<" not available"; getch();
	fin.close();
}	
void updatestudent1(void)
{
	char chup;
	int a;
	char N[25];
	while(flagG)
	{
	  border();
	  ch=searchstudent();
	  switch(ch)
	  {
		  case '1': gotoxy(4,16); cout<<"Enter the admission number";
					cin>>a;  updatestudent(a); break;					
		  case '2': gotoxy(4,16); cout<<"Enter the name:"; gets(N);
					a=Searchbyname(N); updatestudent(a); break;					
		  case '3': flagG=0; break;		  
		  default : gotoxy(4,16);cout<<"You have entered a wrong choice";
			        gotoxy(4,17);cout<<"Please re-enter choice"; flagG=2;
	  }

	  if(flagG==1)
	  {
		 gotoxy(4,21);cout<<"Do you want to get another student(Y/N) : ";  chup=getche();
		 if(tolower(chup)!='y')
			 flagG=0;
	  }
	}
	flagG=1;
}

void removestudent1(void)
{
	border();
	char chr,nam[25];
	int adm;
	while(flagG)
	{

		ch=searchstudent();
		border();

		if(ch=='1')
		{
			gotoxy(5,7);cout<<"Enter the admission number : ";
			cin>>adm;
			ch=Searchstudenta(adm);
			if(ch=='y')
			{
	
					removestudent(adm);
			}

		}
		
		else if(ch=='2')
		{
			cout<<"Enter the Name of student : ";
			gets(nam);
			adm=Searchbyname(nam);

			if(adm!=0);
			{
					removestudent(adm);
			}
		}

		else if(ch=='3')
			flagG=0;

		else
		{
			 gotoxy(6,7);cout<<"You have entered a wrong choice";
		     gotoxy(6,8);cout<<"Please re-enter choice";  flagG=2;
		}

		if(flagG==1)
	     {
			border();
			gotoxy(4,8);cout<<"Do you want to search for another student ";
			cin>>chr;
			chr=tolower(chr);
			if(tolower(chr)!='y')
				flagG=0;
		 }

	}
	flagG=1;
}
void searchstudent1(void)
{
	border();
	char chs1,N[25];
	int adm;
	
	while(flagG)
	  {
		 border();
	     ch=searchstudent();
		 switch(ch)
			{
				case '1': gotoxy(4,16);cout<<"Enter the Admission number : ";cin>>adm;
						  searchstudenta(adm); break;						
				case '2': gotoxy(4,16);cout<<"Enter the Name";gets(N);
						  searchstudentn(N); break;						
				case '3': flagG=0; break;			 
				default : gotoxy(4,16);cout<<"You have entered a wrong choice";
						  gotoxy(4,17);cout<<"Please re-enter choice";  flagG=2;
			}
		if(flagG==1)
			{
				gotoxy(4,22);cout<<"Do you want to search another student(Y/N) "; chs1=getche();	
			}		
		if(tolower(chs1)!='y')
			flagG=0;
	  }
	 flagG=1;
}

void delayprg(void)
{
      int kd=0;
      while(kd<3)
        {
		 border();
		 gotoxy(10,10);cout<<"loading";
		 for(int i=0;i<3;i++)
			{	 delay(450); cout<<".";	 }
        }
}	

void officefeeprg(void)
{
	int feeprg;
	while(1)
	{
		feeprg=officefeemenu();
		switch(feeprg)
		{
			case 1: writefee();      break;
			case 2: rewritefee();    break;
			case 3: return;
			case 4: exit(0);
			default:gotoxy(6,18); cout<<"WRONG CHOICE?????? ...PRESS ENTER......."; getch();
		}
	}
}

void studfeeprg(void)
{
	int feeprg;
	while(flagF)
	{
		feeprg=studfeemenu();
		switch(feeprg)
		{
			case 1: payfees1();    break;
			case 2: checkfees1();  break;
			case 3: showstudfee1();break;
			case 4: flagF=0;       break;
			case 5: exit (0);
			default:gotoxy(6,19);cout<<"WRONG CHOICE?????? ...PRESS ENTER.......";
		}
	}
	flagF=1;
}

void studentprg(void)
{
	border();
	char chs1,flags='1';
	while(flags=='1')
	{
		chs1=studentsmenu1();
		switch(chs1)
		{
			case '1': writestudent();    break;
			case '2': updatestudent1();  break;
			case '3': searchstudent1();  break;
			case '4': viewstudent1();    break;
			case '5': removestudent1();  break;
			case '6': flags='0';         break;
			case '7': exit (0);
			default : gotoxy(6,21);cout<<"You have entered a wrong choice";
					  gotoxy(6,22);cout<<"Please re-enter your choice";
		}
	}
}

void feeprg(void)
{
	int fpg;
	while(1)
	{
		border();
		gotoxy(9,4);  cout<<"..................................";
		gotoxy(9,5);  cout<<":         FEE MENU               :";
		gotoxy(9,6);  cout<<":--------------------------------:";
		gotoxy(9,7);  cout<<":                                :";
		gotoxy(9,8);  cout<<":     1. FEE RECORD(OFFICE)      :";
		gotoxy(9,9);  cout<<":     2. STUDENTS FEE MENU       :";
		gotoxy(9,10); cout<<":     3. GO BACK                 :";
		gotoxy(9,11); cout<<":................................:";
		gotoxy(9,14);cout<<"Enter yor choice :"; cin>>fpg;

		if(fpg==3)  return;			
		switch(fpg)
		{
			case 1: officefeeprg(); break;
			case 2: studfeeprg();   break;
			default: gotoxy(9,16);cout<<"WRONG CHOICE????????????????  ...TRY AGAIN.....";
		}
	}
}