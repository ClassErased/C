#include<stdio.h>
#include<string.h>

void copy(char* dst, char* src){
  while(*src != '\0'){
    char cp = *src;
    *dst = cp;
    src++;
    dst++;
  }
  *dst = '\0'; 
}
 
int main(){
  //read user input
  char srcString[] = "Hello I am a string literal\n\n";
  //char srcString[100]; // create buffer for input
  //printf("Input a string to be copied: ");
  //fgets(srcString, sizeof(srcString), stdin);

  //Remove newline char
  size_t len = strlen(srcString);
  if(len > 0 && srcString[len-1] == '\n'){
    srcString[len-1] = '\0';
  }

  char dstString[len]; //set buffer for dst
  copy(dstString, srcString);
  printf("%s", dstString); 
}