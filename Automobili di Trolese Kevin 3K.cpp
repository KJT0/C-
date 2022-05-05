#include <iostream>
#include <fstream>
#include <string>
using namespace std;
fstream f;
string nomefile = "automobile";
//=========================================
const double Fisso = 4;
struct automobili
{
	string targa;
	string CodiceFiscale;
	double KW;
};
double totale = 0;
int i = 0;
int termina = 1;
automobili a;
//||======================================||
void Scrivi();
void Leggi();
//------------------------------------------
void FileWrite(string nomefile);
void FileAppend(string nomefile);
void FileLettura(string nomefile);
void ChiudiFile();
int main()
{
	Scrivi();
	Leggi();
}

void Scrivi()
{
	FileWrite(nomefile);
		while(termina!=0)
		{
			cout<<"\nInserisci la targa:";
			getline(cin,a.targa);
			cout<<"\nInserisci il codice fiscale del proprietario:";
			getline(cin,a.CodiceFiscale);
			cout<<"\nInserisci il KW:";
			cin>>a.KW;
			f.write((char *)&a,sizeof(a));
			totale = totale+Fisso*a.KW;
			i++;
			cout<<"Inserisci 0 per terminare:";
			cin>>termina;
			cin.ignore(255,'\n');
		}
	ChiudiFile();
}

void Leggi()
{
	FileLettura(nomefile);
	if(!f)
	{
		cout<<"\nErrore con l'apertura del file!";
	}
	else
	{
		cout<<"\nElenco auto:"<<endl;
		while(f.read((char *)&a,sizeof(a)))
		{
			cout<<"\nTarga:"<<a.targa<<endl;
			cout<<"\nCodice Fiscale del proprietario:"<<a.CodiceFiscale<<endl;
			cout<<"\nKW:"<<a.KW<<endl;
		}
		cout<<"\nImporto da pagare per "<<i<<" veicoli:"<<totale;
	}
	ChiudiFile();
}

//-----------------------------------
void FileWrite(string nomefile)
{
	f.open(nomefile.c_str(),ios::out|ios::binary);
}

void FileAppend(string nomefile)
{
	f.open(nomefile.c_str(),ios::app|ios::binary);
}

void ChiudiFile()
{
	f.close();
}

void FileLettura(string nomefile)
{
	f.open(nomefile.c_str(),ios::in|ios::binary);
}
