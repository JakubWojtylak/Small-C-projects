#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>

namespace Ui {
class kalkulator;
}

class kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit kalkulator(QWidget *parent = nullptr);
    ~kalkulator();

private:
    Ui::kalkulator *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void ChangeNumberSign();
};

#endif // KALKULATOR_H
