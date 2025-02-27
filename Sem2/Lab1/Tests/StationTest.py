import unittest
from coach import Coach
from astronaut import Astronaut
from equipment import Equipment
from station import SpaceStation

class SpaceStationTest(unittest.TestCase):

    def setUp(self):
        self.astronaut1 = Astronaut(name="John Doe")
        self.astronaut2 = Astronaut(name="Jane Smith")
        self.coach = Coach()
        self.coach.initialize(name="Coach Ivan", specialization="Физическая подготовка")
        self.equipment = Equipment(name="Дрель", eq_type="Электроинструмент")
        self.station = SpaceStation(name="Международная космическая станция")

    def test_add_astronaut(self):
        self.station.add_astronaut(self.astronaut1)
        self.station.add_astronaut(self.astronaut2)
        self.assertEqual(len(self.station.astronauts), 2)
        self.assertIn(self.astronaut1, self.station.astronauts)
        self.assertIn(self.astronaut2, self.station.astronauts)

    def test_add_equipment(self):
        self.station.add_equipment(self.equipment)
        self.assertEqual(len(self.station.equipment), 1)
        self.assertIn(self.equipment, self.station.equipment)

    def test_str_representation(self):
        self.station.add_astronaut(self.astronaut1)
        self.station.add_astronaut(self.astronaut2)
        self.assertEqual(str(self.station), "Космическая станция Международная космическая станция (Космонавтов: 2)")

    def test_equipment_use(self):
        self.station.add_equipment(self.equipment)
        self.equipment.use()
        self.assertEqual(self.equipment.condition, "В использовании")

    def test_equipment_update_condition(self):
        self.station.add_equipment(self.equipment)
        self.equipment.update_condition("В ремонте")
        self.assertEqual(self.equipment.condition, "В ремонте")


    def test_equip_equipment_valid(self):
        data = {"name": "Молоток", "type": "Строительный инструмент"}
        new_equipment = Equipment(name=data["name"], eq_type=data["type"])
        self.assertIsNotNone(new_equipment)
        self.assertEqual(new_equipment.name, "Молоток")
        self.assertEqual(new_equipment.eq_type, "Строительный инструмент")

    def test_equip_equipment_invalid(self):
        data = {"name": None, "type": "Строительный инструмент"}
        new_equipment = Equipment(name=data["name"], eq_type=data["type"])
        self.assertIsNotNone(new_equipment)
        self.assertIsNone(new_equipment.name)
        self.assertEqual(new_equipment.eq_type, "Строительный инструмент")

if __name__ == '__main__':
    unittest.main()
