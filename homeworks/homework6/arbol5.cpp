//Determinar si un ABB está equiponderado (es equiponderado cuando para todo nodo el peso del subárbol 
//izquierdo es igual al peso del subárbol derecho). El AB vacío está equiponderado por definición. 
//Llamamos peso de un árbol a la suma de todos sus elementos.

#include "ArbolBinario.h"

int main()
{
	void leerAB(ArbolBinario * b); // prototipo de funcion ingreso AB
    void pesoSubarbol(NodoBinario *p, int *h);	// prototipo de funcion que calcula el peso de un arbol
    void verificarEquiponderacion(NodoBinario *p);
	ArbolBinario a; // declara un Arbol binario
	leerAB(&a); // llamado a funcion de ingreso AB
	cout << endl;
	cout<<" ARBOL INGRESADO "<<endl;
	a.imprimirABJerarquia(a.getRaiz(),0);
    verificarEquiponderacion(a.getRaiz());
	cout << endl;
	system("pause");
}

//==================================================================================================

void leerAB(ArbolBinario *b)
{
	int v;
	cout << endl
		 << "LECTURA DE ARBOL BINARIO" << endl
		 << endl;
	cin >> v;
	if (v != 999)
	{
		b->insertarNodo(v);
		leerAB(b);
	}
}

void pesoSubarbol(NodoBinario *p, int *h)
{
    if(p == NULL)
    {
        return;
    }
    pesoSubarbol(p->getIzq(),h);	// verifica peso izq
    *h += p->getDato();	//	suma los valores
    pesoSubarbol(p->getDer(),h);	// verifica peso der
}

void verificarEquiponderacion(NodoBinario *p)
{
    int iz=0, dr =0;
    pesoSubarbol(p->getIzq(),&iz);	// calcula pesosubAB izq
    pesoSubarbol(p->getDer(),&dr);	// calcula pesosubAB izq
    cout<<"El arbol "<< (iz == dr ? "si" : "no") <<" es equiponderado"<<endl;
}