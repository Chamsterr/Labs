import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_selection import VarianceThreshold
from sklearn.decomposition import PCA
from sklearn.metrics import accuracy_score
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
import time

# Шаг 1: Загрузка данных
# Подготовьте или загрузите данные для классификации с не менее чем 30 параметрами
# Пример:
# Cmake_classification - создание датасета
# параметры : обазцы признаки колинф колклассов
X, y = make_classification(n_samples=1000, n_features=50, n_informative=40, n_classes=2, random_state=42)

# Шаг 2: Разделение данных на обучающий и тестовый наборы
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Шаг 3: Обучение модели случайного леса на исходном наборе данных
rf_original = RandomForestClassifier(random_state=42)
rf_original.fit(X_train, y_train)
original_accuracy = accuracy_score(y_test, rf_original.predict(X_test))
print(f"Accuracy on original dataset: {original_accuracy:.4f}")

# Шаг 4: Сокращение количества параметров с низкой дисперсией
# VarianceThreshold метод отбора признаков для сокращения параметров
selector = VarianceThreshold(threshold=3) # разница между наибольшм и наименьшим равна значению threshold
X_train_reduced = selector.fit_transform(X_train)
X_test_reduced = selector.transform(X_test)

# Шаг 5: Обучение модели случайного леса на сокращенном наборе данных
rf_reduced = RandomForestClassifier(random_state=42)
rf_reduced.fit(X_train_reduced, y_train)
reduced_accuracy = accuracy_score(y_test, rf_reduced.predict(X_test_reduced))
print(f"Accuracy on reduced dataset: {reduced_accuracy:.4f}")

# Шаг 6: Применение метода PCA к исходному набору данны
start_time = time.perf_counter()
pca = PCA(n_components=2)# сокращение до 2 главных компонент
X_pca = pca.fit_transform(X)
end_time = time.perf_counter()
pca_execution_time = end_time - start_time
print(f"PCA execution time: {pca_execution_time:.4f} seconds")

# Шаг 7: Визуализация данных по двум главным компонентам
plt.figure(figsize=(8, 6))
plt.scatter(X_pca[:, 0], X_pca[:, 1], c=y, cmap='viridis', s=50, alpha=0.6)
plt.title('PCA: Two Principal Components')
plt.xlabel('Principal Component 1')
plt.ylabel('Principal Component 2')
plt.colorbar(label='Class')
plt.show()

# Шаг 8: Определение оптимального количества главных компонент для 90% дисперсии
#n_components_90 это переменная отвечающая за количество главных компонент
pca = PCA()
pca.fit(X)
# возвращает накопленную сумму элементов массива. В данном случае cumulative_variance_ratio - это массив, 
# содержащий объясненные дисперсии для каждой главной компоненты, упорядоченной по убыванию.
cumulative_variance_ratio = np.cumsum(pca.explained_variance_ratio_)
#возвращает индекс максимального элемента в массиве
n_components_90 = np.argmax(cumulative_variance_ratio >= 0.9) + 1
print(f"Number of components to retain 90% variance: {n_components_90}")

# Шаг 9: Обучение модели случайного леса с определенным количеством компонент
pca_final = PCA(n_components=n_components_90)
X_train_pca_final = pca_final.fit_transform(X_train)
X_test_pca_final = pca_final.transform(X_test)

rf_pca_final = RandomForestClassifier(random_state=42)
rf_pca_final.fit(X_train_pca_final, y_train)
pca_final_accuracy = accuracy_score(y_test, rf_pca_final.predict(X_test_pca_final))
print(f"Accuracy with {n_components_90} PCA components: {pca_final_accuracy:.4f}")


# Accuracy (точность) — это метрика оценки качества 
# классификационной модели, которая показывает долю 
# правильных предсказаний среди всех предсказаний
'''
Использование PCA для уменьшения размерности до двух 
главных компонент позволяет визуализировать данные и 
сохранять основные характеристики данных в более 
компактной форме.
Определение оптимального количества главных компонент
для объяснения 90% дисперсии позволяет уменьшить 
размерность данных, сохраняя при этом большую часть 
их вариации.
'''

