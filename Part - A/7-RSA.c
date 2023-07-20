// Write a program for simple RSA algorithm to encrypt and decrypt the data.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a, int h)
{   while(1)
    {   int temp = a%h;
        if(temp==0)
            return h;
        a = h;
        h = temp;
    }
}

int powermod(int x,int m,int n){
  int y = 1;
  while(m>0){
    if(m%2==1)
       y = (y*x) % n;
    x = (x*x) % n;
    m = m/2;
  }
  return y;
}

 int main()
{   //e for encrypts(public key),d for decrypts(private key)
    int p,q,msg,e=2,d=e;
    printf("Enter two prime numbers:");
    scanf("%d%d",&p,&q);
    printf("Enter the messsage:");
    scanf("%d",&msg);
    int n=p*q,phi_of_n = (p-1)*(q-1);
    //for checking co-prime which satisfies e>1
    while(e<phi_of_n)
    {
        if(gcd(e,phi_of_n)==1)
            break;
        else
            e++;
    }
    //choosing d such that it satisfies d*e mod phi_of_n= 1 
    while(1)
    {
        if((d*e)%phi_of_n==1)
            break;
        else
            d++; 
    }
    //encrpyt and decrypt data and print
    int encrpted = powermod(msg,e,n);
    int decrypted = powermod(encrpted,d,n);
    printf("Message data =%d ",msg);
    printf("\np = %d",p);
    printf("\nq = %d",q);
    printf("\nn = pq = %d",n);
    printf("\nphi(n) = %d",phi_of_n);
    printf("\ne = %d",e);
    printf("\nd = %d ",d);
    printf("\nEncrypted data = %d",encrpted);
    printf("\nDecrypted data (from encrypted)=%d\n",decrypted);
}
