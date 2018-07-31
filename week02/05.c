if (a){
    return b
} else {
    return c
}
a ? b : c
-------------------
ch = getchar();
if (isdigit(ch))
    type = "digit";
else
    type = "non-digit";
printf("'%c' is a %s\n", ch, type);
--------------------
char ch;
char *type;
ch = getchar();
type = isdigit(ch) ? "digit" : "non-digit"
printf("'%c' is a %s\n", ch, type);
