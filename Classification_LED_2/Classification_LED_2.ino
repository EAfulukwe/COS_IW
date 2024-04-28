#include <FastLED.h>

#define NUM_LEDS  100
#define LED_PIN   2

CRGB led[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];

int numMoves = 6;
int move = 0;
unsigned long myTime;

unsigned long moveBegin[] = {
  3700, 13000, 18700, 24800, 32000, 39000
};
unsigned long moveEnd[] = {
  7700, 14200, 20000, 26000, 35000, 39600
};
int moveSequence[] {
  1, 1, 1, 0, 1, 0
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(led, NUM_LEDS);
  FastLED.setBrightness(50);
  startLight(CRGB(189/10,230/35,140/35));
  FastLED.show();
  delay(500);
  startLight(CRGB::Black);
  FastLED.show();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  myTime = millis();
  if (myTime % 1000 == 0) {
    Serial.println(myTime);
    Serial.println(moveBegin[move]);
    Serial.println(move);
    Serial.println();
  }

  // if we start a move, turn on corresponding light
  if (myTime >= moveBegin[move] && move < numMoves) {
    if (moveSequence[move] == 0)
      jumpLight();
    else {
      spinLight();
    }
      
    move++;
  }

}

void jumpLight() {
  for(int i = 0; i < NUM_LEDS; i++) {
    for (int j = 0; j <= 90; j += 15) {
      if (i > j)
        gradientJ(i-j);
    }

    FastLED.show();
    delay(17.5);

    for (int j = 0; j <= 90; j += 15) {
      if (i > j)
        black(i-j);
    }
  }
  FastLED.show();
}

void spinLight() {
  for(int i = 0; i < NUM_LEDS; i++) {
    for (int j = 0; j <= 90; j += 15) {
      if (i > j)
        gradientS(i-j);
    }

    FastLED.show();
    delay(20);

    for (int j = 0; j <= 90; j += 15) {
      if (i > j)
        black(i-j);
    }
  }
  FastLED.show();
  
}


void gradientJ(int i) {
  led[i% NUM_LEDS] = CRGB(255, 40, 0);
  if (i > 0)
    led[(i-1) % NUM_LEDS] = CRGB(255*0.9, 40*0.9, 0);
  if (i > 2)
    led[(i-2) % NUM_LEDS] = CRGB(255*0.8, 40*0.8, 0);
  if (i > 3)
    led[(i-3) % NUM_LEDS] = CRGB(255*0.7, 40*0.7, 0);
  if (i > 4)
    led[(i-4) % NUM_LEDS] = CRGB(255*0.6, 40*0.6, 0);
  if (i > 5)
    led[(i-5) % NUM_LEDS] = CRGB(255*0.5, 40*0.5, 0);
  if (i > 6)
    led[(i-6) % NUM_LEDS] = CRGB(255*0.4, 40*0.4, 0);
  if (i > 7)
    led[(i-7) % NUM_LEDS] = CRGB(255*0.3, 40*0.3, 0);
  if (i > 8)
    led[(i-8) % NUM_LEDS] = CRGB(255*0.2, 40*0.2, 0);
  if (i > 9)
    led[(i-9) % NUM_LEDS] = CRGB(255*0.1, 40*0.1, 0);
  if (i > 10)
    led[(i-10) % NUM_LEDS] = CRGB(0, 0, 0);
}

void gradientS(int i) {
  led[i% NUM_LEDS] = CRGB(4.8, 21.3, 20);
  if (i > 0)
    led[(i-1) % NUM_LEDS] = CRGB(4.8*0.9, 21.3*0.9, 20*0.9);
  if (i > 2)
    led[(i-2) % NUM_LEDS] = CRGB(4.8*0.9, 21.3*0.8, 20*0.8);
  if (i > 3)
    led[(i-3) % NUM_LEDS] = CRGB(4.8*0.7, 21.3*0.7, 20*0.7);
  if (i > 4)
    led[(i-4) % NUM_LEDS] = CRGB(4.8*0.6, 21.3*0.6, 20*0.6);
  if (i > 5)
    led[(i-5) % NUM_LEDS] = CRGB(4.8*0.5, 21.3*0.5, 20*0.5);
  if (i > 6)
    led[(i-6) % NUM_LEDS] = CRGB(4.8*0.4, 21.3*0.4, 20*0.4);
  if (i > 7)
    led[(i-7) % NUM_LEDS] = CRGB(4.8*0.3, 21.3*0.3, 20*0.3);
  if (i > 8)
    led[(i-8) % NUM_LEDS] = CRGB(4.8*0.2, 21.3*0.2, 20*0.2);
  if (i > 9)
    led[(i-9) % NUM_LEDS] = CRGB(4.8*0.1, 21.3*0.1, 20*0.1);
  if (i > 10)
    led[(i-10) % NUM_LEDS] = CRGB(0, 0, 0);
}

void black(int i) {
  led[i % NUM_LEDS] = CRGB::Black;
  if (i > 0)
    led[(i-1) % NUM_LEDS] = CRGB::Black;
  if (i > 2)
    led[(i-2) % NUM_LEDS] = CRGB::Black;
  if (i > 3)
    led[(i-3) % NUM_LEDS] = CRGB::Black;
  if (i > 4)
    led[(i-4) % NUM_LEDS] = CRGB::Black;
  if (i > 5)
    led[(i-5) % NUM_LEDS] = CRGB::Black;
  if (i > 6)
    led[(i-6) % NUM_LEDS] = CRGB::Black;
  if (i > 7)
    led[(i-7) % NUM_LEDS] = CRGB::Black;
  if (i > 8)
    led[(i-8) % NUM_LEDS] = CRGB::Black;
  if (i > 9)
    led[(i-9) % NUM_LEDS] = CRGB::Black;
  if (i > 10)
    led[(i-10) % NUM_LEDS] = CRGB::Black;
}

void startLight(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++)
    led[i] = color;
}

