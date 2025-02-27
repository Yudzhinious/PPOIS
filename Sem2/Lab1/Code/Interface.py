from typing import List
from astronaut import Astronaut
from coach import Coach
from equipment import Equipment
from simulator import Simulator
from spaceship import Spaceship
from station import SpaceStation

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
              9. Физическая подготовка.\n\
              10. Обучение работе с оборудованием.\n\
              11. Тренировка в условиях невесомости.\n\
              12. Подготовка к миссии.\n\
              0. Выход")

    def menu(self):
        while True:
            self.show_menu()
            choice = self.__validate_input(0, 12)

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
                case 9:
                    self.physical_training()
                case 10:
                    self.equipment_training()
                case 11:
                    self.zero_gravity_training()
                case 12:
                    self.mission_preparation()

    def add_astronaut(self) -> None:
        name = input("Введите имя астронавта: ").strip()
        astronaut = Astronaut(name)
        self.astronauts.append(astronaut)
        print(f"Астронавт {astronaut.name} добавлен.")

    def add_coach(self) -> None:
        name = input("Введите имя тренера: ").strip()
        specialization = input("Введите специализацию тренера: ").strip()
        coach = Coach()
        coach.initialize(name, specialization)
        self.coaches.append(coach)
        print(f"Тренер {coach.name} добавлен.")

    def add_equipment(self) -> None:
        name = input("Введите название оборудования: ").strip()
        eq_type = input("Введите тип оборудования: ").strip()
        equipment = Equipment(name, eq_type)
        self.equipments.append(equipment)
        print(f"Оборудование {equipment.name} добавлено.")

    def add_simulator(self) -> None:
        sim_type = input("Введите тип симулятора: ").strip()
        simulator = Simulator(sim_type)
        self.simulators.append(simulator)
        print(f"Симулятор {simulator.sim_type} добавлен.")

    def add_spaceship(self) -> None:
        name = input("Введите название корабля: ").strip()
        ship_type = input("Введите тип корабля: ").strip()
        spaceship = Spaceship(name, ship_type)
        self.spaceships.append(spaceship)
        print(f"Корабль {spaceship.name} добавлен.")

    def add_space_station(self) -> None:
        name = input("Введите название космической станции: ").strip()
        space_station = SpaceStation(name)
        self.space_stations.append(space_station)
        print(f"Космическая станция {space_station.name} добавлена.")

    def conduct_training(self) -> None:
        astronaut_name = input("Введите имя астронавта для тренировки: ").strip()
        coach_name = input("Введите имя тренера для тренировки: ").strip()
        training_type = input("Введите тип тренировки: ").strip()
        duration = int(input("Введите продолжительность тренировки в часах: "))

        astronaut = next((a for a in self.astronauts if a.name == astronaut_name), None)
        coach = next((c for c in self.coaches if c.name == coach_name), None)

        if astronaut and coach:
            coach.conduct_training(astronaut, training_type, duration)
        else:
            print("Не удалось найти астронавта или тренера.")

    def start_simulation(self) -> None:
        print("Список доступных астронавтов:")
        for i, astronaut in enumerate(self.astronauts):
            print(f"{i + 1}. {astronaut.name}")
        astronaut_choice = self.__validate_input(1, len(self.astronauts)) - 1
        astronaut = self.astronauts[astronaut_choice]

        print("Список доступных симуляторов:")
        for i, simulator in enumerate(self.simulators):
            print(f"{i + 1}. {simulator.sim_type}")
        simulator_choice = self.__validate_input(1, len(self.simulators)) - 1
        simulator = self.simulators[simulator_choice]

        simulator.train_astronaut(astronaut)

    def physical_training(self) -> None:
        print("Список доступных астронавтов:")
        for i, astronaut in enumerate(self.astronauts):
            print(f"{i + 1}. {astronaut.name}")
        astronaut_choice = self.__validate_input(1, len(self.astronauts)) - 1
        astronaut = self.astronauts[astronaut_choice]

        print("Список доступных тренеров:")
        for i, coach in enumerate(self.coaches):
            print(f"{i + 1}. {coach.name}")
        coach_choice = self.__validate_input(1, len(self.coaches)) - 1
        coach = self.coaches[coach_choice]

        physical_activity = input("Введите тип физической активности: ").strip()
        duration = int(input("Введите продолжительность тренировки в часах: "))

        coach.conduct_physical_training(astronaut, physical_activity, duration)

    def equipment_training(self) -> None:
        print("Список доступного оборудования:")
        for i, equipment in enumerate(self.equipments):
            print(f"{i + 1}. {equipment.name} ({equipment.eq_type})")
        equipment_choice = self.__validate_input(1, len(self.equipments)) - 1
        equipment = self.equipments[equipment_choice]

        equipment.train_usage()

    def zero_gravity_training(self) -> None:
        print("Список доступных кораблей:")
        for i, spaceship in enumerate(self.spaceships):
            print(f"{i + 1}. {spaceship.name} ({spaceship.ship_type})")
        spaceship_choice = self.__validate_input(1, len(self.spaceships)) - 1
        spaceship = self.spaceships[spaceship_choice]

        print("Список доступных астронавтов:")
        for i, astronaut in enumerate(self.astronauts):
            print(f"{i + 1}. {astronaut.name}")
        print("Выберите номера астронавтов через запятую (например, 1,2,3):")
        astronaut_choices = input().strip().split(",")
        astronaut_choices = [int(choice.strip()) - 1 for choice in astronaut_choices]
        selected_astronauts = [self.astronauts[i].name for i in astronaut_choices]

        spaceship.train_in_zero_gravity(selected_astronauts)

    def mission_preparation(self) -> None:
        print("Список доступных кораблей:")
        for i, spaceship in enumerate(self.spaceships):
            print(f"{i + 1}. {spaceship.name} ({spaceship.ship_type})")
        spaceship_choice = self.__validate_input(1, len(self.spaceships)) - 1
        spaceship = self.spaceships[spaceship_choice]

        mission_name = input("Введите название миссии: ").strip()
        crew_size = int(input("Введите количество членов экипажа: "))

        spaceship.prepare_for_mission(mission_name, crew_size)

def main():
    interface = Interface()
    interface.menu()

if __name__ == "__main__":
    main()