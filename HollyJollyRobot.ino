#include "Pitches.h"

/************************/
/** PIN CONFIGURATIONS **/
/************************/
#define led 13
#define buzzer 3
#define echoPin A0
#define pingPin 10

#define christmasDistance 91 // roughly three feet

void setup() {
	pinMode(led, OUTPUT);
	pinMode(buzzer, OUTPUT);
	pinMode(pingPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

void loop() {
	// See if an object is in front of us
	int distance = msToCm(ping());

	// if it's less than the distance we've defined above, play a song
	if ( distance < christmasDistance ) {

		// pick a random song
		int song = random(1, 4);

		// play the song
		playSong(song);

		// blink the song id
		blink(song);
	}
}

// Note-playing buzzer helper function.
void playNote(int note, int duration, float rest) {
	digitalWrite(led, HIGH);
	tone(buzzer, note, duration);
	delay((duration * rest)/2);
	digitalWrite(led, LOW);
	delay((duration * rest)/2);
}

void playSong(int songIdx) {

	if ( songIdx == 1 ) {
		// hark the herald angels sing
		//cffefaagCCCa#aga
		playNote(NOTE_C5, 200, 2);
		playNote(NOTE_F5, 200, 2);
		playNote(NOTE_F5, 400, 1.5);
		playNote(NOTE_E5, 200, 2);
		playNote(NOTE_F5, 200, 2);
		playNote(NOTE_A5, 200, 2);
		playNote(NOTE_A5, 200, 2);
		playNote(NOTE_G5, 200, 2);
		playNote(NOTE_C6, 200, 2);
		playNote(NOTE_C6, 200, 2);
		playNote(NOTE_C6, 200, 2);
		playNote(NOTE_AS5, 200, 2);
		playNote(NOTE_A5, 200, 2);
		playNote(NOTE_G5, 200, 2);
		playNote(NOTE_A5, 400, 2);
	} else if ( songIdx == 2 ) {
		// oh come all ye faithful
		// ggdgadbabCba
		playNote(NOTE_G5, 200, 2);
		playNote(NOTE_G5, 400, 2);
		playNote(NOTE_D5, 200, 2);
		playNote(NOTE_G5, 200, 2);
		playNote(NOTE_A5, 400, 2);
		playNote(NOTE_D5, 400, 2);
		playNote(NOTE_B5, 200, 2);
		playNote(NOTE_A5, 200, 2);
		playNote(NOTE_B5, 200, 2);
		playNote(NOTE_C6, 200, 2);
		playNote(NOTE_B5, 400, 2);
		playNote(NOTE_A5, 400, 2);
	} else if ( songIdx == 3 ) {
		// jingle bells
		//eeeeeeegcde fffffeeeeddedg
		playNote(NOTE_E5, 200, 1);
		playNote(NOTE_E5, 200, 1);
		playNote(NOTE_E5, 400, 1);
		playNote(NOTE_E5, 200, 1);
		playNote(NOTE_E5, 200, 1);
		playNote(NOTE_E5, 400, 1);
		playNote(NOTE_E5, 200, 1);
		playNote(NOTE_G5, 200, 1);
		playNote(NOTE_C5, 200, 1);
		playNote(NOTE_D5, 200, 1);
		playNote(NOTE_E5, 400, 2);
	}
}

/**********************/
/** Helper Functions **/
/**********************/


// Helper function to manage our ultrasonic sensor.
long ping() {
	long duration;
	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(pingPin, LOW);
	duration = pulseIn(echoPin, HIGH);

	return duration;
}

// Helper function to return the distance to an object
// detected by the ultrasonic sensor in centimeters.
long msToCm(long microseconds) {
	return microseconds / 29 / 2;
}

// Simple blink function called in loop() whenever a state
// change is made by a user button press.
void blink(int blinks) {
	for ( int i = 0; i <= blinks; i++ ) {
		digitalWrite(led, HIGH);
		delay(250);
		digitalWrite(led, LOW);
		delay(250);
	}
}
