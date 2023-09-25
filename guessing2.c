#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct player
{
    char name[10];
    int guesses;

};






//generates random int 10-100
int getGuess() {
	srand(time(0));
	int int2Sqr = rand() % 90 + 10;
	return int2Sqr;

}
//adjust list based on score
int updateList(struct player leaders[],int guesses,char name[]){
		for (int i=0; i<5; i++){
			if (leaders[i].guesses == -1){
				leaders[i].guesses = guesses;
				strcpy(leaders[i].name,name);
				break;
			}
			else if (guesses < leaders[i].guesses){
				for (int j=0; j<5; j++){
					leaders[j-1].guesses = leaders[j].guesses;
				strcpy(leaders[j-1].name,leaders[j].name);
				}
				leaders[i].guesses = guesses;
				strcpy(leaders[i].name,name);
				break;
			}
//print leadboards
		}
for (int i = 0; i<5;i++){
printf("%d.-%s SCORE : %d\n",i+1,leaders[i].name,leaders[i].guesses);
}
	return 0;
}





void PlayGuessingGame(struct player leaders[]) {


 printf("WHATS YOUR NAME?");
 char name[10];
 scanf("%s",&name);
 
 
   


    //num of guesses
    int guesses = 0;
	// user guessed num
		int  guessedNum = 0;
		//number the user is trying guess
		int numToGuess = getGuess();
		//number to be printed as a hint
		float numToHint = sqrt(numToGuess);
		printf("%f is the sqaure root of what number?!?!?", numToHint);
		scanf("%d", &guessedNum);
		if (guessedNum == numToGuess) {
			guessedNum = numToGuess;
            guesses++;

			printf("GOT IT FIRST TRY, NICE\n");
            printf("it took you %d trys\n",guesses);
			updateList(leaders,guesses,name);
			return;
		}

		while (guessedNum != numToGuess) {
			if (guessedNum > numToGuess) {
				printf("TOO HIGH, GUESS AGAIN ");
                guesses++;
			}
			else if (guessedNum < numToGuess) {
				printf("TOO LOW, GUESS AGAIN ");
               guesses++;
			}

			scanf("%d", &guessedNum);
		}
		
		if (guessedNum == numToGuess) {
           guesses++;
			printf("FINALLY GOT IT, TOOK YOU LONG ENOUGH\n");
            printf("it took you %d trys\n",guesses);
		
			
		}
		updateList(leaders,guesses,name);


	}

//function to prompt user inputs to contine playing or quit
int main(){
struct player leaders[5];

for (int i = 0; i < 5; i++) {
        strcpy(leaders[i].name, "N/A");
        leaders[i].guesses = -1;
    }

//creates/loads file
    FILE* fptr = NULL;
char filename[] = "C:/players.txt";

fptr = fopen(filename, "w" );


 
	int playAgain = 2;


	while (playAgain != 1) {
   
	printf("PRESS 2 TO PLAY GUESSING GAME, PRESS 1 TO QUIT");
	scanf("%d", &playAgain);
	if (playAgain == 1) {
		printf("BYE BYE");
		break;
	}
	PlayGuessingGame(leaders);
	
		
}
//saves formatted list to file
	for(int i = 0;i<5;i++){
		fprintf(fptr,"%d. %s  SCORE: %d\n",i+1,leaders[i].name,leaders[i].guesses);
	}
		return 0;
		fclose(fptr);
}