
//**********************************************************
//	PROJECT VIDEO LIBRARY
//**********************************************************

//**********************************************************
//	INCLUDED HEADER FILES
//********************************************************** 
#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS IN THE MENU
//**********************************************************
class MENU
{
	public :
			void MAIN_MENU(void) ;
			char *CHOICE_MENU(void) ;
	private :
			void EDIT_MENU(void) ;
			void DISPLAY_MENU(void) ;
} ;

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO CASSETTE
//**********************************************************
class CASSETTE
{
	public :
			void ADDITION(void) ;
			void MODIFICATION(void) ;
			void DELETION(void) ;
			void LIST(void) ;
			void DISPLAY(void) ;
			char *CASNAME(char[], int) ;
			void UPDATE(char[], int, int, char) ;
	protected :
			int  ISSUED(char[], int) ;
			int  FOUND_CODE(char[], int) ;
			void DISPLAY_RECORD(char[], int) ;
			void DISPLAY_LIST(char[]) ;
	private :
			int  RECORDNO(char[], int) ;
			void ADD_RECORD(char[], int, char[], char,int) ;
			int  LASTCODE(char[]) ;
			void DELETE_RECORD(char[], int) ;
			int  code, custcode;
			char name[36], status ;
} ;

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO CUSTOMER
//**********************************************************
class CUSTOMER
{
	public :
			void LIST(void) ;
			void DISPLAY(void) ;
			char *CUSTNAME(int) ;
	protected :
			void ADD_RECORD(int, char[], char[], char[], int, int, int, int) ;
			void DELETE_RECORD(int) ;
			int  FOUND_CODE(int) ;
			int  LASTCODE(void) ;
			void DISPLAY_RECORD(int) ;
			int  FINE(int) ;
	private :
			int  code, cassette ;
			char name[26], phone[10], fname[13] ;
			int  dd, mm, yy ;   // DATE OF RETURN
} ;

//**********************************************************
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO ISSUE &
// RETURN & CALCULATING FINE ETC. 
//**********************************************************
class ISSUE_RETURN : public CASSETTE, public CUSTOMER
{
	public :
			void ISSUE(void) ;
			void RETURN(void) ;
			int  DIFF(int, int, int, int, int, int) ;
	private :
			void EXTEND_DATE(int,int,int,int) ;
			int  day, mon, year ;
} ;

//**********************************************************
// THIS FUNCTION CONTROL ALL THE FUNCTIONS IN THE MAIN MENU
//**********************************************************
void MENU :: MAIN_MENU(void)
{
	char ch ;

	do
	{
		clrscr() ;
		gotoxy(29,8) ;
		cout <<"VIDEO LIBRARY" ;
		gotoxy(27,11) ;
		cout <<"1: ADD NEW CASSETTE" ;
		gotoxy(27,12) ;
		cout <<"2: ISSUE CASSETTE" ;
		gotoxy(27,13) ;
		cout <<"3: RETURN CASSETTE" ;
		gotoxy(27,14) ;
		cout <<"4: DISPLAY" ;
		gotoxy(27,15) ;
		cout <<"5: EDIT" ;
		gotoxy(27,16) ;
		cout <<"0: QUIT" ;
		gotoxy(27,19) ;
		cout <<"Enter your choice:" ;
		ch = getche() ;
		clrscr() ;
		CASSETTE cas ;
		ISSUE_RETURN ir ;
		switch(ch)
		{
			case 27,'0' : break ;
			case '1' :  cas.ADDITION() ;
				  break ;
			case '2' :  ir.ISSUE() ;
						   break ;
			case '3' :  ir.RETURN() ;
				   break ;
			case '4' :  DISPLAY_MENU() ;
						 break ;
			case '5' :  EDIT_MENU() ;
				    break ;
		}
	} while (ch != 27 && ch != '0') ;
}

//**********************************************************
// THIS FUNCTION RETURNS THE NAME OF THE FILE SELECTED
//**********************************************************
char *MENU :: CHOICE_MENU(void)
{
	char ch ;
	do
	{
		clrscr() ;
		gotoxy(27,9) ;
		cout <<"SELECT CASSETTE FOR..." ;
		gotoxy(24,12) ;
		cout <<"H: HINDI FILMS" ;
		gotoxy(24,13) ;
		cout <<"E: ENGLISH FILMS" ;
		gotoxy(24,14) ;
		cout <<"N: NON FILMS" ;
		gotoxy(24,17) ;
		cout <<"Enter your choice:" ;
		ch = getche() ;
		ch = toupper(ch) ;
		clrscr() ;
		switch(ch)
		{
			case 27,'0' :  break ;
			case 'H' :  return "HINDI.DAT" ;
			case 'E' :  return "ENGLISH.DAT" ;
			case 'N' :  return "NONFILM.DAT" ;
		}
	} while (ch != 27 && ch != '0') ;
	return "FAILED" ;
}




//**********************************************************
// THIS FUNCTION CONTROL ALL THE FUNCTIONS IN THE EDIT MENU
// (MODIFICATION, DELETION).
//**********************************************************
void MENU :: EDIT_MENU(void)
{
	char ch ;
	do
	{
		clrscr() ;
		gotoxy(28,9) ;
		cout <<"EDIT MENU" ;
		gotoxy(24,12) ;
		cout <<"1: MODIFY CASSETTE" ;
		gotoxy(24,14) ;
		cout <<"2: DELETE CASSETTE" ;
		gotoxy(24,16) ;
		cout <<"0: EXIT" ;
		gotoxy(24,18) ;
		cout <<"Enter your choice:" ;
		ch = getche() ;
		clrscr() ;
		CASSETTE cas ;
		switch(ch)
		{
			case 27,'0' : break ;
			case '1' :  cas.MODIFICATION() ;
				   break ;
			case '2' :  cas.DELETION() ;
				   break ;
		}
	} while (ch != 27 && ch != '0') ;
}

//**********************************************************
// THIS FUNCTION CONTROL ALL THE FUNCTIONS RELATED TO
// DISPLAY (LIST, ETC.)
//**********************************************************
void MENU :: DISPLAY_MENU(void)
{
	char ch ;
	do
	{
		clrscr() ;
		gotoxy(28,9) ;
		cout <<"DISPLAY..." ;
		gotoxy(24,12) ;
		cout <<"1: LIST OF CASSETTE" ;
		gotoxy(24,13) ;
		cout <<"2: LIST OF CUSTOMER" ;
		gotoxy(24,14) ;
		cout <<"3: CASSETTE RECORD" ;
		gotoxy(24,15) ;
		cout <<"4: CUSTOMER RECORD" ;
		gotoxy(24,16) ;
		cout <<"0: EXIT" ;
		gotoxy(24,18) ;
		cout <<"Enter your choice:" ;
		ch = getche() ;
		clrscr() ;
		CASSETTE cas ;
		CUSTOMER cust ;
		switch(ch)
		{
			case 27,'0' : break ;
			case '1' :  cas.LIST() ;
				   break ;
			case '2' :  cust.LIST() ;
				   break ;
			case '3' :  cas.DISPLAY() ;
				   break ;
			case '4' :  cust.DISPLAY() ; 			
				    break ;
		}
	} while (ch != 27 && ch != '0') ;
}

//**********************************************************
// THIS FUNCTION RETURNS THE LAST CASSETTE'S CODE
//**********************************************************
int CASSETTE :: LASTCODE(char filename[13])
{
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(CASSETTE)))
		count = code ;
	file.close() ;
	return count ;
}

//**********************************************************
// THIS FUNCTION RETURNS 0 IF THE GIVEN CODE NOT FOUND
//**********************************************************
int CASSETTE :: FOUND_CODE(char filename[13], int cascode)
{	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{
		if (code == cascode)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}

//**********************************************************
// THIS FUNCTION RETURNS RECORD NO. OF THE GIVEN CODE
//**********************************************************
int CASSETTE :: RECORDNO(char filename[13], int cascode)
{
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	int recno=0 ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{
		recno++ ;
		if (code == cascode)
			break ;
	}
	file.close() ;
	return recno ;
}

//**********************************************************
// THIS FUNCTION RETURNS 1 IF CASSETTE IS ISSUDE FOR THE
// GIVEN CODE
//**********************************************************
int CASSETTE :: ISSUED(char filename[13], int cascode) 
{
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	int issued=0 ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{
		if (code == cascode && status == 'N')
		{
			issued = 1 ;
			break ;
		}
	}
	file.close() ;
	return issued ;
}

 //**********************************************************
// THIS FUNCTION RETURNS NAME OF THE CASSETTE FOR THE GIVEN
// CODE
//**********************************************************
char *CASSETTE :: CASNAME(char filename[13], int cascode)
{
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	char casname[36] ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{
		if (code == cascode)
		{
			strcpy(casname,name) ;
			break ;
		}
	}
	file.close() ;
	return casname ;
}

//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE CASSETTES
//**********************************************************
void CASSETTE :: DISPLAY_LIST(char filename[13])
{
	int row = 6 , found=0, flag=0 ;
	char ch ;
	gotoxy(31,2) ;
	cout <<"LIST OF CASSETTES" ;
	gotoxy(30,3) ;
	cout <<"~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(3,4) ;
	cout <<"CODE           NAME                                       STATUS" ;
	gotoxy(1,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{ 		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(4,row) ;
		cout <<code ;
		gotoxy(26,row) ;
		cout <<name ;
		gotoxy(59,row) ;
		cout <<status ;
		if ( row == 23 )
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue or Press <ESC> to exit" ;
			ch = getche() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(31,2) ;
			cout <<"LIST OF CASSETTES" ;
			gotoxy(30,3) ;
			cout <<"~~~~~~~~~~~~~~~~~~~" ;
			gotoxy(3,4) ;
			cout <<"CODE   NAME                                           STATUS" ;
			gotoxy(1,5) ;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		}
		else
			row++ ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"Records not found" ;
	}
	if (!flag)
	{
		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}

//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE CASSETTES
//**********************************************************
void CASSETTE :: LIST(void)
{
	MENU menu ;
	char filename[13] ;
	strcpy(filename,menu.CHOICE_MENU()) ;
	if (!strcmpi(filename,"FAILED"))
		return ;
	DISPLAY_LIST(filename) ;
}

//**********************************************************
// THIS FUNCTION DISPLAYS THE RECORD OF CASSETTE FOR THE
// GIVEN CODE
//**********************************************************
void CASSETTE :: DISPLAY_RECORD(char filename[13], int cascode)
{
	CUSTOMER cust ;
	fstream file ;
	file.open(filename, ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CASSETTE)))
	{
		if (code == cascode)
		{
			gotoxy(5,4) ;
			cout <<"Cassette Code # " <<code ;
			gotoxy(5,6) ;
			cout <<"Cassette Name : " <<name ;
			gotoxy(5,7) ;
			cout <<"Status : " <<status ;
			if (status == 'N' && custcode != 0)
			{
				gotoxy(5,9) ;
				cout <<"Cassette is issued by : " <<cust.CUSTNAME(custcode) ;
			}
			break ;
		}
	}
	file.close() ;
}

//**********************************************************
// THIS FUNCTION GIVES CODE TO DISPLAYS THE RECORD OF
// CASSETTE
//**********************************************************
void CASSETTE :: DISPLAY(void)
{
	MENU menu ;
	char filename[13] ;
	strcpy(filename,menu.CHOICE_MENU()) ;
	if (!strcmpi(filename,"FAILED"))
		return ;
	char t1[10] ;
	int t2, cascode ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5,5) ;
	cout <<"Enter code of the Cassette  " ;
	gets(t1) ;
	t2 = atoi(t1) ;
	cascode = t2 ;
	if (cascode == 0)
		return ;
	clrscr() ;
	if (!FOUND_CODE(filename,cascode))
	{
		gotoxy(5,5) ;
		cout <<"Record not found" ;
		getche() ;
		return ;
	}
	DISPLAY_RECORD(filename,cascode) ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
}
//**********************************************************
// THIS FUNCTION UPDATE THE GIVEN DATA IN THE CASSETTE'S
// FILE
//**********************************************************
void CASSETTE :: UPDATE(char filename[13], int cascode, int ccode, char casstatus)
{
	int recno ;
	recno = RECORDNO(filename,cascode) ;
	fstream file ;
	file.open(filename, ios::out | ios::ate) ;
	custcode = ccode ;
	status = casstatus ;
	int location ;
	location = (recno-1) * sizeof(CASSETTE) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(CASSETTE)) ;
	file.close() ;
}

//**********************************************************
// THIS FUNCTION DELETES THE RECORD OF THE GIVEN CODE.
//**********************************************************
void CASSETTE :: DELETE_RECORD(char filename[13], int cascode)
{
	fstream file ;
	file.open(filename, ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(CASSETTE)) ;
		if (file.eof())
			break ;
		if (code != cascode)
			temp.write((char *) this, sizeof(CASSETTE)) ;
	}
	file.close() ;
	temp.close() ;
	file.open(filename, ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(CASSETTE)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(CASSETTE)) ;
	}
	file.close() ;
	temp.close() ;
}

//**********************************************************
// THIS FUNCTION ADD THE GIVEN DATA IN THE CASSETTE FILE
//**********************************************************
void CASSETTE :: ADD_RECORD(char filename[13], int cascode, char casname[36], char casstatus, int ccode)
{
	fstream file ;
	file.open(filename, ios::app) ;
	code = cascode ;
	strcpy(name,casname) ;
	status = casstatus ;
	custcode = ccode ;
	file.write((char *) this, sizeof(CASSETTE)) ;
	file.close() ;
}

//**********************************************************
// THIS FUNCTION GIVES DATA TO ADD RECORD IN CASSETTE FILE
//**********************************************************
void CASSETTE :: ADDITION(void)
{
	MENU menu ;
	char filename[13], casname[36], ch ;
	int cascode, valid ;
	do
	{
		strcpy(filename,menu.CHOICE_MENU()) ;
		if (!strcmpi(filename,"FAILED"))
			return ;
		cascode = LASTCODE(filename) + 1 ;
		gotoxy(72,1) ;
		cout <<"<0>=EXIT" ;
		gotoxy(27,8) ;
		cout <<"ADDITION OF NEW CASSETTES" ;
		gotoxy(20,12) ;
		cout <<"Code # " <<cascode ;
		do
		{
			valid = 1 ;
			gotoxy(5,25) ; 
			cout <<"ENTER NAME OF THE CASSETTE" ;
			gotoxy(20,14) ;
			cout <<"                                                   " ;
			gotoxy(20,14) ;
			cout <<"Name : " ;
			gets(casname) ;
			if (casname[0] == '0')
				return ;
			if (strlen(casname) < 1 || strlen(casname) > 35)
			{
				valid = 0 ;
				gotoxy(5,25) ;  
              clreol() ;
				cout <<"Enter Correctly (Range: 1..35)" ;
				getche() ;
			}
		} while (!valid) ;
		gotoxy(5,25) ; 
clreol() ;
		do
		{
			gotoxy(20,17) ;
			cout <<"                           " ;
			gotoxy(20,17) ;
			cout <<"Do you want to save (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'Y')
		{
			char casstatus='A' ;
			int  ccode=0 ;
			ADD_RECORD(filename,cascode,casname,casstatus,ccode) ;
			cascode++ ;
		}
		do
		{
			gotoxy(20,19) ;
			cout <<"                               " ;
			gotoxy(20,19) ;
			cout <<"Do you want to Add more (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'Y' && ch != 'N') ;
		if (ch == 'N')
			return ;
	} while (ch == 'Y') ;
}

//**********************************************************
// THIS FUNCTION MODIFY THE CASSETTE RECORD
//********************************************************** 
void CASSETTE :: MODIFICATION(void)
{
	MENU menu ;
	char t1[10], ch, filename[13] ;
	int t2, cascode, valid ;
	strcpy(filename,menu.CHOICE_MENU()) ;
	if (!strcmpi(filename,"FAILED"))
		return ;
	do
	{
		valid = 1 ;
		do
		{
			clrscr() ;
			gotoxy(72,2) ;
			cout <<"<0>=EXIT" ;
			gotoxy(5,5) ;
			cout <<"Enter code of the Cassette or <ENTER> for help " ;
			gets(t1) ;
			t2 = atoi(t1) ;
			cascode = t2 ;
			if (cascode == 0 && strlen(t1) != 0)
				return ;
			if (strlen(t1) == 0)
				DISPLAY_LIST(filename) ;
		} while (strlen(t1) == 0) ;
		if (!FOUND_CODE(filename,cascode))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"Cassette code not found." ;
			getche() ;
		}
	} while (!valid) ;
	clrscr() ;
	gotoxy(72,1) ;
	cout <<"<0>=EXIT" ;
	DISPLAY_RECORD(filename,cascode) ;
	do
	{
		gotoxy(5,12) ;
 clreol() ;
		cout <<"Modify Cassette Name (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	char casname[36] ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; 
clreol() ;
		cout <<"ENTER NAME OF THE CASSETTE" ;
		gotoxy(5,15) ;	
 clreol() ;
		cout <<"Name : " ;
		gets(casname) ;
		if (casname[0] == '0')
			return ;
		if (strlen(casname) < 1 || strlen(casname) > 35)
		{ 			valid = 0 ;
			gotoxy(5,25) ; 
clreol() ;
			cout <<"Enter Correctly (Range: 1..35)" ;
			getche() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ;
 clreol() ;
	do
	{
		gotoxy(5,17) ; clreol() ;
		cout <<"Do you want to save (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	int recno ;
	recno = RECORDNO(filename,cascode) ;
	fstream file ;
	file.open(filename, ios::out | ios::ate) ;
	strcpy(name,casname) ;
	int location ;
	location = (recno-1) * sizeof(CASSETTE) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(CASSETTE)) ;
	file.close() ;
	gotoxy(5,20) ;
	cout <<"Record Modified" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
}

//**********************************************************
// THIS FUNCTION GIVES CODE TO DELETE THE CASSETTE RECORD
//********************************************************** 
void CASSETTE :: DELETION(void)
{
	MENU menu ;
	char t1[10], ch, filename[13] ;
	int t2, cascode, valid ;
	strcpy(filename,menu.CHOICE_MENU()) ;
	if (!strcmpi(filename,"FAILED"))
		return ;
	do
	{
		valid = 1 ;
		do
		{
			clrscr() ;
			gotoxy(72,2) ;
			cout <<"<0>=EXIT" ;
			gotoxy(5,5) ;
			cout <<"Enter code of the Cassette or <ENTER> for help " ;
			gets(t1) ;
			t2 = atoi(t1) ;
			cascode = t2 ;
			if (cascode == 0 && strlen(t1) != 0)
				return ;
			if (strlen(t1) == 0)
				DISPLAY_LIST(filename) ;
		} while (strlen(t1) == 0) ;
		if (!FOUND_CODE(filename,cascode))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"Cassette code not found." ;
			getche() ;
		}
	} while (!valid) ;
	clrscr() ;
	gotoxy(72,1) ;
	cout <<"<0>=EXIT" ;
	DISPLAY_RECORD(filename,cascode) ;
	do
	{
		gotoxy(5,12) ; 			
                             clreol() ;
		cout <<"Delete this Cassette Record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	DELETE_RECORD(filename,cascode) ;
	gotoxy(5,20) ;
	cout <<"Record Deleted" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
}

//**********************************************************
// THIS FUNCTION RETURNS THE LAST CUSTOMER'S CODE
//********************************************************** 
int CUSTOMER :: LASTCODE(void)
{ 	fstream file ; 
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
		count = code ;
	file.close() ;
	return count ;
}

//**********************************************************
// THIS FUNCTION RETURNS 0 IF THE GIVEN CODE NOT FOUND
//**********************************************************
int CUSTOMER :: FOUND_CODE(int custcode)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
	{
		if (code == custcode)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}

//**********************************************************
// THIS FUNCTION RETURNS NAME OF THE CUSTOMER FOR THE GIVEN
// CODE
//**********************************************************
char *CUSTOMER :: CUSTNAME(int custcode)
{
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	char custname[26] ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
	{
		if (code == custcode)
		{
			strcpy(custname,name) ;
			break ;
		}
	}
	file.close() ;
	return custname ;
}

//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE CUSTOMER
//********************************************************** 
void CUSTOMER :: LIST(void)
{ 	int row = 6 , found=0, flag=0 ;
	char ch ;
	gotoxy(31,2) ;
	cout <<"LIST OF CUSTOMERS" ;
	gotoxy(30,3) ;
	cout <<"~~~~~~~~~~~~~~~~~~~" ;
	gotoxy(3,4) ;
	cout <<"CODE   NAME                                           PHONE" ;
	gotoxy(1,5) ;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
	{
		flag = 0 ;
		delay(20) ;
		found = 1 ;
		gotoxy(4,row) ;
		cout <<code ;
		gotoxy(26,row) ;
		cout <<name ;
		gotoxy(57,row) ;
		cout<<phone ;
		if ( row == 23 )
		{
			flag = 1 ;
			row = 6 ;
			gotoxy(1,25) ;
			cout <<"Press any key to continue or Press <ESC> to exit" ;
			ch = getche() ;
			if (ch == 27)
				break ;
			clrscr() ;
			gotoxy(31,2) ;
			cout <<"LIST OF CUSTOMERS" ;
			gotoxy(30,3) ;
			cout <<"~~~~~~~~~~~~~~~~~~~" ;
			gotoxy(3,4) ;
			cout <<"CODE   NAME                                           PHONE" ;
			gotoxy(1,5) ;
			cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
		} 		else
			row++ ;
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"Records not found" ;
	}
	if (!flag)
	{ 		gotoxy(1,25) ;
		cout <<"Press any key to continue..." ;
		getche() ;
	}
	file.close () ;
}

//**********************************************************
// THIS FUNCTION DISPLAYS THE RECORD OF CUSTOMER FOR THE
// GIVEN CODE
//********************************************************** 
void CUSTOMER :: DISPLAY_RECORD(int ccode)
{
	CASSETTE cas ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
	{
		if (code == ccode)
		{
			gotoxy(5,4) ;
			cout <<"Customer Code  # " <<code ;
			gotoxy(5,6) ;
			cout <<"Customer Name  : " <<name ;
			gotoxy(5,7) ;
			cout <<"Customer Phone : " <<phone ;
			gotoxy(5,9) ;
			cout <<"Cassette Issued : " <<cas.CASNAME(fname,cassette) ;
			gotoxy(5,10) ;
			cout <<"Date of Return  : " <<dd <<"/" <<mm <<"/" <<yy ;
			break ;
		}
	}
	file.close() ;
}

//**********************************************************
// THIS FUNCTION GIVES CODE TO DISPLAYS THE RECORD OF
// CUSTOMER
//**********************************************************
void CUSTOMER :: DISPLAY(void)
{
	char t1[10] ;
	int t2, custcode ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	gotoxy(5,5) ;
	cout <<"Enter code of the Customer  " ;
	gets(t1) ;
	t2 = atoi(t1) ;
	custcode = t2 ;
	if (custcode == 0)
		return ;
	clrscr() ;
	if (!FOUND_CODE(custcode))
	{
		gotoxy(5,5) ;
		cout <<"Record not found" ;
		getche() ;
		return ;
	}

	DISPLAY_RECORD(custcode) ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
}

//**********************************************************
// THIS FUNCTION DELETES THE RECORD OF THE GIVEN CODE.
//********************************************************** 
void CUSTOMER :: DELETE_RECORD(int ccode)
{
	CASSETTE cas ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(CUSTOMER)) ;
		if ( file.eof() )
			break ;
		if ( code != ccode )
			temp.write((char *) this, sizeof(CUSTOMER)) ;
		else
			cas.UPDATE(fname,cassette,0,'A') ;
	}
	file.close() ;
	temp.close() ;
	file.open("CUSTOMER.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(CUSTOMER)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(CUSTOMER)) ;
	}
	file.close() ;
	temp.close() ;
}

//**********************************************************
// THIS FUNCTION ADDS THE GIVEN DATA IN THE CUSTOMER'S FILE
//**********************************************************
 void CUSTOMER :: ADD_RECORD(int custcode, char custname[26], char custphone[10], char filename[13], int cascode, int d, int m, int y) {
	fstream file ;
	file.open("CUSTOMER.DAT", ios::app) ;
	code = custcode ;
	strcpy(name,custname) ;
	strcpy(phone,custphone) ;
	strcpy(fname,filename) ;
	cassette = cascode ;
	dd = d ;
	mm = m ;
	yy = y ;
	file.write((char *) this, sizeof(CUSTOMER)) ;
	file.close() ;
}

//**********************************************************
// THIS FUNCTION CALCULATE AND RETURN FINE FOR THE GIVEN
// CUSTOMER CODE.
//**********************************************************
int CUSTOMER :: FINE(int ccode) {
	ISSUE_RETURN ir ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	fstream file ;
	file.open("CUSTOMER.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int days, t_fine ;
	while (file.read((char *) this, sizeof(CUSTOMER)))
	{
		if (code == ccode)
		{
			days = ir.DIFF(dd,mm,yy,d1,m1,y1) ;
			t_fine = days * 20 ;
			break ;
		}
	}
	file.close() ;
	return t_fine ;
}

//**********************************************************
// FUNCTION TO EXTEND GIVEN DATE BY 5 DAYS
//**********************************************************
void ISSUE_RETURN :: EXTEND_DATE(int d1, int m1, int y1, int days)
{
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	for (int i=1; i<=days; i++)
	{
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	} 	day  = d1 ;
	mon  = m1 ;
	year = y1 ;
}

//**********************************************************
// THIS FUNCTION RETURN THE DIFFERENCE BETWEEN TWO GIVEN
// DATES
//********************************************************** 
int ISSUE_RETURN :: DIFF(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days = 0 ;
	if ((y2<y1) || (y2==y1 && m2<m1) || (y2==y1 && m2==m1 && d2<d1))
		return days ;
	static int month[] = {31,29,31,30,31,30,31,31,30,31,30,31} ;
	while (d1 != d2 || m1 != m2 || y1 != y2)
	{
		days++ ;
		d1++ ;
		if ((d1 > month[m1-1]) || (y1%4 != 0 && m1 == 2 && d1 > 28))
		{
			d1 = 1 ;
			m1++ ;
		}
		if (m1 > 12)
		{
			m1 = 1 ;
			y1++ ;
		}
	}
	return days ;
} 

//**********************************************************
// THIS FUNCTION ISSUE CASSETTE TO THE CUSTOMER & GIVE DATA
// TO ADD RECORD IN CUSTOMER'S FILE
//********************************************************** 
void ISSUE_RETURN :: ISSUE(void)
{
	MENU menu ;
	CUSTOMER cust ;
	CASSETTE cas ;
	char filename[13] ;
	strcpy(filename,menu.CHOICE_MENU()) ;
	if (!strcmpi(filename,"FAILED"))
		return ;
	char t1[10] ;
	int t2, cascode, valid ;
	do
	{
		valid = 1 ;
		do
		{
			clrscr() ;
			gotoxy(72,2) ;
			cout <<"<0>=EXIT" ;
			gotoxy(5,5) ;
			cout <<"Enter code of the Cassette or <ENTER> for help " ;
			gets(t1) ;
			t2 = atoi(t1) ;
			cascode = t2 ;
			if (cascode == 0 && strlen(t1) != 0)
				return ;
			if (strlen(t1) == 0)
				DISPLAY_LIST(filename) ;
		} while (strlen(t1) == 0) ;
		if (!CASSETTE::FOUND_CODE(filename,cascode))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"Cassette code not found. Kindly choose another." ;
			getche() ;
		}
		if (valid && ISSUED(filename,cascode))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"Cassette already issued. Kindly choose another." ;
			getche() ;
		}
	} while (!valid) ;
	clrscr() ;
	int ccode ;
	ccode = CUSTOMER::LASTCODE() + 1 ;
	char custname[26], custphone[10] ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(5,2) ;
	cout <<"Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(72,2) ;
	cout <<"<0>=EXIT" ;
	CASSETTE::DISPLAY_RECORD(filename,cascode) ;
gotoxy(5,10) ;
	cout <<"Customer Code # " <<ccode ;
	gotoxy(5,12) ;
	cout <<"Name   : " ;
	gotoxy(5,13) ;
	cout <<"Phone  : " ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"Enter the name of the Customer" ;
		gotoxy(14,12) ; clreol() ;
		gets(custname) ;
		strupr(custname) ;
		if (custname[0] == '0')
			return ;
		if (strlen(custname) < 1 || strlen(custname) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter correctly (Range: 1..25)" ;
			getche() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; 	
clreol() ;
		cout <<"Enter Phone no. of the Customer" ;
		gotoxy(14,13) ; 
clreol() ;
		gets(custphone) ;
		if (custphone[0] == '0')
			return ;
		if ((strlen(custphone) < 7 && strlen(custphone) > 0) || (strlen(custphone) > 9))
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"Enter correctly" ;
			getche() ;
		}
	} while (!valid) ;
	gotoxy(5,25) ; 
clreol() ;
	UPDATE(filename,cascode,ccode,'N') ;
	EXTEND_DATE(d1,m1,y1,5) ;
	d1 = day ;
	m1 = mon ;
	y1 = year ;
	CUSTOMER::ADD_RECORD(ccode,custname,custphone,filename,cascode,d1,m1,y1) ;
	gotoxy(5,17) ;
	cout <<"CASSETTE ISSUED" ;
	gotoxy(5,19) ;
	cout <<"Date of Return : " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
}

//**********************************************************
// THIS FUNCTION RETURN CASSETTE FROM THE CUSTOMER
//**********************************************************
void ISSUE_RETURN :: RETURN(void)
{
	CUSTOMER cust ;
	char t1[10], ch ;
	int t2, ccode, valid ;
	do
	{
		valid = 1 ;
		do
		{
			clrscr() ;
			gotoxy(72,2) ;
			cout <<"<0>=EXIT" ;
			gotoxy(5,5) ;
			cout <<"Enter code of the Customer or <ENTER> for help " ;
			gets(t1) ;
			t2 = atoi(t1) ;
			ccode = t2 ;
			if (ccode == 0 && strlen(t1) != 0)
				return ;
			if (strlen(t1) == 0)
				cust.LIST() ;
		} while (strlen(t1) == 0) ;
		if (!CUSTOMER::FOUND_CODE(ccode))
		{
			valid = 0 ;
			gotoxy(5,20) ;
			cout <<"Customer code not found." ;
			getche() ;
		}
	} while (!valid) ;
	clrscr() ;
	CUSTOMER::DISPLAY_RECORD(ccode) ;
	int d1, m1, y1 ;
	struct date d;
	getdate(&d);
	d1 = d.da_day ;
	m1 = d.da_mon ;
	y1 = d.da_year ;
	gotoxy(5,2) ;
	cout <<"Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	do
	{	gotoxy(5,13) ; clreol() ;
		cout <<"Return Cassette (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	int f=FINE(ccode) ;
	if (f != 0)
	{
		gotoxy(5,16) ;
		cout <<"You have to pay a fine of Rs." <<f ;
		gotoxy(5,17) ;
		cout <<"Please do not delay the Return of Cassette again" ;
	}
	CUSTOMER::DELETE_RECORD(ccode) ;
	gotoxy(5,20) ;
	cout <<"Cassette Returned" ;
	gotoxy(5,25) ;
	cout <<"Press any key to continue..." ;
	getche() ;
} 






//**********************************************************
// MAIN FUNCTION CALLING MAIN MENU
//********************************************************** 
void main(void)
{
	MENU menu ;
	menu.MAIN_MENU() ;
}
















