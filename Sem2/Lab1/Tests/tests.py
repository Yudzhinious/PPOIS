import unittest
from unittest.mock import patch
from astronaut import Astronaut
from coach import Coach
from equipment import Equipment, rename_equipment, equip_equipment
from simulator import Simulator
from station import SpaceStation
from spaceship import Spaceship

class SpaceMissionTest(unittest.TestCase):

    def setUp(self):
        self.astronaut1 = Astronaut(name="Doe")
        self.astronaut2 = Astronaut(name="Smith")
        self.coach = Coach()
        self.coach.initialize(name="Ivan", specialization="Физическая подготовка")

        self.equipment1 = Equipment(name="Отвертка", eq_type="Ручной инструмент")
        self.equipment2 = Equipment(name="Молоток", eq_type="Строительный инструмент")

        self.station = SpaceStation(name="Международная космическая станция")
        self.spaceship = Spaceship(name="Аполлон", ship_type="Космический аппарат")

        self.simulator = Simulator(sim_type="Невесомость")

    def test_astronaut_initial_attributes(self):
        self.assertEqual(self.astronaut1.name, "Doe")
        self.assertEqual(self.astronaut1.training_level, 0)
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_astronaut_train(self):
        self.coach.name = "Ivan"
        self.astronaut1.train(self.coach)
        self.assertEqual(self.astronaut1.condition, "Устал")

    def test_astronaut_use_equipment(self):
        self.astronaut1.use_equipment(self.equipment1)
        self.assertEqual(self.equipment1.condition, "В использовании")

    def test_astronaut_evaluate(self):
        self.coach.evaluate_astronaut(self.astronaut1, skill_level_threshold=1)
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_astronaut_physical_training(self):
        self.coach.conduct_physical_training(self.astronaut1, "Тренировка с гирями", 2)
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_astronaut_str_representation(self):
        self.assertEqual(str(self.astronaut1), "Космонавт Doe (Уровень подготовки: 0, Состояние: Готов)")

    def test_spaceship_initial_condition(self):
        self.assertEqual(self.spaceship.condition, "Готов")

    def test_spaceship_prepare_for_mission(self):
        self.spaceship.prepare_for_mission("Полет на Луну", 4)
        self.assertEqual(self.spaceship.condition, "Готов к запуску")

    def test_spaceship_update_condition(self):
        self.spaceship.update_condition("В ремонте")
        self.assertEqual(self.spaceship.condition, "В ремонте")

    def test_spaceship_str_representation(self):
        self.assertEqual(str(self.spaceship), "Аполлон, Тип: Космический аппарат, Состояние: Готов")

    def test_station_add_astronaut(self):
        self.station.add_astronaut(self.astronaut1)
        self.station.add_astronaut(self.astronaut2)
        self.assertEqual(len(self.station.astronauts), 2)
        self.assertIn(self.astronaut1, self.station.astronauts)
        self.assertIn(self.astronaut2, self.station.astronauts)

    def test_station_add_equipment(self):
        self.station.add_equipment(self.equipment1)
        self.assertEqual(len(self.station.equipment), 1)
        self.assertIn(self.equipment1, self.station.equipment)

    def test_station_str_representation(self):
        self.station.add_astronaut(self.astronaut1)
        self.station.add_astronaut(self.astronaut2)
        self.assertEqual(str(self.station), "Космическая станция Международная космическая станция (Космонавтов: 2)")

    def test_equipment_use(self):
        self.station.add_equipment(self.equipment1)
        self.equipment1.use()
        self.assertEqual(self.equipment1.condition, "В использовании")

    def test_equipment_update_condition(self):
        self.station.add_equipment(self.equipment1)
        self.equipment1.update_condition("В ремонте")
        self.assertEqual(self.equipment1.condition, "В ремонте")

    def test_start_simulation(self):
        self.simulator.start_simulation(self.astronaut1)
        self.assertEqual(self.simulator.condition, "В процессе")
        self.assertEqual(self.astronaut1.condition, "В симуляции")

    def test_end_simulation(self):
        self.simulator.start_simulation(self.astronaut1)
        self.simulator.end_simulation(self.astronaut1)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_train_astronaut(self):
        initial_training_level = self.astronaut1.training_level
        self.simulator.train_astronaut(self.astronaut1)
        self.assertEqual(self.astronaut1.training_level, initial_training_level + 2)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_prepare_for_mission(self):
        self.simulator.prepare_for_mission(self.astronaut1)
        self.assertEqual(self.simulator.condition, "Готов")
        self.assertEqual(self.astronaut1.condition, "Готов")

    def test_initialize_with_valid_data(self):
        result = self.coach.initialize(name="Ivan", specialization="Физическая подготовка")
        self.assertTrue(result)
        self.assertEqual(self.coach.name, "Ivan")
        self.assertEqual(self.coach.specialization, "Физическая подготовка")

    def test_str_representation_when_initialized(self):
        self.coach.initialize(name="Ivan", specialization="Физическая подготовка")
        self.assertEqual(str(self.coach), "Тренер Ivan (Специализация: Физическая подготовка)")

    def test_initial_state(self):
        new_equipment = Equipment(name="Отвертка", eq_type="Ручной инструмент")
        self.assertEqual(new_equipment.name, "Отвертка")
        self.assertEqual(new_equipment.eq_type, "Ручной инструмент")
        self.assertEqual(new_equipment.condition, "Исправен")

    def test_use_equipment_initialized(self):
        self.equipment1.use()
        self.assertEqual(self.equipment1.condition, "В использовании")

    def test_use_equipment_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.use()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_check_condition_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.check_condition()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_update_condition_initialized(self):
        self.equipment1.update_condition("В ремонте")
        self.assertEqual(self.equipment1.condition, "В ремонте")

    def test_update_condition_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.update_condition("В ремонте")
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_train_usage_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.train_usage()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_str_representation_uninitialized(self):
        uninitialized_equipment = Equipment()
        self.assertEqual(str(uninitialized_equipment), "Оборудование не инициализировано.")

    @patch("builtins.input", side_effect=["Отвертка", "Ручной инструмент"])
    def test_rename_equipment_valid(self, mock_input):
        new_equipment = rename_equipment()
        self.assertIsNotNone(new_equipment)
        self.assertEqual(new_equipment.name, "Отвертка")
        self.assertEqual(new_equipment.eq_type, "Ручной инструмент")

    @patch("builtins.input", side_effect=["", "Ручной инструмент"])
    def test_rename_equipment_invalid(self, mock_input):
        with patch("builtins.print") as mock_print:
            new_equipment = rename_equipment()
            self.assertIsNone(new_equipment)
            mock_print.assert_called_with("Ошибка: название и тип оборудования не могут быть пустыми.")

    def test_equip_equipment_valid(self):
        data = {"name": "Молоток", "type": "Строительный инструмент"}
        new_equipment = equip_equipment(data)
        self.assertIsNotNone(new_equipment)
        self.assertEqual(new_equipment.name, "Молоток")
        self.assertEqual(new_equipment.eq_type, "Строительный инструмент")

    def test_equip_equipment_invalid(self):
        data = {"name": None, "type": "Строительный инструмент"}
        new_equipment = equip_equipment(data)
        self.assertIsNotNone(new_equipment)
        self.assertIsNone(new_equipment.name)
        self.assertEqual(new_equipment.eq_type, "Строительный инструмент")

if __name__ == '__main__':
    unittest.main()
