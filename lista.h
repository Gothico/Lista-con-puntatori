/*
 * Quest'opera è stata rilasciata con licenza Creative Commons Attribuzione - Non commerciale - 
 * Condividi allo stesso modo 3.0 Italia. Per leggere una copia della licenza visita il 
 * sito web http://creativecommons.org/licenses/by-nc-sa/3.0/it/  
 * o spedisci una lettera a Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * Classe lista: si occupa di fornire l'interfaccia prevista dalle specifiche per l'uso di una lista
 *
 * Autore: Riccardo Monterisi http://riccardomonterisi.altervista.org/
 */

#ifndef _LISTA_
#define _LISTA_
#include "nodo.h"
#include <iostream>
#include <assert.h>
using namespace std;

template <class tipoelem>
class Lista  {

public:
	Lista();
	~Lista();

	bool listaVuota();
	tipoelem leggiLista(Cella<tipoelem>* );
	Cella<tipoelem>* primoLista(Lista<tipoelem> *);
	bool fineLista(Cella<tipoelem>*);
	Cella<tipoelem>* succLista(Cella<tipoelem>*);
	Cella<tipoelem>* precLista(Cella<tipoelem>*);
	void insLista(Lista<tipoelem> *, tipoelem, Cella<tipoelem>* );
	void cancLista(Cella<tipoelem>*);
	void scriviLista(tipoelem, Cella<tipoelem>*);
	void stampaLista(Lista<tipoelem> *);

private:
     void creaLista();   
     nodo<tipoelem> core;// cuore della lista
	 int n_elementi;

};

template <class tipoelem>
Lista<tipoelem>::Lista()  {	creaLista(); };

template <class tipoelem>
Lista<tipoelem>::~Lista() {};

template <class tipoelem>
void Lista<tipoelem>::creaLista()
/*
 * SPECIFICA SEMANTICA: POST: L'= v, v = < > (sequenza vuota)
 */
 {
	 n_elementi = 0;
 };

template <class tipoelem>
void Lista<tipoelem>::insLista(Lista<tipoelem> *L, tipoelem in, Cella<tipoelem>* pos)
/*
 * SPECIFICA SEMANTICA: INSLISTA(a,p,L) = L'
 *   PRE: p = pos(i) 1 <= i <=n+1
 *   POST: L' = < a1, a2, …, ai-1, a, ai, ai+1, …, an>, se 1 <= i <= n
 * 	       L' = <a1, a2, …,an, a> ,  se i = n+1 (e quindi L' = < a > se i = 1 e L = < >)
 *
 *    con questa realizzazione se 1 <  i < n il precedente elemento, ai, viene sostituito
 * PARAMETRI:
 *  		  in  valore di tipo tipoelem dell'elemento
 *  			    inserito nella lista
 *        pos  posizione dell'elemento all'interno della lista
        	  L  puntatore di tipo Lista<tipoelem>
 */
{
   core.create_new(in, pos);
   n_elementi++;
};

template <class tipoelem>
void Lista<tipoelem>::scriviLista(tipoelem n, Cella<tipoelem>* p)  
/*
 * SPECIFICA SEMANTICA: SCRIVILISTA(a,p,L) = L'
 *   PRE: p = pos(i) 1 <= i <= n
 *   POST: L' = < a1, a2, …, ai-1, a, ai+1, …, an>
 *
 * PARAMETRI:   n  valore dell'elemento da sovrascrivere
 *              p  posizione dell'elemento da sovrascrivere
 *          (per semplicità viene omesso il parametro L
 *           indicato nella specifica)
 */
{   assert(!listaVuota());
	
   core.set_value(p , n);
};

template <class tipoelem>
Cella<tipoelem>* Lista<tipoelem>::primoLista(Lista<tipoelem> *L) 
/*
 * SPECIFICA SEMANTICA: PRIMOLISTA(L) = p
 *   	POST: p = pos(1) (se L = v pos(1) = pos(n+1))
 *
 */
{
   Cella<tipoelem>* output; //posizione
   output = core.get_succ(core.first);
    return output;
};

template <class tipoelem>
bool Lista<tipoelem>::listaVuota()
/*
 * SPECIFICA SEMANTICA: LISTAVUOTA(L)= b
 * 	POST: b = TRUE SE L = < > ALTRIMENTI b = FALSE
 * (per semplicità si omette il parametro L)
 */
{
	return (n_elementi == 0);
};

template <class tipoelem>
bool Lista<tipoelem>::fineLista(Cella<tipoelem>* pos)
/*
 * SPECIFICA SEMANTICA: FINELISTAFINELISTA(p,L) = b
 * 	   PRE:  p = pos(i) 1 <= i <= n+1
 *     POST: b = TRUE SE p = pos(n+1) ALTRIMENTI b = FALSE
 *
 * PARAMETRI:
 *            pos  posizione dell'elemento in considerazione
 *     	  (per semplicità si omette il parametro L)
 */
{
	 bool esito = false;
	 Cella<tipoelem>* px = core.last_full();

	  if (pos == px)
	    esito = true;

	  return esito;
};

template <class tipoelem>
tipoelem Lista<tipoelem>::leggiLista(Cella<tipoelem>* pos) 
/*
 * SPECIFICA SEMANTICA: LEGGILISTA(p,L)= a
 * 	PRE:  p = pos(i) 1 <= i <= n
 * 	POST: a = ai
 *
 * PARAMETRI:
 *            pos posizione dell'elemento da leggere
 *          (per semplicità si omette il parametro L)
 */
{ 
 assert(!listaVuota());
            
  return core.get_value(pos);
};

template <class tipoelem>
 Cella<tipoelem>* Lista<tipoelem>::succLista(Cella<tipoelem>* pos)
/*
 * SPECIFICA SEMANTICA: SUCCLISTA(p,L) = q
 * 	PRE:  p = pos(i) 1 <= i <= n
 *     POST: q = pos(i+1)
 *
 * PARAMETRI:
 *         pos posizione dell'elemento di cui si vuol
 *              conoscere il successivo
 *      (per semplicità si omette il parametro L)
 */
{
  Cella<tipoelem>* output = core.get_succ(pos);

  return output;
};

template <class tipoelem>
Cella<tipoelem>* Lista<tipoelem>::precLista(Cella<tipoelem>* pos)
/*
 * SPECIFICA SEMANTICA: PRECLISTA(p,L) = q
 *     PRE:  p = pos(i) 2 <= i <= n
 *     POST: q = pos(i-1)
 *
 *  PARAMETRI:
 *       pos  posizione dell'elemento di cui si vuol
 *            conoscere il precedente
 *      (per semplicità si omette il parametro L)
 */
{
   Cella<tipoelem>* output = core.get_prec(pos);

   return output;
};

template <class tipoelem>
void Lista<tipoelem>::cancLista(Cella<tipoelem>* pos)  
/*
 * SPECIFICA SEMANTICA: CANCLISTA(p,L) = L'
 *     PRE:  p = pos(i) 1 <= i <=n
 *     POST: L' = < a1, a2, …, ai-1, ai+1, …, an>
 *
 *  PARAMETRI:
 *      pos  posizione dell'elemento da cancellare
 *       (per semplicità si omette il parametro L)
 */
{
   assert(!listaVuota());
  
   core.del_current(pos);
   n_elementi--;
};

template <class tipoelem>
void Lista<tipoelem>::stampaLista(Lista<tipoelem> *lis)  
/*
 * PARAMETRI:
 *          lis  puntatore ad una lista di tipo tipoelem
 */
{
   assert(!(lis->listaVuota()));
   core.print();
};

#endif  //_LISTA_

