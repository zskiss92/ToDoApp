#include "mainwindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString filename = "MyFile.txt";
    read(filename);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString item = ui-> lineEdit -> text();

    if(item != "")
    {
        ui -> listWidget -> addItem(item);
        ui -> lineEdit -> clear();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    if(selectedRow != -1)
    {
        QListWidgetItem *selectedItem = ui-> listWidget -> takeItem(selectedRow);
        delete selectedItem;

        ui -> listWidget -> setCurrentRow(-1);
    }
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    selectedRow = currentRow;
}

void MainWindow::write(QString filename, QStringList text)
{
    QFile file(filename);

    if(!file.open(QFile::WriteOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }

    QTextStream out(&file);
    for(int i = 0; i < text.count(); i++)
    {
        out << text[i];
        if(i != text.count()-1)
        {
            out << '\n';
        }
    }

    file.flush();
    file.close();

}

void MainWindow::read(QString filename)
{
    QFile file(filename);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    QStringList textList = myText.split("\n");
    foreach(QString item, textList)
        addToList(item);

    file.close();
}

void MainWindow::addToList(QString text)
{
    ui -> listWidget -> addItem(text);
}



void MainWindow::on_saveButton_clicked()
{
    QStringList list;
    QString filename = "MyFile.txt";

    for(int i = 0; i < ui->listWidget -> count(); i++)
        list.append(ui->listWidget->item(i)->text());

    foreach(QString value, list)
        qDebug() << value;
    write(filename, list);
}

