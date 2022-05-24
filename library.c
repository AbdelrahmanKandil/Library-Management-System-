#include"library.h"


void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void libraryWellcome(void)
{	
	headMessage("Auther Name : Abdelrahman kandil Abdelhay ali mohamed Attia\n\t\t\t\t https://www.linkedin.com/in/abdulrahman-kandil/ ");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n");
	getch();
	printf("Choose one of the following options:\n");
	printf("-->	To view all books               Enter '1'\n");
	printf("-->	To add a New book               Enter '2'\n");
	printf("-->	To Delete a book                Enter '3'\n");
	printf("-->	To view No. of available books  Enter '4'\n");
	printf("-->	To Exist the Library App        Enter '5'\n");
	printf("----------------------------------------------------------\n");
	printf("---> You Choice is:");

}


void InputData(book_t* inputPtr)
{
    fflush(stdin);
    printf("Enter the Book's name: ");
    gets(inputPtr->Name);
    fflush(stdin);

    printf("Enter the Book's author: ");
    gets(inputPtr->Author);
    fflush(stdin);

    printf("Enter the Book's price: ");
    scanf("%d" , &inputPtr->Price);
}




List_t *CreateList(void)
{
	List_t *ListPtr = (List_t *)malloc(sizeof(List_t));
	if(NULL == ListPtr)
	{
		printf("Error : malloc failed to create your List !!!!\n");
	}
	else{
		ListPtr -> Head = NULL;
		ListPtr -> Size = 0;
		return ListPtr;
	}
}




ListState_t List_Empty(List_t *List)
{
	if(NULL == List)
	{
		printf("ERROR: There is no list!\n");
	}
	else{
		ListState_t Ret_State = LIST_NEMPTY;
		if(List->Size == 0)
		{
			Ret_State = LIST_EMPTY;
		}
		else{}
		return Ret_State;
	}
}




EStatus_t AddBook(List_t *List, book_t *inputptr) //Single Linked List Add from Back
{
	EStatus_t Ret_State = RET_OK;
	book_t *Ptr = NULL;

	if(NULL == List)
	{
		printf("ERROR: There is no list!\n");
		Ret_State = RET_NOK;
	}

	else{
		book_t *BookPtr = (book_t *)malloc(sizeof(book_t));
		if(BookPtr == NULL)
		{
			printf("Error: malloc failed to create your node !\n");
			Ret_State = RET_NOK;
		}
		else{
			BookPtr->Price = inputptr->Price;
            strcpy(BookPtr->Name,inputptr->Name);
            strcpy(BookPtr->Author,inputptr->Author);
			BookPtr->Next = NULL;
			Ptr = List->Head;

			if(Ptr == NULL)
			{
				List->Head = BookPtr;
				List->Size++;
			}

			else{
				while(Ptr->Next != NULL)
				{
					Ptr = Ptr->Next;
				}
				Ptr->Next = BookPtr;
				List->Size++;

			}
		}
	}
	return Ret_State;
}





EStatus_t DeleteBook(List_t *List, u16 position) //Single Linked List
{
	book_t *current = List->Head;
	book_t *previous = List->Head;
	EStatus_t Ret_State = RET_OK;

	if (position > List->Size)
	{
		printf("\nError ! Book number %d is not found in the library\n" , position);
		Ret_State = RET_NOK;	
	}

	else
	{
		if(position == 1)
		{
			List->Head = current->Next;
			free(current);
			current = NULL;
			List->Size--;
		}

		else
		{
			while (position != 1)
			{
			previous = current;
			current = current->Next;
			position--;
			}

			previous->Next = current->Next;
			free(current);
			current = NULL;
			List->Size--;
		}
	}
	return Ret_State;
}




u32 No_Of_Available_Books( List_t *List)
{
    return List->Size;
}




void DisplayBooks(List_t *List)
{
    book_t *ptr = NULL;
    if (List_Empty(List) == LIST_EMPTY)
    {
        printf("\nSorry! The library is empty! \n");
    }
    else
    {
        ptr = List->Head;
        while (ptr->Next != NULL)
        {
            printf("\n*********************************\n");
            printf("Book Name:      %s\n",ptr->Name);
            printf("Book Author:    %s\n",ptr->Author);
            printf("Book Price:     %d\n",ptr->Price);
			
            ptr = ptr->Next;
        }
        printf("\n*********************************\n");
        printf("Book Name:      %s\n",ptr->Name);
        printf("Book Author:    %s\n",ptr->Author);
        printf("Book Price:     %d\n",ptr->Price);
        ptr = ptr->Next;
    }
}

