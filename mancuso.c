/*
   Nella sala prove del giovane talentuoso chitarrista Matteo Mancuso 
   possono entrare e trovare posto seduto al più N appassionati chitarristi
   per una Masterclass con Matteo.
   I partecipanti rimasti in piedi seguiranno il seminario successivo.
   Ogni allievo che ha trovato posto può richiedere 
   ad un collaboratore di Matteo Mancuso un modello di chitarra degli M modelli 
   messi a disposizione dalla casa produttrice, di cui Matteo Mancuso è testimonial, considerando che per ogni modello ci sono K chitarre. 
   Quando tutti gli N allievi hanno la propria chitarra, Matteo suona un pezzo semplice chiedendo a tutti gli  allievi di suonarlo insieme a lui. 
   La masterclass termina quando non ci sono più chitarristi in attesa
*/
typedef struct chitarra{
	int : quantita = K;
}

chitarra : chitarre[M];

semaphore : posti = N
semaphore : richiedi_chitarra = 0;
semaphore : collaboratore_disp = 1;
semaphore : richiedi_chitarra = 0;
semaphore : chitarra_concessa = 0;
semaphore : mancuso = 0;
semaphore : iniziolezione = 0;

int : indice = 0;

allievo(){

	wait(posti);
	wait(collaboratore_disp);
		chitarra_scelta=rand()%M;
		scelta_loc=chitarra_scelta;
	signal(richiedi_chitarra);
	wait(chitarra_concessa);

	wait(mancuso);
	
	wait(mutex_chitarra);
		restituiscichitarra(scelta_loc);
	signal(mutex_chitarra);
		
	signal(posti);
	exit(0);

}

collaboratore(){
	
	while(1){
	wait(richiedi_chitarra);
	wait(mutex_chitarra);
		indice++
		if(chitarre[chitarra_scelta].quantita>0){
			chitarre[chitarra_scelta].quantita--;
		}else{
			selezionaChitarraDisponibile(); //Se la chitarra scelta dall'allievo non c'è gliene do una a casa
		}
	signal(mutex_chitarra);
	signal(chitarra_concessa);
	signal(collaboratore_disp);

	wait(mutex_chitarra);
		if(indice == N){
			signal(mutex_chitarra);
			signal(iniziolezione);
		}
	signal(mutex_chitarra);
	}
}


mancuso(){
	while(1){
	wait(iniziolezione);

	for(1....N)
		signal(mancuso)
	
	//Strimpella
	}
	
}
