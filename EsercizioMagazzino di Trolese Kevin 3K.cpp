#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
using std::tolower;
using std::transform;
using namespace std;

struct Prodotti{
	string descrizione;
	string nomereparto;
	double prezzo;
};
Prodotti p;
fstream a;
ofstream stampante;
//Classi di STREAM!
class FSTREAM{
	public:
		void FileLettura(string nomefile)
	{
			a.open(nomefile.c_str(),ios::in);
	}
	
	void ChiudiFile()
	{
			a.close();
	}
	
	void FileAppend(string nomefile)
	{
			a.open(nomefile.c_str(),ios::app);
	}
	
	void FileScrittura(string nomefile)
	{
			a.open(nomefile.c_str(),ios::out);
	}
};
class OFSTREAM{
	public:
	void FileLettura(string nomefile)
	{
			stampante.open(nomefile.c_str(),ios::in);
	}
	
	void ChiudiFile()
	{
			stampante.close();
	}
	
	void FileAppend(string nomefile)
	{
			stampante.open(nomefile.c_str(),ios::app);
	}
	
	void FileScrittura(string nomefile)
	{
			stampante.open(nomefile.c_str(),ios::out);
	}
};
//OGGETTI 2:
FSTREAM f;
OFSTREAM o;
//CLasse standard contentente funzioni ripetitive!
//FUNZIONI:
int Menu();
void Crea();
void Aggiungi();
void TotaleVenduto();
void Visualizza();
//----------------------
string nomefile1 = "Carne.txt";
string nomefile2 = "Pesce.txt";
string nomefile3 = "Frutta.txt";
int i = 0;
int main()
{
	remove(nomefile1.c_str());
	remove(nomefile2.c_str());
	remove(nomefile3.c_str());
	int scelta;
	do{
		scelta = Menu();
		switch(scelta)
		{
			case 1:
			Crea();
			break;
			case 2:
			TotaleVenduto();
			break;
			case 3:
			Visualizza();
			break;
		}
	}
	while(scelta!=4);
}

int Menu()
{
	int s;
	cout<<"\n|=========================================|"<<endl;
	cout<<"|-> 1.Crea Archivio"<<endl;
	cout<<"|-> 2.Totale venduto da tutti i settori"<<endl;
	cout<<"|-> 3.Visualizza a schermo le voci"<<endl;
	cout<<"|-> 4.Termina il lavoro"<<endl;
	cout<<"|=========================================|"<<endl;
	cout<<"|->Usa un numero per navigare il menu:"<<endl;
	cout<<">>:";
	cin>>s;
	return s;
}

void Crea()
{
	cout<<"\nQuale file vuoi scrivere ? (1 = carne | 2 = pesce | 3 = frutta):";
	int scelta;
	cin>>scelta;
	if(scelta == 1)
	{
		f.FileScrittura(nomefile1);
			cout<<"\nInserisci la descrizione del prodotto:";
			cin.ignore(255,'\n');
			getline(cin,p.descrizione);
			while(p.descrizione!="*")
			{
				a<<"\nNome prodotto:"<<p.descrizione<<endl;
				a<<"Reparto: Carne"<<endl;
				cout<<"\nInserisci il prezzo:";
				cin>>p.prezzo;
				a<<"Prezzo:"<<p.prezzo<<endl;
				cout<<"\nInserisci la descrizione del prodotto (* = termina):";
				cin.ignore(255,'\n');
				getline(cin,p.descrizione);
				i++;
			}
		f.ChiudiFile();
	}
	else if(scelta == 2)
	{
		f.FileScrittura(nomefile2);
			cout<<"\nInserisci la descrizione del prodotto:";
			cin.ignore(255,'\n');
			getline(cin,p.descrizione);
			while(p.descrizione!="*")
			{
				a<<"\nNome prodotto:"<<p.descrizione<<endl;
				a<<"Reparto: Pesce"<<endl;
				cout<<"\nInserisci il prezzo:";
				cin>>p.prezzo;
				a<<"Prezzo:"<<p.prezzo<<endl;
				cout<<"\nInserisci la descrizione del prodotto (* = termina):";
				cin.ignore(255,'\n');
				getline(cin,p.descrizione);
				i++;
			}
		f.ChiudiFile();
	}
	else if(scelta == 3)
	{
	f.FileScrittura(nomefile3);
			cout<<"\nInserisci la descrizione del prodotto:";
			cin.ignore(255,'\n');
			getline(cin,p.descrizione);
			while(p.descrizione!="*")
			{
				a<<"\nNome prodotto:"<<p.descrizione<<endl;
				a<<"Reparto: Frutta"<<endl;
				cout<<"\nInserisci il prezzo:";
				cin>>p.prezzo;
				a<<"Prezzo:"<<p.prezzo<<endl;
				cout<<"\nInserisci la descrizione del prodotto (* = termina):";
				cin.ignore(255,'\n');
				getline(cin,p.descrizione);
				i++;
			}
		f.ChiudiFile();
	}
	else
	{
		cout<<"\nOpzione non disponibile!";
	}

}

void TotaleVenduto()
{
	cout<<"\nProdotti venduti da tutti i settori:"<<i;
}

void Visualizza()
{
	f.FileLettura(nomefile1);
	if(!a)
	{
		cout<<"\n======================================";
		cout<<"\nReparto non esistente!";
	}
	else
	{
			cout<<"\n========================================";
			cout<<"\nReparto Carne:"<<endl;
			string StLine;
			while(!a.eof())
			{
				getline(a,StLine);
				cout<<StLine<<endl;
			}
			cout<<"Stampa del reparto 1 terminato!"<<endl;
		f.ChiudiFile();
	}
	f.FileLettura(nomefile2);
	if(!a)
	{
			cout<<"\n======================================";
			cout<<"\nReparto non esistente!";
	}
	else
	{
		cout<<"\n========================================";
		cout<<"\nReparto Pesce:"<<endl;
		while(!a.eof())
		{
			string StLine;
			getline(a,StLine);
			cout<<StLine<<endl;
		}
		cout<<"\nStampa del reparto 2 terminato!"<<endl;
		f.ChiudiFile();	
	}
	f.FileLettura(nomefile3);
	if(!a)
	{
		cout<<"\n======================================";
		cout<<"\nReparto non esistente!";
	}
	else
	{
	cout<<"\n========================================";
	cout<<"\nReparto Frutta:"<<endl;
	string StLine;
	while(!a.eof())
	{
		getline(a,StLine);
		cout<<StLine<<endl;
	}
	cout<<"\nStampa del reparto 3 terminato!"<<endl;
	f.ChiudiFile();	
	}
}