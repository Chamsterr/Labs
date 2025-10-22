import re

#Модификация расстояния между словами; модификация цвета

def hide_message(text, message):
    # Преобразуем сообщение в список слов
    message_words = message.split()

    # Ищем индексы пробелов в тексте
    space_indices = [m.start() for m in re.finditer(' ', text)]

    # Вычисляем средние расстояния между словами
    avg_space_distance = sum(space_indices[i] - space_indices[i - 1] for i in range(1, len(space_indices))) / (
                len(space_indices) - 1)

    # Количество слов, которые мы можем спрятать в тексте
    num_hidden_words = min(len(space_indices) - 1, len(message_words))

    # Рассчитываем новые индексы для вставки слов сообщения
    new_space_indices = [int(space_indices[i] + (i * avg_space_distance)) for i in range(num_hidden_words)]

    # Вставляем слова сообщения в текст
    for i, word in enumerate(message_words):
        text = text[:new_space_indices[i] + i] + ' ' + word + text[new_space_indices[i] + i:]

    return text


def reveal_message(text):
    # Ищем индексы пробелов в тексте
    space_indices = [m.start() for m in re.finditer(' ', text)]

    # Вычисляем расстояния между словами
    space_distances = [space_indices[i] - space_indices[i - 1] for i in range(1, len(space_indices))]

    # Ищем среднее расстояние
    avg_space_distance = sum(space_distances) / len(space_distances)

    # Находим слова, скрытые с помощью модификации расстояния между словами
    hidden_words = []
    for i in range(1, len(space_indices)):
        if space_indices[i] - space_indices[i - 1] > avg_space_distance:
            hidden_words.append(text[space_indices[i - 1] + 1:space_indices[i]])

    return hidden_words


# Пример использования

# Исходный текст
original_text = "Это пример текста, в котором мы будем скрывать сообщение."

# Сообщение, которое мы хотим скрыть
secret_message = "тайный"

# Скрываем сообщение в тексте
text_with_hidden_message = hide_message(original_text, secret_message)
print("Текст с скрытым сообщением:", text_with_hidden_message)

# Раскрываем сообщение из текста
revealed_message = reveal_message(text_with_hidden_message)
print("Раскрытое сообщение:", revealed_message)
