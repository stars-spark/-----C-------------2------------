/* Sums a series of numbers (using long int variables) */
#include <stdio.h>
#include <string.h>
void encrypt(char *message, int shift);
int main(void){
	char message[80];
	char ch;
	int n;
	int length = 0;

	printf("Enter message to be encrypted: ");
	while((ch = getchar()) != '\n') message[length++] = ch;
	printf("Enter shift amount (1-25): ");
	scanf("%d",&n);
	encrypt(message,n);
	printf("Encrypted message: %s",message);
	return 0;
}

void encrypt(char *message, int shift)
{
  int length = strlen(message);	
  for(int i = 0 ; i < length; i++){
		if(message[i]>='a'&& message[i]<='z')
			message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
		else if(message[i]>='A'&& message[i]<='Z')
			message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
	}

  }
