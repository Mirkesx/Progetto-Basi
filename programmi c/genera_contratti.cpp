#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int * calcolatipo(int n)
{
	int *a = new int[n];
	for(int i = 0; i < n; i++) a[i] = rand() % 3 + 1;
	return a;
}

string * calcoladate(int n, int *t)
{
	int anno, mese, giorno;
	if(rand() % 20 > 4)
		anno = 2019;
	else
		anno = 2018;
		
	mese = rand() % 3 + 6;
	giorno = rand() % 10 + 14;
	int data[6][3];
	string *a = new string[n];
	for(int i = n-1; i >= 0; i--)
	{
		if(i == n-1)
		{
			data[i][0] = anno;
			data[i][1] = mese;
			data[i][2] = giorno;
		}
		else
		{
			data[i][0] = data[i+1][0] - 2;
			data[i][1] = mese;
			data[i][2] = giorno;
			
			/*if(t[i] == 3) data[i][0]--;
			else if(t[i] == 2)
			{
				data[i][1] -= 3;
				if(data[i][1] < 0)
				{
					data[i][0]--;
					data[i][1] += 12;
				}
			}
			else
			{
				data[i][2] -= 28;
				if(data[i][2] < 0)
				{
					data[i][1]--;
					data[i][2] += 28;
				}
			}*/
		}
		/*if(data[i][2] > 28) data[i][2] = 28;
		if(data[i][2] < 1) data[i][2] = 1;
		if(data[i][1] > 12) data[i][2] = 12;
		if(data[i][1] < 1) data[i][2] = 1;*/
		a[i] = to_string(data[i][0]) + "-" + to_string(data[i][1]) + "-" +to_string(data[i][2]);
	}	
	return a;
}

int main(int argc, char** argv) 
{
	ifstream in;
	ofstream out;
	
	string *date;
	int *tipo;
	int n, idcliente;
	int dim = 300;
	
	srand(time(0));
	
	out.open("comandi"+to_string(1/dim)+".txt", ofstream::out);
	
	for(int i = 1; i <= 4000; i++)
	{
		if(i == 1 || i%dim==0)
		{
			out << "INSERT INTO contratto (idcliente,idtipo,datainizio,premium,rinn_auto)" << endl << "VALUES" << endl; 
		}
		
		idcliente = i;
		n = rand() % 5+3;
		tipo = calcolatipo(n);
		date = calcoladate(n,tipo);
		for(int j = 0; j < n; j++)
		{
			out <<"(" << idcliente << "," << tipo[j] << ",\"" << date[j] << "\"," << rand() % 2 << "," << rand() % 2 << ")," << endl;
		}		
		delete [] date;
		delete [] tipo;
		/*if((i+1)%dim == 0)
		{
			out.close();
		}*/
	}
	
	
	return 0;
}
