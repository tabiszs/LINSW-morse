# LINSW-morse
Program for excercise 2 on Linux in Systems Embeded lecture.

Transmiter of morse code and reciver of acknowledgement from user.

Program works on RapsberryPi4.

# Avoiding Bouncing inside buttons

A oczekiwanie na naciśnięcie przycisku - 10s

B oczekiwanie na zbocze wzrastające
    a) wystąpiło w czasie 40ms -> znowu oczekujemy na naciśnięcie przycisku - 10s
	b) timeout

C zanotowanie, że naciśnięto przycisk 
oczekiwanie na puszczenie przycisku - zbocze wzrastające -> timeout - 10s
	a) wystąpiło w czasie 10s -> zinterpretuj i wróć do A
	b) przerwij odbieranie. Błąd


press button -> falling edge
release button -> rising edge

CLICK TIME
przy szybkim kliknaniu wynosi: 25-50 ms
To jest blisko czasu bouncing time. Stąd przy szybkim klikaniu odczyty z GPIO mogą być nieprawidłowe.

kod sprawdzający:
	struct timespec start, stop, diff;  
	while(1)
	{
		printf("cick fast\n");
		wait_for_falling_edge(&timeout);
		
		printf("after pressed button\n");
		wait_for_rising_edge(&timeout);
		timespec_get(&stop, TIME_UTC);
		printf("after release button\n");
		if(stop.tv_nsec < start.tv_nsec) {
			diff.tv_nsec = 1000000000 + stop.tv_nsec - start.tv_nsec;
			diff.tv_sec = stop.tv_sec - start.tv_sec - 1;
		}
		else
		{
			diff.tv_nsec = stop.tv_nsec - start.tv_nsec;
			diff.tv_sec = stop.tv_sec - start.tv_sec;
		}
		printf("click time: %ld, %d\n", diff.tv_sec, diff.tv_nsec);
	}

TODO 
Wczytywanie X z pustego wejścia

Żródła
https://github.com/dibaggioj/morse-code