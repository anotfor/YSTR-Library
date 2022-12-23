#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ystrlen(const char * str) {
	int cyc;
	for(cyc = 0;; cyc++) {
		if(str[cyc] == 0) {
			//printf("%i", cyc); can print
			break;
		}
	}
	return cyc;
}

int ystrslen(const char * str) {
	int cyc;
	for(cyc = 0;; cyc++) {
		if(str[cyc] == 0 || str[cyc] == ' ') {
			//printf("%i", cyc); can print
			break;
		}
	}
	return cyc;
}

const char * ystrchr(const char * str, char cc) {
	int cyca; // cycle a
	for(cyca = 0;; cyca++)  {
		if(str[cyca] == cc) {
			return str+cyca;
		}
		if(str[cyca] == 0) {
			break;
		}
	}
	return 0;
}

int ystrcmp(const char * str1, const char * str2) { 
	int c1; // count 1
	for(c1 = 0;; c1++) {
		if((str1[c1]==0) || (str2[c1] == 0)) {
			return 0;
		} else if(str1[c1] < str2[c1]) {
			return -1;
		} else if(str1[c1] > str2[c1]) {
			return 1;
		} else if(str1[c1] == str2[c1]) {
			continue;
		}
	}
}


//compare strings until str2 ends
//if strict and str2 ended - return 1, otherwise 0
//that is, the string is unlimited or ended first with 1 string - then 0
int _ystrstr(const char * str1, const char * str2) { 
	for(int i1 = 0;; i1++) {
		if(str2[i1] == 0) {
			return 1;
		}
		if(str1[i1] == 0) {
			return 0;
		}
		if(str1[i1] != str2[i1])  {
			return 0;
		}
	}
}

const char * ystrstr(const char * str1, const char * str2) { 
	for(int c1 = 0;str1[c1]!=0; c1++) {
		if(_ystrstr(&str1[c1], str2) == 1) {
			return str1+c1;
		}
	}
	return 0;
}

char * ystrdel(char * str) {
	char sym[] = " \n\t\v\f\a";
	for(int jj = 0; str[jj] != '\0'; jj++) {
		for(int ii = 0; ii < 4; ii++) {
			if(str[jj] == sym[ii]) {
				str[jj] = '\07';
			}
		}
	}
	return str;
}

char * ystrndel(char * str, char s) {
	for(int jj = 0; str[jj] != '\0'; jj++) {
		if(str[jj] == s) {
			str[jj] = '\07';
		}
	}
	return str;
}

char * ystrncpy(char * dst, const char * src, size_t num) {
	for(int ct = 0;; ct++) {
		dst[ct] = src[ct];
		num--;
		if(num == 0) {
			break;
		}
		if(src[ct] == 0) {
			break;
		}
	}
	return dst;
}

char * ystrdup(const char * str) {
	int entr = ystrlen(str)+1;
	char * ss = malloc(entr);
	ystrncpy(ss, str, entr);
	return ss;
}

char * ystrndup(const char * str, int entr) {
	char * ss = malloc(entr+1);
	ystrncpy(ss, str, entr);
	ss[entr]=0;
	return ss;
}

const char * ystrsrh(const char * str1, const char * str2) {
	for(int cc = 0;	0 != str1[cc]; cc++) {
		for(int cc2 = 0; 0 != str2[cc2]; cc2++) {
			if(str1[cc] == str2[cc2]) {
				return &str1[cc];
			}
		}
	}
	return 0;
}
char * ystrcat(char * str1, const char * str2) {
	int lstr1 = ystrlen(str1);
	int lstr2 = ystrlen(str2);
	str1 = realloc(str1, lstr1+lstr2+10);
	int cc;
	for(cc = 0; str1[cc] != 0; cc++) {
		;
	}
	for(int cc2 = 0; str2[cc2] != 0; cc2++) {
		str1[cc++] = str2[cc2];
	}
	return str1;
}

char * ystrrev(char * str) {
	int ssize = ystrlen(str);
	char tmp[ssize+1];
	int step, step2;
	for(step = 0; step<ssize; step++) {
		tmp[step] = str[step];
	}
	step--;
	for(step2 = 0; step2<ssize; step2++, step--) {
		str[step2] = tmp[step];
	}
	return str;
}       

char * ystrlswp(char * str) {
	int n = ystrlen(str);
	char tmp[n+1];
	for(int step = 0; step<n; step++) {
		tmp[step] = str[step];
	}
	for(int step2 = 0; step2<n; step2++) {
		str[step2] = tmp[step2+1];
	}
	str[n-1] = tmp[0]; // n symbol = \0, n-1 = last sym because "STR" = "STR\0" (\0 = 1 symbol)
	return str;
}

char * ystrfswp(char * str) {
	int n = ystrlen(str);
	char tmp[n+1];
	for(int step = 0; step<n; step++) {
		tmp[step] = str[step];
	}
	for(int step2 = 0; step2<n; step2++) {
		str[step2] = tmp[step2-1];
	}
	str[0] = tmp[n-1]; // n symbol = \0, n-1 = last sym because "STR" = "STR\0" (\0 = 1 symbol)
	return str;
}

int ystrlcmp(const char * str, int size) {
	int n = ystrlen(str);
	if(n<size) {
		return -1;
	} else if(n == size){
		return 0;
	} else if(n>size) {
		return 1;
	} else {
		return 2;
	}
}

char * ystrsdel(char * str) {
	int n = ystrlen(str);
	for(int ii=n-1; ii; ++ii) {
		if(' '!=str[ii])		break;
		str[ii]= 0;
	}
	for(;' '== *str;++str)		(void)0;
	return str;
}

char * ystrcaps(char * str) {
	char symcaps[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char symreg[] = "abcdefghigklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	for(int ii = 0; str[ii] != 0; ii++) {
		for(int jj = 0; symreg[jj] != 0; jj++) {
			if(str[ii] == symreg[jj]) {
				str[ii] = symcaps[jj];
			}
		}
	}
	return str;
}

char * ystrreg(char * str) {
	char symcaps[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char symreg[] = "abcdefghigklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	for(int ii = 0; str[ii] != 0; ii++) {
		for(int jj = 0; symcaps[jj] != 0; jj++) {
			if(str[ii] == symcaps[jj]) {
				str[ii] = symreg[jj];
			}
		}
	}
	return str;
}

char * ystrnorm(char * str) {
	char symcaps[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	char symreg[] = "abcdefghigklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	for(int ii = 0; str[ii] != 0; ii++) {
		for(int jj = 0; symcaps[jj] != 0; jj++) {
			if(str[0] == symreg[jj]) {
				str[0] = symcaps[jj];
				continue;
			}
			if(str[ii] == symcaps[jj]) {
				str[ii] = symreg[jj];
			}
		}
	}
	return str;
}

char * ystrsscpy(char * dst, const char * src, size_t num) {
	for(int ct = 0;; ct++) {
		dst[ct] = src[ct];
		num--;
		if(num == 0) {
			break;
		}
		if(src[ct] == 0) {
			break;
		}
		if(src[ct] == ' ') {
			break;
		}
	}
	return dst;
}

char * ystrsdup(const char * str) {
	int entr = ystrslen(str)+1;
	char * ss = malloc(entr);
	ystrsscpy(ss, str, entr);
	return ss;
}

char * ystrscut(char * str) {
	for(int x = 0; str[x] == 0; x++) {
		str[x] = '\07';
		if(str[x] == ' ') {
			str[x] = '\07';
			break; 
		}
	}
	return str;
}

int ystrscnt(const char * str) {
	int jj = 1;
	for(int ii = 0; str[ii] == 0; ii++) {
		if(str[ii] == ' ') {
			jj++;
		}
	}
	return jj;
}

