#include<bits/stdc++.h>         //includes all the C++ standard header files
#include<conio.h>
#include<math.h>
#include<windows.h>        //The header file in particular includes the library and functions used in the libraries like stdio.h or stdlib.h.//
#include<ctime>   //time ko lagi header

using namespace std;
struct order
{
      int prodid1;
      char pname1[50];
      int qty1;
      float price1,dis1;
}o1[50];
int orderk=0;


void write_customer();
void copyme(int k,order order1[],int q1,int &c2);
int getproduct();
int getcustomers();
void product_detail_heading();
void customer_detail_heading();
void prod_tabular();
int before_order();
void cust_menu1();
void cust_menu2();
void cust_menu3();
void modify_record(int n);
void delete_record(int n);
void againopenandclose();
void againopenandclosecust();
void display_sp(int n);
void customerMenu();
void productMenu();
int search(int p);
void write_book();
void place_order();
void display_cust_sp(int n);
void cust_tabular();
void modify_cust_record(int n);
void deletecust_record(int n);
void userMainMenu();
void gotoxy(short x, short y);
void loading();
void welcome();
void mainMenu();
int Login();
string ctime();
void readReport();


	
int main()
{
	loading();
	welcome();
	getch();
	return 0;
	
}


void gotoxy(short x, short y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void loading()
	{

		char l[] = {'L','O','A','D','I','N','G','.','.','.','.'};
		gotoxy(17,15);
		for(int i=0;i<10;i++)
			{
				cout<<l[i]<<'\t';
			}
		cout<<endl;
		Sleep(2000);  
		system("CLS");
	}



//Function that is called as you open program
void welcome()
	{
	string staff;
	cout<<"\n\n\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                           		                                  |>\n";
	cout<<"\t\t\t<|                                  WELCOME TO                                            |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                 Khwopa Engineering College Canteen Service                             |>\n";
	cout<<"\t\t\t<|                       Mind Works When Stomach is Full                                  |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                                                                                        |>\n";
	cout<<"\t\t\t<|                 Enter USER or ADMIN to access respective section                       |>\n";
	cout<<"\t\t\t<|                                    "; cin>>staff;  	
	cout<<"\t\t\t<|________________________________________________________________________________________|>\n\n";
	
	if (staff=="admin" | staff=="ADMIN" | staff == "Admin")
	{
		Sleep(700);
		system("CLS ");
		Login();
	}
			
			
	else if (staff=="user" | staff=="USER" | staff=="User") 
	{
		Sleep(700);
		system("CLS ");
		userMainMenu();
	}
	else
	system("CLS");
	gotoxy(17,15);
	cout<<"\t\t\t\t\nenter valid value"<<endl;
	Sleep(1500);
	system("CLS");
	welcome();		

}

//Login function 
int Login()
{
    label:
    cout<<endl;
     
      string q,w,username;
      int x;string s;
    cout<<"\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< __________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|                      All round canteen service                                   |>\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|              1 : REGISTER                                                        |>\n";
	cout<<"\t\t\t<|              2 : LOGIN                                                           |>\n";
	cout<<"\t\t\t<|              3 : EXIT                       		                            |>\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|                                                                                  |>\n";
	cout<<"\t\t\t<|                            ENTER YOUR CHOICE                                     |>\n";
	cout<<"\t\t\t<|                                    "; cin>>x;  
	cout<<"\t\t\t<|__________________________________________________________________________________|>\n";
	Sleep(1200);
	system("CLS");	


      ofstream fout;
      if(x==1)
      { 
      	cout<<"\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"\t\t\t< __________________________________________________________________________________ >\n";
		cout<<"\t\t\t<|                                                                                  |>\n";
		cout<<"\t\t\t<|                                   REGISTER                                       |>\n";
		cout<<"\t\t\t<|                                                                                  |>\n";
		cout<<"\t\t\t<|                                                                                  |>\n";
		cout<<"\t\t\t<|                                                                                  |>\n";
		cout<<"\t\t\t<|                             ENTER YOUR USER NAME                                 |>\n";
		cout<<"\t\t\t<|                                  ";cin>>s ; 
		cout<<"\t\t\t<|                             ENTER YOUR PASSWORD                                  |>\n"; 
		cout<<"\t\t\t<|                                   ";
		char pass[30];
		char ch;
		bool Enter =false;
		int i=0;
		while(!Enter)
			{
			
			ch=getch();
		    if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')) \
				{
            pass[i]=ch; //store the ch to the pass
            cout << '*';
            i++;
        		}
           if (ch=='\b' && i>=1) 
		   		{
            cout << "\b \b"; //to delete wrong character that user input
            i--;
        		}
           if (ch=='\r')  //r is Enter or 13 charecter code (enter)   // It is used to bring the cursor to the beginning of the line not to the next line, like \n
            Enter = true;      				
			}
		cout<<"\n\t\t\t<|                                                                                  |>\n";
		cout<<"\t\t\t<|                                                                                  |>\n";
	 	s=s+pass;
                  ifstream fin;
                  string line;
                  int offset=0;
                  fin.open("myfile.txt",ios::binary|ios::in|ios::out);
                  if(fin.is_open())
                  {
                        while(!fin.eof())
                        {
                              getline(fin,line);
                              if(line.find(s,0)!=-1)        //for the purpose : if not found -1 dinxa coz,,,If the element pointed by the iterator with the specified range is found, then it will return the first element of the entire range of elements otherwise it will return the last element.
                              {
                                    cout<<"\t\t\t<|                     Sorry! This username is not available                        |>\n";
									cout<<"\t\t\t<|                                                                                  |>\n";
									cout<<"\t\t\t<|                                                                                  |>\n";
									cout<<"\t\t\t<|__________________________________________________________________________________|>\n";
	
									Sleep(1200);
									system("CLS");
                                    goto label;
                              }
                        }
                  }
                fin.close();
                fout.open("myfile.txt",ios::binary|ios::app);
                fout<<s+"\n";
                fout.close();
                cout<<"\t\t\t<|                                                                                  |>\n";
                cout<<"\t\t\t<|                             REGISTER SUCCESSFUL                                  |>\n";
				cout<<"\t\t\t<|                                                                                  |>\n";
				cout<<"\t\t\t<|__________________________________________________________________________________|>\n";
				Sleep(1500);
				system("CLS");
	            goto label;
                            
      }
      else if(x==2){
            string line;
            ifstream fin;
            int offset=0;
            cout<<"\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
			cout<<"\t\t\t< __________________________________________________________________________________ >\n";
			cout<<"\t\t\t<|                                                                                  |>\n";
			cout<<"\t\t\t<|                                   LOGIN                                          |>\n";
			cout<<"\t\t\t<|                                                                                  |>\n";
			cout<<"\t\t\t<|                                                                                  |>\n";
			cout<<"\t\t\t<|                                                                                  |>\n";
			cout<<"\t\t\t<|                             ENTER YOUR USER NAME                                 |>\n";
			cout<<"\t\t\t<|                                  ";cin>>q ; 
			cout<<"\t\t\t<|                             ENTER YOUR PASSWORD                                  |>\n";
			cout<<"\t\t\t<|                                   ";
			char passw[30];
			char cha;
			bool Enter =false;
			int i=0;
			while(!Enter)
			{
			
			cha=getch();
		    if ((cha>='a' && cha<='z') || (cha>='A' && cha<='Z') || (cha>='0' && cha<='9')) 
				{
            passw[i]=cha; //store the ch to the pass
            cout << '*';
            i++;
        		}
           if (cha=='\b' && i>=1) 
		   		{
            cout << "\b \b"; //to delete wrong character that user input
            i--;
        		}
           if (cha=='\r')  //r is Enter or 13 charecter code (enter)
            Enter = true;      				
			}
			
			
			cout<<"\n\t\t\t<|                                                                                  |>\n";
			cout<<"\t\t\t<|                                                                                  |>\n";
			username = q;	
            q=q+passw;
            fin.open("myfile.txt",ios::binary|ios::app);
            if(fin.is_open())
            {
                  while(!fin.eof())
                  {
                        getline(fin,line);
                        if(line.find(q,0)!=-1)    //vetayena vane -1    
                        {
                            cout<<"\t\t\t<|                              You are logged in !!                                |>\n";
							cout<<"\t\t\t<|                                                                                  |>\n";
							cout<<"\t\t\t<|                                                                                  |>\n";
							cout<<"\t\t\t<|__________________________________________________________________________________|>\n";
							Sleep(1200);
							system("CLS");
							
							offset=1; 
							mainMenu();                                         
                		}
                  }
                  if(offset==0)
                  {
                        cout<<"\t\t\t<|                             Sorry, You are unauthorised!!                        |>\n";
						cout<<"\t\t\t<|                                                                                  |>\n";
						cout<<"\t\t\t<|                                                                                  |>\n";
						cout<<"\t\t\t<|__________________________________________________________________________________|>\n";
						Sleep(1200);
						system("CLS");
                        goto label;
                  }
            }
            fin.close();
      }
      else if(x==3)
      {
            return 0;
      }
      else
      {
		gotoxy(17,15);
		cout<<"Please enter any valid value \n";
		Sleep(1200);
		system("CLS");
		goto label;
		  
      }
 }
 
 
 //admin's main menu	
void mainMenu()
{	
	int num;

//	gotoxy(15,2);
 char ch;
      do
      {
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                  Hello, You are welcomed !                            |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";       
	cout<<"\t\t\t<|     1 : MENU DISPLAY                              		                         |>\n";
	cout<<"\t\t\t<|     2 : CREATE NEW CUSTOMER DETAIL           		                         |>\n";
	cout<<"\t\t\t<|     3 : VIEW SPECIFIC CUSTOMER DETAIL      		                                 |>\n";       
	cout<<"\t\t\t<|     4 : PRODUCT SECTION                 		                                 |>\n";
	cout<<"\t\t\t<|     5 : CUSTOMER SECTION                 		                                 |>\n";
	cout<<"\t\t\t<|     6 : FINANCE REPORT                 		                                 |>\n";
	cout<<"\t\t\t<|     7 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          "; cin>>ch  ;              		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";
	Sleep(1000);
	system("CLS");

            switch(ch)
            {
            	case '1':
                        againopenandclose();
						prod_tabular();			
						cin.ignore();
						system("CLS");
						mainMenu();
                        break;
                case '2':
                        write_customer();
                        system("CLS");
                        mainMenu();
                        break;
                case '3':
                        system("CLS");
						cout<<"\t\t\tENTER YOUR CUST ID :";
                  		cin>>num;
                  		display_cust_sp(num);
                  		cin.ignore();
                  		system("CLS");
                        mainMenu();                  		
                        break;
                case '4':
                        productMenu();
                        break;
                case '5':
                        customerMenu();
                        break;
                case '6':
                        readReport();
                        system("pause");
                        system("CLS");
                        mainMenu();
                        break;
                case '7':
                        exit(0);
                default :
                    cout<<"Please enter valid option"<<endl;
                    Sleep(1200);
                    mainMenu();
            }
      }while(ch!='8');
      
    }
    
    
    //Main menu of user when entered
void userMainMenu()
{
	int num;
 	char ch;
      do
      {
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                  Hello, You are welcomed !                            |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|     1 : PLACE ORDER                          		                         |>\n";        
	cout<<"\t\t\t<|     2 : MENU DISPLAY                              		                         |>\n";
	cout<<"\t\t\t<|     3 : CREATE NEW CUSTOMER DETAIL           		                         |>\n";
//	cout<<"\t\t\t<|     4 : VIEW YOUR DETAIL                 		                                 |>\n"; 
	cout<<"\t\t\t<|     4 : SEARCH SPECIFIC PRODUCT BY PRODUCT NUMBER                                     |>\n";      
	cout<<"\t\t\t<|     5 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          "; cin>>ch  ;              		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";
	Sleep(1000);
	system("CLS");

            switch(ch)
            {
                case '1':
                        place_order();
                        break;
            	case '2':
                        againopenandclose();
						prod_tabular();			
						cin.ignore();
						system("CLS");
						userMainMenu();
                        break;
                case '3':
                        write_customer();
                        system("CLS");
                        userMainMenu();
                        break;
//                case '4':
//                        system("CLS");
//						cout<<"\t\t\tENTER YOUR CUST ID :";
//                  		cin>>num;
//                  		display_cust_sp(num);
//                  		cin.ignore();
//                  		system("CLS");
//                        userMainMenu();                  		
//                        break;
                case '4':
                        system("CLS");
						cout<<"\n\n\n\n\t\t\t\tENTER THE PRODUCT ID TO BE SEARCHED:";
                  		cin>>num;
                  		display_sp(num);
                  		system("pause");
                  		system("CLS");
						userMainMenu();
                        break;
                case '5':
                        exit(0);
                default :
                    cout<<"Please enter valid option"<<endl;
                    Sleep(1200);
                    mainMenu();
            }
      }while(ch!='8');
      
    }


//only accessed to admin when wanted to watch more on product    
void productMenu()
	{	
	char chE;
	char ch2;
	int num;
      do
      {
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                  MENU SECTION                                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|     1 : MENU DISPLAY                              		                         |>\n";
	cout<<"\t\t\t<|     2 : ADD PRODUCT                             		                         |>\n";
	cout<<"\t\t\t<|     3 : MODIFY PRODUCT                 		                                 |>\n";          
	cout<<"\t\t\t<|     4 : DELETE PRODUCT                		                                 |>\n";
	cout<<"\t\t\t<|     5 : SEARCH SPECIFIC PRODUCT BY PRODUCT NUMBER                                     |>\n";
	cout<<"\t\t\t<|     6 : RETURN TO HOME PAGE                   	                                 |>\n";
	cout<<"\t\t\t<|     7 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                           "; cin>>chE    ;            		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";
	Sleep(1000);
	system("CLS");


            switch(chE)
            {
                case '1':
                		prod_tabular();
                		cout<<"\t\t\t\t\n\n\n";
                		system("pause");
                		system("CLS");
                        productMenu();
                        break;
            	case '2':
                        write_book();
                        productMenu();
                        break;
                case '3':
                		system("CLS");
						prod_tabular();
                  		cout<<"\n\n\n\n\t\t\t\tENTER THE PRODUCT ID TO BE MODIFIED:";
                  		cin>>num;
                  		modify_record(num);
                        productMenu();
                        break;
                case '4':
                		system("CLS");
						prod_tabular();
                  		cout<<"\n\n\n\n\t\t\t\tENTER THE PRODUCT ID TO BE DELETED:";
                  		cin>>num;
                  		delete_record(num);
                        productMenu();
                        break;
                case '5':
                        system("CLS");
						cout<<"\n\n\n\n\t\t\t\tENTER THE PRODUCT ID TO BE SEARCHED:";
                  		cin>>num;
                  		display_sp(num);
                  		system("pause");
                  		system("CLS");
						productMenu();
                        break;
                case '6':
                        mainMenu();
                        break;
                case '7':
                        exit(0);
                  default :
                        cout<<"Please enter valid option"<<endl;
                        productMenu();
            }
      }while(chE!='7');
    }



//only accessed to admin when want to watch more on customer
void customerMenu()
	{	

	char chA;
    int numb;
      do
      {
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                  CUSTOMER SECTION                                     |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|     1 : ALL CUSTOMER DETAIL                        		                         |>\n";
	cout<<"\t\t\t<|     2 : ADD CUSTOMER                             		                         |>\n";
	cout<<"\t\t\t<|     3 : MODIFY CUSTOMER INFORMATION                                                   |>\n";         
	cout<<"\t\t\t<|     4 : DELETE CUSTOMER                                                               |>\n";
	cout<<"\t\t\t<|     5 : SEARCH SPECIFIC CUSTOMER                                                      |>\n";
	cout<<"\t\t\t<|     6 : RETURN TO HOME PAGE                      		                         |>\n";
	cout<<"\t\t\t<|     7 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                           "; cin>>chA    ;            		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";


            switch(chA)
            {
                case '1':
                		Sleep(700);
				  		system("CLS");
				  		cust_tabular();
				  		cin.ignore();
				  		system("CLS");
                        customerMenu();
                        break;
            	case '2':
                        write_customer();
                        customerMenu();
                        break;
                case '3':
                		Sleep(700);
						system("CLS");
						cust_tabular();
                  		cout<<"\n\t\t\tENTER THE CUST ID TO BE MODIFIED:";
                  		cin>>numb;
                  		Sleep(800);
						system("CLS");
                  		modify_cust_record(numb);
                  		Sleep(1000);
                  		system("CLS");
                        customerMenu();
                        break;
                case '4':
                		Sleep(700);
						system("CLS");
						cust_tabular();
                  		cout<<"\n\t\t\tENTER THE CUST ID TO BE DELETED:";
                  		cin>>numb;
                  		deletecust_record(numb);
                        Sleep(1000);
                  		system("CLS");
						  customerMenu();
                        break;
                case '5':
                        Sleep(700);
						system("CLS");
						cout<<"\t\t\tENTER THE CUST ID TO BE SEARCHED:";
                  		cin>>numb;
                  		display_cust_sp(numb);
                  		cin.ignore();
                  		Sleep(1000);
                  		system("CLS");
						customerMenu();
                        break;
                case '6':
                        Sleep(700);
                        system("CLS");
						mainMenu();
                        break;
                case '7':
                        exit(0);
                default :
                        cout<<"Please enter valid option"<<endl;
                        customerMenu();
            }
      }while(chA!='7');
    }



//Product class starts here:
class product
{
      int prodid;
      char name[50];
      char company[50];
      int qty;
      float price,dis;
      public:
      product()
      {
            qty=0;
            price=0;
            dis=0;
      }
      void modifydata(int n1,char snm[15],int q);          
      void create_prod(int rn1)
      {
             cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
             cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
             cout<<"\t\t\tPRODUCT NO: ";
             prodid=rn1;
             cout<<prodid<<endl;                         // auto save the product id as 1 2 3 4 .. count ++ done at function getproduct
             cout<<"\t\t\tNAME OF PRODUCT:"<<endl;
             cout<<"\t\t\t";
             cin>>name;
             cout<<"\t\t\tPRODUCT PRICE:"<<endl;
             cout<<"\t\t\t";
             cin>>price;
             cout<<"\t\t\tQUANTITY:"<<endl;
             cout<<"\t\t\t";
             cin>>qty;
             cout<<"\t\t\tDISCOUNT%:"<<endl;
             cout<<"\t\t\t";
             cin>>dis;
             cout<<"\t\t\t< ________________________________________________________________________>\n";
      }
      void show_prod()
      {
             cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
             cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
             cout<<"\t\t\tPRODUCT NO            : "<<prodid<<endl;
             cout<<"\t\t\tNAME OF PRODUCT       : "<<name<<endl;
             cout<<"\t\t\tPRODUCT PRICE         : "<<price<<endl;
             cout<<"\t\t\tQUANTITY              : "<<qty<<endl;
             cout<<"\t\t\tDISCOUNT%             : "<<dis<<"%"<<endl;
             cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
       }
      //Function shows product data in tabular form
      void showall()
      {
            cout<<"\t\t\t\t "<<prodid<<setw(15)<<name<<setw(11)<<"Rs."<<price<<setw(10)<<qty<<setw(13)<<dis<<"%"<<endl;
      }
      int retpno()
      {
           return prodid;
      }
      float retprice()
      {
           return price;
      }
      char* getname()
      {
          return name;
      }
      int getqty()
      {
          return qty;
      }
      float retdis()
      {
          return dis;
      }
      void setqty(int q21)
      {
          qty=q21;
      }
};
// Product class ends here




// Fuction to modify product details
void product::modifydata(int n1,char snm[15],int q)
{
      char tmpnm[40],tmpnm2[40];
      char yes1,yes2,yes3,yes4,yes5;
       cout<<"\t\t\tPRODUCT NO: ";
       prodid=n1;
       cout<<"\t\t\t\t"<<prodid<<endl;
       strcpy(name,snm);      
       cout<<"\t\t\tNAME OF PRODUCT:";
       cout<<name<<endl;
       cout<<"\t\t\tWant to change the name of product ? (Yes[ y or Y ] or NO [n or N])"<<endl;
       int flag=0;
       while(1)
       {
            cout<<"\t\t\t";
			cin>>yes1;
            if(yes1== 'Y' || yes1== 'y')
            {
                  cout<<"\t\t\tEnter new name\n";
                  cout<<"\t\t\t";
                  cin>>tmpnm;
                  flag=1;
                  break;
            }
            if(yes1== 'N' || yes1== 'n')
            {
                  flag=0;
                  break;
            }
       }
       if(flag==1)
       {
            strcpy(name,tmpnm);
       }

      int tmpprc=0;
      cout<<"\t\t\tWant to change the price of product ? (Yes[ y or Y ] or NO [n or N])"<<endl;
      flag=0;
      while(1)
      {
            cout<<"\t\t\t";
			cin>>yes2;
            if(yes2== 'Y' || yes2== 'y')
            {
                  cout<<"\t\t\tEnter new price:\n";
                  cout<<"\t\t\t";
                  cin>>tmpprc;
                  flag=1;
                  break;
            }
            if(yes2== 'N' || yes2== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            price=tmpprc;
      }
      
      int tmpqty=0;
      cout<<"\t\t\tWant to change the quantity of product ? (Yes[ y or Y ] or NO [n or N])"<<endl;
      flag=0;
      while(1)
      {
            cout<<"\t\t\t";
			cin>>yes4;
            if(yes4== 'Y' || yes4== 'y')
            {
                  cout<<"\t\t\tEnter new quantity:\n";
                  cout<<"\t\t\t";
                  cin>>tmpqty;
                  flag=1;
                  break;
            }
            if(yes4== 'N' || yes4== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            qty=tmpqty;
      }

     float tmpdis=0;
      cout<<"\t\t\tWant to change the discount of product ? (Yes[ y or Y ] or NO [n or N])"<<endl;
      flag=0;
      while(1)
      {
            cout<<"\t\t\t";
			cin>>yes5;
            if(yes5== 'Y' || yes5== 'y')
            {
                  cout<<"\t\t\tEnter new discount"<<'%'<<"on the product:\n";
				  cout<<"\t\t\t";
                  cin>>tmpdis;
                  flag=1;
                  break;
            }
            if(yes5== 'N' || yes5== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            dis=tmpdis;
      }
      if((yes3== 'Y' || yes3== 'y') || (yes2== 'Y' || yes2== 'y') || (yes1== 'Y' || yes1== 'y') || (yes4== 'Y' || yes4== 'y') || (yes5== 'Y' || yes5== 'y'))
            {
            cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   NEW PRODUCT RECORD SAVED   ^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t< ________________________________________________________________________>\n";
			}
      else
            {
            cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   NO PRODUCT RECORD CHANGED   ^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t< ________________________________________________________________________>\n";
			}
}



//modify record of product
void modify_record(int n)
{
      product st,temp;
      char tmpnm[50],tmpcompany[50];
      ifstream inFile;
      int fpos=-1;
      inFile.open("product.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\n\t\t\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==n)
            {
                  st.show_prod();                  //st is object of product class
                  flag=1;
            }
      }
      inFile.close();
      if(flag==0)
            cout<<"\n\n\n\t\t\t\t\tRecord doesnot exist"<<endl;
      else
      {
            fstream File;
            File.open("product.csv",ios::binary|ios::in|ios::out);
            if(!File)
            {
                  cout<<"\n\t\t\t\t\tFile could not be open !! Press any Key..."<<endl;
                  cin.get();
                  return;
            }
            while(File.read((char *) &st, sizeof(product)))         //main logic starts here for modify the product
            {
                  if(st.retpno()==n)
                  {
                        fpos=(int)File.tellg();
                        break;
                  }
            }
            File.seekp(fpos-sizeof(product),ios::beg);
            strcpy(tmpnm,st.getname());
            int q1=st.getqty();
            cout<<"\n\n\n\t\t\t\t\t   ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE  "<<endl;
            temp.modifydata(n,tmpnm,q1);
            File.write((char *) &temp, sizeof(product));
            File.close();
      }
}



// Global declaration for stream object
fstream fp;


// Class function outside
product pr;


// Function to write product details in file
void write_book()
{
      fp.open("product.csv",ios::out|ios::app);
      int rnn=getproduct();
      pr.create_prod(rnn);
      fp.write((char*)&pr,sizeof(product));
      fp.close();
      cout<<"\t\t\t\t^^^^^^^^^^^^^^^^^^^^^  PRODUCTS RECORD SAVED  ^^^^^^^^^^^^^^^^^^^^^"<<endl;
      cout<<"\t\t\t<|_______________________________________________________________________|>\n";
      Sleep(1500) ;
	  system("CLS");                          
      cin.get();
}



//Function to check the product number already given or not so as to assign new number automatically for the product
int getproduct()
{
      ifstream objiff;
      product st;
      int count=0;
      objiff.open("product.csv",ios::binary);
      objiff.seekg(0,ios::beg);
      if(!objiff)
      {
            cout<<"\n\n\t\t\tFile could not be open !! Press any Key..."<<endl;
            cout<<"\t\t\t\t";
			cin.get();
      }
      while(objiff.read((char *) &st, sizeof(product)))
      {
            count++;
      }
      objiff.seekg(count-sizeof(st),ios::beg);
      objiff.read((char *) &st, sizeof(product));
      count=st.retpno();
      count++;
      objiff.close();
      return count;
}



//Function to read specific record of product from file
void display_sp(int n)
{
      int flag=0;
      fp.open("product.csv",ios::in);
      if(!fp)
      {
            cout<<"\t\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      while(fp.read((char*)&pr,sizeof(product)))
      {
            if(pr.retpno()==n)         //if product number is equal to number to be displayed
            {
                  pr.show_prod();
                  flag=1;
            }
      }
      fp.close();
      if(flag==0)
            cout<<"\n\n\t\t\t\tRecord doesnot exist"<<endl;
            cout<<"\t\t\t\t";
      		cin.get();
}

//FUNCTION TO DISPLAY ALL THE PRODUCTS IN TABULAR FORM
void prod_tabular()
{
      product st;
      ifstream inFile;
      inFile.open("product.csv",ios::binary);     
      if(!inFile)   			 //use inFile to read from the file
      {
            cout<<"\t\t\t\tFile could not be open !! Press any Key..."<<endl;
            cout<<"\t\t\t\t";
			cin.get();
            return;
      }
      product_detail_heading();
      while(inFile.read((char *) &st, sizeof(product)))
      {
            st.showall();
                }
      inFile.close();
      cin.get();
}



//Function to display heading of the product details
void product_detail_heading()
{
          cout<<"\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"\t\t\t ____________________________________________________________________ \n\n";
		cout<<"\t\t\t                              PRODUCTS DETAILS                               \n\n";
		cout<<"\t\t\t\tPROD.NO"<<setw(10)<<"NAME"<<setw(13)<<"PRICE"<<setw(13)<<"QUANTITY"<<setw(15)<<"DISCOUNT"<<endl;        	//setw()  for setting the width for the output field
		cout<<"\t\t\t<_____________________________________________________________________>\n";
 
}



//FUNCTION TO DELETE THE RECORD OF THE PRODUCTS 
void delete_record(int n)
{
      product st;
      ifstream inFile;
      inFile.open("product.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cout<<"\t\t\t";
			cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==n)
            {
                  st.show_prod();
                  flag=1;
            }
      }
      inFile.close();
      char ch;
      if(flag==0)
            cout<<"\n\n\t\t\tRecord doesnot exist"<<endl;
      else
      {
            cout<<"\t\t\tDO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE [YES(Y or y) OR NO(N or n)]";           //here starts the deletion process
			cin>>ch;
            if (toupper(ch)=='Y')
            {
                  ofstream outFile;
                  outFile.open("Temp1.csv",ios::binary);
                  ifstream objiff("product.csv",ios::binary);
                  objiff.seekg(0,ios::beg);
                  while(objiff.read((char *) &st, sizeof(product)))
                  {
                        if(st.retpno()!=n)
                        {
                              outFile.write((char *) &st, sizeof(product));
                        }
                  }
                  outFile.close();
                  objiff.close();
                  remove("product.csv");
                  rename("Temp1.csv","product.csv");
                  againopenandclose();                          
                  cout<<"\t\t\t  ^^^^^^^^^^^^^^^^^^^^^   Record Deleted  ^^^^^^^^^^^^^^^^^^^^^   "<<endl;
                  Sleep(1200);
                  system("CLS");
            }
      }
      cout<<"\t\t\t";
	  cin.get();
}
void againopenandclose()
{
      ifstream inFile;
      product st;
      inFile.open("product.csv",ios::binary);
      if(!inFile)
      {
            cin.get();
            return;
      }
      while(inFile.read((char *) &st, sizeof(product)))
      {
      }
      inFile.close();
}





//Fuction to search the product through its number
int search(int p)
{
      product st;
      int tmprt=0;
      ifstream inFile;
      inFile.open("product.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cout<<"\t\t\t";
            cin.get();
            return -1;
      }
      int flag=0;
      while(inFile.read((char *) &st, sizeof(product)))
      {
            if(st.retpno()==p)
            {
                  st.show_prod();
                  flag=1;
                  tmprt=(int)inFile.tellg();
                  break;
            }
      }
      inFile.close();
      if(flag==0)
            return 1;
      else
      {
            return tmprt;
      }
}




//Fuction to copy all record to a structure during order placement 
void copyme(int k2,order order1[50],int q1,int &c2)            
{
      ifstream objiff2("product.csv",ios::binary);
      product bk1;
      objiff2.seekg(k2-sizeof(product));
      objiff2.read((char*)&bk1,sizeof(product));
      strcpy(order1[c2].pname1,bk1.getname());
      order1[c2].dis1=bk1.retdis();
      order1[c2].price1=bk1.retprice();
      //COPY RECORD
      order1[c2].qty1=q1;
      c2++;			//c2 to know kati ota order gareko ho
      objiff2.close();
}



//class of customer starts here
class customer
{
      int cust_id;
      char cname[100];
      char address[100];
      char phno[15];
public:
      void modifycust_data(int n1,char nm[15],char add[15],char q[15]);
      int getcustid()
      {
            return cust_id;
      }
      char *getcustnm()
      {
            return cname;
      }
      char *getcustadd()
      {
            return address;
      }
      char *getphno()
      {
            return phno;
      }
  
      void cust_input(int custid)
      {
            cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
            cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
            cout<<"\t\t\tCUSTOMER NO: ";
            cust_id=custid;
            cout<<cust_id<<endl;
            cout<<"\t\t\tNAME OF CUSTOMER:";
            cin>>cname;
            cout<<"\t\t\tADDRESS:";
            cin>>address;
            cout<<"\t\t\tPHONE NO.:";
            cin>>phno;
            cout<<"\t\t\t< ________________________________________________________________________>\n";
      }
    
      void showallcust(int c)
      {
            cout<<"\t\t\t    "<<cust_id<<setw(15)<<cname<<setw(23)<<address<<setw(27)<<phno<<endl;
      }
      void show_cust()
      {
      	
             cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
             cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
             cout<<"\t\t\tCUSTOMER NO      : "<<cust_id<<endl;
             cout<<"\t\t\tNAME OF CUSTOMER : "<<cname<<endl;
             cout<<"\t\t\tADDRESS    	 : "<<address<<endl;
             cout<<"\t\t\tPHONE NO.  	 : "<<phno<<endl;
             cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
      }
};
//customer class ends here



   
//Function to modify the customer details
void customer::modifycust_data(int n1,char nm[15],char add[15],char q[15])
{
      char tmpnm[40],tmpnm2[40],tmpnm3[15];
      char yes1,yes2,yes3;
      cust_id=n1;
      strcpy(cname,nm);
      cout<<"\t\t\tNAME OF CUSTOMER:";
      cout<<cname<<endl<<endl;
      cout<<"\t\t\tWant to change the name of customer ? (Yes[ y or Y ] or NO [n or N])";
      int flag=0;
      while(1)
      {
            cin>>yes1;
            if(yes1== 'Y' || yes1== 'y')
            {
                  cout<<"\t\t\tEnter new name\n";
                  cout<<"\t\t\t";
                  cin>>tmpnm;
                  flag=1;
                  break;
            }
            if(yes1== 'N' || yes1== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            strcpy(cname,tmpnm);
      }
      strcpy(address,add);
      cout<<"\t\t\tCUSTOMER ADDRESS:";
      cout<<"\t\t\t"<<address<<endl<<endl;
      cout<<"\t\t\tWant to change the address ? (Yes[ y or Y ] or NO [n or N])";
      flag=0;
      while(1)
      {
            cin>>yes2;
            if(yes2== 'Y' || yes2== 'y')
            {
                  cout<<"\t\t\tEnter new address\n";
                  cout<<"\t\t\t";
                  cin>>tmpnm2;
                  flag=1;
                  break;
            }
            if(yes2== 'N' || yes2== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            strcpy(address,tmpnm2);
      }
      strcpy(phno,q);
      cout<<"\t\t\tCUSTOMER PHONE NO.:";
      cout<<phno<<endl<<endl;
      cout<<"\t\t\tWant to change the phone no. ? (Yes[ y or Y ] or NO [n or N])";
      flag=0;
      while(1)
      {
            cin>>yes3;
            if(yes3== 'Y' || yes3== 'y')
            {
                  cout<<"\t\t\tEnter new phone no.\n";
                  cout<<"\t\t\t";
                  cin>>tmpnm3;
                  flag=1;
                  break;
            }
            if(yes3== 'N' || yes3== 'n')
            {
                  flag=0;
                  break;
            }
      }
      if(flag==1)
      {
            strcpy(phno,tmpnm3);
      }
      if((yes3== 'Y' || yes3== 'y') || (yes2== 'Y' || yes2== 'y') || (yes1== 'Y' || yes1== 'y'))
      		{
      		cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   NEW PRODUCT RECORD SAVED   ^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t< ________________________________________________________________________>\n";
			}
      else
            {
            cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   NO PRODUCT RECORD CHANGED   ^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t <________________________________________________________________________>\n";	
        }
            
}




//Function to add the records in file
void write_customer()
{
      ofstream objoff;
      customer cobj;
      objoff.open("customer.csv",ios::out|ios::app);
      int r=getcustomers();
      if(r>100) //1000
      {
            r=1; // r=100
      }
       cobj.cust_input(r);
       objoff.write((char*)&cobj,sizeof(customer));
       objoff.close();
       cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   CUSTOMER RECORD SAVED   ^^^^^^^^^^^^^^^^^^^^^ "<<endl;
       cout<<"\t\t\t< ________________________________________________________________________>\n";
       cin.ignore();
       cin.get();
}




//Function to check the customer number already given or not
int getcustomers()
{
      ifstream objiff;
      customer cust;
      int count=1;
      objiff.open("customer.csv",ios::binary);
      objiff.seekg(0,ios::beg);
      if(!objiff)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
      }
      while(objiff.read((char *) &cust, sizeof(customer)))
      {
            count++;
      }
      objiff.seekg(count-sizeof(cust),ios::beg);
      objiff.read((char *) &cust, sizeof(customer));
      count=cust.getcustid();
      count++;
      objiff.close();
      return count;
}




// Function to read specific record from file
void display_cust_sp(int n)
{
       ifstream objfp;
       customer cust;
       int flag=0;
       objfp.open("customer.csv",ios::binary);
       if(!objfp)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      while(objfp.read((char*)&cust,sizeof(customer)))
      {
             if(cust.getcustid()==n)
            {
                  cust.show_cust();
                  flag=1;
            }
      }
      objfp.close();
      if(flag==0)
      cout<<"\n\n\t\t\tRecord doesnot exist"<<endl;
      cin.get();
}




//FUNCTION TO DISPLAY ALL THE CUSTOMER TABULAR FORM
void cust_tabular()
{
      int r=0,col=10;
      customer cust;
      ifstream inFile;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      customer_detail_heading();
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
             if(r<=12)
             {
                   r++;
                   cust.showallcust(col);
                   col++;
             }
             else
             {
                   cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   Press any key  ^^^^^^^^^^^^^^^^^^^^^"<<endl;
                   cin.get();
                   customer_detail_heading();
                   col=10;
                   r=0;
            }
      }
      inFile.close();
      cin.get();
}




//function to display heading of customer details
void customer_detail_heading()
{
        cout<<"\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"\t\t\t ____________________________________________________________________ \n\n";
		cout<<"\t\t\t                              CUSTOMER DETAILS                               \n\n";
		cout<<"\t\t\tCUST.NO"<<setw(13)<<"NAME"<<setw(23)<<"ADDRESS"<<setw(27)<<"PHONE NO"<<endl;
		cout<<"\t\t\t<_____________________________________________________________________>\n";
		

      
      
}




//FUNCTION TO MODIFY customer RECORD
void modify_cust_record(int n)
{
      customer cust,temp;
      char tmpnm[50],tmpaddress[50];
      ifstream inFile;
      int fpos1=-1;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==n)
            {
             cust.show_cust();
             flag=1;
            }
      }
      inFile.close();
      if(flag==0)
            cout<<"\n\n\t\t\tRecord doesnot exist"<<endl;
      else
      {
      //modifying the records starts here
            fstream File;
            File.open("customer.csv",ios::binary|ios::in|ios::out);
            if(!File)
            {
                  cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
                  cin.get();
                  return;
            }
            while(File.read((char *) &cust, sizeof(customer)))
            {
                  if(cust.getcustid()==n)
                  {
                        fpos1=(int)File.tellg();
                        break;
                  }
            }
            File.seekp(fpos1-sizeof(customer),ios::beg);
            strcpy(tmpnm,cust.getcustnm());
            strcpy(tmpaddress,cust.getcustadd());
            char q1[15];
            strcpy(q1,cust.getphno());
			cout<<"\n\n\n\t\t\t     ^^^^^^^^^^^^^^^^  ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE  ^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t<___________________________________________________________________________________________>\n";
            temp.modifycust_data(n,tmpnm,tmpaddress,q1);
            File.write((char *) &temp, sizeof(customer));
            File.close();
      }
}



//FUNCTION TO DELETE THE RECORD OF THE CUSTOMER AVAILABLE
void deletecust_record(int n)
{
      customer cust;
      ifstream inFile;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==n)
            {
                   cust.show_cust();
                   flag=1;
            }
      }
      inFile.close();
      char ch;
      if(flag==0)
            cout<<"\n\n\t\t\tRecord doesnot exist"<<endl;
      else
      {
      //Deletion of the records starts from here
            cout<<"\n\n\t\t\tDO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE [YES(Y or y) OR NO(N or n)]";
            cin>>ch;
            if (toupper(ch)=='Y')
            {
                   ofstream outFile;
                   outFile.open("Temp2.csv",ios::binary);
                   ifstream objiff("customer.csv",ios::binary);
                   objiff.seekg(0,ios::beg);
                   while(objiff.read((char *) &cust, sizeof(customer)))
                   {
                         if(cust.getcustid()!=n)
                         {
                              outFile.write((char *) &cust, sizeof(customer));
                         }
                  }
                  outFile.close();
                  objiff.close();
                  remove("customer.csv");
                  rename("Temp2.csv","customer.csv");
                  againopenandclosecust();
                  cout<<"\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^  Record Deleted  ^^^^^^^^^^^^^^^^^^^^"<<endl;
                  cout<<"\t\t\t<_____________________________________________________________________________>\n";
            }
      }
      cin.get();
}



//sometime files doesnt respond so onced opend and close for that purpose
void againopenandclosecust()
{
      ifstream inFile;
      customer cust;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cin.get();
            return;
      }
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
      }
      inFile.close();
}




//Search the customer
int searchcust(int p)
{
      customer cust;
      int tmprt=0;
      ifstream inFile;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return -1;
      }
      int flag=0;
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==p)
            {
                   cust.show_cust();
                   flag=1;
                   tmprt=(int)inFile.tellg();
                   break;
            }
      }
      inFile.close();
      if(flag==0)
            return 1;
      else
      {
            return tmprt;
      }
}



//Fuction to write customer data
void write_customer1()
{
      ofstream objoff;
      customer cobj;
      objoff.open("customer.csv",ios::out|ios::app);
      int r=getcustomers();
      if(r>100) //1000
      {
            r=1; // r=100
      }
       cobj.cust_input(r);
       objoff.write((char*)&cobj,sizeof(customer));
       objoff.close();
       cout<<"\t\t\t^^^^^^^^^^^^^^^^^^^^^   CUSTOMER RECORD SAVED   ^^^^^^^^^^^^^^^^^^^^"<<endl;
       cout<<"\t\t\t<_____________________________________________________________________>\n";
       cin.ignore();
       cin.get();
       system("CLS");
       cust_menu3();
}




//get the correct customer id number that is present on file .. i e customer number jun user le deko tyo file ma xa ki nai herna
int before_order()
{
      int f=-1,num=0;
      customer cust;
      cout<<"\t\t\tENTER THE CUSTOMER ID TO BILL:";
      cin>>num;
      ifstream inFile;
      inFile.open("customer.csv",ios::binary);
      if(!inFile)
      {
            cout<<"\t\t\tFile could not be open !! Press any Key..."<<endl;
            cin.get();
            return -1;
      }
      while(inFile.read((char *) &cust, sizeof(customer)))
      {
            if(cust.getcustid()==num)
            {
                   cust.show_cust();
                   f=1;
                   break;
            }
      }
      inFile.close();
      return f;
}





void cust_menu1()
{	
	char ch2;
    int num;	
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                   CUSTOMER DETAIL SECTION                             |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|     1 : CREATE NEW CUSTOMER DETAIL                  		                         |>\n";
//	cout<<"\t\t\t<|     2 : DISPLAY ALL CUSTOMERS DETAILS              		                         |>\n";
	cout<<"\t\t\t<|     2 : BACK TO HOME PAGE                     		                         |>\n";        
	cout<<"\t\t\t<|     3 : CONTINUE TO PLACE ORDER                		                         |>\n";
	cout<<"\t\t\t<|     4 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                           "; cin>>ch2    ;            		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";

      switch(ch2)
      {
            case '1':
                  Sleep(1200);
				  system("CLS");
				  write_customer1();
                  break;
//            case '2':
//                  Sleep(800);
//                  system("CLS");
//				  cust_tabular();
//                  cin.ignore();
//                  system("CLS");
//                  cust_menu2();
//                  break;
            case '2':
                  Sleep(800);
                  system("CLS");
				  userMainMenu();
                  break;
            case '3':
                  Sleep(800);
                  system("CLS");
				  orderk=0;
                  place_order();
                  break;
            case '4' :
                exit(0);
            default:
                  cout<<"Please enter valid option"<<endl;
      }
      Sleep(1200);
      system("CLS");
}


// 2nd type Function to be display customer options after displaying all customer details from cust menu 1
void cust_menu2()
{
      char ch2;
      int num;
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|     1 : CREATE NEW CUSTOMER DETAIL                 		                         |>\n";
	cout<<"\t\t\t<|     2 : BACK TO HOME PAGE                          		                         |>\n";
	cout<<"\t\t\t<|     3 : CONTINUE TO PLACE ORDER                 		                         |>\n";        
	cout<<"\t\t\t<|     4 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                           "; cin>>ch2    ;            		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";

      switch(ch2)
      {
            case '1':
                  Sleep(1200);
				  system("CLS");
				  write_customer1();
                  break;
            case '2':
                  userMainMenu();
                  break;
            case '3':
                  Sleep(800);
                  system("CLS");
				  orderk=0;
                  place_order();
                  break;
            case '4' :
            	exit(0);
            default:
                  cout<<"Please enter valid option"<<endl;
      }
}




// 3rd type Function to be display customer options  after placing order and has unsufficient balance
void cust_menu3()
{
      char ch2;
      int num;
	cout<<"\n\n\n\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\t\t\t< _______________________________________________________________________________________ >\n";
	cout<<"\t\t\t<|                                                                                       |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                               Please Click the option below                           |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
//	cout<<"\t\t\t<|     1 : DISPLAY ALL CUSTOMERS DETAILS             		                         |>\n";
	cout<<"\t\t\t<|     1 : BACK TO HOME PAGE                          		                         |>\n";
	cout<<"\t\t\t<|     2 : CONTINUE TO BILL	                 		                         |>\n";        
	cout<<"\t\t\t<|     3 : Exit                                    		                         |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                          		                                 |>\n";
	cout<<"\t\t\t<|                                           "; cin>>ch2    ;            		                                
	cout<<"\t\t\t<|_______________________________________________________________________________________|>\n";
      switch(ch2)
      {
//            case '1':
//                  Sleep(900);
//				  system("CLS");
//				  cust_tabular();
//				  cin.ignore();
//				  system("CLS");
//                  cust_menu2();
//                  break;
            case '1':
                  Sleep(900);
				  system("CLS");
				  userMainMenu();
                  break;
            case '2':
                  Sleep(800);
                  system("CLS");
				  orderk=0;
                  place_order();
                  break;
            case '3':
            	exit(0);
            default:
                  cout<<"Please enter valid option"<<endl;
      }
}




//Function to place order and generating invoice for PRODUCT PURCHASED
void place_order()
{
      string timing;
	  order o1[50];
      int c=0,pr1=0;
      char cc;
      float amt=0,damt=0,total=0,ttaxt=0;
      int k=0,q1;
      char ch='Y';
      int ptx[100];
      int v=0;
      int value=before_order();
      if(value==1)
      {
            cout<<endl;
            
            cout<<"\n\n\t\t\t DO YOU WANT TO WATCH MENU BEFORE ORDERING?(Y/N or y/n)";
            	cin>>cc;
            	
				  if(cc=='Y' | cc=='y')
				  	{
					  prod_tabular();
					  
					  }
            do
            {	
				Sleep(1000);
				cin.ignore();
				system("CLS");
                cout<<"\n\n\t\t\t<_____________________________________________________________________________>\n";
            	cout<<"\t\t\t\t                             PLACE YOUR ORDER                           "<<endl;
            	cout<<"\t\t\t<_____________________________________________________________________________>\n";
                  cout<<"\t\t\tENTER THE PRODUCT NO: ";
                  cin>>pr1;
                  k=search(pr1);
                  if(k>0)
                  {
                        cout<<"\t\t\tEnter the Quantity to Purchase:";
                        cin>>q1;
                        copyme(k,o1,q1,c);  //product number, name, quantity and c to know kati ota kura order gareko ho
                        ptx[v]=pr1;
                        v++;
                  }
                  else
                  {
                        cout<<"\t\t\tPRODUCT not found"<<endl;
                  }
                  cout<<"\t\t\tDo you want purchase more ? (Yes[ y or Y ] or NO [n or N])";
                  cin>>ch;
            }while(ch=='y' || ch=='Y');
            cout<<"\n\n\t\t\t\t\tThank You For Placing The Order  ........"<<endl<<endl;
            cin.get();
            Sleep(1500);
            system("CLS");
            cout<<"\n\n\t\t\t<_____________________________________________________________________________>\n";
            cout<<"\t\t\t\t ^^^^^^^^^^^^^^^^^^^^   INVOICE  ^^^^^^^^^^^^^^^^^^^^"<<endl;
            cout<<"\t\t\t<_____________________________________________________________________________>\n";
            cout<<"\t\t\tPR.No."<<setw(7)<<"NAME"<<setw(10)<<"Qty"<<setw(12)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount - discount"<<endl<<endl;
 			ofstream fout;
 			fout.open("sales.txt",ios::binary|ios::app);
 			
 			for(int x=0;x<c;x++)
            {
                  amt=o1[x].qty1*o1[x].price1;
                  damt=amt-o1[x].dis1;
                  cout<<" \t\t\t   "<<ptx[x]<<setw(10)<<o1[x].pname1<<setw(9)<<o1[x].qty1<<setw(12)<<"Rs."<<o1[x].price1<<setw(10)<<"Rs."<<amt<<setw(14)<<"Rs."<<damt<<endl;
                  total+=damt;
                  timing = ctime();
                  fout<<timing<<" \t\t\t\t\t\t   "<<ptx[x]<<setw(10)<<o1[x].pname1<<setw(9)<<o1[x].qty1<<setw(12)<<"Rs."<<o1[x].price1<<setw(10)<<"Rs."<<amt<<setw(14)<<"Rs."<<damt<<endl;  //store qty, product name and time
             }
			 fout.close();
          
             ttaxt=18;
             cout<<"\n\n\t\t\t<_____________________________________________________________________________>\n";
    
             cout<<"\n\t\t\t\t		  TOTAL AMOUNT     :   "<<"Rs."<<total<<endl;
    
             cout<<"\t\t\t<_____________________________________________________________________________>\n";
             cout<<"\t\t\t\t		   P A Y M E N T  S U M M A R Y  "<<endl;
             cout<<"\t\t\t<_____________________________________________________________________________>\n";
             cout<<"\t\t\t\t		  Enter CASH value :   Rs.";
             float vb,xy;
             cin>>vb;
             xy=(vb-total);            
             if(xy<0)
             {
                cout<<"\n\t\t\tSorry! You have paid Insufficient cash. Please reinitiate billing. Thank You."<<endl;
				Sleep(2000);
				cin.ignore();
                system("CLS");
                cust_menu3();                                                 
             }
             else
             {
                cout<<"	\t\t\t\t     Change to be returned :   Rs."<<xy<<endl;
                
                cout<<"\t\t\t<_____________________________________________________________________________>\n";
            cout<<"\n\t\t\t\t			    HAVE A NICE DAY !\n\n";
             cout<<"\t\t\t<_____________________________________________________________________________>\n";
             cin.ignore();
             Sleep(2000);
            system("CLS");
             
             
             }
      }
      else
            {
            cout<<"\t\t\t\t ^^^^^^^^^^^^^^^^^^^^  YOUR ID IS WRONG  ^^^^^^^^^^^^^^^^^^^^^"<<endl;
            cust_menu1();	
			}
}



//to read the file of sales
void readReport()
	{
	char ch;
      ifstream inFile;
      inFile.open("sales.txt",ios::binary|ios::in|ios::out);     
      if(!inFile)   			 //use inFile to read from the file
      {
            cout<<"\t\t\t\tFile could not be open !! Press any Key..."<<endl;
            cout<<"\t\t\t\t";
			cin.get();
            return;
      }
   //   cout<<"\t\t\tPR.No."<<setw(7)<<"NAME"<<setw(10)<<"Qty"<<setw(12)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount - discount"<<endl<<endl;
      while(inFile)
      	{inFile.get(ch);
      	cout<<ch;
		  }
//      while(inFile.read((char *) &st, sizeof(product)))
//      {
//            st.showall();
//                }
//      inFile.close();
//      cin.get();
      
	}


//function to get the current time
string ctime()
	{
	string x;	
	// Declaring argument for time()
	//time() function is used to find the current calendar time.
    time_t tt;
  
    // Declaring variable to store return value of localtime()
    struct tm * ti;
  
    // Applying time()
    time (&tt);
  
    // Using localtime()
    //localtime() function uses the argument of time(), which has the same value as the return value of time(), to fill a structure having date and time as its components, with corresponding time in local timezone.
    
    ti = localtime(&tt);

	//asctime() function is used to convert the contents in the structure filled by localtime into a human-readable version  in format: Day Month Date hh:mm:ss Year
    //cout << "Current Day, Date and Time is = " << asctime(ti);
    x= asctime(ti);       
	return x;
		
	}

