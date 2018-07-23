#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

//PUT "dictionary.txt" into "C:/TEMP" which is the file ally uses to store data

#define NUMBER_OF_CATEGORIES 4
#define NUMBER_OF_OBJECTS 15

//2dim array for storing list of strings
char food[NUMBER_OF_OBJECTS][50];
char countries[NUMBER_OF_OBJECTS][50];
char animals[NUMBER_OF_OBJECTS][50];
char sports[NUMBER_OF_OBJECTS][50];

//
struct player
{
	char name[25];
	int choice;
	int tries;
	int score;
};

void consoleColor()
{
	int choice1, choice2;
	char consolecolour[] = "COLOR 07";
	printf("\n\n0-black\n1-blue\n2-green\n3-aqua\n4-red\n5-purple\n6-yellow\n7-white\n8-gray\n9-light blue");
	printf("\nEnter the choice of background");
	scanf("%d", &choice1);
	switch (choice1)
	{
	case 0:
		consolecolour[6] = '0';
		break;
	case 1:
		consolecolour[6] = '1';
		break;
	case 2:
		consolecolour[6] = '2';
		break;
	case 3:
		consolecolour[6] = '3';
		break;
	case 4:
		consolecolour[6] = '4';
		break;
	case 5:
		consolecolour[6] = '5';
		break;
	case 6:
		consolecolour[6] = '6';
		break;
	case 7:
		consolecolour[6] = '7';
		break;
	case 8:
		consolecolour[6] = '8';
		break;
	case 9:
		consolecolour[6] = '9';
		break;

	}
	system(consolecolour);
	printf("\nEnter colour choice of text");
	scanf("%d", &choice2);

	switch (choice2)
	{
	case 0:
		consolecolour[7] = '0';
		break;
	case 1:
		consolecolour[7] = '1';
		break;
	case 2:
		consolecolour[7] = '2';
		break;
	case 3:
		consolecolour[7] = '3';
		break;
	case 4: 
		consolecolour[7] = '4';
		break;
	case 5: 
		consolecolour[7] = '5';
		break;
	case 6: 
		consolecolour[7] = '6';
		break;
	case 7:
		consolecolour[7] = '7';
		break;
	case 8: 
		consolecolour[7] = '8';
		break;
	case 9:
		consolecolour[7] = '9';
		break;
	}
	system(consolecolour);
	printf("\nThis is how your text will appear");
}
//prints newline 50 times
void clearScreen()
{
	for (int i = 0; i != 50; ++i)
		printf("\n");
}

void showHangman(int choice)                            /**This function show the hangman after each wrong try**/
{

	switch (choice)
	{

	case 0:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||   / %c", '\\');
		printf("\n\t||      ");
		break;
	case 1:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||     %c", '\\');
		printf("\n\t||      ");
		break;
	case 2:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||    | ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 3:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO/", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 4:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||   %cO ", '\\');
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	case 5:
		system("cls");
		printf("\n\t||===== ");
		printf("\n\t||    | ");
		printf("\n\t||    O ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		printf("\n\t||      ");
		break;
	}//end of switch-case
	return;
}


//checks if menu choice is greater than available choice. If it is, prompt user to choose again 
//choice is pointer to original choice, value is number of available choice
void validateChoice(int* choice, int value)
{
	int convertChar;
	do
	{
		convertChar = 0;
		char input[10];
		scanf(" %s", &input);
		//memset(input, '\0', 10);
		convertChar = atoi(input);
		printf("%d", convertChar);
		getchar();
		if (convertChar == 0 || convertChar > value)
			printf("Your choice is invalid, please try again: \n");
		else
		{
			*choice = convertChar;
			break;
		}
	} while (convertChar > value);
}

//main game function: variables are n = name, c = choice, s = score. If new game, score is 0
int RUN_GAME(char* n, int c, int* s, int* t)
{
	int score = *s;
	char name[25];
	strncpy(name, n, 25);

	//if tries == 8, boolLose = 1, else boolLose = 0
	int boolLose = 0;
	//total tries is 8
	int tries = *t;

	//bool escape: if '?' is entered, escape = 0, else escape = 1
	int escape = 1;
	while (boolLose != 1)
	{
		//user will fill this array up according to their input
		char guessedWord[50];
		memset(guessedWord, '\0', 50);
		int objectChoice = rand() % NUMBER_OF_OBJECTS;
		//this array is the correct array
		char word[50];

		//this array contains the letters that have been chosen
		char chosenLetters[50];
		memset(chosenLetters, '\0', 50);
		//iterator to iterate through the chosenLetter array
		int chosenLetters_it = 0;
		
		//copy the correct word into the local word array
		switch (c)
		{
		case 1:
			strncpy(word, food[objectChoice], 50);
			break;
		case 2:
			strncpy(word, countries[objectChoice], 50);
			break;
		case 3:
			strncpy(word, animals[objectChoice], 50);
			break;
		case 4:
			strncpy(word, sports[objectChoice], 50);
			break;
		}
		int objectSize = strlen(word);
		memset(guessedWord, '-', objectSize);

		//lowercase all letters in words
		for (int i = 0; i != objectSize; ++i)
		{
			word[i] = tolower(word[i]);
		}
		
		//boolean value whether input is correct. If correct is 0, else 1
		int passBool = 1;
		int passCount = 0;
		//number of whitespace chars in word
		int whiteSpaceCount = 0;
		for (int i = 0; i != objectSize; ++i)
		{
			if (word[i] == ' ')
			{
				++whiteSpaceCount;
				guessedWord[i] = ' ';
				++passCount;
			}
		}
		//number of valid letters that can be used as input
		//objectSize -= whiteSpaceCount;

		//number of letters entered that are correct

		while (tries != 5 && passBool == 1)
		{
			char input = '\0';
			//check if input word used is available in the word to be guessed. If true, return 0, else return 1
			int inputBool = 1;
			clearScreen();
			/****************************************************************************************/
			/****************************************************************************************/
			//DEBUG
			//DEBUG
			//DEBUG
			//printf("%s\n", word);
			//DEBUG
			//DEBUG
			//DEBUG
			/****************************************************************************************/
			/****************************************************************************************/
			showHangman(5-tries);
			printf("\n\nEnter '?' to save and leave the game\n");
			printf("Your Score: %d", score);
			printf("\n\ntry no %d\n\n", tries);
			printf("%s\n", guessedWord);
			printf("enter a letter\n");
			printf("word size: %d\n\n", objectSize);
			printf("Words Used: %s\n", chosenLetters);
			printf("Words Correct: %d\n", passCount);
			scanf(" %c", &input);

			if (input == '?')
			{
				clearScreen();
				printf("ESCAPE SEQUENCE DETECTED: SAVING...");
				Sleep(1000);
				escape = 0;
				break;
			}

			int reusedBool = 0;
			do
			{
				for (int i = 0; i != strlen(chosenLetters); ++i)
				{
					if (input == chosenLetters[i])
					{
						reusedBool = 1;
						break;
					}
					else
						reusedBool = 0;
				}
				if (reusedBool == 1)
				{
					printf("This choice has already been chosen Enter a new choice\n");
					scanf(" %c", &input);
				}

			} while (reusedBool != 0);
			

			chosenLetters[chosenLetters_it] = input;
			++chosenLetters_it;
	
			for (int i = 0; i != objectSize; ++i)
			{
				if (input == word[i])
				{
					guessedWord[i] = input;
					inputBool = 0;
					++passCount;
					++score;
				}
			}
			if (inputBool == 1)
			{
				clearScreen();
				printf("WRONG CHOICE!");
				Sleep(1000);
				++tries;
			}
			if (passCount == objectSize)
			{
				passBool = 0;
			}
			
		}
		if (escape == 0)
			break;

		if (tries == 5)
		{
			boolLose = 1;
			clearScreen();
			showHangman(5 - tries);
			printf("\n\n\nYOU LOSE! TRY AGAIN NEXT TIME...\n\n");
			Sleep(5000);
			break;
		}
		clearScreen();
		printf("CORRECT! NEXT...\n");
		Sleep(1000);
	}
	*s = score;
	*t = tries;
	return tries;
}

/*s = source, c = string the source is being compared to
**returns 1 when first 4 words are not the same, returns 0 if first 4 words are the same
*/
int wordCompare(const char* s, const char* c)
{
	//local variable for manipulating variables in s & c array easier
	char source[50];
	char compared[50];

	strncpy(source, s, 50);
	strncpy(compared, c, 50);
	
	//1 is false, 0 is true
	int boolean = 1;
	//check first 4 variables for exact similarity
	for (int i = 0; i != 50; ++i)
	{
		if (source[i] == compared[i])
		{
			boolean = 0;
		}
		else if (source[i] == '\0')
			break;
		else
		{
			boolean = 1;
			break;
		}
	}
	return boolean;
}

int readScores(FILE* fp, struct player* players)
{
	int playersIt = 0;
	char buffer[40] = {'\0'};
	for (int i = 0; i != 10; ++i)
	{
		//if end of file is hit
		if (fgets(buffer, 25, fp) == NULL)
		{
			break;
		}
		if (buffer[0] == '\0')
		{
			continue;
		}
		char name[25];
		memset(name, '\0', sizeof(name));
		int name_it = 0;
		int choice;
		int tries; 
		int score = 0;
		int whitespaces = 0;
		for (int x = 0; (size_t)x < strlen(buffer);)
		{
			if (buffer[x] == '<')
			{
				++x;
				while (buffer[x] != '>')
				{
					name[name_it] = buffer[x];
					++name_it; ++x;
				}
			}
			else if (buffer[x] == ' ')
			{
				++whitespaces;
				++x;

				switch (whitespaces)
				{
				case 1:
				{
					char stringChoice[2];
					memset(stringChoice, '\0', sizeof(stringChoice));
					stringChoice[0] = buffer[x];
					choice = atoi(stringChoice);
					++x;
					break;
				}
				case 2:
				{
					char stringTries[3];
					memset(stringTries, '\0', sizeof(stringTries));
					stringTries[0] = buffer[x];
					tries = atoi(stringTries);
					++x;
					break;
				}
				case 3:
				{
					char stringScore[4];
					//printf("YOU WORK");
					memset(stringScore, '\0', sizeof(stringScore));
					for (int k= 0; x != strlen(buffer); ++x, ++k)
					{
						stringScore[k] = buffer[x];
					}
					//printf("%s", stringScore);
					score = atoi(stringScore);
					break;
				}
				default:
					break;
				}
			}
			else
				++x;
		}
		strncpy(players[playersIt].name, name, 25);
		players[playersIt].choice = choice;
		players[playersIt].tries = tries;
		players[playersIt].score = score;
		++playersIt;
	}
	return playersIt;
}

void putScores(struct player* players, FILE* fp, int selection)
{
	fseek(fp, 0L, SEEK_END);
		char name[25];
		int choice = players[selection].choice;
		int tries = players[selection].tries;
		int score = players[selection].score;
		memset(name, '\0', 25);
		fputc('\n', fp);
		strncpy(name, players[selection].name, 25);
		fputc('<', fp);
		fputs(name, fp);
		fputc('>', fp);

		char temp[3];
		memset(temp, '\0', 3);
		_itoa(choice, temp, 10);
		fputc(' ', fp);
		fputs(temp, fp);

		_itoa(tries, temp, 10);
		fputc(' ', fp);
		fputs(temp, fp);

		_itoa(score, temp, 10);
		fputc(' ', fp);
		fputs(temp, fp);
		fputc('\n', fp);
	
}

int main()
{
	int startOrNot = 0;
	srand((unsigned int)(time(NULL)));

	/*
	**|=================================================================================|
	**|THIS PORTION OF THE CODE IS FOR READING WORD INFORMATION FROM EXTERNAL .txt FILE.|
	**|=================================================================================|
	*/

	//Redundancy process to prevent missing null character after string. Allows for checking of missing dictionary
	for (int i = 0; i != NUMBER_OF_OBJECTS; ++i)
	{
		memset(food[i], '\0', sizeof(food[i]));
		memset(countries[i], '\0', sizeof(countries[i]));
		memset(animals[i], '\0', sizeof(animals[i]));
		memset(sports[i], '\0', sizeof(sports[i]));
	}

	FILE *dict;
	dict = fopen("C:/TEMP/dictionary.txt", "r");

	//for every list category, current is 4
	for (int i = 0; i != NUMBER_OF_CATEGORIES; ++i)
	{
		char buffer[500];
		memset(buffer, '\0', sizeof(buffer));
		fgets(buffer, 500, dict);

		//string of category label
		char listName[20];
		memset(listName, '\0', sizeof(listName));

		//initialize iterators for use in while loop
		int x = 0;
		int listPos = 0;
		while (x != sizeof(buffer))
		{
			

			//detect category label & copy label name in listName char array
			if (buffer[x] == '<')
			{
				++x;
				while (buffer[x] != '>')
				{
					listName[x - 1] = buffer[x];
					++x;
					if (x > 50)
					{
						printf("Fatal error: Missing or unformatted dictionary label. Please check .txt file and try again.\n");
						return -1;
					}
				}
				++x;
				
			}
			//detect list object 
			else if (buffer[x] == '[')
			{
				if (listPos >= NUMBER_OF_OBJECTS)
				{
					printf("Error: More than %d objects are detected in %s category.", NUMBER_OF_OBJECTS, listName);
					printf("\nPlease check your .txt file and try again, or change NUMBER_OF_OBJECTS constant in program file\n\n");
					return -1;
				}
				++x;
				char word[50];
				memset(word, '\0', sizeof(word));
				int wordPos = 0;

				//ccpy list object in word char array
				while (buffer[x] != ']')
				{
					word[wordPos] = buffer[x];
					++wordPos;
					++x;
				}

				//copy word char array into main 2d array
				if (wordCompare(listName, "food") == 0)
				{
					strncpy(food[listPos], word, 50);
				}
				else if (wordCompare(listName, "countries") == 0)
				{
					strncpy(countries[listPos], word, 50);
				}
				else if (wordCompare(listName, "animals") == 0)
				{
					strncpy(animals[listPos], word, 50);
				}
				else if (wordCompare(listName, "sports") == 0)
				{
					strncpy(sports[listPos], word, 50);
				}
				else
				{
					printf("Oops! Something went wrong! Dictionary category labels are missing or not valid.\n\n");
					break;
				}
				++listPos;
			}
			//if whitespace character, increment x by one
			else
				x++;
		}
	}

	//Error checking: Checks if the string arrays are filled with meaningful information
	if (food[0][0] == '\0')
	{
		printf("Fatal error: Dictionary .txt file is missing or unreadable! Please check your file location and try again.\n\n");
		return -1;
	}

	/*
	*|===================================================================================|
	*|START OF GAME: THIS PORTION OF THE PROGRAM CONTAINS THE CODE FOR THE GAME: HANGMAN.|
	*|===================================================================================|
	*/

	FILE *scoreboard;
	scoreboard = fopen("C:/TEMP/scoreboard.txt", "w+");

	int mainChoice = 0;
	int wordGenre = 1;
	int newOrNot = 0;

	while (mainChoice != 5)
	{
		clearScreen();
		printf("THE HANGMAN GAME\n\n");
		printf("1. New Game\n");
		printf("2. Load game\n");
		printf("3. Game settings\n");
		printf("4. Scoreboard\n");
		printf("5. Exit\n");

		validateChoice(&mainChoice, 5);

		switch (mainChoice)
		{
		case 1:
		{
			char name[25];
			memset(name, '\0', 25);

			clearScreen();
			printf("Enter your name\n");
			scanf("%s", name);
			fseek(scoreboard, 0L, SEEK_END);

			if (startOrNot != 0)
			{
				fputc('\n', scoreboard);
			}
			++startOrNot;

			fputc('<', scoreboard);
			fputs(name, scoreboard);
			fputc('>', scoreboard);

			clearScreen();
			int choice1 = 0;
			printf("Word Genre\n");
			printf("1. Food\n");
			printf("2. Countries\n");
			printf("3. Animals\n");
			printf("4. Sports\n");
			printf("5. Back\n");
			validateChoice(&choice1, 5);

			char temp[3];
			memset(temp, '\0', 3);
			_itoa(choice1, temp, 10);
			fputc(' ', scoreboard);
			fputs(temp, scoreboard);

			int score = 0;
			int tries = 0;

			tries = RUN_GAME(name, choice1, &score, &tries);

			fputc(' ', scoreboard);
			_itoa(tries, temp, 10);
			fputs(temp, scoreboard);
			fputc(' ', scoreboard);
			_itoa(score, temp, 10);
			fputs(temp, scoreboard);

			break;
		}
		case 2:
		{
			struct player players[10];
			fseek(scoreboard, (long int)0, SEEK_SET);
			int amount;
			int choice;
			int tries;

			amount = readScores(scoreboard, players);
			clearScreen();
			for (int i = 0; i != amount; ++i)
			{
				printf("%d.\nName: %s\n", i+1, players[i].name);
				printf("Choice no. %d\n", players[i].choice);
				printf("No. of tries: %d\n", players[i].tries);
				printf("Score: %d\n\n", players[i].score);
			}
			validateChoice(&choice, amount);
		
			
			if (choice <= 0 || choice > 10)
				break;
			--choice;

			printf("");

			tries = RUN_GAME(players[choice].name, players[choice].choice, &(players[choice].score), &(players[choice].tries));
			
			amount++;
			printf("This works!\n");
			getchar();
			putScores(players, scoreboard, choice);

			break;
		}
		case 3:
		{
			int settingsChoice = 0;
			clearScreen();
			printf("1. Console color\n");
			printf("2. Clear scoreboard\n");
			printf("3. Back");
			validateChoice(&settingsChoice, 3);
			switch (settingsChoice)
			{
			//Word and background colour of console: GAVEEN
			case 1:
			{
				clearScreen();
				consoleColor();
				break;
			}
			//Clear .txt file of scoreboard
			case 2:
			{
				scoreboard = fopen("C:/TEMP/scoreboard.txt", "w+");
				break;
			}

			}
			break;
		}
		case 4:
		{
			clearScreen();
			struct player players[10];
			fseek(scoreboard, (long int)0, SEEK_SET);
			char temp;
			int amount;
			amount = readScores(scoreboard, players);
			printf("AMOUNT: %d\n\n", amount);
			for (int i = 0; i != amount; ++i)
			{

				printf("%d.\nName: %s\n", i + 1, players[i].name);
				printf("Choice no. %d\n", players[i].choice);
				printf("No. of tries: %d\n", players[i].tries);
				printf("Score: %d\n\n", players[i].score);
			}
			scanf(" %c", &temp);
			break;
		}
		case 5:
		{
			
			break;
		}
		
		default:
			printf("what did you do? This shouldn't happen\n\n");
		}
		
	}
	
	printf("\n\nGoodbye!\n\n");
	
	
	return 0;
}
