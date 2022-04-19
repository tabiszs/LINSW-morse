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