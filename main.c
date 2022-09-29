// LED application to turn on or off a user LED
// Sep 2022
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LED3 "/sys/class/leds/beaglebone:green:usr3"

// Prototypes

void WriteLED(char fileName[], char value[]);
void RemoveTrigger();

// main
int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Incorrect number of arguments ....\n");
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
	}
	return 0;
}

// complete functions:
void WriteLED(char fileName[], char value[]){
	FILE* fp;
	char file[100];
	sprintf(file, LED3 "%s", fileName);
    fp = fopen(file, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void RemoveTrigger(){
	WriteLED("/trigger", "none");
}




