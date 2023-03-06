#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string FANOMBRE = "Fernando Josue Aldaz Lascano";
int FACEDULA = 1726623000;
int FACAPACIDADBELICA =27;
int FACOORDENADATOTAL = 10;

enum class faEstado {INICIO, Q1, Q2, ARMAMENTOCOMPLETO,FAIL};

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

ABB faCrearNodo(faCoordenada x)
{
     ABB nuevoNodo = new(struct faNodo);
     nuevoNodo->fanro = x.faCap;
     nuevoNodo->faizq = NULL;
     nuevoNodo->fader = NULL;

     return nuevoNodo;
}
void insertar(ABB &faarbol, faCoordenada x)
{
     if(faarbol==NULL)
     {
          faarbol = faCrearNodo(x);
     }
     else if(x.faCap > faarbol->fanro)
          insertar(faarbol->faizq, x);
     else if(x.faCap < faarbol->fanro)
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
               if (fapalabra[0]=='T')
               {
                    faActual=faEstado::Q1;
               }
               if (faActual==faEstado::Q1 && fapalabra[1]=='D')
               {
                    faActual=faEstado::Q2;
               }
               if (faActual==faEstado::Q2 && fapalabra[2]=='A')
               {
                    faActual=faEstado::ARMAMENTOCOMPLETO;
               }else{
                    faActual=faEstado::FAIL;
               }
          }
     }
     return faActual;
}

void faEscribir(){
    faCoordenada fa1={0,"GPS0","aaabbcd"};
    faCoordenada fa2={0,"GPS0","acd"};
    faCoordenada fa3={0,"GPS0","acd"};
    faCoordenada fa4={3,"GPS3","bct"};
    faCoordenada fa5={2,"GPS2","bcd"};
    faCoordenada fa6={6,"GPS6","act"};
    faCoordenada fa7={6,"GPS6","bcd"};
    faCoordenada fa8={2,"GPS2","ab"};
    faCoordenada fa9={7,"GPS7","bc"};
    faCoordenada fa10={1,"GPS1","bc"};
    ofstream faArchivo;

    system("color 04");

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

void faLectura(){
    fstream faArchivo;
    string faTexto;
    int i = 0;
    faArchivo.open("Coordenadas.txt",ios::in);

    system("color 05");

    if (faArchivo.is_open())
       while (!faArchivo.eof())
        {
            getline(faArchivo,faTexto);
            cout << faTexto << endl;
            Sleep(10);
        }
    else
     {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    faArchivo.close();    
}

void faInformacion(){
    cout << "[+] Informacion Arbol Binario de Capacidad Belica Ucrania" << endl
         << "Developer_Name: " << FANOMBRE << endl
         << "Developer_Cedula: " << FACEDULA << endl
         << "Capacidad Belica: " << FACAPACIDADBELICA << endl
         << "Coordenada_Total: " << FACOORDENADATOTAL << endl
         << "Coordenada_SecCarga: ";



}

int main(){
    faCoordenada fa[10]={{0,"GPS0","aaabbcd"},{0,"GPS0","acd"},{0,"GPS0","acd"},{3,"GPS3","bct"},{2,"GPS2","bcd"},{6,"GPS6","act"},{6,"GPS6","bcd"},{2,"GPS2","ab"},{7,"GPS7","bc"},{1,"GPS1","bc"}};
    ABB arbol = NULL;
    string bomba = "TDA";
    faEstado ultimo;
     
    for(int i=0; i<FACOORDENADATOTAL; i++)
    {
        insertar( arbol, fa[10]);
    }

    faEscribir(); //funcion que manda las coordenadas a Coordenadas.txt
    faLectura(); //funcion que permite leer el archivo Coordenadas.txt
    faInformacion(); //funcion que imprime la informacion
    enOrden(arbol);

    return 0;
}