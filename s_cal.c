#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define PI 3.14159265
#define one 0.0002
#define MAX 256

double result=0,save=0;
int frag=0;

void help(char * c);
void eatspase(char *c);
double func(char * c);
double modif(char * c);
int main(void){
    char c_put;
    int i=0; 

    system("clear");
    printf("\x1b[36m\x1b[40m");
    printf("##################################################\n");
    printf("#                                                #\n");
    printf("# Hello! Welcome to scientific calculator!!      #\n");
    printf("#                                                #\n");
    printf("# If this formula is empty,this proglam close !! #\n");
    printf("#                                                #\n");
    printf("# If you leave blank in formula,this calculator  #\n");
    printf("#                                     correct it.#\n");
    printf("#                                                #\n");
    printf("#   If you want to see help, you puress 'help'   #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
    printf("\n\n");
    printf("\x1b[m");
    while(1){
    char c[MAX]={0};
        i=0;
        printf(">>>>>>");
        scanf("%c",&c_put);
        while(c_put!='\n'){
            c[i++] = c_put;
            scanf("%c",&c_put);
        }
        c[i]='\0';
    result=0;
    eatspase(c);
    help(c);
    if(frag){
        frag=0;
        continue;
    }
    result=modif(c);
        if(!c[0]){
            system("clear"); 
    printf("\x1b[36m\x1b[4m");
    printf("\n\t\tbye!!\n\n");
    printf("\x1b[m");
            return 0;
        }
        printf("\x1b[33m\x1b[4m");
        printf("\t\t\t=%f\n\n",result);
        printf("\x1b[m");
        save=result;
        result=0; 
    }
}
void eatspase(char *c){
    int i = 0,j = 0;
    while((*(c+i)=*(c+j++))!='\0'){
        if(*(c+i)!=' '){
            i++;
        }
    }
    return;
}

double modif(char * c){
    double buffer=0;
    double ans=0,power=0;
    double set_k[80]={0};
    double exclamation=1;
    int i=0,p=0,k=0,o=0,x=0,put=0,fra=0,t=0,w=0,e=0,ki=0,frag_f=0;

    if(c[0]=='-'||c[0]=='+'||c[0]=='*'||c[0]=='/'||c[0]=='^'||c[0]=='!'){
        set_k[0]=c[0]+one;
        i++;
        p++;
        buffer=0;
    }
    while(c[i]!='\0'){
        if(isdigit(c[i])){
            buffer =buffer*10+c[i]-48;
            i++;
            if(c[i]=='.'){
                for(i=i+1;isdigit(c[i]);i++){
                    buffer=buffer*10+c[i]-48;
                    k++;
                }
            for(o=0;o<k;o++){
                buffer/=10;
            }
            }
         set_k[p]=buffer;
         k=0;
        }
        else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='^'||c[i]=='!'){     
            p++;
            buffer=0;           
            set_k[p]=c[i]+one;
            i++;
            buffer=0;
            if(c[i-1]!='!')
            p++;
        }
        else if(isupper(c[i])||islower(c[i])){ 
            while(isupper(c[i])||islower(c[i])){
            buffer+=c[i];
            i++;
            }
            set_k[p]=buffer+one;
            buffer=0;
            p++;
        }
        else{
            system("clear");
            printf("\x1b[41m\x1b[33m");
            printf("\t\t\t###################################\t\t\t\n");
            printf("\t\t\t#                                 #\t\t\t\n");
            printf("\t\t\t#                                 #\t\t\t\n");
            printf("\t\t\t#   This formula is not defined   #\t\t\t\n");
            printf("\t\t\t#                                 #\t\t\t\n");
            printf("\t\t\t#         bye !!                  #\t\t\t\n");
            printf("\t\t\t#                                 #\t\t\t\n");
            printf("\t\t\t###################################\t\t\t\n");
            printf("\x1b[m");
            printf("\n\n\n");
            exit(1);
        }
    }

    buffer=0.0; 
    while(set_k[x]!='\0'){
        if(set_k[x]=='s'+'i'+'n'+one){
            set_k[x]=sin(set_k[x+1]*PI/180);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];     
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';          
        } 
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='a'+'s'+'i'+'n'+one){
            set_k[x]=asin(set_k[x+1])/PI*180;
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];     
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';          
        } 
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='c'+'o'+'s'+one){
            set_k[x]=cos(set_k[x+1]*PI/180);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='a'+'c'+'o'+'s'+one){
            set_k[x]=acos(set_k[x+1])/PI*180;
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='t'+'a'+'n'+one){
            set_k[x]=tan(set_k[x+1]*PI/180);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;  
    while(set_k[x]!='\0'){
        if(set_k[x]=='a'+'t'+'a'+'n'+one){
            set_k[x]=atan(set_k[x+1])/PI*180;
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;  
    while(set_k[x]!='\0'){
        if(set_k[x]=='l'+'o'+'g'+one){
            set_k[x]=log10(set_k[x+1]);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='l'+'o'+'g'+'e'+one){
            set_k[x]=log(set_k[x+1]);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='s'+'q'+'r'+'t'+one){
            set_k[x]=sqrt(set_k[x+1]);
            fra++;
            for(put=x+2;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++)
                set_k[p-t]='\0';
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[x]=='!'+one){
            for(int pow=set_k[x-1];pow>0;pow--){
                exclamation=pow*exclamation;
            }
            set_k[x-1]=exclamation;
            fra++;
            for(put=x+1;set_k[put]!='\0';put++)
                set_k[put-1]=set_k[put];
            for(t=0;t<fra;t++){
                set_k[p-t]='\0';
            }
        }
        x++;
    }
    p=p-fra;
    fra=0;
    x=0;
    while(set_k[x]!='\0'){
        if(set_k[0]=='^'+one&&frag_f==0){
            x=1;
            frag_f=1;
        }
        if(set_k[x]=='^'+one){
            power = set_k[x-1];
            for(ki=1;ki<set_k[x+1];ki++)
                power=power*set_k[x-1];
            set_k[x-1]=power;
            fra++;
            for(put=x;put<=p;put++){
                set_k[put]=set_k[put+2];
                w=0;
            }
            if(w){
                x=0;
                w=0;
                continue;
            }
        }
        x++;
    }
    p=p-fra;
    fra=0;
    frag_f=0;
    x=0; 
    power=0;
    while(set_k[x]!='\0'){
        if(set_k[0]=='*'+one&&frag_f==0){
            x=1;
            frag_f=1;
        }
        if(set_k[x]=='*'+one){
            set_k[x-1]=set_k[x-1]*set_k[x+1];
            fra++;
            for(put=x;put<=p;put++){
                set_k[put]=set_k[put+2];
                w=1;
            }
            if(w){
                x=0;
                w=0;
                continue;
            }
        }
        x++;
    }
    p=p-fra;
    fra=0;
    frag_f=0;
    x=0;
    while(set_k[x]!='\0'&&frag_f==0){
        if(set_k[0]=='/'+one){
            x=1;
            frag_f=1;
        }
        if(set_k[x]=='/'+one){
            set_k[x-1]=set_k[x-1]/set_k[x+1];
            fra++;
            for(put=x;put<=p;put++){
                set_k[put]=set_k[put+2];
                w=1;
            }
            if(w){
                x=0;
                w=0;
                continue;
            }
        }
        x++;
    }
    p=p-fra;
    fra=0;
    frag_f=0;
    x=0; 

    if(set_k[0]=='+'+one||set_k[0]=='-'+one||set_k[0]=='*'+one||set_k[0]=='/'+one||set_k[0]=='^'+one||set_k[0]=='!'+one){
        x=1;
        e=1;
        ans=set_k[1];
    }
    else{
        ans=set_k[0];
        e=0;
    }
    while(set_k[x]!='\0'){
        if(set_k[x]=='+'+one)
            ans+=set_k[x+1];
        else if(set_k[x]=='-'+one)
            ans-=set_k[x+1]; 
        x++;
    }
    if(e==1){
        if(set_k[0]=='+'+one)
            ans=save+ans;
        else if(set_k[0]=='-'+one)
            ans=save-ans;
        else if(set_k[0]=='*'+one)
            ans=save*ans;
        else if(set_k[0]=='/'+one)
            ans=save/ans;
        else if(set_k[0]=='^'+one){
            power=save;
            for(ki=1;ki<ans;ki++)
                power=power*save;
            ans=power;
        }
            

    }
    return ans;
}
void help(char * c){
    char help_exit;
    if(c[0]=='h'&&c[1]=='e'&&c[2]=='l'&&c[3]=='p'){
        system("clear");
        printf("\x1b[40m\x1b[32m");
        printf("##################################\n");
        printf("#-How to ues function and others-#\n");
        printf("\x1b[4m");
        printf("#                                #\n");
        printf("\x1b[m\x1b[40m\x1b[32m");
        printf("#   Trigonometric function:      #\n"); 
        printf("#  e.g. cos60     =0.5           #\n");
        printf("#       sin30*2   =1.0           #\n");
        printf("#       asin0.5   =30.0          #\n");
        printf("\x1b[4m");
        printf("#                                #\n");
        printf("\x1b[m\x1b[40m\x1b[32m");
        printf("#   log:                         #\n");
        printf("#  e.g. log 1000  =3.0           #\n");
        printf("#       log e 10  =2.302585      #\n");
        printf("\x1b[4m");
        printf("#                                #\n");
        printf("\x1b[m\x1b[40m\x1b[32m");
        printf("#   etc:                         #\n");
        printf("#  e.g. 5!        =120.0         #\n");
        printf("#       2^3       =8.0           #\n");
        printf("#       sqrt4     =2.0           #\n");
        printf("\x1b[4m");
        printf("#                                #\n");
        printf("\x1b[m\x1b[40m\x1b[32m");
        printf("#   Continuous calculation:      #\n");
        printf("#  e.g. >>>2+3    =5.0           #\n");
        printf("#       >>>*2+1   =15.0          #\n");
        printf("#                                #\n");
        printf("#       (1/6)^3                  #\n");
        printf("#         |||||                  #\n");
        printf("#         vvvvv                  #\n");
        printf("#    >>>1/6       =0.166667      #\n");
        printf("#    >>>^3        =0.00463       #\n");
        printf("\x1b[4m");
        printf("#                                #\n");
        printf("\x1b[m\x1b[40m\x1b[32m");
        printf("##################################\n");
        printf("\x1b[m");
        printf("   \n\n<<--press enter to return two times-->>\n");
    while(help_exit!='\n')
        scanf("%c",&help_exit);
        getchar();
    
    if(help_exit=='\n'){
        system("clear");
    printf("\x1b[36m\x1b[40m");
    printf("##################################################\n");
    printf("#                                                #\n");
    printf("# Hello! Welcome to scientific calculatori!!     #\n");
    printf("#                                                #\n");
    printf("# If this formula is empty,this proglam close !! #\n");
    printf("#                                                #\n");
    printf("# If you leave blank in formula,this calculator  #\n");
    printf("#                                     correct it.#\n");
    printf("#                                                #\n");
    printf("#   If you want to see help, you puress 'help'   #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
    printf("\n\n");
    printf("\x1b[m");
    help_exit='\0';
        frag=1; 
    }
    }
}
