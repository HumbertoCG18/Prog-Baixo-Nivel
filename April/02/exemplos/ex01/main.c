#include <stdio.h>

int main () {

   char greeting1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   char greeting2[7] = {'H', 'e', 'l', 'l', 'o', '\0'};
   char greeting3[5] = {'H', 'e', 'l', 'l', 'o', '\0'};
   printf("Greeting message1(%p): %s\n", greeting1, greeting1 );
   printf("Greeting message2(%p): %s\n", greeting2, greeting2 );
   printf("Greeting message3(%p): %s\n", greeting3, greeting3 );
   return 0;
}
