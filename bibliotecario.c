/* Una biblioteca universitaria dispone di N posti per la consultazione dei libri e M (M<N) postazioni multimediali per la ricerca dei 
volumi. Ogni studente che accede alla biblioteca effettua la ricerca di un volume, successivamente si reca dal bibliotecario per 
richiederne una copia ed infine occupa un posto per consultare il libro. Si supponga che di ogni libro esistano K copie. Nel caso in cui 
non ci siano posti per la consultazione disponibili o se le copie del libro scelte sono terminate, lo studente lascia la biblioteca. */

#define N
#define M
#define K

typedef struct lib{
	int copie = K
	char *nome;
	char *autore;
}Libro

Libro libri[100];
int id_scelta
int id_stud
int flag=0
int flag_cons=0
studente(){
	int scelta;
	wait(mutex_mult)
		if(ind_posti_mult<M){
			ind_posti_mult++
			signal(mutex_mult)
			scelta = ricerca_libro(libri)//variabile locale per ricordare la scelta
			
			wait(bibliotecario) //1
			
			#wait(mutex_scelta)
			id_scelta = scelta //imposto scelta su variabile globale perché il bibliotecario è disponibile
			#signal(mutex_scelta)
			
			signal(scelta) 
			wait(risposta)
			wait(mutex_esito)
			if(flag==1 && ind_posti_cons<N){ //ho il libro e posso consultarlo
				flag=0
				flag_cons=1
				ind_posti_cons++
				signal(mutex_esito)
				
				signal(posti_cons)
				wait(vai)
				//CONSULTO LIBRO
				wait(mutex_esito)
				ind_posti_cons--
				signal(mutex_esito)
				#devo dare copia al bibliotecario
				wait(mutex_esito)
				restituisci_libro(libri,scelta);
				signal(mutex_esito)
				
				exit()
				
			}else if(ind_posti_cons==N){//non ci sono posti consultazione
				flag=0
				flag_cons=0
				signal(mutex_esito)
				signal(posti_cons)
				wait(vai)
				exit()
				
				exit()
			}else if(flag==0){//sono finite le k copie del libro richiesto
				flag_cons=1 //illudiamo bibliotecario per non fargli mettere il libro a posto
				signal(mutex_esito)
				signal(posti_cons)
				wait(vai)
				exit()
			}
			
		}
		else{
			signal(mutex_mult)
			exit()
		}
	
}

bibliotecario(){
	
	while(1){
		wait(scelta)
		
		wait(mutex_esito)
		flag=prendi_libro(libri,id_scelta) //se flag=1 allora c'è una copia del libro, altrimenti se =0 non c'è
		signal(mutex_esito)
		
		signal(risposta)
		
		wait(posti_cons)
		
		wait(mutex_esito)
		if(flag_cons==0)
			restituisci_libro(libri,id_scelta)
		signal(mutex_esito)
		
		signal(vai)
		
		signal(bibliotecario)
	}
	
}


