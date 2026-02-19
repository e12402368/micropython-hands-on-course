/*
* DEEPCRAFT Studio 5.8.4292+50129d917517243fc033cba30ce355705c84a08c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 02/17/2026 15:47:06 UTC. Any changes will be lost.
* 
* Model ID  250d51c7-7bd4-4ba1-ad44-78720a581c40
* 
* Memory    Size                      Efficiency
* Buffers   48000 bytes (RAM)         80 %
* State     2608 bytes (RAM)          100 %
* Readonly  75212 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv2d-medium-balanced-1
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | circle
* 2           | shaking
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
* Convolution 2D                 [50,3,16]       float      dequeue
*    filters = 16
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,16,16]
* Convolution 2D                 [50,3,16]       float      dequeue
*    filters = 16
*    kernel_size = [3,3]
*    strides = [1,1]
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,3,16,16]
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
* Dense                          [3]             float      dequeue
*    units = 3
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[32,3]
*    bias = float[3]
* Activation                     [3]             float      dequeue
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* int IMAI_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[3].
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
* (ACC) Accuracy 89.693 %
* (F1S) F1 Score 89.763 %
* 
* Name of class                                            (unlabelled)           circle          shaking
* (TP) True Positive or Correct Positive Prediction                1643              843              551
* (FN) False Negative or Incorrect Negative Prediction              324                4               21
* (FP) False Positive or Incorrect Positive Prediction               23              201              125
* (TN) True Negative or Correct Negative Prediction                1396             2338             2689
* (TPR) True Positive Rate or Sensitivity, Recall               83.53 %          99.53 %          96.33 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.38 %          92.08 %          95.56 %
* (PPV) Positive Predictive Value or Precision                  98.62 %          80.75 %          81.51 %
* (NPV) Negative Predictive Value                               81.16 %          99.83 %          99.23 %
* (FNR) False Negative Rate or Miss Rate                        16.47 %           0.47 %           3.67 %
* (FPR) False Positive Rate or Fall-Out                          1.62 %           7.92 %           4.44 %
* (FDR) False Discovery Rate                                     1.38 %          19.25 %          18.49 %
* (FOR) False Omission Rate                                     18.84 %           0.17 %           0.77 %
* (F1S) F1 Score                                                90.45 %          89.16 %          88.30 %
*/


#define IMAI_TEST_AVG_ACC 0.896928529238039 // Accuracy
#define IMAI_TEST_AVG_F1S 0.8976334278697728 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 1643, FN: 324, FP: 23, TN: 1396, TPR: 0.8352821555668, TNR: 0.9837914023960, PPV: 0.9861944777911, NPV: 0.8116279069767, FNR: 0.1647178444331, FPR: 0.0162085976039, FDR: 0.0138055222088, FOR: 0.1883720930232, F1S: 0.9044866501513, }, \
 {name: "circle", TP: 843, FN: 4, FP: 201, TN: 2338, TPR: 0.9952774498229, TNR: 0.9208349743993, PPV: 0.8074712643678, NPV: 0.9982920580700, FNR: 0.0047225501770, FPR: 0.0791650256006, FDR: 0.1925287356321, FOR: 0.0017079419299, F1S: 0.8915917503966, }, \
 {name: "shaking", TP: 551, FN: 21, FP: 125, TN: 2689, TPR: 0.9632867132867, TNR: 0.9555792466240, PPV: 0.8150887573964, NPV: 0.9922509225092, FNR: 0.0367132867132, FPR: 0.0444207533759, FDR: 0.1849112426035, FOR: 0.0077490774907, F1S: 0.8830128205128, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 94.975 %
* (F1S) F1 Score 94.965 %
* 
* Name of class                                            (unlabelled)           circle          shaking
* (TP) True Positive or Correct Positive Prediction                3810             3249             1900
* (FN) False Negative or Incorrect Negative Prediction              327               10              137
* (FP) False Positive or Incorrect Positive Prediction               63              272              139
* (TN) True Negative or Correct Negative Prediction                5233             5902             7257
* (TPR) True Positive Rate or Sensitivity, Recall               92.10 %          99.69 %          93.27 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.81 %          95.59 %          98.12 %
* (PPV) Positive Predictive Value or Precision                  98.37 %          92.27 %          93.18 %
* (NPV) Negative Predictive Value                               94.12 %          99.83 %          98.15 %
* (FNR) False Negative Rate or Miss Rate                         7.90 %           0.31 %           6.73 %
* (FPR) False Positive Rate or Fall-Out                          1.19 %           4.41 %           1.88 %
* (FDR) False Discovery Rate                                     1.63 %           7.73 %           6.82 %
* (FOR) False Omission Rate                                      5.88 %           0.17 %           1.85 %
* (F1S) F1 Score                                                95.13 %          95.84 %          93.23 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9497508745892081 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9496543432332015 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 3810, FN: 327, FP: 63, TN: 5233, TPR: 0.9209572153734, TNR: 0.9881042296072, PPV: 0.9837335398915, NPV: 0.9411870503597, FNR: 0.0790427846265, FPR: 0.0118957703927, FDR: 0.0162664601084, FOR: 0.0588129496402, F1S: 0.9513108614232, }, \
 {name: "circle", TP: 3249, FN: 10, FP: 272, TN: 5902, TPR: 0.9969315741024, TNR: 0.9559442824748, PPV: 0.9227492189718, NPV: 0.9983085250338, FNR: 0.0030684258975, FPR: 0.0440557175251, FDR: 0.0772507810281, FOR: 0.0016914749661, F1S: 0.9584070796460, }, \
 {name: "shaking", TP: 1900, FN: 137, FP: 139, TN: 7257, TPR: 0.9327442317133, TNR: 0.9812060573282, PPV: 0.9318293281020, NPV: 0.9814714633486, FNR: 0.0672557682866, FPR: 0.0187939426717, FDR: 0.0681706718979, FOR: 0.0185285366513, F1S: 0.9322865554465, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 85.526 %
* (F1S) F1 Score 85.579 %
* 
* Name of class                                            (unlabelled)           circle          shaking
* (TP) True Positive or Correct Positive Prediction                1324              823              577
* (FN) False Negative or Incorrect Negative Prediction              416               24               21
* (FP) False Positive or Incorrect Positive Prediction               17              273              171
* (TN) True Negative or Correct Negative Prediction                1428             2065             2416
* (TPR) True Positive Rate or Sensitivity, Recall               76.09 %          97.17 %          96.49 %
* (TNR) True Negative Rate or Specificity, Selectivity          98.82 %          88.32 %          93.39 %
* (PPV) Positive Predictive Value or Precision                  98.73 %          75.09 %          77.14 %
* (NPV) Negative Predictive Value                               77.44 %          98.85 %          99.14 %
* (FNR) False Negative Rate or Miss Rate                        23.91 %           2.83 %           3.51 %
* (FPR) False Positive Rate or Fall-Out                          1.18 %          11.68 %           6.61 %
* (FDR) False Discovery Rate                                     1.27 %          24.91 %          22.86 %
* (FOR) False Omission Rate                                     22.56 %           1.15 %           0.86 %
* (F1S) F1 Score                                                85.95 %          84.71 %          85.74 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.8552590266875981 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.8557901100305148 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 1324, FN: 416, FP: 17, TN: 1428, TPR: 0.7609195402298, TNR: 0.9882352941176, PPV: 0.9873228933631, NPV: 0.7744034707158, FNR: 0.2390804597701, FPR: 0.0117647058823, FDR: 0.0126771066368, FOR: 0.2255965292841, F1S: 0.8594612138915, }, \
 {name: "circle", TP: 823, FN: 24, FP: 273, TN: 2065, TPR: 0.9716646989374, TNR: 0.8832335329341, PPV: 0.7509124087591, NPV: 0.9885112494016, FNR: 0.0283353010625, FPR: 0.1167664670658, FDR: 0.2490875912408, FOR: 0.0114887505983, F1S: 0.8471435923829, }, \
 {name: "shaking", TP: 577, FN: 21, FP: 171, TN: 2416, TPR: 0.9648829431438, TNR: 0.9339002705836, PPV: 0.7713903743315, NPV: 0.9913828477636, FNR: 0.0351170568561, FPR: 0.0660997294163, FDR: 0.2286096256684, FOR: 0.0086171522363, F1S: 0.8573551263001, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_QUEUE

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "circle", "shaking"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xc7, 0x51, 0x0d, 0x25, 0xd4, 0x7b, 0xa1, 0x4b, 0xad, 0x44, 0x78, 0x72, 0x0a, 0x58, 0x1c, 0x40}

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

// data_out [3] (12 bytes)
#define IMAI_DATA_OUT_COUNT (3)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (35)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
int IMAI_dequeue(float *restrict data_out);
int IMAI_enqueue(const float *restrict data_in);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
