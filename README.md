# K-Means Clustering from Scratch (C) with Python Visualization

This repository contains an implementation of the **k-means clustering algorithm from scratch in C**, combined with **Python (matplotlib)** for data visualization.

The project was developed as part of a **Computational Intelligence** assignment and demonstrates the full workflow of:
- synthetic data generation,
- unsupervised clustering,
- centroid convergence,
- and visual inspection of results.

---

## Project Overview

The workflow of the project is:

1. **Generate synthetic 2D datasets**  
   Using `examples.c`, two datasets are created:
   - `examplesSDO.txt`
   - `examplesSDT.txt`  
   During generation, two plots are displayed for visual inspection.

2. **Apply K-Means clustering**  
   Using `kmeans.c`, the k-means algorithm:
   - assigns each point to a cluster,
   - iteratively updates centroids,
   - stops when convergence is reached,
   - reports the number of iterations and total clustering error.

3. **Visualize clustering results**  
   The final clusters and centroids are visualized using Python.

---

## Technologies Used

- **C (main language)**  
  - Full implementation of the k-means algorithm
  - Dataset generation
- **Python (supporting)**  
  - Data visualization using `matplotlib`

---

## Project Structure

```
.
├── examples.c            # Synthetic dataset generator
├── kmeans.c              # K-means clustering implementation
├── script.py             # Visualization of clustering results
├── pointSDO.py           # Dataset visualization (SDO)
├── pointSDT.py           # Dataset visualization (SDT)
├── examplesSDO.txt       # Generated dataset (input to k-means)
├── examplesSDT.txt       # Generated dataset
├── teams_data.txt        # Output: point-to-cluster assignments
├── centers_data.txt      # Output: final centroid coordinates
├── Report2.pdf           # Assignment report
└── README.md
```

---

## How to Run

### Requirements

- GCC compiler
- Python 3
- Python libraries:
  ```bash
  pip install matplotlib
  ```

---

### Step 1: Generate the datasets

Compile and run the dataset generator:

```bash
gcc examples.c -o examples -lm
./examples
```

This will:
- create `examplesSDO.txt` and `examplesSDT.txt`
- display **two plots** of the generated data

---

### Step 2: Run k-means clustering

Compile and run k-means:

```bash
gcc kmeans.c -o kmeans -lm
./kmeans
```

This will:
- read `examplesSDO.txt`
- iteratively compute cluster assignments
- print intermediate information such as:
  - initial point assignments
  - old and new centroid positions
  - number of iterations
  - total clustering error
- generate:
  - `teams_data.txt`
  - `centers_data.txt`
- display a **final clustering plot**

---

## Output Description

- **teams_data.txt**  
  Contains each data point with its assigned cluster.

- **centers_data.txt**  
  Contains the final coordinates of the centroids.

Example console output includes:
- centroid updates,
- convergence after a number of iterations,
- total clustering error.

---

## Notes

- The k-means algorithm is implemented **without external ML libraries**.
- Python is used strictly for visualization purposes.
- The project demonstrates understanding of:
  - unsupervised learning,
  - iterative optimization,
  - distance-based clustering.

---
