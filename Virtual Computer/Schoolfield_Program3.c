#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*https://c-for-dummies.com/blog/?p=1112
  https://stackoverflow.com/questions/32016815/split-integer-into-two-separate-integers
*/

enum command { READ = 10, WRIT, PRNT, LOAD = 20, STOR, SET, ADD = 30, SUB, DIV, MULT, MOD, BRAN = 40, BRNG, BRZR, HALT = 99 };

struct virt_mem {
	int mem_arr[100];
	int accumulator;
	int instruction_counter;
	int instruction_register;
	int operation_code;
	int operand;
};

void compile(struct virt_mem* vm);
void execute(struct virt_mem* vm);
void dumpvm(struct virt_mem** vm);
void word_overflow_ce(char*, int);
int word_overflow_rt(int);
void num_splitter(struct virt_mem** vm, int address);
void num_splitter_two(int address, int* x, int* y);

void compile(struct virt_mem* vm) {

	char word[16], command[8], temp_mem_address[8], temp_str[8];
	char* ptr;
	int i, temp_mem = 0, halt_flag = 0;
	long ir_num;

	for (i = 0; i < 100; i++) {
		vm->mem_arr[i] = 0000;
	}

	while (fgets(word, 16, stdin) != NULL) {
		vm->accumulator = 0000;
		vm->instruction_counter = 00;
		vm->instruction_register = 0000;
		vm->operation_code = 00;
		vm->operand = 00;

		i = sscanf(word, "%d %s %s", &temp_mem, command, temp_mem_address);
		vm->instruction_counter = temp_mem;

		if (strstr(command, "READ")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "10");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "WRIT")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "11");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "PRNT")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "12");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "LOAD")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "20");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "STOR")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "21");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "SET")) { 
			strcpy(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;

		}
		else if (strstr(command, "ADD")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "30");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "SUB")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "31");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "DIV")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "32");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "MULT")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "33");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "MOD")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "34");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "BRAN")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "40");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "BRNG")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "41");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "BRZR")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "42");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
		}
		else if (strstr(command, "HALT")) {
			strcpy(temp_str, command);
			strcpy(temp_str, "99");
			strcat(temp_str, temp_mem_address);
			ir_num = strtol(temp_str, &ptr, 10);
			vm->instruction_register = (int)ir_num;
			word_overflow_ce(temp_str, temp_mem);
			vm->mem_arr[temp_mem] = vm->instruction_register;
			temp_mem++;
			halt_flag = 1;
		}
		else {
			for (i = 0; i < strlen(command); i++) {
				if ((command[i] >= 'a' && command[i] <= 'z') || (command[i] >= 'A' && command[i] <= 'Z')) {
					printf("Error: Unknown command at line: %d", temp_mem);
					exit(1);
				}
				else if (command[i] >= '0' && command[i] <= '9') {
					printf("Error: Undefined use at line: %d" , temp_mem);
					exit(1);
				}
			}
		}
	}
	if (halt_flag == 0) {
		printf("Error: no HALT detected...");
		exit(1);
	}
}

void execute(struct virt_mem* vm) {
	int i, j, in = 0;
	int x = 0, y = 0, temp=0;

	vm->accumulator = 0;
	vm->instruction_counter = 0;
	vm->instruction_register = 0;
	vm->operation_code = 0;
	vm->operand = 0;

	stdin = fopen("/dev/tty", "r");

	for (i = 0; i < 100; i++) {

		vm->instruction_register = vm->mem_arr[i];
		num_splitter(&vm, vm->mem_arr[i]);
		vm->instruction_counter = i+1;

		if (i == 99 && vm->instruction_register != 9999) {
			printf("Segmentation Fault: Halt never reached or memory doesn't exist.");
			vm->operation_code = HALT;
		}
		else if (vm->operation_code == READ) {
			vm->instruction_register = vm->mem_arr[i];
			scanf("%d", &in);
			vm->mem_arr[vm->operand] = in;
		}
		else if (vm->operation_code == WRIT) {
			vm->instruction_register = vm->mem_arr[i];
			printf("%d", vm->mem_arr[vm->operand]);
		}
		else if (vm->operation_code == PRNT) {
			vm->instruction_register = vm->mem_arr[i];
			j = vm->operand;
			while (vm->mem_arr[j] > 0) {
				num_splitter_two(vm->mem_arr[j], &x, &y);
				if (((x == 10 || (x >= 65 && x <= 90)) || (x >= 48 && x <= 57)) && ((y == 10 || (y >= 65 && y <= 90)) || (y <=48 && y >= 57))) {
					printf("%c%c", x, y);
				}
				else if((x == 00 && y == 00)|| (x == 10 && y == 00) || (x == 00 && y == 10)){
					printf("\n");
					break;
				}
				else {
					printf("\nUnknown character at :%d", vm->mem_arr[j]);
					vm->operation_code = HALT;
					break;
				}
				j++;
			}
		}
		else if (vm->operation_code == LOAD) {
			vm->instruction_register = vm->mem_arr[i];
			vm->accumulator = vm->mem_arr[vm->operand];
		}
		else if (vm->operation_code == STOR) {
			vm->instruction_register = vm->mem_arr[i];
			vm->mem_arr[vm->operand] = vm->accumulator;
		}
		else if (vm->operation_code == SET) {
			vm->mem_arr[i] = vm->instruction_register;
		}
		else if (vm->operation_code == ADD) {
			vm->instruction_register = vm->mem_arr[i];
			temp = vm->accumulator + vm->mem_arr[vm->operand];
			if (word_overflow_rt(temp) == 0) {
				vm->accumulator = temp;
			}
			else {
				printf("Word overflow error at line: %d", i);
				vm->operation_code = HALT;
			}
		}
		else if (vm->operation_code == SUB) {
			vm->instruction_register = vm->mem_arr[i];
			temp = vm->accumulator - vm->mem_arr[vm->operand];
			if (word_overflow_rt(temp) == 0) {
				vm->accumulator = temp;
			}
			else {
				printf("Word overflow error at location: %d", i);
				vm->operation_code = HALT;
			}
		}
		else if (vm->operation_code == DIV) {
			vm->instruction_register = vm->mem_arr[i];
			if (vm->mem_arr[vm->operand] != 0) {
				vm->accumulator = vm->accumulator / vm->mem_arr[vm->operand];
			}
			else {
				printf("Division by 0 was attempted at: %d", vm->instruction_counter);
				vm->operation_code = HALT;
			}
		}
		else if (vm->operation_code == MULT) {
			vm->instruction_register = vm->mem_arr[i];
			temp = vm->accumulator * vm->mem_arr[vm->operand];
			if (word_overflow_rt(temp) == 0) {
				vm->accumulator = temp;
			}
			else {
				printf("Word overflow error at location: %d", vm->operand);
				vm->operation_code = HALT;
			}
		}
		else if (vm->operation_code == MOD) {
			vm->instruction_register = vm->mem_arr[i];
			if (vm->mem_arr[vm->operand] != 0) {
				vm->accumulator = vm->accumulator % vm->mem_arr[vm->operand];
			}
			else {
				printf("Division by 0 was attempted at: %d", vm->instruction_counter);
				vm->operation_code = HALT;
			}
		}
		else if (vm->operation_code == BRAN) {
			vm->instruction_register = vm->mem_arr[i];
			i = vm->operand - 1;
		}
		else if (vm->operation_code == BRNG) {
			vm->instruction_register = vm->mem_arr[i];
			if (vm->accumulator < 0) {
				i = vm->operand - 1;
			}
		}
		else if (vm->operation_code == BRZR) {
			vm->instruction_register = vm->mem_arr[i];
			if (vm->accumulator == 0) {
				i = vm->operand - 1;
			}
		}
		else if (vm->operation_code == HALT) {
			vm->instruction_register = 9999;
			dumpvm(&vm);
			exit(1);
		}
		else {
			printf("Unknown command at line :%d", vm->instruction_counter);
			vm->operation_code = HALT;
		}
	}
	dumpvm(&vm);
}

void dumpvm(struct virt_mem** vm) {
	int i, j;

	printf("\nREGISTERS:\n");
	printf("accumulator %+16.4d\n", (*vm)->accumulator);
	printf("instructionCounter %9.2d\n", (*vm)->instruction_counter);
	printf("instructionRegister %+8.4d\n", (*vm)->instruction_register);
	printf("operationCode %14.2d\n", (*vm)->operation_code);
	printf("operand %20.2d\n\n", (*vm)->operand);
	printf("MEMORY:\n");

	for (i = 0; i < 10; i++){ 
		for (j = 0; j < 10; j++) {
			printf("+%.4d  ", (*vm)->mem_arr[10 * i + j]);
		}
	printf("\n\n");
	}
}

void word_overflow_ce(char* address, int location) {
	int size = 4;
	if (strlen(address) > size) {
		printf("Word overflow error at line: %d", location);
		exit(1);
	}
}

int word_overflow_rt(int address) {
	int size = 4;
	int error = 0;
	char str[8];
	sprintf(str, "%d", address);
	if (strlen(str) > size) {
		error = 1;
	}
	return error;
}

void num_splitter(struct virt_mem** vm, int address) {
	/*I can't think of a different way to do this without overhauling the program.*/
	int length = floor(log10(abs(address))) + 1;
	(*vm)->operation_code = address / pow(10, length / 2);
	(*vm)->operand = address - (*vm)->operation_code * pow(10, length / 2);
}

void num_splitter_two(int address, int* x, int* y) {
	int length = floor(log10(abs(address))) + 1;
	*x = address / pow(10, length / 2);
	*y = address - *x * pow(10, length / 2);
}

int main(void) {
	struct virt_mem vm;
	compile(&vm);
	execute(&vm);
	return 0;
}