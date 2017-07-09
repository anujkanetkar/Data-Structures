#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100
#define FOUND 1
#define NOTFOUND 0
#define YES 1
#define NO 0

void unio(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz);
void intersect(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz);
void onlyCricket(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz);
void onlyBaddy(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz);
void neither(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz);

int main()
{
	int stud_num, crick_num, baddy_num;
	int stud[MAX], crick[MAX], baddy[MAX];
	int i, j, k;

	printf("Enter the no of students in class: \n");
	scanf("%d", &stud_num);

	printf("Enter the roll nos of students in the class: \n");
	int a; int count=0; int flag;

	for (i = 0; i < stud_num;)
	{
		flag = NOTFOUND;
		scanf("%d", &a);
		if (a < 0)
		{
			printf("You entered a negative roll no. Enter again\n");
			continue;
		}
		for (j = 0; j < count; j++)
		{
			if (stud[j] == a)
			{
				flag = FOUND;
				break;
			}
		}
		if (flag == NOTFOUND)
		{
			stud[i] = a;
			count++;
			i++;
		}
		else
			printf("Repeated roll no. Enter a different one: \n");
	}

	printf("Enter no of students playing cricket: \n");
	scanf("%d", &crick_num);

	printf("Enter roll no of students who play cricket: \n");

	for (i = 0; i < crick_num;)
	{
		flag = NOTFOUND;
		scanf("%d", &a);
		if (a < 0)
		{
			printf("You entered a negative roll no. Enter again\n");
			continue;
		}
		for (j = 0; j < count; j++)
		{
			if (crick[j] == a)
			{
				flag = FOUND;
				break;
			}
		}
		if (flag == NOTFOUND)
		{
			crick[i] = a;
			count++;
			i++;
		}
		else
			printf("Repeated roll no. Enter a different one: \n");
	}

	printf("Enter no of students playing badminton: \n");
	scanf("%d", &baddy_num);

	printf("Enter roll no of students who play badminton\n");

	for (i = 0; i < baddy_num;)
	{
		flag = NOTFOUND;
		scanf("%d", &a);
		if (a < 0)
		{
			printf("You entered a negative roll no. Enter again\n");
			continue;
		}
		for (j = 0; j < count; j++)
		{
			if (baddy[j] == a)
			{
				flag = FOUND;
				break;
			}
		}
		if (flag == NOTFOUND)
		{
			baddy[i] = a;
			count++;
			i++;
		}
		else
			printf("Repeated roll no. Enter a different one: \n");
	}

	int choice;

	while (1)
	{
		printf("Enter choice code: 1 for union, 2 for intersection, 3 for only cricket, 4 for only badminton, 5 for neither: \n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			unio(stud, stud_num, crick, crick_num, baddy, baddy_num);
			break;
		case 2:
			intersect(stud, stud_num, crick, crick_num, baddy, baddy_num);
			break;
		case 3:
			onlyCricket(stud, stud_num, crick, crick_num, baddy, baddy_num);
			break;
		case 4:
			onlyBaddy(stud, stud_num, crick, crick_num, baddy, baddy_num);
			break;
		case 5:
			neither(stud, stud_num, crick, crick_num, baddy, baddy_num);
			break;
		default:
			printf("Invalid choice code\n");
			exit(1);
		}
	}

	return 0;
}

void unio(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz)
{
	printf("Students playing either cricket or badminton or both are: \n");

	int flag, i, j, k, l;
	int count = 0;
	int arr[MAX];

	for (i = 0; i < cric_sz; i++)
	{
		arr[count] = cr[i];
		count++;
	}

	for (k = 0; k < baddy_sz; k++)
	{
		flag = NOTFOUND;
		for (l = 0; l < count; l++)
		{
			if (arr[l] == badm[k])
			{
				flag = FOUND;
				break;
			}
		}

		if (flag == NOTFOUND)
		{
			arr[count] = badm[k];
			count++;
		}
	}

	for (l = 0; l < count; l++)
		printf("%d ", arr[l]);
}

void intersect(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz)
{
	printf("Students playing both games are \n");
	for (int i = 0; i < stud_sz; i++)
	{
		for (int j = 0; j < cric_sz; j++)
		{
			if (s[i] == cr[j])
			{
				for (int k = 0; k < baddy_sz; k++)
				{
					if (s[i] == badm[k])
						printf("%d\n", s[i]);
				}
			}
		}
	}
}

void onlyCricket(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz)
{
	int flag;

	printf("Students playing only cricket are \n");
	for (int i = 0; i < stud_sz; i++)
	{
		for (int j = 0; j < cric_sz; j++)
		{
			if (s[i] == cr[j])
			{
				flag = NOTFOUND;
				for (int k = 0; k < baddy_sz; k++)
				{
					if (s[i] == badm[k])
						flag = FOUND;
				}
				if (flag == NOTFOUND)
					printf("%d\n", s[i]);
			}
		}
	}

}

void onlyBaddy(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz)
{
	int flag;

	printf("Students playing only badminton are \n");
	for (int i = 0; i < stud_sz; i++)
	{
		for (int j = 0; j < baddy_sz; j++)
		{
			if (s[i] == badm[j])
			{
				flag = NOTFOUND;
				for (int k = 0; k < cric_sz; k++)
				{
					if (s[i] == cr[k])
						flag = FOUND;
				}
				if (flag == NOTFOUND)
					printf("%d\n", s[i]);
			}
		}
	}
}

void neither(int *s, int stud_sz, int *cr, int cric_sz, int *badm, int baddy_sz)
{
	int cricket, baddy;
	printf("Students playing neither game are \n");


	for (int i = 0; i < stud_sz; i++)
	{
		cricket = NO;
		for (int j = 0; j < cric_sz; j++)
		{
			if (s[i] == cr[j])
			{
				cricket = YES;
				break;
			}
		}

		baddy = NO;
		for (int k = 0; k < baddy_sz; k++)
		{
			if (s[i] == badm[k])
			{
				baddy = YES;
				break;
			}
		}
		if (cricket == NO && baddy == NO)
			printf("%d\n", s[i]);
	}
}
