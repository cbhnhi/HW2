#include <stdio.h>
#include <sys/fcntl.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
int debug=1;
int handleSygnal(int argc,char*argv[]);
int main(int argc,char*argv[])
{
    handleSygnal(argc,argv);
}



int sendSignal(int type)
{

}

int handleSygnal(int argc,char*argv[])
{
    char * inputfile[80];
    char * buffer[2];
    char inputString[80];
    int P1,P2,P3,P4;
    int inputFd,check1;
    int i=0;
    sprintf(inputfile,"to_srv.txt");
    /*
    inputFd=open(inputfile,O_RDONLY);
    if(inputFd<0)
    {
        int fail=1;
        sendSignal(fail);//shouldnt happen i wouldnt have received the signal to activate without file
    }

    do{
        check1=read(inputFd,(void*)buffer,sizeof(char));
        inputString[i]=buffer[0];
        i++;
    }while(check1!=0);
    //now ive got the enire inputstring saved
    inputFd=remove(inputfile);
    */
    sprintf(inputfile,"0 2 1 -2");
     //sscanf(inputfile,"%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d",&P1,&P2,&P3,&P4);
    sscanf(inputfile,"%d %d %d %d",&P1,&P2,&P3,&P4);

    //now i have all 4 parameters
    if(debug)
    {
        printf("%d %d %d %d\n",P1,P2,P3,P4);
        getchar();
    }
    int result=0;
    switch(P3)
    {
        case 1:
        {
            if(debug)
            {
                printf("inside add\n");
                getchar();
            }
            //add
            result=P2+P4;
            if(debug)
            {
                printf("add successfull\n");
                getchar();
            }     
        }
        case 2:
        {
            if(debug)
            {
                printf("inside sub\n");
                getchar();
            }
            //sub
            result=P2-P4;
            if(debug)
            {
                printf("sub succesfull\n");
                getchar();
            }
        }
        case 3:
        {
            if(debug)
            {
                printf("inside mul\n");
                getchar();
            }
            //mul
            result=P2*P4;
            if(debug)
            {
                printf("mul succesfull\n");
                getchar();
            }
        }
        case 4:
        {
            if(debug)
            {
                printf("inside div\n");
                getchar();
            }
            //div
            result=P2/P4;
            if(debug)
            {
                printf("div succesfull\n");
                getchar();
            }
        }
        default:
        {
            if(debug)
            {
                printf("problem\n");
                getchar();
            }
            //problem
        }
    }
    //write result to file
    int success =2;
    sendSignal(success);
    //now need a cleanup massacre

    
}