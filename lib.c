
#include <stdarg.h>
#include <stdio.h>
void WriteText(char *format ,...){
   va_list args;
   va_start(args, format);
   vfprintf(stdout, format, args);
   va_end(args);
}
int _main(){ 
   WriteText("count from 0 to 9 : \n");
   int i;
   for (i=0; i<10; i++){
      
      WriteText("%d ", i);
   }
  
   

   return 0;
}

// hada code li radi diro f fichier smito lib.c, khass yekoun fih had point d'entrée _main()