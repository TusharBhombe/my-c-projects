#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    int quantity ;
    float price ;
    char foodname [50];
    struct node *next;
    struct node *prv ;
};

struct node *heada = NULL;
struct node *headc = NULL;
struct node *enda = NULL;
struct node *endc = NULL;
struct node *newnode = NULL;
struct node *head_s;

void adminmenu()
{
    printf("\t\t\t\t\t\t\t\t 1.view total sales \n");
    printf("\t\t\t\t\t\t\t\t 2.Add new atoms in the order menu \n");
    printf("\t\t\t\t\t\t\t\t 3.delete atoms in the order menu \n");
    printf("\t\t\t\t\t\t\t\t 4.display the order menu \n");
    printf("\t\t\t\t\t\t\t\t 5.Back to main menu \n");
    printf("\t\t\t\t\t\t\t\t   Enter your choice:--> ");
}


void customermenu()
{
    printf("\t\t\t\t\t\t\t\t 1.place your order \n");
    printf("\t\t\t\t\t\t\t\t 2.view your placed order \n");
    printf("\t\t\t\t\t\t\t\t 3.delete an atoms from orders \n");
    printf("\t\t\t\t\t\t\t\t 4.display the final  bill \n");
    printf("\t\t\t\t\t\t\t\t 5.Back to main menu \n");
    printf("\t\t\t\t\t\t\t\t   Enter your choice :--> ");
}


struct node *creatadmin(struct node *head,int data,float price,char foodname[25])
{
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->price = price ;
    strcpy(newnode->foodname,foodname);
    newnode->quantity =0 ;
    newnode->next = NULL;
    newnode->prv = NULL;

    struct node * temp  = head ;

    if (temp == NULL)
    {
        heada = enda = newnode ;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode ;
        newnode->prv = enda ;
        enda = newnode;

        
    }
    
    return heada ;

}


struct node *creatcustamor(struct node *head,int data,int quantity)
{
    newnode = (struct node *)malloc(sizeof(struct node));

    struct node *temp1 = heada;
    int flag = 0;
    while (temp1 != NULL)
    {
        if (temp1->data == data)
        {
            flag = 1;
            break ;
        }
        
        temp1 = temp1->next;
    }

    
    if (flag = 1){
        newnode->data = data;
        newnode->price = quantity * (temp1->price);
        newnode->quantity = quantity ;
        strcpy(newnode->foodname,temp1->foodname);
        newnode->next = NULL;
        newnode->prv = NULL;
    
        struct node * temp  = head ;

        if (temp == NULL)
        {
            headc = endc = newnode ;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode ;
            newnode->prv = endc;
            endc = newnode;

            
        }

    }
    else
    {
        printf(" This atom is not present in menu ");
    }
    


    
    return headc ;

}

struct node *dispalylist(struct node *head)
{
    struct node *temp = head ;

    if (temp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t list is empty \n\n");
    }


    else
    {
        printf("\n");

        while (temp != NULL)
        {
            if (temp->quantity == 0)
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n",temp->data,temp->foodname,temp->price);
            }
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n",temp->data,temp->foodname,temp->quantity,temp->price);

            }
            temp = temp->next ;
            
            
        }
        printf("\n");
    }

}

struct node *totalsale(int data , int quantity)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    int flag = 0 ;
    struct node *temp1 = heada ;
    while (temp1->data != data)
    {
        temp1 = temp1->next ;
    }
    newnode->data = data;
    newnode->price = quantity * (temp1->price);
    newnode->quantity =quantity ;
    strcpy(newnode->foodname,temp1->foodname);
    newnode->next = NULL;
    newnode->prv = NULL;
    
    struct node *temp = head_s ;
    if (temp == NULL)
    {
        head_s = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->data == data)
            {
                flag = 1 ;
               
                break ;
            }
            temp = temp->next ;

            
        }
        if (flag == 1)
        {
            temp->quantity += newnode->quantity ;
            temp->price += newnode->price ;
        }
        else
        {
            temp->next = newnode ;
        }
            
        
    }
    return head_s ;

}
void calculatesale()
{
    struct node *temp = headc ;
    while (temp != NULL)
    {
        head_s = totalsale(temp->data,temp->quantity);
        temp = temp->next ;
    }
    
}

struct node *delete(int data, struct node *head, struct node *tail)
{
    if (head == NULL)
    {
        printf("\t\t\t\t list is empty \n");
    }
    else
    {
        struct node *temp ;
        if (data == head->data)
        {
            temp = head ;
            head = head->next;
            if (head != NULL)
            {
                head->prv = NULL;
            }
            
            free(temp);
        }
        
        else if (data == tail->data)
        {
            temp = tail;
            tail = tail->prv;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp = head ;
            while (data != temp->data)
            {
                temp = temp->next ;
                
            }
            (temp->prv)->next = temp->next;
            (temp->next)->prv = temp->prv ;
            free(temp);
            
        }
        
        
        
    }
    return head;
    
    
    
}
int deleteadmin()
{
    int num ;
    printf("\n\t\t\t\t\t enter the serial no of atom which you wnat to delete:-->");
    scanf("%d",&num);

    struct node *temp = heada;
    while (temp != NULL)
    {
        if(temp->data == num)
        {
            heada = delete(num,heada,enda);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
    

}
int deletecustomar()
{
    int choice ;
    printf("\n\t\t\t\t enter the serial no of atom which you wnat to delete :");
    scanf("%d",&choice);

    struct node *temp = headc;
    while (temp != NULL)
    {
        if(temp->data == choice)
        {
            headc = delete(choice,headc,endc);
            return 1;
        }
        temp = temp->next;
    }
    return 0;
    

}

void displaybill()
{
    dispalylist(headc);
    struct node *temp = headc ;
    float total_price = 0;
    while (temp != NULL)
    {
        total_price += temp->price ;
        temp = temp->next;
    }
    printf("\t\t\t\t\t\t your total bill is %0.2f\n",total_price);

}
struct node *deletelist(struct node *head)
{
    if (head == NULL)
    {
        return NULL ;
    }
    else
    {
        struct node *temp  = head;
        
        while (temp->next != NULL)
        {
            temp = temp->next;
            free(temp->prv);
            
            
        }
        free(temp);

        head = NULL;
        
    }
    return head;
    
    
}
void mainmenu()
{                    
    printf("\n                                     ************************************************\n");
    printf("                                                 WELCOME TO THE RESTURANT\n");                    
    printf("                                     *************************************************\n\n\n");
    printf("\t\t\t\t\t\t 1. ADMIN SECTION :--> \n");
    printf("\t\t\t\t\t\t 2. CUSTOMER SECTION :--> \n");
    printf("\t\t\t\t\t\t 3. EXIT :-->\n\n");
    printf("\t\t\t\t\t\t  Enter your choice :-->  ");

}

int admin()
{                    
    printf("\t\t\t\t\t\t  -------------------------------------\n");
    printf("\t\t\t\t\t\t\t        ADMIN SECTION\n");                     
    printf("\t\t\t\t\t\t  --------------------------------------\n");
    while (1)
    {
        adminmenu();

        int opt;
        scanf("%d", &opt);
        if (opt == 5)
        {
            return main();
            break;
        }
        
        

        switch (opt)
        {
            case 1:
                dispalylist(head_s);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t enter the serial no of food atom :-->");
                int num ;
                int flag =0 ;
                float price;
                char name[50];
                scanf("%d", &num);
                struct node *temp = heada;
                while (temp != NULL)
                {
                    if(temp->data == num);
                    {
                        printf("\t\t\t\t\t\t\t food atom eith given serioal number is alredy exis in list!!!\n");
                        flag = 1 ;
                        break;
                    }
                    temp = temp->next ;
                }
                if (flag == 1)
                {
                    break;
                }
                else
                {
                    printf("\t\t\t\t\t\t Enter the name of the food atom :     ");
                    scanf("%s", name);
                    printf("\t\t\t\t\t\tEnter the price of the food atom :     ");
                    scanf("%f", &price);
                    heada = creatadmin(heada,num,price,name);
                    printf("\n\t\t\t\t\t\t your food atom is added sucssfullay  \n");

                }
                
                
                break;
            case 3:
                if (deleteadmin())
                {
                    printf("\n\t\t\t\t\t\t### updated list of order menu is## \n");
                    dispalylist(heada);
                }
                else
                {
                    printf("\n\t\t\t\t\t you enter atom is not present in list(wrong input!)     \n\n");
                }
                break;
                
                
                    
                
            case 4:
                printf("\n\t\t\t\t\t\t ### Ordered menu ### \n");
                dispalylist(heada);
                break ;

            

                    
                
            default:
                printf("\n\t\t\t\t\t\t Wrong input! enter a valid input    \n ");
                break;
        }
        
        
    }
    
}

int customer()
{
    int flag = 0;
    char ch ;
    printf("\t\t\t\t\t\t  -------------------------------------\n");
    printf("\t\t\t\t\t\t\t        CUSTOMER SECTION\n");                     
    printf("\t\t\t\t\t\t  --------------------------------------\n");
    while (1)
    {

        customermenu();

        int opt;
        scanf("%d", &opt);
        if (opt == 5)
        {
            return main();
            break;
            
        }
       
        
        
        
        

            
        switch (opt)
        {

            case 1:
                dispalylist(heada);
                printf("\n\t\t\t\t\t\t enter the corrosponding serial no of food atom :-  ");
                int data, q ;
                scanf("%d", &data);
                printf("\t\t\t\t\t\t enter the Quantity of food atom :-  ");
                scanf("%d",&q);
                headc = creatcustamor(headc,data,q);
                printf("\t\t\t\t\t\t your order is placed successfully  \n");
                break;
            case 2:
                printf("\n\t\t\t\t\t\t ##list of ordered food atoms ##\n");
                dispalylist(headc);
                break;
            case 3:
                if (deletecustomar())
                {
                    printf("\n\t\t\t\t\t\t ##updated list of order menu is ##\n");
                    dispalylist(headc);
                }
                else
                {
                    printf("\t\t\t\t\t\t you enter atom is not present in list(wrong input!)     \n");
                }
                break;
                    
                    
                        
                    
            case 4:
                calculatesale();
                printf("\n\t\t\t\t\t\t ###Final Bill ###\n ");
                displaybill();
                headc = deletelist(headc);
                printf("\n\t\t\t\t\t\t Press any key to return to main menu :-->  ");
                fflush(stdin);
                ch = fgetc(stdin);
                flag = 1;
                    
                break ;

            

                        
                    
            default:
                printf("\n\t\t\t\t\t\t Wrong input! enter a valid input    \n ");
                break;
        }

        if (flag == 1)
        {
            break ;

        }
        
       
        

            
           
               
            
        
    }   
   
    
}


int main()
{
    heada = creatadmin(heada,1,60 ,"chiken fried rice");
    heada = creatadmin(heada,2,80 ,"Hakka noodles");
    heada = creatadmin(heada,3,100,"shejvan  rice");
    heada = creatadmin(heada,4,120,"Manchurian with noodles");
    heada = creatadmin(heada,5,50 ,"Hot tomato Soup");

    while (1)
    {
        mainmenu();
        int choice ;
        scanf("%d", &choice);
       
        
        
       

        switch (choice)
        {

            case 1:
                admin();
                break;

            case 2:
                customer();
                break;
            
            case 3:
               
                break;

            
            default:
                break;
        }
        if (choice==3);
        {
            printf("\n\t\t\t\t\t\t *************** Thank You ! *************\n");
            break;
        }

       
       

       
        
        
    }
    
    return 0 ;
}