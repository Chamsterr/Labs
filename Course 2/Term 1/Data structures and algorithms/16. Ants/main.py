# муравьиный алгоритм
# 1. Инициализация феромонов
# 2. Построение пути
# 3. Обновление феромонов
import random

matrix = [
    # 0         1         2         3         4
    [[0, 0.2], [1, 0.2], [3, 0.2], [4, 0.2], [5, 0.2]],  # 0
    [[1, 0.2], [0, 0.2], [1, 0.2], [4, 0.2], [8, 0.2]],  # 1
    [[3, 0.2], [1, 0.2], [0, 0.2], [5, 0.2], [1, 0.2]],  # 2
    [[4, 0.2], [4, 0.2], [5, 0.2], [0, 0.2], [2, 0.2]],  # 3
    [[5, 0.2], [8, 0.2], [1, 0.2], [2, 0.2], [0, 0.2]],  # 4
]

alfa = 1
beta = 1
node_number = 5
ant_number = 1
WAY = 0.2  # константа для длины пути
history = []  # история посещенных вершин
history_history = []  # история истоии посещенных вершин
start_node = 0
Q = 4  # константа для обновления феромонов
P = 0.7  # коффицент испарения феромонов


def get_probability(node):
    global node_number
    global WAY
    global history
    probalities = []
    sum = 0
    for i in range(node_number):
        if matrix[node][i][0] != 0 and i not in history:
            sum += matrix[node][i][1] ** alfa * (WAY / matrix[node][i][0]) ** beta
    for i in range(node_number):
        if matrix[node][i][0] != 0 and i not in history:
            probalities.append(
                matrix[node][i][1] ** alfa * (WAY / matrix[node][i][0]) ** beta / sum
            )
        else:
            probalities.append(0)
    print(probalities)
    sum1 = 0
    for i in probalities:
        sum1 += i
    print(sum1)
    return probalities


def chose_node(probalities):
    rand = random.uniform(0, 1)
    for i in probalities:
        if rand < i:
            print(probalities.index(i))
            break
        else:
            rand -= i
    return probalities.index(i)


def get_lenght(history_history, matrix):
    lenght = 0
    for i in range(len(history_history) - 1):
        lenght += matrix[history_history[i]][history_history[i + 1]][0]
    return lenght


def find_all_lenght(history_history):
    global matrix
    fitness = []
    for i in history_history:
        fitness.append(get_lenght(i, matrix))
    return [[fitness[i], history_history[i]] for i in range(len(history_history))]


def update_feromons(all_lenght):
    global Q
    global matrix
    global P
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j][1] *= P
    for i in range(len(all_lenght)):
        for j in range(len(all_lenght[i][1]) - 1):
            matrix[all_lenght[i][1][j]][all_lenght[i][1][j + 1]][1] += (
                Q / all_lenght[i][0]
            )
            matrix[all_lenght[i][1][j + 1]][all_lenght[i][1][j]][1] += (
                Q / all_lenght[i][0]
            )


for k in range(10):
    for i in range(node_number):
        history.append(start_node)
        probalities = get_probability(start_node)
        start_node = chose_node(probalities)
    history_history.append(history)
    all_lenght = find_all_lenght(history_history)
    update_feromons(all_lenght)
    history = []
    if k == 9:
        print(find_all_lenght(history_history))
        history_history = []
