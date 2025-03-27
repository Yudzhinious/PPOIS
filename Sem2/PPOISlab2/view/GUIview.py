import tkinter as tk
from tkinter import messagebox,ttk,filedialog
from .view import TableView,TreeView
from typing import List
from tkcalendar import DateEntry

class GUI(tk.Tk):
    
    def __init__(self, contr):
       super().__init__()
       self.controller = contr
       self.title("Model-View-Controller")
       self.geometry("1920x1080")
       self.withdraw()
       self.create_menu()
       self.create_widgets()
       self.choose_model()
    
    def choose_model(self):
        model = tk.Toplevel(self)
        model.geometry("900x700")
        model.title("Выберите модель для чтения данных")
        DB = tk.Button(model,text="DB",command=lambda: self.choose_db(model))
        XML = tk.Button(model,text="XML",command=lambda: self.choose_xml(model))
        DB.pack(fill="both",anchor='w')
        XML.pack(fill="both",anchor='e')
        model.protocol("WM_DELETE_WINDOW",lambda: self.end())
    
    def end(self):
        self.destroy()

    def choose_db(self,window):
        self.controller.choose_db()
        window.destroy()
        self.wm_deiconify()

    def select_file(self, file_path, choice_window, main_window):
        self.controller.choose_xml(file_path)
        choice_window.destroy()
        main_window.destroy()
        self.deiconify()

    def close_all(self, choice_window, main_window):
        choice_window.destroy()
        main_window.destroy()
        self.destroy()

    def choose_xml(self, window):
        self.withdraw()

        choice_window = tk.Toplevel(self)
        choice_window.title("Выберите XML файл")
        choice_window.geometry("300x150")
        choice_window.resizable(False, False)
        file1_path = 'model/XML/test1.xml'
        file2_path = "model/XML/test2.xml"

        label = tk.Label(choice_window, text="Выберите XML файл:", font=("Arial", 12))
        label.pack(pady=10)

        btn1 = tk.Button(choice_window, text="test1.xml", width=20,
        command=lambda: self.select_file(file1_path, choice_window, window))
        btn1.pack(pady=5)

        btn2 = tk.Button(choice_window, text="test2.xml", width=20,
        command=lambda: self.select_file(file2_path, choice_window, window))
        btn2.pack(pady=5)

        choice_window.protocol("WM_DELETE_WINDOW", lambda: self.close_all(choice_window, window))

    def create_menu(self):
        menu_bar = tk.Menu(self)
        self.config(menu=menu_bar)
        add_menu = tk.Menu(menu_bar)
        add_menu.add_command(label="Ввести самостоятельно", command=self.add_tournament)
        add_menu.add_command(label="Автоматические заполнение",command=self.add_random)
        menu_bar.add_cascade(label="Добавление",menu=add_menu)     
        
        search_menu = tk.Menu(menu_bar)
        search_menu.add_command(label="Найти по фамилии победителя", command=self.get_FIO_to_search)
        search_menu.add_command(label="Найти по виду спорта", command=self.search_by_sport_action)
        search_menu.add_command(label="Найти по дате", command=self.get_date_to_search)
        search_menu.add_command(label="Найти по размеру призовых", command=lambda: self.get_prize_to_search())
        search_menu.add_command(label="Объединённый поиск по имени и заработку", command=self.combined_search_by_name_and_earnings)
        menu_bar.add_cascade(label="Поиск информации",menu=search_menu)
        
        delete_menu = tk.Menu(menu_bar)
        delete_menu.add_command(label = "Удалить по фамилии победителя",command=self.get_FIO_to_del)
        delete_menu.add_command(label="Удалить по виду спорта", command=self.delete_by_sport_action)
        delete_menu.add_command(label="Удалить по дате", command=self.get_date_to_del)
        delete_menu.add_command(label="Удалить по размеру призовых", command=lambda: self.get_prize_to_del())
        delete_menu.add_command(label="Объединённое удаление по имени и заработку",command=self.combined_delete_by_name_and_earnings)
        menu_bar.add_cascade(label="Удаление данных",menu = delete_menu)
        
        menu_bar.add_command(label="Изменить кол-во записей на странице",command=self.change_pagination)
        menu_bar.add_command(label="Посмотреть информацию",command=lambda: self.print_message(self.controller.get_info()))
        menu_bar.add_command(label="Изменить представление", command=self.change_view)
        menu_bar.add_command(label='Изменить хранилище для данных',command=self.choose_model)

    def create_widgets(self):
        self.fram = tk.Frame(self)
        self.table = TableView(self.fram)
        self.table.pack(fill = "both",expand=True)
        self.fram.pack(fill = "both",expand=True)
        navigation_frame = tk.Frame(self)
        self.to_the_start = tk.Button(navigation_frame,text="<<",command=self.controller.start_page)
        self.to_the_start.pack(side=tk.LEFT,padx=5)
        self.prev_button = tk.Button(navigation_frame,text="<",command=self.controller.prev_page)
        self.prev_button.pack(side=tk.LEFT,padx=5)
        navigation_frame.pack(pady=10)
        self.page_label = tk.Label(navigation_frame,text="1")
        self.page_label.pack(side=tk.LEFT,padx = 5)
        self.next_button = tk.Button(navigation_frame,text=">",command=self.controller.next_page)
        self.next_button.pack(side=tk.LEFT,padx=5)
        self.to_the_finish = tk.Button(navigation_frame,text=">>",command=self.controller.end_page)
        self.to_the_finish.pack(side=tk.LEFT,padx=5)
        self.infos_label = tk.Label(self,text="Записей на странице")
        self.infos_label.pack(anchor="center")

    def change_view(self):
        data = self.table.get_data()
        if self.table.__class__ == TableView:
            self.table.destroy()
            self.table = TreeView(self.fram)
            self.table.pack(fill="both",expand=True)
        else:
            self.table.destroy()
            self.table = TableView(self.fram)
            self.table.pack(fill="both",expand=True)
        self.table.insert_data(data)

    def add_random(self):
        self.controller.add_random()

    def update_table(self, data: List):
        self.table.insert_data(data)
        
    def update_page_label(self,current_page,total_pages):
        self.page_label.config(text=f"{current_page}/{total_pages}")

    def update_infos_label(self,curr_len,overall_len):
        self.infos_label.config(text=f"Записей на странице: {curr_len}/{overall_len}")

    def add_tournament(self):
        add_data = tk.Toplevel(self)
        add_data.title("Добавление нового турнира")
        add_data.geometry("400x250")

        tk.Label(add_data, text="Название турнира").grid(row=0, column=0, sticky="w")
        tk.Label(add_data, text="Дата проведения").grid(row=1, column=0, sticky="w")
        tk.Label(add_data, text="Название вида спорта").grid(row=2, column=0, sticky="w")
        tk.Label(add_data, text="ФИО победителя").grid(row=3, column=0, sticky="w")
        tk.Label(add_data, text="Размер призовых турнира").grid(row=4, column=0, sticky="w")

        tournament_entry = tk.Entry(add_data)
        date_entry = DateEntry(add_data, date_pattern='yyyy-mm-dd')
        sports_entry = tk.Entry(add_data)
        name_entry = tk.Entry(add_data)
        prize_entry = tk.Entry(add_data)

        tournament_entry.grid(row=0, column=1, padx=5, pady=2)
        date_entry.grid(row=1, column=1, padx=5, pady=2)
        sports_entry.grid(row=2, column=1, padx=5, pady=2)
        name_entry.grid(row=3, column=1, padx=5, pady=2)
        prize_entry.grid(row=4, column=1, padx=5, pady=2)

        add_button = tk.Button(add_data, text="Добавить данные",command=lambda: self.add_record(tournament_entry.get(),date_entry.get_date(),sports_entry.get(),name_entry.get(),prize_entry.get(),add_data))
        add_button.grid(row=6, column=0, columnspan=2, sticky="ew", pady=10)

    def add_record(self, tournament: str, date, sports: str, name: str, prize: str, window):
        tournament, sports, name = tournament.strip(), sports.strip(), name.strip()

        if not tournament:
            self.print_message("Ошибка ввода\nНазвание турнира не может быть пустым")
            window.destroy()
            return

        if not sports.isalpha() or not name.replace(" ", "").isalpha():
            self.print_message("Ошибка ввода\nНазвание и вид спорта должны состоять только из букв")
            window.destroy()
            return

        try:
            prize = int(prize.strip())
        except ValueError:
            self.print_message("Ошибка ввода\nПризовой фонд должен быть числом")
            window.destroy()
            return
        self.controller.add_data((tournament, date, sports, name, prize))
        window.destroy()

    def change_pagination(self):
        changing = tk.Toplevel(self)
        changing.geometry("250x100")
        changing.title("Количество записей на странице")
        new_label = tk.Label(changing,text="Новое значение")
        new_label.grid(row=0,column=0)
        new_entry = tk.Entry(changing)
        new_entry.grid(row=1,column=0)
        entry_button = tk.Button(changing,text="Изменить",command=lambda: self.change_pagin(new_entry.get().strip(),changing))
        entry_button.grid(row=2,column=1)
        
    def change_pagin(self,new_pages: str,window):
        try:
            new_pages = int(new_pages)
        except ValueError:
            self.print_message("Должно быть натуральное число")
            window.destroy()
            return    
        if new_pages < 1:
            self.print_message("Должно быть натуральным")
        else:
            self.controller.change_pagination(new_pages)
        window.destroy()

    def get_date_to_search(self):
        search = tk.Toplevel(self)
        search.title("Поиск по дате")

        tk.Label(search, text="Дата (yyyy-mm-dd)").grid(row=0)

        date_entry = DateEntry(search, date_pattern='yyyy-mm-dd')
        date_entry.grid(row=1, column=0)

        button = tk.Button(search, text="Искать", command=lambda: self.search_by_date(date_entry.get_date(), search))
        button.grid(row=1, column=2)

    def search_by_date(self, search_date, search_window):
        if search_date:
            self.controller.search_by_date(search_date)
            search_window.destroy()
        else:
            self.print_message("Ошибка ввода\nДата не может быть пустой.")
            search_window.destroy()

    def get_date_to_del(self):
        delition = tk.Toplevel(self)
        delition.title("Удаление по дате")
        tk.Label(delition, text="Дата (yyyy-mm-dd)").grid(row=0)
        date_entry = DateEntry(delition, date_pattern='yyyy-mm-dd')
        date_entry.grid(row=1, column=0)
        button = tk.Button(delition, text="Удалить",
                           command=lambda: self.delete_by_date(date_entry.get_date(), delition))
        button.grid(row=1, column=2)

    def delete_by_date(self, delete_date, window):
        if delete_date:
            self.controller.delete_by_date(delete_date)
            window.destroy()
        else:
            self.print_message("Ошибка ввода\nДата не может быть пустой.")
            window.destroy()

    def get_prize_to_search(self):
        search = tk.Toplevel(self)
        search.title("Поиск по призовым")

        tk.Label(search, text="Минимальная сумма призовых").grid(row=0)
        tk.Label(search, text="Максимальная сумма призовых").grid(row=1)

        min_prize_entry = tk.Entry(search)
        max_prize_entry = tk.Entry(search)

        min_prize_entry.grid(row=0, column=1)
        max_prize_entry.grid(row=1, column=1)

        button = tk.Button(search, text="Искать", command=lambda: self.search_by_prize_range_action(
            min_prize_entry.get().strip(), max_prize_entry.get().strip(), search))
        button.grid(row=2, column=1)

    def search_by_sport_action(self):
        unique_sports = self.controller.get_unique_sports()
        if not unique_sports:
            messagebox.showwarning("Warning", "No sports found in the data.")
            return

        search_window = tk.Toplevel(self)
        search_window.title("Искать по виде спорта")

        sport_var = tk.StringVar()
        sport_var.set("Select one")
        sport_menu = tk.OptionMenu(search_window, sport_var, *unique_sports)
        sport_menu.grid(row=1, column=0)

        def confirm_search():
            selected_sport = sport_var.get()
            if selected_sport != "Select one":
                results = self.controller.search_by_sports(selected_sport)
                self.show_find(results)
                search_window.destroy()

        confirm_button = tk.Button(search_window, text="Search", command=confirm_search)
        confirm_button.grid(row=2, column=0)

    def search_by_prize_range_action(self, min_prize_str, max_prize_str, search_window):
        try:
            min_prize = int(min_prize_str)
            max_prize = int(max_prize_str)
        except ValueError:
            self.print_message("Ошибка ввода\nПризовые должны быть числами")
            search_window.destroy()
            return

        if min_prize > max_prize:
            self.print_message("Ошибка ввода\nМинимальная сумма призовых не может быть больше максимальной.")
            search_window.destroy()
            return

        results = self.controller.search_by_prize_range(min_prize, max_prize)

        if results:
            result_window = tk.Toplevel(search_window)
            result_window.title("Результаты поиска по призовым")
            for i, tournament in enumerate(results, 1):
                earnings = int(tournament.prize * 0.6)
                tk.Label(result_window, text=f"{tournament.tournament_name} - Заработок: {earnings}").grid(row=i,column=0)
        else:
            self.print_message("Турниры в заданном диапазоне призовых не найдены")
        search_window.destroy()

    def get_FIO_to_search(self):
        search = tk.Toplevel(self)
        search.title("Поиск")
        tk.Label(search,text="ФИО").grid(row=0)
        FIO_entry = tk.Entry(search)
        FIO_entry.grid(row=1,column=0)
        button = tk.Button(search,text="Искать",command=lambda: self.search_by_FIO(FIO_entry.get().strip(),search))
        button.grid(row=1,column=2)

    def search_by_FIO(self,FIO,window):
        for i in FIO:
            if i.isdigit():
                self.print_message("Ошибка ввода\nФИО должно состоять из букв (и пробельных символов)")
                window.destroy()
                return
            
        if FIO:
            self.controller.search_by_FIO(FIO)
            window.destroy()
        else:
            self.print_message("Ошибка ввода\nФИО должно состоять из букв (и пробельных символов)")
            window.destroy()

    def get_sports_to_search(self):
        search = tk.Toplevel(self)
        search.title("Поиск")
        tk.Label(search, text="Спорт").grid(row=0)
        sports_entry = tk.Entry(search)
        sports_entry.grid(row=1, column=0)
        button = tk.Button(search, text="Искать", command=lambda: self.search_by_sports(sports_entry.get().strip(), search))
        button.grid(row=1, column=2)

    def delete_by_sport_action(self):
        unique_sports = self.controller.get_unique_sports()
        if not unique_sports:
            messagebox.showwarning("Warning", "No sports found in the data.")
            return

        delete_window = tk.Toplevel(self)
        delete_window.title("Удалить по виду спорта")

        label = tk.Label(delete_window, text="Выберите вид спорта для удаления:").grid(row=0, column=0)

        sport_var = tk.StringVar()
        sport_var.set("Выберите один")
        sport_menu = tk.OptionMenu(delete_window, sport_var, *unique_sports)
        sport_menu.grid(row=1, column=0)

        def confirm_delete():
            selected_sport = sport_var.get()
            if selected_sport != "Выберите один":
                self.controller.delete_by_sports(selected_sport)
                delete_window.destroy()
            else:
                messagebox.showwarning("Warning", "Пожалуйста, выберите вид спорта.")

        confirm_button = tk.Button(delete_window, text="Удалить", command=confirm_delete)
        confirm_button.grid(row=2, column=0)

    def search_by_sports(self, sports, window):
        for i in sports:
            if i.isdigit():
                self.print_message("Ошибка ввода\n должен состоять из букв (и пробельных символов)")
                window.destroy()
                return

        if sports:
            self.controller.search_by_sports(sports)
            window.destroy()
        else:
            self.print_message("Ошибка ввода\nдолжен состоять из букв (и пробельных символов)")
            window.destroy()

    def show_find(self,info: List):
        show_table = tk.Toplevel(self)
        show_table.geometry("1920x600")
        table = TableView(show_table)
        show_table.title(f"Найдено {len(info)} записей")
        table.pack(fill = "both",expand=True)
        table.insert_data(info)
        b = tk.Button(show_table,text="Close",command= show_table.destroy)
        b.pack()    
    
    def print_message(self,message):
        messagebox.showwarning(message=message)
    
    def get_FIO_to_del(self):
        delition = tk.Toplevel(self)
        delition.title("Удаление спортсмена")
        name_label = tk.Label(delition,text="ФИО")
        name_label.grid(row=0,column=0)
        name_entry = tk.Entry(delition)
        name_entry.grid(row=1,column=0)
        entry_button = tk.Button(delition,text='Удалить',command=lambda: self.delete_by_FIO(name_entry.get().strip(),delition))
        entry_button.grid(row=2,column=1)

    def get_prize_to_del(self):
        delition = tk.Toplevel(self)
        delition.title("Удаление по призовым")

        tk.Label(delition, text="Минимальная сумма призовых").grid(row=0)
        tk.Label(delition, text="Максимальная сумма призовых").grid(row=1)

        min_prize_entry = tk.Entry(delition)
        max_prize_entry = tk.Entry(delition)

        min_prize_entry.grid(row=0, column=1)
        max_prize_entry.grid(row=1, column=1)

        button = tk.Button(delition, text="Удалить", command=lambda: self.delete_by_prize_range_action(
            min_prize_entry.get().strip(), max_prize_entry.get().strip(), delition))
        button.grid(row=2, column=1)

    def delete_by_prize_range_action(self, min_prize_str, max_prize_str, window):

        min_prize = int(min_prize_str)
        max_prize = int(max_prize_str)

        if min_prize > max_prize:
            self.print_message("Ошибка ввода\nМинимальная сумма призовых не может быть больше максимальной.")
            window.destroy()
            return

        if min_prize_str:
            self.controller.delete_by_prize_range(min_prize_str, max_prize_str)
        else:
            pass
        window.destroy()

    def get_sports_to_del(self):
        delition = tk.Toplevel(self)
        delition.title("Удаление вида спорта")
        name_label = tk.Label(delition,text="Спорт")
        name_label.grid(row=0,column=0)
        sports_entry = tk.Entry(delition)
        sports_entry.grid(row=1,column=0)
        entry_button = tk.Button(delition,text='Удалить',command=lambda: self.delete_by_sports(sports_entry.get().strip(),delition))
        entry_button.grid(row=2,column=1)

    def delete_by_sports(self, sports, window):
        if sports:
            self.controller.delete_by_sports(sports)
        else:
            self.print_message("Ошибка ввода\n должн состоять из букв (и пробельных символов)")
        window.destroy()

    def delete_by_FIO(self,FIO,window):
        if FIO:
            self.controller.delete_by_FIO(FIO)
        else:
            self.print_message("Ошибка ввода\nФИО должно состоять из букв (и пробельных символов)")
        window.destroy()

    def combined_search_by_name_and_earnings(self):
        search_window = tk.Toplevel(self)
        search_window.title("Объединённый поиск по имени и заработку")

        name_label = tk.Label(search_window, text="Имя победителя:").grid(row=0, column=0)
        name_entry = tk.Entry(search_window)
        name_entry.grid(row=0, column=1)

        min_earnings_label = tk.Label(search_window, text="Минимальный заработок:").grid(row=1, column=0)
        min_earnings_entry = tk.Entry(search_window)
        min_earnings_entry.grid(row=1, column=1)

        max_earnings_label = tk.Label(search_window, text="Максимальный заработок:").grid(row=2, column=0)
        max_earnings_entry = tk.Entry(search_window)
        max_earnings_entry.grid(row=2, column=1)

        def confirm_search():
            name = name_entry.get().strip()
            try:
                min_earnings = int(min_earnings_entry.get().strip())
                max_earnings = int(max_earnings_entry.get().strip())
            except ValueError:
                messagebox.showwarning("Warning", "Заработок должен быть целым числом.")
                return

            if min_earnings > max_earnings:
                messagebox.showwarning("Warning", "Минимальный заработок не может быть больше максимального.")
                return

            self.controller.search_by_name_and_earnings(name, min_earnings, max_earnings)
            search_window.destroy()

        confirm_button = tk.Button(search_window, text="Поиск", command=confirm_search)
        confirm_button.grid(row=3, column=1)

    def combined_delete_by_name_and_earnings(self):
        delete_window = tk.Toplevel(self)
        delete_window.title("Объединённое удаление по имени и заработку")

        name_label = tk.Label(delete_window, text="Имя победителя:").grid(row=0, column=0)
        name_entry = tk.Entry(delete_window)
        name_entry.grid(row=0, column=1)

        min_earnings_label = tk.Label(delete_window, text="Минимальный заработок:").grid(row=1, column=0)
        min_earnings_entry = tk.Entry(delete_window)
        min_earnings_entry.grid(row=1, column=1)

        max_earnings_label = tk.Label(delete_window, text="Максимальный заработок:").grid(row=2, column=0)
        max_earnings_entry = tk.Entry(delete_window)
        max_earnings_entry.grid(row=2, column=1)

        def confirm_delete():
            name = name_entry.get().strip()
            try:
                min_earnings = int(min_earnings_entry.get().strip())
                max_earnings = int(max_earnings_entry.get().strip())
            except ValueError:
                messagebox.showwarning("Warning", "Заработок должен быть целым числом.")
                return

            if min_earnings > max_earnings:
                messagebox.showwarning("Warning", "Минимальный заработок не может быть больше максимального.")
                return

            if messagebox.askyesno("Подтвердите удаление", "Вы уверены, что хотите удалить подходящие турниры?"):
                self.controller.delete_by_name_and_earnings(name, min_earnings, max_earnings)
                delete_window.destroy()
            else:
                delete_window.destroy()

        confirm_button = tk.Button(delete_window, text="Удалить", command=confirm_delete)
        confirm_button.grid(row=3, column=1)