/************************************************************************************************
** Auther Name : Abdelrahman kandil Abdelhay ali mohamed Attia
** Desc : Library management system using C Langauge.
** Lecturer : ENG.Mohammed Serag 
** Date : 30/30/2022
***********************************************************************************************/

#include "main.h"



int main(void)
{
    u16 choice = 0 , position = 0;
    u32 number_of_books = 0;

    EStatus_t status;
    book_t book;

    List_t *listaddress = NULL;
    listaddress = CreateList();


    do
    {
        libraryWellcome();
        printf("Enter Your Choice -----> ");
        scanf("%d" , &choice);


        switch (choice)
        {

        case 1:
            DisplayBooks(listaddress); 
            break;
        
        case 2:
            InputData(&book);
            status = AddBook(listaddress,&book);

            if (status == RET_OK)
            {
					printf("\n-------------------------------- Book Has been added successfully --------------------------------\n");

            }
            else
            {
					printf("\n-------------------------------- Failed to Add The Book ! --------------------------------\n");
            }

            break;


        case 3:
                if (List_Empty(listaddress) == LIST_EMPTY)
                {
                    printf("\nSorry! The library is empty! \n");
                }

                else
                {
                    printf("Enter the number of book you want to delete (From 1 to %d): ", listaddress->Size);
                    scanf("%d" ,&position);
                    status = DeleteBook(listaddress,position);

                    if (status == RET_OK)
                        {
						printf("\n--------------------------------Sorry The library is empty!!-------------------------------- \n");
                        }
                        else
                        {
                            printf("\n--------------------------------  Book Has been added deleted !!--------------------------------\n");
                        }
                }

            break;


        case 4:
            number_of_books = No_Of_Available_Books(listaddress);
			if (number_of_books == 0)
			{
			printf("\n--------------------------------Sorry The library is empty!!-------------------------------- \n");	
			}
			else{
            printf("\nThe number of available Books: %d\n",number_of_books);
			}
            break;

        case 5:
				    printf("\n-------------------------------- Close The Program !! !!--------------------------------\n");
            exit(0);
            break;


        default:
			printf("\n--------------------------------Error! Wrong Choice--------------------------------\n");		
            break;
        }



    } while (choice != 5);
    

    return 0;
}