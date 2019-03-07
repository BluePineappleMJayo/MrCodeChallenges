#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void input(string& twlHour, string& twlMinuet, string& m,string time);
void convert(string& twlHour, string m);
void display(string twlHour, string twlMinuet, string m);


int main()
{
	string time,m,twlHour,twlMinuet;
	char ans;
do{
	input(twlHour,twlMinuet,m,time);
	convert(twlHour,m);
	display(twlHour,twlMinuet,m);
	cout<< "Want to do another? (Y/N): ";
	cin >> ans;	
	}while(ans=='y'|| ans=='Y');
	cout << "Bye!";
	return 0;
}
void input(string& twlHour, string& twlMinuet,string&m,string time)
{
	int i,x,t;
	stringstream sx,st;
do{
	cout << "Enter your time in the formate XX:XXxm : ";
	cin >> time;
	size_t junk= time.find(":");
	twlHour=time.substr(0,junk);
	twlMinuet=time.substr(junk+1,2);
	m=time.substr(junk+3);
	sx.clear();
	st.clear();
	sx<<twlMinuet;
	sx>>x;
	st<<twlHour;
	st>>t;
	if(x>60||t>12)
		cout << "Please Enter a valid time."<<endl;
	else
	break;
	}while(1);

}
void convert(string& twlHour, string m)
{
	int y=0;
	stringstream ss;
	if (m=="pm" && twlHour!="12")
		{
			ss<<twlHour;
			ss>>y;
			ss.clear();
			ss.str("");
			y=y+12;
			ss<<y;
			twlHour=ss.str();
		}
	else if(m=="am" && twlHour == "12")
	{
		ss<<y;
		twlHour=ss.str();
	}
}
void display(string twlHour,string twlMinuet, string m)
{
	cout << twlHour << ":" << twlMinuet<<endl;
}
