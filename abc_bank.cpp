#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class account
{
	int acc_no;
	char first_name[25];
	char last_name[25];
	char type[10];

	public:
	long int deposit;
	void create_acc()
	{
		cout<<"Enter account number: ";
		cin>>acc_no;
		cout<<"Enter account holder's first name: ";
		cin>>first_name;
		cout<<"Enter account holder's last name: ";
		cin>>last_name;
        cout<<"Enter type of account(current/saving): ";
		cin>>type;;
		cout<<"Enter amount to be deposited: ";
		cin>>deposit;
		cout<<"Account created"<<endl;
		}

	void display()
	{
		cout<<"Account no: "<<acc_no<<endl;
		cout<<"Account holder's name: "<<first_name<<" "<<last_name<<endl;
		cout<<"Account type: "<<type<<endl;
		cout<<"Balance: Rs "<<deposit<<endl;
		
		}
	int acc_number()
	{
		return(acc_no);
		}

	};

void insert()
{
	ofstream f;
	f.open("abc bank.dat", ios::binary|ios::app);
	account a;
	a.create_acc();
	f.write((char*)&a, sizeof(a));
	f.close();
	}

void show()
{
	ifstream f;
	f.open("abc bank.dat", ios::binary|ios::in);
	account a;
	while(f.read((char*)&a, sizeof(a)))
	{	a.display();
		cout<<endl;
	}
	f.close();
	}

void search(int n)
{
	ifstream f("abc bank.dat",ios::binary|ios::in);
	account a;
	while(f.read((char*)&a, sizeof(a)))
	{       int c=a.acc_number();
		if(n==c)
		a.display();
		}
	f.close();
	}
	

void deposit(int n)
{       long int dep_amt,c;
	account a;
	cout<<"Enter the amount you want to deposit: ";
	cin>>dep_amt;
	ifstream f("abc bank.dat",ios::binary|ios::in);
	ofstream t("temp.dat",ios::binary|ios::out);
	while(f.read((char*)&a, sizeof(a)))
	{       c=a.acc_number();
		if(n==c)
		      a.deposit=a.deposit+dep_amt;
		      t.write((char*)&a, sizeof(a));
		      }
		f.close();
		t.close();
		remove("abc bank.dat");
		rename("temp.dat", "abc bank.dat");
		}

void withdraw(int n)
{
	long int withd_amt,c;
	account a;
	cout<<"Enter the amount you want to withdraw: ";
	cin>>withd_amt;
	ifstream f("abc bank.dat",ios::binary|ios::in);
	ofstream t("temp.dat",ios::binary|ios::out);
	while(f.read((char*)&a, sizeof(a)))
	{       c=a.acc_number();
		if(n==c)
		      a.deposit=a.deposit-withd_amt;
		      t.write((char*)&a, sizeof(a));
		      }
		f.close();
		t.close();
		remove("abc bank.dat");
		rename("temp.dat", "abc bank.dat");
		}

void close(int n)
{
	ofstream o("temp.dat",ios::binary|ios::app);
	ifstream i("abc bank.dat",ios::binary|ios::in);
	account a;

	while(i.read((char*)&a, sizeof(a)))
	{       int c=a.acc_number();
		if(n!=c)
		o.write((char*)&a, sizeof(a));
		}
		o.close();
		i.close();
		remove("abc bank.dat");
		rename("temp.dat", "abc bank,dat");
		cout<<"account closed successfully"<<endl;
		}

void modify(int n)
{
	ofstream o("temp.dat",ios::binary|ios::app);
	ifstream i("abc bank.dat",ios::binary|ios::in);
	account a;

	while(i.read((char*)&a, sizeof(a)))
	{       int c=a.acc_number();
		if(n==c)
		a.create_acc();
		o.write((char*)&a, sizeof(a));
		}
		o.close();
		i.close();
		remove("abc bank.dat");
		rename("temp.dat", "abc bank,dat");
		}

int main()
{
	account b;
	int x, n;
	char ch;
	cout<<"<><><><><><><>Welcome to ABC BANK<><><><><><><><><>"<<endl;
	do
	{
	system("cls");
	cout<<"--------MENU---------"<<endl;
	cout<<"1. Create new account"<<endl;
	cout<<"2. Deposit amount"<<endl;
	cout<<"3. Withdraw amount"<<endl;
	cout<<"4. Check account balance"<<endl;
	cout<<"5. View all account holder's list"<<endl;
	cout<<"6. Close an account"<<endl;
	cout<<"7. Modify account"<<endl;
	cout<<endl<<"Submit choice: ";
	cin>>x;
	system("cls");
	switch(x)
	{
		case 1: insert();
			break;
		case 2: cout<<"Enter account number"<<endl;
			cin>>n;
			deposit(n);
			break;
		case 3: cout<<"Enter account number"<<endl;
			cin>>n;
			withdraw(n);
		case 4: cout<<"Enter account number"<<endl;
			cin>>n;
			search(n);
			break;
		case 5: show();
			break;
		case 6: cout<<"Enter account number"<<endl;
			cin>>n;
			close(n);
			break;
		case 7: cout<<"Enter account number"<<endl;
			cin>>n;
			modify(n);
			break;
		default: cout<<"Invalid choice, Try again"<<endl;
		};
		cout<<endl<<"do you want to go back to menu?"<<endl;
		cout<<"press y for yes and n for no"<<endl;
		cin>>ch;
		}while(ch=='y');
		
		}
