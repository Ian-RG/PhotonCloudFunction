const int greenLed = D0;
const int yellowLed = D1;
const int redLed = D2;

bool greenState = false;
bool yellowState = false;
bool redState = false;

void setup() {
    Particle.function("led", switchLedState);
    pinMode(greenLed, OUTPUT);
    pinMode(yellowLed, OUTPUT);
    pinMode(redLed, OUTPUT);
}

void loop() {
}

int switchLedState(String s) {
    int result = -1;
    String ledName = s.toLowerCase();
    if (ledName.indexOf("green") >= 0) {
        greenState ? digitalWrite(greenLed, LOW) : digitalWrite(greenLed, HIGH);
        greenState = !greenState;
        result = 1;
    }
    else if (ledName.indexOf("yellow") >= 0) {
        yellowState ? digitalWrite(yellowLed, LOW) : digitalWrite(yellowLed, HIGH);
        yellowState = !yellowState;
        result = 1;
    }
    else if (ledName.indexOf("red") >= 0) {
        redState ? digitalWrite(redLed, LOW) : digitalWrite(redLed, HIGH);
        redState = !redState;
        result = 1;
    }
    return result;
}
