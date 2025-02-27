import unittest
from astronaut import Astronaut
from coach import Coach

class CoachTest(unittest.TestCase):

    def setUp(self):
        self.astronaut = Astronaut(name="John Doe")

        self.coach = Coach()

    def test_initialize_with_valid_data(self):
        result = self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.assertTrue(result)
        self.assertEqual(self.coach.name, "Coach Ivan")
        self.assertEqual(self.coach.specialization, "Физическая подготовка")

    def test_conduct_training_when_uninitialized(self):
        self.coach.name = None
        self.coach.specialization = None
        self.coach.conduct_training(self.astronaut, "Физическая подготовка", 2)

    def test_conduct_training_when_initialized(self):
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.coach.conduct_training(self.astronaut, "Физическая подготовка", 2)

    def test_evaluate_astronaut_when_uninitialized(self):
        self.coach.name = None
        self.coach.specialization = None
        self.coach.evaluate_astronaut(self.astronaut, 1)

    def test_evaluate_astronaut_when_initialized(self):
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.coach.evaluate_astronaut(self.astronaut, skill_level_threshold=1)
        self.astronaut.training_level = 2

    def test_conduct_physical_training_when_uninitialized(self):
        self.coach.name = None
        self.coach.specialization = None
        self.coach.conduct_physical_training(self.astronaut, "Тренировка с гирями", 2)

    def test_conduct_physical_training_when_initialized(self):
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.coach.conduct_physical_training(self.astronaut, "Тренировка с гирями", 2)

    def test_str_representation_when_uninitialized(self):
        self.assertEqual(str(self.coach), "Тренер не инициализирован.")

    def test_str_representation_when_initialized(self):
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.assertEqual(str(self.coach), "Тренер Coach Ivan (Специализация: Физическая подготовка)")


if __name__ == '__main__':
    unittest.main()
