
# Neuronal network in C++

A personal project where I developed a basic neuronal network using C++ language.

## Index

- [TO-DO List](#to-do-list)
- [How to build](#build)

### TO-DO List

| 🟢 : Ready | 🔵 : In progress | ⚪️ : To-do

---

🟢  Create basic maths algorithms and classes.

🟢 Create basic neuronal network.

🔵 Implement backprogation algorithm.

    - 🔵 Implement gradient descent algorithm.
    - ⚪️ Use the backpropagation algorithm to train the network.
    - ⚪️ Implement the feedforward algorithm.

⚪️ Paralellize with kokos Kokkos.

⚪️ Paralellize with CUDA.

### Build

Go to `build` folder, and run the following commands:

```bash
cmake ..
make
```

Then at the same folder you will find the executable file `nnc`.

## Contributors
<a href="https://github.com/uwo-o/Neuronal-Network-C/graphs/contributors">
<img src="https://contrib.rocks/image?repo=uwo-o/Neuronal-Network-C" />
</a>

---
Based and inspired by [Neuronal Networks - 3Blue1Brown](https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&ab_channel=3Blue1Brown)

### References
#### Backpropagation algorithm
- [Backpropagation](https://en.wikipedia.org/wiki/Backpropagation)
- [Understanding Backpropagation Algorithm](https://towardsdatascience.com/understanding-backpropagation-algorithm-7bb3aa2f95fd)