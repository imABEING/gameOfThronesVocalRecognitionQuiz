/////////////////////////////////////////////////////////////////
/////////////Game of Thrones Vocal Recognition Quiz//////////////
/////////////////////////////////////////////////////////////////
/////////////Created by Kamilah Mitchell on 01/21/15/////////////
/////////////////////////////////////////////////////////////////
//
//This game uses the Csound sampler to play back audio samples of GoT characters within a multiple choice quiz.
//
//
//to compile & run: gcc -o gameOfThronesVocalRecognitionQuiz gameOfThronesVocalRecognitionQuiz.c && ./gameOfThronesVocalRecognitionQuiz
//
//
//
//
//
//


#include <stdio.h>
#include <string.h>

#define LINE "___________________________________"
#define TITLE "  Game of Thrones Vocal Recognition Quiz"
#define AUTHOR "  by Kamilah Mitchell"

    FILE *csdPointer;
    char csdFile[256] = "Playback.csd";
    void system();
    void heading();


int game();
int rep();
int Stark();
int Tyrell();
int Greyjoy();
int Arryn();
int Baelish();
int Lannister();
int Martell();
int sBaratheon();
int jBaratheon();


void heading()
{
	system("clear");
	printf("\n \t %s \n", LINE);
	printf("\n \t %s \n", TITLE);
	printf("\n \t %s \n", AUTHOR);
	printf("\t %s \n", LINE);
	printf("\n \t %s \n \n", LINE);
}

int main()
	
	{

	//Welcome screen and tone
    heading();

   csdPointer = fopen(csdFile, "w");
   if(csdPointer != NULL)
   
    {   	
	fprintf(csdPointer,"<CsoundSynthesizer>\n");
	fprintf(csdPointer,"<CsInstruments>\n");
	fprintf(csdPointer,"instr testing\n");
	fprintf(csdPointer," a1 oscili 7000, p5, 1\n");
	fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
	fprintf(csdPointer," out a1 * k1\n");
	fprintf(csdPointer,"endin\n");
	fprintf(csdPointer,"</CsInstruments>\n");
	fprintf(csdPointer,"<CsScore>\n");
	fprintf(csdPointer,"f 1  0 8192 10   1 ; GEN10 to compute a sine wave\n");
	fprintf(csdPointer,"i \"testing\" 0.3 0.3 0 440\n");
	fprintf(csdPointer,"i \"testing\" 0.6 0.3 0 494\n");
	fprintf(csdPointer,"i \"testing\" 0.9 0.3 0 523\n");
	fprintf(csdPointer,"i \"testing\" 1.2 0.3 0 660\n");
	fprintf(csdPointer,"i \"testing\" 1.5 0.3 0 880\n");

	fprintf(csdPointer,"i \"testing\" 1.9 2 0.1 440\n");
	fprintf(csdPointer,"i \"testing\" 1.9 2 0.1 494\n");
	fprintf(csdPointer,"i \"testing\" 1.9 2 0.1 523\n");
	fprintf(csdPointer,"i \"testing\" 1.9 2 0.1 330\n");

	fprintf(csdPointer,"e 2.2\n");	
	fprintf(csdPointer,"</CsScore>\n");
	fprintf(csdPointer,"</CsoundSynthesizer>\n");
    }
    	
	fclose(csdPointer);
	
	char commandline [1000] = "csound -odac -d -O null ";
	strcat(commandline, csdFile);
	system (commandline);		
	char cleanup [1000] = "rm ";
	strcat(cleanup, csdFile);
	system (cleanup);		
	
	game();
	}


	int game()
	{
		heading();


	//user input
	printf("\n");
	printf("Choose a Kingdom of Origin: \n");

    printf("1 ------ the North\n");
    printf("2 ------ the Reach\n");
    printf("3 ------ the Iron Islands\n");
    printf("4 ------ the Vale\n");
    printf("5 ------ the Riverlands\n");
    printf("6 ------ the Westerlands\n");
    printf("7 ------ Dorne\n");
    printf("8 ------ the Stormlands\n");
    printf("9 ------ the Crownlands\n");	 

    printf("(Input the corresponding number)\n\n\n");

    //choice
    int choice;
    int answer;

    scanf("%d", &choice);

    //North, Ned Stark
	if(choice==1)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Stark();

		printf("Who spoke these words?\n");

		printf("1 --- Tyrion Lannister\n");
		printf("2 --- Ned Stark\n");
		printf("3 --- Daenerys Targaryen\n");
		printf("4 --- Oberyn Martell\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==2)
		{
			//play winning sound
			printf("///////////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Lord Eddard Stark of Winterfell!///////\n");
			printf("///////////////////////////////////////////////////////////////////\n");
			printf("*******************************************************************\n\n");
			rep();			
			
		}

		else
		{
			printf("*******************************\n");
			printf("Sorry! The answer was Ned Stark\n");
			printf("*******************************\n\n");
			rep();
		}
	}

	//the Reach, Olenna Tyrell
	else if(choice==2)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
	
		Tyrell();

		printf("Who spoke these words?\n");

		printf("1 --- Olenna Tyrell\n");
		printf("2 --- Roose Bolton\n");
		printf("3 --- Margaery Tyrell\n");
		printf("4 --- Sansa Stark\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==1)
		{
			//play winning sound
			printf("///////////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Lady Olenna Tyrell of Highgarden!//////\n");
			printf("///////////////////////////////////////////////////////////////////\n");
			printf("*******************************************************************\n\n");
			rep();		
			
		}

		else
		{
			//play losing sound
			printf("***********************************\n");
			printf("Sorry! The answer was Olenna Tyrell\n");
			printf("***********************************\n\n");
			rep();
		}
	}


	//Iron Islands, Theon Greyjoy
	else if(choice==3)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Greyjoy();

		printf("Who spoke these words?\n");

		printf("1 --- Ramsay Bolton\n");
		printf("2 --- Lord Varys\n");
		printf("3 --- Theon Greyjoy\n");
		printf("4 --- Sir Gregor Clegane, 'The Mountain'\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==3)
		{
			//play winning sound
			printf("////////////////////////////////////////////////\n");
			printf("///////You're right, it was Theon Greyjoy!//////\n");
			printf("////////////////////////////////////////////////\n");
			printf("************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("***********************************\n");
			printf("Sorry! The answer was Theon Greyjoy\n");
			printf("***********************************\n\n");
			rep();
		}
	}

	//the Vale, Robin Arryn
	else if(choice==4)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Arryn();

		printf("Who spoke these words?\n");

		printf("1 --- Bran Stark\n");
		printf("2 --- Tommen Baratheon\n");
		printf("3 --- Yara Greyjoy\n");
		printf("4 --- Robin Arryn\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==4)
		{
			//play winning sound
			printf("//////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Robin Arryn of the Vale!//////\n");
			printf("//////////////////////////////////////////////////////////\n");
			printf("**********************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("*********************************\n");
			printf("Sorry! The answer was Robin Arryn\n");
			printf("*********************************\n\n");
			rep();
		}
	}

	//the Riverlands, Petyr Baelish
	else if(choice==5)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Baelish();

		printf("Who spoke these words?\n");

		printf("1 --- Rob Stark\n");
		printf("2 --- Peter Baelish, 'Littlefinger'\n");
		printf("3 --- Renly Baratheon\n");
		printf("4 --- John Snow\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==2)
		{
			//play winning sound
			printf("//////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Peter Baelish, Littlefinger!//////\n");
			printf("//////////////////////////////////////////////////////////////\n");
			printf("**************************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("***********************************\n");
			printf("Sorry! The answer was Peter Baelish\n");
			printf("***********************************\n\n");
			rep();
		}
	}

	//the Westerlands, Tywin Lannister
	else if(choice==6)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Lannister();

		printf("Who spoke these words?\n");

		printf("1 --- Maester Pycelle\n");
		printf("2 --- Khal Drogo\n");
		printf("3 --- Tywin Lannister\n");
		printf("4 --- King Robert Baratheon\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==3)
		{
			//play winning sound
			printf("/////////////////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Tywin Lannister, Lord of Casterly Rock!//////\n");
			printf("/////////////////////////////////////////////////////////////////////////\n");
			printf("*************************************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("*************************************\n");
			printf("Sorry! The answer was Tywin Lannister\n");
			printf("*************************************\n\n");
			rep();
		}
	}

	//Dorne, Oberyn Martell
	else if(choice==7)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		Martell();

		printf("Who spoke these words?\n");

		printf("1 --- Prince Oberyn Martell\n");
		printf("2 --- Jorah Mormont\n");
		printf("3 --- Sir Sandor Clegane, 'The Hound'\n");
		printf("4 --- Bronn\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==1)
		{
			//play winning sound
			printf("//////////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Prince Oberyn Martell, of Dorne!//////\n");
			printf("//////////////////////////////////////////////////////////////////\n");
			printf("******************************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("************************************\n");
			printf("Sorry! The answer was Oberyn Martell\n");
			printf("************************************\n\n");
			rep();
		}
	}
	

	//the Stormlands, Stannis Baratheon
	else if(choice==8)
	{
		printf("\n\n");
		printf("Listen to this vocal sample...............\n\n");
		
		sBaratheon();

		printf("Who spoke these words?\n");

		printf("1 --- Mace Tyrell\n");
		printf("2 --- Edmure Tully\n");
		printf("3 --- Lord Baric Dondarrion\n");
		printf("4 --- Stannis Baratheon\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==4)
		{
			//play winning sound
			printf("///////////////////////////////////////////////////////////////////////////\n");
			printf("///////You're right, it was Stannis Baratheon, Lord of Dragonstone!//////\n");
			printf("///////////////////////////////////////////////////////////////////////////\n");
			printf("***************************************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("***************************************\n");
			printf("Sorry! The answer was Stannis Baratheon\n");
			printf("***************************************\n\n");
			rep();
		}
	}

	//the Crownlands, Joffrey Baratheon
	else if(choice==9)
	{
		printf("\n\n");

		printf("Listen to this vocal sample...............\n\n");
		
		jBaratheon();

		printf("Who spoke these words?\n");

		printf("1 --- Robert Baratheon\n");
		printf("2 --- Rickon Stark\n");
		printf("3 --- Joffrey Baratheon\n");
		printf("4 --- Renly Baratheon\n\n");

		//answer
		printf("Type your number choice\n\n");

		scanf("%d", &answer);

		printf("\n");

		if(answer==3)
		{
			//play winning sound
			printf("////////////////////////////////////////////////////////////////////////////\n");
			printf("//Correct, it was Joffrey Baratheon, King of the Andals and the First Men!//\n");
			printf("////////////////////////////////////////////////////////////////////////////\n");
			printf("****************************************************************************\n\n");
			rep();			
			
		}

		else
		{
			//play losing sound
			printf("****************************************\n");
			printf("Sorry! The answer was Joffrey Baratheon.\n");
			printf("****************************************\n\n");
			rep();
		}
	}

	else
	{
		//FIX! Ends here
		printf("\n");
		printf("That was not a valid choice. Come on. ");
		printf("\n");
		rep();
	}


	return 0;	
}



int rep()
	{
		int replay;

		printf("");
		printf("Would you like to play again?\n");
		printf("1 --- yes\n");
		printf("2 --- no\n");

		scanf("%d", &replay);

		if(replay==1)
		{
			game();
		}

		else
		{
			printf("\n");
			printf("Goodbye!\n");
			printf("********************");
		}
		return 0;
	}


		int Stark()
		{
		   csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"NedStark.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 2.5 0 1 \n");
			fprintf(csdPointer,"e 3\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
		}
	



int Tyrell()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"OlennaTyrell.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 3 0 1 \n");
			fprintf(csdPointer,"e 3.5\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int Greyjoy()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"TheonGreyjoy.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 5.5 0 1 \n");
			fprintf(csdPointer,"e 6\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int Arryn()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"RobinArryn.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 6.3 0 1 \n");
			fprintf(csdPointer,"e 6.8\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int Baelish()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"PeterBaelish.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 7.1 0 1 \n");
			fprintf(csdPointer,"e 7.6\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int Lannister()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"TywinLannister.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 4.7 0 1 \n");
			fprintf(csdPointer,"e 5.2\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int Martell()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"OberynMartell.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 7.2 0 1 \n");
			fprintf(csdPointer,"e 7.7\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

int sBaratheon()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"StannisBaratheon.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 3.4 0 1 \n");
			fprintf(csdPointer,"e 4\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}


int jBaratheon()
{
	csdPointer = fopen(csdFile, "w");
		   if(csdPointer != NULL)
		   
		    {   	
			fprintf(csdPointer,"<CsoundSynthesizer>\n");
			fprintf(csdPointer,"<CsInstruments>\n");
			fprintf(csdPointer,"instr testing\n");
			fprintf(csdPointer," a1 diskin2 \"JoffreyBaratheon.aif\", p5\n");
			fprintf(csdPointer," k1 linen 1, .2, p3, .3\n");
			fprintf(csdPointer," out a1 * k1\n");
			fprintf(csdPointer,"endin\n");
			fprintf(csdPointer,"</CsInstruments>\n");
			fprintf(csdPointer,"<CsScore>\n");
			fprintf(csdPointer,"i \"testing\" 0 6.2 0 1 \n");
			fprintf(csdPointer,"e 6.7\n");	
			fprintf(csdPointer,"</CsScore>\n");
			fprintf(csdPointer,"</CsoundSynthesizer>\n");
		    }
		    	
			fclose(csdPointer);
			
			char commandline [1000] = "csound -odac -d -O null ";
			strcat(commandline, csdFile);
			system (commandline);		
			
			return 0;	
}

