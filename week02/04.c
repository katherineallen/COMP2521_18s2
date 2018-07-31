assert(islower(ch));
switch (ch) {
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
	printf("vowel"); break;
default:
	printf("consonant"); break;
}