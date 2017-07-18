#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

typedef struct{
	int minerals;
	int free;
}node;

pthread_mutex_t mutex_minerals;
pthread_mutex_t mutex_center;
int map_minerals;
int user_minerals;
node *nodes;
int node_count;
pthread_t SCVs[5];
int marines = 0;
int workers = 5;

void set_stuffs_on_map(){
	map_minerals = 500 * node_count;
	for(int i = 0 ; i < node_count ; i++){
		nodes[i].free = 1;
		nodes[i].minerals = 500;
	}

}

void add_minerals(int load,int number){
	pthread_mutex_lock(&mutex_center);
		user_minerals += load;
		printf("SCV %d delivered minerals to the Command center\n",number);
		map_minerals -= load;
	pthread_mutex_unlock(&mutex_center);
}

void make_marine(){
	pthread_mutex_lock(&mutex_center);
		user_minerals -= 50;
	pthread_mutex_unlock(&mutex_center);
	marines++;
	printf("You wanna piece of me, boy?\n");
}

void *scv(void *argv){
		
	int counter;
	int cargo = 0;
	int worker_id = *((int*)argv);
	free(argv);

		while(map_minerals > 0){
			for(counter = 0 ; counter < node_count ; counter++){
				if(nodes[counter].minerals > 0 && nodes[counter].free == 1){
					pthread_mutex_lock(&mutex_minerals);
						nodes[counter].free = 0;
						printf("SCV %d is mining from mineral block %d\n",worker_id,counter+1);
						if(nodes[counter].minerals < 8){
							cargo = nodes[counter].minerals;
							nodes[counter].minerals = 0;
						}else{
							cargo = 8;
							nodes[counter].minerals -= 8;
							nodes[counter].free = 1;
						}
						pthread_mutex_unlock(&mutex_minerals);
						printf("SCV %d is transporting minerals\n",worker_id);
						sleep(2);
						add_minerals(cargo,worker_id);
						sleep(3);					
				}else{sleep(3);}

		}	

	}	
}

int main(int argc, char* argv[]){
	pthread_mutex_init(&mutex_minerals, NULL);
	pthread_mutex_init(&mutex_center, NULL);
	int i;	

	if(argc == 1){
		node_count = 2;	
		nodes = (node*) malloc(2 * sizeof(node));
	}else{
		node_count = atoi(argv[1]);
		nodes = (node*) malloc(node_count * sizeof(node));
	}

	set_stuffs_on_map();
	
	for(i = 0 ; i < 5 ; i++){
		int *arg = malloc(sizeof(*arg));
		*arg = i+1;
		int check = pthread_create(&SCVs[i], NULL, scv, arg);
		if(check){
			perror("pthread_create:");
			exit(EXIT_FAILURE);
		}
	}

	
	while (1){
		if(marines == 20){
			printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n",node_count * 500,user_minerals,workers,marines);
			exit(EXIT_SUCCESS);		
		}
		char input;
		scanf("%s",&input);
		if(input == 'm'){
			if(user_minerals >= 50){
			sleep(1);
			make_marine();
			}
			else{printf("Not enough minerals.\n");}
		}
	}

	for(i = 0 ; i < 5 ; i++){
		int check = pthread_join(SCVs[i],NULL);
		if(check){
			perror("pthread_join:");
			exit(EXIT_FAILURE);
		}
	}

	pthread_mutex_destroy(&mutex_minerals);
	pthread_mutex_destroy(&mutex_center);
		
	free(nodes);
	return 0;
}
