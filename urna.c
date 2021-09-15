/* Per lo svolgimento di un esame, una commissione decide di assegnare agli N candidati le tracce d'esame secondo il seguente schema. 
 * La commissione inserisce in un'urna M>N tracce ed attende che tutti i candidati siano presenti. 
 * I candidati, uno alla volta, estraggono 3 tracce dall'urna, ne scelgono una e riconsegnano alla commissione le altre due. 
 * La commissione inserisce le due tracce nell'urna e chiama il candidato successivo, finchè tutti i candidati hanno scelto la propria traccia. 
 * Commissione e candidati terminano solo dopo che tutti i candidati hanno ricevuto la traccia.
 * Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili.  */




int : urna[M];
int : indiceCandidati = 0;
int : indiceEstrazione = 0;
char : tracciaScartata1
char : tracciaScartata2

semaphore : estrazione_completata = 0;
semaphore : candidati = 0;
semaphore : chiamata_estrazione = 1;
semaphore : fine = 0;
semaphore : entra = 0;
commissione(){

	inserisciTracce(urna);
	for(1...N)
	signal(entra);

	wait(candidati);
	
	while(1){
		wait(estrazione_completata);
			wait(mutex_estraggo);
				tracceScelte.add(tracciaScartata1);
				tracceScelte.add(tracciaScartata2);
			if(indiceEstrazione == n){
				signal(mutex_estraggo);
				for(1...N)
				signal(fine);
				break;
			}	
			signal(mutex_estraggo);
		signal(chiamata_estrazione);
	}
	
	exit();
}

candidati(){
	int : tracceScelte[3]
	
	wait(entra);
	
	wait(mutex_ind);
	if(indiceCandidati > n){
		exit();
	}
	else{
		indiceCandidati++
	}

	if(indiceCandidati == n){
		signal(candidati);
	}
	signal(mutex_ind);

	wait(chiamata_estrazione);
		wait(mutex_estraggo);
			tracceScelte[0] = scegliTraccia(rand()%M) //Scelgo la traccia e la rimuovo dall'urna
			tracceScelte[1] = scegliTraccia(rand()%M)
			tracceScelte[2] = scegliTraccia(rand()%M)

			tracciaScartata1 = tracceScelte[rand()%2]; //Rand speciale che restituisce due numeri diversi compresi nell'intervallo 0...2
			tracciaScartata2 = tracceScelte[rand()%2];
			indiceEstrazione++;
		signal(mutex_estraggo);
	signal(estrazione_completata);

	wait(fine);
}


