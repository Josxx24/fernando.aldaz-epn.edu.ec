#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include "..\lib\FaColores.h"

using namespace std;

string FANOMBRE = "Fernando Josue Aldaz Lascano";
int FACEDULA = 1726623000;
int FACAPACIDADBELICA =19;
int FACOORDENADATOTAL = 10;
string FAENORDEN = "0 1 2 3 6 7 ";

enum class faEstado {INICIO, Q1, Q2,Q3, ARMAMENTOCOMPLETO,FAIL};

struct faCoordenada
{
   int faCap;
   string faGeo;
   string faArsenal;
};


struct faNodo{
     int fanro;
     struct faNodo *faizq, *fader;
};

typedef struct faNodo *ABB;

ABB faCrearNodo(int x)
{
     ABB nuevoNodo = new(struct faNodo);
     nuevoNodo->fanro = x;
     nuevoNodo->faizq = NULL;
     nuevoNodo->fader = NULL;

     return nuevoNodo;
}
void insertar(ABB &faarbol, int x)
{
     if(faarbol==NULL)
     {
          faarbol = faCrearNodo(x);
     }
     else if(x > faarbol->fanro)
          insertar(faarbol->faizq, x);
     else if(x < faarbol->fanro)
          insertar(faarbol->fader, x);
}
void faVerArbol(ABB faarbol, int fan)
{
     if(faarbol==NULL)
          return;
     faVerArbol(faarbol->fader, fan+1);

     for(int i=0; i<fan; i++)
         cout<<"     ";

     cout<< faarbol->fanro  <<endl;
     faVerArbol(faarbol->faizq, fan+1);
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->faizq);
          cout << arbol->fanro << " ";
          enOrden(arbol->fader);
     }
}

faEstado faArmamentoBomba(string fapalabra){
     faEstado faActual = faEstado::INICIO;
     bool finalizar = false;
     unsigned int pos=0;

     for (int i = 0; i < sizeof(fapalabra); i++)
     {
          if (faActual==faEstado::INICIO)
          {
               if (fapalabra[i]=='a')
               {
                    faActual=faEstado::Q1;
                    if (faActual==faEstado::Q1 && fapalabra[i]=='b'){
                        faActual=faEstado::Q2;
                        if (faActual==faEstado::Q2 && fapalabra[i]=='c' || faActual==faEstado::Q2){
                            faActual=faEstado::Q3;
                            if(faActual==faEstado::Q3 && fapalabra[i]=='d' || faActual==faEstado::Q3){
                                faActual=faEstado::ARMAMENTOCOMPLETO;
                            }else{
                                faActual=faEstado::FAIL;
                            }
                        }
                    }
               }
          }
     }
     return faActual;
}

void faEscribir(){
    faCoordenada fa1={0,"GPS0","ab"};
    faCoordenada fa2={0,"GPS0","ab"};
    faCoordenada fa3={0,"GPS0","ab"};
    faCoordenada fa4={3,"GPS3","bcd"};
    faCoordenada fa5={2,"GPS2","ac"};
    faCoordenada fa6={6,"GPS6","act"};
    faCoordenada fa7={6,"GPS6","act"};
    faCoordenada fa8={2,"GPS2","ac"};
    faCoordenada fa9={7,"GPS7","aaabbct"};
    faCoordenada fa10={1,"GPS1","bc"};
    ofstream faArchivo;

    faArchivo.open("Coordenadas.txt",ios::out);

    if(faArchivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
faArchivo << "Error: Cap\t" << "Geo\t" << "Arsenal --> stoi" << endl
          << fa1.faCap << "\t" << fa1.faGeo << "\t" << fa1.faArsenal << endl
          << fa2.faCap << "\t" << fa2.faGeo << "\t" << fa2.faArsenal << endl
          << fa3.faCap << "\t" << fa3.faGeo << "\t" << fa3.faArsenal << endl
          << fa4.faCap << "\t" << fa4.faGeo << "\t" << fa4.faArsenal << endl
          << fa5.faCap << "\t" << fa5.faGeo << "\t" << fa5.faArsenal << endl
          << fa6.faCap << "\t" << fa6.faGeo << "\t" << fa6.faArsenal << endl
          << fa7.faCap << "\t" << fa7.faGeo << "\t" << fa7.faArsenal << endl
          << fa8.faCap << "\t" << fa8.faGeo << "\t" << fa8.faArsenal << endl
          << fa9.faCap << "\t" << fa9.faGeo << "\t" << fa9.faArsenal << endl
          << fa10.faCap << "\t" << fa10.faGeo << "\t" << fa10.faArsenal << endl;

faArchivo.close();
}

void faCargando()
{ 
    int fai =0;
    string fac= "\\|/-|"; 
    for(int fas=0; fas<= 100; fas++)
    {   
        if(fas % 4 ==0)
            fai =0; 
        cout    << "\r" << fac[fai++]   
                << " " << fas << "%\t";
        Sleep(10);
    }
}

void faLectura(){
    fstream faArchivo;
    string faTexto;
    int i = 0;
    faArchivo.open("Coordenadas.txt",ios::in);

    
    if (faArchivo.is_open())
       while (!faArchivo.eof())
        {
            getline(faArchivo,faTexto);

            if (faTexto[0]=='E')
            {
                faSetColor(0,4);
                faCargando();
                cout << faTexto << endl;
            }else{
            faSetColor(0,2);
            faCargando();
            cout << faTexto << endl;
            Sleep(10);
            }
        }
    else
     {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    faArchivo.close();    
}

void faInformacion(){
    faSetColor(0,8);

    cout << "[+] Informacion Arbol Binario de Capacidad Belica Ucrania" << endl
         << "Developer_Name: " << FANOMBRE << endl
         << "Developer_Cedula: " << FACEDULA << endl
         << "Capacidad Belica: " << FACAPACIDADBELICA << endl
         << "Coordenada_Total: " << FACOORDENADATOTAL << endl
         << "Coordenada_SecCarga: " << FAENORDEN;
}

int main(){
    faCoordenada fa[10]={{0,"GPS0","aaabbcd"},{0,"GPS0","acd"},{0,"GPS0","acd"},{3,"GPS3","bct"},{2,"GPS2","bcd"},{6,"GPS6","act"},{6,"GPS6","bcd"},{2,"GPS2","ab"},{7,"GPS7","bc"},{1,"GPS1","bc"}};
    ABB arbol = NULL;
    string bomba = "aaabbct";
    faEstado ultimo;
     
    for(int i=0; i<FACOORDENADATOTAL; i++)
    {
        insertar( arbol, fa->faCap);
    }

    faEscribir(); //funcion que manda las coordenadas a Coordenadas.txt
    faLectura(); //funcion que permite leer el archivo Coordenadas.txt
    faInformacion(); //funcion que imprime la informacion

    ultimo= faArmamentoBomba(bomba);
    
    if(ultimo==faEstado::ARMAMENTOCOMPLETO){
        cout << "\n\nLa BOMB-IPI ha explotado exitosamente";
    }else if(ultimo==faEstado::FAIL){
        cout << "\n\nLa BOMB-IPI no coincide con el armamento";
    }

    return 0;
}