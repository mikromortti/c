int getLine(char s[], int lim) {

	int i, c;
	

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
		s[i] = c;
	}

	for (;i >= 0; i--) {
		if(s[i - 1] == '\t' || s[i - 1] == ' ') {
			s[i - 1] = '\0';
		} else {
			break;
		}
	}


	
	s[i] = '\0';
	return i;
}

int getOneLine(char s[], int lim) {

	int i, c;
	

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
		s[i] = c;
		if(c == '\n') {
			i++;
			break;
		}
	}

	for (;i >= 0; i--) {
		if(s[i - 1] == '\t' || s[i - 1] == ' ') {
			s[i - 1] = '\0';
		} else {
			break;
		}
	}


	
	s[i] = '\0';
	return i;
}

void detab(char s[], int n) {

int i = 0;
int k = 0;

while (s[i] != '\0') {
	if(k == n) {
		k = 0;
	}
	if(s[i] == '\t') {
		while(k < n) {
			printf(" ");
			k++;
		}
		i++;
		k = 0;
	} else {
		printf("%c", s[i]);
		i++;
		k++;	
	}


}

}

void fold(char s[], int n) {
	int lastBlank = -1;
	int pos = 1;
	int i;


	for(i = 0; s[i] != '\0'; i++, pos++) {
		if(s[i] == ' ' || s[i] == '\t') {
			lastBlank = i;
		} 
		// else if (s[i] == '\n') {
		// 	lastBlank = -1;
		// 	pos = 1;
		// } 
		if (pos >= n) {
			s[lastBlank] = '\n';
			pos = 1;
		}


	}

	pos = 1;

	for(int j= 0; s[j] != '\0'; j++, pos++) {
		if(s[j] == '\n') {
			pos = 0;
		}
		if(pos > n) {
			printf("\n");
			pos = 0;
		}
		printf("%c", s[j]);
	}

}



