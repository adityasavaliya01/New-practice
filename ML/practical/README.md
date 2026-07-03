# 📊 Telco Customer Churn Prediction using Machine Learning

## 📌 Project Overview

Customer churn is one of the biggest challenges faced by telecom companies. Losing existing customers directly affects revenue, and acquiring new customers is significantly more expensive than retaining existing ones.

This project builds a Machine Learning model to predict whether a telecom customer is likely to churn. The objective is to help telecom companies such as **Jio** and **Airtel** identify high-risk customers so that the retention team can proactively contact them with personalized offers and reduce customer loss.

---

# 📂 Dataset

**Dataset Name:** IBM Telco Customer Churn Dataset

The dataset contains information about telecom customers including:

- Customer demographics
- Services subscribed
- Contract type
- Payment method
- Monthly charges
- Total charges
- Customer tenure
- Churn status (Target Variable)

**Target Variable**

- Churn
  - Yes → Customer left the company
  - No → Customer stayed with the company

---

# 🛠 Technologies Used

- Python
- Pandas
- NumPy
- Matplotlib
- Seaborn
- Scikit-Learn
- Imbalanced-Learn (SMOTE)
- Joblib
- Jupyter Notebook

---

# 📋 Project Workflow

## 1. Data Preprocessing

- Loaded dataset
- Checked data types
- Handled missing values
- Removed inconsistencies
- Converted TotalCharges to numeric format

---

## 2. Exploratory Data Analysis (EDA)

Performed various visualizations including:

- Countplot of Churn
- Churn by Contract Type
- Churn by Tenure Group
- Monthly Charges vs Churn
- Correlation Heatmap
- ROC Curves
- Feature Importance
- Model Comparison Charts

---

## 3. Feature Engineering

Created new features:

- tenure_group
- num_services
- AutoPay

---

## 4. Feature Encoding

Applied:

- Binary Encoding
- One-Hot Encoding
- Label Encoding

---

## 5. Feature Scaling

Applied **StandardScaler** on:

- tenure
- MonthlyCharges
- TotalCharges
- num_services

---

## 6. Handling Class Imbalance

Used **SMOTE (Synthetic Minority Over-sampling Technique)** only on the training dataset after train-test split.

---

## 7. Machine Learning Models

The following classification models were trained and evaluated:

- K-Nearest Neighbors (KNN)
- Gaussian Naive Bayes
- Support Vector Machine (SVM)
- Decision Tree Classifier

---

## 8. Hyperparameter Tuning

Performed tuning for:

### KNN

- Tuned K values
- Selected best K using F1-Score

### SVM

- Tuned C parameter using 3-Fold Cross Validation

### Decision Tree

- Tuned max_depth
- Compared different tree depths

---

## 9. Model Evaluation

Models were evaluated using:

- Accuracy
- Precision
- Recall
- F1-Score
- ROC-AUC Score
- Confusion Matrix
- ROC Curve

A comparison table was created to compare all models.

---

## 10. Error Analysis

Performed analysis of:

- False Negatives
- Customer profile of missed churners
- Feature Importance
- Business insights

---

# 📈 Business Insights

Some important churn indicators discovered during analysis include:

- Customers with Month-to-Month contracts are more likely to churn.
- Customers with shorter tenure have a higher churn probability.
- Customers paying higher monthly charges are more likely to leave.
- Long-term contract customers generally have lower churn rates.

These insights can help telecom companies prioritize customer retention campaigns.

---

# 🤖 Model Deployment

The final trained model was saved using **Joblib**.

```python
joblib.dump(pipeline, "churn_model.pkl")
```

The saved model can later be loaded for real-time churn prediction.

---

# 📁 Project Structure

```
Telco-Customer-Churn-Prediction/
│
├── practical.ipynb
├── churn_model.pkl
├── requirements.txt
├── summary_report.md
├── README.md
├── WA_Fn-UseC_-Telco-Customer-Churn.csv
└── images/
```

---

# ▶️ How to Run

### Clone the repository

```bash
git clone https://github.com/yourusername/Telco-Customer-Churn-Prediction.git
```

### Install dependencies

```bash
pip install -r requirements.txt
```

### Open Jupyter Notebook

```bash
jupyter notebook
```

Open:

```
practical.ipynb
```

Run all cells sequentially.

---

# 📊 Evaluation Metrics

The models were compared using:

- Accuracy
- Precision
- Recall
- F1 Score
- ROC-AUC

Special emphasis was given to **Recall**, since identifying customers who are likely to churn is more important than minimizing false alarms.

---

# 🚀 Future Improvements

- Collect more customer behavior data
- Include complaint and customer support history
- Use advanced boosting models such as XGBoost or LightGBM
- Deploy the model using Flask/FastAPI
- Build a Streamlit dashboard for real-time churn prediction

---
