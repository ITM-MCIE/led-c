// LED application to turn on or off the user LED3
// Sep 2022
// Gerardo Marx

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//definitions:
#define LED3 "/sys/class/leds/beaglebone:green:usr3"

// Prototype functions

void WriteLED(char path[], char value[]); //Write commands to the LED path
void RemoveTrigger(); //remove the trigger of LED

// main
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Incorrect number of arguments ....\n");
		printf("use './main on' to turn on the LED\n");
		printf("use './main off' to turn off the LED\n");
		printf("----------------------\n");
		// more information for the user
		return 2;
	}
	printf("Number of Arguments OK\n");
	if(strcmp(argv[1], "on")==0){
		printf("LED on\n");
		RemoveTrigger();
		WriteLED("/brightness", "1");
	}
	else if(strcmp(argv[1], "off")==0){
		printf("LED off\n");	
		RemoveTrigger();
		WriteLED("/brightness", "0");
	}
	printf("App done!!!!\n");
	printf("----------------------\n");
	return 0;
}

// complete functions:
// Write command to a LED path
void WriteLED(char ledpath[], char value[]){
	FILE* fp; //file pointer to LED path
	char fullPath[100]; //variable to store the full LED path
	sprintf(fullPath, LED3 "%s", ledpath); 
    fp = fopen(fullPath, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void RemoveTrigger(){
	WriteLED("/trigger", "none");
}

