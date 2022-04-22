#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>

#define	TRANSMITER	"TRANSMITER"
#define	RECIVER		"RECIVER"

#define MAX_LIMIT 100

struct gpiod_chip *chip;
struct gpiod_line *output_line;
struct gpiod_line *input_line;
struct gpiod_line_event event;
struct timespec timeout = {10, 0};
struct timespec bouncingtime = { 0,  40000000};

const static char DOT = '.';
const static char DAH = '-';
const static char SLASH = '/';

const static long int MORSE_UNIT =        800000000; //ns
const static long int LENGTH_DOT =        1 * MORSE_UNIT;
const static long int BLINK_DAH =         3 * MORSE_UNIT;
const static long int SPACE_INTERUNIT =   1 * MORSE_UNIT;
const static long int SPACE_INTERCHAR =   3 * MORSE_UNIT;
const static long int SPACE_INTERWORD =   7 * MORSE_UNIT;
const static long int SPACE_INTERCHAR_REMAINING =   SPACE_INTERCHAR - SPACE_INTERUNIT; // character already ends with an inter-unit space, so deduct that

long int interval, is_on = 0;
struct timespec start, stop;

void convert(char* str, char* str1)
{
	fflush(stdin);
	printf("Enter test to convert into Morse Code :: ");
	scanf("%[^\n]%*c", str);

	int j=0;
	int i=0;
	for( ; i<=strlen(str); i++)
	{
		str1[j++]='/';
		switch(toupper(str[i]))
		{
				case 'A':
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'B':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case 'C':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case 'D':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case 'E':
				  str1[j]='.';
					break;

				case 'F':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case 'G':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='.';
				  break;

				case 'H':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case 'I':
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case 'J':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case 'K':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'L':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='.';
				  break;

				case 'M':
				  str1[j++]='-';
					str1[j]='-';
					break;

				case 'N':
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case 'O':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case 'P':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case 'Q':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'R':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case 'S':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case 'T':
				  str1[j]='-';
					break;

				case 'U':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'V':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'W':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case 'X':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case 'y':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case 'Z':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '0':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case '1':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case '2':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case '3':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case '4':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case '5':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '6':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '7':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '8':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '9':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '.':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case ',':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='-';
					break;

				case ':':
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '?':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j]='.';
					break;


				case '-':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case ';':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '"':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '+':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '/':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '&':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='.';
					break;

				case '$':
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;


				case '@':
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='-';
				  str1[j]='.';
					break;

				case '=':
				  str1[j++]='-';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j++]='.';
				  str1[j]='-';
					break;

				case ' ':
				  //str1[j]='/';
				  j--;
					break;
				}
			j++;
	}
	str1[j-1]='\0';
	printf("%s\n", str1);
	return;
}

void cleanup_gpio()
{
	gpiod_line_release(input_line);
	gpiod_line_release(output_line);
	gpiod_chip_close(chip);
}

int wait_for_falling_edge(struct timespec* timeout)
{
	int err, val = 1;
	printf("waiting for falling edge event\n");
	err = gpiod_line_event_wait(input_line, timeout);
	if(err == -1) {
		perror("gpiod_line_event_wait");
		cleanup_gpio();
		exit(1);
	} else if(err == 0) {
		fprintf(stderr, "wait timed out\n");
		val = 0;
	}

	if(val) {
		err = gpiod_line_event_read(input_line, &event);
		if(err) {
			perror("gpiod_line_event_read");
			cleanup_gpio();
			exit(1);
		}

		if(event.event_type == GPIOD_LINE_EVENT_FALLING_EDGE)
			val = 1;
		else
			val = 0;
	}
	
	return val;
}

int wait_for_rising_edge(struct timespec* timeout)
{
	int err, val = 1;
	printf("waiting for rising edge event\n");
	err = gpiod_line_event_wait(input_line, timeout);
	if(err == -1){
		perror("gpiod_line_event_wait");
		cleanup_gpio();
		exit(1);
	} else if(err == 0) {
		fprintf(stderr, "wait timed out\n");
		val = 0;
	}

	if(val) {
		err = gpiod_line_event_read(input_line, &event);
		if(err) {
			perror("gpiod_line_event_read");
			cleanup_gpio();
			exit(1);
		}

		if(event.event_type == GPIOD_LINE_EVENT_RISING_EDGE)
			val = 1;
		else
			val = 0;
	}
	
	return val;
}

int recive_signal(char *recived_text, int *i)
{
	int pressed, rised, exist = 0;
	do{
		pressed = wait_for_falling_edge(&timeout);
		if(pressed){
			exist = wait_for_rising_edge(&bouncingtime);
		}
	} while (pressed && exist);
	
	if(!pressed) return 0;

	if(is_on)
	{
		timespec_get(&stop, TIME_UTC);
		interval = (stop.tv_sec-start.tv_sec)*1000000000 + stop.tv_nsec-start.tv_nsec;
		timespec_get(&start, TIME_UTC);
		if(interval < SPACE_INTERUNIT) {/*do nothing*/}
		else if(interval < SPACE_INTERCHAR) {
			recived_text[(*i)++] = SLASH;
		}else{
			recived_text[(*i)++] = SLASH;
			recived_text[(*i)++] = SLASH;
		}
	}else{
		is_on = 1;
		timespec_get(&start, TIME_UTC);
	}

	// wait for rising edge
	do
	{
		rised = wait_for_rising_edge(&timeout);
		if(rised)
		{
			exist = wait_for_falling_edge(&bouncingtime);
		}
	} while (rised && exist);

	if(!rised) return 0;

	timespec_get(&stop, TIME_UTC);
	interval = (stop.tv_sec-start.tv_sec)*1000000000 + stop.tv_nsec-start.tv_nsec;
	timespec_get(&start, TIME_UTC);
	if(interval < LENGTH_DOT) recived_text[(*i)++] = DOT;
	else recived_text[(*i)++] = DAH;

	return 1;
}

int main(int argc, char **argv)
{
	char *chipname = "gpiochip0";
	unsigned int output_line_num = 24;	// GPIO Pin #23
	unsigned int input_line_num = 13; 	// GPIO Pin #22
	unsigned int error_line_num = 10; 	// GPIO Pin #10
	unsigned int val;
	int i, ret, err;
	char str[MAX_LIMIT],str1[MAX_LIMIT*10];

	struct timespec timelapse = {0, 0};
	struct timespec basetime = {0 , 500000000};

	convert(str, str1);

	chip = gpiod_chip_open_by_name(chipname);
	if (!chip) {
		perror("Open chip failed\n");
		return(EXIT_FAILURE);
	}

	output_line = gpiod_chip_get_line(chip, output_line_num);
	if (!output_line) {
		perror("Get line failed\n");
		gpiod_chip_close(chip);
		return(EXIT_FAILURE);
	}

	input_line = gpiod_chip_get_line(chip, input_line_num);
	if (!input_line) {
		perror("Get line failed\n");
		gpiod_chip_close(chip);
		return(EXIT_FAILURE);
	}

	ret = gpiod_line_request_output(output_line, TRANSMITER, 1);
	if (ret < 0) {
		perror("Request line as output failed\n");
		gpiod_line_release(output_line);
		gpiod_chip_close(chip);
		return(EXIT_FAILURE);
	}

	printf("TRANSMIT CODE\n");
	val = 0;
	int timeset = 1;
	for (i = 0; i < strlen(str1); i++) {
		
		switch (str1[i])
		{
		case '.':
			timeset = 1;
			val = 1;
			break;
		case '/':
			timeset = 3;
			val = 0;
			break;        
		case '-':
			timeset = 3;
			val = 1;
			break;
		}

		ret = gpiod_line_set_value(output_line, val);
		if (ret < 0) {
			perror("Set line output failed\n");
			gpiod_line_release(output_line);
			gpiod_chip_close(chip);
			return(EXIT_FAILURE);
		}
		printf("Show %c sign\n", str1[i]);
		sleep(timeset);

		if(str1[i] != '/')
		{
			val = 0;
			ret = gpiod_line_set_value(output_line, val);
			if (ret < 0) {
				perror("Set line output failed\n");
				gpiod_line_release(output_line);
				gpiod_chip_close(chip);
				return(EXIT_FAILURE);
			}
			sleep(1);
		}
	}

	err = gpiod_line_request_both_edges_events(input_line, RECIVER);
	if(err) 
	{
		cleanup_gpio();
		return(EXIT_FAILURE);
	}

	printf("WAIT FOR RECIVE\n");
	int recived, idx=0;
	char recived_text[1000];
	recived_text[idx++] = SLASH;
	do
	{
		recived = recive_signal(recived_text, &idx);
		printf("recived text: %s\n", recived_text);
	} while( recived );

	recived_text[idx++] = SLASH;
	printf("recived text: %s\n", recived_text);
	return 0;
}
