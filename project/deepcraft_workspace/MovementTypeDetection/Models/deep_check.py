import os
os.environ["TF_ENABLE_ONEDNN_OPTS"] = "0" # Warnungen unterdrücken
import tensorflow as tf
import h5py
import json

def analyze_deep(path):
    print(f"\n{'#'*40}")
    print(f"ANALYSE: {path}")
    print(f"{'#'*40}")

    if not os.path.exists(path):
        print(f"❌ DATEI NICHT GEFUNDEN: {path}")
        return

    # --- TEIL 1: Metadaten checken (ohne TensorFlow zu laden) ---
    try:
        with h5py.File(path, 'r') as f:
            # Keras Version auslesen
            k_ver = f.attrs.get('keras_version')
            backend = f.attrs.get('backend')
            
            # Decodieren falls Bytes
            if isinstance(k_ver, bytes): k_ver = k_ver.decode('utf-8')
            if isinstance(backend, bytes): backend = backend.decode('utf-8')
            
            print(f"📂 H5 Attribute:")
            print(f"   • Keras Version: {k_ver}")
            print(f"   • Backend:       {backend}")

            # Model Config JSON holen (Das Herzstück)
            config_str = f.attrs.get('model_config')
            if isinstance(config_str, bytes): config_str = config_str.decode('utf-8')
            model_config = json.loads(config_str)
            
            # Prüfen wie der Input definiert ist
            print(f"🔧 JSON Config Struktur:")
            if 'config' in model_config and 'input_layers' in model_config['config']:
                print(f"   • Input Layers (Functional API): {model_config['config']['input_layers']}")
            elif 'config' in model_config and 'layers' in model_config['config']:
                first_layer = model_config['config']['layers'][0]
                print(f"   • Erster Layer (Sequential): {first_layer['class_name']}")
                if 'batch_input_shape' in first_layer['config']:
                    print(f"     -> batch_input_shape: {first_layer['config']['batch_input_shape']}")
                else:
                    print(f"     -> ❌ WARNUNG: Kein 'batch_input_shape' im ersten Layer!")

    except Exception as e:
        print(f"❌ Fehler beim Lesen der Metadaten: {e}")

    # --- TEIL 2: TensorFlow Load Check ---
    try:
        print(f"\n🧠 TensorFlow Loading Check:")
        model = tf.keras.models.load_model(path, compile=False)
        
        # Inputs genau prüfen
        if model.inputs:
            for i, inp in enumerate(model.inputs):
                print(f"   • Input {i}:")
                print(f"     - Name:  '{inp.name}'")
                print(f"     - Shape: {inp.shape}")
                print(f"     - Dtype: {inp.dtype.name}") # WICHTIG: float32 vs float64
        else:
            print("   ❌ KEINE Inputs im Modellobjekt gefunden!")

    except Exception as e:
        print(f"❌ TensorFlow konnte das Modell nicht laden: {e}")

# Pfade ausführen
analyze_deep("conv2d-medium-balanced-0/conv2d-medium-balanced-0.h5")
analyze_deep("conv2d-medium-balanced-1/conv2d-medium-balanced-1.h5")