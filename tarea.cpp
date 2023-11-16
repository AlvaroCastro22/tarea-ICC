#include <iostream>
#include <string>
using namespace std;
int menu();
int Boletos();
int Hospedaje();
int Servicios();
int Pagar();
int validar_digito(string cadena);
int monto = 10;
int opc;
int opc2;
int main()
{
    do{
    opc = menu();
    switch(opc){
        case 1:
            Boletos();
            break;
        case 2:
            Hospedaje();
            break;
        case 3:
            Servicios();
            break;
        case 4:
            if(monto!=0){
                Pagar();
                break;
            }
            break;

    }
    cout<<endl;
    system("pause");
    }while(opc!=0);
    return 0;
}



int menu ()
{int opcion;
do {
    cout<<"-----Bienvenido al programa de la agencia de viajes-----"<<endl;
   cout<<"Menu"<<endl;
    cout<<" [1] "<<endl;
    cout<<" [2] "<<endl;
    cout<<" [3] "<<endl;
    if(monto!=0){cout<<" [4] Pagar"<<endl;}
    cout<<" [0] "<<endl;
    
    if(monto!=0) cout<<"Subtotal: "<<monto<<endl;
    cout<<"Ingrese la opción: "; 
    cin>>opcion;
    } while (opcion<0 or opcion>4);
return opcion;
}


int Boletos(){
    cout<<"Ejercutando programa de boletos";
    return 0;
}
int Hospedaje(){
    cout<<"Ejercutando programa de hospedajes";
    return 0;
}
int Servicios(){
    cout<<"Ejercutando programa de otros servicios";
    return 0;
}
int Pagar(){
    do{
    cout<<"Subtotal:"<< monto<<endl;
    cout<<"Comision: 5 soles"<<endl;
    cout<<"El total a pagar es "<<monto+5<<endl;
    cout<<"[1] Aceptar"<<endl;
    cout<<"[0] Regresar"<<endl;
    cin>>opc2;
    
    switch(opc2){
        case 1:
            cout<<"Gracias por usar el programa";
            opc = 0;
            break;
        case 0:
            break;
        default:
            cout<<"Porfavor eliga una opcion valida"<<endl;
            break;
    }
    }while(!(opc2==1 or opc2==0));
    return 0;
}

/*
int validar_digito (string cadena) 
{int cantidad_digitos=0;
for (int i=0;i<cadena.length();i++)
    {if (int (cadena [i])>47 and cadena [i]<58) 
        { cantidad_digitos++;
            
        }
    }
    return cantidad_digitos;
    }*/
