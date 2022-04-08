const int perf = 20;
const int relay = 10;
const int sensor = A0;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void addwater() {
  digitalWrite(relay, HIGH);
  delay(500);
  digitalWrite(relay, LOW);
  return;
}

void loop() {
  int feuchtigkeit = analogRead(sensor);
  int percentage = map(feuchtigkeit,550,0,0,100);
  Serial.println("========================");
  Serial.print("Handling new data: ");
  Serial.print(percentage);
  Serial.print("%, Raw: ");
  Serial.println(feuchtigkeit);
  Serial.print("Action: ");
  if (percentage >= perf) { Serial.println("none, enough water"); }
  if (percentage < perf) { Serial.println("not enough water, adding some"); addwater(); }
  delay(2500);
}

// je höher die feuchtigkeit desto kleiner der output
// je weniger die feuchtigkeit desto größer der output
