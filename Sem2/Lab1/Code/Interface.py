from typing import List
from Astronaut import Astronaut
from Coach import Coach
from Equipment import Equipment
from Simulator import Simulator
from Spaceship import Spaceship
from Station import SpaceStation

class Interface:
    def __init__(self):
        self.astronauts: List[Astronaut] = []
        self.coaches: List[Coach] = []
        self.equipments: List[Equipment] = []
        self.simulators: List[Simulator] = []
        self.spaceships: List[Spaceship] = []
        self.space_stations: List[SpaceStation] = []

    def __validate_input(self, lower_boundary: int, upper_boundary: int) -> int:
        while True:
            try:
                choice = int(input())
                if lower_boundary <= choice <= upper_boundary:
                    return choice
                else:
                    print("Такого пункта в меню нет, напишите правильно!")
            except ValueError:
                print("Напишите ЦИФРУ пункта меню!")

    def show_menu(self):
        print("Выберите пункт меню:\n\
              1. Добавить астронавта.\n\
              2. Добавить тренера.\n\
              3. Добавить оборудование.\n\
              4. Добавить симулятор.\n\
              5. Добавить космический корабль.\n\
              6. Добавить космическую станцию.\n\
              7. Провести тренировку.\n\
              8. Запустить симуляцию.\n\
              0. Выход")

    def menu(self):
        self.show_menu()
        choice = self.__validate_input(0, 8)

        match choice:
            case 0:
                print("Выход из программы.")
                return
            case 1:
                self.add_astronaut()
            case 2:
                self.add_coach()
            case 3:
                self.add_equipment()
            case 4:
                self.add_simulator()
            case 5:
                self.add_spaceship()
            case 6:
                self.add_space_station()
            case 7:
                self.conduct_training()
            case 8:
                self.start_simulation()

    def add_astronaut(self):
        name = input("Введите имя астронавта: ").strip()
        astronaut = Astronaut(name)
        self.astronauts.append(astronaut)
        print(f"Астронавт {astronaut.name} добавлен.")

    def add_coach(self):
        name = input("Введите имя тренера: ").strip()
        specialization = input("Введите специализацию тренера: ").strip()
        coach = Coach()
        coach.initialize(name, specialization)
        self.coaches.append(coach)
        print(f"Тренер {coach.name} добавлен.")

    def add_equipment(self):
        name = input("Введите название оборудования: ").strip()
        eq_type = input("Введите тип оборудования: ").strip()
        equipment = Equipment(name, eq_type)
        self.equipments.append(equipment)
        print(f"Оборудование {equipment.name} добавлено.")

    def add_simulator(self):
        sim_type = input("Введите тип симулятора: ").strip()
        simulator = Simulator(sim_type)
        self.simulators.append(simulator)
        print(f"Симулятор {simulator.sim_type} добавлен.")

    def add_spaceship(self):
        name = input("Введите название корабля: ").strip()
        ship_type = input("Введите тип корабля: ").strip()
        spaceship = Spaceship(name, ship_type)
        self.spaceships.append(spaceship)
        print(f"Корабль {spaceship.name} добавлен.")

    def add_space_station(self):
        name = input("Введите название космической станции: ").strip()
        space_station = SpaceStation(name)
        self.space_stations.append(space_station)
        print(f"Космическая станция {space_station.name} добавлена.")

    def conduct_training(self):
        astronaut_name = input("Введите имя астронавта для тренировки: ").strip()
        coach_name = input("Введите имя тренера для тренировки: ").strip()

        astronaut = next((a for a in self.astronauts if a.name == astronaut_name), None)
        coach = next((c for c in self.coaches if c.name == coach_name), None)

        if astronaut and coach:
            coach.conduct_training(astronaut, "Общая тренировка", 2)
        else:
            print("Не удалось найти астронавта или тренера.")

    def start_simulation(self):
        astronaut_name = input("Введите имя астронавта для симуляции: ").strip()
        simulator_type = input("Введите тип симулятора для симуляции: ").strip()

        astronaut = next((a for a in self.astronauts if a.name == astronaut_name), None)
        simulator = next((s for s in self.simulators if s.sim_type == simulator_type), None)

        if astronaut and simulator:
            simulator.train_astronaut(astronaut)
        else:
            print("Не удалось найти астронавта или симулятор.")
def main():
    interface = Interface()

    while True:
        interface.menu()

if __name__ == "__main__":
    main()