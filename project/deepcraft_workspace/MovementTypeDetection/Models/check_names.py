import h5py
import json

def inspect_details(filename):
    print(f"\n--- DETAIL-CHECK: {filename} ---")
    try:
        with h5py.File(filename, 'r') as f:
            # Config laden
            config_str = f.attrs.get('model_config')
            if isinstance(config_str, bytes):
                config_str = config_str.decode('utf-8')
            model_config = json.loads(config_str)
            
            # Layer Liste holen
            layers = model_config['config']['layers']
            
            # 1. Name des ersten Layers (Input)
            first_layer = layers[0]
            print(f"INPUT NAME: '{first_layer['config']['name']}'")
            
            # 2. Alle Layer Typen auflisten
            print("LAYER LISTE:")
            for l in layers:
                print(f"  - {l['class_name']} (Name: {l['config']['name']})")
                
    except Exception as e:
        print(f"Fehler: {e}")
        
# Pfade zu deinen Dateien (ggf. anpassen)
inspect_details("conv2d-medium-balanced-0/conv2d-medium-balanced-0.h5")
inspect_details("conv2d-medium-balanced-1/conv2d-medium-balanced-1.h5")