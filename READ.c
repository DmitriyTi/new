
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include <malloc.h> 

#define BUFFER_SIZE 255

struct list 
{ 
  char data[BUFFER_SIZE]; 
  struct list *next; 
}; 

int main()
{ 
  struct list *head = NULL; 
  struct list *head_ptr = NULL, *common_ptr = NULL, *buff_ptr = NULL; 
  int r = 0,dl = 0; 
  char buffer[BUFFER_SIZE]; 
  
  memset(&buffer, 0, sizeof(buffer));

  while(r != 1) { 
    fgets(buffer, BUFFER_SIZE, stdin); 

    if (head == NULL) 
    { 
      head_ptr = malloc(sizeof(struct list)); 
	    strcpy(head_ptr->data, buffer);
      head_ptr->next = NULL; 
      head = head_ptr; 
      dl++; 
    } 
      else 
    { 
      common_ptr = malloc(sizeof(struct list)); 
      strcpy(common_ptr->data, buffer); 
      dl++; 
      head_ptr = head; 

      while (head_ptr->next != NULL) 
      head_ptr = head_ptr->next; 
      common_ptr->next = head_ptr->next; 
      head_ptr->next = common_ptr; 
    } 
	

    if (buffer[0] == '.')
    { 
      printf("\n"); 
      dl--; 
      r = 1; 
    } 
}

  common_ptr = head; 

  while (common_ptr->next != NULL) 
  { 
    buff_ptr = common_ptr;
    printf("%s\n", common_ptr->data); 
    common_ptr = common_ptr->next; 
    free(buff_ptr);
  }
  free(common_ptr);
  getchar(); 
  return 0; 
}
