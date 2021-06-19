#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTimer>
#include <QMap>
#include <QMessageBox>
#include "MyHeader.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QHBoxLayout* firstLayout; // itt lehet a nehézséget kiválasztani, játéidőt mutatja stb.
    QGridLayout* gameLayout; // ezen vannak a játék gombjai
    QVBoxLayout* mainLayout; // az előző két layout-ot tartalmazza
    QComboBox* difficulties; // játék nehézségének kiválasztására
    QFont font; // gombok, labelek betűtípusának beállítására
    MyButton*** buttons; // a játék gombjai
    QPushButton* resetButton; // reset gomb új játékhoz
    QPushButton* showHighscores; // gomb a top 10 eredmény mutatásához
    QString** buttonText; // a gomboknak megfelelő 'szövegek' pl. bomba, üres, 1, 2 stb.
    QLabel* flags; // mutatja hogy hány flag van még
    QLabel* timeLabel; // a játékidőt mutatja
    QTimer* timer; // méri a játékidőt
    double time; // az időméréshez szükséges
    int difficulty; // játék nehézségét tárolja: 0 - könnyű, 1 - közepes, 2 - nehéz
    int buttonRows, buttonColumns; // a játéktér aktuális méreteit tárolják
    int numberOfBombs; // bombák száma, nehézségtől függ
    int disabledButtons; // játék során hány gombot nem lehet már használni, a játék végének eldöntéséhez kell
    int numberOfFlags; // kezdetben bombák számával megegyező, a megmaradt flag-ek számát tárolja
    bool endOfGame; // false játék közben, nyerés/vesztés után true
    QMap <double, QString> highscoresEasy;// a legjobb eredményeket tárolják, az idő a kulcs
    QMap <double, QString> highscoresMedium;
    QMap <double, QString> highscoresHard;
    QMessageBox* top10; // a legjobb eredmények megmutatásához

    void clearButtons(); // letörli az összes gombot a játéktérről
    void setButtons(int n, int m, int size); // beállítja a gombokat
    void setBombs(); // random leteszi a bombákat (hiba: a random generálás seedje az aktuális időtől függ, mégis minden futtatásnál ugyanaz van)
    void setNumbers(); // bombák alapján beállítja a gombokhoz tartozó számokat
    void onFreeButtonClicked(int i, int j); // ha üres gombra kattintunk; rekurzív
    void bombClicked(); // ha bombára kattintunk
    void win(); // ha nyertünk
    void reset(); // beállít mindent alaphelyzetbe
    void showTop10(int difficulty);
    QComboBox* createComboBox();


private slots:
     void difficultyChanged(); // ha megváltoztatjuk a nehézséget
     void buttonClicked(); // ha a játéktér egy gombjára kattintunk
     void rightButtonClicked(); // ha jobb-klikket nyomunk
     void tick(); // időméréshez szükséges
};
#endif // MAINWINDOW_H
