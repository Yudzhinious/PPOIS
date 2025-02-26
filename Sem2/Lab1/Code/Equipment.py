class Equipment:
    def __init__(self, name=None, eq_type=None) -> None:
        self.name = name
        self.eq_type = eq_type
        self.condition = "Исправен"

    def use(self) -> None:
        if not self.is_initialized():
            print("Оборудование не инициализировано.")
            return
        print(f"Оборудование {self.name} используется.")
        self.condition = "В использовании"

    def check_condition(self) -> None:
        if not self.is_initialized():
            print("Оборудование не инициализировано.")
            return
        print(f"Состояние оборудования {self.name}: {self.condition}")

    def update_condition(self, new_condition: str) -> None:
        if not self.is_initialized():
            print("Оборудование не инициализировано.")
            return
        self.condition = new_condition
        print(f"Состояние оборудования {self.name} изменено на: {new_condition}")

    def train_usage(self) -> None:
        if not self.is_initialized():
            print("Оборудование не инициализировано.")
            return
        print(f"Обучение работе с оборудованием {self.name} ({self.eq_type})")
        print("Этап 1: Теоретическая подготовка.")
        input("Нажмите Enter для продолжения...")
        print("Этап 2: Практическое использование.")
        input("Нажмите Enter для продолжения...")
        print("Этап 3: Проверка знаний.")
        input("Нажмите Enter для завершения обучения...")
        print(f"Обучение работе с {self.name} завершено успешно!")

    def __str__(self) -> str:
        if not self.is_initialized():
            return "Оборудование не инициализировано."
        return f"Оборудование {self.name} (Тип: {self.eq_type}, Состояние: {self.condition})"

    def is_initialized(self) -> bool:
        return self.name is not None and self.eq_type is not None


def rename_equipment():
    name = input("Введите название оборудования: ").strip()
    eq_type = input("Введите тип оборудования: ").strip()
    if not name or not eq_type:
        print("Ошибка: название и тип оборудования не могут быть пустыми.")
        return None
    return Equipment(name, eq_type)


def equip_equipment(data: dict):
    name = data.get("name")
    eq_type = data.get("type")
    return Equipment(name, eq_type)
