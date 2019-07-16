//시뮬레이션 2019.07.16
#include<stdio.h>

int k,num,dir,ret,cnt[4];
char ch[4][9];//+2 가 오른쪽 +6이 왼쪽

void rotation(int number,int direction,int from)//dir 1은 오른쪽, -1은 왼쪽회전
{
	if (from < number)//왼쪽에서 왔음 
	{
		if (number != 3)if (ch[number][(cnt[number] + 2) % 8] != ch[number + 1][(cnt[number+1] + 6) % 8])rotation(number + 1, -direction, number);
	}
	else if (from > number)//오른쪽
	{
		if (number != 0)if (ch[number][(cnt[number] + 6) % 8] != ch[number - 1][(cnt[number-1] + 2) % 8])rotation(number - 1, -direction, number);
	}
	else//자가회전
	{
		if (number != 3)if (ch[number][(cnt[number] + 2) % 8] != ch[number + 1][(cnt[number+1] + 6) % 8])rotation(number + 1, -direction, number);
		if (number != 0)if (ch[number][(cnt[number] + 6) % 8] != ch[number - 1][(cnt[number-1] + 2) % 8])rotation(number - 1, -direction, number);
	}
	cnt[number]-=direction;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	for (int i = 0; i < 4; cnt[i]=128,i++)scanf("%s", ch[i]);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d", &num, &dir);
		rotation(num - 1, dir, num - 1);
	}
	for (int i = 0, score = 1; i < 4; i++, score *= 2)if (ch[i][cnt[i]%8] == '1')ret += score;
	printf("%d", ret);
}
