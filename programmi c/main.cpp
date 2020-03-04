#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

string nazioni[] = {"Italia", "USA", "Svezia", "Giappone", "Germania", "Sudafrica", "Australia", "Russia", "Spagna", "Regno Unito"};
int n = 10;

string trasforma(string s)
{
	string r = s;
	for(int i = 1 ; i < s.length(); i++) r[i] = tolower(s[i]);
	
	return r;
}

int main(int argc, char** argv) 
{
	srand(time(0));
	ifstream in("attori.txt");
	ofstream out("comandi.txt");
	string s1, s2, tmp;
	
	for(int i = 0; i < 200; i++)
	{
		in >> tmp >> s1 >> s2 >> tmp >> tmp;
		s1 = trasforma(s1);
		s2 = trasforma(s2);
		out << "UPDATE Artista" << endl;
		out << "SET nazionalita = \"" << nazioni[rand()%9+1] << "\"" << endl;
		out << "WHERE nome = \"" << s1 << "\" and cognome = \"" << s2 << "\";"<< endl;
	}
	
//	cout << n << " " << dim << endl;
	
	
	return 0;
}
