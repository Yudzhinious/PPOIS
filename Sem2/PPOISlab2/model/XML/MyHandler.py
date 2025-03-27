import xml.sax
from .MyTournament import MyTournament

class MyHandler(xml.sax.ContentHandler):
    def __init__(self):
        self.data = []
        self.tournament = None
        self.current = ""

    def startElement(self, name, attrs):
        self.current = name
        if name == "tournament":
            tournament_id = attrs.get('id', None)
            if tournament_id is not None:
                self.tournament = MyTournament(tournament_id)
            else:
                self.tournament = MyTournament("unknown_id")

    def characters(self, content):
        if not content.strip():
            return
        if self.current == "name":
            self.tournament.tournament_name = content.strip()
        elif self.current == "date":
            self.tournament.date = content.strip()
        elif self.current == "sport":
            self.tournament.sport = content.strip()
        elif self.current == "winner":
            self.tournament.winner = content.strip()
        elif self.current == "prize":
            try:
                self.tournament.prize = int(content.strip())
            except ValueError:
                self.tournament.prize = 0
        elif self.current == "earnings":
            try:
                self.tournament.earnings = int(content.strip())
            except ValueError:
                self.tournament.earnings = 0

    def endElement(self, name):
        if name == "tournament" and self.tournament:
            self.data.append(self.tournament)
            self.tournament = None
