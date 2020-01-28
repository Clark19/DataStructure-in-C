/*
 * DataStructure_Algorithm.c
 *
 *  Created on: 2020. 1. 27.
 *      Author: i7-5820k
 */
#include <stdio.h>
#include <stdbool.h>

#define FiboLength 15

typedef enum _DS_Algo {
	FIBONACCI = 0,
	FACTORIAL,
	BINARY_SEARCH_RECUR,
	HANOI_TOWER

} DS_Algo;

struct DS_Algo_Str {
	DS_Algo key;
	char eName[30];
	char kName[30];
};

struct DS_Algo_Str DsAlgoStr[4] = { {FIBONACCI, "FIBONACCI Sequence", "피보나치 수열"}
 , {FACTORIAL, "FACTORIAL", "팩토리얼"} ,{ BINARY_SEARCH_RECUR, "BINARY SEARCH (Recursion)", "이진 탐색 (재귀)"}
 , {HANOI_TOWER, "HANOI TOWER Move", "하노이 타워 이동"}
};


int* init();
void run(DS_Algo NumberOfDS_Algo);
int BSearchRecur(int ar[], int first, int last, int target);
int Fibonacci(int n);
void makeFibonacciSequence(int fiboArr[], const int length);
bool equalArray(int a[], int b[], const int sizeA, const int sizeB);
int Factorial(int n);
void HanoiTowerMove(int numOfDisk, char from, char by, char to);

int main() {

  run(FIBONACCI);
  run(FACTORIAL);
  run(BINARY_SEARCH_RECUR);
  run(HANOI_TOWER);
  return 0;
}


void run(DS_Algo NumberOfDS_Algo) {
	printf("Start of %s Example = %s 예제 시작 \n", DsAlgoStr[NumberOfDS_Algo].eName, DsAlgoStr[NumberOfDS_Algo].kName);
	switch (NumberOfDS_Algo)
	{
	case FIBONACCI: {
		int fibonacciTestData[] = { 0,1,1,2,3,5,8,13,21, 34, 55, 89, 144, 233, 377 };
		int fibonacciTestFalseData[] = { 0,1,1,2,3,5,8,13,21, 34, 55, 89, 144, 233, 111 };
		int testDataLength = sizeof(fibonacciTestData) / sizeof(int);

		int fibonacciData[FiboLength];
		makeFibonacciSequence(fibonacciData, FiboLength);
		if ( equalArray(fibonacciTestData, fibonacciData, testDataLength, FiboLength)
			 && !equalArray(fibonacciTestFalseData, fibonacciData, testDataLength, FiboLength) ) {
			printf("Success of Fibonacci Sequence! : \n");
			//show fibonacci sequence
			for (int i=0; i< FiboLength; i++)
				printf("%d ", fibonacciData[i]);
			printf("\n");
		}
		else
			printf("fibonacci Fail! \n");
	}
				  break;
	case FACTORIAL: {
		int factorialTestData = 1;
		const int FactorialTestNumber = 6;
		for (int i=FactorialTestNumber; i>=1; i--)
			factorialTestData *= i;
		int  result = Factorial(FactorialTestNumber);
		if (factorialTestData == result)
			printf("Factorial Success! %d! = %d \n", FactorialTestNumber, result);
		else
			puts("Factorial Fail!");

	}
				  break;
	case BINARY_SEARCH_RECUR: {
		int* ar = init(NumberOfDS_Algo);
		int resultIdx = BSearchRecur(ar, 0, 4, 7);
		if (resultIdx == -1)
			printf("탐색 실패! \n");
		else
			printf("탐색 성공! find idx : = %d,  find value = %d \n", resultIdx, ar[resultIdx]);
	}
		break;
	case HANOI_TOWER: {
		HanoiTowerMove(3, 'A', 'B', 'C');
	}
		break;
	default:
		break;
	}
	printf("End of %s Example = %s 예제 끝 \n\n", DsAlgoStr[NumberOfDS_Algo].eName, DsAlgoStr[NumberOfDS_Algo].kName);
}

int Factorial(int n) {
// n! = n x (n-1) x ... x 1
	if (n == 1)
		return 1;
	if (n >= 2)
		return n * Factorial(n-1);

	return 0;
}

void HanoiTowerMove(int numOfDisk, char from, char by, char to) {
	if (numOfDisk == 1) {
		printf("원반1을 %c에서 %c로 이동. \n", from, to);
	}
	else {
		HanoiTowerMove(numOfDisk-1, from, to, by);
		printf("원반%d를 %c에서 %c로 이동.\n", numOfDisk, from, to);
		HanoiTowerMove(numOfDisk-1, by, from, to);
	}
}


void makeFibonacciSequence(int fiboArr[], const int length) {
	//int* fiboArr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		fiboArr[i] = Fibonacci(i);
	}
	//return fiboArr;
}
int Fibonacci(int n) { // 피보나치 수열의 n번째 항 구하는 함수
	//0,1,1,2,3,5,8,13,21
	// f(n) n==0 -> 0; n= =1 : 1, n>=2 : f(n)= f(n-2)+f(n-1)
	if (n == 0 || n == 1)
		return n;

	if (n >= 2)
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	return -1;
}

int* init(DS_Algo NumberOfDS_Algo) {
	static int ar[] = { 3, 4, 7, 11, 2 };
	return ar;
}
int BSearchRecur(int ar[], int first, int last, int target) {
	int mid = -1; // 찾지 못했을 때 반환 값
	if (first > last)
		return mid;

	mid = (first + last) / 2;
	if (ar[mid] == target) {
		return mid;
	}
	else {
		if (target < ar[mid]) {
			mid = BSearchRecur(ar, first, mid - 1, target);
		}
		else if (target > ar[mid]) {
			mid = BSearchRecur(ar, mid + 1, last, target);
		}
	}

	return mid;
}

// 두 배열의 동일 인덱스에 있는 원소가 같은지 확인하는 함수
bool equalArray(int a[], int b[], const int sizeA, const int sizeB) {
	if (sizeA != sizeB)
		return false;

	for (int i = 0; i < sizeA; i++)
	{
		if (a[i] != b[i])
			return false;

	}
	return true;
}
