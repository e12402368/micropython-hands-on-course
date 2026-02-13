import time
from machine import I2C
import bmi270

# I2C Setup für CY8CKIT-062S2-AI
i2c = I2C(scl='P0_2', sda='P0_3') 
bmi = bmi270.BMI270(i2c)

# ANSI Escape Sequenz: 
# \033[2J = Bildschirm löschen
# \033[H  = Cursor nach oben links bewegen
CLEAR_SCREEN = "\033[2J\033[H"

# --- Main Loop ---
while True:
    try:
        # Daten lesen
        accx, accy, accz = bmi.accel() 
        gyrox, gyroy, gyroz = bmi.gyro()    
        
        # Bildschirm bereinigen und Cursor zurücksetzen
        print(CLEAR_SCREEN, end="")

        
        print("-" * 40)   
        print("ACCELERATION (m/s²) :")
        print(f"   X: {accx:6.2f}    Y: {accy:6.2f}    Z: {accz:6.2f}")
        print("GYROSCOPE (°/s)     :")
        print(f"   X: {gyrox:6.2f}    Y: {gyroy:6.2f}    Z: {gyroz:6.2f}")
        print("-" * 40)
        
        # Kurze Pause, um Flackern zu reduzieren
        time.sleep(0.2)
        
    except OSError as e:
        print(f"Fehler beim Lesen des Sensors: {e}")
        time.sleep(1)