from machine import Pin
import time
import configuration as cfg
from lightbulb import MiLight

# 1. Initialisierung der Lampe (Daten aus der configuration.py)
bulb = MiLight(cfg.BULB_IP, cfg.BULB_PORT)

# 2. Setup des Tasters an Pin P5.2
# IN: Eingang, PULL_UP: Interner Widerstand (aktiviert bei Tastendruck gegen GND)
button = Pin(cfg.BUTTON_PIN, Pin.IN, Pin.PULL_UP)

print("Test-Programm gestartet. Drücke den Taster an P5.2 zum Schalten.")

while True:
    # Falls der Taster gedrückt wird (Signal geht auf 0 / Low)
    if button.value() == 0:
        print("Taster gedrückt! Sende Toggle-Befehl...")
        
        # Befehl an die Lampe senden
        bulb.toggle()
        
        # Simples Entprellen (Debouncing), um Mehrfachauslösungen zu verhindern
        time.sleep(1)
    
    # Kurze Pause zur Entlastung der CPU
    time.sleep_ms(10)


