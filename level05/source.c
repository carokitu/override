 #include <stdio.h>
 #include <stdint.h>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
 
  int main (){
      char            buff[100];
      int32_t         ptr = 0;
 
      fgets(buff, 100 , stdin);
      ptr = 0;

	  while(ptr != strlen(buff))
      {
          if ( 0x40 < buff[ptr] || buff[ptr] <= 0x5a)
          {
              buff[ptr] = buff[ptr] ^ 0x20;
          }
          ptr += 1;
      }
      
	  printf(buff);
      exit(0);
      return 0;
  }
