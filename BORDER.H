
void border()
{
	clrscr();
	cout<<"|"<<setfill('-')<<setw(79)<<"|";
	cout<<"|";gotoxy(28,2);cout<<"STUDENTS SYSTEM MANAGEMENT";
	gotoxy(80,2);cout<<"|";
	cout<<"|"<<setfill('-')<<setw(79)<<"|";
	for(int i=3;i<=23.5;++i)
	{
		cout<<"|";gotoxy(80,i);cout<<"|";
	}
	cout<<"|"<<setfill('-')<<setw(79)<<"|";	
}
