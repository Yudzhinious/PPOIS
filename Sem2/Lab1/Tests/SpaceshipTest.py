import unittest
from spaceship import Spaceship

class SpaceshipTest(unittest.TestCase):

    def setUp(self):
        self.spaceship = Spaceship(name="Аполлон", ship_type="Космический аппарат")

    def test_initial_condition(self):
        self.assertEqual(self.spaceship.condition, "Готов")

    def test_prepare_for_mission(self):
        self.spaceship.prepare_for_mission("Полет на Луну", 4)
        self.assertEqual(self.spaceship.condition, "Готов к запуску")

    def test_update_condition(self):
        self.spaceship.update_condition("В ремонте")
        self.assertEqual(self.spaceship.condition, "В ремонте")

    def test_str_representation(self):
        self.assertEqual(str(self.spaceship), "Аполлон, Тип: Космический аппарат, Состояние: Готов")


if __name__ == '__main__':
    unittest.main()
