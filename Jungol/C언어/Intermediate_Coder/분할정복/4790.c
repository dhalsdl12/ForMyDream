#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int n, m;
int* arr;

int isPossible(int mid);
int main()
{
	int left = 0;
	int right = 0;
	int mid;

	scanf("%d %d", &n, &m);

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (left < arr[i])
			left = arr[i];
		right += arr[i];
	}
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (isPossible(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
int isPossible(int mid)
{
	int sum = 0;
	int cnt = 1;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (sum > mid)
		{
			sum = arr[i];
			cnt++;
		}
	}
	if (cnt <= m)
		return 1;
	else
		return 0;
}