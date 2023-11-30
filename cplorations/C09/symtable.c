#include "symtable.h"
#include "error.h"
#include "hack.h"

Symbol* hashArray[SYMBOL_TABLE_SIZE]; 

int hash(char *str)
{
   
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    hash %= SYMBOL_TABLE_SIZE;
    return hash;
}

void symtable_insert(char* key, hack_addr addr) {


   
   Symbol *item =  malloc(sizeof(Symbol));
   item->address = addr;  
   item->name = strdup(key);

   //get the hash 
   
   int hashIndex = hash(key);

   
   //move in array until an empty or deleted cell
   while((hashArray[hashIndex] != NULL) && (hashArray[hashIndex]->name != NULL)) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }
	
   hashArray[hashIndex] = item;
}


Symbol *symtable_find(char *name) {
   //get the hash 
   int hashIndex = hash(name);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(strcmp(hashArray[hashIndex]->name, name) ==0)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SYMBOL_TABLE_SIZE;
   }        
   return NULL;     

  
}


void symtable_display_table() {
   int i = 0;
	
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->name,hashArray[i]->address);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

void symtable_print_labels() {
   int i = 0;    
   for(i = 0; i<SYMBOL_TABLE_SIZE; i++) {
        if(hashArray[i] != NULL){
             printf("{%s,%d}\n",hashArray[i]->name,hashArray[i]->address);
   
        }
        
   }
}
