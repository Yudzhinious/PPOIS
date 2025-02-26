from typing import List
from Astronaut import Astronaut

class Coach:
    def __init__(self):
        self.name = None
        self.specialization = None

    def initialize(self, name: str, specialization: str):
        self.name = name
        self.specialization = specialization
        return True

    def conduct_training(self, astronaut: Astronaut, training_type: str, duration: int):
        if self.name is None or self.specialization is None:
            print("Тренер не инициализирован.")
            return
        print("Тренер", self.name, "проводит тренировку", training_type, "для", astronaut.name, "продолжительностью", duration, "часов.")

    def evaluate_astronaut(self, astronaut: Astronaut, skill_level_threshold: int):

        if self.name is None or self.specialization is None:
            print("Тренер не инициализирован.")
            return
        print("Тренер", self.name, "оценивает подготовку", astronaut.name)
        if astronaut.training_level > skill_level_threshold:
            print(astronaut.name, "готов к миссии.")
        else:
            print(astronaut.name, "нуждается в дополнительной подготовке.")

    def conduct_physical_training(self, astronaut: Astronaut, physical_activity: str, duration: int):
        if self.name is None or self.specialization is None:
            print("Тренер не инициализирован.")
            return
        print("Тренер", {self.name},"проводит физическую подготовку", physical_activity,"для", astronaut.name, "продолжительностью",duration, "часов.")

    def __str__(self):
        if self.name is None or self.specialization is None:
            return "Тренер не инициализирован."
        return f"Тренер {self.name} (Специализация: {self.specialization})"


