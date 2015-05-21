#include <stdio.h>
#include <math.h>

int myAtoi(char* str) {
	int signal = 1, length = 0, integer_length = 0, start_position, i, count = 0;
	char c;
	int integer_part = 1;
	const int MAX = 2147483647;
	const int MIN = -2147483648;

	while (str[length] == ' ')						//dispose spaces
		++length;

	if (str[length] == '-') {						//dispose negivate
		length++;
		signal = -1;
	}	
	else if (str[length] == '+') {					//dispose positive
		length++;
	}

	start_position = length;						//first number position
	while ((c = str[length++]) != '\0') {			//traversal
		if (c >= '0' && c <= '9') {					//count the length of integer part
			if (integer_part)
				integer_length++;					//count integer part length
		}
		else if (c == '.') {						//judge decimal point
			if (integer_part) {
				integer_part = 0;
			}
			else
				return 0;							//multiple decimal points means error
		}
		else
		{
			break;									//other characters means break (But I think should be an error 0.0)
		}
	}

	for (i = start_position; i < integer_length + start_position; i++)		//start from start_position
	{
		count += (str[i] - '0') * (int)pow(10, integer_length + start_position - i - 1);
		if (count < 0 && signal > 0) {				//dispose overflow
			return MAX;
		}
		if (count < 0 && signal < 0) {
			return MIN;
		}
	}

	return count*signal;
}



int main() {
	printf("%d", myAtoi("   010"));
}