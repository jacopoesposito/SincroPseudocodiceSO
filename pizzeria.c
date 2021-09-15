/* In una pizzeria, due pizzaioli sfornano continuamente pizze che pongono di volta in volta in uno di N piatti
disponibili su un bancone. I piatti sono prelevati da M (M<N) camerieri che provvedono a servirle ai tavoli.
Ciascun cameriere può portare 2 pizze per volta, se disponibili, ma, in caso di affollamento, i camerieri
preleveranno 3 pizze per volta. Fornire una soluzione con semafori e discutere eventuali problemi di
starvation/deadlock. */


list : bancone;

pizzaiolo(){

	while(1){
		wait(mutex);
			if(bancone.size()<N){ //Controllo che il bancone non sia pieno
				bancone.add(1);
			}
		signal(mutex);
	
	}



}
cameriere(){

	while(1){
		wait(mutex);
			if(isAffolato()){ //Controllo che il locale sia affolato, in caso positivo posso prendere tre piatti.
				if(bancone.size>=3){ //Controllo la disponibilità delle pizze nel bancone 
					bancone.remove(1);
					bancone.remove(1);
					bancone.remove(1);
				}
			}else{
				if(bancone.size>=2){ //Controllo la disponibilità delle pizze nel bancone
					bancone.remove(1);
					bancone.remove(1);
				}
			}
		signal(mutex);
	}
}
