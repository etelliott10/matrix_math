# Matrix Math Notes

Vectors hold information. Matrices transform information. Shapes control
whether a transformation is valid. Transpose flips rows and columns.

## Learning Plan

| Week | Topics                                                    |
| ---- | --------------------------------------------------------- |
| 1    | Vectors, dot product, magnitude/length, cosine similarity |
| 2    | Matrices, matrix multiplication, shapes, transpose        |
| 3    | NumPy implementation + small neural network math          |
| 4    | Embeddings, vector search, recommendation systems         |

Roadmap: **probability → calculus basics → machine learning models → neural networks**

### Checklist

- [ ] Add and scale vectors
- [ ] Calculate vector length
- [ ] Calculate dot product
- [ ] Explain cosine similarity
- [ ] Multiply matrix × vector
- [ ] Multiply matrix × matrix
- [ ] Understand matrix shape rules
- [ ] Explain transpose
- [ ] Explain what a neural network weight matrix does
- [ ] Use NumPy for vectors/matrices
- [ ] Explain embeddings as vectors
- [ ] Build a tiny similarity search example

---

## Vectors

**What is a vector?**

- `[x, y]` — a list of numbers that represents something (direction, magnitude, or feature)
- `x`: left or right, `y`: up or down
- Words, images, and audio can all be represented as vectors of numbers

**Magnitude** — the strength/size (length) of a vector.

```
v = [a, b, c, d, ...]
||v|| = sqrt(a² + b² + c² + d² + ...)

Example: v = [2, 12]
||v|| = sqrt(2² + 12²) = 13.0
```

### Dot Product

Measures alignment/similarity between two vectors.

```
A = [1, 0]              A = [1, 0]              A = [1, 0]
B = [1, 0]              B = [0, 1]               B = [-1, 0]
A · B = 1*1 + 0*0 = 1   A · B = 1*0 + 0*1 = 0   A · B = 1*-1 + 0*0 = -1
same direction          perpendicular            opposite directions
```

- Positive dot product → similar direction
- Zero dot product → unrelated / perpendicular
- Negative dot product → opposite direction
- Higher score → more similar, lower score → less similar

### Cosine Similarity

Like the dot product, but cleaner for comparing direction — it ignores
vector length and focuses only on whether vectors point the same way.

```
cos(a, b) = (a · b) / (||a|| * ||b||)
```

### Dot Product vs. Cosine Similarity

| Concept           | Measures                 | Sensitive to Length |
| ----------------- | ------------------------ | ------------------- |
| Dot product       | alignment + magnitude    | Yes                 |
| Cosine similarity | direction similarity     | No                  |
| Distance          | how far apart points are | Yes                 |

**Summary**

- Vector = list of numbers representing something
- Magnitude = length of the vector
- Dot product = alignment score
- Cosine similarity = direction similarity, from -1 to 1

---

## Matrices

**What is a matrix?**

- Like a function that transforms an input vector into a new output vector
- A grid of numbers that can transform vectors, or store many vectors/data rows

**What does matrix multiplication do?**

- Creates a new vector/matrix output by combining rows and columns

**Why do dimensions/shapes matter?**

- They determine whether a transformation (or multiplication) is even valid

### Matrix × Vector

```
| 2 0 |   | 1 |   | (2*1) + (0*4) |   | 2  |
| 2 3 | × | 4 | = | (2*1) + (3*4) | = | 14 |
```

### Matrix × Matrix

```
| 2 0 |   | 1 4 |   | (2*1)+(0*4)  (2*4)+(0*1) |   | 2  8  |
| 2 3 | × | 0 1 | = | (2*0)+(3*1)  (2*1)+(3*4) | = | 3  14 |
```

### Key Rules

- Vector = list of numbers
- Matrix = grid of numbers
- Shape = rows × columns
- Transpose = flip rows and columns
- Matrix-vector multiplication = matrix transforms a vector
- Matrix-matrix multiplication = row dot column
- `A @ B` works only if `A`'s columns = `B`'s rows

---

## Embeddings & Search

- Embedding = an object (word, image, user, product) converted into a
  meaning vector
- Instead of comparing raw words, images, or users, we compare their vectors

### Vector Search vs. Keyword Search

| Search Type    | Looks At    | Good For                              |
| -------------- | ----------- | ------------------------------------- |
| Keyword search | exact words | precise terms, filters, names         |
| Vector search  | meaning     | semantic search, RAG, recommendations |
| Hybrid search  | both        | best production systems               |

- **Vector search** — given one vector, find the closest vectors in a database
- **Keyword search** — looks for matching words

### Recommendation Systems

A recommendation system ranks items for a user — it answers _"what should
this user see next?"_

- **Content-based filtering** — recommends items similar to what the user likes
- **Collaborative filtering** — recommends based on the behavior of similar users
- **Hybrid recommendation** — combines content similarity + user behavior +
  business rules (most real systems are hybrid)

### How Embeddings Power RAG

**RAG = Retrieval-Augmented Generation**

1. Split documents into chunks
2. Convert each chunk into an embedding
3. Store embeddings in a vector database
4. User asks a question
5. Convert the question into an embedding
6. Find similar chunks
7. Send those chunks to the LLM
8. LLM answers using the retrieved context

### Vector Database

A vector database stores embeddings and searches by similarity.

- Embedding = object converted to a meaning vector
- Vector search = find the nearest meaning vectors
- Recommendation system = rank items/users/content by similarity + behavior
