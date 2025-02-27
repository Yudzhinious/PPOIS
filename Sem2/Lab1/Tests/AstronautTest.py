import unittest
from astronaut import Astronaut
from coach import Coach
from equipment import Equipment

class AstronautTest(unittest.TestCase):

    def setUp(self):
        self.astronaut = Astronaut(name="John Doe")

        self.coach = Coach()
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.equipment = Equipment(name="Дрель", eq_type="Электроинструмент")

    def test_initial_attributes(self):
        self.assertEqual(self.astronaut.name, "John Doe")
        self.assertEqual(self.astronaut.training_level, 0)
        self.assertEqual(self.astronaut.condition, "Готов")

    def test_train(self):
        initial_condition = self.astronaut.condition

        self.coach.name = "Coach Ivan"
        self.astronaut.train(self.coach)
        self.assertEqual(self.astronaut.condition, "Устал")

    def test_use_equipment(self):
        self.astronaut.use_equipment(self.equipment)
        self.assertEqual(self.equipment.condition, "В использовании")

    def test_evaluate_astronaut(self):
        self.coach.evaluate_astronaut(self.astronaut, skill_level_threshold=1)
        self.assertEqual(self.astronaut.condition, "Готов")

    def test_conduct_physical_training(self):
        self.coach.conduct_physical_training(self.astronaut, "Тренировка с гирями", 2)
        self.assertEqual(self.astronaut.condition, "Готов")

    def test_str_representation(self):
        self.assertEqual(str(self.astronaut), "Космонавт John Doe (Уровень подготовки: 0, Состояние: Готов)")

if __name__ == '__main__':
    unittest.main()
