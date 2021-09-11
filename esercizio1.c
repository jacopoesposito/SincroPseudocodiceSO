/* Una commissione composta da 3 commissari (di cui un presidente), dovendo esaminare N studenti presenti in un'aula, opera come segue: prima dell'esame,
 * uno studente effettua il riconoscimento con un commissario e successivamente si presenta alla commissione mettendosi in attesa di ricevere domande.
 *  Il presidente, per ogni studente, decide il numero di domande che verranno fatte ed i 3 commissari effettuano, in maniera random ed una alla volta le domande. 
 *  Terminate le domande, lo studente lascia l'aula, ogni commissario gli attribuisce un voto ed il presidente assegna il voto finale come media dei voti dei commissari.
Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili.  */

int id;
int numeroDomande;
int voto[3]; 
int indice = 0;
presidente : semaphore = 1;
studente_entra : semaphore = 0;
scegli_numero_d : semaphore = 0;
documentoAccettato : semaphore 0;
decidi_domande : semaphore = 0;
mutex_commiss : semaphore = 0;
collega : semaphore = 1;
array_voto_mutex : semaphore = 0;
commissione_fintio : semaphore = 0;
mutex1 : semaphore = 0;


studente(i){
	
	signal(studente_entra);
	wait(documentoAccettato);
	
	wait(presidente);
	wait(commissario);
	wait(mutex);
		id = i;
	signal(mutex);
	signal(scegli_numero_d);
	int commissari_ind = 0;

	while(commissari_ind<3){
		wait(domanda[i]);
		commissari_ind++;
		rispondi();
		signal(risposta);
	}
	
	wait(voto);

	wait(array_voto_mutex);
		voto={0, 0, 0}
		indice = 0;
	signal(array_voto_mutex);
	exit();
}


commissari(){

	while(1){
	wait(studente_entra);
		esaminaDocumento();
	signal(documentoAccettato);
	
	wait(decidi_domande[id]);
	wait(risposta);
	mutex(mutex_commiss);
		faidomanda(numerodomande);
	signal(mutex_commiss);
	signal(domanda[id];
	
	wait(array_voto_mutex);
		voto[indice]=sceglivoto();
		indice++;
		if(indice==3)
			signal(commissione_finito);
	signal(array_voto_mutex);

	
	
	signal(commissario);
	}
}


presidente(){

	while(1){
	wait(scegli_numero_d);
		wait(mutex_domande);
			numeroDomande=rand();
		signal(mutex_domande);
	signal(decidi_domande[id]);


	wait(commissione_finito);
		faimedia(voto);
	signal(voto);
	signal(presidente);
	}
}

