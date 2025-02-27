import unittest
from astronaut import Astronaut
from simulator import Simulator

class SimulatorTest(unittest.TestCase):
    def setUp(self):
        self.astronaut = Astronaut(name="John Doe")
        self.simulator = Simulator(sim_type="Невесомость")

    def test_start_simulation(self):
        self.simulator.start_simulation(self.astronaut)
        self.assertEqual(self.simulator.condition, "В процессе")
        self.assertEqual(self.astronaut.condition, "В симуляции")

    def test_end_simulation(self):
        self.simulator.start_simulation(self.astronaut)
        self.simulator.end_simulation(self.astronaut)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut.condition, "Готов")

    def test_train_astronaut(self):
        initial_training_level = self.astronaut.training_level
        self.simulator.train_astronaut(self.astronaut)
        self.assertEqual(self.astronaut.training_level, initial_training_level + 2)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut.condition, "Готов")

    def test_prepare_for_mission(self):
        self.simulator.prepare_for_mission(self.astronaut)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut.condition, "Готов")

if __name__ == '__main__':
    unittest.main()