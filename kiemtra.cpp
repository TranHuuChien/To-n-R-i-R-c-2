#include<iostream>
#include<cstring>
using namespace std;
void ChuanHoa(char *s)
		{
			while(s[0]==' ') strcpy(&s[0],&s[1]);
			do{
				s[strlen(s)-1] = '\0';
			}while(s[strlen(s)-1]==' ');
			for(int i = 0 ; i < strlen(s)- 1; i++)
			{
				if(s[i]==' '&& s[i+1]==' ')
				{
					strcpy(&s[i],&s[i+1]);
					i--;
				}
			}
		
		for(int i = 0 ; i < strlen(s);i++)
				{
					s[i]= tolower(s[i]);
				}
		s[0] = toupper(s[0]);
		for(int i = 0 ; i < strlen(s);i++)
		{
			if(s[i]==' '&& s[i+1]!=' ')
			{
				s[i+1] = toupper(s[i+1]);
			}
		}
    }
void xoakhoangtrang(char *s)
		{
			while(s[0]==' ') strcpy(&s[0],&s[1]);
//			do{
//				s[strlen(s)-1] = '\0';
//			}while(s[strlen(s)-1]==' ');
			while(s[strlen(s)-1]==' ')
			{
				strcpy(&s[strlen(s)-1],&s[strlen(s)]);
			}
			for(int i = 0 ; i < strlen(s)-1; i++)
			{
				if(s[i]==' '&& s[i+1]==' ')
				{
					strcpy(&s[i],&s[i+1]);
					i--;
				}
			}
		}
int main()
{
    int a = 1;
	switch (a)
	{
	case 1:
		cout<<"ket qua la mot";
	case 2:
		cout<<"ket qua la 2";
		break;
	default:
		break;
	}
}