#include "entrenador.h"
#include "bitacora.h"
#include "login.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std; // Usa el espacio de nombres estándar

// Constructor de la clase entrenador
entrenador::entrenador(string id, string TipH, string TipC, string Pre, string est)
{
    this->id = id;
    this->TipH = TipH;
    this->TipC = TipC;
    this->Pre = Pre;
    this->est = est;
}


string entrenador::setid(string id)
{
    this->id = id; // Asigna el nuevo id
    return id; // Retorna el id asignado
}


string entrenador::getid()
{
    return id;
}

string entrenador::setTipH(string TipH)
{
    this->TipH = TipH;
    return TipH;
}


string entrenador::getTipH()
{
    return TipH;
}


string entrenador::setTipC(string TipC)
{
    this->TipC = TipC;
    return TipC;
}


string entrenador::getTipC()
{
    return TipC;
}


string entrenador::setPre(string Pre)
{
    this->Pre = Pre;
    return Pre;
}


string entrenador::getPre()
{
    return Pre;
}


string entrenador::setest(string est)
{
    this->est = est;
    return est;
}

// Getter para el shabitacion
string entrenador::getest()
{
    return est; // Retorna el segundo apellido dhabitacion
}


// Método para mostrar el menú de opciones
void entrenador::menu()
{
    system("cls"); // Limpia la pantalla
    int opc; // Variable para la opción seleccionada
    char continuar; // Variable para continuar el ingreso dhabitacion

    string usuarioActual = Login::getUsuarioActual(); // Obtiene el usuario actual
    Bitacora bitacora; // Crea un objeto de bitacora
    bitacora.ingresoBitacora(usuarioActual, "2454", "Habi"); // Registra el ingreso en la bitácora

    do
    {
        // Muestra el menú de opciones
        cout << "\n";
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   Catalogo de Habitacion     |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Insertar                   |" << endl;
        cout << "\t\t\t 2. Desplegar                  |" << endl;
        cout << "\t\t\t 3. Modificar                  |" << endl;
        cout << "\t\t\t 4. Borrar                     |" << endl;
        cout << "\t\t\t 5. Salir del programa         |" << endl;
        cout << "\t\t\t 6. Regresar al menu           |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc; // Lee la opción seleccionada

        switch(opc)
        {
        case 1: // Opción para insertar habitacion
            system("cls"); // Limpia la pantalla
            do
            {
                insertar(); // Llama a la función insertar
                cout<<" -> Deseas ingresar a otra Habitacion? (S/N): ";
                cin>>continuar; // Lee si desea continuar ingresando habitacion
            } while(continuar=='S' || continuar=='s'); // Repite mientras la respuesta sea 'S' o 's'
            system("pause"); // Pausa la ejecución
            system("cls"); // Limpia la pantalla
            break;
        case 2: // Opción para desplegar entrenadores
            system("cls"); // Limpia la pantalla
            desplegar(); // Llama a la función desplegar
            system("pause"); // Pausa la ejecución
            system("cls"); // Limpia la pantalla
            break;
        case 3: // Opción para modificar entrenadores
            system("cls"); // Limpia la pantalla
            modificar(); // Llama a la función modificar
            system("pause"); // Pausa la ejecución
            system("cls"); // Limpia la pantalla
            break;
        case 4: // Opción para borrar entrenadores
            system("cls"); // Limpia la pantalla
            borrar(); // Llama a la función borrar
            system("pause"); // Pausa la ejecución
            system("cls"); // Limpia la pantalla
            break;
        case 5: // Opción para salir del programa
            exit(0); // Sale del programa
            break;
        case 6: // Opción para regresar al menú principal
            system("cls"); // Limpia la pantalla
            break;
        default: // Opción inválida
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore(); // Ignora el buffer de entrada
            cin.get(); // Pausa la ejecución
            system("cls"); // Limpia la pantalla
        }
    } while (opc!=6); // Repite mientras la opción no sea 6
}

// Método para insertar habitacion
void entrenador::insertar()
{
    string usuarioActual = Login::getUsuarioActual(); // Obtiene el usuario actual
    Bitacora bitacora; // Crea un objeto de bitacora
    bitacora.ingresoBitacora(usuarioActual, "2045", "INHABI"); // Registra el ingreso en la bitácora

    // Muestra el encabezado para agregar detalles habitacion
    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|        Agregar detalles del Habitacion   |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL)); // Inicializa la semilla para generar números aleatorios
    Entrenador entrenador; // Crea un objeto dhabitacion
    int numAleatorio = (rand() % 9998) + 1; // Genera un número aleatorio

    string idString = "entre-" + to_string(numAleatorio); // Crea el id del habitacion

    for (int i = 0; i < idString.length(); ++i) {
        entrenador.id[i] = idString[i]; // Asigna el id alhabitacion
    }
    entrenador.id[idString.length()] = '\0'; // Termina la cadena de id

    cout<<"        -> Generando codigo del entrenador: " << entrenador.id<<endl;
    cin.ignore(); // Ignora el buffer de entrada

    // Lee los detalles habitacion
    cout<<"        -> Ingrese  el tipo de habitacion: ";
    cin.getline(entrenador.TipH, 45);

    cout<<"        -> Ingrese  el tipo de cama: ";
    cin.getline(entrenador.TipC, 45);

    cout<<"        -> Ingrese el precio : ";
    cin.getline(entrenador.Pre, 45);

    cout<<"        -> Ingrese el Status: ";
    cin.getline(entrenador.est, 45);

    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    // Abre el archivo en modo binario para agregar los detalles habitacion
    ofstream archivo("Habitacion.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrenador), sizeof(entrenador)); // Escribe los detalles en el archivo
    archivo.close(); // Cierra el archivo
}

// Método para desplegar los detalles de habitacion
void entrenador::desplegar()
{
    string usuarioActual = Login::getUsuarioActual(); // Obtiene el usuario actual
    Bitacora bitacora; // Crea un objeto de bitacora
    bitacora.ingresoBitacora(usuarioActual, "5675", "VERH"); // Registra el ingreso en la bitácora

    // Muestra el encabezado para ver detalles habitacion
    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|          Ver detalles de Habitacion      |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    // Abre el archivo en modo binario para leer los detalles de las habitacion
    ifstream archivo("Habitacion.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
    Entrenador entrenador; // Crea un objeto de habitacion

    // Lee los detalles del archivo y los muestra
    while (archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador)))
    {
        cout<<"       -> Codigo de habitacion: "<< entrenador.id << endl;
        cout<<"       -> Tipo de habitacion : "<< entrenador.TipH << endl;
        cout<<"       -> Tipo de cama: "<< entrenador.TipC << endl;
        cout<<"       -> Precio: "<< entrenador.Pre << endl;
        cout<<"       -> Estatus: "<< entrenador.est << endl;
        cout << "     +-----------------------------------------------+" << endl;
        cout << "\n";
    }

    archivo.close(); // Cierra el archivo

    cout << "Presione Enter Para Continuar";
    cin.ignore(); // Ignora el buffer de entrada
    cin.get(); // Pausa la ejecución
}

// Método para modificar los detalles de habitacion
void entrenador::modificar()
{
    string usuarioActual = Login::getUsuarioActual(); // Obtiene el usuario actual
    Bitacora bitacora; // Crea un objeto de bitacora
    bitacora.ingresoBitacora(usuarioActual, "5644", "MHABI"); // Registra el ingreso en la bitácora

    // Muestra el encabezado para modificar detalles del entrenador
    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|      Modificar detalles de Habitacion    |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idEntre; // Variable para el id habitacion a modificar
    bool encontrado = false; // Variable para indicar si se encontró habitacion

    archivo.open("Habitacion.dat", ios::binary | ios::in | ios::out); // Abre el archivo en modo binario para lectura y escritura
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo de Habitacion: ";
    cin >> idEntre; // Lee el id del entrenador a modificar

    Entrenador entrenador; // Crea un objeto habitacion

    // Busca habitacion con el id proporcionado
    while (archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador))) {
        if (entrenador.id == idEntre) {
            encontrado = true;

            // Muestra los detalles de habitacion encontrado y solicita los nuevos detalles
            cout << "\n" << endl;
            cout << "           Habitacion encontrada con exito!" << endl;
            cout << "\n" << endl;
            cout<<"        -> Ingrese codigo de Habitacion: ";
            cin >> entrenador.id;
            cout<<"        -> Ingrese el tipo de habitacion ";
            cin >> entrenador.TipH;
            cout<<"        -> Ingrese el tipo de cama: ";
            cin >> entrenador.TipC;
            cout<<"        -> Ingrese el precio: ";
            cin >> entrenador.Pre;
            cout<<"        -> Ingrese el estatus: ";
            cin >> entrenador.est;
            cout << "\n" << endl;

            // Posiciona el puntero del archivo al inicio del registro y escribe los nuevos detalles
            archivo.seekp(-static_cast<int>(sizeof(Entrenador)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador));
            break;
        }
    }

    archivo.close(); // Cierra el archivo

    if (!encontrado) {
        cout << "       -> No se encontró una habitacion con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore(); // Ignora el buffer de entrada
    cin.get(); // Pausa la ejecución
}

// Método para borrar los detalles de un habitacion
void entrenador::borrar()
{
    string usuarioActual = Login::getUsuarioActual(); // Obtiene el usuario actual
    Bitacora bitacora; // Crea un objeto de bitacora
    bitacora.ingresoBitacora(usuarioActual, "2567", "EHABI"); // Registra el ingreso en la bitácora

    // Muestra el encabezado para eliminar detalles del entrenador
    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t|       Eliminar detalles de Habitacion    |" << endl;
    cout << "\t|                                          |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Habitacion.dat", ios::binary); // Abre el archivo en modo binario para lectura
    string idEntre; // Variable para el id de habitacion a borrar

    if(!archivo)
    {
        cout<<"       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }

    ofstream archivo2("Habitacion2.dat", ios::binary); // Abre un nuevo archivo en modo binario para escritura

    Entrenador entrenador;

    cout<<"       -> Ingrese el codigo de Habitacion: ";
    cin>>idEntre; // Lee el id del entrenador a borrar

    bool resta = false;


    while(archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(Entrenador)))
    {
        if(entrenador.id != idEntre)
        {
            archivo2.write(reinterpret_cast<const char*>(&entrenador), sizeof(Entrenador));
        }
        else
        {
            resta = true;
        }

    }
    archivo.close(); // Cierra el archivo original
    archivo2.close(); // Cierra el nuevo archivo

    remove("Habitacion.dat"); // Elimina el archivo original

    rename("Habitacion2.dat","Habitacion.dat"); // Renombra el nuevo archivo

    if (resta)
    {
        cout << "\n" << endl;
        cout << "       -> Habitacion eliminado con exito." << endl;
        cout << "\n";
    }
    else
    {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar la habitacion" << endl;
        cout << "\n";
    }
}
