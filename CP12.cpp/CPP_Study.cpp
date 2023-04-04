#include <iostream>
using namespace std;


// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str)
{
	// str 문자열 길이 반환
	int count = 0;

	while (true)
	{
		if (str[count] == '\0')
			break;

		count++;
	}
	
	return count;
}

// 문제2) 문자열 복사 함수
char* StrCpy(char* dest, char* src)
{
	// 1) 배열 방식
	/*int count = 0;
	
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	
	dest[count] = '\0';
		
	return dest;*/

	// 2) 포인터 방식
	// 배열 초기 위치값
	char* ret = dest;

	while (*src != '\0')
	{
		 *dest = *src;
		 dest++;
		 src++;
	}
	
	*dest = '\0';

	return ret; // 반환값은 배열의 초기 위치값
	
}

// 문제3) 문자열을 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
	// 1) 배열 방식
	/*int count = strlen(dest);

	int i = 0;

	while (src[i] != '\0')
	{
		dest[count] = src[i];
		count++;
		i++;
	}

	dest[count+1] = '\0';

	return dest;*/

	// 2) 포인터 방식
	char* ret = dest;

	while (*dest != '\0')
		dest++;
	
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return ret; 
}


#pragma warning(disable: 4996) // 4996 에러 무시

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][][][][][][][][][][][]
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];
	char c[BUF_SIZE] = "World";


	int len = strlen(a); // strlen()은 '\0'은 문자열 개수로 취급 X
	
	int len2 = sizeof(a);
	int len3 = StrLen(a);


	cout << len << endl;
	cout << len2 << endl;
	cout << len3 << endl;

	// 문자열 복사 함수
	strcpy(b, a); // 버퍼 오버플로우 주의! 
	strcpy_s(b, a); // 권장 버전
	StrCpy(b, a);
	cout << b << endl;
	//strcat(a, c); // a문자열에 c문자열을 이어붙인 후 a에 저장
	//cout << a << endl;

	StrCat(a, c);
	cout << a << endl;        
	return 0;
}