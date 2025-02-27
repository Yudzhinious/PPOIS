from astronaut import Astronaut

class Simulator:
    def __init__(self, sim_type: str = None) -> None:
        self.sim_type = sim_type
        self.condition = "Готов"

    def start_simulation(self, astronaut: Astronaut) -> None:
        print("Запуск симуляции", self.sim_type, "для", astronaut.name)
        self.condition = "В процессе"
        astronaut.condition = "В симуляции"

    def end_simulation(self, astronaut: Astronaut) -> None:
        if self.sim_type is None:
            print("Ошибка: тип симулятора не задан.")
            return
        print("Завершение симуляции", self.sim_type, "для", astronaut.name)
        self.condition = "Готов"
        astronaut.condition = "Готов"

    def train_astronaut(self, astronaut: Astronaut) -> None:

        if self.sim_type is None:
            print("Ошибка: тип симулятора не задан.")
            return

        print("Обучение", astronaut.name, "в симуляторе", self.sim_type)
        self.start_simulation(astronaut)

        if self.sim_type == "Невесомость":
            print(astronaut.name, "проходит тренировку по управлению телом в условиях невесомости.")
            print("Этап 1: Теоретическая подготовка.")
            print("Этап 2: Практические упражнения в невесомости.")
            print("Этап 3: Проверка навыков.")
            astronaut.training_level += 2
            print(astronaut.name, "успешно завершил тренировку в симуляторе невесомости.")

        print(astronaut.name, "завершил обучение в симуляторе.")
        self.end_simulation(astronaut)

    def prepare_for_mission(self, astronaut: Astronaut):
        print("Подготовка", astronaut.name, "к миссии в симуляторе", self.sim_type)
        self.start_simulation(astronaut)

        if self.condition == "Готов":
            print(astronaut.name, "полностью готов к полету.")

        elif self.condition == "В процессе":
            print(astronaut.name, " проходит подготовку.")
            print("Этап 1: Изучение маршрута миссии.")
            print("Этап 2: Тренировка по управлению кораблем.")
            print("Этап 3: Проверка готовности к пилотированию.")
            print(astronaut.name, "готов к полету.")
        else:
            self.end_simulation(astronaut)
            return
        print(astronaut.name, "завершил подготовку к миссии.")
        self.end_simulation(astronaut)