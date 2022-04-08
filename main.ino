const int perf = 20;   // perfect percentage
const int relay = 10;  // relay port
const int sensor = A0; // sensor port

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
  int moisture = analogRead(sensor);
  int percentage = map(moisture,550,0,0,100);
  // the higher the moisture, the lower the output
  // the less the moisture, the greater the output
  Serial.println("========================");
  Serial.print("Handling new data: ");
  Serial.print(percentage);
  Serial.print("%, Raw: ");
  Serial.println(moisture);
  Serial.print("Action: ");
  if (percentage >= perf) { Serial.println("none, enough water"); }
  if (percentage < perf) { Serial.println("not enough water, adding some"); addwater(); }
  delay(2500);
}
