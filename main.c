/*
Rajpreet Judge
CSE 215
Nick Macias
02/26/2020
PROGRAMMING ASSIGNMENT 4

Nick this is where you might hate me because i did my program description in morse code....(time to start cracking the code ... quite literally)
- .... .. ... / .--. .-. --- --. .-. .- -- / .... . .-. . / .. ... / -.-. .- .-.. .-.. . -.. / .--. .- ..... / .- -. -.. / .. - / .-- .. .-.. .-.. / -.-. --- -. ... .. ... - / --- ..-. / .- / - .-. . . / --- .-. / -... ... - .-.-.- / -.-- --- ..- / .-- .. .-.. .-.. / -... . / .- -... .-.. . / - --- / ... . .- .-. -.-. .... / .- -. -.. / .--. .-. .. -. - / --- ..- - / --- ..-. / - .... . / - .-. . . / --- ..-. / .--. . --- .--. .-.. . / .-- .... --- / .... .- ...- . / .- / .-.. .. -.-. . -. ... . / .--. .-.. .- - . / ... - --- .-. . -.. / .. -. / - .... . / -.. .- - .- -... .- ... . / - .... .- - / -.-- --- ..- / .... .- ...- . / - .... . / .--. .-. --- --. .-. .- -- / .-. . .- -.. / ..-. .-. --- -- .-.-.- / -.-- --- ..- / -.-. .- -. / ..- ... . / - .... .. ... / .--. .-. --- --. .-. .- -- / - --- / .-- .-. .. - . / - .. -.-. -.- . - ... / --- .-. / - .-. .- -.-. -.- / .--. . --- .--. .-.. . .-.-.- / .. / ..- .--. .-.. --- .- -.. / - .... .. ... / .--. .-. --- --. .-. .- -- / .. -. / ..-. ..- .-.. .-.. / ..-. .- .. - .... / .. - / .-- .. .-.. .-.. / -. --- - / -... . / ..- ... . -.. / ..-. --- .-. / .- -. -.-- - .... .. -. --. / .. .-.. .-.. . --. .- .-.. / --- .-. / .-- . .. .-. -.. / .- -. -.. / .--. ..- - / - .-. ..- ... - / .. -. / - .... . / ..- ... . .-. / - .... . -.-- / .-- .. .-.. .-.. / -... . / . - .... .. -.-. .- .-.. / .-- .. - .... / - .... . / ..- ... . .-.-.-
*/

#include<stdio.h> //this is pronounced include studio not standard i o
#include<string.h> //this ties all the functions together with a string
#include<stdlib.h> //this will look up all the words typed in this program in the standard library
#include"stuff.h" //this just includes stuff literally just stuff



int main(int argc, char **argv) // I had a main written but i accidently deleted it so this is my rewritten main but it contains less funny comments
{
    if (argc != 2) { //checking for 2 argies 
        printf("ERROR: program not ran with too many or too few arguments"); //clearly the user didnt get the program documentation when they downloaded
        return (0); //returning the 0 because why not
    }

    printf("DATABASE FILE NAME IS: %s\n", argv[1]); //showing the user the data base they chose... as if they might of forgetten the data base they just typed 5 seconds ago

    Node root = NULL; //making my root null

    FILE *fp = fopen(argv[1], "r"); //opening the file and assigning it to the pointer fp

    if(fp == NULL) { //checking for a valid database file
      printf("ERROR: DATABASE FILE NOT VALID\n"); //i mean do i need to comment this?
      return (0); // again a zero is returndd
    }

    char temp[256]; //"i tried so hard and got so far" "I had to fall to lose it all" just random lyrics idk why

    while(fgets(temp,256,fp) != NULL) { //reading the file in a whilely loop
        char plate[32], first[32], last[32]; //creating 3 temp arrays to pass to add function
        sscanf(temp,"%s %s %s", plate, first, last); //sscanfing the input and assigning to the arrays
        root = add(root, plate, first, last); //calling the add fuuction and assigning the return value to root
    }
    fclose(fp); //closing this file because the 1 byte that is getting leaked will nuke your computer LOL
    printf("FILE CLOSED\n"); //ill let you know i closed it
  
    char input[120], template[120]; //temp array's i might have used them 
 
    printf("ENTER COMMAND OR PLATE: "); //i think you want to know what to enter

    while(fgets(input,120,stdin) != NULL) { //this is finally where the actual program starts well it started back there but the user doesnt care about that
      char fn[50], ln[50]; //temp arrays that i ass to functions

      input[strlen(input) - 1] = '\0'; //removing the new line

      if(strcmp(input,"*DUMP") == 0) { // the user entered *DUMP

        printf("The height of tree is: %d\n", height(root)); //finding the height of the tree also if it is balanced
        int rem = balanced(root); //calling balnaced
   
        if(rem == 1) //checking the return value
          printf("tree is balanced?: YES\n"); //i mean come on just read the print statement 
        else
          printf("Tree is balanced?: NO\n"); //else read this one

        printf("\n\nLNR TRAVS:\n"); //this is where the printing happens "it must be a dream"
        LNR(root); //actually calling it here
        printf("\n\nEnd of LNR\n"); //telling you it ended

        printf("\n\nNLR TRAVS:\n"); //this is the NLR traversal
        NLR(root); //well its actually right here that was just a print statement
        printf("\n\nEnd of NLR\n"); //just like this one

        printf("\n\nLRN TRAVS:\n"); //this is the print statement
        LRN(root); //same here
        printf("\n\nEnd of LRN\n"); //haha this was the print statement and the one about it is the call to LRN HEHEHEH

      } else if(sscanf(input,"*DELETE %s", template) == 1) { //checking to see if the user has entered *DELETE with a number plate
 
           if(search(root,template, fn, ln) == 1)  //checking to see if the plate even exists because the user cannot be trusted
             root = delte(root, template); //the user is trusted here because no other way to get in here
           else
             printf("PLATE NOT FOUND\n"); //well they lied 
             
      } else if(search(root, input, fn, ln) == 1) { //well we will have to search because they just entered a plate

          printf("First Name: %s\nLast Name: %s\n",fn, ln); //printingt the data if the plate exists

        }
        else
          printf("NOT FOUND\n"); //well last time i trust the user....

      printf("ENTER COMMAND OR PLATE: "); //lets see what this guy wants
    } 
  treeFree(root); //its time to call the landscaper for these tree nodes
  free(root); //and have the landscaper free the root here
  printf("DONE FREEING\n"); //he left his business card 
}
