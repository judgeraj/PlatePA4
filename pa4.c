#include <stdio.h>  //this here is pronounced #include(sideways carrot) studio.h (sideways carrot)
#include <string.h> // i might not used some variables or libraries but i will include them
#include <stdlib.h> // for an unknown reason
#include "stuff.h"  // contains stuff


Node delte(Node root, char *plate) {

  if(root == NULL) //if the tree is empty well then shoot
    return root; //return the empty tree i guess...cannot delete thin air. Then I would just have thinner air
  
  if(strcmp(root->plate,plate) != 0) { //if the plate at the root isnt matching with the plate input
    if(strcmp(root->plate,plate) < 0) {  //recurse left subtree
      root->left = delte(root->left, plate); //i miss spelt delete and just "corrected" the typo in the opposite direction by making more typos...
      return (root); //THIS WAS WHY IT WAS DELETING BOTH... i didnt return here
    }
    else {
      root->right = delte(root->right, plate);  //this is recursing right subtree
      return (root); // return root
    }
  }

  if(root->left == NULL) { //if nothing is in the left subtree
    Node temp = root->right; //then i will make a temp var and make root right equal to that
    free(root->plate); //free the data
    free(root->first); //free the owners first name
    free(root->last); // free the last name
    free(root); //and free the root itself
    return (temp); //return temp node
  }

  Node LST = root->left; //left subtree is LST

  if(LST->right == NULL) { //if the lst has no larger value other than root of lst
    LST->right = root->right; //ummmm left sub tree's right adopts root->right
    free(root->plate); //well im too tired for more comments lolol
    free(root->first); //free this also
    free(root->last); //free last
    free(root); //free the rooT!!!!! BECAUE IM GROOOT!!!!!
    return (LST); //return LST
  } 

  Node prior = LST; //time to SHINE BOYS!
  Node curr = LST->right; //curr equals left subtrees right child
  
  while(curr->right != NULL) { //looping until the right is null
    prior = curr; curr = curr->right;
  }
  prior->right = curr->left; //making  prior right the curr left 
  curr->left = LST; //not currect left  is the LST
  curr->right = root->right; //curr right is now adopted the root right subtree
  free(root->plate); //free data
  free(root->first); //more data 
  free(root->last); //data buddy
  free (root); //free the root do not need any mnore
  return (curr); //return the curr 
      
}

Node add(Node root, char *plate, char *first, char *last) { //adding to tree not a wooden tree but an imaginary tree built inside of a computer's cloud
    
    Node newroot;

    if(root == NULL) { //sticking a branch in the empty 

        newroot = malloc(sizeof(struct node)); //malloc is my friend

        newroot->plate = malloc(strlen(plate)+1); //I am 90% sure i do need to add 1 but I did it anyways LOL
        newroot->first = malloc(strlen(first)+1); //possibly could just replace with malloc(32)
        newroot->last = malloc(strlen(last)+1); 

        strcpy(newroot->plate, plate); //and the plate just noticed i wrote the copy comments in reverse order... interms of grammer
        strcpy(newroot->first, first); //copying the name
        strcpy(newroot->last, last);  //copying data

        newroot->left = NULL; //left to NULL
        newroot->right = NULL; //setting the right to NULL

        return (newroot); //this will return
    }

    if(strcmp(root->plate,plate) < 0)  //add to left
        root->left = add(root->left, plate, first, last); //add the left
    else //adding to the right
        root->right = add(root->right, plate, first, last); //adding to the right
       
    return (root); //return the root
}

void treeFree(Node root) { 
  
  if(root == NULL) { //nully null null
    return;
  }
  treeFree(root->left); //free the left
  
  free(root->plate); //free the contents
  free(root->first); //contests
  free(root->last); //contents
  free(root->left); //contents
  
  treeFree(root->right); //free the right
  free(root->right); //free the right 
}

int balanced(Node root) { //this here is my balanced function...it will tell you the tree balance not if you are balanced...

    if(root == NULL) //basey casey
      return (1);  //if the tree is empty well is it balanced??
    
    int left = balanced(root->left); //well keep going left buddy
    int right = balanced(root->right); //and right buddy
    int rem; //you will be the remainder
 
    rem = right-left; //lets subtract both sides

    if(rem == -1) //if the remainder is -1 
      return (1); //then its balanced

    if((rem > 1) || (rem < -1)) //if it is greater than 2 or -2 its not
      return (-1);   //no no balance
    else
      return (1); //then it has to be balanced
}


int height(Node root) { //this determines the height...of the tree not you Nick

    if (root == NULL) //if the root is empty much like my wallet then it returns -1
        return (-1);  //returning the returning

    int left = height(root->left);   //here the function calls its friend...which is itself
    int right = height(root->right); //again considers itself a friend
                                     //blank space
    if (left > right)                //comparing the the height of the left and right sub trees
        return (left + 1);           //adding the one and only one to the left height
    else
        return (right + 1); // ^^***right height***
} //this is a curly brace

int search(Node root, char *plate, char *fn, char *ln) { //searching this tree will be a task in and of itself...get it?? (it calls itself)

    if (root == NULL) { //base case of base cases
        return 0;
    }

    if (strcmp(root->plate, plate) == 0) { //I DO AS STRCMP SAYS
        strcpy(fn,root->first); //copying into the arrys
        strcpy(ln,root->last); //here also
        return (1);                 //return 1; statement need more info? email me at r.judge2@students.clark.edu hours from 9 am to 5 pm mondays - fridays
    } 

    if (search(root->left, plate, fn, ln)) { //checking the left subtree
        return (1); //found
    }

    if (search(root->right, plate, fn, ln)) { //search the right
        return (1); //found
    }
    return (0); //returning 0 for not found
}


void LNR(Node root) { // left subtree, visits the node and then right subtree

    if(root == NULL) //base case for this also
      return; //returning

    LNR(root->left); //traversing the left subbie
    printf("Plate: %s \nFirst Name: %s \nLast Name: %s \n", root->plate, root->first, root->last); //printing the data at the node
    LNR(root->right); //traversing right

}

void NLR(Node root) { //visit the node first and then left sub tree and then right sub tree

    if(root == NULL) //base casey if NULL
      return; //returning
    
    printf("Plate: %s \nFirst Name: %s \nLast Name: %s \n", root->plate, root->first, root->last); //printing the data at the node
    NLR(root->left); //traversing left
    NLR(root->right); //traversing right

}

void LRN(Node root) { //LEFT RIGHT NODE traversal i think thats waht that stands for... well it will traverse the left sub tree and then right subtree lastly will visit the node

    if(root == NULL) //if NULL?!!?!?!?!??!?!?
      return; //base case of a null root
    
    LRN(root->left); //traversing lefty
    LRN(root->right); //traversing right
    printf("Plate: %s \nFirst Name: %s \nLast Name: %s \n", root->plate, root->first, root->last); //prinintg here well i tihnk that is obvisous ... too many typos

}
