int main(){
    int num;
    int Onum, num1, num2, num3;
    scanf("%d", &num);
    scanf("%d", &Onum);
    num1 = Onum / 100;
    num2 = Onum / 10 % 10;
    num3 = Onum % 10;
    printf("%d\n", num*num3);
    printf("%d\n", num*num2);
    printf("%d\n", num*num1);
    printf("%d", num*Onum);
}