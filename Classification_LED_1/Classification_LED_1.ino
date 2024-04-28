// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

int spin = 1;
int jump = 0;
int numMoves = 6;

unsigned long moveBegin[] = {
  3700, 13000, 18700, 24800, 32000, 39000
};
unsigned long moveEnd[] = {
  7700, 14200, 20000, 26000, 35000, 39600
};
int moveSequence[] {
  spin, spin, spin, jump, spin, jump
};
int delayTime = 3000;
int move = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 0);
  digitalWrite(BLUE, 0);
}

// define variables
int lightStart = -1;
unsigned long myTime;

void loop() {
  // elapsed time since application start in ms
  myTime = millis();
  if (myTime % 1000 == 0) {
    Serial.println(myTime);
    Serial.println(moveBegin[move]);
    Serial.println(move);
    Serial.println();
  }

  // turn of lights if they've been on for a second or more
  if (lightStart > 0 && myTime - lightStart > delayTime) {
    endLight();
    if (move > numMoves) {
      for (;;);
    }
  }
  // if we start a move, turn on corresponding light
  if (myTime >= moveBegin[move] && move <= numMoves) {
    lightStart = myTime;
    if (moveSequence[move] == jump)
      jumpLight();
    else
      spinLight();
    move++;
  }

  

}

void jumpLight() {
  analogWrite(RED, 255/1.5);
  analogWrite(GREEN, 40/1.5);
  analogWrite(BLUE, 0);
}

void spinLight() {
  analogWrite(RED, 48/10);
  analogWrite(GREEN, 213/10);
  analogWrite(BLUE, 200/10);
}

void endLight() {
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}
