
#include <iostream>

int main()
{
   
    char result[256];
    char firstString[] = "qwerty";
    char secondString[] = "12345";
    _asm  
    {
        lea esi, [firstString]
        lea edi, [result]

        FOR_1:
            lodsb
            stosb
            cmp al, 0
        jnz FOR_1

        lea esi, [secondString]
        dec edi

        FOR_2 :
            lodsb
            stosb
            cmp al, 0
        jnz FOR_2

    }
    std::cout << result;
}


