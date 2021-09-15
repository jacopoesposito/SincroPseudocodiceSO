// Si consideri il seguente problema:
// In un ristorante più persone siedono allo stesso tavolo e condividono B1 bottiglie di acqua e B2 bottiglie di vino. La politica della mensa è che un operatore della mensa controlla se terminano
// le bottiglie e le sostituisce se vuote fino a quando le persone non decidono di lasciare il ristorante.
// Si fornisca una soluzione usando semafori e processi. Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili.

typedef struct bottiglia{
	int : pieno = 1;
}

list bottiglia bottiglieAcqua;
list bottiglia bottiglieVino;
flag = 1;

operatore(){
	while(1){
		wait(mutex);
		if(orarioChiusra()){ //Orario chiusura restituisce true se il locale deve chiudere, immagino la mensa serva più clienti fintanto che non arriva l'orario di chiusura.
			flag = 1
			signal(mutex);
			break;
		}
		if(indiceAcqua > B1)
			indiceAcqua = 0;
		if(indiceVino > B2)
			indiceAcqua = 0;

		if(bottigliaAcqua[indiceAcqua].pieno == 0){
			sostituisciBottigliaAcqua(bottigliaAcqua[indiceAcqua], indiceAcqua);
			indiceAcqua++;

		}
		if(bottigliaVino[indiceVino].pieno == 0){
			sostituisciBottigliaVino(bottigliaVino[indiceVino], indiceVino);
			indiceVino++;
	
		}
		signal(mutex);
	}

}


cliente(){
	int sceltaVino;
	int sceltaAcqua;
	while(1){
		wait(mutex);
			if(noia() || flag == 1){ //Noia restituisce true se i clienti vogliono lasciare il locale
				signal(mutex)
				break;
			}
			sceltaAcqua = randSpeciale(B1); //Una rand speciale che restituisce solo indici di bottiglie piene
	       		sceltaVino =  randSpeciale(B2);
			beviAcqua(sceltaAcqua);
			beVino(sceltaVino);
		signal(mutex);
	}

}
