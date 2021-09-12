/*  Si consideri il seguente problema con 4 fumatori ed un tabaccaio:
 *  Ogni fumatore continua a creare una sigaretta ed a fumarla, ma per farlo ha necessità di tabacco, cartine, filtro e fiammiferi. 
 *  Purtroppo ognuno dei 4 fumatori possiede solo uno di questi elementi, mentre il tabaccaio possiede naturalmente tutti gli elementi in un quantitativo pari a tabacco=100, cartine=120, filtro=80, fiammiferi=130. 
 *  Il tabaccaio pone casualmente tre degli elementi sul bancone, per cui il fumatore che possiede il rimanente elemento, può fare la sigaretta e fumarla. 
 *  Il procedimento continua finchè ci sono elementi sufficienti. Trovare una soluzione con semafori. 
 *  Si fornisca una soluzione usando semafori e processi. Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili. */



list : bancone
int : fatto;

tabaccaio(){

	typedef struct Elemento{
		tipo = 1...3
		quantita = 80...120
	
	};

	Elemento elementi[3];
	


	wait(fumatori);

		int el1 =  rand();
		int el2 =  rand();
		int el3 = rand();
	if(elemento[el1].quantita > 0 and elemento[el2].quantita > 0 and elemento[el3].quantita >0){
		elementi[el1].quantita--;
		elementi[el2].quantita--;
		elementi[el3].quantita--;
		
		wait(mutex_bancone);
			bancone.add(elemento[el1].tipo);
			bancone.add(elemento[el2].tipo);
			bancone.add(elemento[el3].tipo);
		signal(mutex_bancone);
	
	signal(aiutoTabaccaio);
	signal(tabacco);


	}
}


fumatori(){
	
	tabacco = 0;
	cartine = 0;
	filtro = 0;
	fiammiferi = 0;
	
	array : elementi_necessari;
	int fatto;
	while(1){
		fatto = 0
		wait(tabacco);
	
		while(fatto == 0){
			wait(mutex_bancone);
			if(elementi_necessari=verifica_disponibilita_elementi()){
				removeFromBancone(elementi_necessari)
				fatto = 1;
			}
			signal(mutex_bancone);
			//FUMA
			if(fatto == 0){
				wait(aiutoTabaccaio);
			}
		}	
	
		signal(fumatori);	
	}
}

//L'algoritmo presenta dei problemi di starvation iniziale in quanto servono almeno due iterazioni del tabaccaio per fornire i requisiti minimi ai fumatori.
