#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>




int main(int argc, char *argv[])
{
    FILE *file = popen("gcc -c -Wall -Werror -fpic lib.c", "r");
    if (file!= NULL){
        
        pclose(file);
        file = popen("gcc -shared -o lib.dll lib.o", "r");
        if (file!= NULL){
            pclose(file);
            
            HMODULE module= LoadLibraryA("lib.dll");
            FARPROC proc= GetProcAddress(module, "_main");
            proc();
            FreeLibrary(module);
            
        }
		else
		{
            printf("Shared library creation failed\n");

        }
        
    }else{
        printf("Error creating object file\n");
    }
    
    return 0;
   
}
