#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

string FANOMBRE = "Fernando Josue Aldaz Lascano";
int FACEDULA = 1726623000;

enum class faEstado {INICIO, Q1, Q2, ARMAMENTOCOMPLETO,FAIL};

struct faNodo{
     int fanro;
     struct faNodo *faizq, *fader;
};

typedef struct faNodo *ABB;

struct faCiudad
{
     string faNombreCiudad;
     float fapoblacion;
};

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
     else if(x < faarbol->fanro)
          insertar(faarbol->faizq, x);
     else if(x > faarbol->fanro)
          insertar(faarbol->fader, x);
}
void faVerArbol(ABB faarbol, int fan)
{
     if(faarbol==NULL)
          return;
     faVerArbol(faarbol->fader, fan+1);

     for(int i=0; i<fan; i++)
         cout<<"     ";

     cout<< faarbol->fanro <<endl;

     faVerArbol(faarbol->faizq, fan+1);
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



int main(){
     ABB faArbol = NULL;
     int x;
     string faBomba = "TDA";
     faEstado faUltimo;
     struct faCiudad faObetivo;

     faObetivo.faNombreCiudad="UCRANIA";
     faObetivo.fapoblacion=43.79;

     system("color 04");
     cout << "\n\t  ..[ MAPA DE COORDENADAS ]..  \n\n";

     cout << endl;

     for(int i=0; i<5; i++)
     {
         cout << " coordenada " << i+1 << ": ";
         cin >> x;
         insertar( faArbol, x);
     }
     system("color 05");
     cout << "\n\t Mostrando ciudad\n\n"<<faObetivo.faNombreCiudad<<"\tpoblacion: "<<faObetivo.fapoblacion<<" M\n\n";

     faVerArbol( faArbol, 0);

     faUltimo = faArmamentoBomba(faBomba);

     if (faUltimo==faEstado::ARMAMENTOCOMPLETO)
     {
          cout<<"La bomba ha estallado con exito";
     }else if(faUltimo==faEstado::FAIL){
          cout<<"La bomba no coincide con el armamento de dicha coordenada";
     }
     

    return 0;
}