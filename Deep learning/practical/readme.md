# Deep Learning Practicals – Set C

## 📌 Project Overview

This repository contains five mini-projects completed as part of the Deep Learning Practical (Set C). The projects demonstrate the practical implementation of Artificial Neural Networks, Computer Vision, Convolutional Neural Networks, Recurrent Neural Networks and Transformers.

The main objective is to understand different deep learning architectures, perform data preprocessing, build and evaluate models, and explore their applications in real-world problems.

## 🎯 Projects Included

### 1. Artificial Neural Network (ANN)

- **Dataset:** Wine Recognition Dataset (Scikit-learn)
- **Task:** Multi-class classification of wine cultivars.
- **Features:** 13 chemical measurements.
- **Classes:** 3 wine categories.
- **Architecture:** Dense layers with 16 and 8 neurons, followed by a 3-neuron Softmax output layer.
- **Result:** 94.44% test accuracy.

### 2. OpenCV – Colour, Morphology & Face Detection

- **Dataset:** 5 images (4 from Scikit-image and 1 personal image).
- **Task:** Image processing and face detection.
- **Techniques Used:**
  - BGR to RGB and HSV colour conversion.
  - Colour masking using `cv2.inRange()`.
  - Erosion and dilation.
  - Sobel edge detection.
  - Haar Cascade face detection.
- **Result:** Successfully detected 1 face in the Astronaut image.

### 3. Convolutional Neural Network (CNN)

- **Dataset:** MNIST Handwritten Digits Dataset.
- **Training Samples:** 20,000 images.
- **Testing Samples:** 4,000 images.
- **Task:** Classification of handwritten digits (0–9).
- **Architecture:** Conv2D, MaxPooling2D, Flatten and Dense layers.
- **Result:** 97.62% test accuracy.
- **ANN Baseline:** 95.65% test accuracy.

### 4. Recurrent Neural Network (RNN)

- **Dataset:** Daily Minimum Temperatures in Melbourne.
- **Records:** 3,650 daily observations (1981–1990).
- **Task:** Predict the next day's minimum temperature using the previous 30 days.
- **Architecture:** GRU layer with 32 units and a Dense output layer.
- **Techniques Used:** MinMax Scaling, sequence creation and time-series forecasting.
- **Results:**
  - RMSE: 2.23°C
  - MAE: 1.75°C
  - Naive Baseline RMSE: 2.48°C

### 5. Transformers – NLP Applications

- **Dataset:** 5 India-related paragraphs.
- **Task:** Natural Language Processing using pre-trained Transformer models.
- **Models Used:**
  - DistilBERT – Fill-Mask.
  - DistilBERT – Question Answering.
  - DistilGPT-2 – Text Generation.
- **Techniques Used:** Masked word prediction, extractive question answering, text generation and temperature comparison.
- **Result:** 7 out of 10 question-answering responses were manually marked correct.

## 🛠️ Technologies & Libraries

The following technologies and Python libraries were used:

- Python
- NumPy
- Pandas
- Matplotlib
- Seaborn
- Scikit-learn
- TensorFlow / Keras
- OpenCV
- Scikit-image
- Hugging Face Transformers
- PyTorch

## 📂 Project Structure

```text
Deep-Learning-Practicals/
│
├── Step_1_ANN/
│   └── ANN_Wine.ipynb
│
├── Step_2_OpenCV/
│   └── OpenCV_Image_Processing.ipynb
│
├── Step_3_CNN/
│   └── CNN_MNIST.ipynb
│
├── Step_4_RNN/
│   └── RNN_Temperature.ipynb
│
├── Step_5_Transformers/
│   └── Transformers_NLP.ipynb
│
├── Step_6_Comparison/
│   └── Comparison_Reflection.ipynb
│
├── summary_report.md
├── requirements.txt
└── README.md
```

## ⚙️ Installation & Setup

**1. Clone the repository**

```bash
git clone https://github.com/your-username/Deep-Learning-Practicals.git
```

**2. Navigate to the project directory**

```bash
cd Deep-Learning-Practicals
```

**3. Install the required libraries**

```bash
pip install -r requirements.txt
```

**4. Launch Jupyter Notebook**

```bash
jupyter notebook
```

Open the required notebook and execute the cells sequentially.

## 📊 Results Summary

| Project | Evaluation Metric | Result |
|---|---|---:|
| ANN | Test Accuracy | 94.44% |
| OpenCV | Faces Detected | 1 |
| CNN | Test Accuracy | 97.62% |
| RNN (GRU) | RMSE | 2.23°C |
| Transformer | Correct Answers | 7/10 |

## 📚 Key Learnings

Through these practical implementations, I gained experience in:

- Understanding ANN architecture and multi-class classification.
- Performing image processing and face detection using OpenCV.
- Learning convolution, pooling and feature extraction in CNNs.
- Understanding sequential data processing and GRU-based forecasting.
- Exploring Transformer architectures and pre-trained NLP models.
- Evaluating models using accuracy, RMSE, MAE and classification reports.
- Understanding the strengths and limitations of different deep learning approaches.

## 👨‍💻 Author

**Aditya Savaliya**

BE – Computer Engineering

Interested in Artificial Intelligence, Machine Learning and Data Science.

---

*This repository is created for educational and practical learning purposes as part of Deep Learning Practical – Set C.*
