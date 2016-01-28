/*
 *Quest'opera è stata rilasciata con licenza Creative Commons Attribuzione - Non commerciale - 
 *Condividi allo stesso modo 3.0 Italia. Per leggere una copia della licenza visita il 
 *sito web http://creativecommons.org/licenses/by-nc-sa/3.0/it/  
 *o spedisci una lettera a Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
 *
 * Classe cella: contiene l'astrazione relativa alla cella
 *
 * Autore: Riccardo Monterisi http://riccardomonterisi.altervista.org/
 */

#ifndef CELLA_H_
#define CELLA_H_

template <class tipoelem>
class Cella{
public:
	tipoelem dato;
	Cella<tipoelem> *prec;
	Cella<tipoelem> *succ;

};
/*
 * da cambiare ogni volta
 */
typedef Cella<float>* posizione;

typedef Cella<float>* NODO;

#endif /* CELLA_H_ */
