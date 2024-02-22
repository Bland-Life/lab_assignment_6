#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	// Middle Index
	int mid = low + ((high - low) / 2);

	// If the index between low and high does not equal the value and there are no more middle values, return -1
	if (numbers[mid] != value && (mid == low || mid == high)) {
		return -1;
	}

	// If the middle value is lower than the search value, check the upper half of the array
	if (numbers[mid] < value) {
		return search(numbers, mid, high, value);
	}
	// Else if the middle value is higher than the search value, check the lower half of the array
	else if (numbers[mid] > value) {
		return search(numbers, low, mid, value);
	}
	// If none of the previous conditions are true then mid MUST be the index with the search value
	return mid;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}