# Summary Report

## Mall Customer Segmentation Using Unsupervised Learning

### 1. Business Problem and Dataset

The primary objective of this project was to segment mall customers into meaningful groups based on their demographic information and purchasing behaviour. Customer segmentation enables retail businesses to understand different types of shoppers, allowing them to design personalized marketing campaigns, improve customer satisfaction, increase customer retention, and optimize business decisions. The analysis was performed using the **Mall Customers** dataset, which contains **200 customer records** with four main attributes: **Gender, Age, Annual Income (k$), and Spending Score (1–100)**. Since the dataset does not contain predefined customer categories, unsupervised machine learning algorithms were used to identify natural customer segments.

---

### 2. Features Used for Clustering (2D vs 5D)

Two different feature sets were used for clustering experiments.

The **2D feature set** consisted of **Annual Income (k$)** and **Spending Score (1–100)**. These two variables directly represent customers' purchasing power and spending behaviour, making them ideal for visualization and customer segmentation.

The second experiment used a richer **5D feature set**, which included **Age**, **Annual Income (k$)**, **Spending Score (1–100)**, and **Gender_enc** (label-encoded Gender). Although the assignment refers to this as 5D clustering, the provided features form a four-dimensional dataset. The additional demographic information was included to determine whether it improved clustering quality compared to the simpler 2D representation.

---

### 3. Best Performing Algorithm

Three clustering algorithms were evaluated: **K-Means**, **Agglomerative Hierarchical Clustering**, and **DBSCAN**. Their performance was compared using **Silhouette Score**, **Davies–Bouldin Index**, and **Calinski–Harabasz Index**.

Among these algorithms, **K-Means** produced the best overall results by generating compact, well-separated, and highly stable customer clusters. Agglomerative Clustering using Ward linkage produced results very similar to K-Means but was slightly less effective according to the internal evaluation metrics. DBSCAN successfully identified noise points; however, because the Mall Customers dataset is relatively clean and naturally clustered, it produced fewer meaningful customer groups. Overall, the algorithm's output aligned well with business intuition, as the identified customer segments closely matched realistic shopping behaviours observed in retail environments.

---

### 4. Shopper Segments

**Big Spenders:** Customers with high annual income and high spending scores. They frequently purchase premium products and should be targeted through VIP memberships, exclusive events, and luxury brand promotions.

**Young Aspirers:** Young customers with relatively lower income but high spending behaviour. They respond well to fashion trends, entertainment offers, student discounts, and digital marketing campaigns.

**Average Customers:** Customers with moderate income and average spending habits. Loyalty programs, personalized recommendations, and seasonal promotions can encourage repeat purchases.

**Budget Shoppers:** Customers with low income and low spending behaviour. These customers are highly price-sensitive and are attracted by discounts, cashback offers, festival sales, and value-for-money brands.

**Mature Savers:** Customers with high income but relatively low spending scores. Premium experiences, family shopping packages, dining vouchers, and personalized offers can motivate increased spending.

---

### 5. Future Improvements

The current analysis uses only demographic information and spending behaviour. Future work can significantly improve customer segmentation by collecting additional behavioural data such as purchase history, product categories, loyalty app usage, visit frequency, payment methods, average transaction value, and time spent inside the mall. More advanced techniques, including **semi-supervised learning**, **deep clustering**, and a **real-time customer persona tagging API** integrated with the mall's loyalty application, could provide dynamic customer segmentation and highly personalized marketing recommendations. These enhancements would help mall management improve customer engagement, increase sales, and make more informed business decisions.
