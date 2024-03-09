#include<bits/stdc++.h>
#include<fstream>
#include<string.h>

using namespace std;

class date{public:
	int d, m, y;
};

class CompareString
{
public:
    string a;
    int l;
    int operator==(CompareString& b)
    {
        if(l!=(b.l))
		return 0;
	else{
		for(int i=0;i<b.l;i++){
			if(toupper(a[i])!=toupper(b.a[i]))
				return 0;
		}
	}
	return 1;
    }
};

inline int Search(char a[], char b[]){
//	if(strlen(a)!=strlen(b))
//		return 1;
//	else{
		for(int i=0;i<strlen(b);i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 1;
		}
//	}
	return 0;
}
