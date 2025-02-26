from typing import List
class Spaceship:
    def __init__(self, name: str, ship_type: str):
        self.name = name
        self.ship_type = ship_type
        self.condition = "Готов"

    def prepare_for_mission(self, mission_name: str, crew_size: int):
        print(self.name, "готовится к миссии", mission_name)
        print("Экипаж:", crew_size, "человек.")
        self.condition = "Готов к запуску"

    def update_condition(self, new_condition: str):
        self.condition = new_condition
        print("Состояние корабля", self.name, "изменено на:", new_condition)

    def train_in_zero_gravity(self, astronauts: List[str]):
        print(self.name, "начинает тренировку в условиях невесомости.")
        for astronaut in astronauts:
            print(astronaut, "проходит тренировку в невесомости.")
        print("Все астронавты успешно завершили тренировку в невесомости.")

    def __str__(self):
        return f"{self.name}, Тип: {self.ship_type}, Состояние: {self.condition}"

