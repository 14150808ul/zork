#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_west_clicked();
    void on_button_east_clicked();
    void on_button_north_clicked();
    void on_button_south_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
