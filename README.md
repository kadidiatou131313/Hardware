# Hardware for Signal Processing

# Practical Assignment – Concurrency, SPD Matrices and Performance Measures

This repository contains the implementation and analysis of a practical assignment focused on concurrent programming, numerical linear algebra, and performance evaluation in machine learning models.

## Repository Content

- `HSP.pdf**  
  **This file contains the full written report of the practical assignment**, including explanations, results, and discussions for all parts.

- `main.cpp`  
  Main C++ program used to test the wallet system in sequential and multi-threaded contexts.

- `wallet.h`  
  Header file defining the `Wallet` class and its interfaces, including thread-safe mechanisms.

- `wallet.cpp`  
  Implementation of the `Wallet` class, including mutex-based synchronization and the instant wallet mechanism.

- `main.exe`  
  Compiled executable of the C++ program.

- `main.obj`, `wallet.obj`  
  Object files generated during the compilation process.

- `SPD_matrix.ipynb`  
  Jupyter notebook implementing operations on symmetric positive definite (SPD) matrices using PyTorch. It includes vectorization, devectorization, matrix square root, matrix logarithm, and performance comparisons between optimized and non-optimized implementations.

- `measures_diffusion_model.ipynb`  
  Jupyter notebook dedicated to the estimation of FLOPs for a diffusion model. It presents both analytical and automatic methods to evaluate the computational cost of the noise prediction network.

## Project Overview

The project is structured in three main parts:
1. Multi-threading and synchronization in C++.
2. Vectorized numerical operations on SPD matrices using PyTorch.
3. Performance measurement and FLOPs estimation for a diffusion model.

This repository provides both code and experimental results to illustrate key concepts in efficient and reliable computing.
