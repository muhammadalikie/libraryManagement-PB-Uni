#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<ctime>
#include<stdio.h>
using namespace std;
//variables:
int c;
int f;
int a;
int l;
int b;
int k;
int o = 0;
string adminu = "admin";
char adminp[20] = "1234";
//custom functions header:
void clrsrc(){system("cls");}
void time(int &year,int &month,int &day);
//---------------------
void home();
void pay();
//--------user-------------
int ifconst();
void ofconst();
//---------------------
void get_userinfo();
void update_user();
//---------------------
void submit_info();
void user_register();
//---------------------
void user_login();
void user_page();
//---------------------
void user_edit();
void membership();
//--------admin-------------
void admin_login();
void admin_page();
//---------------------
int aifstream();
void aofstream();
//---------------------
void submit_admin();
void get_admininfo();
//---------------------
void register_admin();
void remove_user();
void remove_update();
//--------book-------------
int bifstream();
void bofstream();
//---------------------
void submit_book();
void get_bookinfo();
void remove_book_update();
void update_book();
//---------------------
void register_book();
void remove_book();
void book_edit();
//---------------------
void search_book();
void show_book();
void submit_book_borrow();
void borrow_book();
void return_book();
void return_book_sub();
void pay_b();
void pay_book_sub();
void add_borrow_time();
void sub_add_borrow();
//structure:
struct users{
	int id;
	string username;
	char password[20];
	string fullname;
	string birthday;
	string address;
	string phone;
	string email;
	long register_date;
	long end_register_date;
	string register_type;
	int borrow_limit_number;
	int borrow_limit_time;
	int borrow_number;
	int delay;
	string borrow_list[10];
	long debt;
}user[100];
struct admins{
	int id;
	string username;
	char password[20];
}admin[20];
struct books{
	int id;
	string name;
	string topic;
	string Publisher;
	string Version_umber;
	string Edit_number;
	string Date_Release;
	string date_last_edit;
	string price;
	string author;
	int borrow_possibility;
	int last_borrow_id;
	string borrow_penalty_price;
	long date_last_borrow;
	long date_return;
}book[100];
//main function:
int main(){
	home();
	return 0;
}
void home(){
	clrsrc();

	get_userinfo();
	get_admininfo();
	get_bookinfo();

	int x;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Asli ************";

	cout<<"\n\n\t 1) Vorod Modir";
	cout<<"\n\t 2) Vorod karbar";
	cout<<"\n\t 3) Sabtenam Karbar";
	cout<<"\n\t 4) Khorog";
	cout<<"\n\n\n\t Adad Morede Nazar Ra Vared Konid: ";
	cin>>x;
	switch(x){
		case 1:clrsrc();admin_login();break;
		case 2:clrsrc();user_login();break;
		case 3:clrsrc();user_register();break;
		case 4:clrsrc();exit(0);break;
		default:home();
	}
}
//custom functions:
void time(int &year,int &month,int &day){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	year= (1900 + ltm->tm_year);
	month= (1 + ltm->tm_mon);
	day=  ltm->tm_mday;
}

void pay(){
	clrsrc();
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Pardakht ************";
	cout<<"\n\n\t Baray Pardakht Kalame \'pay\' Ra Vared Konid: ";
	string pay;
	do{
		cin>>pay;
		if(!pay.compare("pay")){
			cout<<"\n\t Pardakht Ba Movafaghiyat Anjam Shod.";
			getch();
			user[f].debt = 0;
		}
		else
			cout<<"\n\t Error:\n\t Lotfan Kalame \'pay\' Ra Vared Konid: ";
	}while(pay.compare("pay"));
}
//-----------user----------

int ifconst(){
	int y;
	ifstream myfile("const.txt");
	if(!myfile)
		exit(0);

	myfile>>y;

	myfile.close();
	return y;
}

void ofconst(){

	ofstream myfile("const.txt");
	if(!myfile)
		exit(0);

	myfile<<c<<"\n";
	myfile.close();

}

//---------------------

void get_userinfo(){

	int i=0;

	ifstream myfile("user.txt");
	if(!myfile)
		c=-1;

	else{
		while(!myfile.eof()){

			myfile>>user[i].id;
			myfile>>user[i].username;
			myfile>>user[i].password;
			myfile>>user[i].fullname;
			myfile>>user[i].birthday;
			myfile>>user[i].address;
			myfile>>user[i].phone;
			myfile>>user[i].email;
			myfile>>user[i].register_date;
			myfile>>user[i].end_register_date;
			myfile>>user[i].register_type;
			myfile>>user[i].debt;
			myfile>>user[i].borrow_limit_number;
			myfile>>user[i].borrow_limit_time;
			myfile>>user[i].borrow_number;
			myfile>>user[i].delay;
			myfile>>user[i].borrow_list[o];
			i++;
		}
		c = ifconst();
	}
	myfile.close();
	ofconst();
}

void update_user(){
	int x = 0;

	ofstream myfile("user.txt");
		if (!myfile)
			exit(0);

	while(x<=c){
			myfile<<user[x].id<<"\n";
			myfile<<user[x].username<<"\n";
			myfile<<user[x].password<<"\n";
			myfile<<user[x].fullname<<"\n";
			myfile<<user[x].birthday<<"\n";
			myfile<<user[x].address<<"\n";
			myfile<<user[x].phone<<"\n";
			myfile<<user[x].email<<"\n";
			myfile<<user[x].register_date<<"\n";
			myfile<<user[x].end_register_date<<"\n";
			myfile<<user[x].register_type<<"\n";
			myfile<<user[x].debt<<"\n";
			myfile<<user[x].borrow_limit_number<<"\n";
			myfile<<user[x].borrow_limit_time<<"\n";
			myfile<<user[x].borrow_number<<"\n";
			myfile<<user[x].delay<<"\n";
			myfile<<user[x].borrow_list<<"\n";
			x++;
		}
	myfile.close();
}

//---------------------

void submit_info(){
	ofstream myfile("user.txt", ios::app);
		if (!myfile)
			exit(0);

		int x = c ;

		myfile<<user[x].id<<"\n";
		myfile<<user[x].username<<"\n";
		myfile<<user[x].password<<"\n";
		myfile<<user[x].fullname<<"\n";
		myfile<<user[x].birthday<<"\n";
		myfile<<user[x].address<<"\n";
		myfile<<user[x].phone<<"\n";
		myfile<<user[x].email<<"\n";
		myfile<<user[x].register_date<<"\n";
		myfile<<user[x].end_register_date<<"\n";
		myfile<<user[x].register_type<<"\n";
		myfile<<user[x].debt<<"\n";
		myfile<<user[x].borrow_limit_number<<"\n";
		myfile<<user[x].borrow_limit_time<<"\n";
		myfile<<user[x].borrow_number<<"\n";
		myfile<<user[x].delay<<"\n";
		myfile<<user[x].borrow_list<<"\n";
		myfile.close();
		ofconst();
}

void user_register(){
	clrsrc();
	ifconst();

	//variables:
	int i = ++c,month,year,day;
	user[i].id = c;
	time(year,month,day);
	user[i].debt = 30000;


	//recive information:
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\n\t Tarikh Emroz: "<<year<<"/"<<month<<"/"<<day;


	cout<<"\n\n\t Name Karbari:";
	cin>>user[i].username;

	for(int j=0 ; j<=ifconst() ; j++)
		if(!user[j].username.compare(user[i].username)){
			cout<<"\n\t In Name Karbari Ggablan Sabt Shode.";
			c--;
			getch();
			user_register();
		}

	cout<<"\n\t Ramz:";
	cin>>user[i].password;
	cout<<"\n\t Nam Va Name Khanevadegi:";
	cin>>user[i].fullname;
	cout<<"\n\t Tarikh Tavalod:";
	cin>>user[i].birthday;
	cout<<"\n\t Address:";
	cin>>user[i].address;
	cout<<"\n\t Shomare Telephone:";
	cin>>user[i].phone;
	cout<<"\n\t Email:";
	cin>>user[i].email;


	month *=100;
	year *=10000;
	long date = year + month + day;
	user[i].register_date = date;

	if(month==1200){
		year+=10000;
		month=100;
	}else
		month+=100;

	long date_end = year + month + day;
	user[i].end_register_date = date_end;

	cout<<"\n\t Tarikh Payan Ozviyat:"<<year/10000<<"/"<<month/100<<"/"<<day;

	cout<<"\n\n\t Noe Sabtnam Khod Ra Vared Konid(normal/vip):";
	cin>>user[i].register_type;

	if(!user[i].register_type.compare("vip")){
		user[i].debt += 10000;
		user[i].borrow_limit_number = 10;
		user[i].borrow_limit_time = 30;
		user[i].borrow_number = 0;
		user[i].delay = 0;
		user[i].borrow_list[o] = "empty";

	}else{
		user[i].borrow_limit_number = 5;
		user[i].borrow_limit_time = 10;
		user[i].borrow_number = 0;
		user[i].delay = 0;
		user[i].borrow_list[o] = "empty";
	}
	submit_info();
	cout<<"\n\t Hazine Sabtnam:"<<user[i].debt;
	getch();
	pay();

	update_user();
	get_userinfo();

	clrsrc();
	home();
}

//---------------------

void user_login(){
	clrsrc();
	get_userinfo();

	int x=0;
	string username,password;


	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Vorod Karbaran ************";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Karbari:";
	cin>>username;

	if(!username.compare("close"))
		home();

	for(int i=0 ; i<=c ; i++)
		if(!user[i].username.compare(username)){
			x=1;
			f = i;
		}


	if(x==0){
		cout<<"\n\t Name Karbari Peyda Nashod!";
		getch();
		user_login();
	}

	do{
		cout<<"\n\t Ramz:";
		cin>>password;

		if(!password.compare("close"))
		home();

		if(password==user[f].password){
			cout<<"\n\t Vorod Movafaghiyat Amiz!";
			getch();
			user_page();
		break;
		}
		else
			cout<<"\n\t Ramz Eshtebah Ast!";
	}while(password!=user[f].password);

	getch();
	clrsrc();
	home();
}

void user_page(){
	clrsrc();
	int x;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ "<<user[f].username<<" Khosh Amadi ************";

	cout<<"\n\n\t 1) Virayesh Etelaat Fardi";
	cout<<"\n\t 2) Tamdid Ozviyat";
	cout<<"\n\t 3) Daryaft Ketab";
	cout<<"\n\t 4) Tahvil Ketab";
	cout<<"\n\t 5) Tamdid Mohlate Amanat";
	cout<<"\n\t 6) Pardakht Jarime";
	cout<<"\n\t 7) JostoJoe Ketab";
	cout<<"\n\t 8) Safhe Asli";
	cout<<"\n\n\n\t Adad Morede Nazar Ra Vared Konid: ";
	cin>>x;


	switch(x){
	case 1:clrsrc();user_edit();break;
	case 2:clrsrc();membership();break;
	case 3:clrsrc();borrow_book();break;
	case 4:clrsrc();return_book();break;
	case 5:clrsrc();add_borrow_time();break;
	case 6:clrsrc();pay_b();break;
	case 7:clrsrc();search_book();break;
	case 8:clrsrc();home();break;
		default:clrsrc();user_page();
	}
}

void user_edit(){
	clrsrc();

	int x=0;
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Virayesh Etelaat Fardi ************";

	cout<<"\n\n\t 1) Name Karbari: "<<user[f].username;
	cout<<"\n\t 2) Ramz: "<<user[f].password;
	cout<<"\n\t 3) Nam Va Name Khanevadegi: "<<user[f].fullname;
	cout<<"\n\t 4) Tarikh Tavalod: "<<user[f].birthday;
	cout<<"\n\t 5) Address: "<<user[f].address;
	cout<<"\n\t 6) Shomare Telephone: "<<user[f].phone;
	cout<<"\n\t 7) Email: "<<user[f].email;
	cout<<"\n\t 8) Safhe Asli";
	cout<<"\n\t 9) Bargasht Be Safhe Ghabl";
	cout<<"\n\n\n\t Adad Morede Nazar Ra Vared Konid: ";

	cin>>x;

	switch(x){
		case 1:cout<<"\n\t Name Karbari Jadid Ra Vared Konid: ";cin>>user[f].username;break;
		case 2:cout<<"\n\t Ramz Jadid Ra Vared Konid: ";cin>>user[f].password;break;
		case 3:cout<<"\n\t Nam Va Name Khanevadegi Jadid Ra Vared Konid: ";cin>>user[f].fullname;break;
		case 4:cout<<"\n\t Tarikh Tavalod Jadid Ra Vared Konid: ";cin>>user[f].birthday;break;
		case 5:cout<<"\n\t Address Jadid Ra Vared Konid: ";cin>>user[f].address;break;
		case 6:cout<<"\n\t Shomare Telephone Jadid Ra Vared Konid: ";cin>>user[f].phone;break;
		case 7:cout<<"\n\t Email Jadid Ra Vared Konid: ";cin>>user[f].email;break;
		case 8:home();break;
		case 9:user_page();break;
		default:user_edit();
	}
	update_user();
	get_userinfo();
	user_edit();
}

void membership(){
	clrsrc();
	//e=end    n=now    r=renew    empty = date of register
	long x=user[f].register_date,y=user[f].end_register_date;
	int year,month,day,yeare,monthe,daye,yearn,monthn,dayn,yearr,monthr,dayr;
	time(yearn,monthn,dayn);

	year = x/10000;
	month = (x-(year*10000))/100;
	day = (x-(year*10000))-(month*100);

	yeare = y/10000;
	monthe = (y-(yeare*10000))/100;
	daye = (y-(yeare*10000))-(monthe*100);


	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Tamdid Ozviyat ************";
	cout<<"\n\t Tarikh Emroz: "<<yearn<<"/"<<monthn<<"/"<<dayn;

	cout<<"\n\n\t Tarikh Sabte Nam: "<<year<<"/"<<month<<"/"<<day;
	cout<<"\n\t Tarikh Payane Ozviyat: "<<yeare<<"/"<<monthe<<"/"<<daye;

	yearr = (yearn - yeare);
	monthr = (monthn - monthe);
	dayr = (dayn - daye);

	int Rejected_date = (yearr*365) + (monthr*30) + day;
	if(Rejected_date>0){
		Rejected_date /= 30;
		user[f].debt = Rejected_date*30000;
		cout<<"\n\t Hazine Tamdid Ozviyat: "<<user[f].debt;

		pay();
	}else{
		cout<<"\n\n\t Ozviyat Shoma Hanoz Be Payan Nareside Ast!";
		getch();
	}


	clrsrc();
	update_user();
	get_userinfo();
	user_page();
}


//---------admin------------

void admin_login(){
	clrsrc();

	string username,password;
	int x=0;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Vorod Admin ************";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Karbari: ";
	cin>>username;


	if(!username.compare("close"))
		home();


	if(!username.compare(adminu))
		x=1;
	else{
		for(int i=0 ; i<=a ; i++){
			if(!username.compare(admin[i].username)){
				l = i;
				x = 1;
			}

		}
	}

	if(x==0){
		cout<<"\n\t Name Karbari Peyda Nashod!";
		getch();
		admin_login();
	}

	do{
		cout<<" \n\t Ramz:";
		cin>>password;

		if(!password.compare("close"))
			home();

		if(!password.compare(adminp) || !password.compare(admin[l].password))
			admin_page();
		else{
			cout<<"\n\t Ramz Eshtebah ast.";
		}

	}while(password.compare(adminp) || password.compare(admin[l].password));

	getch();
	clrsrc();
	home();
}

void admin_page(){
	clrsrc();
	int x;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Modiriyat ************";

	cout<<"\n\n\t 1) Sabtenam Admin";
	cout<<"\n\t 2) Afzodan Ketab";
	cout<<"\n\t 3) Hazf Ketab";
	cout<<"\n\t 4) Virayesh Etelaat Ketab";
	cout<<"\n\t 5) Laghve Ozviyat Karbar";
	cout<<"\n\t 6) Safhe Asli";
	cout<<"\n\n\n\t Adad Morede Nazar Ra Vared Konid: ";
	cin>>x;


	switch(x){
	case 1:clrsrc();register_admin();break;
	case 2:clrsrc();register_book();break;
	case 3:clrsrc();remove_book();break;
	case 4:clrsrc();book_edit();break;
	case 5:clrsrc();remove_user();break;
	case 6:clrsrc();home();break;
		default:clrsrc();admin_page();
	}
}

//---------------------

void aofconst(){
	ofstream myfile("aconst.txt");
	if(!myfile)
		exit(0);

	myfile<<a<<'\n';
	myfile.close();
}

int aifconst(){
	int y;

	ifstream myfile("aconst.txt");
	if(!myfile)
		exit(0);

	myfile>>y;
	return y;
}

//---------------------

void get_admininfo(){

	int i=0;

	ifstream myfile("admin.txt");

	if(!myfile)
		a=-1;

	else{
		while(!myfile.eof()){
			myfile>>admin[i].id;
			myfile>>admin[i].username;
			myfile>>admin[i].password;
			i++;
		}
		a = aifconst();
	}


	myfile.close();
	aofconst();
}

void submit_admin(){

	int i = a;

	ofstream myfile("admin.txt", ios::app);
		if (!myfile)
			exit(0);

		myfile<<admin[i].id<<"\n";
		myfile<<admin[i].username<<"\n";
		myfile<<admin[i].password<<"\n";

		aofconst();
}

void remove_update(){
	int x = 0;

	ofstream myfile("user.txt");
		if (!myfile)
			exit(0);

	if(user[f].id==0){
		remove("user.txt");
		cout<<"\n\t Karbar Ba Movafaghiyat Hazf Shod!";
		getch();
		c = -1;
		ofconst();
		myfile.close();
		admin_page();
	}

	while(x<=c){
		if(x==f)
			x++;

			myfile<<user[x].id<<"\n";
			myfile<<user[x].username<<"\n";
			myfile<<user[x].password<<"\n";
			myfile<<user[x].fullname<<"\n";
			myfile<<user[x].birthday<<"\n";
			myfile<<user[x].address<<"\n";
			myfile<<user[x].phone<<"\n";
			myfile<<user[x].email<<"\n";
			myfile<<user[x].register_date<<"\n";
			myfile<<user[x].end_register_date<<"\n";
			myfile<<user[x].register_type<<"\n";
			myfile<<user[x].debt<<"\n";
			myfile<<user[x].borrow_limit_number<<"\n";
			myfile<<user[x].borrow_limit_time<<"\n";
			myfile<<user[x].borrow_number<<"\n";
			myfile<<user[x].delay<<"\n";
			myfile<<user[x].borrow_list<<"\n";
			x++;
		}
	myfile.close();
}

//---------------------

void register_admin(){
	clrsrc();
	aifconst();


	int i=++a;

	admin[i].id = a;
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";

	cout<<"\n\n\t Name Karbari: ";
	cin>>admin[i].username;
	cout<<"\n\t Ramz: ";
	cin>>admin[i].password;

	submit_admin();

	cout<<"\n\t Sabt Name Admin Jadid Movafaghiyat Amiz Bod. ";
	getch();


	clrsrc();
	get_admininfo();
	admin_page();
}

void remove_user(){
	clrsrc();
	get_userinfo();

	int x=0;
	string username,password;


	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Hazf Karbar ************";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Karbari:";
	cin>>username;

	if(!username.compare("close"))
		home();

	for(int i=0 ; i<=c ; i++)
		if(!user[i].username.compare(username)){
			x=1;
			f = i;
		}

	if(x==0){
		cout<<"\n\t Name Karbari Peyda Nashod!";
		getch();
		remove_user();
	}

	remove_update();

	cout<<"\n\t Karbar Ba Movafaghiyat Hazf Shod!";
	getch();
	admin_page();
}

//---------book------------

void bofconst(){
	ofstream myfile("bconst.txt");
	if(!myfile)
		exit(0);

	myfile<<b<<'\n';
	myfile.close();
}

int bifconst(){
	int y;

	ifstream myfile("bconst.txt");
	if(!myfile)
		exit(0);

	myfile>>y;
	return y;
}

//---------------------

void get_bookinfo(){

	int i=0;

	ifstream myfile("book.txt");

	if(!myfile)
		b=-1;

	else{
		while(!myfile.eof()){
			myfile>>book[i].name;
			myfile>>book[i].id;
			myfile>>book[i].topic;
			myfile>>book[i].Publisher;
			myfile>>book[i].Version_umber;
			myfile>>book[i].Edit_number;
			myfile>>book[i].Date_Release;
			myfile>>book[i].date_last_edit;
			myfile>>book[i].price;
			myfile>>book[i].author;
			myfile>>book[i].borrow_possibility;
			myfile>>book[i].last_borrow_id;
			myfile>>book[i].borrow_penalty_price;
			myfile>>book[i].date_last_borrow;
			myfile>>book[i].date_return;
			i++;
		}
		b = bifconst();
	}


	myfile.close();
	bofconst();
}

void submit_book(){

	int i = b;

	ofstream myfile("book.txt", ios::app);
		if (!myfile)
			exit(0);

		myfile<<book[i].name<<"\n";
		myfile<<book[i].id<<"\n";
		myfile<<book[i].topic<<"\n";
		myfile<<book[i].Publisher<<"\n";
		myfile<<book[i].Version_umber<<"\n";
		myfile<<book[i].Edit_number<<"\n";
		myfile<<book[i].Date_Release<<"\n";
		myfile<<book[i].date_last_edit<<"\n";
		myfile<<book[i].price<<"\n";
		myfile<<book[i].author<<"\n";
		myfile<<book[i].borrow_possibility<<"\n";
		myfile<<book[i].last_borrow_id<<"\n";
		myfile<<book[i].borrow_penalty_price<<"\n";
		myfile<<book[i].date_last_borrow<<"\n";
		myfile<<book[i].date_return<<"\n";

		bofconst();
}

void remove_book_update(){
	int i = 0;

	ofstream myfile("book.txt");
		if (!myfile)
			exit(0);

	if(book[b].id==0){
		remove("book.txt");
		cout<<"\n\t Ketab Ba Movafaghiyat Hazf Shod!";
		b = -1;
		bofconst();
		getch();
		myfile.close();
		admin_page();
	}


	while(i<=b){
		if(i==k)
			i++;

			myfile<<book[i].name<<"\n";
			myfile<<book[i].id<<"\n";
			myfile<<book[i].topic<<"\n";
			myfile<<book[i].Publisher<<"\n";
			myfile<<book[i].Version_umber<<"\n";
			myfile<<book[i].Edit_number<<"\n";
			myfile<<book[i].Date_Release<<"\n";
			myfile<<book[i].date_last_edit<<"\n";
			myfile<<book[i].price<<"\n";
			myfile<<book[i].author<<"\n";
			myfile<<book[i].borrow_possibility<<"\n";
			myfile<<book[i].last_borrow_id<<"\n";
			myfile<<book[i].borrow_penalty_price<<"\n";
			myfile<<book[i].date_last_borrow<<"\n";
			myfile<<book[i].date_return<<"\n";
			i++;
		}
	myfile.close();
}

void update_book(){
	int i = 0;

	ofstream myfile("book.txt");
		if (!myfile)
			exit(0);

	while(i<=b){
			myfile<<book[i].name<<"\n";
			myfile<<book[i].id<<"\n";
			myfile<<book[i].topic<<"\n";
			myfile<<book[i].Publisher<<"\n";
			myfile<<book[i].Version_umber<<"\n";
			myfile<<book[i].Edit_number<<"\n";
			myfile<<book[i].Date_Release<<"\n";
			myfile<<book[i].date_last_edit<<"\n";
			myfile<<book[i].price<<"\n";
			myfile<<book[i].author<<"\n";
			myfile<<book[i].borrow_possibility<<"\n";
			myfile<<book[i].last_borrow_id<<"\n";
			myfile<<book[i].borrow_penalty_price<<"\n";
			myfile<<book[i].date_last_borrow<<"\n";
			myfile<<book[i].date_return<<"\n";
			i++;
		}
	myfile.close();
}
//---------------------
void register_book(){
	clrsrc();
	bifconst();

	int i = ++b;


	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabt Ketab ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";

	cout<<"\n\n\t Onvan: ";
	cin>>book[i].name;
	book[i].id = i;
	cout<<"\n\t Mozoe: ";
	cin>>book[i].topic;
	cout<<"\n\t Nasher: ";
	cin>>book[i].Publisher;
	cout<<"\n\t Shomare Noskhe: ";
	cin>>book[i].Version_umber;
	cout<<"\n\t Shomare Virayesh: ";
	cin>>book[i].Edit_number;
	cout<<"\n\t Tarikh Enteshar: ";
	cin>>book[i].Date_Release;
	cout<<"\n\t Tarikh Akharin Virayesh: ";
	cin>>book[i].date_last_edit;
	cout<<"\n\t Gheymat: ";
	cin>>book[i].price;
	cout<<"\n\t Nevisande: ";
	cin>>book[i].author;
	book[i].borrow_possibility = 1;
	book[i].last_borrow_id = -1;
	cout<<"\n\t Mablaghe jarime baraye har roz: ";
	cin>>book[i].borrow_penalty_price;
	book[i].date_last_borrow = 0;
	book[i].date_return = 0 ;

	submit_book();

	cout<<"\n\t Sabt Ketab Jadid Movafaghiyat Amiz Bod. ";
	getch();


	clrsrc();
	get_bookinfo();
	admin_page();
}

void remove_book(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;


	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Hazf Ketab ************";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab:";
	cin>>name;

	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
		}

	if(x==0){
		cout<<"\n\t Name Ketab Peyda Nashod!";
		getch();
		remove_book();
	}

	remove_book_update();

	cout<<"\n\t Ketab Ba Movafaghiyat Hazf Shod!";
	getch();
	admin_page();
}

void book_edit(){
	clrsrc();
	string name;
	int x=0;
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Virayesh Etelaat Ketab ************";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;

	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
		}
	if(x==0){
		cout<<"\n\t Name Ketab Peyda Nashod!";
		getch();
		book_edit();
	}

	clrsrc();

	while(true){
		clrsrc();
		int n=0;
	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Virayesh Etelaat Ketab ************";

	cout<<"\n\n\t 1) Name Ketab: "<<book[k].name;
	cout<<"\n\t 2) Mozoe: "<<book[k].topic;
	cout<<"\n\t 3) Nasher: "<<book[k].Publisher;
	cout<<"\n\t 4) Shomare Noskhe: "<<book[k].Version_umber;
	cout<<"\n\t 5) Shomare Virayesh: "<<book[k].Edit_number;
	cout<<"\n\t 6) Tarikh Enteshar: "<<book[k].Date_Release;
	cout<<"\n\t 7) Tarikh Akharin Virayesh: "<<book[k].date_last_edit;
	cout<<"\n\t 8) Gheymat: "<<book[k].price;
	cout<<"\n\t 9) Nevisande: "<<book[k].author;
	cout<<"\n\t 10) Jarime: "<<book[k].borrow_penalty_price;
	cout<<"\n\t 11) Safhe Asli";
	cout<<"\n\t 12) Bargasht Be Safhe Ghabl";
	cout<<"\n\n\n\t Adad Morede Nazar Ra Vared Konid: ";

	cin>>n;

	switch(n){
		case 1:cout<<"\n\t Name Jadid Ra Vared Konid: ";cin>>book[k].name;break;
		case 2:cout<<"\n\t Mozoe Jadid Ra Vared Konid: ";cin>>book[k].topic;break;
		case 3:cout<<"\n\t Nasher Jadid Ra Vared Konid: ";cin>>book[k].Publisher;break;
		case 4:cout<<"\n\t Shomare Noskhe Jadid Ra Vared Konid: ";cin>>book[k].Version_umber;break;
		case 5:cout<<"\n\t Shomare Virayesh Jadid Ra Vared Konid: ";cin>>book[k].Edit_number;break;
		case 6:cout<<"\n\t Tarikh Enteshar Jadid Ra Vared Konid: ";cin>>book[k].Date_Release;break;
		case 7:cout<<"\n\t Tarikh Akharin Virayesh Jadid Ra Vared Konid: ";cin>>book[k].date_last_edit;break;
		case 8:cout<<"\n\t Gheymat Jadid Ra Vared Konid: ";cin>>book[k].price;break;
		case 9:cout<<"\n\t Nevisande Jadid Ra Vared Konid: ";cin>>book[k].author;break;
		case 10:cout<<"\n\t Jarime Jadid Ra Vared Konid: ";cin>>book[k].borrow_penalty_price;break;
		case 11:home();break;
		case 12:admin_page();break;
		default:book_edit();
	}
	update_book();
	get_bookinfo();
	}

}

//---------------------

void search_book(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;


	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
			clrsrc();
			show_book();
		}

	if(x==0){
		cout<<"\n\t Ketab Yaft Nashod.";
		getch();
		search_book();
	}

	clrsrc();
	getch();
	search_book();
}

void show_book(){

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Moshakhasat Ketab ************";

	cout<<"\n\n\t  Name Ketab: "<<book[k].name;
	cout<<"\n\t  Mozoe: "<<book[k].topic;
	cout<<"\n\t  Nasher: "<<book[k].Publisher;
	cout<<"\n\t  Shomare Noskhe: "<<book[k].Version_umber;
	cout<<"\n\t  Shomare Virayesh: "<<book[k].Edit_number;
	cout<<"\n\t  Tarikh Enteshar: "<<book[k].Date_Release;
	cout<<"\n\t  Tarikh Akharin Virayesh: "<<book[k].date_last_edit;
	cout<<"\n\t  Gheymat: "<<book[k].price;
	cout<<"\n\t  Nevisande: "<<book[k].author;
	cout<<"\n\t  Jarime: "<<book[k].borrow_penalty_price;

	if(book[k].borrow_possibility==1)
		cout<<"\n\t  Ghabel Amanat Gereftan: bale";
	else
		cout<<"\n\t  Ghabel Amanat Gereftan: kheir";

	if(book[k].last_borrow_id==-1)
		cout<<"\n\t  Name Akharin Amanat: Amanat Gerefte Nashod";
	else
		cout<<"\n\t  Name Akharin Amanat: "<<book[k].last_borrow_id;

	if(book[k].date_last_borrow==0)
		cout<<"\n\t  Tarikh Akharin Amanat: Amanat Gerefte Nashod";
	else
		cout<<"\n\t  Tarikh Akharin Amanat: "<<book[k].date_last_borrow;

	if(book[k].date_return==0)
		cout<<"\n\t  Tarikh Bargasht: Amanat Gerefte Nashod";
	else
		cout<<"\n\t  Tarikh Bargasht: "<<book[k].date_return;
	getch();

	clrsrc();
	user_page();
}

void borrow_book(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;


	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
			submit_book_borrow();
			cout<<"\n\t Ketab Sabt shod.";
			getch();
			user_page();
		}

	if(x==0){
		cout<<"\n\t Ketab Yaft Nashod.";
		getch();
		borrow_book();
	}
}

void submit_book_borrow(){
	int month,year,day,monthn,yearn,dayn,montht,yeart,dayt;
	time(year,month,day);
	time(yearn,monthn,dayn);
	time(yeart,montht,dayt);
	month *=100;
	year *=10000;
	if(month==1200){
		year+=10000;
		month=100;
	}else
		month+=100;

	month *=100;
	year *=10000;
	day+=10;
	if(dayn>30){
		dayn -=30;
		monthn+=100;
	}
	if(monthn==1200){
		yearn+=10000;
		monthn=100;
	}

	montht *=100;
	yeart *=10000;
	long date_v = year + month + day;
	long date_n = yearn + monthn + dayn;
	long date_t = yeart + montht + dayt;

	if(!user[f].register_type.compare("vip")){
		o = user[f].borrow_number;
		user[f].borrow_list[user[f].borrow_number] = book[k].name;
		user[f].borrow_limit_number--;
		user[f].borrow_limit_time = date_v;
		user[f].borrow_number++;
	}else{
		o = user[f].borrow_number;
		user[f].borrow_limit_number--;
		user[f].borrow_limit_time = date_n;
		user[f].borrow_list[user[f].borrow_number] = book[k].name;
		user[f].borrow_number++;
	}
	book[k].borrow_possibility=0;
	book[k].last_borrow_id= user[f].id;
	book[k].date_last_borrow = date_t;

	update_user();
	get_userinfo();
}

void return_book(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;


	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
			return_book_sub();
			cout<<"\n\t Tahvil Anjam Shod.";
			getch();
			user_page();
		}

	if(x==0){
		cout<<"\n\t Ketab Yaft Nashod.";
		getch();
		return_book();
	}
}

void return_book_sub(){
	long x=user[f].borrow_limit_time;
	int year,month,day,yeare,monthe,daye,yearr,monthr,dayr;
	time(year,month,day);

	yeare = x/10000;
	monthe = (x-(year*10000))/100;
	daye = (x-(year*10000))-(month*100);

	yearr = (year - yeare);
	monthr = (month - monthe);
	dayr = (day - daye);

	int Rejected_date = (yearr*365) + (monthr*30) + day;
	if(Rejected_date>0){
		user[f].debt = Rejected_date*5000;
		user[f].delay = Rejected_date;

	}
	year *=10000;
	month *=100;
	long now = year + month + day;
	book[k].borrow_possibility=1;
	user[f].borrow_number--;
	book[k].date_return = now;
}

void pay_book_sub(){
	long x=user[f].borrow_limit_time;
	int year,month,day,yeare,monthe,daye,yearr,monthr,dayr;
	time(year,month,day);

	yeare = x/10000;
	monthe = (x-(year*10000))/100;
	daye = (x-(year*10000))-(month*100);

	yearr = (year - yeare);
	monthr = (month - monthe);
	dayr = (day - daye);

	int Rejected_date = (yearr*365) + (monthr*30) + day;
	if(Rejected_date>0){
		user[f].debt = Rejected_date*5000;
		user[f].delay = Rejected_date;
	}
}

void pay_b(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;


	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
			pay_b();

			if(user[f].debt!=0){
				cout<<"\n\t Jarime Shoma: "<<user[f].debt;
				getch();
			}
			else{
				cout<<"\n\t Shoma Baraye In Ketab Takhir Nadashtid ";
				getch();
			}
			getch();
			user_page();
		}

	if(x==0){
		cout<<"\n\t Ketab Yaft Nashod.";
		getch();
		return_book();
	}
}

void add_borrow_time(){
	clrsrc();
	get_bookinfo();

	int x=0;
	string name;

	cout<<"\n\t\t Daneshgah Noshirvani ";
	cout<<"\n\t************ Safhe Sabtnam Admin ************";
	cout<<"\n\n\t Lotfan Bejaye Fasele Az \'/\' Ya \'-\' Estefade Konid ";
	cout<<"\n\t Baraye khoroj \'close\' Ra Vared Konid";

	cout<<"\n\n\t Name Ketab: ";
	cin>>name;


	if(!name.compare("close"))
		home();

	for(int i=0 ; i<=b ; i++)
		if(!book[i].name.compare(name)){
			x=1;
			k = i;
			sub_add_borrow();
			cout<<"\n\t 10 Roz Tamdid Shod.";
			getch();
			user_page();
		}

	if(x==0){
		cout<<"\n\t Ketab Yaft Nashod.";
		getch();
		add_borrow_time();
	}
}

void sub_add_borrow(){
	long x=user[f].borrow_limit_time;
	int year,month,day;

	year = x/10000;
	month = (x-(year*10000))/100;
	day = (x-(year*10000))-(month*100);

	month *=100;
	year *=10000;
	day +=10;

	if(day>30){
		day-=30;
		month+=100;
	}
	if(month==1200){
		year+=10000;
		month=100;
	}

	long date = year + month + day;


	user[f].borrow_limit_time = date;


	update_user();
	get_userinfo();
}
