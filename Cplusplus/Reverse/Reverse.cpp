#include <bits/stdc++.h>
using namespace std;

void reverse(char* s) {
	int l = 0;
	int r = strlen(s) - 1;
	while (l < r) {
		int temp = s[l];
		s[l] = s[r];
		s[r] = temp;
		l++;
		r--;
	}
}

int strlen(char *s){
	int count = 0;
	while(*s){
		s++;
		count++;
	}
	return count;
}

void m_strcopy(char *src, char *des){
	while (*src != '\0' && *des != '\0'){
		*des = *src;
		src++; des++;
	}
}



/*void reverse(char *s){
	char ch = *s;
	if(isalpha(ch)){
		reverse(s+1);
		cout << ch;
	}
	return;
}*/

void m_strcat(char *s1, char *s2, char *tmp){
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i < len1; i++){
		tmp[i]= *s1++;
	}
	for (int j = 0; j < len2; j++){
		tmp[len1 + j] = *s2++;
	}
}

int m_strcmp(char *s1, char *s2) {
	while (*s1 == *s2) {
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		char s[31];
		cin >> s;
		cout << strlen(s) << endl;
		reverse(s);
		cout << s << endl;
		char d[strlen(s)];
		m_strcopy(s, d);
		string str(d);
		cout << str << endl;
		char s1[] = "abc";
		char s2[] = "xyz";
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		char tmp[len1+len2];
		m_strcat(s1,s2, tmp);
		cout << tmp << endl;
		cout << m_strcmp(s1,s2) << endl;
	}
}
