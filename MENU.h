#include<border.h>

char searchstudent(void)                        //search student menu    $$function:14
{   char chm;
	border();
	gotoxy(6,6);  cout<<"...........................................";
	gotoxy(6,7);  cout<<":                                         :";
	gotoxy(6,8);  cout<<":   1. Search student by Admission number :";//#7
	gotoxy(6,9);  cout<<":   2. Search student by Name             :";//#6
	gotoxy(6,10); cout<<":   3. GO BACK                            :";
	gotoxy(6,11); cout<<":                                         :";
	gotoxy(6,12); cout<<":.........................................:";
	gotoxy(6,14); cout<<"Enter your choice :";
	          cin>>chm;  return (chm);
}
char studentsmenu1(void)                        //student program menu    $$function:13
{
    char chm1;
	border();
	gotoxy(6,6);cout<<".............................................";
	gotoxy(6,7);cout<<":           What do yo wish to do           :";
	gotoxy(6,8);cout<<":...........................................:";
	gotoxy(6,9);cout<<":                                           :";
	gotoxy(6,10);cout<<":  1. Add a new student                     :"; //#1
	gotoxy(6,11);cout<<":  2. Modify data of existing student       :"; //#2
	gotoxy(6,12);cout<<":  3. Search student                        :"; //searchstudent menu
	gotoxy(6,13);cout<<":  4. View students(admno:name)             :"; //#5
	gotoxy(6,14);cout<<":  5. Remove student                        :"; //#4
	gotoxy(6,15);cout<<":  6. GO BACK                               :";
	gotoxy(6,16);cout<<":  7. EXIT                                  :";
	gotoxy(6,17);cout<<":                                           :";
	gotoxy(6,18);cout<<":...........................................:";
	gotoxy(6,20);cout<<"Enter your choice : ";
			   chm1=getche();  return (chm1);
}

int studentfeemenu(void)
{
	border();
	int sfm;
	gotoxy(6,6);cout<<"......................................";
	gotoxy(6,7);cout<<":            FEE MENU                :";
	gotoxy(6,8);cout<<":....................................:";
	gotoxy(6,9);cout<<":                                    :";
	gotoxy(6,10);cout<<":    1. Pay student's fee            :";
	gotoxy(6,11);cout<<":    2. Check payment status         :";
	gotoxy(6,12);cout<<":    3. Check payment amount         :";
	gotoxy(6,13);cout<<":    4. GO BACK                      :";
	gotoxy(6,14);cout<<":    5. EXIT                         :";
	gotoxy(6,15);cout<<":....................................:";
	gotoxy(6,17);cout<<" Enter your choice : ";
	cin>>sfm;
	return sfm;
}

int officefeemenu(void)
{
	border();
	int sfm;
	gotoxy(6,6);cout<<"......................................";
	gotoxy(6,7);cout<<":            FEE MENU                :";
	gotoxy(6,8);cout<<":....................................:";
	gotoxy(6,9);cout<<":                                    :";
	gotoxy(6,10);cout<<":    1. Enter a new fee structure    :";
	gotoxy(6,11);cout<<":    2. Edit current fee structure   :";
	gotoxy(6,12);cout<<":    3. GO BACK                      :";
	gotoxy(6,13);cout<<":    4. EXIT                         :";
	gotoxy(6,14);cout<<":....................................:";
	gotoxy(6,16);cout<<"Enter your choice : ";
	cin>>sfm;
	return sfm;
}

int programmenu()
{   
	border();
	int mc;
	gotoxy(6,6);cout<<"............................";
	gotoxy(6,7);cout<<":                          :";
	gotoxy(6,8);cout<<":    1. Fee menu           :";
	gotoxy(6,9);cout<<":    2. Student's menu     :";
	gotoxy(6,10);cout<<":    3. EXIT               :";
	gotoxy(6,11);cout<<":                          :";
	gotoxy(6,12);cout<<":..........................:";
	gotoxy(6,14);cout<<"Enter your choice : ";
	cin>>mc;
	return mc;
}
