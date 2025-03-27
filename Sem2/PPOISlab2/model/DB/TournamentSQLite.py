from sqlalchemy import create_engine, Column, String, Integer
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from faker import Faker
from typing import List, Tuple

DB_NAME = "model/DB/tournaments.db"
engine = create_engine(f"sqlite:///{DB_NAME}", echo=False)
BASE = declarative_base()


class Tournament(BASE):
    __tablename__ = "tournaments"
    id = Column(Integer, primary_key=True)
    tournament_name = Column(String, nullable=False)
    tournament_date = Column(String, nullable=False)
    sport_type = Column(String, nullable=False)
    winner_name = Column(String, nullable=False)
    prize = Column(Integer, default=0)
    earnings = Column(Integer, default=0)

    @classmethod
    def add_info(cls, info: Tuple[str, str, str, str, int] = None):
        fake = Faker()
        if info is None:
            info = (
                fake.word(),
                fake.date(),
                fake.word(),
                fake.name(),
                fake.random_int(min=100, max=10000)
            )

        session = Session()
        new_tournament = cls(
            tournament_name=info[0],
            tournament_date=info[1],
            sport_type=info[2],
            winner_name=info[3],
            prize=int(info[4]),
            earnings=int(info[4] * 0.6)
        )
        session.add(new_tournament)
        session.commit()
        session.close()

    @classmethod
    def get_info_paged(cls, page: int, per_page: int):
        offset = (page - 1) * per_page
        session = Session()
        tournaments = session.query(cls).offset(offset).limit(per_page).all()
        session.close()
        return tournaments

    @classmethod
    def get_data(cls) -> int:
        session = Session()
        count = session.query(cls).count()
        session.close()
        return count

    def to_tuple(self) -> Tuple:
        values = (self.tournament_name, self.tournament_date, self.sport_type,
                  self.winner_name, self.prize, self.earnings)
        return values

    @classmethod
    def delete_by_date(cls, date: str):
        session = Session()
        session.query(cls).filter(cls.tournament_date == date).delete()
        session.commit()
        session.close()

    @classmethod
    def get_sports(cls) -> List[str]:
        session = Session()
        tournaments = session.query(cls).all()
        session.close()
        sports = []
        for tournament in tournaments:
            sports.append(tournament.sport_type)
        return sports

    @classmethod
    def search_by_sports(cls, sport_name: str):
        session = Session()
        tournaments = session.query(cls).filter(cls.sport_type == sport_name).all()
        session.close()
        return tournaments

    @classmethod
    def get_unique_sports(cls) -> List[str]:
        session = Session()
        unique_sports = session.query(cls.sport_type).distinct().all()
        session.close()
        return [sport[0] for sport in unique_sports]

    @classmethod
    def delete_by_sports(cls, sport_name: str):
        session = Session()
        session.query(cls).filter(cls.sport_type == sport_name).delete()
        session.commit()
        session.close()

    @classmethod
    def search_by_date(cls, date: str):
        session = Session()
        tournaments = session.query(cls).filter(cls.tournament_date == date).all()
        session.close()
        return tournaments

    @classmethod
    def delete_by_date(cls, date: str):
        session = Session()
        session.query(cls).filter(cls.tournament_date == date).delete()
        session.commit()
        session.close()

    @classmethod
    def delete_by_prize_range(cls, min_prize: int, max_prize: int):
        session = Session()
        session.query(cls).filter(cls.prize.between(min_prize, max_prize)).delete()
        session.commit()
        session.close()

    @classmethod
    def delete_by_winner(cls, winner_name: str):
        session = Session()
        tournaments = session.query(cls).filter(cls.winner_name.like(f"{winner_name}")).all()
        for tournament in tournaments:
            session.delete(tournament)
        session.commit()
        session.close()

    @classmethod
    def search_by_winner(cls, winner_name: str):
        session = Session()
        tournaments = session.query(cls).filter(cls.winner_name.like(f"{winner_name}")).all()
        session.close()
        return tournaments

    @classmethod
    def delete_by_FIO(cls, FIO: str):
        session = Session()
        tournaments = session.query(cls).filter(cls.winner_name.like(f"%{FIO}%")).all()
        for tournament in tournaments:
            session.delete(tournament)
        session.commit()
        session.close()

    @classmethod
    def search_by_prize_range(cls, min_prize: int, max_prize: int):
        session = Session()
        tournaments = session.query(cls).filter(cls.prize.between(min_prize, max_prize)).all()
        session.close()
        return tournaments

    @classmethod
    def delete_tournaments(cls, tournaments: List):
        session = Session()
        for tournament in tournaments:
            session.delete(tournament)
        session.commit()
        session.close()

    @classmethod
    def search_by_name_and_earnings(cls, name: str, min_earnings: int, max_earnings: int):
        session = Session()
        tournaments = session.query(cls).filter(
            cls.winner_name.like(f'%{name}%'),
            cls.earnings.between(min_earnings, max_earnings)
        ).all()
        session.close()
        return tournaments

    @classmethod
    def delete_by_name_and_earnings(cls, name: str, min_earnings: int, max_earnings: int):
        session = Session()
        session.query(cls).filter(
            cls.winner_name.like(f'%{name}%'),
            cls.earnings.between(min_earnings, max_earnings)
        ).delete()
        session.commit()
        session.close()

    def __repr__(self):
        return f"Tournament(id={self.id}, tournament_name='{self.tournament_name}', winner_name='{self.winner_name}')"


BASE.metadata.create_all(engine)
Session = sessionmaker(bind=engine)
