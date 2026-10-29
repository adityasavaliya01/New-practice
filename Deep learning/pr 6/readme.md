# Transformer Architecture and NLP Toolkit

## 📌 Project Overview

This project explores Transformer architectures and their applications in Natural Language Processing (NLP) using Python and pretrained deep learning models. It combines theoretical concepts with practical implementations to understand how Transformers process text, calculate attention, generate sequences, and perform different NLP tasks.

The project also evaluates sentiment analysis performance, compares inference time at different input lengths, examines text generation reliability, and develops a reusable text toolkit for sentiment analysis, summarization, and English-to-French translation.

## 🎯 Objectives

- Understand the history, architecture, and applications of Transformer models.
- Implement scaled dot-product attention and explore self-attention mechanisms.
- Study multi-head attention, positional encoding, and layer normalization.
- Understand Transformer encoder and decoder architectures.
- Explore causal masking, padding masks, and cross-attention.
- Analyze pretrained models such as DistilBERT, GPT-2, and T5.
- Evaluate sentiment classification using accuracy, precision, recall, and F1-score.
- Compare model performance and inference time at different sequence lengths.
- Investigate factual errors in generated text.
- Build a reusable NLP toolkit that performs sentiment analysis, summarization, and translation.

## 🛠️ Technologies Used

- **Programming Language:** Python
- **Deep Learning Framework:** PyTorch
- **NLP and Transformer Models:** Hugging Face Transformers
- **Dataset Management:** Hugging Face Datasets
- **Data Processing:** NumPy, Pandas
- **Visualization:** Matplotlib, Seaborn
- **Model Evaluation:** Scikit-learn
- **Development Environment:** Jupyter Notebook

## 🤖 Models Used

| Model | Architecture | Application |
|---|---|---|
| DistilBERT | Encoder-only Transformer | Sentiment analysis, attention visualization, and masked-word prediction |
| GPT-2 | Decoder-only Transformer | Autoregressive text generation and text continuation |
| T5-small | Encoder-decoder Transformer | Text summarization and English-to-French translation |

The project uses pretrained models and does not fine-tune them for the experiments.

## 📚 Project Modules

### 1. Introduction to Transformers and Tokenization
- Explored Transformer applications, advantages, and limitations.
- Loaded a pretrained sentiment analysis pipeline.
- Examined tokenization, subword tokens, input IDs, padding, and attention masks.
- Inspected model configurations and parameter counts.

### 2. Self-Attention and Scaled Dot-Product Attention
- Implemented scaled dot-product attention.
- Studied Query (Q), Key (K), and Value (V) representations.
- Examined the purpose of scaling attention scores by the square root of the key dimension.
- Compared self-attention with Luong dot-product attention.
- Demonstrated why positional encoding is necessary.
- Compared manually calculated attention weights with DistilBERT attention outputs.

### 3. Multi-Head Attention and Positional Encoding
- Extracted and visualized attention heads from DistilBERT.
- Calculated attention entropy to examine attention distributions.
- Implemented sinusoidal positional encoding.
- Studied how positional information changes word representations.
- Inspected learned positional embeddings.
- Implemented layer normalization using NumPy.

### 4. Transformer Encoder and Masked Attention
- Inspected Transformer encoder modules and model dimensions.
- Analyzed parameter counts across model components.
- Used DistilBERT for masked-word prediction.
- Visualized bidirectional encoder attention.
- Implemented causal masking and examined its effect on attention weights.
- Compared padding masks with causal masks.
- Verified that causal masking prevents attention to future tokens.

### 5. Transformer Decoder, Cross-Attention, and Inference
- Studied the Transformer decoder architecture.
- Examined the difference between self-attention and cross-attention.
- Used T5 for English-to-French translation and text summarization.
- Extracted and visualized cross-attention weights.
- Implemented a manual autoregressive token-generation loop.
- Compared manual generation with the model's `generate()` method.
- Explored decoding strategies and key-value caching.
- Compared the DistilBERT, GPT-2, and T5 model families.

### 6. NLP Evaluation and Mini Text Toolkit
- Evaluated sentiment classification on 200 IMDB test reviews.
- Calculated accuracy, precision, recall, and F1-score.
- Compared sentiment performance at maximum input lengths of 64, 128, 256, and 512 tokens.
- Measured inference time at different sequence lengths.
- Tested GPT-2 with factual prompts to investigate generation reliability.
- Developed a reusable `text_toolkit()` function that performs:
  - Sentiment analysis using DistilBERT.
  - Text summarization using T5.
  - English-to-French translation of the generated summary using T5.
- Tested the toolkit on product reviews, news-style text, and technology passages.
- Added handling for empty or invalid input.

## 📊 Results

### Sentiment Analysis Evaluation

The pretrained DistilBERT sentiment classifier was evaluated on 200 randomly selected IMDB test reviews using a fixed random seed.

| Metric | Result |
|---|---:|
| Accuracy | 87.00% |
| Precision | 88.89% |
| Recall | 83.33% |
| F1-Score | 86.02% |

### Performance at Different Input Lengths

| Maximum Input Length | Accuracy | F1-Score | Runtime (seconds) |
|---:|---:|---:|---:|
| 64 tokens | 75.00% | 72.53% | 0.50 |
| 128 tokens | 77.50% | 76.92% | 0.78 |
| 256 tokens | 84.00% | 82.61% | 1.35 |
| 512 tokens | 87.00% | 86.02% | 2.62 |

In this experiment, increasing the maximum input length improved sentiment classification performance but also increased runtime. The measurements were obtained in the notebook's execution environment and may differ on other hardware.

### Inference Latency

DistilBERT's mean forward-pass latency was measured using different sequence lengths on a CPU.

| Sequence Length | Mean Latency |
|---:|---:|
| 32 tokens | 71.70 ms |
| 64 tokens | 102.80 ms |
| 128 tokens | 172.91 ms |
| 256 tokens | 303.73 ms |
| 512 tokens | 570.80 ms |

The experiment showed that longer input sequences required more inference time.

### Text Toolkit Output

The toolkit was tested on three types of passages:

- Product review
- News-style passage
- Technology passage

For each passage, the function returned a sentiment label, confidence score, generated summary, French translation, and execution status. It also returned an appropriate validation message for empty input.

### Run the Project

1. Clone or download this repository.
2. Open the project folder.
3. Start Jupyter Notebook.
4. Open `pr 6.ipynb`.
5. Execute the notebook cells in order.

The notebook downloads the required pretrained models and IMDB dataset when they are not already available locally. The initial setup and inference may take time depending on your internet connection and hardware.

## 📁 Project Structure

```text
Transformer-Architecture-and-NLP-Toolkit/
│
├── pr 6.ipynb
└── README.md
```

## ⚠️ Limitations

- Transformer inference time increases with input sequence length.
- Models have maximum input-length limits, and longer text may be truncated.
- Pretrained language models can generate factually incorrect or repetitive text.
- Sentiment predictions may not correctly interpret sarcasm, context, or complex opinions.
- Summaries and translations may not always preserve the original meaning.
- Model outputs require validation before being used in real-world applications.
- The project uses pretrained models without task-specific fine-tuning.

## 🚀 Future Improvements

- Build an interactive web application for the NLP toolkit.
- Add support for more languages and translation directions.
- Compare additional pretrained Transformer models.
- Evaluate the models on larger and more diverse datasets.
- Add automated factuality and translation-quality evaluation.
- Optimize inference speed and memory consumption.
- Add support for uploading text files and processing multiple documents.

## 📖 Key Learnings

Through this project, I gained practical experience with Transformer architectures, attention mechanisms, tokenization, positional encoding, masking, encoder-decoder models, autoregressive generation, and pretrained NLP pipelines.

I also learned how to evaluate classification performance, benchmark inference latency, visualize attention patterns, and examine the limitations of generated text.

## 👨‍💻 Author

**Aditya Savaliya**

Computer Engineering Student | AI/ML and Data Science Learner

---
