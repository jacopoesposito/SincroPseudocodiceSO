/* Si consideri il seguente problema:
 * Un servizio di pool-car ha a disposizione N automobili, ognuna assegnata ad una zona della città. 
 * Gli utenti del servizio si recano al punto di partenza e prenotano un posto sull'automobile per la zona desiderata. 
 * Ogni automobile ha a disposizione M posti. Una volta occupati gli M posti il veicolo parte per la zona stabilita. 
 * Nel caso in cui sia trascorso un tempo T, a partire dalla prima prenotazione per una determinata zona, il veicolo parte per la zona assegnata. 
 * Nel caso in cui non ci siano più posti disponibili su un veicolo, gli utenti in eccesso si mettono in attesa della prossima corsa per la zona desiderata.
 * Si fornisca una soluzione usando semafori e processi. 
 * Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili. */


typedef struct auto{
	posti: Semaforo = M
	tempo: int = T
	flag: int = 0
}Automobile


Automobile car[N]

parti: semaforo = 0

automobile(i){
	wait(parti)
	car[i].flag=0
	//arriva in zona
	signal(arrivo)
}

cliente(int id){
	
	wait(car[id].posti)
	if(sem_getvalue(car[id].posti) == M-1) //se è il primo
		cronometro(car[id].tempo,car[id].flag) //fa diventare la flag a 1 dopo T secondi
	if(sem_getvalue(car[id].posti) == 0 && car[id].flag == 1)
		signal(parti)
	wait(arrivo)
	signal(car[id].posti)
}
