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
	input(twlHour,twlMinuet,m,time);
	convert(twlHour,m);
	display(twlHour,twlMinuet,m);
	return 0;
}
void input(string& twlHour, string& twlMinuet,string&m,string time)
{
	int i,x;
	cout << "Enter your time in the formate XX:XXxm : ";
	cin >> time;
	size_t junk= time.find(":");
	twlHour=time.substr(0,junk);
	twlMinuet=time.substr(junk+1,2);
	m=time.substr(junk+3);
}
void convert(string& twlHour, string m)
{
	int y=0;
	stringstream ss;
	if (m=="pm" && twlHour!="12")
		{
			ss<<twlHour;
			ss>>y;
			y=y+12;
			ss.clear();
			ss.str("");
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
	cout << twlHour << ":" << twlMinuet;
}
