import unittest
from unittest.mock import patch
from equipment import Equipment, rename_equipment, equip_equipment


class TestEquipment(unittest.TestCase):

    def setUp(self):
        self.equipment = Equipment()
        self.equipment.name = "Дрель"
        self.equipment.eq_type = "Электроинструмент"

    def test_initial_state(self):
        new_equipment = Equipment()
        self.assertIsNone(new_equipment.name)
        self.assertIsNone(new_equipment.eq_type)
        self.assertEqual(new_equipment.condition, "Исправен")

    def test_use_equipment_initialized(self):
        self.equipment.use()
        self.assertEqual(self.equipment.condition, "В использовании")

    def test_use_equipment_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.use()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_check_condition_initialized(self):
        with patch("builtins.print") as mock_print:
            self.equipment.check_condition()
            mock_print.assert_called_with("Состояние оборудования Дрель: Исправен")

    def test_check_condition_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.check_condition()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_update_condition_initialized(self):
        self.equipment.update_condition("В ремонте")
        self.assertEqual(self.equipment.condition, "В ремонте")

    def test_update_condition_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.update_condition("В ремонте")
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_train_usage_initialized(self):
        with patch("builtins.input", return_value=""), patch("builtins.print") as mock_print:
            self.equipment.train_usage()
            mock_print.assert_any_call("Этап 1: Теоретическая подготовка.")
            mock_print.assert_any_call("Этап 2: Практическое использование.")
            mock_print.assert_any_call("Этап 3: Проверка знаний.")
            mock_print.assert_any_call("Обучение работе с Дрель завершено успешно!")

    def test_train_usage_uninitialized(self):
        uninitialized_equipment = Equipment()
        with patch("builtins.print") as mock_print:
            uninitialized_equipment.train_usage()
            mock_print.assert_called_with("Оборудование не инициализировано.")

    def test_str_representation_initialized(self):
        self.assertEqual(str(self.equipment), "Оборудование Дрель (Тип: Электроинструмент, Состояние: Исправен)")

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


if __name__ == "__main__":
    unittest.main()
