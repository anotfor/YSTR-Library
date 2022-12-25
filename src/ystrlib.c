#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int ystrlen(const char * str) {
	int cyc;
	for(cyc = 0;; cyc++) {
		if(str[cyc] == '\0') {
			//printf("%i", cyc); can print
			break;
		}
	}
	return cyc;
}

unsigned int ystrlen_z(const char * str) {
	int cyc;
	for(cyc = 0;; cyc++) {
		if(str[cyc] == '\0') {
			//printf("%i", cyc); can print
			++cyc;
			break;
		}
	}
	return cyc;
}

unsigned int ystrslen(const char * str, char ss) {
	int cyc;
	for(cyc = 0;; cyc++) {
		if(str[cyc] == '\0' || str[cyc] == ss) {
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
		if(str[cyca] == '\0') {
			break;
		}
	}
	return 0;
}

int ystrcmp(const char * str1, const char * str2) {
	int c1; // count 1
	for(c1 = 0;; c1++) {
		if((str1[c1]=='\0') || (str2[c1] == '\0')) {
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

int ystrlhcmp(const char * str1, const char * str2) {
    unsigned int len1 = ystrlen_z(str1);
    unsigned int len2 = ystrlen_z(str2);
    if(len1 < len2) {
        return -1;
    } else if(len1 > len2) {
        return 1;
    } else {
        return 0;
    }
}

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

int ystrrep(char str[], char bef, char aft) {
    int x = 0;
    for(; str[x] != '\0'; x++) {
        if(str[x] == bef) {
            str[x] = aft;
        }
    }
    return 0;
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

char * ystrscat(const char * str1, const char * str2) {
	int lstr1 = ystrlen(str1);
	int lstr2 = ystrlen(str2);
	char *str3 = malloc(lstr1+lstr2+1);
	int cc;
	for(cc = 0; str1[cc] != 0; cc++) {
		str3[cc] = str1[cc];
	}
	for(int cc2 = 0; str2[cc2] != 0; cc2++) {
		str3[cc++] = str2[cc2];
	}
	str3[cc] = '\0';
	return str3;
}

char * ystrcat(char * str1, const char * str2) {
	int lstr1 = ystrlen(str1);
	int lstr2 = ystrlen(str2);
	str1 = realloc(str1, lstr1+lstr2+1);
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

int ystrlcmp(const char * str, unsigned int size) {
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

char * ystrsdup(const char * str, char sl) {
	int entr = ystrslen(str, sl)+1;
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

char * ystrsscut(char * str1, const char * str2) {
    for(int x = 0; str1[x] != '\0'; x++) {
        for(int y = 0; str2[y] != '\0'; y++) {
            if(str1[x] == str2[y]) {
                str1[x] = '\07';
            }
        }
    }
    return 0;
}

int ystrscnt(const char * str) {
	int jj = 0;
	for(int ii = 0; str[ii] == 0; ii++) {
		if(str[ii] == ' ') {
			jj++;
		}
	}
	return jj;
}

int ystrnscnt(const char * str, char sym) {
	int jj = 0;
	for(int ii = 0; str[ii] == 0; ii++) {
		if(str[ii] == sym) {
			jj++;
		}
	}
	return jj;
}

int ystrslc(char * buf, const char * str, int index1, int index2) {
    for(int x = index1; x<index2; x++) {
        buf[x-index1] = str[x];
    }
    return 0;
}

int ystrtok(char buf[], char * str, int in, char ss) {
    int c = 0;
    int c2 = 0;
    for(int x = 0; 0 != str[x]; x++) {
        if(str[x] == ss) {
            ++c;
        }
        if(in == c) {
            for(int y = x;; y++, c2++) {
                buf[c2] = str[y];
                if(buf[0] == ss) {
                   ++y;
                   buf[c2] = str[y];
                }
                if(buf[c2] == '\0') {
                    return 0;
                }
                if(str[y] == ss) {
                    buf[c2] = '\0';
                    return 0;
                }
            }
        }
    }
    return 0;
}
