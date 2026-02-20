import array
import time
import deepcraft_model as m
from machine import I2C, Pin
import bmi270
import configuration as cfg
from lightbulb import MiLight

# --- Initialisierung ---

# DeepCraft AI Modell Setup
model = m.DEEPCRAFT()
model.init()
output_dim = model.get_model_output_dim()
input_dim = model.get_model_input_dim()
output_buffer = array.array('f', [0.0] * output_dim)
input_buffer = array.array('f', [0.0] * input_dim)

# IMU (BMI270) Setup
i2c = I2C(scl=Pin(cfg.I2C_SCL), sda=Pin(cfg.I2C_SDA))
bmi = bmi270.BMI270(i2c)

# Timing & State Variablen
next_tick = time.ticks_ms()
last_heartbeat = time.ticks_ms()
last_label_idx = -1  # Speichert die letzte erkannte Geste

print("--- System gestartet. Warte auf Gesten (50Hz) ---")

# --- Main Loop ---
while True:
    # Sensordaten
    ax, ay, az = bmi.accel()
    gx, gy, gz = bmi.gyro()
    
    # Input-Buffer
    input_buffer[0], input_buffer[1], input_buffer[2] = ax, ay, az
    input_buffer[3], input_buffer[4], input_buffer[5] = gx, gy, gz
    
    # Daten in das Modell einspeisen
    if model.enqueue(input_buffer) == -1:
        print("Error: Modell-Enqueue")
    
    # Modell-Ausgabe
    if model.dequeue(output_buffer) == 0:
        score = max(output_buffer)
        current_idx = list(output_buffer).index(score)
        
        # Diagnose: Alle 3 Sekunden Status-Update im Terminal
        if time.ticks_diff(time.ticks_ms(), last_heartbeat) > 3000:
            print(f"[Live-Monitor] Max Score: {score*100:.1f}% bei Index: {current_idx}")
            last_heartbeat = time.ticks_ms()

        # Logik für Geste-Erkennung
        if score > cfg.GESTURE_THRESHOLD:
            # Nur ausgeben, wenn es ein NEUER Index ist
            if current_idx != last_label_idx:
                print(f">>> EVENT: Geste erkannt! Index: {current_idx} ({score*100:.1f}%)")
                
                last_label_idx = current_idx
        else:
            if last_label_idx != -1:
                # Optional: print("--- Geste beendet / Neutraler Status ---")
                last_label_idx = -1

    # --- Timing-Steuerung (konstante Frequenz) ---
    sample_time_ms = int(cfg.SAMPLE_TIME * 1000)
    next_tick = time.ticks_add(next_tick, sample_time_ms)
    
    sleep_duration = time.ticks_diff(next_tick, time.ticks_ms())
    if sleep_duration > 0:
        time.sleep_ms(sleep_duration)
    else:
        next_tick = time.ticks_ms()
