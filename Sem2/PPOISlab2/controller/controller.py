from view.GUIview import GUI
from typing import Tuple
from faker import Faker
import random
import model.DB.TournamentSQLite as db
import model.XML.TournamentXML as xml

class Controller:

    def __init__(self):
        self.view = GUI(self)
        self.current_page = 1
        self.records_per_page = 10
        self.deleted = 0
        self.find = 0
        self.faker = Faker()

    def show(self):
        self.view.mainloop()

    def choose_db(self):
        self.model = db.Tournament()
        self.curr_data = self.get_data()
        self.current_page = 1
        self.total_pages = self.calculate_total_pages()
        self.update_view()

    def choose_xml(self, path: str):
        self.model = xml.Model(path)
        self.curr_data = self.get_data()
        self.current_page = 1
        self.total_pages = self.calculate_total_pages()
        self.update_view()

    def update_view_deletion(self):
        amount = self.curr_data - self.get_data()
        self.deleted += amount
        if amount:
            self.view.print_message(f"Удалено записей {amount}")
        else:
            self.view.print_message("Таких записей не найдено")
        self.curr_data = self.get_data()
        self.total_pages = self.calculate_total_pages()
        self.current_page = 1
        self.update_view()

    def update_view(self):
        info = self.model.get_info_paged(self.current_page, self.records_per_page)
        self.view.update_table(info)
        self.view.update_page_label(self.current_page, self.total_pages)
        self.view.update_infos_label(len(info), self.get_data())

    def calculate_total_pages(self):
        self.curr_data = self.model.get_data()
        return max(((self.curr_data + self.records_per_page - 1) // self.records_per_page), 1)

    def change_pagination(self, new_numb: int):
        self.records_per_page = new_numb
        self.current_page = 1
        self.total_pages = self.calculate_total_pages()
        self.update_view()

    def next_page(self):
        if self.current_page < self.total_pages:
            self.current_page += 1
        self.update_view()

    def prev_page(self):
        if self.current_page > 1:
            self.current_page -= 1
        self.update_view()

    def end_page(self):
        self.current_page = self.total_pages
        self.update_view()

    def start_page(self):
        self.current_page = 1
        self.update_view()

    def add_random(self):
        for _ in range(50):
            tournament_name = f"{self.faker.word().capitalize()} Tournament {random.randint(1, 1000)}"
            date = self.faker.date_this_decade()
            sport = random.choice(["Football", "Basketball", "Tennis", "Volleyball"])
            winner = self.faker.name()
            prize = random.randint(1000, 10000)

            self.model.add_info((tournament_name, date, sport, winner, prize))

        self.total_pages = self.calculate_total_pages()
        self.update_view()

    def add_data(self, info: Tuple):
        self.model.add_info(info)
        self.total_pages = self.calculate_total_pages()
        self.update_view()

    def get_unique_sports(self):
        return self.model.get_unique_sports()

    def get_data(self):
        return self.model.get_data()

    def get_info(self):
        return f"Найдено: {self.find}\nУдалено: {self.deleted}"

    def get_all_sports(self):
        sports = set(self.model.get_sports())
        return sports

    def delete_by_FIO(self, FIO: str):
        self.model.delete_by_FIO(FIO)
        self.update_view_deletion()

    def search_by_FIO(self, FIO: str):
        tournaments = self.model.search_by_winner(FIO)
        self.find += len(tournaments)
        self.view.show_find(tournaments)

    def delete_by_sports(self, sports: str):
        self.model.delete_by_sports(sports)
        self.update_view_deletion()

    def delete_by_date(self, delete_date):
        self.model.delete_by_date(delete_date)
        self.update_view_deletion()

    def delete_by_prize_range(self, min_prize: str, max_prize: str):  # Принимаем строки из GUI
        try:
            min_prize = int(min_prize)
            max_prize = int(max_prize)
        except ValueError:
            self.view.print_message("Ошибка ввода\nПризовые должны быть числами")
            return
        self.model.delete_by_prize_range(min_prize, max_prize)
        self.update_view_deletion()

    def search_by_name_and_earnings(self, name: str, min_earnings: int, max_earnings: int):
        results = self.model.search_by_name_and_earnings(name, min_earnings, max_earnings)
        self.find += len(results)
        self.view.show_find(results)

    def delete_by_name_and_earnings(self, name: str, min_earnings: int, max_earnings: int):
        self.model.delete_by_name_and_earnings(name, min_earnings, max_earnings)
        self.update_view_deletion()

    def search_by_date(self, search_date):
        tournaments = self.model.search_by_date(search_date)
        self.find += len(tournaments)
        self.view.show_find(tournaments)

    def search_by_sports(self, sports: str):
        tournaments = self.model.search_by_sports(sports)
        self.find += len(tournaments)
        self.view.show_find(tournaments)

    def search_by_prize_range(self,  min_prize: int, max_prize: int):
        tournaments = self.model.search_by_prize_range( min_prize, max_prize)
        self.find += len(tournaments)
        self.view.show_find(tournaments)