#include <iostream>
#include <fstream>
#include <string.h>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n_maschi = 5349;
int n_femm = 3876;
int n_cogn = 175240;
string maschi_path = "../file_testo_utili/nomi_maschili.txt";
string femm_path = "../file_testo_utili/nomi_femminili.txt";
string cognomi_path = "../file_testo_utili/cognomi.txt";
string nazioni[] = {"Italia", "USA", "Svezia", "Giappone", "Germania", "Sudafrica", "Australia", "Russia", "Spagna", "Regno Unito"};

int main(int argc, char** argv) 
{
	ifstream in;
	ofstream out;
	int n_rand;
	string nickname, nome, cognome, genere,email,datanascita;
	int n, slc, anno, mese, giorno;
	int dim;
	
	srand(time(0));
	
	cout << "Indicare quanti clienti creare: ";
	cin >> n;
	cout << "Indicare quanti comandi salvare in ogni foglio: ";
	cin >> dim;
	if(n < 0) n = 10;
	if(dim < 0) dim = 10;
	
	for(int i = 0; i < n; i++)
	{
		if(i == 0 || i % dim == 0)
		{
			out.open("comandi"+to_string((i/dim)+1)+".txt", ofstream::out);
		}
		//out << "INSERT INTO cliente (nickname,nome,cognome,datanascita,email,genere)" << endl << "VALUES (";
		out << "INSERT INTO artista (nome,cognome,nazionalita)" << endl << "VALUES (";
		if(rand() % 3 < 2)
		{
			in.open(maschi_path, ifstream::in);
			n_rand = n_maschi;
			genere = "maschio";
		}
		else
		{
			in.open(femm_path, ifstream::in);
			n_rand = n_femm;
			genere = "femmina";
		}
		
		slc = rand() % n_rand + 1;
		for(int j = 0; j < slc; j++) in >> nome;
		
		in.close();
		
		in.open(cognomi_path, ifstream::in);
		
		slc = rand() % n_cogn + 1;
		for(int j = 0; j < slc; j++) in >> cognome;
		
		in.close();
		
		anno = rand() % 45 + 1961;
		mese = rand() % 12 + 1;
		giorno = rand() % 28 + 1;
		datanascita = to_string(anno) + "-" + to_string(mese) + "-" + to_string(giorno);
		nickname = nome+cognome+to_string(i+1);
		email = nickname + "@gmail.com";
		
		//out << "\"" << nickname << "\"," << "\"" << nome << "\"," << "\"" << cognome << "\"," << "\"" << datanascita << "\"," << "\"" << email << "\"," << "\"" << genere << "\");" << endl;
		out << "\"" << nome << "\",\"" << cognome << "\",\"" << nazioni[rand() % 10] << "\");" << endl;
 		if((i+1) % dim == 0)
		{
			out.close();
		}
		//cout << i << endl;
	}
	
//	cout << n << " " << dim << endl;
	
	
	return 0;
}
