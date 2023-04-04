#include <iostream>
using namespace std;


// ����1) ���ڿ� ���̸� ����ϴ� �Լ�
int StrLen(const char* str)
{
	// str ���ڿ� ���� ��ȯ
	int count = 0;

	while (true)
	{
		if (str[count] == '\0')
			break;

		count++;
	}
	
	return count;
}

// ����2) ���ڿ� ���� �Լ�
char* StrCpy(char* dest, char* src)
{
	// 1) �迭 ���
	/*int count = 0;
	
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	
	dest[count] = '\0';
		
	return dest;*/

	// 2) ������ ���
	// �迭 �ʱ� ��ġ��
	char* ret = dest;

	while (*src != '\0')
	{
		 *dest = *src;
		 dest++;
		 src++;
	}
	
	*dest = '\0';

	return ret; // ��ȯ���� �迭�� �ʱ� ��ġ��
	
}

// ����3) ���ڿ��� �����̴� �Լ�
char* StrCat(char* dest, char* src)
{
	// 1) �迭 ���
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

	// 2) ������ ���
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


#pragma warning(disable: 4996) // 4996 ���� ����

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][][][][][][][][][][][]
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];
	char c[BUF_SIZE] = "World";


	int len = strlen(a); // strlen()�� '\0'�� ���ڿ� ������ ��� X
	
	int len2 = sizeof(a);
	int len3 = StrLen(a);


	cout << len << endl;
	cout << len2 << endl;
	cout << len3 << endl;

	// ���ڿ� ���� �Լ�
	strcpy(b, a); // ���� �����÷ο� ����! 
	strcpy_s(b, a); // ���� ����
	StrCpy(b, a);
	cout << b << endl;
	//strcat(a, c); // a���ڿ��� c���ڿ��� �̾���� �� a�� ����
	//cout << a << endl;

	StrCat(a, c);
	cout << a << endl;        
	return 0;
}