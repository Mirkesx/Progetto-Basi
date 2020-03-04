#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string rece[9][3] = { {"Soldi completamente buttati!","Ho perso solo tempo a guardare questo scempio!","IL piu' brutto film della storia del cinema!"},//1
					{"Ma chi me lo ha fatto fare di vederlo?","Che noia!","Rivoglio i miei soldi!"},//1.5
					{"Sarebbe potuto essere, ma è troppo lento.","Noioso...","Pessima recitazione!"},//2
					{"Non mi è piaciuto.","Non è completamente da buttare, ma si poteva fare di più!","La recitazione dava a desiderare..."},//2.5
					{"Nulla di speciale.","Peccato, potevano farlo meglio.","Il protagonista scelto non mi convince."},//3
					{"Buon film, nulla di piu'.","Divertente, ma poteva essere fatto meglio.","Lento in certi frangenti, ma si riscatta alla fine!"},//3.5
					{"Ottimo film.","Dovrebbero farli tutti cosi.","Lo consiglio a tutti!"},//4
					{"Film spettacolare!","Divertente fino alla fine!","Incredibile cosa riescono a fare di questi giorni. Gli effetti speciali erano fantastici."},//4.5
					{"Il piu' bel film della mia vita!","L'avro' visto 324892348 volte. Non posso smettere di riguardarlo continuamente!","Un capolavoro!"}};//5

int * cliente_random()
{
	int n = 4000;
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
	int n, idfilm, index;
	int dim = 300;
	
	srand(time(0));
	
	out.open("comandi"+to_string(1/dim)+".txt", ofstream::out);
	
	for(int i = 1; i < 1076; i++)
	{
		if(i == 1 || i%dim==0)
		{
			out << "INSERT INTO recensioni (idcliente,idfilm,descrizione,rating)" << endl << "VALUES" << endl; 
		}
		idfilm = i;
		int *idcliente = cliente_random();
		
		n = rand() % 50;
		for(int j = 0; j < n; j++)
		{
			out << "(";
			index = (rand()%2)*1+(rand()%2)*2+(rand()%2)*2+(rand()%2)*2+(rand()%2)*1;
			out <<idcliente[j] << "," << idfilm << ",\"" << rece[index][rand() % 3] << "\"," << (0.5*index)+1 << ")," << endl;
		}
		
		delete [] idcliente;
		
 		
		if(i == 11) i = 12;
		if(i == 24) i = 75;
		/*if((i+1)%dim == 0)
		{
			out.close();
		}*/
	}
	
	
	return 0;
}
