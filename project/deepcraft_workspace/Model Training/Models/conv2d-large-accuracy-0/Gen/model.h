/*
* DEEPCRAFT Studio 5.9.4563.0+34bdb7f4372a1120ca38a0cb02e62db5b4b78270
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/19/2026 16:15:50 UTC. Any changes will be lost.
* 
* Model ID  cc706013-17f0-404d-aab3-67542f33c33a
* 
* Memory    Size                      Efficiency
* Buffers   38400 bytes (RAM)         100 %
* State     2608 bytes (RAM)          100 %
* Readonly  168532 bytes (Flash)      100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv2d-large-accuracy-0
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
* Reshape                        [100,6,1]       float      dequeue
*    shape = [100,6,1]
*    trainable = True
* Convolution 2D                 [50,3,16]       float      dequeue
*    filters = 16
*    kernel_size = [3,3]
*    strides = [2,2]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,1,16]
* Batch Normalization            [50,3,16]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [50,3,16]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,32]       float      dequeue
*    filters = 32
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,16,32]
* Batch Normalization            [50,3,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,3,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,32]       float      dequeue
*    filters = 32
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,32,32]
* Batch Normalization            [50,3,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,3,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,32]       float      dequeue
*    filters = 32
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,32,32]
* Batch Normalization            [50,3,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,3,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,32]       float      dequeue
*    filters = 32
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,32,32]
* Batch Normalization            [50,3,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,3,32]       float      dequeue
*    activation = relu
*    trainable = True
* Convolution 2D                 [50,3,32]       float      dequeue
*    filters = 32
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,32,32]
* Batch Normalization            [50,3,32]       float      dequeue
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 3
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [50,3,32]       float      dequeue
*    activation = relu
*    trainable = True
* Global average pooling 2D      [32]            float      dequeue
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
* (ACC) Accuracy 96.930 %
* (F1S) F1 Score 96.134 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5222                3               11                0                6
* (FN) False Negative or Incorrect Negative Prediction               33               30               25               33               45
* (FP) False Positive or Incorrect Positive Prediction              133                4               22                1                6
* (TN) True Negative or Correct Negative Prediction                  20             5371             5350             5374             5351
* (TPR) True Positive Rate or Sensitivity, Recall               99.37 %           9.09 %          30.56 %           0.00 %          11.76 %
* (TNR) True Negative Rate or Specificity, Selectivity          13.07 %          99.93 %          99.59 %          99.98 %          99.89 %
* (PPV) Positive Predictive Value or Precision                  97.52 %          42.86 %          33.33 %           0.00 %          50.00 %
* (NPV) Negative Predictive Value                               37.74 %          99.44 %          99.53 %          99.39 %          99.17 %
* (FNR) False Negative Rate or Miss Rate                         0.63 %          90.91 %          69.44 %         100.00 %          88.24 %
* (FPR) False Positive Rate or Fall-Out                         86.93 %           0.07 %           0.41 %           0.02 %           0.11 %
* (FDR) False Discovery Rate                                     2.48 %          57.14 %          66.67 %         100.00 %          50.00 %
* (FOR) False Omission Rate                                     62.26 %           0.56 %           0.47 %           0.61 %           0.83 %
* (F1S) F1 Score                                                98.44 %          15.00 %          31.88 %           0.00 %          19.05 %
*/


#define IMAI_TEST_AVG_ACC 0.9693047337278107 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9613396500464046 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "unlabeled", TP: 5222, FN: 33, FP: 133, TN: 20, TPR: 0.9937202664129, TNR: 0.1307189542483, PPV: 0.9751633986928, NPV: 0.3773584905660, FNR: 0.0062797335870, FPR: 0.8692810457516, FDR: 0.0248366013071, FOR: 0.6226415094339, F1S: 0.9843543826578, }, \
 {name: "On", TP: 6, FN: 45, FP: 6, TN: 5351, TPR: 0.1176470588235, TNR: 0.9988799701325, PPV: 0.5, NPV: 0.9916604892512, FNR: 0.8823529411764, FPR: 0.0011200298674, FDR: 0.5, FOR: 0.0083395107487, F1S: 0.1904761904761, }, \
 {name: "Off", TP: 0, FN: 33, FP: 1, TN: 5374, TPR: 0, TNR: 0.9998139534883, PPV: 0, NPV: 0.9938968004438, FNR: 1, FPR: 0.0001860465116, FDR: 1, FOR: 0.0061031995561, F1S: 0, }, \
 {name: "Dimmer", TP: 3, FN: 30, FP: 4, TN: 5371, TPR: 0.0909090909090, TNR: 0.9992558139534, PPV: 0.4285714285714, NPV: 0.9944454730605, FNR: 0.9090909090909, FPR: 0.0007441860465, FDR: 0.5714285714285, FOR: 0.0055545269394, F1S: 0.15, }, \
 {name: "Lighter", TP: 11, FN: 25, FP: 22, TN: 5350, TPR: 0.3055555555555, TNR: 0.9959046909903, PPV: 0.3333333333333, NPV: 0.9953488372093, FNR: 0.6944444444444, FPR: 0.0040953090096, FDR: 0.6666666666666, FOR: 0.0046511627906, F1S: 0.3188405797101, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 96.017 %
* (F1S) F1 Score 95.772 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction               19714               70              129               18              200
* (FN) False Negative or Incorrect Negative Prediction              359               73               65              170              168
* (FP) False Positive or Incorrect Positive Prediction              475               64              165               24              107
* (TN) True Negative or Correct Negative Prediction                 418            20759            20607            20754            20491
* (TPR) True Positive Rate or Sensitivity, Recall               98.21 %          48.95 %          66.49 %           9.57 %          54.35 %
* (TNR) True Negative Rate or Specificity, Selectivity          46.81 %          99.69 %          99.21 %          99.88 %          99.48 %
* (PPV) Positive Predictive Value or Precision                  97.65 %          52.24 %          43.88 %          42.86 %          65.15 %
* (NPV) Negative Predictive Value                               53.80 %          99.65 %          99.69 %          99.19 %          99.19 %
* (FNR) False Negative Rate or Miss Rate                         1.79 %          51.05 %          33.51 %          90.43 %          45.65 %
* (FPR) False Positive Rate or Fall-Out                         53.19 %           0.31 %           0.79 %           0.12 %           0.52 %
* (FDR) False Discovery Rate                                     2.35 %          47.76 %          56.12 %          57.14 %          34.85 %
* (FOR) False Omission Rate                                     46.20 %           0.35 %           0.31 %           0.81 %           0.81 %
* (F1S) F1 Score                                                97.93 %          50.54 %          52.87 %          15.65 %          59.26 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9601736144233521 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9577192375112807 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "unlabeled", TP: 19714, FN: 359, FP: 475, TN: 418, TPR: 0.9821152792308, TNR: 0.4680851063829, PPV: 0.9764723364208, NPV: 0.5379665379665, FNR: 0.0178847207691, FPR: 0.5319148936170, FDR: 0.0235276635791, FOR: 0.4620334620334, F1S: 0.9792856788038, }, \
 {name: "On", TP: 200, FN: 168, FP: 107, TN: 20491, TPR: 0.5434782608695, TNR: 0.9948053209049, PPV: 0.6514657980456, NPV: 0.9918679510140, FNR: 0.4565217391304, FPR: 0.0051946790950, FDR: 0.3485342019543, FOR: 0.0081320489859, F1S: 0.5925925925925, }, \
 {name: "Off", TP: 18, FN: 170, FP: 24, TN: 20754, TPR: 0.0957446808510, TNR: 0.9988449321397, PPV: 0.4285714285714, NPV: 0.9918753584400, FNR: 0.9042553191489, FPR: 0.0011550678602, FDR: 0.5714285714285, FOR: 0.0081246415599, F1S: 0.1565217391304, }, \
 {name: "Dimmer", TP: 70, FN: 73, FP: 64, TN: 20759, TPR: 0.4895104895104, TNR: 0.9969264755318, PPV: 0.5223880597014, NPV: 0.9964957757296, FNR: 0.5104895104895, FPR: 0.0030735244681, FDR: 0.4776119402985, FOR: 0.0035042242703, F1S: 0.5054151624548, }, \
 {name: "Lighter", TP: 129, FN: 65, FP: 165, TN: 20607, TPR: 0.6649484536082, TNR: 0.9920566146735, PPV: 0.4387755102040, NPV: 0.9968556501547, FNR: 0.3350515463917, FPR: 0.0079433853264, FDR: 0.5612244897959, FOR: 0.0031443498452, F1S: 0.5286885245901, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 96.801 %
* (F1S) F1 Score 96.067 %
* 
* Name of class                                               unlabeled           Dimmer          Lighter              Off               On
* (TP) True Positive or Correct Positive Prediction                5837                8               13                3                9
* (FN) False Negative or Incorrect Negative Prediction               38               40               35               35               46
* (FP) False Positive or Incorrect Positive Prediction              156                8               21                3                6
* (TN) True Negative or Correct Negative Prediction                  33             6008             5995             6023             6003
* (TPR) True Positive Rate or Sensitivity, Recall               99.35 %          16.67 %          27.08 %           7.89 %          16.36 %
* (TNR) True Negative Rate or Specificity, Selectivity          17.46 %          99.87 %          99.65 %          99.95 %          99.90 %
* (PPV) Positive Predictive Value or Precision                  97.40 %          50.00 %          38.24 %          50.00 %          60.00 %
* (NPV) Negative Predictive Value                               46.48 %          99.34 %          99.42 %          99.42 %          99.24 %
* (FNR) False Negative Rate or Miss Rate                         0.65 %          83.33 %          72.92 %          92.11 %          83.64 %
* (FPR) False Positive Rate or Fall-Out                         82.54 %           0.13 %           0.35 %           0.05 %           0.10 %
* (FDR) False Discovery Rate                                     2.60 %          50.00 %          61.76 %          50.00 %          40.00 %
* (FOR) False Omission Rate                                     53.52 %           0.66 %           0.58 %           0.58 %           0.76 %
* (F1S) F1 Score                                                98.37 %          25.00 %          31.71 %          13.64 %          25.71 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9680079155672823 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9606709481723783 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "unlabeled", TP: 5837, FN: 38, FP: 156, TN: 33, TPR: 0.9935319148936, TNR: 0.1746031746031, PPV: 0.9739696312364, NPV: 0.4647887323943, FNR: 0.0064680851063, FPR: 0.8253968253968, FDR: 0.0260303687635, FOR: 0.5352112676056, F1S: 0.9836535220761, }, \
 {name: "On", TP: 9, FN: 46, FP: 6, TN: 6003, TPR: 0.1636363636363, TNR: 0.9990014977533, PPV: 0.6, NPV: 0.9923954372623, FNR: 0.8363636363636, FPR: 0.0009985022466, FDR: 0.4, FOR: 0.0076045627376, F1S: 0.2571428571428, }, \
 {name: "Off", TP: 3, FN: 35, FP: 3, TN: 6023, TPR: 0.0789473684210, TNR: 0.9995021573182, PPV: 0.5, NPV: 0.9942225156817, FNR: 0.9210526315789, FPR: 0.0004978426817, FDR: 0.5, FOR: 0.0057774843182, F1S: 0.1363636363636, }, \
 {name: "Dimmer", TP: 8, FN: 40, FP: 8, TN: 6008, TPR: 0.1666666666666, TNR: 0.9986702127659, PPV: 0.5, NPV: 0.9933862433862, FNR: 0.8333333333333, FPR: 0.0013297872340, FDR: 0.5, FOR: 0.0066137566137, F1S: 0.25, }, \
 {name: "Lighter", TP: 13, FN: 35, FP: 21, TN: 5995, TPR: 0.2708333333333, TNR: 0.9965093085106, PPV: 0.3823529411764, NPV: 0.9941956882255, FNR: 0.7291666666666, FPR: 0.0034906914893, FDR: 0.6176470588235, FOR: 0.0058043117744, F1S: 0.3170731707317, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"(unlabeled)", "On", "Off", "Dimmer", "Lighter"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x13, 0x60, 0x70, 0xcc, 0xf0, 0x17, 0x4d, 0x40, 0xaa, 0xb3, 0x67, 0x54, 0x2f, 0x33, 0xc3, 0x3a}

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

#define IMAI_KEY_MAX (52)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
