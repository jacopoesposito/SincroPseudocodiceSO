/* In un ambulatorio medico lavorano due medici ed un infermiere. Inizialmente i due medici sono in attesa
dell'arrivo dei pazienti. Un paziente entra nell'ambulatorio e si reca dal primo medico libero che esegue la visita medica. Al termine della visita, il medico redige un referto che inserisce in un portadocumenti con M posizioni.
L'infermiere preleva un referto alla volta e lo inserisce nel database dell'ambulatorio. Se entrambi i medici sono impegnati, il paziente si accomoda nella sala d'aspetto che dispone di N sedie. Se le N sedie sono tutte occupate, il paziente lascia l'ambulatorio.
Discutere la soluzione proposta in termini di possibili situazioni di starvation/deadlock e, nel caso, si propongano soluzioni ammissibili. */

#define N //sedie
#define M
coda: int =0
array[M]: Portadocumenti 
indice: int = 0
ind_med: int = 0

cons: semaforo =0
prod: semaforo =1
paz: semaforo = 0
med: semaforo = 0
ambulatorio: semaforo = 0



mutex_referto: mutex 
mutex_occupato: mutex

infermiere(){
	while(1){
		wait(cons) //0
		wait(mutex_referto)
		ins_database(array,indice)
		signal(mutex_referto)
		signal(prod)
	}
}

medico(){
	
	while(1){
		
		wait(paz)
		
		
		//inizia visita
		signal(med)
		
		wait(prod) //1
		wait(mutex_referto)
		crea_referto(array,indice)
		if(indice==M)
			indice=0
		indice++
		signal(mutex_referto)
		
		signal(cons) 
		
		wait(mutex_occupato)
		ind_med--
		if(coda>0)
			signal(ambulatorio)
		signal(mutex_occupato)
		
	}
	
}

paziente(){
	
	wait(mutex_occupato)
	if(coda<N && ind_med == 2){
		coda++
		signal(mutex_occupato)
		wait(ambulatorio)
	       	wait(mutex_occupato)
			ind_med++
		signal(mutex_occupato)	
		signal(paz)
		wait(med)
		exit()//esce il paziente
	}
	else if(ind_med<2){ //se è libero il medico mo' piglj ij perche' sono furbo e faccio starvation su quelli seduti perche' 
		ind_med++				//così dice la traccia
		signal(mutex_occupato)
		signal(paz)
		wait(med)
		//fa la visita
		exit() //esce il paziente perche' ha finito la visita
		
		
	}
	else if (coda>=N){
		//VAI VIA 
		signal(mutex_occupato)
		exit() //esce il paziente
	}
	
	
	
	
	
}

