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

    QImage qImg;

private slots:
    void on_Btn_openFile_clicked();

    void on_buildCode_Btn_clicked();

    void on_Btn_savePic_clicked();

    void on_buildCode_Btn_bar_clicked();

    void on_Btn_savePic_bar_clicked();

    void on_Btn_openFile_bar_clicked();

private:
    Ui::MainWindow *ui;


protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
