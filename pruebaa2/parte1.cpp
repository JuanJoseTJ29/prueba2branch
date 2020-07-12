/*Diseñe un algoritmo que permita ingresar en un vector los nombres de las 
facultades de la UNMSM, luego por cada facultad deberá ingresar los nombres de las
escuelas profesionales. En base a esta información realizar lo siguiente:

a) Leer los datos.
b) Mostrar los datos leídos.
c) Indicar la facultad que tiene el mayor numero de escuelas.
d) Mostrar la información calculada en el punto C
*/

#include<iostream>
#include<string.h>
using namespace std;
#define N 100

void leer(int n, int m[], char esc[][N][N], char nom[][N])
{
	for(int i=0;i<n;i++)
	{
		cout<<"Ingresar nombre de la facultad #"<<i+1<<": ";
		fflush(stdin);
		cin.getline(nom[i],N);
		cout<<"Ingresar cantidad de escuelas de la facultad de "<<nom[i]<<": ";
		cin>>m[i];
		for(int j=0;j<m[i];j++)
		{
			cout<<"Ingrese nombre de la escuela #"<<j+1<<": ";
			fflush(stdin);
			cin.getline(esc[i][j],N);
		}
		cout<<"------------------------------------------------\n";
	}
}


void mostrar(int n, int m[], char esc[][N][N], char nom[][N])
{
	for(int i=0;i<n;i++)
	{
		cout<<"Escuelas de la facultad de "<<nom[i]<<":"<<endl<<endl;
		for(int j=0;j<m[i];j++)
		{
			cout<<esc[i][j]<<endl;;
		}
		cout<<"------------------------------------------------\n";
	}
}


void mayorEscuelas(int n, int m[], char esc[][N][N], char nom[][N])
{
	char fm[N];
	int may=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m[i];i++)
		{
			if(may<m[i])
			{
				may=m[i];
				strcpy(fm,nom[i]);
			}
		}
	}
	cout<<"Facultad con mayor # de facultades es "<<fm<<
	" con "<<may<<" facultades\n";
}
void mostrarEscuelas(int n, int m[], char esc[][N][N], char nom[][N])
{
	for(int i=0;i<n;i++)
	{
		cout<<"Facultad de "<<nom[i]<<" tiene "<<m[i]<<" escuelas\n";
	}
}



