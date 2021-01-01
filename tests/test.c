
void good(int aa, int bb)
{
    printf("%c, %d\n", aa, bb);
    int d = bb;
    good(aa / 2, bb / 2);
    return 0;
}

int main() {
int s;
int a[5][5], c;
a[0][1] = -10;
a[3][1] = 5;
c = a[1][1];
s = 0;
char ch;
scanf("%c", ch);
int b = 10;
printf("%c\n", ch);
// printf("result is: %d\n", a.a[0]);
while(a[0][1]>0 && (s < 20 || s % 100 == 99)) {
if(a[0][1] > 0)
{
    printf("good! then\n");
    }
a[0][1] = a[0][1] - 1;
printf("result is: %d\n", a[0][1]);
good(1, 2);
int i;
int b = 10;
for(i=0; i < b; i = i + 1) {
printf("Have fun: %d\n", i);
}
}
return 0;
}