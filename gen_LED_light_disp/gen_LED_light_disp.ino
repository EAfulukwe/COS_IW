#include <FastLED.h>

#define NUM_LEDS  100
#define LED_PIN   2

CRGB led[NUM_LEDS];
uint8_t colorIndex[NUM_LEDS];
int i = 0;

CRGB color1 = CRGB(255/1.5, 40/1.5, 0);

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(led, NUM_LEDS);
  FastLED.setBrightness(20);
}

void loop() {

  for(int i = 0; i < NUM_LEDS+70; i++) {
    gradient(i);
    // if (i > 20)
    //   gradient(i-20);
    // if (i > 40)
    //   gradient(i-40);
    // if (i > 60)
    //   gradient(i-60);
    // if (i > 80)
    //   gradient(i-80);

    if (i > 15)
      gradient(i-15);
    if (i > 30)
      gradient(i-30);
    if (i > 45)
      gradient(i-45);
    if (i > 60)
      gradient(i-60);
    if (i > 75)
      gradient(i-75);
    if (i > 90)
      gradient(i-90);


    FastLED.show();
    delay(20);
    black(i, CRGB::Black);
    // if (i > 20)
    //   black(i-20, CRGB::Black);
    // if (i > 40)
    //   black(i-40, CRGB::Black);
    // if (i > 60)
    //   black(i-60, CRGB::Black);
    // if (i > 80)
    //   black(i-80, CRGB::Black);

    if (i > 15)
      black(i-15, CRGB::Black);
    if (i > 30)
      black(i-30, CRGB::Black);
    if (i > 45)
      black(i-45, CRGB::Black);
    if (i > 60)
      black(i-60, CRGB::Black);
    if (i > 75)
      black(i-75, CRGB::Black);
    if (i > 90)
      black(i-90, CRGB::Black);

  }

  i += 1;
  if (i == 3)
    while(true){}
}

// void black(int i, CRGB color) {
//   if (i < NUM_LEDS)
//     led[i] = color*1;
//   if (i > 0 && i-1 < NUM_LEDS)
//     led[i-1] = color;
//   if (i > 2 && i-2 < NUM_LEDS)
//     led[i-2] = color;
//   if (i > 3 && i-3 < NUM_LEDS)
//     led[i-3] = color;
//   if (i > 4 && i-4 < NUM_LEDS)
//     led[i-4] = color;
//   if (i > 5 && i-5 < NUM_LEDS)
//     led[i-5] = color;
//   if (i > 6 && i-6 < NUM_LEDS)
//     led[i-6] = color;
//   if (i > 7 && i-7 < NUM_LEDS)
//     led[i-7] = color;
//   if (i > 8 && i-8 < NUM_LEDS)
//     led[i-8] = color;
//   if (i > 9 && i-9 < NUM_LEDS)
//     led[i-9] = color;
//   if (i > 10 && i-10 < NUM_LEDS)
//     led[i-10] = color;
// }

// void gradient(int i) {
//   if (i < NUM_LEDS)
//     led[i] = CRGB(255, 40, 0);
//   if (i > 0 && i-1 < NUM_LEDS)
//     led[i-1] = CRGB(255*0.9, 40*0.9, 0);
//   if (i > 2 && i-2 < NUM_LEDS)
//     led[i-2] = CRGB(255*0.8, 40*0.8, 0);
//   if (i > 3 && i-3 < NUM_LEDS)
//     led[i-3] = CRGB(255*0.7, 40*0.7, 0);
//   if (i > 4 && i-4 < NUM_LEDS)
//     led[i-4] = CRGB(255*0.6, 40*0.6, 0);
//   if (i > 5 && i-5 < NUM_LEDS)
//     led[i-5] = CRGB(255*0.5, 40*0.5, 0);
//   if (i > 6 && i-6 < NUM_LEDS)
//     led[i-6] = CRGB(255*0.4, 40*0.4, 0);
//   if (i > 7 && i-7 < NUM_LEDS)
//     led[i-7] = CRGB(255*0.3, 40*0.3, 0);
//   if (i > 8 && i-8 < NUM_LEDS)
//     led[i-8] = CRGB(255*0.2, 40*0.2, 0);
//   if (i > 9 && i-9 < NUM_LEDS)
//     led[i-9] = CRGB(255*0.1, 40*0.1, 0);
//   if (i > 10 && i-10 < NUM_LEDS)
//     led[i-10] = CRGB(0, 0, 0);;
// }

void gradient(int i) {
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
    led[(i-10) % NUM_LEDS] = CRGB(0, 0, 0);;
}

void black(int i, CRGB color) {
  led[i % NUM_LEDS] = color*1;
  if (i > 0)
    led[(i-1) % NUM_LEDS] = color;
  if (i > 2)
    led[(i-2) % NUM_LEDS] = color;
  if (i > 3)
    led[(i-3) % NUM_LEDS] = color;
  if (i > 4)
    led[(i-4) % NUM_LEDS] = color;
  if (i > 5)
    led[(i-5) % NUM_LEDS] = color;
  if (i > 6)
    led[(i-6) % NUM_LEDS] = color;
  if (i > 7)
    led[(i-7) % NUM_LEDS] = color;
  if (i > 8)
    led[(i-8) % NUM_LEDS] = color;
  if (i > 9)
    led[(i-9) % NUM_LEDS] = color;
  if (i > 10)
    led[(i-10) % NUM_LEDS] = color;
}