/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/19/2026 16:15:28 UTC. Any changes will be lost.
* 
* Model ID  ff26806b-9bee-4728-8ee5-93d02d9a825d
* 
* Memory    Size                      Efficiency
* Buffers   15200 bytes (RAM)         84 %
* State     2864 bytes (RAM)          100 %
* Readonly  84948 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-large-accuracy-2
* 
* Class Index | Symbol Label
* 0           | (unlabeled)
* 1           | On
* 2           | Off
* 3           | Dimmer
* 4           | Lighter
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [100,6]         float      dequeue
*    window_shape = [100,6]
*    stride = 60
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [100,6]         float      dequeue
*    contextual_length_sec = 2
*    prediction_freq = 5
* Input Layer                    [100,6]         float      dequeue
*    shape = [100,6]
* Convolution 1D                 [100,16]        float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,6,16]
* Batch Normalization            [100,16]        float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [100,16]        float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [100,16]        float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [100,16]        float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [100,16]        float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [100,16]        float      dequeue
*    filters = 16
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,16]
* Batch Normalization            [100,16]        float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [100,16]        float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [50,16]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [50,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,16,32]
* Batch Normalization            [50,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [50,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [50,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [25,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [25,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [25,32]         float      dequeue
*    activation = relu
*    trainable = True
* Convolution 1D                 [25,32]         float      dequeue
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [25,32]         float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [25,32]         float      dequeue
*    activation = relu
*    trainable = True
* Max pooling 1D                 [12,32]         float      dequeue
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Long Short-Term Memory         [12,32]         float      dequeue
*    units = 32
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,128]
*    recurrent_kernel = float[32,128]
*    bias = float[128]
* Global average pooling 1D      [32]            float      dequeue
*    trainable = True
* Dense                          [5]             float      dequeue
*    units = 5
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,5]
*    bias = float[5]
* Activation                     [5]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[5].
* 
* int IMAI_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[2,3].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 97.670 %
* (F1S) F1 Score 97.358 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5217                4                7               16               38
* (FN) False Negative or Incorrect Negative Prediction               38               29               29               17               13
* (FP) False Positive or Incorrect Positive Prediction               78                5                6               13               24
* (TN) True Negative or Correct Negative Prediction                  75             5370             5366             5362             5333
* (TPR) True Positive Rate or Sensitivity, Recall               99.28 %          12.12 %          19.44 %          48.48 %          74.51 %
* (TNR) True Negative Rate or Specificity, Selectivity          49.02 %          99.91 %          99.89 %          99.76 %          99.55 %
* (PPV) Positive Predictive Value or Precision                  98.53 %          44.44 %          53.85 %          55.17 %          61.29 %
* (NPV) Negative Predictive Value                               66.37 %          99.46 %          99.46 %          99.68 %          99.76 %
* (FNR) False Negative Rate or Miss Rate                         0.72 %          87.88 %          80.56 %          51.52 %          25.49 %
* (FPR) False Positive Rate or Fall-Out                         50.98 %           0.09 %           0.11 %           0.24 %           0.45 %
* (FDR) False Discovery Rate                                     1.47 %          55.56 %          46.15 %          44.83 %          38.71 %
* (FOR) False Omission Rate                                     33.63 %           0.54 %           0.54 %           0.32 %           0.24 %
* (F1S) F1 Score                                                98.90 %          19.05 %          28.57 %          51.61 %          67.26 %
*/


#define IMAI_TEST_AVG_ACC 0.9767011834319527 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9735807094683742 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5217, FN: 38, FP: 78, TN: 75, TPR: 0.9927687916270, TNR: 0.4901960784313, PPV: 0.9852691218130, NPV: 0.6637168141592, FNR: 0.0072312083729, FPR: 0.5098039215686, FDR: 0.0147308781869, FOR: 0.3362831858407, F1S: 0.9890047393364, }, \
 {name: "On", TP: 38, FN: 13, FP: 24, TN: 5333, TPR: 0.7450980392156, TNR: 0.9955198805301, PPV: 0.6129032258064, NPV: 0.9975682753460, FNR: 0.2549019607843, FPR: 0.0044801194698, FDR: 0.3870967741935, FOR: 0.0024317246539, F1S: 0.6725663716814, }, \
 {name: "Off", TP: 16, FN: 17, FP: 13, TN: 5362, TPR: 0.4848484848484, TNR: 0.9975813953488, PPV: 0.5517241379310, NPV: 0.9968395612567, FNR: 0.5151515151515, FPR: 0.0024186046511, FDR: 0.4482758620689, FOR: 0.0031604387432, F1S: 0.5161290322580, }, \
 {name: "Dimmer", TP: 4, FN: 29, FP: 5, TN: 5370, TPR: 0.1212121212121, TNR: 0.9990697674418, PPV: 0.4444444444444, NPV: 0.9946286349323, FNR: 0.8787878787878, FPR: 0.0009302325581, FDR: 0.5555555555555, FOR: 0.0053713650676, F1S: 0.1904761904761, }, \
 {name: "Lighter", TP: 7, FN: 29, FP: 6, TN: 5366, TPR: 0.1944444444444, TNR: 0.9988830975428, PPV: 0.5384615384615, NPV: 0.9946246524559, FNR: 0.8055555555555, FPR: 0.0011169024571, FDR: 0.4615384615384, FOR: 0.0053753475440, F1S: 0.2857142857142, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 97.711 %
* (F1S) F1 Score 97.615 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19873               81               82              156              294
* (FN) False Negative or Incorrect Negative Prediction              200               62              112               32               74
* (FP) False Positive or Incorrect Positive Prediction              277               31                9               37              126
* (TN) True Negative or Correct Negative Prediction                 616            20792            20763            20741            20472
* (TPR) True Positive Rate or Sensitivity, Recall               99.00 %          56.64 %          42.27 %          82.98 %          79.89 %
* (TNR) True Negative Rate or Specificity, Selectivity          68.98 %          99.85 %          99.96 %          99.82 %          99.39 %
* (PPV) Positive Predictive Value or Precision                  98.63 %          72.32 %          90.11 %          80.83 %          70.00 %
* (NPV) Negative Predictive Value                               75.49 %          99.70 %          99.46 %          99.85 %          99.64 %
* (FNR) False Negative Rate or Miss Rate                         1.00 %          43.36 %          57.73 %          17.02 %          20.11 %
* (FPR) False Positive Rate or Fall-Out                         31.02 %           0.15 %           0.04 %           0.18 %           0.61 %
* (FDR) False Discovery Rate                                     1.37 %          27.68 %           9.89 %          19.17 %          30.00 %
* (FOR) False Omission Rate                                     24.51 %           0.30 %           0.54 %           0.15 %           0.36 %
* (F1S) F1 Score                                                98.81 %          63.53 %          57.54 %          81.89 %          74.62 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9771057903271965 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9761514096326489 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19873, FN: 200, FP: 277, TN: 616, TPR: 0.9900363672595, TNR: 0.6898096304591, PPV: 0.9862531017369, NPV: 0.7549019607843, FNR: 0.0099636327404, FPR: 0.3101903695408, FDR: 0.0137468982630, FOR: 0.2450980392156, F1S: 0.9881411132933, }, \
 {name: "On", TP: 294, FN: 74, FP: 126, TN: 20472, TPR: 0.7989130434782, TNR: 0.9938829012525, PPV: 0.7, NPV: 0.9963983257081, FNR: 0.2010869565217, FPR: 0.0061170987474, FDR: 0.3, FOR: 0.0036016742918, F1S: 0.7461928934010, }, \
 {name: "Off", TP: 156, FN: 32, FP: 37, TN: 20741, TPR: 0.8297872340425, TNR: 0.9982192703821, PPV: 0.8082901554404, NPV: 0.9984595388244, FNR: 0.1702127659574, FPR: 0.0017807296178, FDR: 0.1917098445595, FOR: 0.0015404611755, F1S: 0.8188976377952, }, \
 {name: "Dimmer", TP: 81, FN: 62, FP: 31, TN: 20792, TPR: 0.5664335664335, TNR: 0.9985112615857, PPV: 0.7232142857142, NPV: 0.9970269492663, FNR: 0.4335664335664, FPR: 0.0014887384142, FDR: 0.2767857142857, FOR: 0.0029730507336, F1S: 0.6352941176470, }, \
 {name: "Lighter", TP: 82, FN: 112, FP: 9, TN: 20763, TPR: 0.4226804123711, TNR: 0.9995667244367, PPV: 0.9010989010989, NPV: 0.9946347305389, FNR: 0.5773195876288, FPR: 0.0004332755632, FDR: 0.0989010989010, FOR: 0.0053652694610, F1S: 0.5754385964912, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 97.708 %
* (F1S) F1 Score 97.452 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5836               14               15               19               41
* (FN) False Negative or Incorrect Negative Prediction               39               34               33               19               14
* (FP) False Positive or Incorrect Positive Prediction               91                8                5               11               24
* (TN) True Negative or Correct Negative Prediction                  98             6008             6011             6015             5985
* (TPR) True Positive Rate or Sensitivity, Recall               99.34 %          29.17 %          31.25 %          50.00 %          74.55 %
* (TNR) True Negative Rate or Specificity, Selectivity          51.85 %          99.87 %          99.92 %          99.82 %          99.60 %
* (PPV) Positive Predictive Value or Precision                  98.46 %          63.64 %          75.00 %          63.33 %          63.08 %
* (NPV) Negative Predictive Value                               71.53 %          99.44 %          99.45 %          99.69 %          99.77 %
* (FNR) False Negative Rate or Miss Rate                         0.66 %          70.83 %          68.75 %          50.00 %          25.45 %
* (FPR) False Positive Rate or Fall-Out                         48.15 %           0.13 %           0.08 %           0.18 %           0.40 %
* (FDR) False Discovery Rate                                     1.54 %          36.36 %          25.00 %          36.67 %          36.92 %
* (FOR) False Omission Rate                                     28.47 %           0.56 %           0.55 %           0.31 %           0.23 %
* (F1S) F1 Score                                                98.90 %          40.00 %          44.12 %          55.88 %          68.33 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9770778364116095 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.97451871539844 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5836, FN: 39, FP: 91, TN: 98, TPR: 0.9933617021276, TNR: 0.5185185185185, PPV: 0.9846465328159, NPV: 0.7153284671532, FNR: 0.0066382978723, FPR: 0.4814814814814, FDR: 0.0153534671840, FOR: 0.2846715328467, F1S: 0.9889849178105, }, \
 {name: "On", TP: 41, FN: 14, FP: 24, TN: 5985, TPR: 0.7454545454545, TNR: 0.9960059910134, PPV: 0.6307692307692, NPV: 0.9976662777129, FNR: 0.2545454545454, FPR: 0.0039940089865, FDR: 0.3692307692307, FOR: 0.0023337222870, F1S: 0.6833333333333, }, \
 {name: "Off", TP: 19, FN: 19, FP: 11, TN: 6015, TPR: 0.5, TNR: 0.9981745768337, PPV: 0.6333333333333, NPV: 0.9968511766655, FNR: 0.5, FPR: 0.0018254231662, FDR: 0.3666666666666, FOR: 0.0031488233344, F1S: 0.5588235294117, }, \
 {name: "Dimmer", TP: 14, FN: 34, FP: 8, TN: 6008, TPR: 0.2916666666666, TNR: 0.9986702127659, PPV: 0.6363636363636, NPV: 0.9943727242634, FNR: 0.7083333333333, FPR: 0.0013297872340, FDR: 0.3636363636363, FOR: 0.0056272757365, F1S: 0.4, }, \
 {name: "Lighter", TP: 15, FN: 33, FP: 5, TN: 6011, TPR: 0.3125, TNR: 0.9991688829787, PPV: 0.75, NPV: 0.9945400397088, FNR: 0.6875, FPR: 0.0008311170212, FDR: 0.25, FOR: 0.0054599602911, F1S: 0.4411764705882, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x6b, 0x80, 0x26, 0xff, 0xee, 0x9b, 0x28, 0x47, 0x8e, 0xe5, 0x93, 0xd0, 0x2d, 0x9a, 0x82, 0x5d}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [2,3] (24 bytes)
#define IMAI_DATA_IN_COUNT (6)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [5] (20 bytes)
#define IMAI_DATA_OUT_COUNT (5)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (110)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
