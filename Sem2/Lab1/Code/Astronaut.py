class Astronaut:
    def __init__(self, name: str) -> None:
        self.name = name
        self.training_level = 0
        self.condition = "Готов"

    def train(self, coach) -> None:
        try:
            if not hasattr(coach, "name"):
                raise TypeError("Передан некорректный объект тренера.")

            print(self.name, "проходит тренировку с тренером", coach.name)
            self.condition = "Устал"
        except TypeError as e:
            print("Ошибка:", e)

    def use_equipment(self, equipment) -> None:
        print(self.name, "использует", equipment.name)
        equipment.use()

    def __str__(self) -> str:
        return f"Космонавт {self.name} (Уровень подготовки: {self.training_level}, Состояние: {self.condition})"
