#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g_intWaitAndPrintIndex=0;
void WaitAndPrint(int bReset)//1 �N�N���ݵ����A0 �N�O�~�򵥫�
  {
    char strTickCharacter[] = "|/-\\";

    if(bReset)
      {
        g_intWaitAndPrintIndex = (-1);

        fprintf(stdout, "\n");//���ݵ���

        return;
      }

    g_intWaitAndPrintIndex ++;
    g_intWaitAndPrintIndex %= strlen(strTickCharacter);//�p��n��ܪ��r��


    if(g_intWaitAndPrintIndex == 0)
    {
        fprintf(stdout, ".");
    }

    fprintf(stdout, "%c\b", strTickCharacter[g_intWaitAndPrintIndex]);//�z�L\b���L�X�Ӫ��r�����N�e�@�Ӧr��,�y����r�������ݰʵe�ĪG
  }
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        WaitAndPrint(0);
        _sleep(1000/5);
    }
    WaitAndPrint(1);
    return 0;
}
