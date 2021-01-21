struct node //struct node i might or might not have copied this from PA3 and made minor adjustments...
{
    char *plate; //pointer to first char of a plate
    char *first; //pointer to the first letter of a name
    char *last; //pointer to the first letter of a last name
    struct node *left; // nodes on the left 
    struct node *right; //nodes on the right
};
typedef struct node *Node; 

int height(Node); //functions for the program like height here
int balanced(Node);  //balanced weill tell you if balanced
Node add(Node, char *, char *, char *); //add function just adds...boring
int search(Node, char *, char *, char *);  //searching is also boring
Node delte(Node, char *); //delte is where the magic happens... it made my program seg fault...go beserk with output
void LNR(Node); //boring but cool functions here
void NLR(Node); //fun stuff
void LRN(Node); //too short kinda did make me feel like im cheating
void treeFree(Node); //freeing the tree
