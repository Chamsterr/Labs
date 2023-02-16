import numpy as np

matrix = [
    # 0  1  2  3  4
    [0, 1, 3, 4, 5],  # 0
    [1, 0, 1, 4, 8],  # 1
    [3, 1, 0, 5, 1],  # 2
    [4, 4, 5, 0, 2],  # 3
    [5, 8, 1, 2, 0],  # 4
]
node_number = 5
population_size = 6
start_city = 0
mutation_probability = 70
generation_number = 20
breaking_point = round(node_number / 2)

def generate_population(population_size, node_number, start_city):
    population = []
    while population_size != len(population):
        hromosome = [start_city] + list(
            np.random.permutation([i for i in range(node_number) if i != start_city])
        )
        if hromosome not in population:
            population.append(hromosome)
    return population


def find_fitness(population, matrix):
    global start_city
    fitness = []
    for i in range(len(population)):
        fitness.append(start_city)
        for j in range(len(population[i])):
            if j == len(population[i]) - 1:
                fitness[i] += matrix[population[i][j]][start_city]
            else:
                fitness[i] += matrix[population[i][j]][population[i][j + 1]]
    return [[fitness[i], population[i]] for i in range(len(population))]


def parent_selection(population_with_fitness):
    parents = np.random.permutation(population_with_fitness)[:2]
    return parents


def get_child(parent1, parent2):
    global node_number
    global breaking_point

    gens_from_first_parent = parent1[:breaking_point]
    gens_from_second_parent = [
        i for i in parent2[breaking_point:] if i not in parent1[:breaking_point]
    ]

    child = gens_from_first_parent + gens_from_second_parent
    for i in parent2:
        if i not in child:
            child.append(i)

    return mutation(child)


def mutation(child):
    random_number = np.random.randint(0, 100)
    if random_number < mutation_probability:
        index1 = np.random.randint(1, len(child))
        index2 = np.random.randint(1, len(child))
        child[index1], child[index2] = child[index2], child[index1]
    return child


def crossing(population_with_fitness, parents):
    child1 = get_child(parents[0][1], parents[1][1])
    child2 = get_child(parents[1][1], parents[0][1])
    population_with_fitness += find_fitness([child1, child2], matrix)
    population_with_fitness.sort()
    return population_with_fitness[:-2]


population = generate_population(population_size, node_number, start_city)
population_with_fitness = find_fitness(population, matrix)

print("Популяция номер 0")
for i in population_with_fitness:
    print(i)


for i in range(generation_number):
    parents = parent_selection(population_with_fitness)
    population_with_fitness = crossing(population_with_fitness, parents)
    print(f"Популяция номер {i+1}")
    for k in population_with_fitness:
        print(k)
