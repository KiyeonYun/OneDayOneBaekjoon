#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int w, h;
char board[50][50] = { ' ', };

int count(char color)
{
	char even; // Â¦¼ö
	char odd;  // È¦¼ö
	int minCount = 0;
	int currentCount = 0;

	if (color == 'B')
	{
		even = 'B';
		odd = 'W';
	}
	else
	{
		even = 'W';
		odd = 'B';
	}

	for (int i = 0; i <= h - 8; i++)
	{
		for (int j = 0; j <= w - 8; j++)
		{
			//printf("\n½ÃÀÛÁöÁ¡ : %d, %d\n", i, j);
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					//printf("ÇöÀç: board[%d][%d] = %c\n", k, l, board[k][l]);
					if ((k + l == 0 || (k + l) % 2 == 0) && even != board[k][l])
					{
						//printf("1 > (k + l) % 2 = %d, even: %c\n", (k + l) % 2, even);
						currentCount++;
					}
					else if ((k + l) % 2 != 0 && odd != board[k][l])
					{
						//printf("2 > (k + l) % 2 = %d, odd: %c\n", (k + l) % 2, odd);
						currentCount++;
					}
				}
			}
			if ((i == 0 && j == 0 && currentCount != 0) || minCount > currentCount) minCount = currentCount;
			currentCount = 0;
		}
	}

	return minCount;
}

int main()
{
	scanf("%d %d", &h, &w);

	for (int i = 0; i < h; i++)
	{
		scanf("%s", board[i]);
	}

	int blackStartCount = count('B');
	int whiteStartCount = count('W');

	printf("%d", (blackStartCount < whiteStartCount ? blackStartCount : whiteStartCount));

	return 0;
}