#include <stdio.h> 

void VeryLongWord(const char * sen) {

	// code goes here 
	int cnt = 0;
	int len = 0;
	int l = 0;
	int j = 0;
	char temp[100];
	char Long[100];
	printf("Input : %s\n", sen);
	for(int i=0;i<12;i++)
	{
		if (('A' <= sen[i] && sen[i] <= 'Z') || ('a' <= sen[i] && sen[i] <= 'z'))
		{
			len++;
			if (l <= len)
			{
				Long[j] = sen[i];
				l = len;//l은 최고 긴 단어 길이 기억
			}
			j++;
		}
		else
		{
			len = 0;//초기화
			cnt = 0;
			j = 0;
		}
		
	}
	printf("output : %s\n", Long);
	
}

int main(void) {

	// keep this function call here
	VeryLongWord("i love dogs"); // 큰 따옴표 잘 넣어보기 
	return 0;

}