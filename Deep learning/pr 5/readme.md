# PR5: Sentiment Analysis Using RNN, LSTM and GRU

## Project Overview

This project implements sentiment analysis on movie reviews using deep learning techniques. It compares different neural network architectures, including an Artificial Neural Network (ANN), Simple Recurrent Neural Network (SimpleRNN), Long Short-Term Memory (LSTM), stacked LSTM, and Gated Recurrent Unit (GRU).

The main objective is to classify movie reviews as positive or negative and investigate how recurrent architectures handle sequential text, word order, long-range dependencies, and gradient-related problems.

The project also covers text preprocessing, tokenisation, sequence padding, manual forward propagation, Backpropagation Through Time (BPTT), gradient clipping, model evaluation, error analysis, and custom sentiment prediction.

## Dataset

- **Dataset:** IMDB Movie Reviews
- **Source:** [IMDB Dataset of 50K Movie Reviews — Kaggle](https://www.kaggle.com/datasets/lakshmi25npathi/imdb-dataset-of-50k-movie-reviews)
- **Input Features:** Review text and sentiment label
- **Target Classes:** Positive and negative

### Dataset observations

| Description | Observed value |
|---|---:|
| Rows loaded | 28,506 |
| Columns | 2 |
| Positive reviews before duplicate removal | 14,266 |
| Negative reviews before duplicate removal | 14,240 |
| Duplicate rows removed | 131 |
| Rows after duplicate removal | 28,375 |
| Training samples | 22,700 |
| Testing samples | 5,675 |
| Missing values | 0 |
| Maximum sequence length | 590 words |

**Note:** Although the Kaggle dataset is described as containing 50,000 reviews, the CSV used in this experiment loaded 28,506 rows. The results in this README correspond to the file actually processed by the notebook.

## Technologies Used

- Python
- Jupyter Notebook
- TensorFlow and Keras
- NumPy
- Pandas
- Matplotlib
- Seaborn
- Scikit-learn

## Project Workflow

1. Load and inspect the movie-review dataset.
2. Identify and remove duplicate reviews.
3. Clean review text by converting it to lowercase and removing HTML tags and unnecessary characters.
4. Analyse review-length distributions using histograms and boxplots.
5. Tokenise the text using the Keras Tokenizer with a vocabulary limit of 10,000 words.
6. Convert reviews into integer sequences and apply pre-padding and truncation.
7. Build an ANN baseline and investigate RNN input/output structures.
8. Implement manual RNN and LSTM calculations using NumPy.
9. Train SimpleRNN, LSTM, stacked LSTM, and GRU sentiment classifiers.
10. Investigate BPTT, vanishing gradients, exploding gradients, and gradient clipping.
11. Compare model performance using classification metrics and ROC curves.
12. Evaluate performance across different review lengths.
13. Analyse incorrect predictions and test custom review sentences.

## Task 1: Text Preprocessing and Sequence Preparation

The dataset was inspected for missing values, class distribution, and duplicate reviews. A total of 131 duplicate rows were removed, leaving 28,375 reviews.

The text-cleaning process included:
- Converting text to lowercase.
- Removing HTML tags.
- Removing unnecessary characters.
- Collapsing repeated spaces.
- Preserving apostrophes to retain meaningful contractions and negation.

The review-length analysis produced the following observations:

| Statistic | Observed value |
|---|---:|
| Mean review length | 229.79 words |
| Median review length | 172 words |
| 90th percentile | 450 words |
| 95th percentile | 590 words |

The distribution is right-skewed because some reviews are much longer than most reviews. A sequence length of 590 was selected based on the 95th percentile.

After tokenisation and padding, the dataset was divided into 22,700 training samples and 5,675 testing samples using a stratified 80:20 split.

## Task 2: ANN Baseline and RNN Forward Propagation

An ANN baseline was created using an embedding layer, a flattening layer, a dense hidden layer, and a sigmoid output layer.

The manual RNN forward-propagation calculation was verified against Keras SimpleRNN. The maximum absolute difference between the manual and Keras hidden-state outputs was approximately `8.92 × 10⁻⁸`, confirming that the two implementations produced nearly identical results.

The SimpleRNN layer with 64 hidden units and 32-dimensional input embeddings contained 6,208 parameters, excluding the embedding and output layers.

The experiment demonstrates that recurrent networks reuse weights across time steps, whereas a flatten-based ANN connects its dense layers to fixed input positions.

## Task 3: SimpleRNN Sentiment Classification

A SimpleRNN model was trained using an embedding layer, a recurrent layer with 64 units, and a sigmoid output layer.

### Observed results

- **Test accuracy:** 83.44%
- **ROC-AUC:** 0.9019
- **Total model parameters:** 326,273

The model learned useful sentiment patterns but performed less effectively than the LSTM model in the final comparison.

## Task 4: Backpropagation Through Time and Gradient Problems

This task investigated how gradients propagate through recurrent time steps and why recurrent networks can experience vanishing or exploding gradients.

The sequence-length experiment produced the following SimpleRNN accuracies:

| Sequence length | Test accuracy |
|---|---:|
| 50 | 73.43% |
| 100 | 63.89% |
| 200 | 80.85% |
| 300 | 81.09% |

The results were not consistently increasing with sequence length. This suggests that the effect of sequence length depends on the amount of useful information retained and the difficulty of learning from the sequence.

In the large-learning-rate experiment, the model without clipping developed NaN loss by the third epoch. The model configured with gradient clipping also developed NaN loss later in training.

Therefore, **gradient clipping did not fully stabilise this particular experiment**. A lower learning rate and further testing would be needed to determine a stable configuration.

The saved GradientTape experiment returned zero gradient norms. Consequently, the gradient-flow measurements from this run are inconclusive and should be corrected and rerun before drawing conclusions about the magnitude of vanishing gradients.

## Task 5: LSTM — Long Short-Term Memory

The LSTM model uses forget, input, and output gates together with a separate cell state. These mechanisms help the model retain and update information across sequential inputs.

The recurrent layer contained 24,832 parameters for 64 units and 32-dimensional embeddings. Including the embedding and classification layers, the complete model contained 344,897 parameters.

### Observed results

- **Test accuracy:** 86.98%
- **Precision:** 91.33%
- **Recall:** 81.81%
- **F1-score:** 86.31%
- **ROC-AUC:** 0.9408
- **Total model parameters:** 344,897
- **Training time:** Approximately 31.69 seconds for five epochs

The LSTM achieved the highest test accuracy and ROC-AUC among the five models in the final comparison. Its precision was higher than its recall, indicating that its positive predictions were relatively reliable, although it missed some positive reviews.

A stacked LSTM was also evaluated to investigate whether adding another recurrent layer improved performance. It achieved 85.18% test accuracy, which was lower than the single-layer LSTM in this experiment.

## Task 6: GRU — Gated Recurrent Unit

The GRU model uses update and reset gates without a separate cell state. Its update gate combines aspects of the information-retention and information-update behaviour handled by separate LSTM gates.

For 64 hidden units and 32-dimensional embeddings, the GRU recurrent layer contained 18,816 parameters. The complete model contained 338,881 parameters.

### Observed results

- **Test accuracy:** 85.52%
- **Precision:** 85.61%
- **Recall:** 85.49%
- **F1-score:** 85.55%
- **ROC-AUC:** 0.9328
- **Total model parameters:** 338,881
- **Training time:** Approximately 42.99 seconds for five epochs

The GRU produced balanced precision and recall and performed better than SimpleRNN in the final comparison. However, its test accuracy and ROC-AUC were lower than those of the single-layer LSTM.

### Hidden-unit sensitivity

The experiment compared LSTM and GRU models using 32, 64, and 128 hidden units.

| Model | Hidden units | Test accuracy | Total parameters |
|---|---:|---:|---:|
| LSTM | 32 | 84.69% | 328,353 |
| LSTM | 64 | 80.04% | 344,897 |
| LSTM | 128 | 70.36% | 402,561 |
| GRU | 32 | 82.77% | 326,369 |
| GRU | 64 | 84.25% | 338,881 |
| GRU | 128 | 83.45% | 382,337 |

In this run, increasing the number of hidden units did not consistently improve accuracy. The LSTM with 32 units performed best within the LSTM sensitivity experiment, while the GRU with 64 units performed best within its experiment.

These results show that additional model capacity does not automatically improve generalisation. However, the sensitivity experiment used separate short training runs, so these results should not be treated as a definitive ranking of the architectures.

## Task 7: Final Model Comparison

The following table summarises the observed test metrics saved in the notebook.

| Model | Accuracy | Precision | Recall | F1-score | ROC-AUC |
|---|---:|---:|---:|---:|---:|
| ANN baseline | 86.10% | 85.90% | 86.48% | 86.19% | 0.9343 |
| SimpleRNN | 83.44% | 82.67% | 84.76% | 83.70% | 0.9019 |
| LSTM | **86.98%** | **91.33%** | 81.81% | **86.31%** | **0.9408** |
| Stacked LSTM | 85.18% | 85.80% | 84.44% | 85.11% | 0.9255 |
| GRU | 85.52% | 85.61% | 85.49% | 85.55% | 0.9328 |

The LSTM achieved the best accuracy, precision, F1-score, and ROC-AUC among the evaluated models. The ANN baseline achieved the second-highest accuracy and slightly higher recall than the LSTM.

The SimpleRNN had the lowest accuracy and ROC-AUC in the comparison, indicating that it was less effective at distinguishing positive from negative reviews in this experiment.

### ROC curve observations

The ROC curves compare true-positive rate against false-positive rate across different classification thresholds.

The LSTM achieved the highest ROC-AUC of 0.9408, followed by the ANN baseline at 0.9343 and GRU at 0.9328. This shows that the LSTM provided the strongest overall class-ranking performance in this experiment.

Accuracy alone does not show how model performance changes with the classification threshold, whereas ROC-AUC evaluates discrimination across multiple thresholds.

## Sequence-Length Robustness

The best gated model selected for this comparison was LSTM. Its performance was compared with SimpleRNN on short, medium, and long reviews.

| Model | Short reviews | Medium reviews | Long reviews |
|---|---:|---:|---:|
| SimpleRNN | 84.27% | 84.06% | 81.83% |
| LSTM | **88.60%** | **87.73%** | **84.79%** |

Short reviews contain fewer than 100 words, medium reviews contain 100–250 words, and long reviews contain more than 250 words.

Both models performed less accurately on long reviews than on short reviews. The LSTM maintained higher accuracy across all three groups. Its accuracy dropped by approximately 3.81 percentage points from short to long reviews, compared with a drop of approximately 2.44 percentage points for SimpleRNN.

Although the LSTM showed a larger short-to-long accuracy gap, it remained more accurate on long reviews overall. This suggests that the LSTM handled the longer reviews more effectively in absolute performance, even though longer inputs remained challenging.

## Error Analysis

The notebook displayed four false-positive and four false-negative examples from the LSTM model.

A false positive occurs when a negative review is classified as positive. A false negative occurs when a positive review is classified as negative.

The custom prediction experiment produced the following observations:

| Custom review | Predicted sentiment | Positive probability |
|---|---|---:|
| This film is absolutely wonderful and I loved every minute. | Positive | 91.47% |
| This was a terrible and boring movie. | Negative | 2.47% |
| This film is not good. | Positive | 53.05% |
| I cannot say that it was not enjoyable. | Positive | 67.94% |
| Great acting, if your goal was to waste two hours. | Negative | 4.10% |
| Good. | Positive | 58.33% |

The model correctly classified the clearly positive and negative examples, as well as the sarcastic negative example. However, it classified “This film is not good” as positive, demonstrating a limitation in handling negation.

The very short review “Good.” was classified as positive, but with a relatively low positive probability compared with the clearly positive example. This illustrates how prediction confidence can vary depending on the input text.

The results also highlight the difficulty of interpreting double negation, sarcasm, mixed sentiment, and reviews in which negative words describe a character or event rather than the overall film.

## Final Recommendation: Which Recurrent Cell Should We Use?

Based on the saved experimental results, the **single-layer LSTM is the recommended recurrent architecture for this project**.

The reasons are:

1. It achieved the highest test accuracy at 86.98%.
2. It achieved the highest ROC-AUC at 0.9408.
3. It provided the highest precision and F1-score in the final comparison.
4. It outperformed SimpleRNN, GRU, and stacked LSTM on the final test set.
5. It maintained higher accuracy than SimpleRNN across short, medium, and long review groups.

The GRU is a reasonable alternative when a simpler gated architecture is preferred. The ANN baseline also performed competitively, achieving 86.10% accuracy with a larger parameter count than the recurrent models.

The stacked LSTM did not improve test performance over the single-layer LSTM in this run, despite having more parameters and requiring more training time.

These recommendations are based on the current experiment and should be validated with repeated runs and further testing before use in a production service.

## Project Files and Outputs

The notebook generated the following output files:

- `plots/full_results.csv` — model parameter counts, training information, and test accuracy.
- `plots/model_metrics.csv` — accuracy, precision, recall, F1-score, and ROC-AUC.
- `plots/roc_curves.png` — ROC curves for the evaluated models.
- `plots/sequence_length_robustness.png` — accuracy comparison by review length.
- `plots/misclassified_reviews.csv` — examples of incorrect predictions.
- `requirements.txt` — required Python libraries.

## How to Run the Project

### 1. Clone the repository

```bash
git clone <your-github-repository-url>
cd <your-repository-folder>
```

### 2. Install dependencies

```bash
pip install -r requirements.txt
```

### 3. Prepare the dataset

Place `IMDB Dataset.csv` in the project directory. Confirm that the file contains the expected `review` and `sentiment` columns.

### 4. Open Jupyter Notebook

```bash
jupyter notebook
```

### 5. Execute the notebook

Run the notebook cells in order, from Task 1 through Task 7. Ensure that the dataset, trained models, tokenizer, preprocessing function, and evaluation variables are available before executing the final comparison.

## Conclusion

This project demonstrates how neural networks can be applied to movie-review sentiment classification and how recurrent architectures differ in predictive performance, model size, and handling of sequential text.

In the saved experiment, LSTM provided the strongest overall classification performance, achieving 86.98% test accuracy and 0.9408 ROC-AUC. GRU offered competitive performance with fewer parameters than LSTM, while SimpleRNN performed less effectively on the final test set.

The experiments also demonstrated that increasing hidden units does not guarantee better accuracy, that long reviews remain challenging, and that negation can lead to incorrect predictions. Further work should correct the gradient-flow measurement, stabilise the gradient-clipping experiment, and validate the results across repeated training runs.
