#include<stdio.h>
#include<math.h>

double sinn(double al){
    double a = sin(3.14159265/(180/al));return a;}
double cosn(double al){
    double a = cos(3.14159265/(180/al));return a;}
double tann(double al){
    double a = tan(3.14159265/(180/al));return a;}
int power_off =1;
double result = 0;
int main(void){
    //x2 necces
printf("\033[2J");printf("\033[2J");
printf("\033[37m");
printf("\033[5;10H");
printf("\r\033[003m####################################Function calculator################################\r\n");
           printf("#                                                                                     #\r\n");
printf("#                                                                                     #\r\n");
printf("#                   To quit:  >>>>\033[36mq<ENTER>\033[37m                                            #\r\n");
printf("#                   (.Ex   :  >>>>\033[36msin(30)+log(10)*-tan(-90)<ENTER>\033[37m                    #\r\n");
printf("#                          :  >>>>\033[36m+20-30*40/50<ENTER>\033[37m                                 #\r\n");
printf("#                                                                                     #\r\n");
printf("#                                                                                     #\r\n");
printf("#                                                                    @date 09-23-2017 #\r\n");
printf("#                                                                    @author 17C1084  #\r\n");
printf("#######################################################################################\n\n\n\n\n\n\n\n\n\n\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n");
printf("\033[m\033[93m");
    while(power_off){
char num[200]={'\0'};
double str[20][6]={'\0'};
double pow_num,mi,memory=0;
fprintf(stderr,"\033[93m>>>>");
scanf("%s",num);
if(num[0]=='q'){break;}
int minus=0;
int i,j,m,n,c,k_max;
int cnum=0;
j=1;
for(i=0;(num[i])!='\0';i++){
    if     (num[i]=='+'){
        str[j][1]=1;}
    else if(num[i]=='-'){
        str[j][1]=2;}
    else if(num[i]=='*'){
        str[j][1]=3;
        if(num[i+1]=='-'){
            minus=1;str[j+1][5]+=1;}
    }
    else if(num[i]=='/'){
        str[j][1]=4;}
        if(num[i+1]=='-'){
            minus=1;str[j+1][5]+=1;}

    if(str[j][1] != '\0'){
        //x    if(j!=0)
        str[j][4]+=i-1;
        str[j+1][3]+=i+1+minus;
        i += minus;
        minus=0;
        j++;
    }

    if(num[i]=='('){
        str[j][3] +=1;
        str[j][4] -=1;
        if(num[i-3]=='s'){str[j][6]=1;}
        else if(num[i-3]=='c'){str[j][6]=2;}
        else if(num[i-3]=='t'){str[j][6]=3;}
        else if(num[i-3]=='l'){str[j][6]=4;}
        if(str[j][6]!=0){str[j][3] +=3;}    
        if(num[i+1]=='-'){
            str[j][5] += 1;
            str[j][3] += 1;
            i++;
        }
    }

}
//str[j][4]+=i;
i--;//null ignore

if(num[i]==')'){i--;}
str[j][4]=i;
k_max = j;
//int cos_check=0;
for(m=1;m<=k_max;m++){
    for(n=str[m][3];n<=str[m][4];n++){
        pow_num = str[m][4]-n;
        memory += (num[n]-48) * pow(10,pow_num); 
    }
    minus =str[m][5];
    if((minus/-2) != 0){
   // if(str[m][5]==1){
        memory *= -1;}
    if(str[m][6]==1){memory = sinn(memory);}
    else if(str[m][6]==2){memory = cosn(memory);}
    else if(str[m][6]==3){memory = tann(memory);}
    else if(str[m][6]==4){memory = log10(memory);}
    str[m][0] = memory;
    memory=0;
    }

if(str[1][0]==0 ){str[1][0]=result;}
for(m=0;m<=k_max;m++){
    if(str[m][1]==3){
        str[m+1][0] = str[m][0] * str[m+1][0];
        str[m][2] = 1;}
    else if(str[m][1]==4){
        str[m+1][0] = str[m][0] / str[m+1][0];
        if(str[m+1][5]==1){
            str[m+1][0]*=-1;}
        str[m][2] = 1;}
}

str[0][1]=1;
str[0][2]=1;
str[k_max][2]=0;
if(str[1][0]!=0){result=0;}
//result = str[k_max][0];
for(m=0;m<=k_max;){
    if(str[m][1]==1){
        m++;
        if(str[m][2]==1){
            for(m++;str[m][2]!=0;m++){}
        }
        result += str[m][0];
    }else if(str[m][1]==2){
        m++;
        if(str[m][2]==1){
            for(m++;str[m][2]!=0;m++){}
        }
        result -= str[m][0];
    }else {m++;}
    
}
//result = result + str[k_max][0];
//printf("\033[2L\r>>>>");
//printf("\033[36m");
fprintf(stderr,"\033[4M\r>>>>\033[36m%lf\033[93m\r\n",result);
//printf("\033[93m");
}
//printf("\033[2J\r\n");
}
