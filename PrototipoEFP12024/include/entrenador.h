#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include <iostream>

using namespace std;

class entrenador
{
    public:

        entrenador() {}
        entrenador(string id, string TipH, string TipC, string Pre, string est);

        string setid(string id);
        string getid();

        string setTipH(string TipH);
        string getTipH();

        string setTipC(string TipC);
        string getTipC();

        string setPre(string Pre);
        string getPre();

        string setest(string est);
        string getest();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Entrenador
        {
            char id[20];
            char TipH[45];
            char TipC[45];
            char Pre[45];
            char est[45];
        };

    protected:

    private:

        string id, TipH, TipC, Pre, est;
};

#endif // ENTRENADOR_H
