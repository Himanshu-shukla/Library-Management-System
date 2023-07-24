/*

	Title			: Library Management System
	Language		: C++
	Author			: Himanshu Shukla
	Date Created	: 17-07-2016
	Last Modified	: 12-03-2017

*/

#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>

//MARK:- Interface Functions Here =>

void intro() {
	cout<<"\n\n\t            ";
	cout<<"     C++ Project On Library Management System";
	cout<<"\n\n\t\t\t\t     MADE BY";
	cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t Himanshu Shukla\t\t\t      ||";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t\t  \t\t\t\t      ||";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void head() {
	clrscr();
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"\t\t\t\t\t\t\t\t\t       ";
	cout<<"\t\t\t\t   Delhi Public Library\t\t\t       ";
	cout<<"\t\t\t\t\t\t\t\t\t       ";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void delay() {
	int i=0;
	long long j;
	cout<<"	\n\n\n	Connecting to Server\n 	Syncing DaTa";
	while(i<10)	{
		for (j=5;j>4;j++) {
			if (j==99999) {
				cout<<".";
				break;
			}
		}
		++i;
	}
}

//MARK:- Library Class Here =>

class library {
	private:
			int book_no;
			char name[30];
			char address[50];
			char phone[15];
			int days;
			float fare;
	public:
			void main_menu();		//to display the main menu
			void add();				//to rent a book
			void display(); 		//to display the student record
			void books();			//to display rented books
			void edit();			//to edit the student record
			int check(int);	     	//to check book status
			void modify(int);		//to modify the record
			void delete_rec(int);   //to delete the record
};

void library::main_menu() {
	int choice;
	while(choice!=5) {
		clrscr();
		head();
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *";
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Rent a book";
		cout<<"\n\t\t\t2.student Record";
		cout<<"\n\t\t\t3.Books Rented";
		cout<<"\n\t\t\t4.Edit Record";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice) {
			case 1:	add();
					break;
			case 2: display();
					break;
			case 3: books();
					break;
			case 4:	edit();
					break;
			case 5: break;
			default: {
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to continue....!!";
				getch();
			}
		}
	}
}

void library::add() {
	clrscr();
	head();
	int r,flag;
	ofstream fout("Record.dat",ios::app);
	cout<<"\n Enter Student Details";
	cout<<"\n ----------------------";
	cout<<"\n\n Book no: ";
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Sorry..!!!Book not available";
	else {
		book_no=r;
		cout<<" Name: ";
		gets(name);
		cout<<" Address: ";
		gets(address);
		cout<<" Phone No: ";
		gets(phone);
		cout<<" No of Days Books allotted for";
		cin>>days;
		fare=days*2;						//2 is currently set as the default price per day
		fout.write((char*)this,sizeof(library));
		cout<<"\n Book Allotted...!!!";
	}

	cout<<"\n Press any key to continue.....!!";
	getch();
	fout.close();
}

void library::display() {
	clrscr();
	head();
	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n Enter book no: ";
	cin>>r;
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(library));
		if(book_no==r) {
			clrscr();
			head();
			cout<<"\n student Details";
			cout<<"\n ----------------";
			cout<<"\n\n Book no: "<<book_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			cout<<"\n Days: "<<days;
			cout<<"\n Total Fare: "<<fare;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\n Sorry Book no. not found or vacant....!!";
	cout<<"\n\n Press any key to continue....!!";
	getch();
	fin.close();
}

void library::books() {
	clrscr();
	head();
	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t    List Of Books Allotted";
	cout<<"\n\t\t\t    ----------------------";
	while( fin.read((char*)this,sizeof(library))) {
		cout<<"\n Book no: "<<book_no<<"\n Name: "<<name;
		cout<<"\n Address: "<<address<<"\n Phone: "<<phone;
		cout<<"\n Days: "<<days<<"\n Total: "<<fare;
		cout<<"\n**********************************";
	}
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}

void library::edit() {
	clrscr();
	head();
	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.Modify student Record";
	cout<<"\n 2.Delete student Record";
	cout<<"\n Enter your choice: ";
	cin>>choice;

	clrscr();
	head();
	cout<<"\n Enter book no: " ;
	cin>>r;
	switch(choice) {
		case 1:	modify(r);
				break;
		case 2:	delete_rec(r);
				break;
		default: cout<<"\n Wrong Choice.....!!";
	}
	cout<<"\n Press any key to continue....!!!";
	getch();
}


int library::check(int r) {
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(library));
		if(book_no==r) {
			flag=1;
			break;
		}
	}

	fin.close();
	return(flag);
}

void library::modify(int r) {
	clrscr();
	head();
	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);
	while(!file.eof()) {
		pos=file.tellg();
		file.read((char*)this,sizeof(library));
		if(book_no==r) {
			cout<<"\n Enter New Details";
			cout<<"\n -----------------";
			cout<<"\n Name: ";
			gets(name);
			cout<<" Address: ";
			gets(address);
			cout<<" Phone no: ";
			gets(phone);
			cout<<" Days: ";
			cin>>days;
			fare=days*900;
			file.seekg(pos);
			file.write((char*)this,sizeof(library));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Book no. not found or vacant...!!";
	file.close();
}

void library::delete_rec(int r) {
	clrscr();
	head();
	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(library));
		if(book_no==r) {
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone No: "<<phone;
			cout<<"\n Days: "<<days;
			cout<<"\n Total Fare: "<<fare;
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;
			if(ch=='n')
				fout.write((char*)this,sizeof(library));
			flag=1;
			break;
		}
		else
			fout.write((char*)this,sizeof(library));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry book no. not available...!!";
	else {
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}

//MARK:- Main() Function Here =>

int main() {
	textbackground(GREEN);
	textcolor(0);
	library h;
	clrscr();
	cout<<"\n\n\n";
	intro();
	delay();
	cout<<"\n\n\n\t\t\tPress any key to continue....!!";

	getch();
	clrscr();
	head();
	char id[5],pass[7];
	cout<<"\n\n\t\t\t\tusername => ";
	cin>>id;
	cout<<"\n\t\t\t\tpassword => ";
	cin>>pass;
	cout<<"\n\n\t";
	delay();
	cout<<"\t";
	if(strcmp(id,"admin")==0&&strcmp(pass,"******")==0)
		cout<<"\n\n\t\t\t  !!!Login Successfull!!!";
	else {
		cout<<"\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
		getch();
		exit(-1);
	}
	clrscr();
	h.main_menu();
	getch();

	return 0;
}







