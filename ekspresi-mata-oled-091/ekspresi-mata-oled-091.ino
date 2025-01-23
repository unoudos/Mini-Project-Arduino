#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  mirarIzquierda();
  delay(1500);
  parpadear();
  delay(150);
  mirarDerecha();
  delay(1500);
  parpadear();
  delay(150);
  plana();
  delay(1500);
  parpadear();
  delay(150);
  enojado();
  delay(1500);
  parpadear();
  delay(150);
  triste();
  delay(1500);
  parpadear();
  delay(150);
  feliz();
  delay(1500);
  parpadear();
  delay(150);
}

void mirarIzquierda() {
  // Mirando hacia la izquierda (ambos ojos llenan la pantalla y están en el centro)
  display.clearDisplay();
  display.fillRoundRect(0, 0, 50, 32, 8, SSD1306_WHITE); // El ojo izquierdo está en el centro de la pantalla con una forma redondeada más pequeña.
  display.fillRoundRect(58, 4, 45, 24, 6, SSD1306_WHITE); // El ojo derecho es más pequeño y está colocado ligeramente más alto.
  display.display();
}

void mirarDerecha() {
  //Mira hacia la derecha (ambos ojos llenan la pantalla y están en el centro)
  display.clearDisplay();
  display.fillRoundRect(24, 4, 45, 24, 6, SSD1306_WHITE); // El ojo izquierdo es más pequeño y está colocado ligeramente más alto.
  display.fillRoundRect(76, 0, 50, 32, 8, SSD1306_WHITE); // El ojo derecho está en el medio de la pantalla con una forma redondeada más pequeña.
  display.display();
}

void plana() {
  // Expresión plana (ambos ojos llenan la pantalla y están en el centro)
  display.clearDisplay();
  display.fillRoundRect(9, 0, 50, 32, 8, SSD1306_WHITE); // El ojo izquierdo está en el centro de la pantalla con una forma redondeada más pequeña.
  display.fillRoundRect(69, 0, 50, 32, 8, SSD1306_WHITE); // El ojo derecho está en el medio de la pantalla con una forma redondeada más pequeña.
  display.display();
}

void enojado() {
  //Expresión de enojo (ambos ojos llenan la pantalla y están en el centro)
  display.clearDisplay();
  display.fillRoundRect(9, 0, 50, 32, 8, SSD1306_WHITE); // El ojo izquierdo está en el medio con una forma redondeada más pequeña.
  display.fillRoundRect(69, 0, 50, 32, 8, SSD1306_WHITE); //El ojo derecho está en el medio con una forma redondeada más pequeña.
  display.fillTriangle(9, 0, 59, 0, 59, 16, SSD1306_BLACK); // Corte izquierdo: de arriba a izquierda a abajo a derecha
  display.fillTriangle(69, 0, 69, 16, 119, 0, SSD1306_BLACK); // Corte derecho: de arriba a la derecha a abajo a la izquierda
  display.display();
}

void triste() {
  //Expresión Triste (ambos ojos llenan la pantalla y están centrados)
  display.clearDisplay();
  display.fillRoundRect(9, 0, 50, 32, 8, SSD1306_WHITE); // El ojo izquierdo está en el medio con una forma redondeada más pequeña.
  display.fillRoundRect(69, 0, 50, 32, 8, SSD1306_WHITE); // El ojo derecho está en el medio con una forma redondeada más pequeña.
  display.fillTriangle(59, 0, 9, 0, 9, 16, SSD1306_BLACK); // Corte izquierdo: de arriba a la derecha a abajo a la izquierda
  display.fillTriangle(69, 0, 119, 16, 119, 0, SSD1306_BLACK); // Corte derecho: de arriba a izquierda a abajo a derecha
  display.display();
}

void feliz() {
  // Happy Expression (ambos ojos llenan la pantalla y están centrados)
  display.clearDisplay();
  display.fillRoundRect(9, 0, 50, 32, 8, SSD1306_WHITE); // El ojo izquierdo está en el medio con una forma redondeada más pequeña.
  display.fillRoundRect(69, 0, 50, 32, 8, SSD1306_WHITE); // El ojo derecho está en el medio con una forma redondeada más pequeña.
  display.fillTriangle(59, 32, 9, 32, 9, 16, SSD1306_BLACK); //Corte izquierdo: de abajo derecha a arriba izquierda
  display.fillTriangle(69, 32, 119, 32, 119, 16, SSD1306_BLACK); // Corte derecho: de abajo izquierda a arriba derecha
  display.display();
}

void parpadear() {
  // Ojos parpadeantes (ambos ojos cerrados llenan la pantalla y están centrados)
  display.clearDisplay();
  display.fillRoundRect(9, 14, 50, 4, 2, SSD1306_WHITE); // Ojo izquierdo cerrado
  display.fillRoundRect(69, 14, 50, 4, 2, SSD1306_WHITE); // Ojo derecho cerrado
  display.display();
}
