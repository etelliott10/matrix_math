import numpy as np

def cosine_similarity(a, b):
    return np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

user = np.array([0.9, 0.1, 0.8])  # sports, gaming, fitness

items = {
    "Lacrosse training program": np.array([1.0, 0.0, 0.9]),
    "Gaming headset": np.array([0.1, 1.0, 0.1]),
    "Protein shaker": np.array([0.6, 0.0, 0.9]),
}

scores = []

for item_name, item_vector in items.items():
    score = cosine_similarity(user, item_vector)
    scores.append((item_name, score))

scores.sort(key=lambda x: x[1], reverse=True)

for item_name, score in scores:
    print(item_name, round(score, 3))