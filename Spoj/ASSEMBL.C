#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char buffer[100];
char *regi[]={"AREG","BREG","CREG","DREG","EREG",""};

int op_cnt,lit_cnt,sym_cnt,pool_cnt;
int ADDRESS;
int ACT_ADDR;
int temp_cnt = 0;
FILE *File,*fout,*target_file;

struct{
  char opcode[10] , opclass[10] , info[10];
  int length;
}op_tab[100];

struct{
  char symbol[10];
  int address , length,act_address;
}sym_tab[100];

struct{
 char literal[10];
 int address,act_address;
}lit_tab[100];

struct{
  int data,reg,address,ins;
}tb[100];

int pool_tab[100];
char generated[100];

void ins_op(char *opcode,char *opclass,char *info,int length){
	 strcpy(op_tab[op_cnt].opcode,opcode);
	 strcpy(op_tab[op_cnt].opclass,opclass);
	 strcpy(op_tab[op_cnt].info,info);
	 op_tab[op_cnt].length = length;
	 op_cnt++;
}

int isreg(char *temp){
     int i = 0;
     for( i = 0;regi[i][0];i++) if(!strcmp(regi[i],temp)) return i;
     return -1;
}

void construct_op_table(){
	 //Imperative Statements
	 ins_op("STOP" , "IS" , "(01,1)" , 1);
	 ins_op( "ADD" , "IS" , "(02,1)" , 2);
	 ins_op( "SUB" , "IS" , "(03,1)" , 2);
	 ins_op("MULT" , "IS" , "(04,1)" , 2);
	 ins_op("MOVER", "IS" , "(05,1)" , 2);
	 ins_op("MOVEM", "IS" , "(06,1)" , 2);
	 ins_op("COMP" , "IS" , "(07,1)" , 2);
	 ins_op( "BC"  , "IS" , "(08,1)" , 2);
	 ins_op( "DIV" , "IS" , "(09,1)" , 2);
	 ins_op("READ" , "IS" , "(10,1)" , 1);
	 ins_op("PRINT", "IS" , "(11,1)" , 1);
	 //Assembler Directives
	 ins_op("START", "AD" , "R#1", 1);
	 ins_op( "END" , "AD" , "R#2", 1);
	 ins_op("ORIGIN", "AD" , "R#3", 1);
	 ins_op( "EQU" , "AD" , "R#4", 1);
	 ins_op("LTORG", "AD" , "R#5", 1);
	 ins_op("EQU" ,  "AD" , "R#6" , 1);
	 //Declarative Statements
	 ins_op("DS" , "DL" , "R#6" ,1);
	 ins_op("DC" , "DL" , "R#7" ,1);
	 ins_op( ""  ,  ""  ,  ""   ,0);
}

int load_line(){
	 char c;
	 int pos = 0;
	 while( !feof(File) ){
	   c = fgetc(File);
	   if(c == '\n') break;
	   else {
		if( c == '\t') c=' ';
		buffer[pos++] = c;
		}
	 }
	 buffer[pos] = '\0';
	 if( pos ) return 1;
	 else return 0;
}

int remo(int start){
	while( buffer[start] && buffer[start] == ' ' ) start++;
	return start;
}

int get_word(char *token,char *buffer,int start){
	 int pos = 0;
	 start = remo(start);
	 while( isalnum(buffer[start]) ){
             token[pos++] = buffer[start++];
     }
	 token[pos] = '\0';
	 return start;
}

int get_expr(char *token,int start){
	 int pos = 0;
	 start = remo(start);
	 while(start<strlen(buffer) && buffer[start] && buffer[start]!=',') token[pos++] = buffer[start++];
	 token[pos] = '\0';
	 return start;
}

int sym_tab_find(char *token){
	int i = 0;
	for(i = 0;op_tab[i].opcode[0]; i++)
	 if( !strcmp(op_tab[i].opcode,token) ) return i;
	return -1;
}
int tonum(char *token);
int ins_sym(char *token);
int target_flag = 0,tcnt = 0;

int eval_main(char *str){
   int i = 0;
   int val = 0,val1 =0;
   int plus = 0;
   while(str[i] && !(str[i]>='0' && str[i]<='9')) if(str[i++]=='+') plus =1;
   while(str[i] && str[i]>='0' && str[i]<='9') val = val*10+(str[i]-'0'),i++;
   while(str[i] && !(str[i]>='0' && str[i]<='9')) if(str[i++]=='+') plus =1;
   while(str[i] && str[i]>='0' && str[i]<='9') val1 = val1*10+(str[i]-'0'),i++;
   if(plus) return sym_tab[val].act_address+val1 ;
   else return sym_tab[val].act_address-val1 ;

}

void generate_ic(char *str,char *buff){
	 int i = 0;
	 int pos = 0;
	 buff[0]='\0';
	 //Check for any literal
	 if(str[0]=='='){
		 int flag = 0,i;
		 for(i=0;i<lit_cnt;i++) if(!strcmp(lit_tab[lit_cnt].literal,str)){ flag=1;break;}
		 if(!flag){
		   pos += sprintf(buff+pos,"(L,%2d) ",lit_cnt+temp_cnt);
		   temp_cnt++;
		 }
		 else  pos += sprintf(buff+pos,"(L,%2d) ",i);
		 return;
	 }

	 while(i<strlen(str)){
	 char token[100];
	  while(str[i] && !isalnum(str[i])) buff[pos++] =str[i++];
	  i = get_word(token,str,i);
	 // i++;
	  if(token[0]>='0' && token[0]<='9'){
		int num = tonum(token);
		pos += sprintf(buff+pos,"(C,%02d) ",num);return;
	  }
	  else {
	   int temp = isreg(token);
	   if(temp<0){
	   int temp = ins_sym(token);
	   pos += sprintf(buff+pos,"(S,%02d) ",temp);
	   if(target_flag) tb[tcnt].data = temp;
	   }
	   else {
	     pos += sprintf(buff+pos,"(%02d)",temp+1);
	     if(target_flag) tb[tcnt].reg = temp+1;
	     }
	  }
	 }
	 return;
}

int ins_sym(char *token){
	 int i = 0;
	 for( i = 0;i < sym_cnt; i++){
		if(!strcmp(sym_tab[i].symbol,token)) return i;
	 }
	 strcpy(sym_tab[sym_cnt].symbol,token);
	 sym_tab[sym_cnt].address = ADDRESS;
	 sym_tab[sym_cnt].act_address = ACT_ADDR;
	 sym_tab[sym_cnt].length = 1;
	 sym_cnt++;
	 return sym_cnt-1;
}

int tonum(char *token){
   int i = 0;
   int ret = 0;
   if(token[i]=='\'') return 1;
   while( token[i] && !( token[i] >= '0' && token[i] <= '9') ) i++;
   while( token[i] && token[i] >= '0' && token[i] <= '9'){
	  ret = ret*10 + (token[i]-'0');
	  i++;
   }
   return ret;
}

int LTORG = 0;

void extract_ad(char *label,int pos,int start){
	 char token[100];

	 if(!strcmp(op_tab[pos].opcode,"START")){
		int temp;
		start = get_expr(token,start+1);
		temp = tonum(token);
		fprintf(fout,"(AD,%02d)",ADDRESS,pos+1);
		fprintf(fout," (C,%d) \n",temp);
		ADDRESS = temp-1;
		ACT_ADDR = temp;
	 }
	 if(!strcmp(op_tab[pos].opcode,"ORIGIN")){
		char buff[100];
		start = get_expr(token,start+1);
		generate_ic(token,buff);
		fprintf(fout,"%d (AD,%02d)",ADDRESS,pos+1);
		fprintf(fout," %s \n",buff);
		ACT_ADDR = eval_main(buff);
	 }
	 if(!strcmp(op_tab[pos].opcode,"LTORG")){
		  pool_tab[pool_cnt] = lit_cnt;
		  LTORG = 1;
	 }
	 if(!strcmp(op_tab[pos].opcode,"EQU")){
		int lab_pos = ins_sym(label);char buff[100];
		sym_tab[lab_pos].address = ADDRESS;

		start = get_expr(token,start+1);
		generate_ic(token,buff);
		fprintf(fout,"%d (AD,%02d)",ADDRESS,pos+1);
		fprintf(fout," %s \n",buff);
		sym_tab[lab_pos].act_address = eval_main(buff);
	 }

}

void extract_is(int pos,int start);

void form_ic(int a){
	 int pos , start = a;
	 char token[20];char label[20];
	 ADDRESS++;
		 start = get_word(token,buffer,start);
		 if(token[0]=='\0' && LTORG){
			 int flag = 0,i;
			 get_expr(token,start);
			 for(i=0;i<lit_cnt;i++){
			   if(!strcmp(lit_tab[lit_cnt].literal,token)){ flag=1;break;}
			 }
			 if(!flag){
			   strcpy(lit_tab[lit_cnt].literal,token);
			   lit_tab[lit_cnt].address = ADDRESS;
			   lit_cnt++;
			 }
			 else{
			   lit_tab[i].address = ADDRESS;
			 }
			 temp_cnt = 0;
			 return;
		 }
		 if(LTORG ) LTORG = 0,pool_cnt++;
		 pos = sym_tab_find(token);
		 if( pos < 0 ){
		   strcpy(label,token);
		   ins_sym(label);
		   start = get_word(token,buffer,start+1);
		   pos = sym_tab_find(token);
		 }

		if(!strcmp(op_tab[pos].opclass,"DL")){
		 //Find the label and update the Length
			 int temp , lab_pos = 0;
			 if(buffer[start+1]=='\'') temp = 1;
			 else{
			  start = get_word(token,buffer,start+1);
			  temp = tonum(token);
			  }
			 fprintf(fout,"%d (DL,%02d) %d\n",ADDRESS,pos+1,temp);
			 lab_pos = ins_sym(label);
			 sym_tab[lab_pos].length = temp;
			 sym_tab[lab_pos].address = ADDRESS;
			 sym_tab[lab_pos].act_address = ACT_ADDR;
			 ACT_ADDR += temp;
		}

		if(!strcmp(op_tab[pos].opclass,"AD")){
			extract_ad(label,pos,start);
		}
		if(!strcmp(op_tab[pos].opclass,"IS")){
			fprintf(fout,"%d (IS,%02d) ",ADDRESS,pos+1);
			ACT_ADDR++;
			extract_is(pos,start);
			fprintf(fout,"\n");
		}
}


void extract_is(int pos,int start){
	 int i = 0;
	 target_flag = 1;
	 tb[tcnt].address = ACT_ADDR;
	 tb[tcnt].ins = pos?pos+1:pos;
	 for( i = 0;i<op_tab[pos].length;i++){
		char expr[100],buff[100];
		start = get_expr(expr,start+1);
		generate_ic(expr,buff);
		fprintf(fout,"%s ",buff);
	 }
	 tcnt++;
	 target_flag = 0;
}


void show_tables();
int main(){
	int i = 0;
	File = fopen("input.txt","r");
	fout = fopen("tout.txt","w");
	clrscr();
	construct_op_table();

	while(load_line()){
	  printf(" %20s",buffer);
	  form_ic(0);
	  printf("\n");
	}

	printf(" TARGET CODE : \n\n");
	for(i=0;i<tcnt;i++){
	  tb[i].data = sym_tab[tb[i].data].act_address;
	  if(tb[i].ins  == 0) printf("   %d) +%3d %02d %02d \n",tb[i].address-1,0,0,0);
	  else  printf("   %d) +%3d %2d %2d \n",tb[i].address-1,tb[i].ins,tb[i].reg,tb[i].data);
	}
	show_tables();


}

void show_tables(){
	 int i = 0;
	 printf("\n\n SYMBOL TABLE\n");

	 for(i=0;i<sym_cnt;i++){
	   printf(" %20s %20d %20d   \n",sym_tab[i].symbol,sym_tab[i].act_address,sym_tab[i].length);
	 }
	 printf("LIT TABLE\n");

//	 for(i=0;i<lit_cnt;i++){
//	   printf(" %20s %20d \n",lit_tab[i].literal,lit_tab[i].address);
//	 }


}
