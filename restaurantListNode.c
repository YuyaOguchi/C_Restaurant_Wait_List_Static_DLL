//  Yuya Oguchi
//  COEN11L     Lab6
//  10/31/2014
//  restaurantwaitlist Node 
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int number;
    char name[20];
    struct node *next;
    struct node *previous;
}Node;

Node *head[4] = {NULL,NULL,NULL,NULL};
Node *tail[4] = {NULL,NULL,NULL,NULL};

void add(struct node node){
    Node *p;
    if ((p = (Node*)malloc (sizeof (Node))) == (Node*)NULL){
		printf ("Node could not be allocated\n");
		return;
	}

    printf("Enter name\n");
	scanf("%s", p->name);

    printf("Enter the number\n");
    scanf("%d",&p->number);
    int y;
    //-------------------list1------------------
    if(p->number <= 2){//only if number is 1 or 2
        y = 0;
    }else if (p->number ==3 || p->number == 4){
        y = 1;
    }else if (p->number ==5 || p->number == 6){
        y = 2;
    }else if (p->number >= 7){
        y = 3;
    }
    if (head[y] == NULL){//at beginning
        head[y] = p;
	}else{
        Node *temp;
        int z;
        for (z = 0; z <= 3;z++){
		temp = head[z];
		while (temp != NULL){
			if (strcmp(temp->name, p->name) == 0){//duplicate
				printf("Duplicate, try again\n");
				free(p);
				return;
			}
			else{//no duplicate
				temp = temp->next;
			}
        }
		}
	}//end else check duplicate

    if (tail[y] != NULL){
		tail[y]->next = p;
	}
	tail[y] = p;
    tail[y]->next=NULL;
    return;

}


void stats(struct node node){
    int x;
    for(x=0; x <=3 ; x++){

    Node *temp1 = head[x];

    //print list 1-4 --------------------
    printf("List%d contains:\n",x + 1);
    while (temp1 != NULL){
        printf("Name: %s\tNumber: %d\n", temp1->name, temp1->number);
		temp1 = temp1->next;
    }
    printf("\n");

    }
    return;
}

void delete(struct node node){//done
    int open;
    int k;
    printf("What is the size of table?\n");
    scanf("%d", &open);

    if(open <= 2){
        k = 0;
    } else if (open == 3 || open == 4){
        k = 1;
    }else if (open == 5 || open == 6){
        k = 2;
    }else if (open >=7){
        k = 3;
    }


    while(k >= 0){

    if (head[k] != NULL){
        Node *temp = head[k];//make temp linklist that is at head
        if (head[k]->number <= open)//checking for head
        {
            head[k] = temp->next;
            free(temp);
            return;
        }
        Node *change;
        Node *temp2;
        change=temp;
        //temp=change->next;
        while (temp->next != NULL){
            if (temp->number <= open)//if num is less than open
            {
                temp2 = change->next;
                change->next = change->next->next;
                free(temp2);
                printf("Value taken out\n");
                return;
            }else if (temp->number > open)
            {
                change = temp;
                temp = temp->next;
            }
        }//close while loop

        if(temp->number <= open){
            printf("Last value taken out\n");
            free(temp);
            tail[k] = change;
            tail[k]->next = NULL;
            return;
        }
    }
        k -= 1;
    if (head[k] == NULL){
        k -= 1;
    }
}
    return;
}//close void


int main()
{
    int command;
    int quit = 0;
    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add waitlist\n");
    printf("Type 2 to eliminate an entry that fits the table\n");
    printf("Type 3 to show all Waitlist\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n");

    struct node Node;
    while (quit == 0){

        scanf("%d",&command);

        if (command == 1){
            add(Node);

        }else if (command == 2){
            delete(Node);

        }else if (command == 3){
            stats(Node);

        }else if (command == 4){
            quit = 1;

        }
        printf("What would you like to do?\n");

    }//end while loop

    return 0;
}
