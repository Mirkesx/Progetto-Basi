#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	ifstream in("query_4.txt");
	ofstream out("update_clienti.txt");
	int idcliente;
	
	srand(time(0));
	
	for(int i = 0; i < 2317; i++)
	{
		in >> idcliente;
		if(rand() % 20 <= 3) out << "UPDATE cliente SET disattivo = 1 WHERE idcliente = " << idcliente << ";" << endl; 
	}
	
	
	return 0;
}
