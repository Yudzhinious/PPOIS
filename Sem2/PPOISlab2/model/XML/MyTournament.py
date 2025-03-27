class MyTournament:
    def __init__(self, id: str, tournament_name: str = "", date: str = "", sport: str = "", winner: str = "",
                 prize: int = 0, earnings: int = 0):
        self.id: str = id
        self.tournament_name: str = tournament_name
        self.date: str = date
        self.sport: str = sport
        self.winner: str = winner
        self.prize: int = prize
        self.earnings: int = earnings

    def to_tuple(self):
        return (self.tournament_name, self.date, self.sport, self.winner, self.prize, self.earnings)

    def __hash__(self):
        return hash((self.id, self.tournament_name, self.date, self.sport, self.winner, self.prize, self.earnings))

    def __repr__(self):
        return f"MyTournament(id={self.id}, name={self.tournament_name}, date={self.date}, winner={self.winner})"
