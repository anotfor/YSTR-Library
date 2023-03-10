unsigned int ystrlen(const char * str);
unsigned int ystrslen(const char * str, char ss);
unsigned int ystrlen_z(const char * str);
const char * ystrchr(const char * str, char cc);
int ystrcmp(const char * str1, const char * str2);
int _ystrstr(const char * str1, const char * str2);
const char * ystrstr(const char * str1, const char * str2);
char * ystrdel(char * str);
char * ystrndel(char * str, char s);
char * ystrncpy(char * dst, const char * src, size_t num);
char * ystrdup(const char * str);
const char * ystrsrh(const char * str1, const char * str2);
char * ystrcat(char * str1, const char * str2);
char * ystrrev(char * str);
char * ystrlswp(char * str);
char * ystrfswp(char * str);
int ystrlcmp(const char * str, int size);
char * ystrsdel(char * str);
char * ystrcaps(char * str);
char * ystrreg(char * str);
char * ystrnorm(char * str);
char * ystrsdup(const char * str);
char * ystrsscpy(char * dst, const char * src, size_t num);
char * ystrscut(char * str);
int ystrscnt(const char * str);
int ystrnscnt(const char * str, char sym);
char * ystrndup(const char * str, int entr);
int ystrslc(char * buf, const char * str, int index1, int index2);
char * ystrscat(const char * str1, const char * str2);
int ystrrep(char str[], char bef, char aft);
int ystrlhcmp(const char * str1, const char * str2);
int ystrtok(char buf[], char * str, int in, char ss);
