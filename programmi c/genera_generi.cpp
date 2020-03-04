#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int * genere_random()
{
	int n = 17;
	int *a = new int[n];
	int n1, n2;
	for(int i = 0; i < n; i++)	a[i] = i+1;
	
	for(int i = 0; i < n*10; i++)
	{
		n1 = rand() % n;
		n2 = rand() % n;
		if(n1 == n2) n2 = (n2+1) % n;
		swap(a[n1],a[n2]);
	}
	return a;
}

int main(int argc, char** argv) 
{
	ifstream in;
	ofstream out;
	
	string ruolo;
	int n, idfilm;
	
	srand(time(0));
	
	for(int i = 1; i < 1076; i++)
	{
		if(i == 1)
		{
			out.open("comandi"+to_string(1)+".txt", ofstream::out);
		}
		idfilm = i;
		int *idgenere = genere_random();
		
		n = rand() % 4 + 1;
		for(int j = 0; j < n; j++)
		{
			out << "INSERT INTO generefilm (idfilm,idgenere)" << endl << "VALUES (";
			
			out << idfilm << "," << idgenere[j] << ");" << endl;
		}
		
		delete [] idgenere;
		
 		/*if((i+1) % dim == 0)
		{
			out.close();
		}*/
		if(i == 11) i = 12;
		if(i == 24) i = 75;
		//cout << i << endl;
	}
	
//	cout << n << " " << dim << endl;
	
	
	return 0;
}
