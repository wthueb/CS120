/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void playNotes(int* melody, int* durations, int n)
{
  for (int i = 0; i < n; i++)
  {
    int duration = 1000 / durations[i];
    tone(8, melody[i], duration);
    
    delay(duration * 1.3);

    noTone(8);
  }
}

void setup() {
  playNotes(melody, noteDurations, 8);

  delay(1000);

  playNotes(&melody[4], &noteDurations[4], 4);
}

void loop() {
  // no need to repeat the melody.
}
