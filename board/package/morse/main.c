#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>

#define	TRANSMITER	"TRANSMITER"
#define	RECIVER		"RECIVER"

#define MAX_LIMIT 100

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

int main(int argc, char **argv)
{
	char *chipname = "gpiochip0";
	unsigned int output_line_num = 24;	// GPIO Pin #23
	unsigned int input_line_num = 12; 	// GPIO Pin #22
	unsigned int error_line_num = 10; 	// GPIO Pin #10
	unsigned int val;
	struct gpiod_chip *chip;
	struct gpiod_line *output_line;
	struct gpiod_line *input_line;
	int i, ret, err;
	char str[MAX_LIMIT],str1[MAX_LIMIT*10];
	struct timespec timeout;
	struct timespec basetime;
	basetime.tv_sec = 0;
  	basetime.tv_nsec = 500000000;

	convert(str, str1);

	chip = gpiod_chip_open_by_name(chipname);
	if (!chip) {
		perror("Open chip failed\n");
		goto end;
	}

	output_line = gpiod_chip_get_line(chip, output_line_num);
	if (!output_line) {
		perror("Get line failed\n");
		goto close_chip;
	}

	input_line = gpiod_chip_get_line(chip, input_line_num);
	if (!input_line) {
		perror("Get line failed\n");
		goto close_chip;
	}
	printf("open input and output line55\n");

	ret = gpiod_line_request_output(output_line, TRANSMITER, 1);
	if (ret < 0) {
		perror("Request line as output failed\n");
		goto release_output;
	}

	// ret = gpiod_line_request_input(input_line, RECIVER);
	// if (ret < 0) {
	// 	perror("Request line as input failed\n");
	// 	goto release_input;
	// }
	printf("gpiod_line_request_output\n");

	/* Send Morse Code */
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
			goto release_output;
		}
		printf("Show %c sign\n", str1[i]);
		sleep(timeset);

        if(str1[i] != '/')
        {
            val = 0;
		    ret = gpiod_line_set_value(output_line, val);
    		if (ret < 0) {
	    		perror("Set line output failed\n");
		    	goto release_output;
    		}
		    sleep(1);
        }
	}

	printf("Czekaj na potwierdzenie odbiorcy. Consumer = %s\n", RECIVER);

    /*  Acknowledgement */
    // wait 10s

	err = gpiod_line_request_rising_edge_events(input_line, RECIVER);
	if(err < 0)
	{
		perror("gpiod_line_request_rising_edge_events");
		goto release_input;
	}

	timeout.tv_sec = 10;
  	timeout.tv_nsec = 0;
	printf("waiting for rising edge event\n");
	err = gpiod_line_event_wait(input_line, &timeout);
  	if(err == -1)
	{
    	perror("gpiod_line_event_wait");
    	goto release_input;
  	}
  	else if(err == 0)
  	{
    	fprintf(stderr, "wait timed out\n");
    	goto release_input;
  	}

	val = err = gpiod_line_get_value(input_line);
	if(err < 0)
	{
		perror("gpiod_line_get_value_bulk");
		goto release_input;
	}
	printf("val = %d\n", val);


release_input:
	gpiod_line_release(input_line);
release_output:
	gpiod_line_release(output_line);
close_chip:
	gpiod_chip_close(chip);
end:
	return 0;
}
