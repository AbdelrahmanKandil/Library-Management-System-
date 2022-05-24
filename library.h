#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
#include "STD_TYPES.h"
// Macro related to the books info
#define MAX_BOOK_NAME   30
#define MAX_AUTHOR_NAME 30

typedef struct Book
{
    u8 Name[MAX_BOOK_NAME];
    u8 Author[MAX_AUTHOR_NAME];
    u16 Price;
    struct Book *Next;

}book_t;


typedef struct 
{
    u16 Size;
    struct Book *Head;
    
}List_t;



typedef enum
{
    LIST_EMPTY,
    LIST_NEMPTY

}ListState_t;


typedef enum{
	RET_NOK,
	RET_OK,
}EStatus_t;


void printMessageCenter(const char* message);
void headMessage(const char *message);
void libraryWellcome(void);
List_t *CreateList(void);
ListState_t List_Empty(List_t *List);
void DisplayBooks(List_t *List);
void InputData(book_t* inputPtr);
EStatus_t AddBook(List_t *List, book_t *inputptr);
EStatus_t DeleteBook(List_t *List, u16 position);
u32 No_Of_Available_Books( List_t *List);



#endif