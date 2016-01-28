/*
 *Quest'opera è stata rilasciata con licenza Creative Commons Attribuzione - Non commerciale - 
 *Condividi allo stesso modo 3.0 Italia. Per leggere una copia della licenza visita il 
 *sito web http://creativecommons.org/licenses/by-nc-sa/3.0/it/  
 *o spedisci una lettera a Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * Classe nodo: si occupa di gestire le celle in modo da supportare il funzionamento di una lista
 *      	collegata, realizzata con l'uso di puntatori (campi prec e succ della classe cella)
 *
 * Autore: Riccardo Monterisi http://riccardomonterisi.altervista.org/
 */
#ifndef _NODO_
#define _NODO_

#include "cella.h"

template <class tipoelem>
class nodo {

public:
	// Cella<tipoelem>* è da intendersi a seconda dei casi come
	//  NODO oppure posizione.
	// Non è stato possibile usare tali tipi in quanto il
	// typedef Cella<tipoelem>* non è possibile fuori dalla
	// classe, come sarebbe necessario, in quanto tipoelem
	//non è definito (a compile-time).
	nodo();
	~nodo();

	void create_new(tipoelem, Cella<tipoelem>*);
	void set_value(Cella<tipoelem>* ,tipoelem );
	Cella<tipoelem>* get_prec(Cella<tipoelem>* );
	Cella<tipoelem>* get_succ(Cella<tipoelem>* );
	Cella<tipoelem>* last_full();
	tipoelem get_value(Cella<tipoelem>* );
	void del_current(Cella<tipoelem>* );
	void print();
	void create(); // chiamata dal costruttore

	Cella<tipoelem>* first; //variabile sentinella

};

#include <iostream>
using namespace std;

template <class tipoelem>
nodo<tipoelem>::nodo()
/*
 * FUNZIONAMENTO: funzione costruttore che chiama il
 *				 metodo create()
 */
{
	create();
};

template <class tipoelem>
nodo<tipoelem>::~nodo(){};/*distruttore*/

template <class tipoelem>
void nodo<tipoelem>::create()
/*
 * FUNZIONAMENTO: metodo chiamato dal costruttore che
 * 				  inizializza la variabile sentinella
 * 				  (first)
 */
{

	first = (Cella<tipoelem>*) malloc(sizeof(Cella<tipoelem>));
	first->dato = 0;
	first->succ = first;
	first->prec = first;
	// n_nodi = 0;
};

template <class tipoelem>
void nodo<tipoelem>::create_new(tipoelem in, Cella<tipoelem>* last)
/*
 * PARAMETRI:     in   variabile di tipo tipoelem che rappresenta
 * 					   il valore della cella
 * 				  last varibile di tipo Cella<tipoelem>* (posizione)
 * 					   che indica la posizione della nuova cella
 * 					   all'interno della lista

 * FUNZIONAMENTO: viene istanziato un elemento Cella<tipoelem>* (NODO)
 * 				  il quale viene collegato opportunamente con la posi-
 * 				  zione fornita.
 *
 */
{
	Cella<tipoelem>* temp;

	temp = (Cella<tipoelem>*) malloc(sizeof(Cella<tipoelem>));

	temp->dato = in; //(tipoelem) casting necessario

	//COMBINAZIONE VINCENTE

	temp->prec = last;
	temp->succ = first;
	last->prec->succ = last;
	last->succ = temp;
	last = temp;
};

template <class tipoelem>
Cella<tipoelem>* nodo<tipoelem>::get_prec(Cella<tipoelem>* current)
/*
 *  PARAMETRO:  current elemento di tipo Cella<tipoelem>* (posizione)
 *  					che indica la posizione dell'elemento di cui
 *  				    si vuole conoscere il precedente
 *
 *  FUNZIONAMENTO: viene restituito il campo prec di current
 */
{
	return current->prec;
};

template <class tipoelem>
Cella<tipoelem>* nodo<tipoelem>::get_succ(Cella<tipoelem>* current)
/*
 *  PARAMETRO:  current elemento di tipo Cella<tipoelem>* (posizione)
 *  					che indica la posizione dell'elemento di cui
 *  				    si vuole conoscere il successivo
 *
 *  FUNZIONAMENTO: viene restituito il campo succ di current
 */
{
	return current->succ;
};

template <class tipoelem>
void nodo<tipoelem>::set_value(Cella<tipoelem>* current, tipoelem in)
/*
 *  PARAMETRI:  current elemento di tipo Cella<tipoelem>* (posizione)
 *  					che indica la posizione dell'elemento di cui
 *  				    si vuole sovrascrivere i valore
 * 					in  elemento di tipo tipoelem che rappresenta
 *						il nuovo valore della cella corrente
 *
 *  FUNZIONAMENTO: viene aggiornato con in il campo dato di current
 */
{
	current->dato =  in; //(tipoelem)
};

template <class tipoelem>
tipoelem nodo<tipoelem>::get_value(Cella<tipoelem>* current)
/*
 *  PARAMETRO:  current elemento di tipo Cella<tipoelem>* (posizione)
 *  					di cui si vuole conoscere il valore
 *
 *  FUNZIONAMENTO: viene restituito il campo dato di current
 */
{
	tipoelem out;

	out = current->dato;
	return out;
};

template <class tipoelem>
Cella<tipoelem>* nodo<tipoelem>::last_full()
/*
 *  FUNZIONAMENTO: viene restituito un valore di tipo Cella<tipoelem>*
 *  			   (posizione) indicante l'ultimo elemento della lista
 *
 */
{
	Cella<tipoelem>* pos;

	pos = first;

	do
	{
		pos = get_succ(pos);
	} while (pos->succ == first);

	return pos;
};

template <class tipoelem>
void nodo<tipoelem>::del_current(Cella<tipoelem>* current)
/*
 * PARAMETRO: current elemento di tipo Cella<tipoelem>* (posizione)
 * 			  		  che indica la posizione dell'elemento da cancellare
 *
 * FUNZIONAMENTO:  vengono collegati tra loro l'elemento precedente e
 * 					quello successivo
 */
{
	Cella<tipoelem>* temp;

	temp = current;

	current->succ->prec = current->prec;
	current->prec->succ = current->succ;
	current = current->succ;


	// n_nodi--;
	free(temp);
};

template <class tipoelem>
void nodo<tipoelem>::print()
/*
 *  FUNZIONAMENTO:  vengono stampati gli elementi della lista tranne
 *  				l'elemento sentinella
 */
{
	Cella<tipoelem>* pos = first;
	Cella<tipoelem>* pos2 = get_succ(pos);

	while (pos2 != first) {

		cout << "Elemento: " << pos2->dato << "\n";
		pos2 = get_succ(pos2);
	}
};

#endif //_NODO_

