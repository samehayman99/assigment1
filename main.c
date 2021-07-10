#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct student
{
    int ID ;
    int day_of_birth ;
    int month_of_birth ;
    int year_of_birth ;
    int score;
    char student_name[MAX] ;
};



struct node
{
    struct student data;
    struct node * next;
};

void insert_at_beginning (struct node ** head,struct node ** tail )
{
    char c;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter your ID ");
    scanf("%d",&new_node->data.ID );
    printf("\nEnter your day_of_birth  ");
    scanf("%d",&new_node->data.day_of_birth );
    printf("\nEnter your month_of_birth ");
    scanf(" %d",&new_node->data.month_of_birth);
    printf("\nEnter your year_of_birth ");
    scanf(" %d",&new_node->data.year_of_birth );
    printf("\nEnter your score ");
    scanf(" %d",&new_node->data.score );
    printf("\nEnter your student_name ");
    while((c = getchar()) != '\n' && c != EOF);
    fgets(new_node->data.student_name, sizeof(new_node->data.student_name), stdin);
    new_node->next = (*head);
    (*head)    = new_node;
    if ((*head)->next == NULL)
       (*tail)=(*head);
}

void insert_at_ending (struct node ** tail,struct node ** head)
{
    char c;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter your ID ");
    scanf("%d",&new_node->data.ID );
    printf("\nEnter your day_of_birth  ");
    scanf("%d",&new_node->data.day_of_birth );
    printf("\nEnter your month_of_birth ");
    scanf(" %d",&new_node->data.month_of_birth);
    printf("\nEnter your year_of_birth ");
    scanf(" %d",&new_node->data.year_of_birth );
    printf("\nEnter your score ");
    scanf(" %d",&new_node->data.score );
    printf("\nEnter your student_name ");
    while((c = getchar()) != '\n' && c != EOF);
    fgets(new_node->data.student_name, sizeof(new_node->data.student_name), stdin);
    new_node->next = NULL;
     if (((*head) == NULL )&&((*tail) == NULL ))
     {
         (*tail)=new_node;
         (*head)=(*tail);
     }
    else
    {
        (*tail)->next =new_node;
        (*tail)    = new_node;
    }
 }

void insert_at_Middle(struct node ** head,struct node ** tail)
{

    int POS,x;
    struct node * c=(*head);
    for(x=0;c!=NULL;x++)
        c=c->next;
    if (x==0)
    {
            printf("list is empty\n");

    }
    else
    {

            printf("you have %d students\nWhere do you want to add your data ?  ",x);
            scanf("%d",&POS);

            if((POS>x)||(POS<=0))
               {
                   printf("Wrong Position \n");
                   return;

               }

            else
                {       struct node * Prev=NULL;
                        struct node * curr=(*head);
                        for(x=1;x <= POS ;x++)
                            {

                                if (x == POS)
                                    {
                                        printf("insert your data\n");
                                        char c;
                                        struct node* new_node = (struct node*) malloc(sizeof(struct node));
                                        printf("\nEnter your ID ");
                                        scanf("%d",&new_node->data.ID );
                                        printf("\nEnter your day_of_birth  ");
                                        scanf("%d",&new_node->data.day_of_birth );
                                        printf("\nEnter your month_of_birth ");
                                        scanf(" %d",&new_node->data.month_of_birth);
                                        printf("\nEnter your year_of_birth ");
                                        scanf(" %d",&new_node->data.year_of_birth );
                                        printf("\nEnter your score ");
                                        scanf(" %d",&new_node->data.score );
                                        printf("\nEnter your student_name ");
                                        while((c = getchar()) != '\n' && c != EOF);
                                        fgets(new_node->data.student_name, sizeof(new_node->data.student_name), stdin);
                                        new_node->next = NULL;

                                        Prev ->next = new_node;
                                        Prev = new_node;
                                        Prev ->next = curr;


                                    }

                                Prev = curr;
                                curr = curr->next;


                            }
                }


    }



}


void traverseList(struct node ** head)
{
    struct node *temp;

    // Return if list is empty
    if((*head) == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = (*head);
    while(temp != NULL)
    {

    printf("\n your ID %d",temp->data.ID);

    printf("\n your day_of_birth  %d",temp->data.day_of_birth);

    printf("\n your month_of_birth %d",temp->data.month_of_birth);

    printf("\n your year_of_birth %d",temp->data.year_of_birth);

    printf("\n your score %d",temp->data.score);

    printf("\n your student_name %s",temp->data.student_name);
        temp = temp->next;                 // Move to next node
    }
}


void link_list_n_students(int N , struct node ** head,struct node ** tail )
{
    if (N==0){return;}
    else{
            int i;
        for (i=1 ;i<=N;i++)
            {

            struct node* new_node = (struct node*) malloc(sizeof(struct node));

            new_node->data.ID =0;

            new_node->data.day_of_birth =0;

            new_node->data.month_of_birth =0;

            new_node->data.year_of_birth =0;

            new_node->data.score =0;

            //new_node->data.student_name;

            new_node->next = (*head);
            (*head)    = new_node;
            if(i==1) (*tail)    = new_node;
            }
        }

}

void Dynamic_array_n_students( int N , struct student ** p)
{
    int i =2;
    (*p) = calloc(N,sizeof(struct student));
    (*p)[i].ID=10;
    (*p)[i].day_of_birth=12;
    (*p)[i].month_of_birth=8;
    (*p)[i].year_of_birth=1999;
    (*p)[i].score=1300;

}

void display(int N , struct student ** p)
{
    int i;
    for ( i = 0; i < N; i++ )
   	 {
   	     printf("ID of No. %d : %d\n", i+1, (*p)[i].ID);
         printf("DAY of Birth of No. %d : %d\n", i+1, (*p)[i].day_of_birth);
         printf("Month of Birth of No. %d : %d\n", i+1, (*p)[i].month_of_birth);
         printf("Year of Birth of No. %d : %d\n", i+1, (*p)[i].year_of_birth);
         printf("SCORE of No. %d : %d\n", i+1, (*p)[i].score);
         printf("your student_name of No. %d %s\n", i+1,(*p)[i].student_name);
     }
}


void dynamic_array_insert(int POS,int N, struct student ** p)
{
    POS--;
    if(POS == 0)
    {
        (*p) = realloc((*p), N);
        int i;
        for(i=N-1;(i<N)&&(i>=0);i--)
        {
            (*p)[i] = (*p)[i-1];

        }
        char c;
        printf("\nEnter your ID ");
        scanf("%d",&(*p)[POS].ID);
        printf("\nEnter your day_of_birth  ");
        scanf("%d",&(*p)[POS].day_of_birth);
        printf("\nEnter your month_of_birth  ");
        scanf("%d",&(*p)[POS].month_of_birth);
        printf("\nEnter your year_of_birth  ");
        scanf("%d",&(*p)[POS].year_of_birth);
        printf("\nEnter your score  ");
        scanf("%d",&(*p)[POS].score);
        printf("\nEnter your student_name ");
        while((c = getchar()) != '\n' && c != EOF);
        fgets((*p)[POS].student_name , sizeof((*p)[POS].student_name ), stdin);


    }

    else if(POS==N-1)
    {
        (*p) = realloc((*p), N);
        char c;
        printf("\nEnter your ID ");
        scanf("%d",&(*p)[POS].ID);
        printf("\nEnter your day_of_birth  ");
        scanf("%d",&(*p)[POS].day_of_birth);
        printf("\nEnter your month_of_birth  ");
        scanf("%d",&(*p)[POS].month_of_birth);
        printf("\nEnter your year_of_birth  ");
        scanf("%d",&(*p)[POS].year_of_birth);
        printf("\nEnter your score  ");
        scanf("%d",&(*p)[POS].score);
        printf("\nEnter your student_name ");
        while((c = getchar()) != '\n' && c != EOF);
        fgets((*p)[POS].student_name , sizeof((*p)[POS].student_name ), stdin);

    }
    else if((POS>0) && (POS <(N-1) ) )
    {
        (*p) = realloc((*p), N);
        int i;
        for(i=N-1;(i<N)&&(i>=POS);i--)
        {
            (*p)[i] = (*p)[i-1];

        }
        char c;
        printf("\nEnter your ID ");
        scanf("%d",&(*p)[POS].ID);
        printf("\nEnter your day_of_birth  ");
        scanf("%d",&(*p)[POS].day_of_birth);
        printf("\nEnter your month_of_birth  ");
        scanf("%d",&(*p)[POS].month_of_birth);
        printf("\nEnter your year_of_birth  ");
        scanf("%d",&(*p)[POS].year_of_birth);
        printf("\nEnter your score  ");
        scanf("%d",&(*p)[POS].score);
        printf("\nEnter your student_name ");
        while((c = getchar()) != '\n' && c != EOF);
        fgets((*p)[POS].student_name , sizeof((*p)[POS].student_name ), stdin);

    }



}

int main()
{

printf("welcome in emmbeded assignment\n");

int select=0;
printf("Press 1 to linked list program\nPress 2 to Dynamic array program\n");
scanf("%d", &select);

if(select==1)
    {
                    int x= 1,N;
                    struct node * head=NULL;
                    struct node * tail=NULL;
                    printf("Enter Number of students\n");
                    scanf("%d", &N);
                    link_list_n_students(N,&head,&tail);
                    do {

                            printf("1.Insert a new student in the beginning\n2.Insert a new student at the end\n3.Insert a new student in the middle\n");
                            printf("press Number of your choose\n");
                            int i;
                            scanf("%d",&i);



                            switch (i)
                             {
                                    case 1:
                                        printf("insert your data");
                                        insert_at_beginning(&head,&tail);
                                        break;

                                    case 2:
                                        printf("insert your data");
                                        insert_at_ending(&tail,&head);
                                        break;

                                    case 3:
                                        insert_at_Middle(&head,&tail);
                                        break;
                                    default:
                                    break;


                     }
                        printf("Do you want to insert more? \n Yes then press any Number \n No then press 0 ");
                        scanf("%d",&x);
                    }while (x!=0);
                    traverseList(&head);


    }

else if (select == 2)
    {
                    int x= 1,N,POS=0;
                    struct student * p;
                    printf("Enter Number of students\n");
                    scanf("%d", &N);
                    Dynamic_array_n_students( N , &p);
                    do {

                            printf("1.Insert a new student in the beginning\n2.Insert a new student at the end\n3.Insert a new student in the middle\n");
                            printf("press Number of your choose\n");
                            int i;
                            scanf("%d",&i);



                            switch (i)
                             {
                                    case 1:
                                        N++;
                                        POS=1;
                                        printf("insert your data");
                                        dynamic_array_insert(POS,N, &p);
                                        break;

                                    case 2:
                                        N++;
                                        POS=N;
                                        printf("insert your data");
                                        dynamic_array_insert(POS,N, &p);
                                        break;

                                    case 3:
                                        N++;
                                        printf("you have %d students\nWhere do you want to add your data ?  ",N-1);
                                        scanf("%d",&POS);
                                        printf("insert your data");
                                        dynamic_array_insert(POS,N, &p);
                                        break;
                                    default:
                                    break;


                     }
                        printf("Do you want to insert more? \n Yes then press any Number \n No then press 0 ");
                        scanf("%d",&x);
                    }while (x!=0);
                    display(N,&p);




    }




    return 0;
}
