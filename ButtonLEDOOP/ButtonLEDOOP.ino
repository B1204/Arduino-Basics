#define LED_1_PIN 9
#define BUTTON_PIN 5

class Led {
  private:
    byte pin;
  public:
    Led(byte pin) {
      // Use 'this->' to make the difference between the
      // 'pin' attribute of the class and the 
      // local variable 'pin' created from the parameter.
      this->pin = pin;
      init();
    }

    void init() {
      pinMode(pin, OUTPUT);
      // Always try to avoid duplicate code.
      // Instead of writing digitalWrite(pin, LOW) here,
      // call the function off() which already does that
      off();
    }

    void on() {
      digitalWrite(pin, HIGH);
    }

    void off() {
      digitalWrite(pin, LOW);
    }
}; // don't forget the semicolon at the end of the class

class Button {
  private:
    byte pin;
    byte state;
    byte lastReading;
    unsigned long lastDebounceTime = 0;
    unsigned long debounceDelay = 50;
  public:
    Button(byte pin) {
      this->pin = pin;
      lastReading = LOW;
      init();
    }

    void init() {
      pinMode(pin, INPUT);
      update();
    }

    void update() {
      // You can handle the debounce of the button directly
      // in the class, so you don't have to think about it
      // elsewhere in your code
      byte newReading = digitalRead(pin);
      
      if (newReading != lastReading) {
        lastDebounceTime = millis();
      }

      if (millis() - lastDebounceTime > debounceDelay) {
        // Update the 'state' attribute only if debounce is checked
        state = newReading;
      }

      lastReading = newReading;
    }

    byte getState() {
      update();
      return state;
    }

    bool isPressed() {
      return (getState() == HIGH);
    }
}; // don't forget the semicolon at the end of the class

// Create your objects in the global scope so you can
// get access to them in the setup() and loop() functions
Led led1(LED_1_PIN);
Button button1(BUTTON_PIN);

void setup() { 
    Serial.begin(9600);// initialize serial communication at 9600 bits per second:
  }

void loop() {
  if (button1.isPressed()) {
    led1.on();
    Serial.println (" Toggle Switch is ON.");

  }
  else {
    led1.off();
    Serial.println (" Toggle Switch is OFF.");

  }
}
