#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include “readline.h”

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int compare_parts(const void *p, const void *q);

int main(void){
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert(); 
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

int find_part(int number){
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

void insert(void){
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

void search(void){
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
  } else
    printf("Part not found.\n");
}

void update(void){
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

void print(void){
  int i;
  qsort(inventory, num_parts, sizeof(struct part), compare_parts);
  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand);
}

int compare_parts(const void *p, const void *q){
if (((struct part *) p)->number < 
((struct part *) q)->number)
   return -1;
else if (((struct part *) p)->number == 
((struct part *) q)->number)
   return 0;
else
   return 1;
}
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include “readline.h”

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;   /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
/********************************************************** 
 * main: Prompts the user to enter an operation code,     * 
 *       then calls a function to perform the requested   * 
 *       action. Repeats until the user enters the        * 
 *       command 'q'. Prints an error message if the user * 
 *       enters an illegal code.                          * 
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert(); 
                break;
      case 's': search(); 
                break;
      case 'u': update(); 
                break;
      case 'p': print();  
                break;
      case 'e': erase();  
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/********************************************************** 
  * find_part: Looks up a part number in the inventory     * 
  *            list. Returns a pointer to the node         * 
  *            containing the part number; if the part     * 
  *            number is not found, returns NULL.          * 
  **********************************************************/
struct part *find_part(int number)
{
  struct part *p;

  for (p = inventory;
       p != NULL && number > p->number;
       p = p->next)
    ;
  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

/********************************************************** 
 * insert: Prompts the user for information about a new   * 
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       * 
 *         returns prematurely if the part already exists * 
 *         or space could not be allocated for the part.  * 
 **********************************************************/
void insert(void)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

/********************************************************** 
 * search: Prompts the user to enter a part number, then  * 
 *         looks up the part in the database. If the part * 
 *         exists, prints the name and quantity on hand;  * 
 *         if not, prints an error message.               * 
 **********************************************************/
void search(void)
{
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/********************************************************** 
 * update: Prompts the user to enter a part number.       * 
 *         Prints an error message if the part doesn't    * 
 *         exist; otherwise, prompts the user to enter    * 
 *         change in quantity on hand and updates the     * 
 *         database.                                      * 
 **********************************************************/
void update(void)
{
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("Part not found.\n");
}

/********************************************************** 
 * print: Prints a listing of all parts in the database,  * 
 *        showing the part number, part name, and         * 
 *        quantity on hand. Part numbers will appear in   * 
 *        ascending order.                                * 
 **********************************************************/
void print(void)
{
  struct part *p;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name,
           p->on_hand);
}

void erase(void)
{
  int number;
  struct part *p, *cur;

  printf("Enter part number to erase: ");
  scanf("%d", &number);

  for (p = inventory;
       p != NULL && p->next->number != number;
       p = p->next);
    cur = p->next;
    p->next = cur->next;
    free(cur);
}
