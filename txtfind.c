#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 30
#define LINE 257

int similar (char *s, char *t);

int main() {
//    printf("Hello! Please enter a text input! \n");

    char line[LINE];
    char word[WORD];
    char* option=" ";
    int wordLength=0;

    fgets(line, LINE, stdin); // gets the first line of the input txt-
    // to get the word to look for, and the option of search (a/b)
    for(int i=0; i<LINE; i++){
 //       printf("word is %s \n", word);
        if(*(line+i)==' '){ //if we got to the option, which is separated by space. take it and stop reading
            //as there's nothing else to read
            option= line+i+1;
            break;
        }
        else{ //else just for simplicity
            wordLength++;
            *(word+i)= *(line+i); //we haven't reached the space yet, so it's still the word
        }
    }

    fgets(line, LINE, stdin); //gets the second line of the input txt, which is always empty

//    printf("option is %c \n", option);
    if(*(option)== 'a'){
        ////PrintAllLinesContaining(*word);
        fgets(line, LINE, stdin); //gets the third line
        while(!feof(stdin)){ // if it's not the end of file
            if(strstr(line, word)!= NULL){ // if this line contains the word we're looking for
                printf(" %s \n",line);
            }
            fgets(line, LINE, stdin);
        }
        if(strstr(line, word)!= NULL){ // if this line contains the word we're looking for
            printf(" %s \n",line);
        }
    }

    else{  // then option=='b': as they've written the input must be correct.
        //// PrintAllWordsCloseByLetterTo(*word);
 //       printf("tryna b \n");
 //       printf("word is %s \n", word);
        char currWord[WORD];
        char cha;
        int i=0;
        int simNum=0;
        while (scanf("%c",&cha)!= EOF){ //for every char until the end of the input file
            if(cha== ' ' || cha== '\n' || cha== '\t' || cha== '\0'){ //if it's the end of the word.
			//	printf("767676767676766767");
                //meaning WE GOT A WORD in our currWord char array.
				if(cha == '\n'){
					currWord[strlen(currWord)-1]='\0';
				}
                simNum= similar(word, currWord);
                if(simNum <= 1){ //if this word differs from the desired word only by one,
                    printf("%s \n",currWord); //print it.
                }
                simNum=0;
                i=0;
                memset(currWord, 0, WORD); //reset the currWord array
            }
            else{
			//	printf("@@@@currword is %s \n", currWord);
                currWord[i]= cha;
                i++;
            }
        }
        simNum= similar(word, currWord); //checking the last word
        if(simNum<=1){ //if this word differs from the desired word only by one,
            printf("%s",currWord); //print it.
        }
		
    }
    return 0;
}

int similar (char s[], char t[]) {
	//s: orgWord. t: newWord.
//	if(strlen(t)==4){
//		printf("w is %s \n",t);
//		for(int i=0; i< strlen(t); i++){
//			printf(" %c \n",t[i]);
//		}
//	}
//	printf(" ORG sent is %s \n", s);
//	printf(" NEW sent is %s \n", t);
//	printf(" ORG LEN sent is %d \n", strlen(s));
//	printf(" NEW LEN sent is %d \n", strlen(t));
    int countDiff = 0;
    if (strcmp(s, t) == 0) { //if the words are equal
//		printf("w is %s",t);
        return 0;
    }
    if (strlen(s) == strlen(t) || strlen(s) == strlen(t) - 1 || strlen(s) - 1 == strlen(t)){
        int j = -1;
        for (int i = 0; i < strlen(s); i++) {
            j++;
            if (s[i] != t[j]) {
                countDiff++;
                i--; //stay at the same point in the T word,
//				to the next comparing to S (original) word
            }
            if (countDiff > 1) {
//				printf("no is %s \n", t);
                return 2;
            }
        }
        return countDiff;
    }
    else {
        return 2; //saying it's not possible they differ in 1/0 letters, must be more.
    }
}
