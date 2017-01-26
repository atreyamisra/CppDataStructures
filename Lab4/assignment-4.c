

#define FALSE 0
#define TRUE 1



/************************************************************/
/* This function is called by the 'match' function.
If the passed character is one of the base set (a,c,g, or t), it 
 returns 1, else it returns 0.
*/
/************************************************************/
int isBase( char c ) {
	if( (c == 'a') || (c =='c') || (c == 'g') || (c == 't') ){
		return 1;
	}

	return 0;
}

int length(char *stringer) {
	int a = 0;
	int lengthofstring = 0;
	while (*stringer != 0) {
		lengthofstring = a + 1;
		*stringer++;
		a++;
	}
	return lengthofstring;
}

/************************************************************/
/************************************************************/
/* 
This is a recursive function that returns 1 if the string s matches 
 the ME string r. It returns 0 otherwise.
You need to implement the following logic in this function:

1. If length(r)=length(s)=0, they match: return 1.

2. If length(r)=length(s)=1, then r matches s only if either r is '.' 
 (which matches any character), or the same character as s.

3. If length(r) > 1, then r can match s in one of these cases:

   a) If r[0] is a base character that matches s[0], and r[1] is a 
    base character or a '.', then r and s match only if r[1..end] 
    matches s[1..end] (checked by a recursive call to match).

   b) If r[0] is a base character, and r[1] is '*', then r matches s 
    only if s is composed as follows:
        0 or more occurences of r[0], followed by a string that matches 
        r[2..end]. This can be checked by calling match recursively for 
        each possible suffix of s.

   c) If r[0] is '.' and r[1]!='*', then unless s is empty, r and s match 
    only if r[1..end] matches s[1..end] (checked by a recursive call to 
    match).
   
   d) If r[0] is '.' and r[1]='*', r and s match if any suffix of s 
    matches r[2:end].
*/

int match( char *s, char *r ) {
	int lengths = length(s);
	int lengthr = length(r);
//	printf("length of s=%d\n", lengths);
//	printf("length of r=%d\n", lengthr);
	int x = 0;
	if (lengthr == 0) {
		if (lengths == 0) {
			goto yes;
			}
		else {
			goto no;
			}	
	}
	if (lengthr == 1) {
		if (lengths == 1) {
			if (s == r) {
				goto yes;
			}
			else {
				if (r == ".") {
					goto yes;
				}
				else {
					goto no;
				}
			}
		}
		else {
			goto no;
		}
	}
	if (lengthr> 1) {
		int j = 0;
		int i = 0;

		for (i; i <= lengthr; i++) {
//			printf("%c\n", r[i]);
//			printf("%c\n", s[j]);
			if (r[i] == s[j]) {}
			else {
				if (r[i] == '.') {
					if (r[i] == '.' && r[i+1] == '*') {
						i = i + 2;
						j = lengths - (lengthr - (i-2));
					}
					else {
						goto next;
					}
				}
				else {
					if (r[i] == '*') {
						int x = 1;
						while (x == 1) {
								if (r[i-1] == s[j]) {
									j++;
								}
								else {
									x = 0;
								}
							
						}
						j = j - 1;
					}
					else {
						if(i+1==lengthr){
							goto no;
						}
						else {
							j--;
						}
					}
				}
			}
			next:
			j++;
		}
	}
yes:
return 1;
no:
return 0;
}
/************************************************************/
/************************************************************/
