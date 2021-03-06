#include <stdio.h>  //  library for I/O
#include <string.h> //  library for strings
#include <stdlib.h>

typedef struct b {              // declaring the structure for describing books
    char title[60], author[50];
    int year;
    float book_rate;
} book;


struct customer {              // declating the structure for describing customers
    char name[50];
    int age;
    float customer_rate;
};

/**/   book book_start;      // just an empty object to create an address for pointer   (it won't be used to avoid confusion)
/**/
/**/   book *book_ptr_head = &book_start + 1;    // pointer, which points at first book in list 
/**/   book *book_ptr_end = &book_start + 1;     // pointer, which points at last(+1) book in list : it means that there is no book/customer at this address
 




/**/   struct customer customer_start;      // the same construction  as in case with books, but for customers
/**/
/**/   struct customer *cust_ptr_head = &customer_start + 1;   // points at first customer
/**/   struct customer *cust_ptr_end = &customer_start + 1;    // points at last(+1) customer



int stop_program = 0;    // variable for function "Quit". If equals to 1, then the program stops.  



void Show_Books();
void Add_Book();
void Update_Book();           
void Remove_Book();                      // These functions are described under the "main" function. Nothing important for now.
void Show_Customers();
void Add_Customer();
void Update_Customer();
void Remove_Customer();
void show_main_menu();

void enumeration(int n) {                  //  enumeration of possible inputs
    
    switch(n){
        case 1:
            Show_Books();
            break;
        case 2:
            Add_Book();
            break;
        case 3:
            Update_Book();
            break;
        case 4:
            Remove_Book();
            break;
        case 5:
            Show_Customers();
            break;
        case 6:
            Add_Customer();
            break;
        case 7:
            Update_Customer();
            break;
        case 8:
            Remove_Customer();
            break;
        case 9:
            stop_program = 1;               
            break;
        default:
            printf("\n!! YOU CAN USE ONLY AN INTEGER, WHICH BELONGS TO [1;9] !!\n\n"); 
    }
}

int main(){      

    while (1) {

        show_main_menu();

        int input;
        scanf("%d", &input);                    // inputing number of function

        enumeration(input);
        if(stop_program)return 0;
        
    }

    return 0;
}



void show_main_menu() {                         // showing possibilities (functionalities) (or main menu)
    printf("Choose one of the functionalities:    \n");
        printf("1 - Show Books                    \n");
        printf("2 - Add Book                      \n");
        printf("3 - Update Book                   \n");
        printf("4 - Remove Book                   \n");
        printf("5 - Show Customers                \n");
        printf("6 - Add Customer                  \n");
        printf("7 - Update Customer               \n");
        printf("8 - Remove Customer               \n");
        printf("9 - Quit                          \n");
        printf("Enter an integer (1 - 9): ");
}


void Show_Books() {
    if(book_ptr_head == book_ptr_end){
        printf("\n!! THERE ARE NO BOOKS IN THE SYSTEM !!\n\n");           // in case of no books
        return;
    }
    else {
        int counter = 1;  // book number
        printf("\n");
        for(book *i = book_ptr_head;i < book_ptr_end;i++){           // enumeration of list using pointers and printring data
            printf("%d Book - Title: %s\n", counter, (*i).title);
            printf("         Author: %s\n", (*i).author);
            printf("         Year: %d\n", (*i).year);
            printf("         Rate: %.2f\n", (*i).book_rate);
            printf("\n");
            counter++;
        }
    }
}

void Add_Book() {
    printf("Enter a title of new book: ");
    scanf("%c");   // to avoid the typing an empty char in "gets()"
    gets(book_ptr_end->title);
    printf("Enter an author's name: ");                                         
    gets(book_ptr_end->author);
    printf("Enter the year: ");                                             // adding the parameters of the new book and moving last pointer forward
    scanf("%d", &(*book_ptr_end).year);
    printf("Enter the book's rate: ");
    scanf("%f", &(*book_ptr_end).book_rate);
    printf("\n!! THE NEW BOOK HAS BEEN SUCCESSFULLY ADDED !!\n\n");
    book_ptr_end++;                                                         
}

void Update_Book() {

    char search[60];
    printf("Enter the title of book, which you want to update: ");
    scanf("%c");   // to avoid the typing an empty char in "gets()"
    gets(search);

    auto int find = 0;    // if equals to 1, then such book exists

    for(book *i = book_ptr_head ;i < book_ptr_end; i++){              // enumeration of all books in linked-list
        if(strcmp(search, (*i).title) == 0){
            printf("\nEnter the new parameters:\n");
            printf("Enter the title of the book: ");
            gets(i->title);
            printf("Enter an author's name: ");
            gets(i->author);                                         // If book with such title is found, then asking to set a new parameters
            printf("Enter the year: ");
            scanf("%d", &(*i).year);
            printf("Enter the book's rate: ");            
            scanf("%f", &(*i).book_rate);
            find = 1;
            printf("\n!! THE BOOK HAS BEEN SUCCESSFULLY UPDATED !!\n\n");
            break;
        }
    }


    if(find == 0){
        printf("\n!! THE BOOK WITH SUCH TITLE DOES NOT EXIST !!\n\n");
    }
}   

void Remove_Book() {
    char search[60];
    printf("Enter the title of book, which you want to remove: ");
    scanf("%c");    // to avoid the typing an empty char in "gets()"
    gets(search);

    auto int find = 0;   // if equals to 1, then such book exists

    for (book *i = book_ptr_head; i < book_ptr_end; i++){
        if(strcmp(search, (*i).title) == 0) {

            for(book *j = i + 1;j < book_ptr_end; j++){      // if book with such title is found, then each of next book takes position of previous
                *(j - 1) = *j;                                                                                    // then pointer of end goes back
            }


            find = 1;
            book_ptr_end--;

            printf("\n!! THE BOOK HAS BEEN SUCCESSFULLY REMOVED !!\n\n");

            break;
        }
    }

    if(find == 0){
        printf("\n!! THE BOOK WITH SUCH TITLE DOES NOT EXIST !!\n\n");
    }

}

void Show_Customers() {

    if(cust_ptr_head == cust_ptr_end){
        printf("\n!! THERE ARE NO CUSTOMERS IN THE SYSTEM !!\n\n");       // in case of no customers
    }
    else {
        int counter = 1;               // customer number
        printf("\n");
        for(struct customer *i = cust_ptr_head; i < cust_ptr_end; i++){          // enumeration of list using pointers and printing data
            printf("%d Customer - Name: %s\n", counter, (*i).name);
            printf("             Age: %d\n", (*i).age);
            printf("             Rate: %.2f\n", (*i).customer_rate);
            printf("\n");
            counter++;
        }
    }
}

void Add_Customer() {      

    printf("Enter a name of new customer: ");
    scanf("%c");     // to avoid the typing an empty char in "gets()"
    gets(cust_ptr_end->name);
    printf("Enter the age of new customer: ");
    scanf("%d", &(*cust_ptr_end).age);                                        // adding parameters of new customer and moving last pointer forward
    printf("Enter the customer's rate: ");
    scanf("%f", &(*cust_ptr_end).customer_rate);
    printf("\n!! THE NEW CUSTOMER HAS BEEN SUCCESSFULLY ADDED !!\n\n");
    cust_ptr_end++;
}

void Update_Customer() {

    char search[60];
    printf("Enter the customer's name, which you want to update: ");
    scanf("%c");    // to avoid the typing an empty char in "gets()"
    gets(search);

    auto int find = 0;   // if equals to 1, then such customer exists

    for(struct customer *i = cust_ptr_head; i < cust_ptr_end ;i++){         //    enumeration of all customers in linked-list
        if(strcmp((*i).name, search) == 0){
            printf("\nEnter the new parameters:\n");
            printf("Enter the customer's name: ");
            gets(i->name);
            printf("Enter the customer's age: ");                         // If customer with such name is found, then asking to set a new parameters
            scanf("%d", &(*i).age);
            printf("Enter the customer's rate: ");
            scanf("%f", &(*i).customer_rate);
            find = 1;
            printf("\n!! THE CUSTOMER HAS BEEN SUCCESSFULLY UPDATED !!\n\n");
            break;
        }
    }

    if (find == 0){
        printf("\n!! THE CUSTOMER WITH SUCH NAME DOES NOT EXIST !!\n\n");
    }
}

void Remove_Customer() {

    char search[60];
    printf("Enter the name of custower, which you want to remove: ");
    scanf("%c");     // to avoid the typing an empty char in "gets()"
    gets(search);


    auto int find = 0;    // if equals to 1, then such customer exists

    for(struct customer *i = cust_ptr_head; i < cust_ptr_end; i++) {          //    enumeration of all customers in linked-list
        if(strcmp((*i).name, search) == 0){

            for(struct customer *j = i + 1; j < cust_ptr_end;j++){
                *(j - 1) = *j;                                        // if customer with such name is found, then each of next customer takes position of previous
            }                                                                                                            // then pointer of end goes back
                                                                                            
            cust_ptr_end--;

            find = 1;
            printf("\n!! THE CUSTOMER HAS BEEN SUCCESSFULLY REMOVED !!\n\n");
            break;
        }
    }

    if(find == 0){
        printf("\n!! THE CUSTOMER WITH SUCH NAME DOES NOT EXIST !!\n\n");
    }
}