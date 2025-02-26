class Astronaut:
    def __init__(self, name: str):
        self.name = name
        self.training_level = 0
        self.condition = "Готов"

    def train(self, coach):
        print(self.name, "проходит тренировку с тренером", coach.name)
        self.condition = "Устал"

    def use_equipment(self, equipment):
        print(self.name, "использует", equipment.name)
        equipment.use()

    def __str__(self):
        return f"Космонавт {self.name} (Уровень подготовки: {self.training_level}, Состояние: {self.condition})"
