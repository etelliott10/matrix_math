import numpy as np

def cosine_similarity(a, b):
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

query = np.array([0.9, 0.1, 0.8])

docs = {
    "Face-off training drills": np.array([1.0, 0.0, 0.9]),
    "Best gaming keyboards": np.array([0.1, 1.0, 0.1]),
    "Strength training for athletes": np.array([0.7, 0.0, 0.9]),
}

results = []

for title, vector in docs.items():
    score = cosine_similarity(query, vector)
    results.append((title, score))

results.sort(key=lambda x: x[1], reverse=True)

print(results)