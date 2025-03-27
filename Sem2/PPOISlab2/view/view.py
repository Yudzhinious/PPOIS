import tkinter as tk
from tkinter import ttk

class TableView(ttk.Frame):
    def __init__(self,parent):
        super().__init__(parent)
        columns = ["Название турнира","Дата проведения", "Название вида спорта","ФИО победителя","Размер призовых турнира","Заработок победителя"]
        self.columns = tuple(columns)
        
        self.table = ttk.Treeview(self,columns=self.columns,show="headings")
        
        total_width = self.table.winfo_width()
        num_columns = len(self.columns)
        width_per_column = total_width // num_columns
        
        fake_table = ttk.Frame(self)
        tk.Label(fake_table,padx=30,text='Проведение турнира').pack(fill='x')
        fake_table.pack()        
        
        for col in self.columns:
            self.table.heading(col,text = col)
            self.table.column(column=col,stretch=True,width=width_per_column)
        self.table.pack(fill="both",expand=True)

    def insert_data(self, data):
        self.data = data
        for row in self.table.get_children():
            self.table.delete(row)
        for row in data:
            d_row = row.to_tuple()
            self.table.insert(parent="", index="end", values=d_row)
            
    def get_data(self):
        return self.data

class TreeView(ttk.Frame):
    def __init__(self, parent):
        super().__init__(parent)
        self.tree = ttk.Treeview(self, show="tree")
        self.tree.pack(expand=True, fill="both")

    def insert_data(self, data):
        self.data = data
        for row in self.tree.get_children():
            self.tree.delete(row)

        for i, row in enumerate(data, start=1):
            d_row = row.to_tuple()
            id = self.tree.insert("", "end", iid=i, text=f"Турнир: {d_row[0]}")
            date_id = self.tree.insert(id, "end", text=f"Дата: {d_row[1]}")
            sport_id = self.tree.insert(date_id, "end", text=f"Вид спорта: {d_row[2]}")
            winner_id = self.tree.insert(sport_id, "end", text=f"Победитель: {d_row[3]}")
            prize_id = self.tree.insert(winner_id, "end", text=f"Призовой фонд: {d_row[4]}")
            earnings_id = self.tree.insert(prize_id, "end", text=f"Заработок победителя: {d_row[5]}")

    def get_data(self):
        return self.data
