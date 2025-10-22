class Rotor:
    def __init__(self, mapping, notch):
        self.mapping = mapping
        self.notch = notch
        self.position = 0

    def encrypt(self, char):
        return self.mapping[(ord(char) - ord('A') + self.position) % 26]

    def encrypt_inverse(self, char):
        return chr((self.mapping.index(char) - self.position + 26) % 26 + ord('A'))

    def rotate(self):
        self.position = (self.position + 1) % 26
        return self.position == self.notch

class Reflector:
    def __init__(self, mapping):
        self.mapping = mapping

    def reflect(self, char):
        return self.mapping[ord(char) - ord('A')]

class Enigma:
    def __init__(self, rotors, reflector):
        self.rotors = rotors
        self.reflector = reflector

    def encrypt(self, char):
        for rotor in self.rotors:
            char = rotor.encrypt(char)
        char = self.reflector.reflect(char)
        for rotor in reversed(self.rotors):
            char = rotor.encrypt_inverse(char)
        if self.rotors[-1].rotate():
            if self.rotors[-2].rotate():
                self.rotors[-3].rotate()
        return char

rotor_II_mapping = "AJDKSIRUXBLHWTMCQGZNPYFVOE"
rotor_II_notch = 1
rotor_II = Rotor(rotor_II_mapping, rotor_II_notch)

rotor_Gamma_mapping = "FSOKANUERHMBTIYCWLQPZXVGJD"
rotor_Gamma_notch = 1
rotor_Gamma = Rotor(rotor_Gamma_mapping, rotor_Gamma_notch)

rotor_IV_mapping = "ESOVPZJAYQUIRHXLNFTGKDCMWB"
rotor_IV_notch = 1
rotor_IV = Rotor(rotor_IV_mapping, rotor_IV_notch)

reflector_C_mapping = "FVPJIAOYEDRZXWGCTKUQSBNMHL"
reflector_C = Reflector(reflector_C_mapping)

rotors = [rotor_II, rotor_Gamma, rotor_IV]
reflector = reflector_C

enigma = Enigma(rotors, reflector)

message = "CMXHTWKMWRPUHGCPWYCDJHJ"
encrypted = "".join(enigma.encrypt(char) for char in message)
print(encrypted)
