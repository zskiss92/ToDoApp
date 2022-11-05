#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void write(QString filename, QStringList text);

    void read(QString filename);

    void addToList(QString text);

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;

    int selectedRow = -1;
};
#endif // MAINWINDOW_H
