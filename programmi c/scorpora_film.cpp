#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string trasforma(string s)
{
	return s.substr(0,8) + "0" + s.substr(8);
}

int main(int argc, char** argv) 
{
	ifstream in("query_3.txt");
	ofstream out("update_film.txt");
	int idfilm, d1, d2;
	bool check;
	int dim;
	
	srand(time(0));
	
	if(dim < 0) dim = 350;
	
	for(int i = 0; i < 1023; i++)
	{
		in >> idfilm >> d1 >> d2;
		
		//cout << idfilm << "," << datapub << ", " << datapub.length() << endl;
		
		if(d2 - d1 > 10)
		{
			d1 = (d2-1) - rand() % 10;
			out << "UPDATE FILM" << endl << "SET annoprod = " << d1 << endl << "WHERE idfilm = " << idfilm << ";" << endl;
		}
		
	}
	
//	cout << n << " " << dim << endl;
	
	
	return 0;
}
