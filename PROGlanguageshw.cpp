#include <stdio.h>
#include <string.h>
int strToInt(char str[]) {
 int number = 0;
 for (int i = 0; i < strlen(str); i++) {
 number = number * 10;
 number += str[i] - 48;
} return number;
}
void CommandChecker(char command[]) {
 if (strncmp(command, "put", 3) == 0) {


 } else if (strncmp(command, "jmpe", 4) == 0) {


 } else if (strncmp(command, "add", 3) == 0) {


 } else if (strncmp(command, "jmpu", 4) == 0) {


 } else if (strncmp(command, "prn", 3) == 0) {


 } else if (strncmp(command, "halt", 4) == 0) {


 } else {

 }
}
int main() {
 FILE *fh;
 fh = fopen("program.sla.txt", "r");
 char size[32];

 if (fh == NULL) {
 printf("error\n");
 return 1;
 }


 while (fgets(size, 32, fh)) {
 printf("Read line: %s", size);
 int number = strToInt(size);
 printf("Converted number: %d\n", number);
 }

 fclose(fh);
 return 0;
}
