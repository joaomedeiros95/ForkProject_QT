#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QProcess *p;
    QTimer *timer;

private slots:
    void on_pushButton_clicked();

    void on_actionSobre_triggered();

public slots:
    void goAdicionar(int);
    void updateText();
    void updateClock();
    void stopClock();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
