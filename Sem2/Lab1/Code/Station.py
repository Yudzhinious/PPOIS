from coach import Coach
from astronaut import Astronaut
from equipment import Equipment
from typing import List

class SpaceStation:
    def __init__(self, name: str) -> None:
        self.name = name
        self.astronauts: List[Astronaut] = []
        self.equipment: List[Equipment] = []

    def add_astronaut(self, astronaut: Astronaut) -> None:
        self.astronauts.append(astronaut)
        print("Космонавт", astronaut.name, "добавлен на станцию",self.name)

    def add_equipment(self, equipment: Equipment) -> None:
        self.equipment.append(equipment)
        print("Оборудование", equipment.name, "добавлено на станцию", self.name)

    def conduct_training_session(self, coach: Coach) -> None:
        print("На станции", self.name, "начинается тренировочная сессия.")
        for astronaut in self.astronauts:
            coach.conduct_training(astronaut)

    def __str__(self) -> str:
        astronaut_count = len(self.astronauts)
        return f"Космическая станция {self.name} (Космонавтов: {astronaut_count})"

