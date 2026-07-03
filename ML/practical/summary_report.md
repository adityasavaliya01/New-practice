# Telco Customer Churn Prediction – Summary Report

## Business Problem and Dataset Summary

Customer churn is one of the most significant challenges faced by telecom companies because retaining an existing customer is considerably less expensive than acquiring a new one. This project aims to develop a machine learning model that predicts whether a customer is likely to churn, enabling telecom operators such as Jio and Airtel to proactively identify high-risk customers and implement targeted retention strategies.

The project uses the IBM Telco Customer Churn dataset, which contains **7,043 customer records** and **21 original features** describing customer demographics, subscribed services, billing information, payment methods, contract details, and account tenure. The target variable is **Churn**, indicating whether a customer left the company ("Yes") or remained with the company ("No").

---

## Data Preprocessing and Class Imbalance Strategy

The dataset was first explored to understand its structure, missing values, and feature distributions. Blank values in the **TotalCharges** column were converted to numeric values and missing entries were handled appropriately.

Several new features were engineered to improve predictive performance, including:

- **tenure_group** – categorizes customers based on their tenure.
- **num_services** – counts the number of subscribed value-added services.
- **AutoPay** – indicates whether the customer uses an automatic payment method.

Binary categorical variables were encoded using binary mapping, while multi-category variables were transformed using One-Hot Encoding. The ordinal feature **tenure_group** was encoded using Label Encoding. Continuous numerical features such as **tenure**, **MonthlyCharges**, **TotalCharges**, and **num_services** were standardized using **StandardScaler**.

Since the dataset is imbalanced, **SMOTE (Synthetic Minority Oversampling Technique)** was applied **only to the training dataset after the train-test split** to generate synthetic samples for the minority churn class and improve the model's ability to identify churning customers.

---

## Model Evaluation and Recommendation

Four machine learning models were developed and evaluated:

- K-Nearest Neighbors (KNN)
- Gaussian Naive Bayes
- Support Vector Machine (SVM)
- Decision Tree Classifier

The models were compared using **Accuracy, Precision, Recall, F1-Score, and ROC-AUC**. Since customer churn prediction is an imbalanced classification problem, **Recall** was considered the most important evaluation metric because missing an actual churner is more costly than incorrectly identifying a loyal customer.

**Recommended Model:** **GauusianNB**.

The GauusianNB achieved strong Recall while remaining highly interpretable. Unlike black-box models, it clearly identifies the most influential customer characteristics affecting churn, making it easier for business stakeholders to understand and trust the predictions. This combination of predictive performance and interpretability makes it suitable for deployment in customer retention campaigns.

---

## Top Three Churn Signals and Business Actions

The analysis identified three major factors contributing to customer churn:

1. **Contract Type:** Customers on **Month-to-Month contracts** have the highest probability of churning. The retention team should target these customers with discounted long-term contract offers and loyalty benefits.

2. **Customer Tenure:** Customers with **shorter tenure** are significantly more likely to leave. Early engagement programs, welcome offers, and proactive customer support can improve long-term retention.

3. **Monthly Charges:** Customers paying **higher monthly charges** exhibit a higher churn tendency. Personalized pricing plans, bundled services, or targeted discounts may help retain these customers.

Since the retention team can contact only a limited number of customers each day, customers with the highest predicted churn probabilities should be prioritized for retention campaigns.

---

## Future Improvements

Several enhancements can further improve the predictive performance and business value of this project. Additional customer information such as complaint history, customer support interactions, network quality metrics, payment history, and service usage patterns could provide richer predictive features. More advanced machine learning algorithms such as XGBoost, LightGBM, or CatBoost may further improve prediction accuracy. Finally, the trained model can be deployed as a real-time prediction API using Flask or FastAPI and integrated with a Streamlit dashboard to support live customer churn monitoring and automated retention decision-making.
