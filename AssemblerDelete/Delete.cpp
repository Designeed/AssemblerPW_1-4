
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    char string[256];
    char result[256];
    int First;
    int Len;
    int counters;
    char f[] = "%s";
    char fd[] = "%d";
    std::cout << "¬ведите строку:";
    char outFStr[256] = "¬ведите индекс, с которого нужно начать удаление: ";
    char outSStr[256] = "¬ведите длину подстроки: ";

    __asm
    {
        lea esi, string

        push esi

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, outFStr

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, First

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ebx, outSStr

        push ebx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea ebx, Len

        push ebx

        lea ecx, fd

        push ecx

        call scanf

        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, First

        lea ebx, string
        push ebx
        dec ebx

        LengthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz LengthStr
            push ecx

            StartDelete :
        cmp First, 0
            jge LengthDelete

            mov First, 0

            LengthDelete :
            cmp Len, 0
            jl StrNoChange

            FirstBiggerLength :
        cmp First, ecx
            jg StrNoChange

            add esp, 8
            mov counters, ecx
            mov ecx, 0
            dec esi

            lea esi, [string]
            lea edi, [result]
            push edi

            mov edx, First

            cmp edx, 1
            jl AddLength

            StartWrite :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne StartWrite

            AddLength :
        add edx, Len
            mov eax, counters
            cmp edx, eax
            jbe EndWrite
            mov edx, eax

            EndWrite :
        inc esi
            inc ecx
            cmp ecx, edx
            jne EndWrite

            ContinueEndWrite :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueEndWrite

            jmp End



        StrNoChange:
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [string]
            lea edi, [result]
            push edi

            ContinueNoChange :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueNoChange

            End :
        pop edi
            pop esi
    }
    std::cout << "Your line: ";
    std::cout << result;
}

