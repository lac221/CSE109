/*
    CSE 109: Fall 2018
    Lydia Cornwell
    LAC221
    <Program Description>
    Program #1
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void reverseWord(char* line, size_t length);
void toggle(char* line, size_t length);
void rotate(char* line, size_t length);
size_t removeDigits(char* line, size_t length);


int main(int argc, char** argv)
{
	int rcount = 0;
	int ocount = 0;
	int tcount = 0;
	int ncount = 0;

	for(int i = 1; i < argc; i++)
	{
		if(strcmp(argv[i], "-r") == 0)
		{
			rcount = 1;
		}
		else if(strcmp(argv[i], "-o") == 0)
		{
			ocount = 1;
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			tcount  = 1;
		}
		else if(strcmp(argv[i], "-n") == 0)
		{
			ncount  = 1;
		}
		else
		{
			fprintf(stdout, "Please enter a valid argument");
			return 1;
		}
	}

	char* line = NULL;
	size_t length = 0;
	size_t read;

	while((read = getline(&line, &length, stdin)) != -1)
	{
		if(rcount)
		{
			reverseWord(line, length);
		}

		if(ocount)
		{
			rotate(line, length);
		}
		if(tcount)
		{
			toggle(line, length);
		}
		if(ncount)
		{
			removeDigits(line, length);
		}
		
		for(int i = 0; i < length; i++)
		{
                	printf("%c", line[i]);
        	}
	}

	free(line);

	return 0;
}

void reverseWord(char* line, size_t length)
{
	int start = 0;
	int stop = 0;
	char temp;

	for(int i = 0; i <=  length; i++)
	{
		if(isspace(line[i]) || (i == length))
		{
			stop = i - 1;
			while(start < stop)
			{
				temp = line[start];
				line[start] = line[stop];
				line[stop] = temp;
				start++;
				stop--;
			}
			start = i + 1;
		}	
	}
}

void toggle(char* line, size_t length)
{
	for(int i = 0; i < length; i++)
	{
		if(isupper(line[i]))
		{
			line[i] = tolower(line[i]);
		}
		else
		{
			line[i] = toupper(line[i]);
		}
	}
}

void rotate(char* line, size_t length)
{
	char temp1;
	char temp2;
	size_t initial = 0;
	size_t current = 0;
	size_t i = 0;
	
	while(isspace(line[i]))
	{
		i++;
	}

	initial = i;
	temp1 = line[initial];

	for(size_t j = i; j<length; j++)
	{
		if(isspace(line[j]) && line[j+1] &&  !isspace(line[j+1]))
		{
			current = j + 1;
			temp2 = line[current];
			line[current] = temp1;
			temp1 = temp2;
		}
	}
	line[initial] = temp2;
			
}

size_t removeDigits(char* line, size_t length)
{
	int j;
	for(int i = 0; line[i] != '\0'; i++)
	{
		while(isdigit(line[i])|| line[i] == '\0')
		{
			for(j = i; line[j] != '\0'; ++j)
			{
				line[j] = line[j+1];
			}
		}
		line[j-1] = '\0';
	}
	
	return strlen(line);
}
