
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    char string[256];
    char FindString[256];
    int counters;
    char f[] = "%s";
    char fd[] = "%d";
    std::cout << "¬ведите вашу строку:";
    char outFStr[256] = "¬ведите искомую строку:";

    __asm
    {
        lea ebx, string

        push ebx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea edx, outFStr

        push edx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea edx, FindString

        push edx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, string
        lea edx, FindString
        dec ebx
        dec edx
        lea ecx, fd
        mov ecx, -1
        push ecx

        FindStr :
        inc ebx
            inc ecx
            mov al, [ebx]
            cmp al, 0
            jz RepeatComp
            jmp Continue
            RepeatComp :
        inc edx
            mov ah, [edx]
            cmp ah, 0
            jz end
            add esp, 4
            mov eax, -1
            push eax
            jmp end
            Continue :
        inc edx
            mov ah, [edx]
            cmp ah, 0
            jz end
            cmp al, ah
            jz CompareResult
            lea edx, FindString
            dec edx
            add esp, 4
            mov eax, -1
            push eax
            jmp FindStr
            CompareResult :
        pop eax
            cmp eax, -1
            jg Next
            push ecx
            jmp FindStr
            Next :
        push eax
            jmp FindStr

            end :
        lea ebx, fd
            push ebx
            call printf
            add esp, 8
    }


}

