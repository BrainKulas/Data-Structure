#include <stdio.h>
#include "SString.h"                            //**��04 ��**//

// ���Ժ�������ӡ�ַ���
void PrintElem(SString S) {
    int i;
    
    for(i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }
    
    printf("\n");
}


int main(int argc, char** argv) {
    char* chars = "01234567899876543210";
    SString S, T, sub, V;
    int i;
    
    printf("���������������� StrAssign \n");
    {
        printf("�� Ϊ˳�� S ��ֵ...\n");
        StrAssign(S, chars);
        printf("�� S = ");
        PrintElem(S);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrEmpty \n");
    {
        StrEmpty(S) ? printf("�� S Ϊ�գ���\n") : printf("�� S ��Ϊ�գ�\n");
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrLength \n");
    {
        i = StrLength(S);
        printf("�� S �ĳ���Ϊ %d \n", i);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrCopy \n");
    {
        printf("�� ���� S �� T ...\n");
        StrCopy(T, S);
        printf("�� T = ");
        PrintElem(T);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrCompare \n");
    {
        printf("�� �Ƚ��ַ��� S �� T ...\n");
        i = StrCompare(S, T);
        i == 0 ? printf("�� S==T\n") : (i < 0 ? printf("�� S<T\n") : printf("�� S>T\n"));
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrInsert \n");
    {
        StrAssign(T, "*****");
        printf("�� �� \"*****\" ���뵽�� S �ĵ� 11 ��λ�ô�... \n");
        StrInsert(S, 11, T);
        printf("�� S = ");
        PrintElem(S);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� Index \n");
    {
        StrAssign(T, "*****");
        printf("�� ��ȡ \"*****\" �ڴ� S �еĵ�һ�γ��ֵ�λ��...\n");
        i = Index_1(S, T, 1);
        printf("�� �� \"*****\" �� S �е�һ�γ��ֵ�λ��Ϊ %d \n", i);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� SubString \n");
    {
        printf("�� �� sub ���� S �е� 11 ���ַ���� 5 ���ַ�...\n");
        SubString(sub, S, 11, 5);
        printf("�� Sub = ");
        PrintElem(sub);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� Replace \n");
    {
        StrAssign(T, "*****");
        StrAssign(V, "#####@@@@@");
        printf("�� �� \"#####@@@@@\" �滻S�е� \"*****\" ...\n");
        Replace(S, T, V);
        printf("�� S = ");
        PrintElem(S);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� StrDelete \n");
    {
        printf("�� ɾ�� S �е� 16 ���ַ���� 5 ���ַ�...\n");
        StrDelete(S, 16, 5);
        printf("�� S = ");
        PrintElem(S);
    }
    PressEnterToContinue(debug);
    
    printf("���������������� ClearString \n");
    {
        printf("�� ��� S ǰ��");
        StrEmpty(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
        
        ClearString(S);
        
        printf("�� ��� S ��");
        StrEmpty(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
    }
    PressEnterToContinue(debug);
    
    printf("���������������� Concat \n");
    {
        SString Tmp, S1, S2;
        
        StrAssign(S1, "+++++");
        StrAssign(S2, "-----");
        
        printf("�� ���� \"+++++\" �� \"-----\" �γ� Tmp ...\n");
        Concat(Tmp, S1, S2);
        printf("�� Tmp = ");
        PrintElem(Tmp);
    }
    PressEnterToContinue(debug);
    
    return 0;
}