#include<iostream>
using namespace std;
void move(int n,char origin,char destination)
{
    cout<<"move disk["<<n<<"] from"<<origin<<"to"<<destination<<endl;
}
void hannoi(int n,char origin,char destination,char helper)
{
    if(n==1)
    {
        // printf("n==1 time ");
        move(1,origin,destination);
        
    }
    else{
        hannoi(n-1,origin,helper,destination);
        move(n,origin,destination);//3
        // // printf("move time");
        hannoi(n-1,helper,destination,origin);
    }
}

int main()
{
    hannoi(3,'A','B','C');
    return 0;
}