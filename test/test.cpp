#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<cstdlib>
using namespace std;
int main()
{
char buff1[20], buff2[20];
int len, i=0, j=0, n;
pid_t pid;
int fd[2];
cout<<"\nEnter a string"<<endl;
cin>>buff1;
len = strlen(buff1);
pipe(fd);
pid = fork();
if(pid < 0)
{
cout<<"\nError in creating child process"<<endl;
exit(1);
}
if(pid == 0)
{
close(fd[0]);
write(fd[1], buff1, len+1);
while(buff1[i] != '\0')
{
i++;
}
i-- ;
for(j=0; j<len; j++, i-- )
{
buff2[j] = buff1[i];
}
buff2[j] = '\0';
cout<<"\nReverse String is: "<<buff2<<endl;
exit(0);
}
else
{
close(fd[1]);
n = read(fd[0], buff1, sizeof(buff1));
cout<<"\nReceived String is: "<<buff1<<endl;
cout<<"\nLength of String = "<<len<<endl;

}
return 0;
}
