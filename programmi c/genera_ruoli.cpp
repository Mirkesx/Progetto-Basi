#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int * attori_random()
{
	int n = 1000;
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
	int n, dim, slc, idattore, idfilm;
	
	srand(time(0));
	
	/*cout << "Indicare quanti ruoli creare per film: ";
	cin >> n;*/
	//cout << "Indicare quanti comandi salvare in ogni foglio: ";
	/*cin >> dim;
	if(n < 0) n = 10;
	if(dim < 0) dim = 10;*/
	
	for(int i = 1; i < 1076; i++)
	{
		if(i == 1)
		{
			out.open("comandi"+to_string((i/dim)+1)+".txt", ofstream::out);
		}
		idfilm = i;
		int *idattori = attori_random();
		
		n = rand() % 10 + 10;
		for(int j = 0; j < n; j++)
		{
			out << "INSERT INTO attorefilm (idattore,idfilm,ruolo)" << endl << "VALUES (";
			slc = rand() % 400 + 1;
			
			in.open("nomi_ruoli.txt", ifstream::in);
			for(int z = 0; z < slc; z++)
			{
				in >> ruolo;			
			}
			in.close();
			
			out << idattori[j] << "," << idfilm << ",\"" << ruolo << "\");" << endl;
		}
		
		delete [] idattori;
		
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
