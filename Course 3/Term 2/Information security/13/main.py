from PIL import Image
import os

def message_to_binary(message):
    binary_message = ''.join(format(ord(char), '08b') for char in message)
    return binary_message

def hide_message(image_path, message):
    if not os.path.exists(image_path):
        img = Image.new("RGB", (100, 100))
        img.save(image_path)

    img = Image.open(image_path)
    binary_message = message_to_binary(message)
    binary_message += '1111111111111110'

    data_index = 0
    img_data = iter(img.getdata())
    # Проходимся по пикселям изображения и меняем младший бит на биты сообщения
    encoded_pixels = []
    for pixel in img_data:
        r, g, b = pixel
        if data_index < len(binary_message):
            r = r & ~1 | int(binary_message[data_index])
            data_index += 1
        if data_index < len(binary_message):
            g = g & ~1 | int(binary_message[data_index])
            data_index += 1
        if data_index < len(binary_message):
            b = b & ~1 | int(binary_message[data_index])
            data_index += 1
        encoded_pixels.append((r, g, b))

    # Создаем новое изображение с закодированным сообщениемdad
    encoded_img = Image.new(img.mode, img.size)
    encoded_img.putdata(encoded_pixels)

    # Сохраняем закодированное изображение
    encoded_img.save('encoded_image.png')

    # Возвращаем изображение и размеры для дальнейшего использования
    return encoded_img, encoded_img.size

def reveal_message(encoded_image_path):
    img = Image.open(encoded_image_path)
    binary_message = ''

    img_data = iter(img.getdata())

    # Извлекаем младшие биты изображения
    for pixel in img_data:
        r, g, b = pixel
        binary_message += str(r & 1)
        binary_message += str(g & 1)
        binary_message += str(b & 1)

    # Находим маркер завершения сообщения
    message_end_index = binary_message.find('1111111111111110')
    binary_message = binary_message[:message_end_index]

    # Преобразуем бинарное сообщение в текст
    message = ''
    for i in range(0, len(binary_message), 8):
        byte = binary_message[i:i+8]
        message += chr(int(byte, 2))

    return message

def extract_LSB(image):
    lsb_matrices = {'R': [], 'G': [], 'B': []}

    # Получаем данные пикселей изображения
    pixels = list(image.getdata())

    # Извлекаем младший бит каждого цветового канала каждого пикселя
    for pixel in pixels:
        r, g, b = pixel
        lsb_matrices['R'].append(r & 1)
        lsb_matrices['G'].append(g & 1)
        lsb_matrices['B'].append(b & 1)

    return lsb_matrices

def display_LSB_matrices(lsb_matrices):
    for channel, lsb_channel in lsb_matrices.items():
        print(f"Матрица младших бит для канала {channel}:")
        for i in range(0, len(lsb_channel), img_width):
            row = lsb_channel[i:i+img_width]
            print(' '.join(map(str, row)))

# Пример использования
message = "Привет, это секретное сообщение!"
image_path = "original_image.png"

# Скрываем сообщение в изображении
encoded_img, img_size = hide_message(image_path, message)

# Извлекаем сообщение из закодированного изображения
decoded_message = reveal_message("encoded_image.png")
print("Извлеченное сообщение:", decoded_message)

# Извлекаем младшие биты из закодированного изображения
img_width, img_height = img_size
lsb_matrices = extract_LSB(encoded_img)

# Отображаем матрицы младших бит
display_LSB_matrices(lsb_matrices)

# Демонстрируем исходное и закодированное изображения
original_img = Image.open(image_path)
original_img.show()

encoded_img.show()
