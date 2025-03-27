import os
from xml.dom import minidom
import xml.sax
from typing import List, Tuple
from .MyTournament import MyTournament
from .MyHandler import MyHandler
from datetime import date

class Model:
    def __init__(self, path: str):
        self.path = path
        if not os.path.exists(path) or os.path.getsize(path) == 0:
            with open(path, "w") as f:
                f.write("<tournaments></tournaments>")
        try:
            self.doc = minidom.parse(path)
        except Exception as e:
            print(e)
            return

        self.handler = MyHandler()
        self.update_data()
        self.last_id = 0

    def update_data(self):
        self.handler.data = []
        with open(self.path, "r", encoding="UTF-8") as file:
            xml.sax.parse(file, handler=self.handler)
            self.data = self.handler.data.copy()

    def get_data(self) -> int:
        return len(self.data)

    def add_info(self, info: Tuple[str, date, str, str, int]):
        tournament_name, date_value, sport, winner, prize = info

        earnings = int(prize * 0.6)
        self.last_id += 1
        tournament_id = str(self.last_id)

        new_tournament = self.doc.createElement("tournament")
        new_tournament.setAttribute("id", tournament_id)

        name_element = self.doc.createElement("name")
        name_element.appendChild(self.doc.createTextNode(tournament_name))
        new_tournament.appendChild(name_element)

        date_element = self.doc.createElement("date")
        date_element.appendChild(self.doc.createTextNode(date_value.strftime('%Y-%m-%d')))
        new_tournament.appendChild(date_element)

        sport_element = self.doc.createElement("sport")
        sport_element.appendChild(self.doc.createTextNode(sport))
        new_tournament.appendChild(sport_element)

        winner_element = self.doc.createElement("winner")
        winner_element.appendChild(self.doc.createTextNode(winner))
        new_tournament.appendChild(winner_element)

        prize_element = self.doc.createElement("prize")
        prize_element.appendChild(self.doc.createTextNode(str(prize)))
        new_tournament.appendChild(prize_element)

        earnings_element = self.doc.createElement("earnings")
        earnings_element.appendChild(self.doc.createTextNode(str(earnings)))
        new_tournament.appendChild(earnings_element)

        root = self.doc.documentElement
        root.appendChild(new_tournament)

        with open(self.path, "w", encoding="UTF-8") as file:
            file.write(self.doc.toprettyxml())
        self.remove_whitespace_nodes(self.doc)
        self.update_data()

    def remove_whitespace_nodes(self, node):
        for n in node.childNodes:
            if n.nodeType == n.TEXT_NODE and not n.nodeValue.strip():
                node.removeChild(n)
            else:
                self.remove_whitespace_nodes(n)

    def search_by_date(self, search_date: date) -> List[MyTournament]:
        return [t for t in self.data if t.date == search_date]

    def search_by_winner(self, winner: str) -> List[MyTournament]:
        return [t for t in self.data if winner.lower() in t.winner.lower()]

    def search_by_prize_range(self, min_prize: int, max_prize: int) -> List[MyTournament]:
        return [t for t in self.data if int(min_prize) <= int(t.prize) <= int(max_prize)]

    def search_by_sports(self, sports: str) -> List[MyTournament]:
        return [t for t in self.data if sports.lower() in t.sport.lower()]

    def delete_by_FIO(self, FIO: str):
        to_delete = self.search_by_winner(FIO)
        if to_delete:
            self.delete(to_delete)
        else:
            print(f"Спортсмены с ФИО {FIO} не найдены.")

    def delete_by_date(self, delete_date: date):
        to_delete = self.search_by_date(delete_date)
        if to_delete:
            self.delete(to_delete)
        else:
            print(f"Турниры с датой {delete_date} не найдены.")

    def search_by_name_and_earnings(self, name: str, min_earnings: int, max_earnings: int):
        return [t for t in self.data if name.lower() in t.winner.lower() and min_earnings <= t.earnings <= max_earnings]

    def delete_by_name_and_earnings(self, name: str, min_earnings: int, max_earnings: int):
        to_delete = self.search_by_name_and_earnings(name, min_earnings, max_earnings)
        if to_delete:
            self.delete(to_delete)

    def get_unique_sports(self) -> List[str]:
        return list(set(t.sport for t in self.data))

    def delete_by_prize_range(self, min_prize: int, max_prize: int):
        to_delete = self.search_by_prize_range(min_prize, max_prize)
        if to_delete:
            self.delete(to_delete)
        else:
            print(f"Ничего не найдено")

    def delete_by_sports(self, sports: str):
        to_delete = self.search_by_sports(sports)
        if to_delete:
            self.delete(to_delete)
        else:
            print(f"Спор {sports} не найден.")

    def delete(self, to_delete: List[MyTournament]):
        to_delete_ids = {t.id for t in to_delete}
        root = self.doc.documentElement
        tournaments = root.getElementsByTagName("tournament")
        for tournament in tournaments:
            if tournament.getAttribute("id") in to_delete_ids:
                root.removeChild(tournament)

        self.remove_whitespace_nodes(self.doc)
        with open(self.path, "w", encoding="UTF-8") as f:
            f.write(self.doc.toprettyxml())
        self.update_data()

    def get_info_paged(self, page: int, per_page: int) -> List[MyTournament]:
        offset = (page - 1) * per_page
        end = page * per_page
        return self.data[offset:end]

    def get_groups(self) -> List[int]:
        groups = []
        for stud in self.data:
            groups.append(stud.group)
        return groups
