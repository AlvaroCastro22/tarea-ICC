#include <iostream>
#include <string>
using namespace std;
int validar_digito (string cadena);
int precioTotalBoletos = 0;
int precioTotalHotel = 0;
int precioTotalServicios = 0;
int menu();
int diasHotel;
int cantidadBoletos;
int elegirDestino();
int Boletos();
int PrecioBoletos[5][3]= {{130,300,540},{102,203,430},{140,250,450},{160,300,500},{130,320,630}};
int PrecioComidas[5][3]= {{13,30,54},{10,20,43},{14,25,45},{16,30,50},{13,32,63}};
int precioHoteles[5] = {200,300,140,320,451};
int Hospedaje();
int Servicios();
int Pagar();
int validar_digito(string cadena);
int confirmar(int opcion);
int monto = 10;
int opc3;
int opc4;

int cantidadComidas(int x);
int opc;
int opc2;
string Destinos[5] = {"Cusco","Ayacucho","Arequipa","Puno","Ica"};

struct Db {
    string first_name;
    string last_name;
    int num_personas;
};
Db client1;

int main()
{
    int num, pasajeros;
    string fname, lname;


    cout << "Bienvenido a Peru Travel"<<endl;
    cout << "Nombre: ";
    cin >> fname;
    client1.first_name = fname;
    cout << "Apellido: ";
    cin >> lname;
    client1.last_name = lname;

    cout << "Numero de pasajeros: ";
    cin >> client1.num_personas;

    do{
    system("cls");
    monto = precioTotalBoletos+precioTotalHotel+precioTotalServicios;
    opc = menu();


    switch(opc){
        case 1:
            elegirDestino();
            break;
        case 2:
            if(opc3){
              Boletos();
                break;
            }
            break;
        case 3:
            if(precioTotalBoletos>0){
            Hospedaje();
            break;}
            break;
        case 4:
            if(precioTotalHotel>0){
            Servicios();
            break;}
            break;
        case 5:
            if(monto!=0){
                Pagar();
                break;
            }
            break;

    }
    cout<<endl;
    }while(opc!=0);
    return 0;
}



int menu ()
{int opcion;
do {
    cout<<"-----Bienvenido al programa de la agencia de viajes "<<client1.first_name<<" "<<client1.last_name<<"-----"<<endl;
   cout<<"Menu"<<endl;
    cout<<" [1] Destino ";
    if(!(opc3==0)){
        cout<<": "<<Destinos[opc3-1];
    };
    cout<<endl;
    if(opc3==1) cout<<" [2] Boletos"<<endl;

    if(precioTotalBoletos>0) cout<<" [3] Hospedaje"<<endl;
    if(precioTotalHotel>0) cout<<"[4] Servicios"<<endl;

    if(monto!=0){cout<<" [5] Pagar"<<endl;}
    cout<<" [0] "<<endl;

    if(monto!=0) cout<<"Subtotal: "<<monto<<endl;
    cout<<"Ingrese la opción: ";
    cin>>opcion;
    } while (opcion<0 or opcion>5);
return opcion;
}


int elegirDestino(){
    precioTotalBoletos = 0;
    precioTotalHotel = 0;
    precioTotalServicios = 0;
    do{
    system("cls");
    cout<<"Eliga uno de los destinos: "<<endl;
    for(int i=0;i<5;i++){
        cout<<" ["<<i+1<<"] : "<<Destinos[i]<<endl;
    }
    cin>>opc3;
    system("cls");
    cout<<"Elegiste el destino de "<<Destinos[opc3-1]<<endl;
    opc3 = confirmar(opc3);
    }while(opc3<1 or opc3>5);
    return 0;
}

int Boletos(){


    do{
    system("cls");
    cout<<"----Precios de los Boletos------";
    cout<<"Destino :"<<Destinos[opc3-1]<<endl;
    cout<<"[1] Clase turista :"<<PrecioBoletos[opc3-1][0]<<endl;
    cout<<"[2] Clase business :"<<PrecioBoletos[opc3-1][1]<<endl;
    cout<<"[3] Primera clase :"<<PrecioBoletos[opc3-1][2]<<endl;
    cout<<"Eliga una opcion"<<endl;
    cin>>opc4;
    system("cls");
    opc4=confirmar(opc4);
    }while(opc4<=0 or opc4>3 );
    system("cls");
     cout<<"La cantidad de boletos es: "<<client1.num_personas<<endl;
    cout<<"El precio total por los boletos seria de "<<client1.num_personas*PrecioBoletos[opc3-1][opc4-1]<<endl;
    precioTotalBoletos=client1.num_personas*PrecioBoletos[opc3-1][opc4-1];
    system("pause");
}


int Hospedaje(){
    system("cls");
    cout<<"Cantidad de personas :"<<client1.num_personas;
    cout<<"El precio por dia en nuestro hotel asociado es de "<<precioHoteles[opc3-1]<<endl;
    do{
    cout<<"Eliga la cantidad de dias del hospedaje: ";
    cin>>diasHotel;
    }while(diasHotel<=0);
    precioTotalHotel = client1.num_personas*precioHoteles[opc3-1]*diasHotel;
    return 0;
}


int Servicios(){
    int desayunos,almuerzos,cenas;
    system("cls");
    cout<<"Cubrimos el servicio de comidas con los siguientes precios"<<endl;
    cout<<"Desayuno: "<<PrecioComidas[opc3-1][0]<<endl;
    cout<<"Almuerzo: "<<PrecioComidas[opc3-1][1]<<endl;
    cout<<"Cena: "<<PrecioComidas[opc3-1][2]<<endl;
    cout<<" Usted se hospedara por un periodo de "<<diasHotel<<" dias"<<endl;
    cout<<" Le pedimos que elija la cantidad de veces que solicitara desayunos, almuerzos y cenas para los "<< client1.num_personas<<" personas(maximo "<<diasHotel<<")"<<endl;
    cout<<"Desayunos: "<<endl;
    desayunos = cantidadComidas(diasHotel);
    cout<<"Almuerzos: "<<endl;
    almuerzos = cantidadComidas(diasHotel);
    cout<<"Cena: "<<endl;
    cenas = cantidadComidas(diasHotel);
    precioTotalServicios = desayunos*PrecioComidas[opc3-1][0] + almuerzos*PrecioComidas[opc3-1][1]  +  cenas*PrecioComidas[opc3-1][2];
    return 0;
}
int Pagar(){
    string mensajeError = "Porfavor eliga una opcion valida";
    do{
    system("cls");
    cout<<"Subtotal:"<< monto<<endl;
    cout<<"Comision: 200 soles"<<endl;
    cout<<"El total a pagar es "<<monto+200<<endl;
    cout<<"[1] Aceptar"<<endl;
    cout<<"[0] Regresar"<<endl;
    cin>>opc2;

    if(opc2==1){
            cout<<"Gracias por usar el programa";
            opc = 0;
     }else {
            if(opc2!=0){
            cout<<mensajeError<<endl;
            system("pause");
     };
     }

    }while(!(opc2==1 or opc2==0));
    return 0;
}

int confirmar(int eleccion){
    int opcion;
    string mensajeError = "Porfavor eliga una opcion valida";
    int validar;
    cout<<"Confirmar eleccion"<<endl;
    cout<<"[1] Aceptar"<<endl;
    cout<<"[0] Regresar"<<endl;
    cin>>validar;
    if(validar==1){
            cout<<"Eleccion confirmada";
            opcion = eleccion;
     }else {
            if(validar!=0){
            cout<<mensajeError<<endl;
            system("pause");
            opcion = 0;
     }else{
        opcion = 0;
     };
     }
    return opcion;
}

int validar_digito (string cadena)
{int cantidad_digitos=0;
for (int i=0;i<cadena.length();i++)
    {if (int (cadena [i])>47 and cadena [i]<58)
        { cantidad_digitos++;

        }
    }
    return cantidad_digitos;
    }

int cantidadComidas(int x){
    int cantidad;
    do{
        cin>>cantidad;
        if(cantidad>x or cantidad<=0){
            cout<<"Porfavor escribir un numero valido";
        }
    }while(cantidad>x or cantidad<=0);
    return cantidad;
}
